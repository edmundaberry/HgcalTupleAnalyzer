#ifndef HGCHEF_PF_CLUSTER
#define HGCHEF_PF_CLUSTER

#include "PFCluster.h"
#include "HGCHEFRecHit.h"

class HGCHEFCluster : public PFCluster { 
  
 public:
  HGCHEFCluster();
  HGCHEFCluster(Collection& c, unsigned short i, short j = 0);
  
  double & Pt();
  double & Eta();
  double & Phi();
  double & Energy();

  double & X();
  double & Y();
  double & Z();
  double & R();
  int    & Layer();

  bool PassUserID ( ID id, bool verbose = false ); 

  int getNHGCHEFRecHits();
  HGCHEFRecHit getHGCHEFRecHit (int i);
  
 private:
  double m_et;
  
};

#endif
