#ifndef HGCEE_RECHIT_H
#define HGCEE_RECHIT_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

class HGCEERecHit : public Object { 

 public:

  HGCEERecHit();
  HGCEERecHit(Collection& c, unsigned short i, short j = 0);
  
  // Kinematic variables

  double & Et        ();
  double & Pt        ();
  double & Eta       ();
  double & Phi       ();
  double & Energy    ();
		     
  double & X         ();
  double & Y         ();
  double & Z         ();
  double & R         ();
  		     
  int    & Layer     ();
  int    & Cell      ();
  int    & Sector    ();
  int    & Subdet    ();
  int    & SubSector ();
  
  // IDs 

  bool PassUserID ( ID id, bool verbose = false ); 
  
 private:
  double m_et;

};

std::ostream& operator<< (std::ostream& stream, HGCEERecHit& object);

#endif
