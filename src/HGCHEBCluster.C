#include "HGCHEBCluster.h"
#include "Object.h"
#include "IDTypes.h"

#include <cmath>

// Constructors

HGCHEBCluster::HGCHEBCluster():
  PFCluster(),
  m_et (-1.0) {}

HGCHEBCluster::HGCHEBCluster(Collection& c, unsigned short i, short j ):
  PFCluster(c,i),
  m_et (-1.0) {}

// Kinematic variables

double & HGCHEBCluster::Pt        () { Et(); return m_et; }
double & HGCHEBCluster::Eta       () { return m_collection -> GetData() -> HGCHEBPFClusterEta        -> at ( m_raw_index ); } 
double & HGCHEBCluster::Phi       () { return m_collection -> GetData() -> HGCHEBPFClusterPhi        -> at ( m_raw_index ); } 
double & HGCHEBCluster::Energy    () { return m_collection -> GetData() -> HGCHEBPFClusterEnergy     -> at ( m_raw_index ); } 
		        							       
double & HGCHEBCluster::X         () { return m_collection -> GetData() -> HGCHEBPFClusterX          -> at ( m_raw_index ); } 
double & HGCHEBCluster::Y         () { return m_collection -> GetData() -> HGCHEBPFClusterY          -> at ( m_raw_index ); } 
double & HGCHEBCluster::Z         () { return m_collection -> GetData() -> HGCHEBPFClusterZ          -> at ( m_raw_index ); } 
double & HGCHEBCluster::R         () { return m_collection -> GetData() -> HGCHEBPFClusterR          -> at ( m_raw_index ); } 
int    & HGCHEBCluster::Layer     () { return m_collection -> GetData() -> HGCHEBPFClusterLayer      -> at ( m_raw_index ); }

std::ostream& operator<<(std::ostream& stream, HGCHEBCluster & object) {
  stream << object.Name() << " " << ": "
	 << "Pt = "  << object.Pt ()    << ", "
	 << "Eta = " << object.Eta()    << ", "
	 << "Phi = " << object.Phi();
  return stream;
}

HGCHEBRecHit HGCHEBCluster::getHGCHEBRecHit (int i){
  int rechit_index = m_collection -> GetData() -> HGCHEBPFClusterRecHitIndex -> at ( m_raw_index )[i];
  HGCHEBRecHit retval ( *m_collection, rechit_index );
  retval.SetClusterEta( Eta() );
  return retval;
}

int HGCHEBCluster::getNHGCHEBRecHits (){
  return m_collection -> GetData() -> HGCHEBPFClusterRecHitIndex -> at (m_raw_index).size();
}
