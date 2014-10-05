#include "PFPrunedR03Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR03Jet::PFPrunedR03Jet():
  PFPrunedJet(){}

PFPrunedR03Jet::PFPrunedR03Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR03Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Pt           -> at ( m_raw_index );    }
double & PFPrunedR03Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Eta          -> at ( m_raw_index );    } 
double & PFPrunedR03Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Phi          -> at ( m_raw_index );    } 
double & PFPrunedR03Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Tau1         -> at ( m_raw_index );    }
double & PFPrunedR03Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Tau2         -> at ( m_raw_index );    }
double & PFPrunedR03Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Tau3         -> at ( m_raw_index );    }
double & PFPrunedR03Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR03Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03Mass         -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR03Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR03Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut03NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR03Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut03DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR03Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut03DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR03Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut03DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR03Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut03DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR03Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut03PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR03Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut03PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR03Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

