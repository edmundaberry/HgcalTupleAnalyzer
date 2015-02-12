#ifndef HGCHEF_RECHIT_H
#define HGCHEF_RECHIT_H

#include "Object.h"
#include "IDTypes.h"
#include "RecHitTypes.h"
#include "Collection.h"

#include <cmath>

class HGCHEFRecHit : public Object { 

 public:

  HGCHEFRecHit(rechit_type t);
  HGCHEFRecHit(rechit_type t, Collection& c, unsigned int i, int j = 0);
  
  // Kinematic variables

  double & Et ();
  double & Pt ();

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
  void    SetClusterX  ( double x ) { m_clusterX   = x; } 
  void    SetClusterY  ( double y ) { m_clusterY   = y; } 
  void    SetClusterZ  ( double z ) { m_clusterZ   = z; } 

  double  XPrime() { return m_clusterX * Z() / m_clusterZ; }
  double  YPrime() { return m_clusterY * Z() / m_clusterZ; }
  double  RhoSqr() { return std::pow(X() - XPrime(),2) + std::pow ( Y() - YPrime(), 2); }
  double  Rho   () { return std::sqrt ( RhoSqr() ); }

  double  LambdaCoefficient(){ 
    if      ( Layer() == 1  ) return 0.34;
    else                      return 0.27;
  }

  double Length() { return std::tanh(Eta()) * LambdaCoefficient(); }
  int Index() { return Layer() - 1 + 30; }

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
  
 protected:
  double m_et;
  double m_clusterEta;
  double m_clusterX;
  double m_clusterY;
  double m_clusterZ;
  rechit_type m_type;

};

std::ostream& operator<< (std::ostream& stream, HGCHEFRecHit& object);

#endif
