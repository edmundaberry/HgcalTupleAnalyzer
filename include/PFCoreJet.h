#ifndef PF_CORE_JET_H
#define PF_CORE_JET_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"
#include "PFCand.h"

class PFCoreJet : public Object { 

 public:

  // Constructors
  
  PFCoreJet();
  PFCoreJet(Collection& c, unsigned short i, short j=0 );

  // Kinematic variables

  double & Pt           ();
  double & PtRaw        ();
  double & Area         ();
  double & Rho          ();
  double & Eta          ();
  double & Phi          ();
  double & RawMass      ();
  double & Energy       ();

  // PF Candidate variables

  virtual int    getNPFCandidates();
  virtual PFCand getPFCandidate( int i );

  // IDs 

  bool PassUserID ( ID id, bool verbose = false ) { return false; }

  // Q/G ID calculations
  
  double getWidth();
  double getChargedWidth();
  double getNeutralWidth();
  double getChargedFraction();
  double getNeutralFraction();
  double getPTD  ();
  double getWeightedDepth();
  double getWeightedDepthNoEE();
  double getHGCALEnergy();
  double getEEEnergy();
  double getHEBEnergy();
  double getHEFEnergy();
  double getEEEnergy(int min_layer, int max_layer);
  double getHEFEnergy(int min_layer, int max_layer);
  double getMaxRHDepth();
  void   getProfile      ( const int n_radii, double * radii, double * profile );
  double getProfileRadius( const int n_radii, double * radii, double * profile, double fraction );
  
 private:
  
  void calculateDiscriminants();
  double m_sigma;
  double m_sigma_charged;
  double m_sigma_neutral;
  double m_ptd;
  double m_pt;

};

#endif
