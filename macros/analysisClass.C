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
		 TH1F * h_like_quarkJets    , TH1F * h_like_gluonJets,
		 TH1F * h_nsubj_quarkJets   , TH1F * h_nsubj_gluonJets,
		 TH1F * h_mass_quarkJets    , TH1F * h_mass_gluonJets ,
		 TH1F * h_nDaught_quarkJets , TH1F * h_nDaught_gluonJets,
		 TH1F * h_width_quarkJets   , TH1F * h_width_gluonJets,
		 TH1F * h_multi_quarkJets   , TH1F * h_multi_gluonJets,
		 TH1F * h_ptd_quarkJets     , TH1F * h_ptd_gluonJets ) {
  
  int n_jets = jets -> GetSize();

  std::vector<double> variables;

  for (int i = 0; i < n_jets; ++i){
    Jet jet = jets -> GetConstituent<Jet>(i);
    int flavor = getFlavor ( jet , partons );
    if ( flavor == -1 ) continue;
    bool isQuarkJet ( flavor == 1 );
    bool isGluonJet ( flavor == 0 );

    variables.clear();

    variables.push_back ( jet.NDaughters() );
    variables.push_back ( jet.getWidth()   );
    variables.push_back ( jet.getNPFCandidates() );
    variables.push_back ( jet.getPTD() );
    variables.push_back ( jet.NSubJ() );
    
    double likelihood  = l.getLikelihood    ( "quarkPrunedR001Jets", variables );

    // std::cout << "ptd = " << jet.getPTD() << std::endl;
    
    if ( isQuarkJet ){
      h_like_quarkJets    -> Fill ( likelihood );
      h_nsubj_quarkJets   -> Fill ( jet.NSubJ() );
      h_nDaught_quarkJets -> Fill ( jet.NDaughters());
      h_mass_quarkJets    -> Fill ( jet.Mass () * 1000. );
      h_ptd_quarkJets     -> Fill ( jet.getPTD () );
      h_width_quarkJets   -> Fill ( jet.getWidth () );
      h_multi_quarkJets   -> Fill ( jet.getNPFCandidates() );
    }

    if ( isGluonJet ){ 
      h_like_gluonJets    -> Fill ( likelihood );
      h_nsubj_gluonJets   -> Fill ( jet.NSubJ() );
      h_nDaught_gluonJets -> Fill ( jet.NDaughters());
      h_mass_gluonJets    -> Fill ( jet.Mass () * 1000. );
      h_ptd_gluonJets     -> Fill ( jet.getPTD () );
      h_width_gluonJets   -> Fill ( jet.getWidth () );
      h_multi_gluonJets   -> Fill ( jet.getNPFCandidates() );
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

  std::vector<std::string> variables;
  variables.push_back ( "nDaught" );
  variables.push_back ( "width"   );
  variables.push_back ( "multi"   );
  variables.push_back ( "ptd"     );
  variables.push_back ( "nsubj"   );
  
  std::vector<std::string> signals;
  signals.push_back ( "quarkPrunedR001Jets" );

  std::string file_name ("likelihood_hists_fromQQH.root");

  likelihoodGetter l ( file_name, variables, signals );
  
  //--------------------------------------------------------------------------------
  // Make histograms
  //--------------------------------------------------------------------------------

  TH1F * h_nsubj_quarkPrunedR5Jets     = makeTH1F("nsubj_quarkPrunedR5Jets"     ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR5Jets     = makeTH1F("nsubj_gluonPrunedR5Jets"     ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR5Jets      = makeTH1F("mass_quarkPrunedR5Jets"      , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR5Jets      = makeTH1F("mass_gluonPrunedR5Jets"      , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR5Jets   = makeTH1F("nDaught_quarkPrunedR5Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR5Jets   = makeTH1F("nDaught_gluonPrunedR5Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR5Jets     = makeTH1F("width_quarkPrunedR5Jets"     , 200 ,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR5Jets     = makeTH1F("multi_quarkPrunedR5Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR5Jets       = makeTH1F("ptd_quarkPrunedR5Jets"       ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR5Jets     = makeTH1F("width_gluonPrunedR5Jets"     , 200 ,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR5Jets     = makeTH1F("multi_gluonPrunedR5Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR5Jets       = makeTH1F("ptd_gluonPrunedR5Jets"       ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR5Jets      = makeTH1F("like_gluonPrunedR5Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR5Jets      = makeTH1F("like_quarkPrunedR5Jets"      ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR4Jets     = makeTH1F("nsubj_quarkPrunedR4Jets"     ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR4Jets     = makeTH1F("nsubj_gluonPrunedR4Jets"     ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR4Jets      = makeTH1F("mass_quarkPrunedR4Jets"      , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR4Jets      = makeTH1F("mass_gluonPrunedR4Jets"      , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR4Jets   = makeTH1F("nDaught_quarkPrunedR4Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR4Jets   = makeTH1F("nDaught_gluonPrunedR4Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR4Jets     = makeTH1F("width_quarkPrunedR4Jets"     , 200 ,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR4Jets     = makeTH1F("multi_quarkPrunedR4Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR4Jets       = makeTH1F("ptd_quarkPrunedR4Jets"       ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR4Jets     = makeTH1F("width_gluonPrunedR4Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR4Jets     = makeTH1F("multi_gluonPrunedR4Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR4Jets       = makeTH1F("ptd_gluonPrunedR4Jets"       ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR4Jets      = makeTH1F("like_gluonPrunedR4Jets"      ,  20 , 0   ,     1   ); 
  TH1F * h_like_quarkPrunedR4Jets      = makeTH1F("like_quarkPrunedR4Jets"      ,  20 , 0   ,     1   ); 
  
  TH1F * h_nsubj_quarkPrunedR3Jets     = makeTH1F("nsubj_quarkPrunedR3Jets"     ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR3Jets     = makeTH1F("nsubj_gluonPrunedR3Jets"     ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR3Jets      = makeTH1F("mass_quarkPrunedR3Jets"      , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR3Jets      = makeTH1F("mass_gluonPrunedR3Jets"      , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR3Jets   = makeTH1F("nDaught_quarkPrunedR3Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR3Jets   = makeTH1F("nDaught_gluonPrunedR3Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR3Jets     = makeTH1F("width_quarkPrunedR3Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR3Jets     = makeTH1F("multi_quarkPrunedR3Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR3Jets       = makeTH1F("ptd_quarkPrunedR3Jets"       ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR3Jets     = makeTH1F("width_gluonPrunedR3Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR3Jets     = makeTH1F("multi_gluonPrunedR3Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR3Jets       = makeTH1F("ptd_gluonPrunedR3Jets"       ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR3Jets      = makeTH1F("like_gluonPrunedR3Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR3Jets      = makeTH1F("like_quarkPrunedR3Jets"      ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR2Jets     = makeTH1F("nsubj_quarkPrunedR2Jets"     ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR2Jets     = makeTH1F("nsubj_gluonPrunedR2Jets"     ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR2Jets      = makeTH1F("mass_quarkPrunedR2Jets"      , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR2Jets      = makeTH1F("mass_gluonPrunedR2Jets"      , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR2Jets   = makeTH1F("nDaught_quarkPrunedR2Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR2Jets   = makeTH1F("nDaught_gluonPrunedR2Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR2Jets     = makeTH1F("width_quarkPrunedR2Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR2Jets     = makeTH1F("multi_quarkPrunedR2Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR2Jets       = makeTH1F("ptd_quarkPrunedR2Jets"       ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR2Jets     = makeTH1F("width_gluonPrunedR2Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR2Jets     = makeTH1F("multi_gluonPrunedR2Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR2Jets       = makeTH1F("ptd_gluonPrunedR2Jets"       ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR2Jets      = makeTH1F("like_gluonPrunedR2Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR2Jets      = makeTH1F("like_quarkPrunedR2Jets"      ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR1Jets     = makeTH1F("nsubj_quarkPrunedR1Jets"     ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR1Jets     = makeTH1F("nsubj_gluonPrunedR1Jets"     ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR1Jets      = makeTH1F("mass_quarkPrunedR1Jets"      , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR1Jets      = makeTH1F("mass_gluonPrunedR1Jets"      , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR1Jets   = makeTH1F("nDaught_quarkPrunedR1Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR1Jets   = makeTH1F("nDaught_gluonPrunedR1Jets"   , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR1Jets     = makeTH1F("width_quarkPrunedR1Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR1Jets     = makeTH1F("multi_quarkPrunedR1Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR1Jets       = makeTH1F("ptd_quarkPrunedR1Jets"       ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR1Jets     = makeTH1F("width_gluonPrunedR1Jets"     ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR1Jets     = makeTH1F("multi_gluonPrunedR1Jets"     , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR1Jets       = makeTH1F("ptd_gluonPrunedR1Jets"       ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR1Jets      = makeTH1F("like_gluonPrunedR1Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR1Jets      = makeTH1F("like_quarkPrunedR1Jets"      ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR05Jets    = makeTH1F("nsubj_quarkPrunedR05Jets"    ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR05Jets    = makeTH1F("nsubj_gluonPrunedR05Jets"    ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR05Jets     = makeTH1F("mass_quarkPrunedR05Jets"     , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR05Jets     = makeTH1F("mass_gluonPrunedR05Jets"     , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR05Jets  = makeTH1F("nDaught_quarkPrunedR05Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR05Jets  = makeTH1F("nDaught_gluonPrunedR05Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR05Jets    = makeTH1F("width_quarkPrunedR05Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR05Jets    = makeTH1F("multi_quarkPrunedR05Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR05Jets      = makeTH1F("ptd_quarkPrunedR05Jets"      ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR05Jets    = makeTH1F("width_gluonPrunedR05Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR05Jets    = makeTH1F("multi_gluonPrunedR05Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR05Jets      = makeTH1F("ptd_gluonPrunedR05Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR05Jets     = makeTH1F("like_gluonPrunedR05Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR05Jets     = makeTH1F("like_quarkPrunedR05Jets"     ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR04Jets    = makeTH1F("nsubj_quarkPrunedR04Jets"    ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR04Jets    = makeTH1F("nsubj_gluonPrunedR04Jets"    ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR04Jets     = makeTH1F("mass_quarkPrunedR04Jets"     , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR04Jets     = makeTH1F("mass_gluonPrunedR04Jets"     , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR04Jets  = makeTH1F("nDaught_quarkPrunedR04Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR04Jets  = makeTH1F("nDaught_gluonPrunedR04Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR04Jets    = makeTH1F("width_quarkPrunedR04Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR04Jets    = makeTH1F("multi_quarkPrunedR04Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR04Jets      = makeTH1F("ptd_quarkPrunedR04Jets"      ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR04Jets    = makeTH1F("width_gluonPrunedR04Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR04Jets    = makeTH1F("multi_gluonPrunedR04Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR04Jets      = makeTH1F("ptd_gluonPrunedR04Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR04Jets     = makeTH1F("like_gluonPrunedR04Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR04Jets     = makeTH1F("like_quarkPrunedR04Jets"     ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR03Jets    = makeTH1F("nsubj_quarkPrunedR03Jets"    ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR03Jets    = makeTH1F("nsubj_gluonPrunedR03Jets"    ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR03Jets     = makeTH1F("mass_quarkPrunedR03Jets"     , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR03Jets     = makeTH1F("mass_gluonPrunedR03Jets"     , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR03Jets  = makeTH1F("nDaught_quarkPrunedR03Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR03Jets  = makeTH1F("nDaught_gluonPrunedR03Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR03Jets    = makeTH1F("width_quarkPrunedR03Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR03Jets    = makeTH1F("multi_quarkPrunedR03Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR03Jets      = makeTH1F("ptd_quarkPrunedR03Jets"      ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR03Jets    = makeTH1F("width_gluonPrunedR03Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR03Jets    = makeTH1F("multi_gluonPrunedR03Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR03Jets      = makeTH1F("ptd_gluonPrunedR03Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR03Jets     = makeTH1F("like_gluonPrunedR03Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR03Jets     = makeTH1F("like_quarkPrunedR03Jets"     ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR02Jets    = makeTH1F("nsubj_quarkPrunedR02Jets"    ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR02Jets    = makeTH1F("nsubj_gluonPrunedR02Jets"    ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR02Jets     = makeTH1F("mass_quarkPrunedR02Jets"     , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR02Jets     = makeTH1F("mass_gluonPrunedR02Jets"     , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR02Jets  = makeTH1F("nDaught_quarkPrunedR02Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR02Jets  = makeTH1F("nDaught_gluonPrunedR02Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR02Jets    = makeTH1F("width_quarkPrunedR02Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR02Jets    = makeTH1F("multi_quarkPrunedR02Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR02Jets      = makeTH1F("ptd_quarkPrunedR02Jets"      ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR02Jets    = makeTH1F("width_gluonPrunedR02Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR02Jets    = makeTH1F("multi_gluonPrunedR02Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR02Jets      = makeTH1F("ptd_gluonPrunedR02Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR02Jets     = makeTH1F("like_gluonPrunedR02Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR02Jets     = makeTH1F("like_quarkPrunedR02Jets"     ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR01Jets    = makeTH1F("nsubj_quarkPrunedR01Jets"    ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR01Jets    = makeTH1F("nsubj_gluonPrunedR01Jets"    ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR01Jets     = makeTH1F("mass_quarkPrunedR01Jets"     , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR01Jets     = makeTH1F("mass_gluonPrunedR01Jets"     , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR01Jets  = makeTH1F("nDaught_quarkPrunedR01Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR01Jets  = makeTH1F("nDaught_gluonPrunedR01Jets"  , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR01Jets    = makeTH1F("width_quarkPrunedR01Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR01Jets    = makeTH1F("multi_quarkPrunedR01Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR01Jets      = makeTH1F("ptd_quarkPrunedR01Jets"      ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR01Jets    = makeTH1F("width_gluonPrunedR01Jets"    ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR01Jets    = makeTH1F("multi_gluonPrunedR01Jets"    , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR01Jets      = makeTH1F("ptd_gluonPrunedR01Jets"      ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR01Jets     = makeTH1F("like_gluonPrunedR01Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR01Jets     = makeTH1F("like_quarkPrunedR01Jets"     ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR008Jets   = makeTH1F("nsubj_quarkPrunedR008Jets"   ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR008Jets   = makeTH1F("nsubj_gluonPrunedR008Jets"   ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR008Jets    = makeTH1F("mass_quarkPrunedR008Jets"    , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR008Jets    = makeTH1F("mass_gluonPrunedR008Jets"    , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR008Jets = makeTH1F("nDaught_quarkPrunedR008Jets" , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR008Jets = makeTH1F("nDaught_gluonPrunedR008Jets" , 50  , -0.5,    49.5 );
  TH1F * h_width_quarkPrunedR008Jets   = makeTH1F("width_quarkPrunedR008Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR008Jets   = makeTH1F("multi_quarkPrunedR008Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR008Jets     = makeTH1F("ptd_quarkPrunedR008Jets"     ,  20 , 0   ,     1   );
  TH1F * h_width_gluonPrunedR008Jets   = makeTH1F("width_gluonPrunedR008Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR008Jets   = makeTH1F("multi_gluonPrunedR008Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR008Jets     = makeTH1F("ptd_gluonPrunedR008Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR008Jets    = makeTH1F("like_gluonPrunedR008Jets"    ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR008Jets    = makeTH1F("like_quarkPrunedR008Jets"    ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR005Jets   = makeTH1F("nsubj_quarkPrunedR005Jets"   ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR005Jets   = makeTH1F("nsubj_gluonPrunedR005Jets"   ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR005Jets    = makeTH1F("mass_quarkPrunedR005Jets"    , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR005Jets    = makeTH1F("mass_gluonPrunedR005Jets"    , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR005Jets = makeTH1F("nDaught_quarkPrunedR005Jets" , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR005Jets = makeTH1F("nDaught_gluonPrunedR005Jets" , 50  , -0.5,    49.5 );
  TH1F * h_width_gluonPrunedR005Jets   = makeTH1F("width_gluonPrunedR005Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR005Jets   = makeTH1F("multi_gluonPrunedR005Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR005Jets     = makeTH1F("ptd_gluonPrunedR005Jets"     ,  20 , 0   ,     1   );
  TH1F * h_width_quarkPrunedR005Jets   = makeTH1F("width_quarkPrunedR005Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR005Jets   = makeTH1F("multi_quarkPrunedR005Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR005Jets     = makeTH1F("ptd_quarkPrunedR005Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR005Jets    = makeTH1F("like_gluonPrunedR005Jets"    ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR005Jets    = makeTH1F("like_quarkPrunedR005Jets"    ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR003Jets   = makeTH1F("nsubj_quarkPrunedR003Jets"   ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR003Jets   = makeTH1F("nsubj_gluonPrunedR003Jets"   ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR003Jets    = makeTH1F("mass_quarkPrunedR003Jets"    , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR003Jets    = makeTH1F("mass_gluonPrunedR003Jets"    , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR003Jets = makeTH1F("nDaught_quarkPrunedR003Jets" , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR003Jets = makeTH1F("nDaught_gluonPrunedR003Jets" , 50  , -0.5,    49.5 );
  TH1F * h_width_gluonPrunedR003Jets   = makeTH1F("width_gluonPrunedR003Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR003Jets   = makeTH1F("multi_gluonPrunedR003Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR003Jets     = makeTH1F("ptd_gluonPrunedR003Jets"     ,  20 , 0   ,     1   );
  TH1F * h_width_quarkPrunedR003Jets   = makeTH1F("width_quarkPrunedR003Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR003Jets   = makeTH1F("multi_quarkPrunedR003Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR003Jets     = makeTH1F("ptd_quarkPrunedR003Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR003Jets    = makeTH1F("like_gluonPrunedR003Jets"    ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR003Jets    = makeTH1F("like_quarkPrunedR003Jets"    ,  20 , 0   ,     1   );
  
  TH1F * h_nsubj_quarkPrunedR001Jets   = makeTH1F("nsubj_quarkPrunedR001Jets"   ,  20 , 0   ,     1   );
  TH1F * h_nsubj_gluonPrunedR001Jets   = makeTH1F("nsubj_gluonPrunedR001Jets"   ,  20 , 0   ,     1   );
  TH1F * h_mass_quarkPrunedR001Jets    = makeTH1F("mass_quarkPrunedR001Jets"    , 2000,  0. , 20000.  );
  TH1F * h_mass_gluonPrunedR001Jets    = makeTH1F("mass_gluonPrunedR001Jets"    , 2000,  0. , 20000.  );
  TH1F * h_nDaught_quarkPrunedR001Jets = makeTH1F("nDaught_quarkPrunedR001Jets" , 50  , -0.5,    49.5 );
  TH1F * h_nDaught_gluonPrunedR001Jets = makeTH1F("nDaught_gluonPrunedR001Jets" , 50  , -0.5,    49.5 );
  TH1F * h_width_gluonPrunedR001Jets   = makeTH1F("width_gluonPrunedR001Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_gluonPrunedR001Jets   = makeTH1F("multi_gluonPrunedR001Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_gluonPrunedR001Jets     = makeTH1F("ptd_gluonPrunedR001Jets"     ,  20 , 0   ,     1   );
  TH1F * h_width_quarkPrunedR001Jets   = makeTH1F("width_quarkPrunedR001Jets"   ,  200,  0.0,     1.0 );
  TH1F * h_multi_quarkPrunedR001Jets   = makeTH1F("multi_quarkPrunedR001Jets"   , 100 , -0.5,    99.5 );
  TH1F * h_ptd_quarkPrunedR001Jets     = makeTH1F("ptd_quarkPrunedR001Jets"     ,  20 , 0   ,     1   );
  TH1F * h_like_gluonPrunedR001Jets    = makeTH1F("like_gluonPrunedR001Jets"    ,  20 , 0   ,     1   );
  TH1F * h_like_quarkPrunedR001Jets    = makeTH1F("like_quarkPrunedR001Jets"    ,  20 , 0   ,     1   );
  
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
    
    // All pruned PF jets
    CollectionPtr c_pfjet_prunedR5_all   ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt   -> size()));
    CollectionPtr c_pfjet_prunedR4_all   ( new Collection(*tree, tree -> PFCA4PrunedJetRCut4Pt   -> size()));
    CollectionPtr c_pfjet_prunedR3_all   ( new Collection(*tree, tree -> PFCA4PrunedJetRCut3Pt   -> size()));
    CollectionPtr c_pfjet_prunedR2_all   ( new Collection(*tree, tree -> PFCA4PrunedJetRCut2Pt   -> size()));
    CollectionPtr c_pfjet_prunedR1_all   ( new Collection(*tree, tree -> PFCA4PrunedJetRCut1Pt   -> size()));
    CollectionPtr c_pfjet_prunedR05_all  ( new Collection(*tree, tree -> PFCA4PrunedJetRCut05Pt  -> size()));
    CollectionPtr c_pfjet_prunedR04_all  ( new Collection(*tree, tree -> PFCA4PrunedJetRCut04Pt  -> size()));
    CollectionPtr c_pfjet_prunedR03_all  ( new Collection(*tree, tree -> PFCA4PrunedJetRCut03Pt  -> size()));
    CollectionPtr c_pfjet_prunedR02_all  ( new Collection(*tree, tree -> PFCA4PrunedJetRCut02Pt  -> size()));
    CollectionPtr c_pfjet_prunedR01_all  ( new Collection(*tree, tree -> PFCA4PrunedJetRCut01Pt  -> size()));
    CollectionPtr c_pfjet_prunedR008_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut008Pt -> size()));
    CollectionPtr c_pfjet_prunedR005_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut005Pt -> size()));
    CollectionPtr c_pfjet_prunedR003_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut003Pt -> size()));
    CollectionPtr c_pfjet_prunedR001_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut001Pt -> size()));
    
    // All fiducial pruned jets
    CollectionPtr c_pfjet_prunedR5_fid   = c_pfjet_prunedR5_all   -> SkimByAbsEtaRange<PFPrunedR5Jet>   ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR4_fid   = c_pfjet_prunedR4_all   -> SkimByAbsEtaRange<PFPrunedR4Jet>   ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR3_fid   = c_pfjet_prunedR3_all   -> SkimByAbsEtaRange<PFPrunedR3Jet>   ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR2_fid   = c_pfjet_prunedR2_all   -> SkimByAbsEtaRange<PFPrunedR2Jet>   ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR1_fid   = c_pfjet_prunedR1_all   -> SkimByAbsEtaRange<PFPrunedR1Jet>   ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR05_fid  = c_pfjet_prunedR05_all  -> SkimByAbsEtaRange<PFPrunedR05Jet>  ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR04_fid  = c_pfjet_prunedR04_all  -> SkimByAbsEtaRange<PFPrunedR04Jet>  ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR03_fid  = c_pfjet_prunedR03_all  -> SkimByAbsEtaRange<PFPrunedR03Jet>  ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR02_fid  = c_pfjet_prunedR02_all  -> SkimByAbsEtaRange<PFPrunedR02Jet>  ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR01_fid  = c_pfjet_prunedR01_all  -> SkimByAbsEtaRange<PFPrunedR01Jet>  ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR008_fid = c_pfjet_prunedR008_all -> SkimByAbsEtaRange<PFPrunedR008Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR005_fid = c_pfjet_prunedR005_all -> SkimByAbsEtaRange<PFPrunedR005Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR003_fid = c_pfjet_prunedR003_all -> SkimByAbsEtaRange<PFPrunedR003Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
    CollectionPtr c_pfjet_prunedR001_fid = c_pfjet_prunedR001_all -> SkimByAbsEtaRange<PFPrunedR001Jet> ( HGCAL_abseta_min, HGCAL_abseta_max );;
    
    //--------------------------------------------------------------------------------
    // Loop over the jets...
    //--------------------------------------------------------------------------------

    fillPlots<PFPrunedR5Jet> ( c_pfjet_prunedR5_fid, c_partons, l, 
			       h_like_quarkPrunedR5Jets    , h_like_gluonPrunedR5Jets,
			       h_nsubj_quarkPrunedR5Jets   , h_nsubj_gluonPrunedR5Jets, 
			       h_mass_quarkPrunedR5Jets    , h_mass_gluonPrunedR5Jets ,
			       h_nDaught_quarkPrunedR5Jets , h_nDaught_gluonPrunedR5Jets,
			       h_width_quarkPrunedR5Jets   , h_width_gluonPrunedR5Jets,
			       h_multi_quarkPrunedR5Jets   , h_multi_gluonPrunedR5Jets,
			       h_ptd_quarkPrunedR5Jets     , h_ptd_gluonPrunedR5Jets
			       );
    
    fillPlots<PFPrunedR4Jet> ( c_pfjet_prunedR4_fid, c_partons, l, 
			       h_like_quarkPrunedR4Jets    , h_like_gluonPrunedR4Jets,
			       h_nsubj_quarkPrunedR4Jets   , h_nsubj_gluonPrunedR4Jets, 
			       h_mass_quarkPrunedR4Jets    , h_mass_gluonPrunedR4Jets ,
			       h_nDaught_quarkPrunedR4Jets , h_nDaught_gluonPrunedR4Jets,
			       h_width_quarkPrunedR4Jets   , h_width_gluonPrunedR4Jets,
			       h_multi_quarkPrunedR4Jets   , h_multi_gluonPrunedR4Jets,
			       h_ptd_quarkPrunedR4Jets     , h_ptd_gluonPrunedR4Jets
			       );

    fillPlots<PFPrunedR3Jet> ( c_pfjet_prunedR3_fid, c_partons, l, 
			       h_like_quarkPrunedR3Jets    , h_like_gluonPrunedR3Jets,
			       h_nsubj_quarkPrunedR3Jets   , h_nsubj_gluonPrunedR3Jets, 
			       h_mass_quarkPrunedR3Jets    , h_mass_gluonPrunedR3Jets ,
			       h_nDaught_quarkPrunedR3Jets , h_nDaught_gluonPrunedR3Jets,
			       h_width_quarkPrunedR3Jets   , h_width_gluonPrunedR3Jets,
			       h_multi_quarkPrunedR3Jets   , h_multi_gluonPrunedR3Jets,
			       h_ptd_quarkPrunedR3Jets     , h_ptd_gluonPrunedR3Jets
			       );

    fillPlots<PFPrunedR2Jet> ( c_pfjet_prunedR2_fid, c_partons, l, 
			       h_like_quarkPrunedR2Jets    , h_like_gluonPrunedR2Jets,
			       h_nsubj_quarkPrunedR2Jets   , h_nsubj_gluonPrunedR2Jets, 
			       h_mass_quarkPrunedR2Jets    , h_mass_gluonPrunedR2Jets ,
			       h_nDaught_quarkPrunedR2Jets , h_nDaught_gluonPrunedR2Jets,
			       h_width_quarkPrunedR2Jets   , h_width_gluonPrunedR2Jets,
			       h_multi_quarkPrunedR2Jets   , h_multi_gluonPrunedR2Jets,
			       h_ptd_quarkPrunedR2Jets     , h_ptd_gluonPrunedR2Jets
			       );


    fillPlots<PFPrunedR1Jet> ( c_pfjet_prunedR1_fid, c_partons, l, 
			       h_like_quarkPrunedR1Jets    , h_like_gluonPrunedR1Jets,
			       h_nsubj_quarkPrunedR1Jets   , h_nsubj_gluonPrunedR1Jets, 
			       h_mass_quarkPrunedR1Jets    , h_mass_gluonPrunedR1Jets ,
			       h_nDaught_quarkPrunedR1Jets , h_nDaught_gluonPrunedR1Jets,
			       h_width_quarkPrunedR1Jets   , h_width_gluonPrunedR1Jets,
			       h_multi_quarkPrunedR1Jets   , h_multi_gluonPrunedR1Jets,
			       h_ptd_quarkPrunedR1Jets     , h_ptd_gluonPrunedR1Jets
			       );

    fillPlots<PFPrunedR05Jet> ( c_pfjet_prunedR05_fid, c_partons, l, 
				h_like_quarkPrunedR05Jets    , h_like_gluonPrunedR05Jets,
				h_nsubj_quarkPrunedR05Jets   , h_nsubj_gluonPrunedR05Jets, 
				h_mass_quarkPrunedR05Jets    , h_mass_gluonPrunedR05Jets ,
				h_nDaught_quarkPrunedR05Jets , h_nDaught_gluonPrunedR05Jets,
				h_width_quarkPrunedR05Jets   , h_width_gluonPrunedR05Jets,
				h_multi_quarkPrunedR05Jets   , h_multi_gluonPrunedR05Jets,
				h_ptd_quarkPrunedR05Jets     , h_ptd_gluonPrunedR05Jets
				);
    
    fillPlots<PFPrunedR04Jet> ( c_pfjet_prunedR04_fid, c_partons, l, 
				h_like_quarkPrunedR04Jets    , h_like_gluonPrunedR04Jets,
				h_nsubj_quarkPrunedR04Jets   , h_nsubj_gluonPrunedR04Jets, 
				h_mass_quarkPrunedR04Jets    , h_mass_gluonPrunedR04Jets ,
				h_nDaught_quarkPrunedR04Jets , h_nDaught_gluonPrunedR04Jets ,
				h_width_quarkPrunedR04Jets   , h_width_gluonPrunedR04Jets,
				h_multi_quarkPrunedR04Jets   , h_multi_gluonPrunedR04Jets,
				h_ptd_quarkPrunedR04Jets     , h_ptd_gluonPrunedR04Jets
				);

    fillPlots<PFPrunedR03Jet> ( c_pfjet_prunedR03_fid, c_partons, l, 
				h_like_quarkPrunedR03Jets    , h_like_gluonPrunedR03Jets,
				h_nsubj_quarkPrunedR03Jets   , h_nsubj_gluonPrunedR03Jets, 
				h_mass_quarkPrunedR03Jets    , h_mass_gluonPrunedR03Jets ,
				h_nDaught_quarkPrunedR03Jets , h_nDaught_gluonPrunedR03Jets,
				h_width_quarkPrunedR03Jets   , h_width_gluonPrunedR03Jets,
				h_multi_quarkPrunedR03Jets   , h_multi_gluonPrunedR03Jets,
				h_ptd_quarkPrunedR03Jets     , h_ptd_gluonPrunedR03Jets
			       );

    fillPlots<PFPrunedR02Jet> ( c_pfjet_prunedR02_fid, c_partons, l, 
				h_like_quarkPrunedR02Jets    , h_like_gluonPrunedR02Jets,
				h_nsubj_quarkPrunedR02Jets   , h_nsubj_gluonPrunedR02Jets, 
				h_mass_quarkPrunedR02Jets    , h_mass_gluonPrunedR02Jets ,
				h_nDaught_quarkPrunedR02Jets , h_nDaught_gluonPrunedR02Jets,
				h_width_quarkPrunedR02Jets   , h_width_gluonPrunedR02Jets,
				h_multi_quarkPrunedR02Jets   , h_multi_gluonPrunedR02Jets,
				h_ptd_quarkPrunedR02Jets     , h_ptd_gluonPrunedR02Jets
				);
    
    fillPlots<PFPrunedR01Jet> ( c_pfjet_prunedR01_fid, c_partons, l, 
				h_like_quarkPrunedR01Jets    , h_like_gluonPrunedR01Jets,
				h_nsubj_quarkPrunedR01Jets   , h_nsubj_gluonPrunedR01Jets, 
				h_mass_quarkPrunedR01Jets    , h_mass_gluonPrunedR01Jets ,
				h_nDaught_quarkPrunedR01Jets , h_nDaught_gluonPrunedR01Jets,
				h_width_quarkPrunedR01Jets   , h_width_gluonPrunedR01Jets,
				h_multi_quarkPrunedR01Jets   , h_multi_gluonPrunedR01Jets,
				h_ptd_quarkPrunedR01Jets     , h_ptd_gluonPrunedR01Jets
			       );


    fillPlots<PFPrunedR008Jet> ( c_pfjet_prunedR008_fid, c_partons, l, 
				 h_like_quarkPrunedR008Jets    , h_like_gluonPrunedR008Jets,
				 h_nsubj_quarkPrunedR008Jets   , h_nsubj_gluonPrunedR008Jets, 
				 h_mass_quarkPrunedR008Jets    , h_mass_gluonPrunedR008Jets ,
				 h_nDaught_quarkPrunedR008Jets , h_nDaught_gluonPrunedR008Jets,
				 h_width_quarkPrunedR008Jets   , h_width_gluonPrunedR008Jets,
				 h_multi_quarkPrunedR008Jets   , h_multi_gluonPrunedR008Jets,
				 h_ptd_quarkPrunedR008Jets     , h_ptd_gluonPrunedR008Jets
				 );

    fillPlots<PFPrunedR005Jet> ( c_pfjet_prunedR005_fid, c_partons, l, 
				 h_like_quarkPrunedR005Jets    , h_like_gluonPrunedR005Jets,
				 h_nsubj_quarkPrunedR005Jets   , h_nsubj_gluonPrunedR005Jets, 
				 h_mass_quarkPrunedR005Jets    , h_mass_gluonPrunedR005Jets ,
				 h_nDaught_quarkPrunedR005Jets , h_nDaught_gluonPrunedR005Jets ,
				 h_width_quarkPrunedR005Jets   , h_width_gluonPrunedR005Jets,
				 h_multi_quarkPrunedR005Jets   , h_multi_gluonPrunedR005Jets,
				 h_ptd_quarkPrunedR005Jets     , h_ptd_gluonPrunedR005Jets
			       );

    fillPlots<PFPrunedR003Jet> ( c_pfjet_prunedR003_fid, c_partons, l, 
				 h_like_quarkPrunedR003Jets    , h_like_gluonPrunedR003Jets,
				 h_nsubj_quarkPrunedR003Jets   , h_nsubj_gluonPrunedR003Jets, 
				 h_mass_quarkPrunedR003Jets    , h_mass_gluonPrunedR003Jets ,
				 h_nDaught_quarkPrunedR003Jets , h_nDaught_gluonPrunedR003Jets,
				 h_width_quarkPrunedR003Jets   , h_width_gluonPrunedR003Jets,
				 h_multi_quarkPrunedR003Jets   , h_multi_gluonPrunedR003Jets,
				 h_ptd_quarkPrunedR003Jets     , h_ptd_gluonPrunedR003Jets
			       );


    fillPlots<PFPrunedR001Jet> ( c_pfjet_prunedR001_fid, c_partons, l, 
				 h_like_quarkPrunedR001Jets    , h_like_gluonPrunedR001Jets,
				 h_nsubj_quarkPrunedR001Jets   , h_nsubj_gluonPrunedR001Jets, 
				 h_mass_quarkPrunedR001Jets    , h_mass_gluonPrunedR001Jets ,
				 h_nDaught_quarkPrunedR001Jets , h_nDaught_gluonPrunedR001Jets ,
				 h_width_quarkPrunedR001Jets   , h_width_gluonPrunedR001Jets,
				 h_multi_quarkPrunedR001Jets   , h_multi_gluonPrunedR001Jets,
				 h_ptd_quarkPrunedR001Jets     , h_ptd_gluonPrunedR001Jets
			       );


    
  }
}
