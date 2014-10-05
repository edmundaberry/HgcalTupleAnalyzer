#ifndef PFPRUNED_R008_JET_H
#define PFPRUNED_R008_JET_H

#include "PFPrunedJet.h"

class PFPrunedR008Jet : public PFPrunedJet { 

 public:
  
  PFPrunedR008Jet();
  PFPrunedR008Jet(Collection& c, unsigned short i, short j = 0);
  
  // Kinematic variables

  double & Pt           ();
  double & Eta          ();
  double & Phi          ();
  double & Tau1         ();
  double & Tau2         ();
  double & Tau3         ();
  double & NSubJ        ();
  double & Mass         ();

  // Subjet variables

  double & MassDrop     () ;  
  int    & NDaughters   () ;  
  double & DaughterEta  (int i) ;
  double & DaughterMass (int i) ;
  double & DaughterPhi  (int i) ;
  double & DaughterPt   (int i) ;
  
  // PF Candidate variables

  int    getNPFCandidates() ;
  PFCand getPFCandidate( int i ) ;

  // IDs 

  bool PassUserID ( ID id, bool verbose = false ) { return false; }
  
  double RCutParameter() { return 0.008; }

};

std::ostream& operator<< (std::ostream& stream, PFPrunedR008Jet& object);

#endif