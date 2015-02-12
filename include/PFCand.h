#ifndef PFCAND_H
#define PFCAND_H

#include "Object.h"
#include "IDTypes.h"
#include "RecHitTypes.h"
#include "Collection.h"

#include "HGCEECluster.h" 
#include "HGCHEBCluster.h" 
#include "HGCHEFCluster.h"

class PFCand : public Object { 

 public:

  PFCand();
  PFCand(Collection& c, unsigned int i, int j = 0);
  
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
  bool PassUserID_IsCharged       (bool verbose);
  bool PassUserID_IsNeutral       (bool verbose);
 
  int getNHGCEEClusters ();
  int getNHGCHEBClusters();
  int getNHGCHEFClusters();

  void getLeadClusterTypeAndIndex(rechit_type & type, int & raw_index);

  HGCEECluster  getHGCEECluster  (int i);
  HGCHEBCluster getHGCHEBCluster (int i);
  HGCHEFCluster getHGCHEFCluster (int i);
  
};

std::ostream& operator<< (std::ostream& stream, PFCand& object);

#endif
