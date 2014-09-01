#ifndef HGCHEB_RECHIT_H
#define HGCHEB_RECHIT_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

class HGCHEBRecHit : public Object { 

 public:

  HGCHEBRecHit();
  HGCHEBRecHit(Collection& c, unsigned short i, short j = 0);
  
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

std::ostream& operator<< (std::ostream& stream, HGCHEBRecHit& object);

#endif
