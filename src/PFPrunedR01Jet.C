#include "PFPrunedR01Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR01Jet::PFPrunedR01Jet():
  PFPrunedJet(){}

PFPrunedR01Jet::PFPrunedR01Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR01Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Pt           -> at ( m_raw_index );    }
double & PFPrunedR01Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Eta          -> at ( m_raw_index );    } 
double & PFPrunedR01Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Phi          -> at ( m_raw_index );    } 
double & PFPrunedR01Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Tau1         -> at ( m_raw_index );    }
double & PFPrunedR01Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Tau2         -> at ( m_raw_index );    }
double & PFPrunedR01Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Tau3         -> at ( m_raw_index );    }
double & PFPrunedR01Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR01Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Mass         -> at ( m_raw_index );    }
double & PFPrunedR01Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR01Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR01Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut01NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR01Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut01DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR01Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut01DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR01Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut01DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR01Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut01DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR01Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut01PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR01Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut01PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR01Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

