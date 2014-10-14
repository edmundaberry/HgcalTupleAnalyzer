#include "PFPrunedR1Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR1Jet::PFPrunedR1Jet():
  PFPrunedJet(){}

PFPrunedR1Jet::PFPrunedR1Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR1Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Pt           -> at ( m_raw_index );    }
double & PFPrunedR1Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Eta          -> at ( m_raw_index );    } 
double & PFPrunedR1Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Phi          -> at ( m_raw_index );    } 
double & PFPrunedR1Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Tau1         -> at ( m_raw_index );    }
double & PFPrunedR1Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Tau2         -> at ( m_raw_index );    }
double & PFPrunedR1Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Tau3         -> at ( m_raw_index );    }
double & PFPrunedR1Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR1Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Mass         -> at ( m_raw_index );    }
double & PFPrunedR1Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR1Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR1Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut1NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR1Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut1DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR1Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut1DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR1Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut1DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR1Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut1DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR1Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut1PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR1Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut1PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR1Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

