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

std::ostream& operator<<(std::ostream& stream, PFCand& object) {
  stream << object.Name() << " " << ": "
	 << "Id = "  << object.Id ()    << ", "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

