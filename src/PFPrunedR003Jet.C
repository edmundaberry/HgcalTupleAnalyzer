#include "PFPrunedR003Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR003Jet::PFPrunedR003Jet():
  PFPrunedJet(){}

PFPrunedR003Jet::PFPrunedR003Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR003Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Pt           -> at ( m_raw_index );    }
double & PFPrunedR003Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Eta          -> at ( m_raw_index );    } 
double & PFPrunedR003Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Phi          -> at ( m_raw_index );    } 
double & PFPrunedR003Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Tau1         -> at ( m_raw_index );    }
double & PFPrunedR003Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Tau2         -> at ( m_raw_index );    }
double & PFPrunedR003Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Tau3         -> at ( m_raw_index );    }
double & PFPrunedR003Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR003Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Mass         -> at ( m_raw_index );    }
double & PFPrunedR003Jet::Energy       ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003Energy       -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR003Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR003Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut003NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR003Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut003DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR003Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut003DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR003Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut003DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR003Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut003DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR003Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut003PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR003Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut003PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR003Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

