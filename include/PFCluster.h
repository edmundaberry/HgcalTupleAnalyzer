#ifndef PFCLUSTER_H
#define PFCLUSTER_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

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
  
 private:
  double m_et;
};

#endif
