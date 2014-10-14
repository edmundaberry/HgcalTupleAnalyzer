#include "HGCHEFCluster.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCHEFCluster::HGCHEFCluster():
  PFCluster(),
  m_et (-1.0) {}

HGCHEFCluster::HGCHEFCluster(Collection& c, unsigned short i, short j ):
  PFCluster(c,i),
  m_et (-1.0) {}

// Kinematic variables

double & HGCHEFCluster::Pt        () { Et(); return m_et; }
double & HGCHEFCluster::Eta       () { return m_collection -> GetData() -> HGCHEFPFClusterEta        -> at ( m_raw_index ); } 
double & HGCHEFCluster::Phi       () { return m_collection -> GetData() -> HGCHEFPFClusterPhi        -> at ( m_raw_index ); } 
double & HGCHEFCluster::Energy    () { return m_collection -> GetData() -> HGCHEFPFClusterEnergy     -> at ( m_raw_index ); } 
		        							       
double & HGCHEFCluster::X         () { return m_collection -> GetData() -> HGCHEFPFClusterX          -> at ( m_raw_index ); } 
double & HGCHEFCluster::Y         () { return m_collection -> GetData() -> HGCHEFPFClusterY          -> at ( m_raw_index ); } 
double & HGCHEFCluster::Z         () { return m_collection -> GetData() -> HGCHEFPFClusterZ          -> at ( m_raw_index ); } 
double & HGCHEFCluster::R         () { return m_collection -> GetData() -> HGCHEFPFClusterR          -> at ( m_raw_index ); } 
int    & HGCHEFCluster::Layer     () { return m_collection -> GetData() -> HGCHEFPFClusterLayer      -> at ( m_raw_index ); }

std::ostream& operator<<(std::ostream& stream, HGCHEFCluster & object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

HGCHEFRecHit HGCHEFCluster::getHGCHEFRecHit (int i){
  int rechit_index = m_collection -> GetData() -> HGCHEFPFClusterRecHitIndex -> at ( m_raw_index )[i];
  HGCHEFRecHit retval ( *m_collection, rechit_index );
  retval.SetClusterEta( Eta() );
  return retval;
}

int HGCHEFCluster::getNHGCHEFRecHits (){
  return m_collection -> GetData() -> HGCHEFPFClusterRecHitIndex -> at(m_raw_index).size();
}
