#ifndef PFPRUNED_JET_H
#define PFPRUNED_JET_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"
#include "PFCand.h"

class PFPrunedJet : public Object { 

 public:

  // Constructors
  
  PFPrunedJet();
  PFPrunedJet(Collection& c, unsigned short i, short j );

  // Kinematic variables

  virtual double & Pt           () = 0;
  virtual double & Eta          () = 0;
  virtual double & Phi          () = 0;
  virtual double & Tau1         () = 0;
  virtual double & Tau2         () = 0;
  virtual double & Tau3         () = 0;
  virtual double & NSubJ        () = 0;
  virtual double & Mass         () = 0;
  virtual double & Energy       () = 0;

  // Subjet variables

  virtual double & MassDrop     () = 0;  
  virtual int    & NDaughters   () = 0;  
  virtual double & DaughterEta  (int i) = 0;
  virtual double & DaughterMass (int i) = 0;
  virtual double & DaughterPhi  (int i) = 0;
  virtual double & DaughterPt   (int i) = 0;
  virtual double   RCutParameter() = 0;

  // PF Candidate variables

  virtual int    getNPFCandidates() = 0;
  virtual PFCand getPFCandidate( int i ) = 0;

  // IDs 

  bool PassUserID ( ID id, bool verbose = false ) { return false; }

  // Q/G ID calculations
  
  double getWidth();
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
  
 private:
  
  void calculateDiscriminants();
  double m_sigma;
  double m_ptd;
  
};

#endif
