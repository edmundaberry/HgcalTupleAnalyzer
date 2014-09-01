#include "PFJet.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFJet::PFJet():
  Object(){}

PFJet::PFJet(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFJet") {}

// Kinematic variables

double & PFJet::Pt  () { return m_collection -> GetData() -> PFCA4JetPt    -> at ( m_raw_index ); }
double & PFJet::Eta () { return m_collection -> GetData() -> PFCA4JetEta   -> at ( m_raw_index ); } 
double & PFJet::Phi () { return m_collection -> GetData() -> PFCA4JetPhi   -> at ( m_raw_index ); } 

double & PFJet::Tau1() { return m_collection -> GetData() -> PFCA4JetTau1  -> at ( m_raw_index ); }
double & PFJet::Tau2() { return m_collection -> GetData() -> PFCA4JetTau2  -> at ( m_raw_index ); }
double & PFJet::Tau3() { return m_collection -> GetData() -> PFCA4JetTau3  -> at ( m_raw_index ); }
double & PFJet::NSubJ(){ return m_collection -> GetData() -> PFCA4JetNSubJ -> at ( m_raw_index ); }

PFCand PFJet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFCA4JetPFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFJet::getNPFCandidates(){
  return m_collection -> GetData() -> PFCA4JetPFCandIndices -> at ( m_raw_index ).size();
}

std::ostream& operator<<(std::ostream& stream, PFJet& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

