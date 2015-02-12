#ifndef PFCLUSTER_H
#define PFCLUSTER_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"


#include "HGCEERecHit.h"
#include "HGCHEBRecHit.h"
#include "HGCHEFRecHit.h"


class PFCluster : public Object { 

 public:
  PFCluster();
  PFCluster(Collection& c, unsigned short i, short j = 0);
  
  double & Et();
  
  virtual double & Pt() = 0;
  virtual double & Eta() = 0;
  virtual double & Phi() = 0;
  virtual double & Energy() = 0;

  virtual double & X() = 0;
  virtual double & Y() = 0;
  virtual double & Z() = 0;
  virtual double & R() = 0;
  double D();
  virtual int    & Layer() = 0;


  virtual int getNHGCEERecHits () = 0;
  virtual int getNHGCHEBRecHits() = 0;
  virtual int getNHGCHEFRecHits() = 0;
  
  virtual HGCEERecHit  getHGCEERecHit  (int i) = 0;
  virtual HGCHEBRecHit getHGCHEBRecHit (int i) = 0;
  virtual HGCHEFRecHit getHGCHEFRecHit (int i) = 0;
  
  double getVolume();
  double getLength();

 private:
  void calculateVolumeAndLength();
  double m_et;
  double m_volume;
  double m_length;
};

#endif
