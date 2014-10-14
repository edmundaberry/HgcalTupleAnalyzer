#include "PFPrunedR2Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR2Jet::PFPrunedR2Jet():
  PFPrunedJet(){}

PFPrunedR2Jet::PFPrunedR2Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR2Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Pt           -> at ( m_raw_index );    }
double & PFPrunedR2Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Eta          -> at ( m_raw_index );    } 
double & PFPrunedR2Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Phi          -> at ( m_raw_index );    } 
double & PFPrunedR2Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Tau1         -> at ( m_raw_index );    }
double & PFPrunedR2Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Tau2         -> at ( m_raw_index );    }
double & PFPrunedR2Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Tau3         -> at ( m_raw_index );    }
double & PFPrunedR2Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR2Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Mass         -> at ( m_raw_index );    }
double & PFPrunedR2Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR2Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR2Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut2NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR2Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut2DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR2Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut2DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR2Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut2DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR2Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut2DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR2Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut2PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR2Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut2PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR2Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

