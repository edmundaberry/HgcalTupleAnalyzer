#include "PFPrunedR05Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR05Jet::PFPrunedR05Jet():
  PFPrunedJet(){}

PFPrunedR05Jet::PFPrunedR05Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR05Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Pt           -> at ( m_raw_index );    }
double & PFPrunedR05Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Eta          -> at ( m_raw_index );    } 
double & PFPrunedR05Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Phi          -> at ( m_raw_index );    } 
double & PFPrunedR05Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Tau1         -> at ( m_raw_index );    }
double & PFPrunedR05Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Tau2         -> at ( m_raw_index );    }
double & PFPrunedR05Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Tau3         -> at ( m_raw_index );    }
double & PFPrunedR05Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR05Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Mass         -> at ( m_raw_index );    }
double & PFPrunedR05Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR05Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR05Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut05NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR05Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut05DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR05Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut05DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR05Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut05DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR05Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut05DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR05Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut05PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR05Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut05PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR05Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

