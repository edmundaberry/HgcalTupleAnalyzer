#include "HGCEECluster.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCEECluster::HGCEECluster():
  PFCluster(),
  m_et (-1.0) {}

HGCEECluster::HGCEECluster(Collection& c, unsigned short i, short j ):
  PFCluster(c,i),
  m_et (-1.0) {}

// Kinematic variables

double & HGCEECluster::Pt        () { Et(); return m_et; }
double & HGCEECluster::Eta       () { return m_collection -> GetData() -> HGCEEPFClusterEta        -> at ( m_raw_index ); } 
double & HGCEECluster::Phi       () { return m_collection -> GetData() -> HGCEEPFClusterPhi        -> at ( m_raw_index ); } 
double & HGCEECluster::Energy    () { return m_collection -> GetData() -> HGCEEPFClusterEnergy     -> at ( m_raw_index ); } 

double & HGCEECluster::X         () { return m_collection -> GetData() -> HGCEEPFClusterX          -> at ( m_raw_index ); } 
double & HGCEECluster::Y         () { return m_collection -> GetData() -> HGCEEPFClusterY          -> at ( m_raw_index ); } 
double & HGCEECluster::Z         () { return m_collection -> GetData() -> HGCEEPFClusterZ          -> at ( m_raw_index ); } 
double & HGCEECluster::R         () { return m_collection -> GetData() -> HGCEEPFClusterR          -> at ( m_raw_index ); } 
int    & HGCEECluster::Layer     () { return m_collection -> GetData() -> HGCEEPFClusterLayer      -> at ( m_raw_index ); }

std::ostream& operator<<(std::ostream& stream, HGCEECluster & object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

HGCEERecHit HGCEECluster::getHGCEERecHit (int i){
  int rechit_index = m_collection -> GetData() -> HGCEEPFClusterRecHitIndex -> at ( m_raw_index )[i];
  HGCEERecHit retval ( *m_collection, rechit_index );
  return retval;
}

int HGCEECluster::getNHGCEERecHits (){
  return m_collection -> GetData() -> HGCEEPFClusterRecHitIndex -> size();
}
