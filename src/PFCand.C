#include "PFCand.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors

PFCand::PFCand():
  Object(){}

PFCand::PFCand(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFCand") {}

// Kinematic variables

int    & PFCand::Id  () { return m_collection -> GetData() -> PFCandId  -> at ( m_raw_index ); }
double & PFCand::Pt  () { return m_collection -> GetData() -> PFCandPt  -> at ( m_raw_index ); }
double & PFCand::Eta () { return m_collection -> GetData() -> PFCandEta -> at ( m_raw_index ); } 
double & PFCand::Phi () { return m_collection -> GetData() -> PFCandPhi -> at ( m_raw_index ); } 

HGCEERecHit PFCand::getHGCEERecHit (int i){
  int rechit_index = m_collection -> GetData() -> PFCandHGCEERecHitIndex -> at ( m_raw_index )[i];
  HGCEERecHit retval ( *m_collection, rechit_index );
  return retval;
}

HGCHEBRecHit PFCand::getHGCHEBRecHit (int i){
  int rechit_index = m_collection -> GetData() -> PFCandHGCHEBRecHitIndex -> at ( m_raw_index )[i];
  HGCHEBRecHit retval ( *m_collection, rechit_index );
  return retval;
}

HGCHEFRecHit PFCand::getHGCHEFRecHit (int i){
  int rechit_index = m_collection -> GetData() -> PFCandHGCHEFRecHitIndex -> at ( m_raw_index )[i];
  HGCHEFRecHit retval ( *m_collection, rechit_index );
  return retval;
}

int PFCand::getNHGCEERecHits() { return m_collection -> GetData() -> PFCandHGCEERecHitIndex  -> at ( m_raw_index ).size(); }
int PFCand::getNHGCHEBRecHits(){ return m_collection -> GetData() -> PFCandHGCHEBRecHitIndex -> at ( m_raw_index ).size(); }
int PFCand::getNHGCHEFRecHits(){ return m_collection -> GetData() -> PFCandHGCHEFRecHitIndex -> at ( m_raw_index ).size(); }

std::ostream& operator<<(std::ostream& stream, PFCand& object) {
  stream << object.Name() << " " << ": "
	 << "Id = "  << object.Id ()    << ", "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}
