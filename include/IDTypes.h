#ifndef ELECTRON_ID_TYPES_H
#define ELECTRON_ID_TYPES_H

enum ID { 
  EGAMMA_VETO               = 0, 
  EGAMMA_LOOSE              = 1, 
  EGAMMA_MEDIUM             = 2, 
  EGAMMA_TIGHT              = 3, 
  HEEP                      = 4,
  HEEP_LOOSE                = 5,
  MVA                       = 6,
  ECAL_FIDUCIAL             = 7,
  		            
  HIGH_PT_MUON_TRKRELISO01  = 8,
  MUON_TIGHT_PFISO04        = 9,
  MUON_FIDUCIAL             = 10,
  		            
  PFJET_LOOSE               = 11,
  PFJET_MEDIUM              = 12,
  PFJET_TIGHT               = 13,
  	
  GEN_PARTICLE_IS_HARD_SCATTER_VBF_QUARK = 14,
  GEN_PARTICLE_IS_HARD_SCATTER_QUARK     = 15,
  GEN_PARTICLE_IS_HARD_SCATTER_GLUON     = 16,
  
  PFCAND_IS_CHARGED_HADRON = 17,
  PFCAND_IS_ELECTRON       = 18,
  PFCAND_IS_MUON           = 19,
  PFCAND_IS_PHOTON         = 20,
  PFCAND_IS_NEUTRAL_HADRON = 21,
  PFCAND_IS_HF_HADRON      = 22,
  PFCAND_IS_HF_EGAMMA      = 23,


  NULL_ID                  = 999
};

#endif
