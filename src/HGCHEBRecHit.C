#include "HGCHEBRecHit.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCHEBRecHit::HGCHEBRecHit():
  Object(),
  m_et (-1.0) {}

HGCHEBRecHit::HGCHEBRecHit(Collection& c, unsigned short i, short j ):
  Object(c,i,"HGCHEBRecHit"),
  m_et (-1.0) {}

// Kinematic variables

double & HGCHEBRecHit::Pt        () { Et(); return m_et; }
double & HGCHEBRecHit::Eta       () { return m_collection -> GetData() -> HGCHEBRecHitEta        -> at ( m_raw_index ); } 
double & HGCHEBRecHit::Phi       () { return m_collection -> GetData() -> HGCHEBRecHitPhi        -> at ( m_raw_index ); } 
double & HGCHEBRecHit::Energy    () { return m_collection -> GetData() -> HGCHEBRecHitEnergy     -> at ( m_raw_index ); } 
double & HGCHEBRecHit::Et        () { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
			        							       
double & HGCHEBRecHit::X         () { return m_collection -> GetData() -> HGCHEBRecHitX          -> at ( m_raw_index ); } 
double & HGCHEBRecHit::Y         () { return m_collection -> GetData() -> HGCHEBRecHitY          -> at ( m_raw_index ); } 
double & HGCHEBRecHit::Z         () { return m_collection -> GetData() -> HGCHEBRecHitZ          -> at ( m_raw_index ); } 
double & HGCHEBRecHit::R         () { return m_collection -> GetData() -> HGCHEBRecHitR          -> at ( m_raw_index ); } 

int    & HGCHEBRecHit::Layer     () { return m_collection -> GetData() -> HGCHEBRecHitLayer      -> at ( m_raw_index ); }
int    & HGCHEBRecHit::Cell      () { return m_collection -> GetData() -> HGCHEBRecHitCell       -> at ( m_raw_index ); }
int    & HGCHEBRecHit::Sector    () { return m_collection -> GetData() -> HGCHEBRecHitSector     -> at ( m_raw_index ); }
int    & HGCHEBRecHit::Subdet    () { return m_collection -> GetData() -> HGCHEBRecHitSubdet     -> at ( m_raw_index ); }
int    & HGCHEBRecHit::SubSector () { return m_collection -> GetData() -> HGCHEBRecHitSubSector  -> at ( m_raw_index ); }

std::ostream& operator<<(std::ostream& stream, HGCHEBRecHit& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

