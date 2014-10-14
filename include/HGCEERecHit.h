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

  void    SetClusterEta( double e ) { m_clusterEta = e; } 
  double  EffMIPToInvGeV() { 
    double _coef_a = 168.0;
    double _coef_b = 0.6871;
    double _coef_c = 0.9038;
    return _coef_a/(1.0 + std::exp(-_coef_c - _coef_b*std::cosh(m_clusterEta)));
  }
  double  weight (){ 
    int layer = Layer();
    if      ( layer ==  1 )                return 0.42;
    else if ( layer >=  2 && layer <= 11 ) return 1.00;
    else if ( layer >= 12 && layer <= 21 ) return 1.61;
    else if ( layer >- 22 && layer <= 31 ) return 2.44;
    return -999.;
  }
  double  EnergyMIP() { return Energy()/ ( 55.1*1e-6); }
  double  EnergyCorr(){ 
    double retval = 1.0;
    retval *= EnergyMIP();
    retval *= weight();
    retval /= EffMIPToInvGeV();
    return retval;
  }
    
  // IDs 

  bool PassUserID ( ID id, bool verbose = false ); 
  
 private:
  double m_et;
  double m_clusterEta;

};

std::ostream& operator<< (std::ostream& stream, HGCEERecHit& object);

#endif
