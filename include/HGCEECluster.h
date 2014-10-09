#ifndef HGCEE_PF_CLUSTER
#define HGCEE_PF_CLUSTER

#include "PFCluster.h"
#include "HGCEERecHit.h"

class HGCEECluster : public PFCluster { 
  
 public:
  HGCEECluster();
  HGCEECluster(Collection& c, unsigned short i, short j = 0);
  
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

  int getNHGCEERecHits();
  HGCEERecHit getHGCEERecHit (int i);
  
 private:
  double m_et;
  
};

#endif
