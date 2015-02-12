#include "HGCHEBRecHit.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCHEBRecHit::HGCHEBRecHit(rechit_type t):
  Object(),
  m_type(t),
  m_et (-1.0) {}

HGCHEBRecHit::HGCHEBRecHit(rechit_type t, Collection& c, unsigned int i, int j ):
  Object(c,i,"HGCHEBRecHit"),
  m_type(t),
  m_et (-1.0) {}


double & HGCHEBRecHit::Eta       () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterEta        -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterEta       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterEta       -> at ( m_raw_index );
}

double & HGCHEBRecHit::Phi       () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterPhi        -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterPhi       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterPhi       -> at ( m_raw_index );
}

double & HGCHEBRecHit::Energy    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterEnergy     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterEnergy    -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterEnergy    -> at ( m_raw_index );
} 
			        							       
double & HGCHEBRecHit::X         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterX          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterX         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterX         -> at ( m_raw_index );
}

double & HGCHEBRecHit::Y         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterY          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterY         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterY         -> at ( m_raw_index );
}

double & HGCHEBRecHit::Z         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterZ          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterZ         -> at ( m_raw_index );
  else                           return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterZ         -> at ( m_raw_index );
}

double & HGCHEBRecHit::R         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterR          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterR         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterR         -> at ( m_raw_index );
} 

int    & HGCHEBRecHit::Layer     () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterLayer      -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEFClusterLayer     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCHEBClusterLayer     -> at ( m_raw_index );
}

int    & HGCHEBRecHit::Cell      () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterCell       -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterCell       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterCell       -> at ( m_raw_index );
}

int    & HGCHEBRecHit::Sector    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSector     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSector     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSector     -> at ( m_raw_index );
}

int    & HGCHEBRecHit::Subdet    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
}

int    & HGCHEBRecHit::SubSector () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCHEBRecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
}


// Kinematic variables

double & HGCHEBRecHit::Pt        () { Et(); return m_et; }
double & HGCHEBRecHit::Et        () { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
	
std::ostream& operator<<(std::ostream& stream, HGCHEBRecHit& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

