#include "analysisClass.h"

#include "PFPrunedR5Jet.h" 
#include "PFPrunedR4Jet.h" 
#include "PFPrunedR3Jet.h" 
#include "PFPrunedR2Jet.h" 
#include "PFPrunedR1Jet.h" 
#include "PFPrunedR05Jet.h"
#include "PFPrunedR04Jet.h"
#include "PFPrunedR03Jet.h"
#include "PFPrunedR02Jet.h"
#include "PFPrunedR01Jet.h"
#include "PFPrunedR008Jet.h"
#include "PFPrunedR005Jet.h"
#include "PFPrunedR003Jet.h"
#include "PFPrunedR001Jet.h"

#include "GenParticle.h"
#include "Collection.h"
#include "HgcalTupleTree.h"

#include "likelihoodGetter.h"

#include "TH1F.h"

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
void fillPlots ( CollectionPtr jets, CollectionPtr partons, likelihoodGetter & l, 
		 std::vector<TH1F*> quark_th1, std::vector<TH1F*> gluon_th1,
		 std::vector<TH2F*> quark_th2, std::vector<TH2F*> gluon_th2 ){

  int n_jets = jets -> GetSize();

  std::vector<double> likelihood_variables;

  for (int i = 0; i < n_jets; ++i){
    Jet jet = jets -> GetConstituent<Jet>(i);
    int flavor = getFlavor ( jet , partons );
    if ( flavor == -1 ) continue;
    bool isQuarkJet ( flavor == 1 );
    bool isGluonJet ( flavor == 0 );

    likelihood_variables.clear();
    
    likelihood_variables.push_back ( jet.NDaughters() );
    likelihood_variables.push_back ( jet.getWidth()   );
    likelihood_variables.push_back ( jet.getNPFCandidates() );
    likelihood_variables.push_back ( jet.getPTD() );
    likelihood_variables.push_back ( jet.NSubJ() );

    double ee_energy     = jet.getEEEnergy();
    double ee015_energy  = jet.getEEEnergy(0, 15);
    double ee1631_energy  = jet.getEEEnergy(16, 31);
    double hef_energy    = jet.getHEFEnergy();
    double heb_energy    = jet.getHEBEnergy();
    double all_energy    = ee_energy + hef_energy + heb_energy;

    double hef11_energy  = jet.getHEFEnergy(1, 1);
    double hef22_energy  = jet.getHEFEnergy(2, 2);
    double hef34_energy  = jet.getHEFEnergy(3, 4);
    double hef56_energy  = jet.getHEFEnergy(5, 6);
    double hef712_energy = jet.getHEFEnergy(7,12);
    
    double likelihood  = l.getLikelihood ( "quarkPrunedR001Jets", likelihood_variables );
    double weighted_depth = jet.getWeightedDepth();
    double weighted_depth_noEE = jet.getWeightedDepthNoEE();

    if ( isQuarkJet ){

      quark_th1[0] -> Fill ( jet.NSubJ() );
      quark_th1[1] -> Fill ( jet.Mass() * 1000. );
      quark_th1[2] -> Fill ( jet.NDaughters() );
      quark_th1[3] -> Fill ( jet.getNPFCandidates() );
      quark_th1[4] -> Fill ( jet.getWidth() );
      quark_th1[5] -> Fill ( weighted_depth );
      quark_th1[6] -> Fill ( weighted_depth_noEE );
      quark_th1[7] -> Fill ( jet.getPTD() );
      quark_th1[8] -> Fill ( likelihood );
      quark_th1[9] -> Fill ( ee_energy / all_energy );
      quark_th1[10] -> Fill ( ee015_energy / all_energy );
      quark_th1[11] -> Fill ( ee1631_energy / all_energy );
      quark_th1[12]-> Fill ( heb_energy / all_energy );
      quark_th1[13]-> Fill ( hef_energy / all_energy );
      quark_th1[14]-> Fill ( hef11_energy / all_energy );
      quark_th1[15]-> Fill ( hef22_energy / all_energy );
      quark_th1[16]-> Fill ( hef34_energy / all_energy );
      quark_th1[17]-> Fill ( hef56_energy / all_energy );
      quark_th1[18]-> Fill ( hef712_energy / all_energy );

      quark_th2[0] -> Fill ( jet.Pt(), weighted_depth );
      quark_th2[1] -> Fill ( jet.Pt(), jet.getMaxRHDepth());
      quark_th2[2] -> Fill ( jet.getNPFCandidates(), jet.NDaughters() );
    }
    
    if ( isGluonJet ){

      gluon_th1[0] -> Fill ( jet.NSubJ() );
      gluon_th1[1] -> Fill ( jet.Mass() * 1000. );
      gluon_th1[2] -> Fill ( jet.NDaughters() );
      gluon_th1[3] -> Fill ( jet.getNPFCandidates() );
      gluon_th1[4] -> Fill ( jet.getWidth() );
      gluon_th1[5] -> Fill ( weighted_depth );
      gluon_th1[6] -> Fill ( weighted_depth_noEE );
      gluon_th1[7] -> Fill ( jet.getPTD() );
      gluon_th1[8] -> Fill ( likelihood );
      gluon_th1[9] -> Fill ( ee_energy / all_energy );

      gluon_th1[10] -> Fill ( ee015_energy / all_energy );
      gluon_th1[11] -> Fill ( ee1631_energy / all_energy );
      gluon_th1[12]-> Fill ( heb_energy / all_energy );
      gluon_th1[13]-> Fill ( hef_energy / all_energy );
      gluon_th1[14]-> Fill ( hef11_energy / all_energy );
      gluon_th1[15]-> Fill ( hef22_energy / all_energy );
      gluon_th1[16]-> Fill ( hef34_energy / all_energy );
      gluon_th1[17]-> Fill ( hef56_energy / all_energy );
      gluon_th1[18]-> Fill ( hef712_energy / all_energy );

      gluon_th2[0] -> Fill ( jet.Pt(), weighted_depth );
      gluon_th2[1] -> Fill ( jet.Pt(), jet.getMaxRHDepth());
      gluon_th2[2] -> Fill ( jet.getNPFCandidates(), jet.NDaughters() );
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

  float HGCAL_abseta_min = 1.4;
  float HGCAL_abseta_max = 3.0;
  
  //--------------------------------------------------------------------------------
  // Declare tree(s)
  //--------------------------------------------------------------------------------
  
  HgcalTupleTree * tree = getTree<HgcalTupleTree>("hgcal_tree");
  int n_events = tree -> fChain -> GetEntries();

  //--------------------------------------------------------------------------------
  // Likelihood getter
  //--------------------------------------------------------------------------------

  std::vector<std::string> likelihood_variables;
  likelihood_variables.push_back ( "nDaught" );
  likelihood_variables.push_back ( "width"   );
  likelihood_variables.push_back ( "multi"   );
  likelihood_variables.push_back ( "ptd"     );
  likelihood_variables.push_back ( "nsubj"   );
  
  std::vector<std::string> signals;
  signals.push_back ( "quarkPrunedR001Jets" );

  std::string file_name ("likelihood_hists_fromQQH.root");

  likelihoodGetter l ( file_name, likelihood_variables, signals );
  
  //--------------------------------------------------------------------------------
  // Make histograms
  //--------------------------------------------------------------------------------

  std::vector<TH1F*> th1_templates;
  th1_templates.push_back ( makeTH1F ("nsubj"                 , 20  ,  0. ,     1.  )); // 0
  th1_templates.push_back ( makeTH1F ("mass"                  ,2000 ,  0. , 20000.  )); // 1
  th1_templates.push_back ( makeTH1F ("nDaught"               , 50  , -0.5,    49.5 )); // 2
  th1_templates.push_back ( makeTH1F ("multi"                 , 100 , -0.5,    99.5 ));	// 3
  th1_templates.push_back ( makeTH1F ("width"                 , 200 ,  0. ,     1.  ));	// 4
  th1_templates.push_back ( makeTH1F ("depth"                 , 200 ,  0. ,  1000.  ));	// 5
  th1_templates.push_back ( makeTH1F ("depth_noEE"            , 200 ,  0. ,  1000.  ));	// 6
  th1_templates.push_back ( makeTH1F ("ptd"                   ,  20 ,  0. ,     1.  ));	// 7
  th1_templates.push_back ( makeTH1F ("like"                  ,1000 ,  0. ,     1.  ));	// 8
  th1_templates.push_back ( makeTH1F ("ee_energy_fraction"    , 100 ,  0. ,     1.  ));	// 9
  th1_templates.push_back ( makeTH1F ("ee015_energy_fraction" , 100 ,  0. ,     1.  ));	// 9
  th1_templates.push_back ( makeTH1F ("ee1631_energy_fraction" , 100 ,  0. ,     1.  ));	// 9
  th1_templates.push_back ( makeTH1F ("heb_energy_fraction"   , 100 ,  0. ,     1.  ));	// 10
  th1_templates.push_back ( makeTH1F ("hef_energy_fraction"   , 100 ,  0. ,     1.  ));	// 11
  th1_templates.push_back ( makeTH1F ("hef11_energy_fraction" , 100 ,  0. ,     1.  ));	// 12
  th1_templates.push_back ( makeTH1F ("hef22_energy_fraction" , 100 ,  0. ,     1.  ));	// 13
  th1_templates.push_back ( makeTH1F ("hef34_energy_fraction" , 100 ,  0. ,     1.  ));	// 14
  th1_templates.push_back ( makeTH1F ("hef56_energy_fraction" , 100 ,  0. ,     1.  ));	// 15
  th1_templates.push_back ( makeTH1F ("hef712_energy_fraction", 100 ,  0. ,     1.  )); // 16
			    
  std::vector<TH2F*> th2_templates;
  th2_templates.push_back ( makeTH2F ("jetPt_vs_depth"      , 100, 0, 250, 200 ,  0. ,  1000.  ));
  th2_templates.push_back ( makeTH2F ("jetPt_vs_maxRHDepth" , 100, 0, 250, 200 ,  0. ,  1000.  ));
  th2_templates.push_back ( makeTH2F ("NPFCands_vs_NSubJets", 51 , -0.5, 50.5, 51 , -0.5, 50.5 ));

  std::vector<std::string> rcut_values;
  rcut_values.push_back ( "R5" );
  rcut_values.push_back ( "R4" );
  rcut_values.push_back ( "R3" );
  rcut_values.push_back ( "R2" );
  rcut_values.push_back ( "R1" );
  rcut_values.push_back ( "R05" );
  rcut_values.push_back ( "R04" );
  rcut_values.push_back ( "R03" );
  rcut_values.push_back ( "R02" );
  rcut_values.push_back ( "R01" );
  rcut_values.push_back ( "R008" );
  rcut_values.push_back ( "R005" );
  rcut_values.push_back ( "R003" );
  rcut_values.push_back ( "R001" );

  std::map<std::string, std::vector<TH1F*> > m_quark_rcut_th1;
  std::map<std::string, std::vector<TH1F*> > m_gluon_rcut_th1;
  std::map<std::string, std::vector<TH2F*> > m_quark_rcut_th2;
  std::map<std::string, std::vector<TH2F*> > m_gluon_rcut_th2;
  
  int n_th1_templates = th1_templates.size();
  int n_th2_templates = th2_templates.size();
  int n_rcutValues    = rcut_values.size();
  char quark_hist_name[100];
  char gluon_hist_name[100];
  
  for (int i_th1_template = 0; i_th1_template < n_th1_templates; ++i_th1_template){
    for (int i_rcutValue = 0; i_rcutValue < n_rcutValues; ++i_rcutValue ){
      
      TH1F * hist_template = th1_templates[i_th1_template];
      
      sprintf(quark_hist_name, "%s_quarkPruned%sJets", hist_template -> GetName(), rcut_values[i_rcutValue].c_str());
      sprintf(gluon_hist_name, "%s_gluonPruned%sJets", hist_template -> GetName(), rcut_values[i_rcutValue].c_str());
      
      TH1F * quark_hist = makeTH1F(quark_hist_name, 
				   hist_template -> GetNbinsX(), 
				   hist_template -> GetXaxis() -> GetXmin(),
				   hist_template -> GetXaxis() -> GetXmax() );
				   
      TH1F * gluon_hist = makeTH1F(gluon_hist_name, 
				   hist_template -> GetNbinsX(), 
				   hist_template -> GetXaxis() -> GetXmin(),
				   hist_template -> GetXaxis() -> GetXmax() );

      m_quark_rcut_th1[rcut_values[i_rcutValue]].push_back(quark_hist);
      m_gluon_rcut_th1[rcut_values[i_rcutValue]].push_back(gluon_hist);
      
    }
  }

  
  for (int i_th2_template = 0; i_th2_template < n_th2_templates; ++i_th2_template){
    for (int i_rcutValue = 0; i_rcutValue < n_rcutValues; ++i_rcutValue ){
      
      TH2F * hist_template = th2_templates[i_th2_template];
      
      sprintf(quark_hist_name, "%s_quarkPruned%sJets", hist_template -> GetName(), rcut_values[i_rcutValue].c_str());
      sprintf(gluon_hist_name, "%s_gluonPruned%sJets", hist_template -> GetName(), rcut_values[i_rcutValue].c_str());
      
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
				   
      m_quark_rcut_th2[rcut_values[i_rcutValue]].push_back(quark_hist);
      m_gluon_rcut_th2[rcut_values[i_rcutValue]].push_back(gluon_hist);
      
    }
  }

  
  
  //--------------------------------------------------------------------------------
  // Loop over the events
  //--------------------------------------------------------------------------------
  
  for (int iEvent = 0; iEvent < n_events; ++iEvent){
  
    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------

    if ( (iEvent + 1) <= 10 || (iEvent + 1) % 100 == 0 ) std::cout << "Processing event " << (iEvent + 1) << "/" << n_events << std::endl;
      

    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    tree -> GetEntry (iEvent);

    //--------------------------------------------------------------------------------
    // GEN particle collections
    //--------------------------------------------------------------------------------
    
    // All GEN particles
    CollectionPtr c_gen_all  ( new Collection(*tree, tree -> GenParticlePt -> size()));

    // GEN particles for jet matching
    CollectionPtr c_partons = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_FINAL_STATE_PARTON);

    //--------------------------------------------------------------------------------
    // PFJet collections
    //--------------------------------------------------------------------------------
    
    std::vector<std::string>::iterator i_rcut     = rcut_values.begin();
    std::vector<std::string>::iterator i_rcut_end = rcut_values.end();
    
    for (; i_rcut != i_rcut_end; ++i_rcut){
      
      if      ( i_rcut -> compare( "R5" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR5Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR5Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R4" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR4Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR4Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R3" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR3Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR3Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R2" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR2Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR2Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R1" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR1Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR1Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R05" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR05Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR05Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R04" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR04Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR04Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R03" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR03Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR03Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R02" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR02Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR02Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R01" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR01Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR01Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R008" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR008Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR008Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R005" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR005Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR005Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
      else if ( i_rcut -> compare( "R003" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR003Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR003Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }

      else if ( i_rcut -> compare( "R001" ) == 0 ){ 
	CollectionPtr c_pfjet_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
	CollectionPtr c_pfjet_fid = c_pfjet_all -> SkimByAbsEtaRange<PFPrunedR001Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
	fillPlots<PFPrunedR001Jet> ( c_pfjet_fid, c_partons, l, m_quark_rcut_th1[*i_rcut], m_gluon_rcut_th1[*i_rcut], m_quark_rcut_th2[*i_rcut], m_gluon_rcut_th2[*i_rcut] );
      }
      
    } // end loop over r-cut values
  } // end loop over events
} // end loop function
