#ifndef HGCHEB_PF_CLUSTER
#define HGCHEB_PF_CLUSTER

#include "PFCluster.h"
#include "HGCEERecHit.h"
#include "HGCHEBRecHit.h"
#include "HGCHEFRecHit.h"

class HGCHEBCluster : public PFCluster { 
  
 public:
  HGCHEBCluster();
  HGCHEBCluster(Collection& c, unsigned int i, int j = 0);
  
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

  int getNHGCEERecHits ();
  int getNHGCHEBRecHits();
  int getNHGCHEFRecHits();

  HGCEERecHit  getHGCEERecHit  (int i);
  HGCHEBRecHit getHGCHEBRecHit (int i);
  HGCHEFRecHit getHGCHEFRecHit (int i);
  
 private:
  double m_et;
  std::vector<double> m_lambdaHEF;
  std::vector<double> m_rhoRecHitHEF;
  std::vector<double> m_rhoRecHitHEFSqr;

};

#endif
