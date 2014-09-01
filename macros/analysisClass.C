#include "analysisClass.h"
#include "PFPrunedR5Jet.h"
#include "GenParticle.h"
#include "Collection.h"
#include "HgcalTupleTree.h"

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
  // Make histograms
  //--------------------------------------------------------------------------------

  TH1F * h_DR_pfJet_vbfQuark = makeTH1F("DR_pfJet_vbfQuark", 100, 0, 5.0);
  TH1F * h_nsubj_quarkJets   = makeTH1F("nsubj_quarkJets"   , 100, 0, 1);
  TH1F * h_nsubj_gluonJets   = makeTH1F("nsubj_gluonJets"   , 100, 0, 1);

  TH2F * h_pfCandId_vs_count_vbfJets = makeTH2F("pfCandId_vs_count_vbfJets", 9, -0.5, 8.5, 201, -0.5, 200.5);
  TH2F * h_pfCandId_vs_count_hbJets  = makeTH2F("pfCandId_vs_count_hbJets" , 9, -0.5, 8.5, 201, -0.5, 200.5);
  TH2F * h_pfCandId_vs_count_hgcJets = makeTH2F("pfCandId_vs_count_hgcJets", 9, -0.5, 8.5, 201, -0.5, 200.5);
			
  preparePFCandAxis(h_pfCandId_vs_count_vbfJets);
  preparePFCandAxis(h_pfCandId_vs_count_hbJets );
  preparePFCandAxis(h_pfCandId_vs_count_hgcJets);
  
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
    
    // VBF quarks
    CollectionPtr c_gen_VBF     = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_HARD_SCATTER_VBF_QUARK);
    CollectionPtr c_gen_VBF_fid = c_gen_VBF -> SkimByAbsEtaRange<GenParticle> ( HGCAL_abseta_min, HGCAL_abseta_max );

    // Gluons
    CollectionPtr c_gen_glu     = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_HARD_SCATTER_GLUON);
    CollectionPtr c_gen_glu_fid = c_gen_glu -> SkimByAbsEtaRange <GenParticle> ( HGCAL_abseta_min, HGCAL_abseta_max );

    //--------------------------------------------------------------------------------
    // PFJet collections
    //--------------------------------------------------------------------------------
    
    // All pruned PF jets
    CollectionPtr c_pfjet_prunedR5_all ( new Collection(*tree, tree -> PFCA4PrunedJetRCut5Pt -> size()));
    
    // VBF jets
    CollectionPtr c_pfjet_prunedR5_VBF     = c_pfjet_prunedR5_all -> SkimByRequireDRMatch<PFPrunedR5Jet, GenParticle>(c_gen_VBF, 0.4);
    CollectionPtr c_pfjet_prunedR5_VBF_fid = c_pfjet_prunedR5_VBF -> SkimByAbsEtaRange<PFPrunedR5Jet> ( HGCAL_abseta_min, HGCAL_abseta_max ); 
    
    // Gluon jets
    CollectionPtr c_pfjet_prunedR5_glu     = c_pfjet_prunedR5_all -> SkimByRequireDRMatch<PFPrunedR5Jet, GenParticle>(c_gen_glu, 0.4);
    CollectionPtr c_pfjet_prunedR5_glu_fid = c_pfjet_prunedR5_glu -> SkimByAbsEtaRange<PFPrunedR5Jet> ( HGCAL_abseta_min, HGCAL_abseta_max ); 
    
    
  }

}
