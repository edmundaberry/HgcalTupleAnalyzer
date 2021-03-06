#ifndef GENPARTICLE_H
#define GENPARTICLE_H

#include "Object.h"
#include "IDTypes.h"
#include "Collection.h"

class GenParticle : public Object { 

 public:

  GenParticle();
  GenParticle(Collection& c, unsigned int i, int j = 0);
  
  // Kinematic variables

  double & Pt() ;
  double & Eta();
  double & Phi();

  // IDs 

  bool PassUserID ( ID id, bool verbose = false); 
  
  // ID variables  

  int PdgId            ();
  int Mother1Index     ();
  int Mother2Index     ();
  int Mother1PdgId     ();
  int Mother2PdgId     ();
  int Status           ();
  int NumMother        ();
  int HasPartonDaughter();
  
 private:

  bool PassUserID_IsFinalStateParton (bool verbose);
  bool PassUserID_IsHardScatter(bool verbose);
  bool PassUserID_IsLepton     (bool verbose);
  bool PassUserID_IsTau        (bool verbose);
  bool PassUserID_IsQuark      (bool verbose);
  bool PassUserID_IsBQuark     (bool verbose);
  bool PassUserID_IsCQuark     (bool verbose);
  bool PassUserID_IsGluon      (bool verbose);
  bool PassUserID_SharesHiggsMother  (bool verbose);
  bool PassUserID_IsFromQuark  (bool verbose);
  bool PassUserID_IsVBFQuark   (bool verbose);
  bool PassUserID_IsHardScatterVBFQuark ( bool verbose );
  bool PassUserID_IsHardScatterQuark    ( bool verbose );
  bool PassUserID_IsHardScatterGluon    ( bool verbose );
  bool PassUserID_IsHardScatterLepton   ( bool verbose );
  bool PassUserID_IsHardScatterTau      ( bool verbose );
};

std::ostream& operator<< (std::ostream& stream, GenParticle& object);

#endif
