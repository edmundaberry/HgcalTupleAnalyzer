#ifndef HGCHEF_RECHIT_H
#define HGCHEF_RECHIT_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

class HGCHEFRecHit : public Object { 

 public:

  HGCHEFRecHit();
  HGCHEFRecHit(Collection& c, unsigned short i, short j = 0);
  
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

std::ostream& operator<< (std::ostream& stream, HGCHEFRecHit& object);

#endif
