#include "PFPrunedR4Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR4Jet::PFPrunedR4Jet():
  PFPrunedJet(){}

PFPrunedR4Jet::PFPrunedR4Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR4Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Pt           -> at ( m_raw_index );    }
double & PFPrunedR4Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Eta          -> at ( m_raw_index );    } 
double & PFPrunedR4Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Phi          -> at ( m_raw_index );    } 
double & PFPrunedR4Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Tau1         -> at ( m_raw_index );    }
double & PFPrunedR4Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Tau2         -> at ( m_raw_index );    }
double & PFPrunedR4Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Tau3         -> at ( m_raw_index );    }
double & PFPrunedR4Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR4Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Mass         -> at ( m_raw_index );    }
double & PFPrunedR4Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR4Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR4Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut4NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR4Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut4DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR4Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut4DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR4Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut4DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR4Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut4DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR4Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut4PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR4Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut4PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR4Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

