#include <algorithm>
#include <cmath>

#include "GenParticle.h"
#include "Collection.h"
#include "IDTypes.h"

bool GenParticle::PassUserID (ID id, bool verbose){ 
  if      ( id == GEN_PARTICLE_IS_HARD_SCATTER_VBF_QUARK ) return PassUserID_IsVBFQuark         (verbose);
  else if ( id == GEN_PARTICLE_IS_HARD_SCATTER_QUARK     ) return PassUserID_IsHardScatterQuark (verbose);
  else if ( id == GEN_PARTICLE_IS_HARD_SCATTER_GLUON     ) return PassUserID_IsHardScatterGluon (verbose);
  else if ( id == GEN_PARTICLE_IS_FINAL_STATE_PARTON     ) return PassUserID_IsFinalStateParton (verbose);
  else if ( id == GEN_PARTICLE_IS_B_QUARK                ) return PassUserID_IsBQuark           (verbose);
  else if ( id == GEN_PARTICLE_IS_C_QUARK                ) return PassUserID_IsCQuark           (verbose);
  else if ( id == GEN_PARTICLE_IS_HARD_SCATTER_LEPTON    ) return PassUserID_IsHardScatterLepton(verbose);
  else if ( id == GEN_PARTICLE_IS_HARD_SCATTER_TAU       ) return PassUserID_IsHardScatterTau   (verbose);
  else return false;
}

bool GenParticle::PassUserID_IsBQuark ( bool verbose ) {
  return ( abs ( PdgId() ) == 5 );
}

bool GenParticle::PassUserID_IsCQuark ( bool verbose ) {
  return ( abs ( PdgId() ) == 4 );
}

bool GenParticle::PassUserID_IsFinalStateParton (bool verbose){
  if ( PdgId() >= 81 && PdgId() <= 100 ) return false;
  if ( HasPartonDaughter() == 1        ) return false;
  return true;
}

bool GenParticle::PassUserID_IsHardScatter(bool verbose){
  return ( Status() == 3 );
}

bool GenParticle::PassUserID_IsQuark(bool verbose){
  return ( abs ( PdgId() ) <= 6 );
}

bool GenParticle::PassUserID_IsLepton(bool verbose){
  return ( abs ( PdgId() ) == 11 ||
	   abs ( PdgId() ) == 13 ||
	   abs ( PdgId() ) == 15  );
}

bool GenParticle::PassUserID_IsTau(bool verbose){
  return ( abs ( PdgId() ) == 15  );
}

bool GenParticle::PassUserID_IsGluon(bool verbose){
  return ( abs (PdgId()) == 21 );
}

bool GenParticle::PassUserID_SharesHiggsMother(bool verbose){
  
  int higgs_mother_1 = -999;
  int higgs_mother_2 = -999;
  
  for (int i = 0; i < 10; ++i){
    int status = m_collection -> GetData() -> GenParticleStatus -> at(i);
    int pdgid  = m_collection -> GetData() -> GenParticlePdgId  -> at(i);
    if ( status != 3 ) continue;
    if ( pdgid  != 25) continue;
    higgs_mother_1 = m_collection -> GetData() -> GenParticleMother1Index-> at (i);
    higgs_mother_2 = m_collection -> GetData() -> GenParticleMother2Index-> at (i);
    break;
  }

  if ( higgs_mother_1 < 0 && higgs_mother_2 < 0 ) return false;

  bool match = false;
  
  if ( NumMother() == 1 ) {
    bool mother_1_match = ( Mother1Index() == higgs_mother_1 || Mother1Index() == higgs_mother_2 );
    match = mother_1_match;
  }
  else if ( NumMother() == 2 ) { 
    bool mother_1_match = ( Mother1Index() == higgs_mother_1 || Mother1Index() == higgs_mother_2 );
    bool mother_2_match = ( Mother2Index() == higgs_mother_1 || Mother2Index() == higgs_mother_2 );
    match = ( mother_1_match || mother_2_match );
  }
  
  return match;
}

bool GenParticle::PassUserID_IsFromQuark(bool verbose){
  if      ( NumMother() == 1 ) return ( abs(Mother1PdgId()) <= 6 );
  else if ( NumMother() == 2 ) return ( abs(Mother1PdgId()) <= 6 || Mother2PdgId() <= 6 );
  else return false;
}

bool GenParticle::PassUserID_IsVBFQuark(bool verbose){
  if ( ! PassUserID_SharesHiggsMother (verbose) ) return false;
  if ( ! PassUserID_IsQuark           (verbose) ) return false;
  if ( ! PassUserID_IsFromQuark       (verbose) ) return false;
  return true;
}

bool GenParticle::PassUserID_IsHardScatterQuark ( bool verbose ) {
  if ( ! PassUserID_IsHardScatter(verbose) ) return false;
  if ( ! PassUserID_IsQuark      (verbose) ) return false;
  return true;
}


bool GenParticle::PassUserID_IsHardScatterLepton ( bool verbose ) {
  if ( ! PassUserID_IsHardScatter(verbose) ) return false;
  if ( ! PassUserID_IsLepton     (verbose) ) return false;
  return true;
}


bool GenParticle::PassUserID_IsHardScatterTau ( bool verbose ) {
  if ( ! PassUserID_IsHardScatter(verbose) ) return false;
  if ( ! PassUserID_IsTau        (verbose) ) return false;
  return true;
}


bool GenParticle::PassUserID_IsHardScatterVBFQuark ( bool verbose ) {
  if ( ! PassUserID_IsHardScatter(verbose) ) return false;
  if ( ! PassUserID_IsVBFQuark   (verbose) ) return false;
  return true;
}

bool GenParticle::PassUserID_IsHardScatterGluon ( bool verbose ) {
  if ( ! PassUserID_IsHardScatter(verbose) ) return false;
  if ( ! PassUserID_IsGluon      (verbose) ) return false;
  return true;
}



