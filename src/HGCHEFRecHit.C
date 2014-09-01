#include "HGCHEFRecHit.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCHEFRecHit::HGCHEFRecHit():
  Object(),
  m_et (-1.0) {}

HGCHEFRecHit::HGCHEFRecHit(Collection& c, unsigned short i, short j ):
  Object(c,i,"HGCHEFRecHit"),
  m_et (-1.0) {}

// Kinematic variables

double & HGCHEFRecHit::Pt        () { Et(); return m_et; }
double & HGCHEFRecHit::Eta       () { return m_collection -> GetData() -> HGCHEFRecHitEta        -> at ( m_raw_index ); } 
double & HGCHEFRecHit::Phi       () { return m_collection -> GetData() -> HGCHEFRecHitPhi        -> at ( m_raw_index ); } 
double & HGCHEFRecHit::Energy    () { return m_collection -> GetData() -> HGCHEFRecHitEnergy     -> at ( m_raw_index ); } 
double & HGCHEFRecHit::Et        () { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
			        							       
double & HGCHEFRecHit::X         () { return m_collection -> GetData() -> HGCHEFRecHitX          -> at ( m_raw_index ); } 
double & HGCHEFRecHit::Y         () { return m_collection -> GetData() -> HGCHEFRecHitY          -> at ( m_raw_index ); } 
double & HGCHEFRecHit::Z         () { return m_collection -> GetData() -> HGCHEFRecHitZ          -> at ( m_raw_index ); } 
double & HGCHEFRecHit::R         () { return m_collection -> GetData() -> HGCHEFRecHitR          -> at ( m_raw_index ); } 

int    & HGCHEFRecHit::Layer     () { return m_collection -> GetData() -> HGCHEFRecHitLayer      -> at ( m_raw_index ); }
int    & HGCHEFRecHit::Cell      () { return m_collection -> GetData() -> HGCHEFRecHitCell       -> at ( m_raw_index ); }
int    & HGCHEFRecHit::Sector    () { return m_collection -> GetData() -> HGCHEFRecHitSector     -> at ( m_raw_index ); }
int    & HGCHEFRecHit::Subdet    () { return m_collection -> GetData() -> HGCHEFRecHitSubdet     -> at ( m_raw_index ); }
int    & HGCHEFRecHit::SubSector () { return m_collection -> GetData() -> HGCHEFRecHitSubSector  -> at ( m_raw_index ); }

std::ostream& operator<<(std::ostream& stream, HGCHEFRecHit& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

