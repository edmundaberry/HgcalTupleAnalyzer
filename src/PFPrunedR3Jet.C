#include "PFPrunedR3Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR3Jet::PFPrunedR3Jet():
  PFPrunedJet(){}

PFPrunedR3Jet::PFPrunedR3Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR3Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Pt           -> at ( m_raw_index );    }
double & PFPrunedR3Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Eta          -> at ( m_raw_index );    } 
double & PFPrunedR3Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Phi          -> at ( m_raw_index );    } 
double & PFPrunedR3Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Tau1         -> at ( m_raw_index );    }
double & PFPrunedR3Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Tau2         -> at ( m_raw_index );    }
double & PFPrunedR3Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Tau3         -> at ( m_raw_index );    }
double & PFPrunedR3Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR3Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Mass         -> at ( m_raw_index );    }
double & PFPrunedR3Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR3Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR3Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut3NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR3Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut3DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR3Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut3DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR3Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut3DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR3Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut3DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR3Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut3PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR3Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut3PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR3Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

