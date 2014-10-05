#include "PFPrunedR02Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR02Jet::PFPrunedR02Jet():
  PFPrunedJet(){}

PFPrunedR02Jet::PFPrunedR02Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR02Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Pt           -> at ( m_raw_index );    }
double & PFPrunedR02Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Eta          -> at ( m_raw_index );    } 
double & PFPrunedR02Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Phi          -> at ( m_raw_index );    } 
double & PFPrunedR02Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Tau1         -> at ( m_raw_index );    }
double & PFPrunedR02Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Tau2         -> at ( m_raw_index );    }
double & PFPrunedR02Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Tau3         -> at ( m_raw_index );    }
double & PFPrunedR02Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR02Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02Mass         -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR02Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR02Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut02NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR02Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut02DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR02Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut02DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR02Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut02DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR02Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut02DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR02Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut02PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR02Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut02PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR02Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

