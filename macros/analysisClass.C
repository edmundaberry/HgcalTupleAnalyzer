#include "analysisClass.h"
#include "GenJet.h"
#include "GenParticle.h"
#include "Collection.h"
#include "HgcalTupleTree.h"

#include "TH1F.h"

void analysisClass::loop(){

  //--------------------------------------------------------------------------------
  // Declare tree(s)
  //--------------------------------------------------------------------------------
  
  HgcalTupleTree * tree = getTree<HgcalTupleTree>("hgcal_tree");
  int n_events = tree -> fChain -> GetEntries();

  //--------------------------------------------------------------------------------
  // Make histograms
  //--------------------------------------------------------------------------------

  TH1F * h_DR_genJet_vbfQuark     = makeTH1F("DR_genJet_vbfQuark"    , 100, 0, 5.0);
  TH1F * h_PtPull_genJet_vbfQuark = makeTH1F("PtPull_genJet_vbfQuark", 100, -1.0, 1.0);
  TH2F * h_PtPull_vs_DR_genJet_vbfQuark = makeTH2F( "PtPull_vs_DR_genJet_vbfQuark", 100, -1.0, 1.0, 100, 0, 5.0);
  
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
    // Build initial inclusive collections
    //--------------------------------------------------------------------------------
    
    CollectionPtr c_gen_all   ( new Collection(*tree, tree -> GenParticlePt -> size()));
    CollectionPtr c_genJet_all( new Collection(*tree, tree -> GenJetPt      -> size()));
    
    //--------------------------------------------------------------------------------
    // GEN particle sorting
    //--------------------------------------------------------------------------------
    
    CollectionPtr c_gen_VBFQuarks = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_HARD_SCATTER_VBF_QUARK);
    CollectionPtr c_gen_gluons    = c_gen_all -> SkimByID<GenParticle>(GEN_PARTICLE_IS_HARD_SCATTER_GLUON);
    
    int n_VBF_quarks = c_gen_VBFQuarks -> GetSize();
    int n_gen_jets   = c_genJet_all -> GetSize();

    // Make matching plots

    for (int i_VBF_quark = 0; i_VBF_quark < n_VBF_quarks; ++i_VBF_quark){
      GenParticle vbf_quark = c_gen_VBFQuarks -> GetConstituent<GenParticle>(i_VBF_quark);
      for (int i_gen_jet = 0; i_gen_jet < n_gen_jets; ++i_gen_jet){
	GenJet gen_jet = c_genJet_all -> GetConstituent<GenJet>(i_gen_jet);
	double deltaR  = vbf_quark.DeltaR (&gen_jet);
	double pt_pull = ( gen_jet.Pt() - vbf_quark.Pt() ) / ( vbf_quark.Pt() );
	
	h_DR_genJet_vbfQuark           -> Fill ( deltaR  );
	h_PtPull_genJet_vbfQuark       -> Fill ( pt_pull );
	h_PtPull_vs_DR_genJet_vbfQuark -> Fill ( pt_pull, deltaR) ;
      }
    }
    
    CollectionPtr c_genJet_VBF = c_genJet_all -> SkimByRequireDRMatch<GenJet, GenParticle>( c_gen_VBFQuarks, 0.2 );
    
    //--------------------------------------------------------------------------------
    // Examine
    //--------------------------------------------------------------------------------
    
    c_gen_VBFQuarks -> examine<GenParticle> ( "VBF quarks" );
    c_genJet_VBF    -> examine<GenJet>      ( "VBF GenJets" );
    
  }

}
