#include "PFCand.h"

bool PFCand::PassUserID (ID id, bool verbose){ 
  if      ( id == PFCAND_IS_CHARGED_HADRON ) return PassUserID_IsChargedHadron (verbose);
  else if ( id == PFCAND_IS_ELECTRON       ) return PassUserID_IsElectron      (verbose);
  else if ( id == PFCAND_IS_MUON           ) return PassUserID_IsMuon          (verbose);
  else if ( id == PFCAND_IS_PHOTON         ) return PassUserID_IsPhoton        (verbose);
  else if ( id == PFCAND_IS_NEUTRAL_HADRON ) return PassUserID_IsNeutralHadron (verbose);
  else if ( id == PFCAND_IS_HF_HADRON      ) return PassUserID_IsHFHadron      (verbose);
  else if ( id == PFCAND_IS_HF_EGAMMA      ) return PassUserID_IsHFEGamma      (verbose);
  else return false;
}

bool PFCand::PassUserID_IsChargedHadron (bool verbose){ return ( Id() == 1 ); }
bool PFCand::PassUserID_IsElectron      (bool verbose){ return ( Id() == 2 ); }
bool PFCand::PassUserID_IsMuon          (bool verbose){ return ( Id() == 3 ); }
bool PFCand::PassUserID_IsPhoton        (bool verbose){ return ( Id() == 4 ); }
bool PFCand::PassUserID_IsNeutralHadron (bool verbose){ return ( Id() == 5 ); }
bool PFCand::PassUserID_IsHFHadron      (bool verbose){ return ( Id() == 6 ); }
bool PFCand::PassUserID_IsHFEGamma      (bool verbose){ return ( Id() == 7 ); }
