#include "PFPrunedR001Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR001Jet::PFPrunedR001Jet():
  PFPrunedJet(){}

PFPrunedR001Jet::PFPrunedR001Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR001Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Pt           -> at ( m_raw_index );    }
double & PFPrunedR001Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Eta          -> at ( m_raw_index );    } 
double & PFPrunedR001Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Phi          -> at ( m_raw_index );    } 
double & PFPrunedR001Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Tau1         -> at ( m_raw_index );    }
double & PFPrunedR001Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Tau2         -> at ( m_raw_index );    }
double & PFPrunedR001Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Tau3         -> at ( m_raw_index );    }
double & PFPrunedR001Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR001Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001Mass         -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR001Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR001Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut001NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR001Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut001DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR001Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut001DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR001Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut001DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR001Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut001DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR001Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut001PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR001Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut001PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR001Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

