#include "HGCHEFRecHit.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCHEFRecHit::HGCHEFRecHit(rechit_type t):
  Object(),
  m_type(t),
  m_et (-1.0) {}

HGCHEFRecHit::HGCHEFRecHit(rechit_type t, Collection& c, unsigned int i, int j ):
  Object(c,i,"HGCHEFRecHit"),
  m_type(t),
  m_et (-1.0) {}


double & HGCHEFRecHit::Eta       () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterEta        -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterEta       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterEta       -> at ( m_raw_index );
}

double & HGCHEFRecHit::Phi       () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterPhi        -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterPhi       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterPhi       -> at ( m_raw_index );
}

double & HGCHEFRecHit::Energy    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterEnergy     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterEnergy    -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterEnergy    -> at ( m_raw_index );
} 
			        							       
double & HGCHEFRecHit::X         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterX          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterX         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterX         -> at ( m_raw_index );
}

double & HGCHEFRecHit::Y         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterY          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterY         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterY         -> at ( m_raw_index );
}

double & HGCHEFRecHit::Z         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterZ          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterZ         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterZ         -> at ( m_raw_index );
}

double & HGCHEFRecHit::R         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterR          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterR         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterR         -> at ( m_raw_index );
} 

int    & HGCHEFRecHit::Layer     () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterLayer      -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEFClusterLayer     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCHEBClusterLayer     -> at ( m_raw_index );
}

int    & HGCHEFRecHit::Cell      () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterCell       -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterCell       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterCell       -> at ( m_raw_index );
}

int    & HGCHEFRecHit::Sector    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSector     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSector     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSector     -> at ( m_raw_index );
}

int    & HGCHEFRecHit::Subdet    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
}

int    & HGCHEFRecHit::SubSector () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEFRecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
}


// Kinematic variables

double & HGCHEFRecHit::Pt        () { Et(); return m_et; }
double & HGCHEFRecHit::Et        () { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
	
std::ostream& operator<<(std::ostream& stream, HGCHEFRecHit& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

