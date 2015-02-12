#ifndef HGCEE_RECHIT_H
#define HGCEE_RECHIT_H

#include "Object.h"
#include "IDTypes.h"
#include "RecHitTypes.h"
#include "Collection.h"

#include <cmath>

class HGCEERecHit : public Object { 

 public:

  HGCEERecHit(rechit_type t);
  HGCEERecHit(rechit_type t, Collection& c, unsigned int i, int j = 0);
  
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
    if      ( Layer() == 1  ) return 0.01;
    else if ( Layer() == 2  ) return 0.05;
    else if ( Layer() == 3 ||
	      Layer() == 5 ||
	      Layer() == 7 ||
	      Layer() == 9 ||
	      Layer() == 11 ) return 0.04;
    else if ( Layer() == 4 ||
	      Layer() == 6 ||
	      Layer() == 8 ||
	      Layer() == 10 ) return 0.02;
    else if ( Layer() == 13 ||
	      Layer() == 15 ||
	      Layer() == 17 ||
	      Layer() == 19 ||
	      Layer() == 21 ) return 0.05;
    else if ( Layer() == 12 ||
	      Layer() == 14 ||
	      Layer() == 16 ||
	      Layer() == 18 ||
	      Layer() == 20 ) return 0.03;
    else if ( Layer() == 23 ||
	      Layer() == 25 ||
	      Layer() == 27 ||
	      Layer() == 29 ) return 0.06;
    else if ( Layer() == 22 ||
	      Layer() == 24 ||
	      Layer() == 26 ||
	      Layer() == 28 ||
	      Layer() == 30 ) return 0.05;
    return 0;
  }
  double Length() { return std::tanh(fabs(Eta())) * LambdaCoefficient(); }
  int Index() { return Layer() - 1; }

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

std::ostream& operator<< (std::ostream& stream, HGCEERecHit& object);

#endif
