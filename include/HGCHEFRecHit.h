#ifndef HGCHEF_RECHIT_H
#define HGCHEF_RECHIT_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

static const double HGCHEFMIPValueInGeV = 85.0*1e-6;

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

  void    SetClusterEta( double e ) { m_clusterEta = e; } 
  double  EffMIPToInvGeV() { 
    double _coef_a = 1.0;
    double _coef_b = 1e6;
    double _coef_c = 1e6;
    return _coef_a/(1.0 + std::exp(-_coef_c - _coef_b*std::cosh(m_clusterEta)));
  }
  double  weight (){ return 0.0902; }
  double  EnergyMIP() { return Energy()    / HGCHEFMIPValueInGeV; }
  double  EnergyCorr(){ return EnergyMIP() * weight() / EffMIPToInvGeV(); }
  
  
  // IDs 

  bool PassUserID ( ID id, bool verbose = false ); 
  
 private:
  double m_et;
  double m_clusterEta;

};

std::ostream& operator<< (std::ostream& stream, HGCHEFRecHit& object);

#endif
