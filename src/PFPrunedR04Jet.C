#include "PFPrunedR04Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR04Jet::PFPrunedR04Jet():
  PFPrunedJet(){}

PFPrunedR04Jet::PFPrunedR04Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR04Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Pt           -> at ( m_raw_index );    }
double & PFPrunedR04Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Eta          -> at ( m_raw_index );    } 
double & PFPrunedR04Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Phi          -> at ( m_raw_index );    } 
double & PFPrunedR04Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Tau1         -> at ( m_raw_index );    }
double & PFPrunedR04Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Tau2         -> at ( m_raw_index );    }
double & PFPrunedR04Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Tau3         -> at ( m_raw_index );    }
double & PFPrunedR04Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR04Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Mass         -> at ( m_raw_index );    }
double & PFPrunedR04Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR04Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR04Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut04NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR04Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut04DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR04Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut04DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR04Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut04DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR04Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut04DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR04Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut04PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR04Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut04PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR04Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

