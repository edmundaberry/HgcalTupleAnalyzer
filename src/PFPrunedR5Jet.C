#include "PFPrunedR5Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR5Jet::PFPrunedR5Jet():
  Object(){}

PFPrunedR5Jet::PFPrunedR5Jet(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFPrunedR5Jet") {}

// Kinematic variables

double & PFPrunedR5Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5Pt           -> at ( m_raw_index );    }
double & PFPrunedR5Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5Eta          -> at ( m_raw_index );    } 
double & PFPrunedR5Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5Phi          -> at ( m_raw_index );    } 
double & PFPrunedR5Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5Tau1         -> at ( m_raw_index );    }
double & PFPrunedR5Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5Tau2         -> at ( m_raw_index );    }
double & PFPrunedR5Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5Tau3         -> at ( m_raw_index );    }
double & PFPrunedR5Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5NSubJ        -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR5Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR5Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut5NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR5Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut5DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR5Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut5DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR5Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut5DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR5Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut5DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR5Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut5PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR5Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut5PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR5Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

