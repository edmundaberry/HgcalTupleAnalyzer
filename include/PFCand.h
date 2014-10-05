#ifndef PFCAND_H
#define PFCAND_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

class PFCand : public Object { 

 public:

  PFCand();
  PFCand(Collection& c, unsigned short i, short j = 0);
  
  // Kinematic variables

  int    & Id()  ;
  double & Pt()  ;
  double & Eta() ;
  double & Phi() ;

  // IDs 

  bool PassUserID ( ID id, bool verbose = false ); 
  
  bool PassUserID_IsChargedHadron (bool verbose);
  bool PassUserID_IsElectron      (bool verbose);
  bool PassUserID_IsMuon          (bool verbose);
  bool PassUserID_IsPhoton        (bool verbose);
  bool PassUserID_IsNeutralHadron (bool verbose);
  bool PassUserID_IsHFHadron      (bool verbose);
  bool PassUserID_IsHFEGamma      (bool verbose);
  
};

std::ostream& operator<< (std::ostream& stream, PFCand& object);

#endif