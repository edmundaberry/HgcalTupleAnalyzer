#include "PFPrunedR005Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR005Jet::PFPrunedR005Jet():
  PFPrunedJet(){}

PFPrunedR005Jet::PFPrunedR005Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR005Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Pt           -> at ( m_raw_index );    }
double & PFPrunedR005Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Eta          -> at ( m_raw_index );    } 
double & PFPrunedR005Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Phi          -> at ( m_raw_index );    } 
double & PFPrunedR005Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Tau1         -> at ( m_raw_index );    }
double & PFPrunedR005Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Tau2         -> at ( m_raw_index );    }
double & PFPrunedR005Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Tau3         -> at ( m_raw_index );    }
double & PFPrunedR005Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR005Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005Mass         -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR005Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR005Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut005NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR005Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut005DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR005Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut005DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR005Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut005DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR005Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut005DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR005Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut005PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR005Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut005PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR005Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

