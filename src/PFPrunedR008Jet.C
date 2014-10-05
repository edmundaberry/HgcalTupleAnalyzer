#include "PFPrunedR008Jet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFPrunedR008Jet::PFPrunedR008Jet():
  PFPrunedJet(){}

PFPrunedR008Jet::PFPrunedR008Jet(Collection& c, unsigned short i, short j ):
  PFPrunedJet(c,i,j) {}

// Kinematic variables

double & PFPrunedR008Jet::Pt           ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Pt           -> at ( m_raw_index );    }
double & PFPrunedR008Jet::Eta          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Eta          -> at ( m_raw_index );    } 
double & PFPrunedR008Jet::Phi          ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Phi          -> at ( m_raw_index );    } 
double & PFPrunedR008Jet::Tau1         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Tau1         -> at ( m_raw_index );    }
double & PFPrunedR008Jet::Tau2         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Tau2         -> at ( m_raw_index );    }
double & PFPrunedR008Jet::Tau3         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Tau3         -> at ( m_raw_index );    }
double & PFPrunedR008Jet::NSubJ        ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008NSubJ        -> at ( m_raw_index );    }
double & PFPrunedR008Jet::Mass         ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008Mass         -> at ( m_raw_index );    }

// Subjet variables  

double & PFPrunedR008Jet::MassDrop     ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008MassDrop     -> at ( m_raw_index );    }
int    & PFPrunedR008Jet::NDaughters   ()      { return m_collection -> GetData() -> PFCA4PrunedJetRCut008NDaughters   -> at ( m_raw_index );    }
double & PFPrunedR008Jet::DaughterEta  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut008DaughterEta  -> at ( m_raw_index )[i]; }
double & PFPrunedR008Jet::DaughterMass (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut008DaughterMass -> at ( m_raw_index )[i]; }
double & PFPrunedR008Jet::DaughterPhi  (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut008DaughterPhi  -> at ( m_raw_index )[i]; }
double & PFPrunedR008Jet::DaughterPt   (int i) { return m_collection -> GetData() -> PFCA4PrunedJetRCut008DaughterPt   -> at ( m_raw_index )[i]; }

// PF Candidate variables

PFCand PFPrunedR008Jet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4PrunedJetRCut008PFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFPrunedR008Jet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4PrunedJetRCut008PFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFPrunedR008Jet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

