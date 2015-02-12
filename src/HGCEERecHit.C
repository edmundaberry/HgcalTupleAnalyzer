#include "HGCEERecHit.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCEERecHit::HGCEERecHit(rechit_type t):
  Object(),
  m_type(t),
  m_et (-1.0)
{}

HGCEERecHit::HGCEERecHit(rechit_type t, Collection& c, unsigned int i, int j ):
  Object(c,i,"HGCEERecHit"),
  m_type(t),
  m_et (-1.0)
{}


double & HGCEERecHit::Eta       () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterEta        -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterEta       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterEta       -> at ( m_raw_index );
}

double & HGCEERecHit::Phi       () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterPhi        -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterPhi       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterPhi       -> at ( m_raw_index );
}

double & HGCEERecHit::Energy    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterEnergy     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterEnergy    -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterEnergy    -> at ( m_raw_index );
} 
			        							       
double & HGCEERecHit::X         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterX          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterX         -> at ( m_raw_index );
  else                       return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterX         -> at ( m_raw_index );
}

double & HGCEERecHit::Y         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterY          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterY         -> at ( m_raw_index );
  else                       return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterY         -> at ( m_raw_index );
}

double & HGCEERecHit::Z         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterZ          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterZ         -> at ( m_raw_index );
  else                       return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterZ         -> at ( m_raw_index );
}

double & HGCEERecHit::R         () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterR          -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterR         -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterR         -> at ( m_raw_index );
} 

int    & HGCEERecHit::Layer     () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterLayer      -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCHEFClusterLayer     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCHEBClusterLayer     -> at ( m_raw_index );
}

int    & HGCEERecHit::Cell      () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterCell       -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterCell       -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterCell       -> at ( m_raw_index );
}

int    & HGCEERecHit::Sector    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSector     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSector     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSector     -> at ( m_raw_index );
}

int    & HGCEERecHit::Subdet    () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSubdet     -> at ( m_raw_index );
}

int    & HGCEERecHit::SubSector () {
  if      ( m_type == HGCEE  ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
  else if ( m_type == HGCHEF ) return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
  else                         return m_collection -> GetData() -> HGCEERecHitFromHGCEEClusterSubSector  -> at ( m_raw_index );
}


// Kinematic variables

double & HGCEERecHit::Pt        () { Et(); return m_et; }
double & HGCEERecHit::Et        () { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
	
std::ostream& operator<<(std::ostream& stream, HGCEERecHit& object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

