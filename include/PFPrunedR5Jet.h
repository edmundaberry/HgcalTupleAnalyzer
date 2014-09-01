#ifndef PFPRUNED_R5_JET_H
#define PFPRUNED_R5_JET_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"
#include "PFCand.h"

class PFPrunedR5Jet : public Object { 

 public:

  PFPrunedR5Jet();
  PFPrunedR5Jet(Collection& c, unsigned short i, short j = 0);
  
  // Kinematic variables

  double & Pt           ();
  double & Eta          ();
  double & Phi          ();
  double & Tau1         ();
  double & Tau2         ();
  double & Tau3         ();
  double & NSubJ        ();

  // Subjet variables

  double & MassDrop     ();  
  int    & NDaughters   ();  
  double & DaughterEta  (int i);
  double & DaughterMass (int i);
  double & DaughterPhi  (int i);
  double & DaughterPt   (int i);
  double   RCutParameter() { return 0.5; }

  // PF Candidate variables

  int    getNPFCandidates();
  PFCand getPFCandidate( int i );

  // IDs 

  bool PassUserID ( ID id, bool verbose = false ) { return false; }
  
};

std::ostream& operator<< (std::ostream& stream, PFPrunedR5Jet& object);

#endif
