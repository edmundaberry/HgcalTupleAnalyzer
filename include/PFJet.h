#ifndef PFJET_H
#define PFJET_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

#include "PFCand.h"

class PFJet : public Object { 

 public:

  PFJet();
  PFJet(Collection& c, unsigned short i, short j = 0);
  
  // Kinematic variables

  double & Pt()   ;
  double & Eta()  ;
  double & Phi()  ;
  double & Tau1() ;
  double & Tau2() ;
  double & Tau3() ;
  double & NSubJ();
  
  int    getNPFCandidates();
  PFCand getPFCandidate( int i );

  // IDs 

  bool PassUserID ( ID id, bool verbose = false ); 
  
  
};

std::ostream& operator<< (std::ostream& stream, PFJet& object);

#endif
