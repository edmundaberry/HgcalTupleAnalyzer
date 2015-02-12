#include "analysisClass.h"

#include "PFPrunedJet.h"
#include "PFCoreJet.h"
#include "GenParticle.h"
#include "GenJet.h"
#include "Collection.h"
#include "HgcalTupleTree.h"
#include "likelihoodGetter.h"

#include "TH1F.h"

static const int n_radii       = 100;
static const double max_radius = 0.5;
static const double min_radius = 0.0;
static double radii[n_radii];


static const float HGCAL_abseta_min = 1.6;
static const float HGCAL_abseta_max = 3.0;
// static const float HGCAL_abseta_min = 1.5;
// static const float HGCAL_abseta_max = 1.8;
// static const float HGCAL_abseta_min = 2.6;
// static const float HGCAL_abseta_max = 2.9;

static const double pfcorejet_pt_minimum = 0.;
static const double pfjet_pt_minimum = 20.;
static const double maximum_deltaR_match = 0.2;

void preparePFCandAxis( TH1F * hist ) {
  hist -> GetXaxis() -> SetBinLabel(1, "Undefined");
  hist -> GetXaxis() -> SetBinLabel(2, "Charged had");
  hist -> GetXaxis() -> SetBinLabel(3, "Electron");
  hist -> GetXaxis() -> SetBinLabel(4, "Muon");
  hist -> GetXaxis() -> SetBinLabel(5, "Photon");
  hist -> GetXaxis() -> SetBinLabel(6, "Neutral had");
  hist -> GetXaxis() -> SetBinLabel(7, "HF had");
  hist -> GetXaxis() -> SetBinLabel(8, "HF egamma");
  hist -> GetXaxis() -> SetBinLabel(9, "All");
}

void preparePFCandAxis( TH2F * hist ) {
  hist -> GetXaxis() -> SetBinLabel(1, "Undefined");
  hist -> GetXaxis() -> SetBinLabel(2, "Charged had");
  hist -> GetXaxis() -> SetBinLabel(3, "Electron");
  hist -> GetXaxis() -> SetBinLabel(4, "Muon");
  hist -> GetXaxis() -> SetBinLabel(5, "Photon");
  hist -> GetXaxis() -> SetBinLabel(6, "Neutral had");
  hist -> GetXaxis() -> SetBinLabel(7, "HF had");
  hist -> GetXaxis() -> SetBinLabel(8, "HF egamma");
  hist -> GetXaxis() -> SetBinLabel(9, "All");
}

template <class Jet>
int getFlavor ( Jet & jet, CollectionPtr gen ){

  CollectionPtr gen_matched   = gen         -> SkimByRequireDRMatch<GenParticle, Jet> ( jet, 0.3 );
  CollectionPtr gen_matched_b = gen_matched -> SkimByID<GenParticle>( GEN_PARTICLE_IS_B_QUARK );
  CollectionPtr gen_matched_c = gen_matched -> SkimByID<GenParticle>( GEN_PARTICLE_IS_C_QUARK );
  CollectionPtr gen_matched_l = gen_matched -> SkimByID<GenParticle>( GEN_PARTICLE_IS_HARD_SCATTER_LEPTON );

  if ( gen_matched -> GetSize() == 0 ) return -1;

  if ( gen_matched_l -> GetSize() > 0 ) {
    return abs(gen_matched -> GetLeadPtObject<GenParticle>().PdgId());
  }

  if      ( gen_matched_b -> GetSize() > 0 ) return 1;
  else if ( gen_matched_c -> GetSize() > 0 ) return 1;
  
  int lead_parton_pdg = abs(gen_matched -> GetLeadPtObject<GenParticle>().PdgId());

  if      ( lead_parton_pdg == 21 ) return 0;
  else if ( lead_parton_pdg <= 6  ) return 1;
  
  return -1;
}

template <class Jet>
void fillPlots ( CollectionPtr & jets, 
		 CollectionPtr & core_jets, 
		 CollectionPtr & partons,
		 CollectionPtr & hgceeClusters,
		 CollectionPtr & hgchefClusters,
		 CollectionPtr & hgchebClusters,
		 likelihoodGetter & l, 
		 int index,
		 std::vector<TH1F*> quark_th1, std::vector<TH1F*> gluon_th1,
		 std::vector<TH2F*> quark_th2, std::vector<TH2F*> gluon_th2 ){

  int n_jets = jets -> GetSize();

  std::vector<double> likelihood_variables;

  for (int i = 0; i < n_jets; ++i){

    Jet jet = jets -> GetConstituent<Jet>(i);
    CollectionPtr all_core_jets     = core_jets;
    CollectionPtr matched_core_jets = core_jets -> SkimByRequireDRMatch<PFCoreJet, PFPrunedJet>( jet, 0.3 ) ;
    
    rechit_type my_type = NO_TYPE;
    int my_index = -1;
    jet.getLeadClusterTypeAndIndex(my_type, my_index);    
    double clusterLength = -1.;
    double clusterVolume = -1.;
    if ( my_type == NO_TYPE ) continue;

    if ( my_type == HGCEE ){
      HGCEECluster c(*hgceeClusters, my_index);
      clusterLength = c.getLength();
      clusterVolume = c.getVolume();
    }

    else if ( my_type == HGCHEF ){
      HGCHEFCluster c(*hgchefClusters, my_index);
      clusterLength = c.getLength();
      clusterVolume = c.getVolume();
    }

    else {
      HGCHEBCluster c(*hgchebClusters, my_index);
      clusterLength = c.getLength();
      clusterVolume = c.getVolume();
    }

    double core_over_total_pt = -1.;
    double lead_core_jet_dr   = -1.;
    double n_core_jets        = matched_core_jets -> GetSize();
    if ( n_core_jets > 0 ){
      PFCoreJet lead_core_jet = matched_core_jets -> GetLeadPtObject<PFCoreJet> ();
      double core_pt = lead_core_jet.Pt();
      core_over_total_pt = core_pt / jet.Pt();
      lead_core_jet_dr   = jet.DeltaR( &lead_core_jet );
    }
    
    int flavor = getFlavor ( jet , partons );
    if ( flavor == -1 ) continue;
    bool isQuarkJet ( flavor == 1 );
    bool isGluonJet ( flavor == 0 );


    likelihood_variables.clear();

    double weighted_depth = jet.getWeightedDepth();
    double weighted_depth_noEE = jet.getWeightedDepthNoEE();

    double profile[n_radii];
    jet.getProfile(n_radii, radii, profile);

    double profile50 = jet.getProfileRadius(n_radii, radii, profile, 0.5);
    double profile90 = jet.getProfileRadius(n_radii, radii, profile, 0.9);
    double profile95 = jet.getProfileRadius(n_radii, radii, profile, 0.95);
    double profile99 = jet.getProfileRadius(n_radii, radii, profile, 0.99);

    likelihood_variables.push_back ( jet.TrimmedNSubjets(index) );
    likelihood_variables.push_back ( jet.getWidth()   );
    likelihood_variables.push_back ( jet.getNPFCandidates() );
    likelihood_variables.push_back ( jet.getPTD() );
    likelihood_variables.push_back ( jet.NSubJettiness() );
    likelihood_variables.push_back ( jet.TrimmedMass(index) * 1000. );
    likelihood_variables.push_back ( profile50 );
    likelihood_variables.push_back ( core_over_total_pt );
    likelihood_variables.push_back ( lead_core_jet_dr );

    double ee_energy     = jet.getEEEnergy();
    double ee015_energy  = jet.getEEEnergy(0, 15);
    double ee1631_energy = jet.getEEEnergy(16, 31);
    double hef_energy    = jet.getHEFEnergy();
    double heb_energy    = jet.getHEBEnergy();
    double all_energy    = ee_energy + hef_energy + heb_energy;

    double hef11_energy  = jet.getHEFEnergy(1, 1);
    double hef22_energy  = jet.getHEFEnergy(2, 2);
    double hef34_energy  = jet.getHEFEnergy(3, 4);
    double hef56_energy  = jet.getHEFEnergy(5, 6);
    double hef712_energy = jet.getHEFEnergy(7,12);

    double likelihood  = l.getLikelihood ( likelihood_variables );

    if ( isQuarkJet ){

      quark_th1[0] -> Fill ( jet.NSubJettiness() );
      quark_th1[1] -> Fill ( jet.TrimmedMass(index) * 1000. );
      quark_th1[2] -> Fill ( jet.TrimmedNSubjets(index) );
      quark_th1[3] -> Fill ( jet.getNPFCandidates() );
      quark_th1[4] -> Fill ( jet.getWidth() );
      quark_th1[5] -> Fill ( jet.getChargedWidth() );
      quark_th1[6] -> Fill ( jet.getNeutralWidth() );
      quark_th1[7] -> Fill ( weighted_depth );
      quark_th1[8] -> Fill ( weighted_depth_noEE );
      quark_th1[9] -> Fill ( jet.getPTD() );
      quark_th1[10] -> Fill ( likelihood );
      quark_th1[11] -> Fill ( ee_energy / all_energy );
      quark_th1[12] -> Fill ( ee015_energy / all_energy );
      quark_th1[13] -> Fill ( ee1631_energy / all_energy );
      quark_th1[14]-> Fill ( heb_energy / all_energy );
      quark_th1[15]-> Fill ( hef_energy / all_energy );
      quark_th1[16]-> Fill ( hef11_energy / all_energy );
      quark_th1[17]-> Fill ( hef22_energy / all_energy );
      quark_th1[18]-> Fill ( hef34_energy / all_energy );
      quark_th1[19]-> Fill ( hef56_energy / all_energy );
      quark_th1[20]-> Fill ( hef712_energy / all_energy );
      for (int i_radius = 0; i_radius < n_radii; ++i_radius){
	quark_th1[21] -> Fill(radii[i_radius], profile[i_radius]);
      }
      quark_th1[22] -> Fill ( profile50 );
      quark_th1[23] -> Fill ( profile90 );
      quark_th1[24] -> Fill ( profile95 );
      quark_th1[25] -> Fill ( profile99 );
      quark_th1[26] -> Fill ( n_core_jets        );
      quark_th1[27] -> Fill ( lead_core_jet_dr   );
      quark_th1[28] -> Fill ( core_over_total_pt );
      quark_th1[29] -> Fill ( clusterVolume );
      quark_th1[30] -> Fill ( clusterLength );
      
      quark_th2[0] -> Fill ( jet.Pt(), weighted_depth );
      quark_th2[1] -> Fill ( jet.Pt(), jet.getMaxRHDepth());
      quark_th2[2] -> Fill ( jet.getNPFCandidates(), jet.TrimmedNSubjets(index) );
    }

    if ( isGluonJet ){
      
      gluon_th1[0] -> Fill ( jet.NSubJettiness() );
      gluon_th1[1] -> Fill ( jet.TrimmedMass(index) * 1000. );
      gluon_th1[2] -> Fill ( jet.TrimmedNSubjets(index) );
      gluon_th1[3] -> Fill ( jet.getNPFCandidates() );
      gluon_th1[4] -> Fill ( jet.getWidth() );
      gluon_th1[5] -> Fill ( jet.getChargedWidth() );
      gluon_th1[6] -> Fill ( jet.getNeutralWidth() );
      gluon_th1[7] -> Fill ( weighted_depth );
      gluon_th1[8] -> Fill ( weighted_depth_noEE );
      gluon_th1[9] -> Fill ( jet.getPTD() );
      gluon_th1[10] -> Fill ( likelihood );
      gluon_th1[11] -> Fill ( ee_energy / all_energy );

      gluon_th1[12] -> Fill ( ee015_energy / all_energy );
      gluon_th1[13] -> Fill ( ee1631_energy / all_energy );
      gluon_th1[14]-> Fill ( heb_energy / all_energy );
      gluon_th1[15]-> Fill ( hef_energy / all_energy );
      gluon_th1[16]-> Fill ( hef11_energy / all_energy );
      gluon_th1[17]-> Fill ( hef22_energy / all_energy );
      gluon_th1[18]-> Fill ( hef34_energy / all_energy );
      gluon_th1[19]-> Fill ( hef56_energy / all_energy );
      gluon_th1[20]-> Fill ( hef712_energy / all_energy );
      for (int i_radius = 0; i_radius < n_radii; ++i_radius){
	gluon_th1[21] -> Fill(radii[i_radius], profile[i_radius]);
      }
      gluon_th1[22] -> Fill ( profile50 );
      gluon_th1[23] -> Fill ( profile90 );
      gluon_th1[24] -> Fill ( profile95 );
      gluon_th1[25] -> Fill ( profile99 );
      gluon_th1[26] -> Fill ( n_core_jets        );
      gluon_th1[27] -> Fill ( lead_core_jet_dr   );
      gluon_th1[28] -> Fill ( core_over_total_pt );
      gluon_th1[29] -> Fill ( clusterVolume );
      gluon_th1[30] -> Fill ( clusterLength );

      gluon_th2[0] -> Fill ( jet.Pt(), weighted_depth );
      gluon_th2[1] -> Fill ( jet.Pt(), jet.getMaxRHDepth());
      gluon_th2[2] -> Fill ( jet.getNPFCandidates(), jet.TrimmedNSubjets(index) );

      
    }
  }
}
		 

template <class Jet>
void fillPFCandVsCount ( Jet & jet, TH2F* hist ){
  
  const int n_ids = 8;
  int pfcand_ids[n_ids + 1];
  memset ( pfcand_ids, 0, sizeof (pfcand_ids));
  
  int nPFCands = jet.getNPFCandidates();
  for (int iPFCand = 0; iPFCand < nPFCands; ++iPFCand){
    PFCand cand = jet.getPFCandidate( iPFCand );
    pfcand_ids[cand.Id()]++;
    pfcand_ids[n_ids]++;
  }
  for (int i = 0; i <= n_ids; ++i) hist -> Fill(i, pfcand_ids[i]);

}

void analysisClass::loop(){

  //--------------------------------------------------------------------------------
  // Store important variables
  //--------------------------------------------------------------------------------

  for (int i_radius = 1; i_radius <= n_radii; ++i_radius){
    radii[i_radius-1] = min_radius + i_radius * (max_radius - min_radius) / double(n_radii);
  }
  
  //--------------------------------------------------------------------------------
  // Declare tree(s)
  //--------------------------------------------------------------------------------
  
  HgcalTupleTree * tree = getTree<HgcalTupleTree>("hgcal_tree");
  int n_events = tree -> fChain -> GetEntries();
  // int n_events = 200;
  
  std::vector<std::string> * rcut_values = new std::vector<std::string>();
  rcut_values -> push_back ("R5"); 
  rcut_values -> push_back ("R4"); 
  rcut_values -> push_back ("R3"); 
  rcut_values -> push_back ("R2"); 
  rcut_values -> push_back ("R1"); 
  rcut_values -> push_back ("R05"); 
  rcut_values -> push_back ("R04"); 
  rcut_values -> push_back ("R03"); 
  rcut_values -> push_back ("R02"); 
  rcut_values -> push_back ("R01"); 
  rcut_values -> push_back ("R008"); 
  rcut_values -> push_back ("R005"); 
  rcut_values -> push_back ("R003"); 
  rcut_values -> push_back ("R001");
  
  //--------------------------------------------------------------------------------
  // Likelihood getter
  //--------------------------------------------------------------------------------

  int n_rcut_variables = rcut_values -> size();

  std::vector<std::string> likelihood_variables;
  likelihood_variables.push_back ( "nDaught" );
  likelihood_variables.push_back ( "width"   );
  likelihood_variables.push_back ( "multi"   );
  likelihood_variables.push_back ( "ptd"     );
  likelihood_variables.push_back ( "nsubj"   );
  likelihood_variables.push_back ( "mass"    );
  likelihood_variables.push_back ( "profile50" );
  likelihood_variables.push_back ( "leadCoreJetFraction" );
  likelihood_variables.push_back ("leadCoreJetDR");
  
  std::string file_name ("likelihood_hists_fromWJet.root");

  std::vector<likelihoodGetter> likelihoods;

  for (int ircut = 0; ircut < n_rcut_variables; ++ircut){
    std::string signal("quarkPruned");
    signal = signal + (*rcut_values)[ircut];
    signal = signal + std::string("Jets");
    std::vector<std::string> signals;
    signals.push_back ( signal );
    likelihoodGetter l ( file_name,(*rcut_values)[ircut] , likelihood_variables, signals );
    likelihoods.push_back (l);
  }
  
  //--------------------------------------------------------------------------------
  // Make histograms
  //--------------------------------------------------------------------------------

  TH2F * all_tau_ptVsPull      = makeTH2F("all_tau_ptVsPull" ,  100, 0, 500,  100, -2, 2);
  TH2F * fid_tau_ptVsPull      = makeTH2F("fid_tau_ptVsPull" ,  100, 0, 500,  100, -2, 2);
  TH2F * all_vbfq_ptVsPull     = makeTH2F("all_vbfq_ptVsPull",  100, 0, 500,   100, -2, 2);
  TH2F * fid_vbfq_ptVsPull     = makeTH2F("fid_vbfq_ptVsPull",  100, 0, 500,   100, -2, 2);

  TH1F * all_vbfq_matchDR = makeTH1F( "all_vbfq_matchDR", 100, 0, 2 );
  TH1F * fid_vbfq_matchDR = makeTH1F( "fid_vbfq_matchDR", 100, 0, 2 );

  TH1F * all_recojet_matched_matchDR = makeTH1F("all_recojet_matched_matchDR", 100, 0, 2 );
  TH1F * all_recojet_matched_eta     = makeTH1F("all_recojet_matched_eta", 100, -5., 5.);
  TH1F * all_recojet_matched_pt      = makeTH1F("all_recojet_matched_pt", 100, 0, 200 );
	                             
  TH1F * fid_recojet_matched_matchDR = makeTH1F("fid_recojet_matched_matchDR", 100, 0, 2 );
  TH1F * fid_recojet_matched_eta     = makeTH1F("fid_recojet_matched_eta", 100, -5., 5.);
  TH1F * fid_recojet_matched_pt      = makeTH1F("fid_recojet_matched_pt", 100, 0, 200 );
  
  TH1F* all_tau_pull      = makeTH1F("all_tau_pull"     , 100, -2, 2);
  TH1F* fid_tau_pull      = makeTH1F("fid_tau_pull"     , 100, -2, 2);
  TH1F* all_vbfq_pull     = makeTH1F("all_vbfq_pull"     , 100, -2, 2);
  TH1F* fid_vbfq_pull     = makeTH1F("fid_vbfq_pull"     , 100, -2, 2);

  TH1F* all_tau_rawPull      = makeTH1F("all_tau_rawPull"     , 100, -2, 2);
  TH1F* fid_tau_rawPull      = makeTH1F("fid_tau_rawPull"     , 100, -2, 2);
  TH1F* all_vbfq_rawPull     = makeTH1F("all_vbfq_rawPull"     , 100, -2, 2);
  TH1F* fid_vbfq_rawPull     = makeTH1F("fid_vbfq_rawPull"     , 100, -2, 2);
  
  TH1F* all_tau_gen_pt    = makeTH1F("all_tau_gen_pt"   , 100, 0, 500);
  TH1F* all_tau_reco_pt   = makeTH1F("all_tau_reco_pt"  , 100, 0, 500);
  TH1F* fid_tau_gen_pt    = makeTH1F("fid_tau_gen_pt"   , 100, 0, 500);
  TH1F* fid_tau_reco_pt   = makeTH1F("fid_tau_reco_pt"  , 100, 0, 500);

  TH1F* all_vbfq_gen_pt   = makeTH1F("all_vbfq_gen_pt"  , 100, 0, 500);
  TH1F* all_vbfq_reco_pt  = makeTH1F("all_vbfq_reco_pt" , 100, 0, 500);
  TH1F* fid_vbfq_gen_pt   = makeTH1F("fid_vbfq_gen_pt"  , 100, 0, 500);
  TH1F* fid_vbfq_reco_pt  = makeTH1F("fid_vbfq_reco_pt" , 100, 0, 500);

  TH1F* all_tau_gen_eta   = makeTH1F("all_tau_gen_eta"  , 100, -5., 5.);
  TH1F* all_tau_reco_eta  = makeTH1F("all_tau_reco_eta" , 100, -5., 5.);
  TH1F* fid_tau_gen_eta   = makeTH1F("fid_tau_gen_eta"  , 100, -5., 5.);
  TH1F* fid_tau_reco_eta  = makeTH1F("fid_tau_reco_eta" , 100, -5., 5.);

  TH1F* all_vbfq_gen_eta  = makeTH1F("all_vbfq_gen_eta" , 100, -5., 5.);
  TH1F* all_vbfq_reco_eta = makeTH1F("all_vbfq_reco_eta", 100, -5., 5.);
  TH1F* fid_vbfq_gen_eta  = makeTH1F("fid_vbfq_gen_eta" , 100, -5., 5.);
  TH1F* fid_vbfq_reco_eta = makeTH1F("fid_vbfq_reco_eta", 100, -5., 5.);

  TH1F * fid_vbfq_reco_chargedFraction = makeTH1F("fid_vbfq_reco_chargedFraction", 100, 0, 1.);
  TH1F * fid_vbfq_reco_neutralFraction = makeTH1F("fid_vbfq_reco_neutralFraction", 100, 0, 1.);

  std::vector<TH1F*> th1_templates;
  th1_templates.push_back ( makeTH1F ("nsubj"                 , 20  ,  0. ,     1.  )); // 0
  th1_templates.push_back ( makeTH1F ("mass"                  , 40 ,  0. , 200000.  )); // 1
  th1_templates.push_back ( makeTH1F ("nDaught"               , 50  , -0.5,    49.5 )); // 2
  th1_templates.push_back ( makeTH1F ("multi"                 , 100 , -0.5,   999.5 ));	// 3
  th1_templates.push_back ( makeTH1F ("width"                 , 200 ,  0. ,     1.  ));	// 4
  th1_templates.push_back ( makeTH1F ("chargedWidth"          , 200 ,  0. ,     1.  ));	// 5
  th1_templates.push_back ( makeTH1F ("neutralWidth"          , 200 ,  0. ,     1.  ));	// 6
  th1_templates.push_back ( makeTH1F ("depth"                 , 200 ,  0. ,  1000.  ));	// 7
  th1_templates.push_back ( makeTH1F ("depth_noEE"            , 200 ,  0. ,  1000.  ));	// 8
  th1_templates.push_back ( makeTH1F ("ptd"                   ,  20 ,  0. ,     1.  ));	// 9
  th1_templates.push_back ( makeTH1F ("like"                  , 100 ,  0. ,     1.1 ));	// 10
  th1_templates.push_back ( makeTH1F ("ee_energy_fraction"    , 100 ,  0. ,     1.  ));	// 11
  th1_templates.push_back ( makeTH1F ("ee015_energy_fraction" , 100 ,  0. ,     1.  ));	// 12
  th1_templates.push_back ( makeTH1F ("ee1631_energy_fraction", 100 ,  0. ,     1.  )); // 13
  th1_templates.push_back ( makeTH1F ("heb_energy_fraction"   , 100 ,  0. ,     1.  ));	// 14
  th1_templates.push_back ( makeTH1F ("hef_energy_fraction"   , 100 ,  0. ,     1.  ));	// 15
  th1_templates.push_back ( makeTH1F ("hef11_energy_fraction" , 100 ,  0. ,     1.  ));	// 16
  th1_templates.push_back ( makeTH1F ("hef22_energy_fraction" , 100 ,  0. ,     1.  ));	// 17
  th1_templates.push_back ( makeTH1F ("hef34_energy_fraction" , 100 ,  0. ,     1.  ));	// 18
  th1_templates.push_back ( makeTH1F ("hef56_energy_fraction" , 100 ,  0. ,     1.  ));	// 19
  th1_templates.push_back ( makeTH1F ("hef712_energy_fraction", 100 ,  0. ,     1.  )); // 20
  th1_templates.push_back ( makeTH1F ("profile"               , n_radii + 1 ,  min_radius, max_radius )); // 21
  th1_templates.push_back ( makeTH1F ("profile50"             , n_radii + 1 ,  min_radius, max_radius )); // 22
  th1_templates.push_back ( makeTH1F ("profile90"             , n_radii + 1 ,  min_radius, max_radius )); // 23
  th1_templates.push_back ( makeTH1F ("profile95"             , n_radii + 1 ,  min_radius, max_radius )); // 24
  th1_templates.push_back ( makeTH1F ("profile99"             , n_radii + 1 ,  min_radius, max_radius )); // 25
  th1_templates.push_back ( makeTH1F ("nCoreJets"             , 10, -0.5, 9.5 )); // 26
  th1_templates.push_back ( makeTH1F ("leadCoreJetDR"         , 100, 0., 0.4 )); // 27
  th1_templates.push_back ( makeTH1F ("leadCoreJetFraction"   , 100, 0., 1.  )); // 28
  th1_templates.push_back ( makeTH1F ("volume"                , 100, -10, 10)); // 29
  th1_templates.push_back ( makeTH1F ("length"                , 100, -10, 10)); // 30
  
  std::vector<TH2F*> th2_templates;
  th2_templates.push_back ( makeTH2F ("jetPt_vs_depth"      , 100, 0, 250, 200 ,  0. ,  1000.  ));
  th2_templates.push_back ( makeTH2F ("jetPt_vs_maxRHDepth" , 100, 0, 250, 200 ,  0. ,  1000.  ));
  th2_templates.push_back ( makeTH2F ("NPFCands_vs_NSubJets", 51 , -0.5, 50.5, 5 , -0.5, 4.5 ));

  std::map<std::string, std::vector<TH1F*> > m_quark_rcut_th1;
  std::map<std::string, std::vector<TH1F*> > m_gluon_rcut_th1;
  std::map<std::string, std::vector<TH2F*> > m_quark_rcut_th2;
  std::map<std::string, std::vector<TH2F*> > m_gluon_rcut_th2;
  
  int n_th1_templates = th1_templates.size();
  int n_th2_templates = th2_templates.size();
  int n_rcutValues    = rcut_values -> size();
  char quark_hist_name[100];
  char gluon_hist_name[100];

  for (int i_th1_template = 0; i_th1_template < n_th1_templates; ++i_th1_template){
    for (int i_rcutValue = 0; i_rcutValue < n_rcutValues; ++i_rcutValue ){
      
      TH1F * hist_template = th1_templates[i_th1_template];
      
      sprintf(quark_hist_name, "%s_quarkPruned%sJets", hist_template -> GetName(), (*rcut_values)[i_rcutValue].c_str());
      sprintf(gluon_hist_name, "%s_gluonPruned%sJets", hist_template -> GetName(), (*rcut_values)[i_rcutValue].c_str());
      
      TH1F * quark_hist = makeTH1F(quark_hist_name, 
				   hist_template -> GetNbinsX(), 
				   hist_template -> GetXaxis() -> GetXmin(),
				   hist_template -> GetXaxis() -> GetXmax() );
				   
      TH1F * gluon_hist = makeTH1F(gluon_hist_name, 
				   hist_template -> GetNbinsX(), 
				   hist_template -> GetXaxis() -> GetXmin(),
				   hist_template -> GetXaxis() -> GetXmax() );

      m_quark_rcut_th1[(*rcut_values)[i_rcutValue]].push_back(quark_hist);
      m_gluon_rcut_th1[(*rcut_values)[i_rcutValue]].push_back(gluon_hist);
      
    }
  }

  
  for (int i_th2_template = 0; i_th2_template < n_th2_templates; ++i_th2_template){
    for (int i_rcutValue = 0; i_rcutValue < n_rcutValues; ++i_rcutValue ){
      
      TH2F * hist_template = th2_templates[i_th2_template];
      
      sprintf(quark_hist_name, "%s_quarkPruned%sJets", hist_template -> GetName(), (*rcut_values)[i_rcutValue].c_str());
      sprintf(gluon_hist_name, "%s_gluonPruned%sJets", hist_template -> GetName(), (*rcut_values)[i_rcutValue].c_str());
      
      TH2F * quark_hist = makeTH2F(quark_hist_name, 
				   hist_template -> GetNbinsX(), 
				   hist_template -> GetXaxis() -> GetXmin(),
				   hist_template -> GetXaxis() -> GetXmax(),
				   hist_template -> GetNbinsY(), 
				   hist_template -> GetYaxis() -> GetXmin(),
				   hist_template -> GetYaxis() -> GetXmax());
				   
      TH2F * gluon_hist = makeTH2F(gluon_hist_name, 
				   hist_template -> GetNbinsX(), 
				   hist_template -> GetXaxis() -> GetXmin(),
				   hist_template -> GetXaxis() -> GetXmax(),
				   hist_template -> GetNbinsY(), 
				   hist_template -> GetYaxis() -> GetXmin(),
				   hist_template -> GetYaxis() -> GetXmax());
				   
      m_quark_rcut_th2[(*rcut_values)[i_rcutValue]].push_back(quark_hist);
      m_gluon_rcut_th2[(*rcut_values)[i_rcutValue]].push_back(gluon_hist);
      
    }
  }

  
  
  //--------------------------------------------------------------------------------
  // Loop over the events
  //--------------------------------------------------------------------------------
  
  for (int iEvent = 0; iEvent < n_events; ++iEvent){

    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------

    if ( (iEvent + 1) <= 10 || (iEvent + 1) % 100 == 0 ) 
      std::cout << "Processing event " << (iEvent + 1) << "/" << n_events << std::endl;
    
    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    tree -> GetEntry (iEvent);

    //--------------------------------------------------------------------------------
    // GEN particle collections
    //--------------------------------------------------------------------------------
    
    // All GEN particles
    CollectionPtr c_gen_all  ( new Collection(*tree, tree -> GenParticlePt -> size()));

    // std::cout << "------------------------------------------------------------" << std::endl;
    // c_gen_all ->  examine <GenParticle> ( "All GEN particles" );
    // 
    // continue;

    // GEN particles for jet matching
    CollectionPtr c_partons  = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_FINAL_STATE_PARTON);
    CollectionPtr c_gen_vbfq = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_HARD_SCATTER_VBF_QUARK);
    CollectionPtr c_gen_tau  = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_HARD_SCATTER_TAU);

    //--------------------------------------------------------------------------------
    // PFJet collections
    //--------------------------------------------------------------------------------

    CollectionPtr c_pfjet_all  ( new Collection(*tree, tree -> PFCA4JetPt -> size()));
    CollectionPtr c_pfjet_minPt       = c_pfjet_all   -> SkimByMinPt<PFPrunedJet> ( pfjet_pt_minimum ) ;
    CollectionPtr c_pfjet_fid         = c_pfjet_all   -> SkimByAbsEtaRange<PFPrunedJet> ( HGCAL_abseta_min, HGCAL_abseta_max );
    CollectionPtr c_pfjet_minPtAndFid = c_pfjet_minPt -> SkimByAbsEtaRange<PFPrunedJet> ( HGCAL_abseta_min, HGCAL_abseta_max );

    CollectionPtr c_pfcorejet_all  ( new Collection(*tree, tree -> PFAK1p5JetPt -> size()));
    CollectionPtr c_pfcorejet_minPt       = c_pfcorejet_all   -> SkimByMinPt<PFCoreJet> ( pfcorejet_pt_minimum ) ;
    CollectionPtr c_pfcorejet_minPtAndFid = c_pfcorejet_minPt -> SkimByAbsEtaRange<PFCoreJet> ( HGCAL_abseta_min, HGCAL_abseta_max );

    //--------------------------------------------------------------------------------
    // Clusters
    //--------------------------------------------------------------------------------

    CollectionPtr c_hgceeClusters_all  ( new Collection (*tree, tree -> HGCEEPFClusterPt  -> size()));
    CollectionPtr c_hgchefClusters_all ( new Collection (*tree, tree -> HGCHEFPFClusterPt -> size()));
    CollectionPtr c_hgchebClusters_all ( new Collection (*tree, tree -> HGCHEBPFClusterPt -> size()));
    
    //--------------------------------------------------------------------------------
    // GenJet collections
    //--------------------------------------------------------------------------------

    /*
    CollectionPtr c_genjet_all ( new Collection(*tree, tree -> GenJetPt -> size()));
    int n_genjet = c_genjet_all -> GetSize();

    for (int i_genjet = 0; i_genjet < n_genjet; ++i_genjet){
      GenJet genjet = c_genjet_all -> GetConstituent<GenJet>(i_genjet);
      int flavor = getFlavor( genjet, c_partons );
      if ( flavor == 0 ) continue;
      PFPrunedJet jet_matched_reco = c_pfjet_all -> GetClosestInDR<PFPrunedJet, GenJet>(genjet);
      double deltaR = jet_matched_reco.DeltaR( &genjet );
      double eta    = jet_matched_reco.Eta();
      double pt     = jet_matched_reco.Pt();
      
      all_recojet_matched_matchDR  -> Fill ( deltaR );
      all_recojet_matched_eta      -> Fill ( eta    );
      all_recojet_matched_pt       -> Fill ( pt     );
                                  
      if ( abs(genjet.Eta()) > HGCAL_abseta_min && 
	   abs(genjet.Eta()) < HGCAL_abseta_max ){
	
	fid_recojet_matched_matchDR -> Fill ( deltaR ) ;
	fid_recojet_matched_eta     -> Fill ( eta    ) ;
	fid_recojet_matched_pt      -> Fill ( pt     ) ;
      }
    }
    */

    //--------------------------------------------------------------------------------
    // Match PFJets 
    //--------------------------------------------------------------------------------

    int n_gen_vbfq = c_gen_vbfq -> GetSize();

    for (int i_gen_vbfq = 0; i_gen_vbfq < n_gen_vbfq; ++i_gen_vbfq){

      GenParticle vbfq_gen  = c_gen_vbfq    -> GetConstituent<GenParticle> (i_gen_vbfq);
      PFPrunedJet vbfq_reco = c_pfjet_minPt -> GetClosestInDR<PFPrunedJet, GenParticle>(vbfq_gen);      

      if ( vbfq_reco.GetRawIndex() < 0 ) continue;
      double pull, rawPull;
      if ( vbfq_gen.Pt() > 0. ) pull    = (vbfq_reco.Pt()    - vbfq_gen.Pt()) / vbfq_gen.Pt();
      if ( vbfq_gen.Pt() > 0. ) rawPull = (vbfq_reco.PtRaw() - vbfq_gen.Pt()) / vbfq_gen.Pt();
      else continue;
      
      bool isFid = ( fabs(vbfq_gen.Eta()) >= HGCAL_abseta_min &&
		     fabs(vbfq_gen.Eta()) <= HGCAL_abseta_max );

      double deltaR = vbfq_reco.DeltaR(&vbfq_gen);
      if ( deltaR > maximum_deltaR_match ) continue;

      all_vbfq_ptVsPull -> Fill ( vbfq_gen.Pt(), pull );
      all_vbfq_pull     -> Fill ( pull );
      all_vbfq_rawPull  -> Fill ( rawPull );
      all_vbfq_gen_pt   -> Fill ( vbfq_gen.Pt() );
      all_vbfq_reco_pt  -> Fill ( vbfq_reco.Pt() );
      all_vbfq_gen_eta  -> Fill ( vbfq_gen.Eta() );
      all_vbfq_reco_eta -> Fill ( vbfq_reco.Eta() );
      all_vbfq_matchDR  -> Fill ( deltaR );

      if ( isFid ){
	fid_vbfq_reco_chargedFraction -> Fill ( vbfq_reco.getChargedFraction() );
	fid_vbfq_reco_neutralFraction -> Fill ( vbfq_reco.getNeutralFraction() );
	fid_vbfq_ptVsPull -> Fill ( vbfq_gen.Pt(), pull );
	fid_vbfq_pull     -> Fill ( pull );
	fid_vbfq_rawPull  -> Fill ( rawPull );
	fid_vbfq_gen_pt   -> Fill ( vbfq_gen.Pt() );
	fid_vbfq_reco_pt  -> Fill ( vbfq_reco.Pt() );
	fid_vbfq_gen_eta  -> Fill ( vbfq_gen.Eta() );
	fid_vbfq_reco_eta -> Fill ( vbfq_reco.Eta() );
	fid_vbfq_matchDR  -> Fill ( vbfq_reco.DeltaR(&vbfq_gen));
      }
    }

    int n_gen_tau = c_gen_tau -> GetSize();
    for (int i_gen_tau = 0; i_gen_tau < n_gen_tau; ++i_gen_tau){
      GenParticle tau_gen  = c_gen_tau  -> GetConstituent<GenParticle> (i_gen_tau);
      PFPrunedJet tau_reco = c_pfjet_all -> GetClosestInDR<PFPrunedJet, GenParticle>(tau_gen);
      if ( tau_reco.GetRawIndex() < 0 ) continue;
      double pull, rawPull;
      if ( tau_gen.Pt() > 0. ) pull    = (tau_reco.Pt()    - tau_gen.Pt()) / tau_gen.Pt();
      if ( tau_gen.Pt() > 0. ) rawPull = (tau_reco.PtRaw() - tau_gen.Pt()) / tau_gen.Pt();
      bool isFid = ( fabs(tau_gen.Eta()) >= HGCAL_abseta_min &&
		     fabs(tau_gen.Eta()) <= HGCAL_abseta_max );


      all_tau_ptVsPull -> Fill ( tau_gen.Pt(), pull );
      all_tau_pull     -> Fill ( pull );
      all_tau_rawPull  -> Fill ( rawPull );
      all_tau_gen_pt   -> Fill ( tau_gen.Pt() );
      all_tau_reco_pt  -> Fill ( tau_reco.Pt() );
      all_tau_gen_eta   -> Fill ( tau_gen.Eta() );
      all_tau_reco_eta  -> Fill ( tau_reco.Eta() );

      if ( isFid ){
	fid_tau_ptVsPull -> Fill ( tau_gen.Pt(), pull );
	fid_tau_pull     -> Fill ( pull );
	fid_tau_rawPull  -> Fill ( rawPull );
	fid_tau_gen_pt   -> Fill ( tau_gen.Pt() );
	fid_tau_reco_pt  -> Fill ( tau_reco.Pt() );
	fid_tau_gen_eta   -> Fill ( tau_gen.Eta() );
	fid_tau_reco_eta  -> Fill ( tau_reco.Eta() );
      }
    }

    //--------------------------------------------------------------------------------
    // Loop over rcut values
    //--------------------------------------------------------------------------------

    for (int i_rcutValue = 0; i_rcutValue < n_rcutValues; ++i_rcutValue){

      fillPlots<PFPrunedJet> ( c_pfjet_minPtAndFid, c_pfcorejet_minPtAndFid , c_partons,
			       c_hgceeClusters_all, c_hgchefClusters_all, c_hgchebClusters_all, 
			       likelihoods[i_rcutValue], i_rcutValue,
    			       m_quark_rcut_th1[(*rcut_values)[i_rcutValue]], 
    			       m_gluon_rcut_th1[(*rcut_values)[i_rcutValue]], 
    			       m_quark_rcut_th2[(*rcut_values)[i_rcutValue]], 
    			       m_gluon_rcut_th2[(*rcut_values)[i_rcutValue]] );
      
    }
    // end loop over r-cut values
  } // end loop over events
} // end loop function
