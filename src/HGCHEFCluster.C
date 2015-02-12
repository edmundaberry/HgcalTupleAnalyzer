#include "HGCHEFCluster.h"
#include "HGCEERecHit.h"
#include "Object.h"
#include "IDTypes.h"
#include "RecHitTypes.h"

#include <cmath>

// Constructors

HGCHEFCluster::HGCHEFCluster():
  PFCluster(),
  m_et (-1.0)
{}

HGCHEFCluster::HGCHEFCluster(Collection& c, unsigned int i, int j ):
  PFCluster(c,i),
  m_et (-1.0)
{}

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

HGCEERecHit HGCHEFCluster::getHGCEERecHit (int i){
  int rechit_index = m_collection -> GetData() -> HGCHEFPFClusterHGCEERecHitIndex  -> at ( m_raw_index )[i];
  HGCEERecHit retval ( HGCHEF, *m_collection, rechit_index );
  retval.SetClusterEta( Eta() );
  retval.SetClusterX  ( X()   );
  retval.SetClusterY  ( Y()   );
  retval.SetClusterZ  ( Z()   );
  return retval;
}


HGCHEBRecHit HGCHEFCluster::getHGCHEBRecHit (int i){
  int rechit_index = m_collection -> GetData() -> HGCHEFPFClusterHGCHEBRecHitIndex -> at ( m_raw_index )[i];
  HGCHEBRecHit retval ( HGCHEF, *m_collection, rechit_index );
  retval.SetClusterEta( Eta() );
  retval.SetClusterX  ( X()   );
  retval.SetClusterY  ( Y()   );
  retval.SetClusterZ  ( Z()   );
  return retval;
}

HGCHEFRecHit HGCHEFCluster::getHGCHEFRecHit (int i){
  int rechit_index = m_collection -> GetData() -> HGCHEFPFClusterHGCHEFRecHitIndex -> at ( m_raw_index )[i];
  HGCHEFRecHit retval ( HGCHEF, *m_collection, rechit_index );
  retval.SetClusterEta( Eta() );
  retval.SetClusterX  ( X()   );
  retval.SetClusterY  ( Y()   );
  retval.SetClusterZ  ( Z()   );
  return retval;
}


int HGCHEFCluster::getNHGCEERecHits (){
  return m_collection -> GetData() -> HGCHEFPFClusterHGCEERecHitIndex -> at (m_raw_index).size();
}

int HGCHEFCluster::getNHGCHEBRecHits (){
  return m_collection -> GetData() -> HGCHEFPFClusterHGCHEBRecHitIndex -> at (m_raw_index).size();
}

int HGCHEFCluster::getNHGCHEFRecHits (){
  return m_collection -> GetData() -> HGCHEFPFClusterHGCHEFRecHitIndex -> at (m_raw_index).size();
}
