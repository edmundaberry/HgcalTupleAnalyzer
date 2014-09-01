#include "HGCEERecHit.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCEERecHit::HGCEERecHit():
  Object(),
  m_et (-1.0) {}

HGCEERecHit::HGCEERecHit(Collection& c, unsigned short i, short j ):
  Object(c,i,"HGCEERecHit"),
  m_et (-1.0) {}

// Kinematic variables

double & HGCEERecHit::Pt        () { Et(); return m_et; }
double & HGCEERecHit::Eta       () { return m_collection -> GetData() -> HGCEERecHitEta        -> at ( m_raw_index ); } 
double & HGCEERecHit::Phi       () { return m_collection -> GetData() -> HGCEERecHitPhi        -> at ( m_raw_index ); } 
double & HGCEERecHit::Energy    () { return m_collection -> GetData() -> HGCEERecHitEnergy     -> at ( m_raw_index ); } 
double & HGCEERecHit::Et        () { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
			        							       
double & HGCEERecHit::X         () { return m_collection -> GetData() -> HGCEERecHitX          -> at ( m_raw_index ); } 
double & HGCEERecHit::Y         () { return m_collection -> GetData() -> HGCEERecHitY          -> at ( m_raw_index ); } 
double & HGCEERecHit::Z         () { return m_collection -> GetData() -> HGCEERecHitZ          -> at ( m_raw_index ); } 
double & HGCEERecHit::R         () { return m_collection -> GetData() -> HGCEERecHitR          -> at ( m_raw_index ); } 

int    & HGCEERecHit::Layer     () { return m_collection -> GetData() -> HGCEERecHitLayer      -> at ( m_raw_index ); }
int    & HGCEERecHit::Cell      () { return m_collection -> GetData() -> HGCEERecHitCell       -> at ( m_raw_index ); }
int    & HGCEERecHit::Sector    () { return m_collection -> GetData() -> HGCEERecHitSector     -> at ( m_raw_index ); }
int    & HGCEERecHit::Subdet    () { return m_collection -> GetData() -> HGCEERecHitSubdet     -> at ( m_raw_index ); }
int    & HGCEERecHit::SubSector () { return m_collection -> GetData() -> HGCEERecHitSubSector  -> at ( m_raw_index ); }

std::ostream& operator<<(std::ostream& stream, HGCEERecHit& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

