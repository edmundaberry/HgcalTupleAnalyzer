#ifndef HGCHEB_PF_CLUSTER
#define HGCHEB_PF_CLUSTER

#include "PFCluster.h"
#include "HGCHEBRecHit.h"

class HGCHEBCluster : public PFCluster { 
  
 public:
  HGCHEBCluster();
  HGCHEBCluster(Collection& c, unsigned short i, short j = 0);
  
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

  int getNHGCHEBRecHits();
  HGCHEBRecHit getHGCHEBRecHit (int i);
  
 private:
  double m_et;
  
};

#endif
