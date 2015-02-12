//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 27 14:36:47 2015 by ROOT version 5.34/25
// from TTree tree/
// found on file: data/QQH_SLHC23_v3/HgcalRelVal_QQH_MC_ANA.root
//////////////////////////////////////////////////////////

#ifndef HgcalTupleTree_h
#define HgcalTupleTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class HgcalTupleTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<string>  *PFAK1p5JetRCutFactorNames;
   vector<string>  *PFCA4JetRCutFactorNames;
   vector<bool>    *VertexIsFake;
   Double_t        rho;
   vector<double>  *CaloJetEnergy;
   vector<double>  *CaloJetEta;
   vector<double>  *CaloJetP;
   vector<double>  *CaloJetPhi;
   vector<double>  *CaloJetPt;
   vector<double>  *GenJetEMF;
   vector<double>  *GenJetEnergy;
   vector<double>  *GenJetEta;
   vector<double>  *GenJetHADF;
   vector<double>  *GenJetP;
   vector<double>  *GenJetPhi;
   vector<double>  *GenJetPt;
   vector<double>  *GenParticleEnergy;
   vector<double>  *GenParticleEta;
   vector<double>  *GenParticleP;
   vector<double>  *GenParticlePhi;
   vector<double>  *GenParticlePt;
   vector<double>  *GenParticlePx;
   vector<double>  *GenParticlePy;
   vector<double>  *GenParticlePz;
   vector<double>  *GenParticleVX;
   vector<double>  *GenParticleVY;
   vector<double>  *GenParticleVZ;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner1Eta;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner1Phi;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner2Eta;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner2Phi;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner3Eta;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner3Phi;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner4Eta;
   vector<double>  *HGCEERecHitFromHGCEEClusterCorner4Phi;
   vector<double>  *HGCEERecHitFromHGCEEClusterEnergy;
   vector<double>  *HGCEERecHitFromHGCEEClusterEta;
   vector<double>  *HGCEERecHitFromHGCEEClusterPhi;
   vector<double>  *HGCEERecHitFromHGCEEClusterR;
   vector<double>  *HGCEERecHitFromHGCEEClusterTime;
   vector<double>  *HGCEERecHitFromHGCEEClusterX;
   vector<double>  *HGCEERecHitFromHGCEEClusterY;
   vector<double>  *HGCEERecHitFromHGCEEClusterZ;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner1Eta;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner1Phi;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner2Eta;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner2Phi;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner3Eta;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner3Phi;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner4Eta;
   vector<double>  *HGCEERecHitFromHGCHEBClusterCorner4Phi;
   vector<double>  *HGCEERecHitFromHGCHEBClusterEnergy;
   vector<double>  *HGCEERecHitFromHGCHEBClusterEta;
   vector<double>  *HGCEERecHitFromHGCHEBClusterPhi;
   vector<double>  *HGCEERecHitFromHGCHEBClusterR;
   vector<double>  *HGCEERecHitFromHGCHEBClusterTime;
   vector<double>  *HGCEERecHitFromHGCHEBClusterX;
   vector<double>  *HGCEERecHitFromHGCHEBClusterY;
   vector<double>  *HGCEERecHitFromHGCHEBClusterZ;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner1Eta;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner1Phi;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner2Eta;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner2Phi;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner3Eta;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner3Phi;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner4Eta;
   vector<double>  *HGCEERecHitFromHGCHEFClusterCorner4Phi;
   vector<double>  *HGCEERecHitFromHGCHEFClusterEnergy;
   vector<double>  *HGCEERecHitFromHGCHEFClusterEta;
   vector<double>  *HGCEERecHitFromHGCHEFClusterPhi;
   vector<double>  *HGCEERecHitFromHGCHEFClusterR;
   vector<double>  *HGCEERecHitFromHGCHEFClusterTime;
   vector<double>  *HGCEERecHitFromHGCHEFClusterX;
   vector<double>  *HGCEERecHitFromHGCHEFClusterY;
   vector<double>  *HGCEERecHitFromHGCHEFClusterZ;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner1Eta;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner1Phi;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner2Eta;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner2Phi;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner3Eta;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner3Phi;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner4Eta;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterCorner4Phi;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterEnergy;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterEta;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterPhi;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterR;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterTime;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterX;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterY;
   vector<double>  *HGCHEBRecHitFromHGCEEClusterZ;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner1Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner1Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner2Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner2Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner3Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner3Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner4Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterCorner4Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterEnergy;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterEta;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterPhi;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterR;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterTime;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterX;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterY;
   vector<double>  *HGCHEBRecHitFromHGCHEBClusterZ;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner1Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner1Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner2Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner2Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner3Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner3Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner4Eta;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterCorner4Phi;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterEnergy;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterEta;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterPhi;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterR;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterTime;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterX;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterY;
   vector<double>  *HGCHEBRecHitFromHGCHEFClusterZ;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner1Eta;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner1Phi;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner2Eta;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner2Phi;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner3Eta;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner3Phi;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner4Eta;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterCorner4Phi;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterEnergy;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterEta;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterPhi;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterR;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterTime;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterX;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterY;
   vector<double>  *HGCHEFRecHitFromHGCEEClusterZ;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner1Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner1Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner2Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner2Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner3Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner3Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner4Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterCorner4Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterEnergy;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterEta;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterPhi;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterR;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterTime;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterX;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterY;
   vector<double>  *HGCHEFRecHitFromHGCHEBClusterZ;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner1Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner1Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner2Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner2Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner3Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner3Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner4Eta;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterCorner4Phi;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterEnergy;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterEta;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterPhi;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterR;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterTime;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterX;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterY;
   vector<double>  *HGCHEFRecHitFromHGCHEFClusterZ;
   vector<double>  *HGCEEPFClusterEnergy;
   vector<double>  *HGCEEPFClusterEta;
   vector<double>  *HGCEEPFClusterPhi;
   vector<double>  *HGCEEPFClusterPt;
   vector<double>  *HGCEEPFClusterR;
   vector<double>  *HGCEEPFClusterTime;
   vector<double>  *HGCEEPFClusterX;
   vector<double>  *HGCEEPFClusterY;
   vector<double>  *HGCEEPFClusterZ;
   vector<double>  *HGCHEBPFClusterEnergy;
   vector<double>  *HGCHEBPFClusterEta;
   vector<double>  *HGCHEBPFClusterPhi;
   vector<double>  *HGCHEBPFClusterPt;
   vector<double>  *HGCHEBPFClusterR;
   vector<double>  *HGCHEBPFClusterTime;
   vector<double>  *HGCHEBPFClusterX;
   vector<double>  *HGCHEBPFClusterY;
   vector<double>  *HGCHEBPFClusterZ;
   vector<double>  *HGCHEFPFClusterEnergy;
   vector<double>  *HGCHEFPFClusterEta;
   vector<double>  *HGCHEFPFClusterPhi;
   vector<double>  *HGCHEFPFClusterPt;
   vector<double>  *HGCHEFPFClusterR;
   vector<double>  *HGCHEFPFClusterTime;
   vector<double>  *HGCHEFPFClusterX;
   vector<double>  *HGCHEFPFClusterY;
   vector<double>  *HGCHEFPFClusterZ;
   vector<double>  *PFAK1p5JetArea;
   vector<double>  *PFAK1p5JetEnergy;
   vector<double>  *PFAK1p5JetEta;
   vector<double>  *PFAK1p5JetNSubJ;
   vector<double>  *PFAK1p5JetP;
   vector<double>  *PFAK1p5JetPhi;
   vector<double>  *PFAK1p5JetPt;
   vector<double>  *PFAK1p5JetRCutFactors;
   vector<double>  *PFAK1p5JetRawMass;
   vector<double>  *PFAK1p5JetTau1;
   vector<double>  *PFAK1p5JetTau2;
   vector<double>  *PFAK1p5JetTau3;
   vector<double>  *PFCA4JetArea;
   vector<double>  *PFCA4JetEnergy;
   vector<double>  *PFCA4JetEta;
   vector<double>  *PFCA4JetNSubJ;
   vector<double>  *PFCA4JetP;
   vector<double>  *PFCA4JetPhi;
   vector<double>  *PFCA4JetPt;
   vector<double>  *PFCA4JetRCutFactors;
   vector<double>  *PFCA4JetRawMass;
   vector<double>  *PFCA4JetTau1;
   vector<double>  *PFCA4JetTau2;
   vector<double>  *PFCA4JetTau3;
   vector<double>  *PFCandEta;
   vector<double>  *PFCandPhi;
   vector<double>  *PFCandPt;
   vector<double>  *PFTauEta;
   vector<double>  *PFTauP;
   vector<double>  *PFTauPhi;
   vector<double>  *PFTauPt;
   vector<double>  *VertexChi2;
   vector<double>  *VertexNDF;
   vector<double>  *VertexRho;
   vector<double>  *VertexX;
   vector<double>  *VertexXErr;
   vector<double>  *VertexY;
   vector<double>  *VertexYErr;
   vector<double>  *VertexZ;
   vector<double>  *VertexZErr;
   vector<vector<double> > *HGCEEPFClusterHGCEERecHitFraction;
   vector<vector<double> > *HGCEEPFClusterHGCHEBRecHitFraction;
   vector<vector<double> > *HGCEEPFClusterHGCHEFRecHitFraction;
   vector<vector<double> > *HGCHEBPFClusterHGCEERecHitFraction;
   vector<vector<double> > *HGCHEBPFClusterHGCHEBRecHitFraction;
   vector<vector<double> > *HGCHEBPFClusterHGCHEFRecHitFraction;
   vector<vector<double> > *HGCHEFPFClusterHGCEERecHitFraction;
   vector<vector<double> > *HGCHEFPFClusterHGCHEBRecHitFraction;
   vector<vector<double> > *HGCHEFPFClusterHGCHEFRecHitFraction;
   vector<vector<double> > *PFAK1p5JetTrimmedMass;
   vector<vector<double> > *PFAK1p5JetTrimmedMassDrop;
   vector<vector<double> > *PFCA4JetTrimmedMass;
   vector<vector<double> > *PFCA4JetTrimmedMassDrop;
   vector<int>     *GenParticleHasPartonDaughter;
   vector<int>     *GenParticleMother1Index;
   vector<int>     *GenParticleMother2Index;
   vector<int>     *GenParticleNumDaught;
   vector<int>     *GenParticleNumDaught3;
   vector<int>     *GenParticleNumMother;
   vector<int>     *GenParticlePdgId;
   vector<int>     *GenParticleStatus;
   vector<int>     *HGCEERecHitFromHGCEEClusterCell;
   vector<int>     *HGCEERecHitFromHGCEEClusterLayer;
   vector<int>     *HGCEERecHitFromHGCEEClusterSector;
   vector<int>     *HGCEERecHitFromHGCEEClusterSubSector;
   vector<int>     *HGCEERecHitFromHGCEEClusterSubdet;
   vector<int>     *HGCEERecHitFromHGCHEBClusterCell;
   vector<int>     *HGCEERecHitFromHGCHEBClusterLayer;
   vector<int>     *HGCEERecHitFromHGCHEBClusterSector;
   vector<int>     *HGCEERecHitFromHGCHEBClusterSubSector;
   vector<int>     *HGCEERecHitFromHGCHEBClusterSubdet;
   vector<int>     *HGCEERecHitFromHGCHEFClusterCell;
   vector<int>     *HGCEERecHitFromHGCHEFClusterLayer;
   vector<int>     *HGCEERecHitFromHGCHEFClusterSector;
   vector<int>     *HGCEERecHitFromHGCHEFClusterSubSector;
   vector<int>     *HGCEERecHitFromHGCHEFClusterSubdet;
   vector<int>     *HGCHEBRecHitFromHGCEEClusterCell;
   vector<int>     *HGCHEBRecHitFromHGCEEClusterLayer;
   vector<int>     *HGCHEBRecHitFromHGCEEClusterSector;
   vector<int>     *HGCHEBRecHitFromHGCEEClusterSubSector;
   vector<int>     *HGCHEBRecHitFromHGCEEClusterSubdet;
   vector<int>     *HGCHEBRecHitFromHGCHEBClusterCell;
   vector<int>     *HGCHEBRecHitFromHGCHEBClusterLayer;
   vector<int>     *HGCHEBRecHitFromHGCHEBClusterSector;
   vector<int>     *HGCHEBRecHitFromHGCHEBClusterSubSector;
   vector<int>     *HGCHEBRecHitFromHGCHEBClusterSubdet;
   vector<int>     *HGCHEBRecHitFromHGCHEFClusterCell;
   vector<int>     *HGCHEBRecHitFromHGCHEFClusterLayer;
   vector<int>     *HGCHEBRecHitFromHGCHEFClusterSector;
   vector<int>     *HGCHEBRecHitFromHGCHEFClusterSubSector;
   vector<int>     *HGCHEBRecHitFromHGCHEFClusterSubdet;
   vector<int>     *HGCHEFRecHitFromHGCEEClusterCell;
   vector<int>     *HGCHEFRecHitFromHGCEEClusterLayer;
   vector<int>     *HGCHEFRecHitFromHGCEEClusterSector;
   vector<int>     *HGCHEFRecHitFromHGCEEClusterSubSector;
   vector<int>     *HGCHEFRecHitFromHGCEEClusterSubdet;
   vector<int>     *HGCHEFRecHitFromHGCHEBClusterCell;
   vector<int>     *HGCHEFRecHitFromHGCHEBClusterLayer;
   vector<int>     *HGCHEFRecHitFromHGCHEBClusterSector;
   vector<int>     *HGCHEFRecHitFromHGCHEBClusterSubSector;
   vector<int>     *HGCHEFRecHitFromHGCHEBClusterSubdet;
   vector<int>     *HGCHEFRecHitFromHGCHEFClusterCell;
   vector<int>     *HGCHEFRecHitFromHGCHEFClusterLayer;
   vector<int>     *HGCHEFRecHitFromHGCHEFClusterSector;
   vector<int>     *HGCHEFRecHitFromHGCHEFClusterSubSector;
   vector<int>     *HGCHEFRecHitFromHGCHEFClusterSubdet;
   vector<int>     *HGCEEPFClusterLayer;
   vector<int>     *HGCHEBPFClusterLayer;
   vector<int>     *HGCHEFPFClusterLayer;
   vector<int>     *PFAK1p5JetRawNPFCands;
   vector<int>     *PFCA4JetRawNPFCands;
   vector<int>     *PFCandId;
   vector<int>     *PFTauPassAll;
   vector<int>     *PFTauPassDecayModeFinding;
   vector<int>     *PFTauPassLooseCombinedIsolation;
   vector<int>     *PFTauPassMuonRejection;
   vector<int>     *VertexNTracks;
   vector<int>     *VertexNTracksW05;
   vector<vector<int> > *HGCEEPFClusterHGCEERecHitIndex;
   vector<vector<int> > *HGCEEPFClusterHGCHEBRecHitIndex;
   vector<vector<int> > *HGCEEPFClusterHGCHEFRecHitIndex;
   vector<vector<int> > *HGCHEBPFClusterHGCEERecHitIndex;
   vector<vector<int> > *HGCHEBPFClusterHGCHEBRecHitIndex;
   vector<vector<int> > *HGCHEBPFClusterHGCHEFRecHitIndex;
   vector<vector<int> > *HGCHEFPFClusterHGCEERecHitIndex;
   vector<vector<int> > *HGCHEFPFClusterHGCHEBRecHitIndex;
   vector<vector<int> > *HGCHEFPFClusterHGCHEFRecHitIndex;
   vector<vector<int> > *PFAK1p5JetPFCandIndices;
   vector<vector<int> > *PFAK1p5JetTrimmedNPFCands;
   vector<vector<int> > *PFAK1p5JetTrimmedNSubjets;
   vector<vector<int> > *PFCA4JetPFCandIndices;
   vector<vector<int> > *PFCA4JetTrimmedNPFCands;
   vector<vector<int> > *PFCA4JetTrimmedNSubjets;
   vector<vector<int> > *PFCandHGCEEClusterIndex;
   vector<vector<int> > *PFCandHGCHEBClusterIndex;
   vector<vector<int> > *PFCandHGCHEFClusterIndex;
   UInt_t          event;
   UInt_t          ls;
   UInt_t          run;

   // List of branches
   TBranch        *b_PFAK1p5JetRCutFactorNames;   //!
   TBranch        *b_PFCA4JetRCutFactorNames;   //!
   TBranch        *b_VertexIsFake;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_CaloJetEnergy;   //!
   TBranch        *b_CaloJetEta;   //!
   TBranch        *b_CaloJetP;   //!
   TBranch        *b_CaloJetPhi;   //!
   TBranch        *b_CaloJetPt;   //!
   TBranch        *b_GenJetEMF;   //!
   TBranch        *b_GenJetEnergy;   //!
   TBranch        *b_GenJetEta;   //!
   TBranch        *b_GenJetHADF;   //!
   TBranch        *b_GenJetP;   //!
   TBranch        *b_GenJetPhi;   //!
   TBranch        *b_GenJetPt;   //!
   TBranch        *b_GenParticleEnergy;   //!
   TBranch        *b_GenParticleEta;   //!
   TBranch        *b_GenParticleP;   //!
   TBranch        *b_GenParticlePhi;   //!
   TBranch        *b_GenParticlePt;   //!
   TBranch        *b_GenParticlePx;   //!
   TBranch        *b_GenParticlePy;   //!
   TBranch        *b_GenParticlePz;   //!
   TBranch        *b_GenParticleVX;   //!
   TBranch        *b_GenParticleVY;   //!
   TBranch        *b_GenParticleVZ;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner1Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner1Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner2Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner2Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner3Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner3Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner4Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCorner4Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterEnergy;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterEta;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterPhi;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterR;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterTime;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterX;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterY;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterZ;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner1Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner1Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner2Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner2Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner3Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner3Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner4Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCorner4Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterEnergy;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterEta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterPhi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterR;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterTime;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterX;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterY;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterZ;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner1Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner1Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner2Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner2Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner3Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner3Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner4Eta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCorner4Phi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterEnergy;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterEta;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterPhi;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterR;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterTime;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterX;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterY;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterZ;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner1Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner1Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner2Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner2Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner3Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner3Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner4Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCorner4Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterEnergy;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterEta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterPhi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterR;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterTime;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterX;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterY;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterZ;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner1Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner1Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner2Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner2Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner3Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner3Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner4Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCorner4Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterEnergy;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterEta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterPhi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterR;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterTime;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterX;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterY;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterZ;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner1Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner1Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner2Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner2Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner3Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner3Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner4Eta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCorner4Phi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterEnergy;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterEta;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterPhi;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterR;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterTime;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterX;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterY;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterZ;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner1Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner1Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner2Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner2Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner3Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner3Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner4Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCorner4Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterEnergy;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterEta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterPhi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterR;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterTime;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterX;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterY;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterZ;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner1Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner1Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner2Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner2Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner3Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner3Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner4Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCorner4Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterEnergy;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterEta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterPhi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterR;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterTime;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterX;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterY;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterZ;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner1Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner1Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner2Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner2Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner3Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner3Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner4Eta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCorner4Phi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterEnergy;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterEta;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterPhi;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterR;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterTime;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterX;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterY;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterZ;   //!
   TBranch        *b_HGCEEPFClusterEnergy;   //!
   TBranch        *b_HGCEEPFClusterEta;   //!
   TBranch        *b_HGCEEPFClusterPhi;   //!
   TBranch        *b_HGCEEPFClusterPt;   //!
   TBranch        *b_HGCEEPFClusterR;   //!
   TBranch        *b_HGCEEPFClusterTime;   //!
   TBranch        *b_HGCEEPFClusterX;   //!
   TBranch        *b_HGCEEPFClusterY;   //!
   TBranch        *b_HGCEEPFClusterZ;   //!
   TBranch        *b_HGCHEBPFClusterEnergy;   //!
   TBranch        *b_HGCHEBPFClusterEta;   //!
   TBranch        *b_HGCHEBPFClusterPhi;   //!
   TBranch        *b_HGCHEBPFClusterPt;   //!
   TBranch        *b_HGCHEBPFClusterR;   //!
   TBranch        *b_HGCHEBPFClusterTime;   //!
   TBranch        *b_HGCHEBPFClusterX;   //!
   TBranch        *b_HGCHEBPFClusterY;   //!
   TBranch        *b_HGCHEBPFClusterZ;   //!
   TBranch        *b_HGCHEFPFClusterEnergy;   //!
   TBranch        *b_HGCHEFPFClusterEta;   //!
   TBranch        *b_HGCHEFPFClusterPhi;   //!
   TBranch        *b_HGCHEFPFClusterPt;   //!
   TBranch        *b_HGCHEFPFClusterR;   //!
   TBranch        *b_HGCHEFPFClusterTime;   //!
   TBranch        *b_HGCHEFPFClusterX;   //!
   TBranch        *b_HGCHEFPFClusterY;   //!
   TBranch        *b_HGCHEFPFClusterZ;   //!
   TBranch        *b_PFAK1p5JetArea;   //!
   TBranch        *b_PFAK1p5JetEnergy;   //!
   TBranch        *b_PFAK1p5JetEta;   //!
   TBranch        *b_PFAK1p5JetNSubJ;   //!
   TBranch        *b_PFAK1p5JetP;   //!
   TBranch        *b_PFAK1p5JetPhi;   //!
   TBranch        *b_PFAK1p5JetPt;   //!
   TBranch        *b_PFAK1p5JetRCutFactors;   //!
   TBranch        *b_PFAK1p5JetRawMass;   //!
   TBranch        *b_PFAK1p5JetTau1;   //!
   TBranch        *b_PFAK1p5JetTau2;   //!
   TBranch        *b_PFAK1p5JetTau3;   //!
   TBranch        *b_PFCA4JetArea;   //!
   TBranch        *b_PFCA4JetEnergy;   //!
   TBranch        *b_PFCA4JetEta;   //!
   TBranch        *b_PFCA4JetNSubJ;   //!
   TBranch        *b_PFCA4JetP;   //!
   TBranch        *b_PFCA4JetPhi;   //!
   TBranch        *b_PFCA4JetPt;   //!
   TBranch        *b_PFCA4JetRCutFactors;   //!
   TBranch        *b_PFCA4JetRawMass;   //!
   TBranch        *b_PFCA4JetTau1;   //!
   TBranch        *b_PFCA4JetTau2;   //!
   TBranch        *b_PFCA4JetTau3;   //!
   TBranch        *b_PFCandEta;   //!
   TBranch        *b_PFCandPhi;   //!
   TBranch        *b_PFCandPt;   //!
   TBranch        *b_PFTauEta;   //!
   TBranch        *b_PFTauP;   //!
   TBranch        *b_PFTauPhi;   //!
   TBranch        *b_PFTauPt;   //!
   TBranch        *b_VertexChi2;   //!
   TBranch        *b_VertexNDF;   //!
   TBranch        *b_VertexRho;   //!
   TBranch        *b_VertexX;   //!
   TBranch        *b_VertexXErr;   //!
   TBranch        *b_VertexY;   //!
   TBranch        *b_VertexYErr;   //!
   TBranch        *b_VertexZ;   //!
   TBranch        *b_VertexZErr;   //!
   TBranch        *b_HGCEEPFClusterHGCEERecHitFraction;   //!
   TBranch        *b_HGCEEPFClusterHGCHEBRecHitFraction;   //!
   TBranch        *b_HGCEEPFClusterHGCHEFRecHitFraction;   //!
   TBranch        *b_HGCHEBPFClusterHGCEERecHitFraction;   //!
   TBranch        *b_HGCHEBPFClusterHGCHEBRecHitFraction;   //!
   TBranch        *b_HGCHEBPFClusterHGCHEFRecHitFraction;   //!
   TBranch        *b_HGCHEFPFClusterHGCEERecHitFraction;   //!
   TBranch        *b_HGCHEFPFClusterHGCHEBRecHitFraction;   //!
   TBranch        *b_HGCHEFPFClusterHGCHEFRecHitFraction;   //!
   TBranch        *b_PFAK1p5JetTrimmedMass;   //!
   TBranch        *b_PFAK1p5JetTrimmedMassDrop;   //!
   TBranch        *b_PFCA4JetTrimmedMass;   //!
   TBranch        *b_PFCA4JetTrimmedMassDrop;   //!
   TBranch        *b_GenParticleHasPartonDaughter;   //!
   TBranch        *b_GenParticleMother1Index;   //!
   TBranch        *b_GenParticleMother2Index;   //!
   TBranch        *b_GenParticleNumDaught;   //!
   TBranch        *b_GenParticleNumDaught3;   //!
   TBranch        *b_GenParticleNumMother;   //!
   TBranch        *b_GenParticlePdgId;   //!
   TBranch        *b_GenParticleStatus;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterCell;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterLayer;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterSector;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterSubSector;   //!
   TBranch        *b_HGCEERecHitFromHGCEEClusterSubdet;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterCell;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterLayer;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterSector;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterSubSector;   //!
   TBranch        *b_HGCEERecHitFromHGCHEBClusterSubdet;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterCell;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterLayer;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterSector;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterSubSector;   //!
   TBranch        *b_HGCEERecHitFromHGCHEFClusterSubdet;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterCell;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterLayer;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterSector;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterSubSector;   //!
   TBranch        *b_HGCHEBRecHitFromHGCEEClusterSubdet;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterCell;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterLayer;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterSector;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterSubSector;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEBClusterSubdet;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterCell;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterLayer;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterSector;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterSubSector;   //!
   TBranch        *b_HGCHEBRecHitFromHGCHEFClusterSubdet;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterCell;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterLayer;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterSector;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterSubSector;   //!
   TBranch        *b_HGCHEFRecHitFromHGCEEClusterSubdet;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterCell;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterLayer;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterSector;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterSubSector;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEBClusterSubdet;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterCell;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterLayer;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterSector;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterSubSector;   //!
   TBranch        *b_HGCHEFRecHitFromHGCHEFClusterSubdet;   //!
   TBranch        *b_HGCEEPFClusterLayer;   //!
   TBranch        *b_HGCHEBPFClusterLayer;   //!
   TBranch        *b_HGCHEFPFClusterLayer;   //!
   TBranch        *b_PFAK1p5JetRawNPFCands;   //!
   TBranch        *b_PFCA4JetRawNPFCands;   //!
   TBranch        *b_PFCandId;   //!
   TBranch        *b_PFTauPassAll;   //!
   TBranch        *b_PFTauPassDecayModeFinding;   //!
   TBranch        *b_PFTauPassLooseCombinedIsolation;   //!
   TBranch        *b_PFTauPassMuonRejection;   //!
   TBranch        *b_VertexNTracks;   //!
   TBranch        *b_VertexNTracksW05;   //!
   TBranch        *b_HGCEEPFClusterHGCEERecHitIndex;   //!
   TBranch        *b_HGCEEPFClusterHGCHEBRecHitIndex;   //!
   TBranch        *b_HGCEEPFClusterHGCHEFRecHitIndex;   //!
   TBranch        *b_HGCHEBPFClusterHGCEERecHitIndex;   //!
   TBranch        *b_HGCHEBPFClusterHGCHEBRecHitIndex;   //!
   TBranch        *b_HGCHEBPFClusterHGCHEFRecHitIndex;   //!
   TBranch        *b_HGCHEFPFClusterHGCEERecHitIndex;   //!
   TBranch        *b_HGCHEFPFClusterHGCHEBRecHitIndex;   //!
   TBranch        *b_HGCHEFPFClusterHGCHEFRecHitIndex;   //!
   TBranch        *b_PFAK1p5JetPFCandIndices;   //!
   TBranch        *b_PFAK1p5JetTrimmedNPFCands;   //!
   TBranch        *b_PFAK1p5JetTrimmedNSubjets;   //!
   TBranch        *b_PFCA4JetPFCandIndices;   //!
   TBranch        *b_PFCA4JetTrimmedNPFCands;   //!
   TBranch        *b_PFCA4JetTrimmedNSubjets;   //!
   TBranch        *b_PFCandHGCEEClusterIndex;   //!
   TBranch        *b_PFCandHGCHEBClusterIndex;   //!
   TBranch        *b_PFCandHGCHEFClusterIndex;   //!
   TBranch        *b_event;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_run;   //!

   HgcalTupleTree(TTree *tree=0);
   virtual ~HgcalTupleTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HgcalTupleTree_cxx
HgcalTupleTree::HgcalTupleTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/QQH_SLHC23_v3/HgcalRelVal_QQH_MC_ANA.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("data/QQH_SLHC23_v3/HgcalRelVal_QQH_MC_ANA.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("data/QQH_SLHC23_v3/HgcalRelVal_QQH_MC_ANA.root:/hgcalTupleTree");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

HgcalTupleTree::~HgcalTupleTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HgcalTupleTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HgcalTupleTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HgcalTupleTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   PFAK1p5JetRCutFactorNames = 0;
   PFCA4JetRCutFactorNames = 0;
   VertexIsFake = 0;
   CaloJetEnergy = 0;
   CaloJetEta = 0;
   CaloJetP = 0;
   CaloJetPhi = 0;
   CaloJetPt = 0;
   GenJetEMF = 0;
   GenJetEnergy = 0;
   GenJetEta = 0;
   GenJetHADF = 0;
   GenJetP = 0;
   GenJetPhi = 0;
   GenJetPt = 0;
   GenParticleEnergy = 0;
   GenParticleEta = 0;
   GenParticleP = 0;
   GenParticlePhi = 0;
   GenParticlePt = 0;
   GenParticlePx = 0;
   GenParticlePy = 0;
   GenParticlePz = 0;
   GenParticleVX = 0;
   GenParticleVY = 0;
   GenParticleVZ = 0;
   HGCEERecHitFromHGCEEClusterCorner1Eta = 0;
   HGCEERecHitFromHGCEEClusterCorner1Phi = 0;
   HGCEERecHitFromHGCEEClusterCorner2Eta = 0;
   HGCEERecHitFromHGCEEClusterCorner2Phi = 0;
   HGCEERecHitFromHGCEEClusterCorner3Eta = 0;
   HGCEERecHitFromHGCEEClusterCorner3Phi = 0;
   HGCEERecHitFromHGCEEClusterCorner4Eta = 0;
   HGCEERecHitFromHGCEEClusterCorner4Phi = 0;
   HGCEERecHitFromHGCEEClusterEnergy = 0;
   HGCEERecHitFromHGCEEClusterEta = 0;
   HGCEERecHitFromHGCEEClusterPhi = 0;
   HGCEERecHitFromHGCEEClusterR = 0;
   HGCEERecHitFromHGCEEClusterTime = 0;
   HGCEERecHitFromHGCEEClusterX = 0;
   HGCEERecHitFromHGCEEClusterY = 0;
   HGCEERecHitFromHGCEEClusterZ = 0;
   HGCEERecHitFromHGCHEBClusterCorner1Eta = 0;
   HGCEERecHitFromHGCHEBClusterCorner1Phi = 0;
   HGCEERecHitFromHGCHEBClusterCorner2Eta = 0;
   HGCEERecHitFromHGCHEBClusterCorner2Phi = 0;
   HGCEERecHitFromHGCHEBClusterCorner3Eta = 0;
   HGCEERecHitFromHGCHEBClusterCorner3Phi = 0;
   HGCEERecHitFromHGCHEBClusterCorner4Eta = 0;
   HGCEERecHitFromHGCHEBClusterCorner4Phi = 0;
   HGCEERecHitFromHGCHEBClusterEnergy = 0;
   HGCEERecHitFromHGCHEBClusterEta = 0;
   HGCEERecHitFromHGCHEBClusterPhi = 0;
   HGCEERecHitFromHGCHEBClusterR = 0;
   HGCEERecHitFromHGCHEBClusterTime = 0;
   HGCEERecHitFromHGCHEBClusterX = 0;
   HGCEERecHitFromHGCHEBClusterY = 0;
   HGCEERecHitFromHGCHEBClusterZ = 0;
   HGCEERecHitFromHGCHEFClusterCorner1Eta = 0;
   HGCEERecHitFromHGCHEFClusterCorner1Phi = 0;
   HGCEERecHitFromHGCHEFClusterCorner2Eta = 0;
   HGCEERecHitFromHGCHEFClusterCorner2Phi = 0;
   HGCEERecHitFromHGCHEFClusterCorner3Eta = 0;
   HGCEERecHitFromHGCHEFClusterCorner3Phi = 0;
   HGCEERecHitFromHGCHEFClusterCorner4Eta = 0;
   HGCEERecHitFromHGCHEFClusterCorner4Phi = 0;
   HGCEERecHitFromHGCHEFClusterEnergy = 0;
   HGCEERecHitFromHGCHEFClusterEta = 0;
   HGCEERecHitFromHGCHEFClusterPhi = 0;
   HGCEERecHitFromHGCHEFClusterR = 0;
   HGCEERecHitFromHGCHEFClusterTime = 0;
   HGCEERecHitFromHGCHEFClusterX = 0;
   HGCEERecHitFromHGCHEFClusterY = 0;
   HGCEERecHitFromHGCHEFClusterZ = 0;
   HGCHEBRecHitFromHGCEEClusterCorner1Eta = 0;
   HGCHEBRecHitFromHGCEEClusterCorner1Phi = 0;
   HGCHEBRecHitFromHGCEEClusterCorner2Eta = 0;
   HGCHEBRecHitFromHGCEEClusterCorner2Phi = 0;
   HGCHEBRecHitFromHGCEEClusterCorner3Eta = 0;
   HGCHEBRecHitFromHGCEEClusterCorner3Phi = 0;
   HGCHEBRecHitFromHGCEEClusterCorner4Eta = 0;
   HGCHEBRecHitFromHGCEEClusterCorner4Phi = 0;
   HGCHEBRecHitFromHGCEEClusterEnergy = 0;
   HGCHEBRecHitFromHGCEEClusterEta = 0;
   HGCHEBRecHitFromHGCEEClusterPhi = 0;
   HGCHEBRecHitFromHGCEEClusterR = 0;
   HGCHEBRecHitFromHGCEEClusterTime = 0;
   HGCHEBRecHitFromHGCEEClusterX = 0;
   HGCHEBRecHitFromHGCEEClusterY = 0;
   HGCHEBRecHitFromHGCEEClusterZ = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner1Eta = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner1Phi = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner2Eta = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner2Phi = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner3Eta = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner3Phi = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner4Eta = 0;
   HGCHEBRecHitFromHGCHEBClusterCorner4Phi = 0;
   HGCHEBRecHitFromHGCHEBClusterEnergy = 0;
   HGCHEBRecHitFromHGCHEBClusterEta = 0;
   HGCHEBRecHitFromHGCHEBClusterPhi = 0;
   HGCHEBRecHitFromHGCHEBClusterR = 0;
   HGCHEBRecHitFromHGCHEBClusterTime = 0;
   HGCHEBRecHitFromHGCHEBClusterX = 0;
   HGCHEBRecHitFromHGCHEBClusterY = 0;
   HGCHEBRecHitFromHGCHEBClusterZ = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner1Eta = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner1Phi = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner2Eta = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner2Phi = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner3Eta = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner3Phi = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner4Eta = 0;
   HGCHEBRecHitFromHGCHEFClusterCorner4Phi = 0;
   HGCHEBRecHitFromHGCHEFClusterEnergy = 0;
   HGCHEBRecHitFromHGCHEFClusterEta = 0;
   HGCHEBRecHitFromHGCHEFClusterPhi = 0;
   HGCHEBRecHitFromHGCHEFClusterR = 0;
   HGCHEBRecHitFromHGCHEFClusterTime = 0;
   HGCHEBRecHitFromHGCHEFClusterX = 0;
   HGCHEBRecHitFromHGCHEFClusterY = 0;
   HGCHEBRecHitFromHGCHEFClusterZ = 0;
   HGCHEFRecHitFromHGCEEClusterCorner1Eta = 0;
   HGCHEFRecHitFromHGCEEClusterCorner1Phi = 0;
   HGCHEFRecHitFromHGCEEClusterCorner2Eta = 0;
   HGCHEFRecHitFromHGCEEClusterCorner2Phi = 0;
   HGCHEFRecHitFromHGCEEClusterCorner3Eta = 0;
   HGCHEFRecHitFromHGCEEClusterCorner3Phi = 0;
   HGCHEFRecHitFromHGCEEClusterCorner4Eta = 0;
   HGCHEFRecHitFromHGCEEClusterCorner4Phi = 0;
   HGCHEFRecHitFromHGCEEClusterEnergy = 0;
   HGCHEFRecHitFromHGCEEClusterEta = 0;
   HGCHEFRecHitFromHGCEEClusterPhi = 0;
   HGCHEFRecHitFromHGCEEClusterR = 0;
   HGCHEFRecHitFromHGCEEClusterTime = 0;
   HGCHEFRecHitFromHGCEEClusterX = 0;
   HGCHEFRecHitFromHGCEEClusterY = 0;
   HGCHEFRecHitFromHGCEEClusterZ = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner1Eta = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner1Phi = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner2Eta = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner2Phi = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner3Eta = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner3Phi = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner4Eta = 0;
   HGCHEFRecHitFromHGCHEBClusterCorner4Phi = 0;
   HGCHEFRecHitFromHGCHEBClusterEnergy = 0;
   HGCHEFRecHitFromHGCHEBClusterEta = 0;
   HGCHEFRecHitFromHGCHEBClusterPhi = 0;
   HGCHEFRecHitFromHGCHEBClusterR = 0;
   HGCHEFRecHitFromHGCHEBClusterTime = 0;
   HGCHEFRecHitFromHGCHEBClusterX = 0;
   HGCHEFRecHitFromHGCHEBClusterY = 0;
   HGCHEFRecHitFromHGCHEBClusterZ = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner1Eta = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner1Phi = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner2Eta = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner2Phi = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner3Eta = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner3Phi = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner4Eta = 0;
   HGCHEFRecHitFromHGCHEFClusterCorner4Phi = 0;
   HGCHEFRecHitFromHGCHEFClusterEnergy = 0;
   HGCHEFRecHitFromHGCHEFClusterEta = 0;
   HGCHEFRecHitFromHGCHEFClusterPhi = 0;
   HGCHEFRecHitFromHGCHEFClusterR = 0;
   HGCHEFRecHitFromHGCHEFClusterTime = 0;
   HGCHEFRecHitFromHGCHEFClusterX = 0;
   HGCHEFRecHitFromHGCHEFClusterY = 0;
   HGCHEFRecHitFromHGCHEFClusterZ = 0;
   HGCEEPFClusterEnergy = 0;
   HGCEEPFClusterEta = 0;
   HGCEEPFClusterPhi = 0;
   HGCEEPFClusterPt = 0;
   HGCEEPFClusterR = 0;
   HGCEEPFClusterTime = 0;
   HGCEEPFClusterX = 0;
   HGCEEPFClusterY = 0;
   HGCEEPFClusterZ = 0;
   HGCHEBPFClusterEnergy = 0;
   HGCHEBPFClusterEta = 0;
   HGCHEBPFClusterPhi = 0;
   HGCHEBPFClusterPt = 0;
   HGCHEBPFClusterR = 0;
   HGCHEBPFClusterTime = 0;
   HGCHEBPFClusterX = 0;
   HGCHEBPFClusterY = 0;
   HGCHEBPFClusterZ = 0;
   HGCHEFPFClusterEnergy = 0;
   HGCHEFPFClusterEta = 0;
   HGCHEFPFClusterPhi = 0;
   HGCHEFPFClusterPt = 0;
   HGCHEFPFClusterR = 0;
   HGCHEFPFClusterTime = 0;
   HGCHEFPFClusterX = 0;
   HGCHEFPFClusterY = 0;
   HGCHEFPFClusterZ = 0;
   PFAK1p5JetArea = 0;
   PFAK1p5JetEnergy = 0;
   PFAK1p5JetEta = 0;
   PFAK1p5JetNSubJ = 0;
   PFAK1p5JetP = 0;
   PFAK1p5JetPhi = 0;
   PFAK1p5JetPt = 0;
   PFAK1p5JetRCutFactors = 0;
   PFAK1p5JetRawMass = 0;
   PFAK1p5JetTau1 = 0;
   PFAK1p5JetTau2 = 0;
   PFAK1p5JetTau3 = 0;
   PFCA4JetArea = 0;
   PFCA4JetEnergy = 0;
   PFCA4JetEta = 0;
   PFCA4JetNSubJ = 0;
   PFCA4JetP = 0;
   PFCA4JetPhi = 0;
   PFCA4JetPt = 0;
   PFCA4JetRCutFactors = 0;
   PFCA4JetRawMass = 0;
   PFCA4JetTau1 = 0;
   PFCA4JetTau2 = 0;
   PFCA4JetTau3 = 0;
   PFCandEta = 0;
   PFCandPhi = 0;
   PFCandPt = 0;
   PFTauEta = 0;
   PFTauP = 0;
   PFTauPhi = 0;
   PFTauPt = 0;
   VertexChi2 = 0;
   VertexNDF = 0;
   VertexRho = 0;
   VertexX = 0;
   VertexXErr = 0;
   VertexY = 0;
   VertexYErr = 0;
   VertexZ = 0;
   VertexZErr = 0;
   HGCEEPFClusterHGCEERecHitFraction = 0;
   HGCEEPFClusterHGCHEBRecHitFraction = 0;
   HGCEEPFClusterHGCHEFRecHitFraction = 0;
   HGCHEBPFClusterHGCEERecHitFraction = 0;
   HGCHEBPFClusterHGCHEBRecHitFraction = 0;
   HGCHEBPFClusterHGCHEFRecHitFraction = 0;
   HGCHEFPFClusterHGCEERecHitFraction = 0;
   HGCHEFPFClusterHGCHEBRecHitFraction = 0;
   HGCHEFPFClusterHGCHEFRecHitFraction = 0;
   PFAK1p5JetTrimmedMass = 0;
   PFAK1p5JetTrimmedMassDrop = 0;
   PFCA4JetTrimmedMass = 0;
   PFCA4JetTrimmedMassDrop = 0;
   GenParticleHasPartonDaughter = 0;
   GenParticleMother1Index = 0;
   GenParticleMother2Index = 0;
   GenParticleNumDaught = 0;
   GenParticleNumDaught3 = 0;
   GenParticleNumMother = 0;
   GenParticlePdgId = 0;
   GenParticleStatus = 0;
   HGCEERecHitFromHGCEEClusterCell = 0;
   HGCEERecHitFromHGCEEClusterLayer = 0;
   HGCEERecHitFromHGCEEClusterSector = 0;
   HGCEERecHitFromHGCEEClusterSubSector = 0;
   HGCEERecHitFromHGCEEClusterSubdet = 0;
   HGCEERecHitFromHGCHEBClusterCell = 0;
   HGCEERecHitFromHGCHEBClusterLayer = 0;
   HGCEERecHitFromHGCHEBClusterSector = 0;
   HGCEERecHitFromHGCHEBClusterSubSector = 0;
   HGCEERecHitFromHGCHEBClusterSubdet = 0;
   HGCEERecHitFromHGCHEFClusterCell = 0;
   HGCEERecHitFromHGCHEFClusterLayer = 0;
   HGCEERecHitFromHGCHEFClusterSector = 0;
   HGCEERecHitFromHGCHEFClusterSubSector = 0;
   HGCEERecHitFromHGCHEFClusterSubdet = 0;
   HGCHEBRecHitFromHGCEEClusterCell = 0;
   HGCHEBRecHitFromHGCEEClusterLayer = 0;
   HGCHEBRecHitFromHGCEEClusterSector = 0;
   HGCHEBRecHitFromHGCEEClusterSubSector = 0;
   HGCHEBRecHitFromHGCEEClusterSubdet = 0;
   HGCHEBRecHitFromHGCHEBClusterCell = 0;
   HGCHEBRecHitFromHGCHEBClusterLayer = 0;
   HGCHEBRecHitFromHGCHEBClusterSector = 0;
   HGCHEBRecHitFromHGCHEBClusterSubSector = 0;
   HGCHEBRecHitFromHGCHEBClusterSubdet = 0;
   HGCHEBRecHitFromHGCHEFClusterCell = 0;
   HGCHEBRecHitFromHGCHEFClusterLayer = 0;
   HGCHEBRecHitFromHGCHEFClusterSector = 0;
   HGCHEBRecHitFromHGCHEFClusterSubSector = 0;
   HGCHEBRecHitFromHGCHEFClusterSubdet = 0;
   HGCHEFRecHitFromHGCEEClusterCell = 0;
   HGCHEFRecHitFromHGCEEClusterLayer = 0;
   HGCHEFRecHitFromHGCEEClusterSector = 0;
   HGCHEFRecHitFromHGCEEClusterSubSector = 0;
   HGCHEFRecHitFromHGCEEClusterSubdet = 0;
   HGCHEFRecHitFromHGCHEBClusterCell = 0;
   HGCHEFRecHitFromHGCHEBClusterLayer = 0;
   HGCHEFRecHitFromHGCHEBClusterSector = 0;
   HGCHEFRecHitFromHGCHEBClusterSubSector = 0;
   HGCHEFRecHitFromHGCHEBClusterSubdet = 0;
   HGCHEFRecHitFromHGCHEFClusterCell = 0;
   HGCHEFRecHitFromHGCHEFClusterLayer = 0;
   HGCHEFRecHitFromHGCHEFClusterSector = 0;
   HGCHEFRecHitFromHGCHEFClusterSubSector = 0;
   HGCHEFRecHitFromHGCHEFClusterSubdet = 0;
   HGCEEPFClusterLayer = 0;
   HGCHEBPFClusterLayer = 0;
   HGCHEFPFClusterLayer = 0;
   PFAK1p5JetRawNPFCands = 0;
   PFCA4JetRawNPFCands = 0;
   PFCandId = 0;
   PFTauPassAll = 0;
   PFTauPassDecayModeFinding = 0;
   PFTauPassLooseCombinedIsolation = 0;
   PFTauPassMuonRejection = 0;
   VertexNTracks = 0;
   VertexNTracksW05 = 0;
   HGCEEPFClusterHGCEERecHitIndex = 0;
   HGCEEPFClusterHGCHEBRecHitIndex = 0;
   HGCEEPFClusterHGCHEFRecHitIndex = 0;
   HGCHEBPFClusterHGCEERecHitIndex = 0;
   HGCHEBPFClusterHGCHEBRecHitIndex = 0;
   HGCHEBPFClusterHGCHEFRecHitIndex = 0;
   HGCHEFPFClusterHGCEERecHitIndex = 0;
   HGCHEFPFClusterHGCHEBRecHitIndex = 0;
   HGCHEFPFClusterHGCHEFRecHitIndex = 0;
   PFAK1p5JetPFCandIndices = 0;
   PFAK1p5JetTrimmedNPFCands = 0;
   PFAK1p5JetTrimmedNSubjets = 0;
   PFCA4JetPFCandIndices = 0;
   PFCA4JetTrimmedNPFCands = 0;
   PFCA4JetTrimmedNSubjets = 0;
   PFCandHGCEEClusterIndex = 0;
   PFCandHGCHEBClusterIndex = 0;
   PFCandHGCHEFClusterIndex = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("PFAK1p5JetRCutFactorNames", &PFAK1p5JetRCutFactorNames, &b_PFAK1p5JetRCutFactorNames);
   fChain->SetBranchAddress("PFCA4JetRCutFactorNames", &PFCA4JetRCutFactorNames, &b_PFCA4JetRCutFactorNames);
   fChain->SetBranchAddress("VertexIsFake", &VertexIsFake, &b_VertexIsFake);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("CaloJetEnergy", &CaloJetEnergy, &b_CaloJetEnergy);
   fChain->SetBranchAddress("CaloJetEta", &CaloJetEta, &b_CaloJetEta);
   fChain->SetBranchAddress("CaloJetP", &CaloJetP, &b_CaloJetP);
   fChain->SetBranchAddress("CaloJetPhi", &CaloJetPhi, &b_CaloJetPhi);
   fChain->SetBranchAddress("CaloJetPt", &CaloJetPt, &b_CaloJetPt);
   fChain->SetBranchAddress("GenJetEMF", &GenJetEMF, &b_GenJetEMF);
   fChain->SetBranchAddress("GenJetEnergy", &GenJetEnergy, &b_GenJetEnergy);
   fChain->SetBranchAddress("GenJetEta", &GenJetEta, &b_GenJetEta);
   fChain->SetBranchAddress("GenJetHADF", &GenJetHADF, &b_GenJetHADF);
   fChain->SetBranchAddress("GenJetP", &GenJetP, &b_GenJetP);
   fChain->SetBranchAddress("GenJetPhi", &GenJetPhi, &b_GenJetPhi);
   fChain->SetBranchAddress("GenJetPt", &GenJetPt, &b_GenJetPt);
   fChain->SetBranchAddress("GenParticleEnergy", &GenParticleEnergy, &b_GenParticleEnergy);
   fChain->SetBranchAddress("GenParticleEta", &GenParticleEta, &b_GenParticleEta);
   fChain->SetBranchAddress("GenParticleP", &GenParticleP, &b_GenParticleP);
   fChain->SetBranchAddress("GenParticlePhi", &GenParticlePhi, &b_GenParticlePhi);
   fChain->SetBranchAddress("GenParticlePt", &GenParticlePt, &b_GenParticlePt);
   fChain->SetBranchAddress("GenParticlePx", &GenParticlePx, &b_GenParticlePx);
   fChain->SetBranchAddress("GenParticlePy", &GenParticlePy, &b_GenParticlePy);
   fChain->SetBranchAddress("GenParticlePz", &GenParticlePz, &b_GenParticlePz);
   fChain->SetBranchAddress("GenParticleVX", &GenParticleVX, &b_GenParticleVX);
   fChain->SetBranchAddress("GenParticleVY", &GenParticleVY, &b_GenParticleVY);
   fChain->SetBranchAddress("GenParticleVZ", &GenParticleVZ, &b_GenParticleVZ);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner1Eta", &HGCEERecHitFromHGCEEClusterCorner1Eta, &b_HGCEERecHitFromHGCEEClusterCorner1Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner1Phi", &HGCEERecHitFromHGCEEClusterCorner1Phi, &b_HGCEERecHitFromHGCEEClusterCorner1Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner2Eta", &HGCEERecHitFromHGCEEClusterCorner2Eta, &b_HGCEERecHitFromHGCEEClusterCorner2Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner2Phi", &HGCEERecHitFromHGCEEClusterCorner2Phi, &b_HGCEERecHitFromHGCEEClusterCorner2Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner3Eta", &HGCEERecHitFromHGCEEClusterCorner3Eta, &b_HGCEERecHitFromHGCEEClusterCorner3Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner3Phi", &HGCEERecHitFromHGCEEClusterCorner3Phi, &b_HGCEERecHitFromHGCEEClusterCorner3Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner4Eta", &HGCEERecHitFromHGCEEClusterCorner4Eta, &b_HGCEERecHitFromHGCEEClusterCorner4Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCorner4Phi", &HGCEERecHitFromHGCEEClusterCorner4Phi, &b_HGCEERecHitFromHGCEEClusterCorner4Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterEnergy", &HGCEERecHitFromHGCEEClusterEnergy, &b_HGCEERecHitFromHGCEEClusterEnergy);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterEta", &HGCEERecHitFromHGCEEClusterEta, &b_HGCEERecHitFromHGCEEClusterEta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterPhi", &HGCEERecHitFromHGCEEClusterPhi, &b_HGCEERecHitFromHGCEEClusterPhi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterR", &HGCEERecHitFromHGCEEClusterR, &b_HGCEERecHitFromHGCEEClusterR);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterTime", &HGCEERecHitFromHGCEEClusterTime, &b_HGCEERecHitFromHGCEEClusterTime);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterX", &HGCEERecHitFromHGCEEClusterX, &b_HGCEERecHitFromHGCEEClusterX);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterY", &HGCEERecHitFromHGCEEClusterY, &b_HGCEERecHitFromHGCEEClusterY);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterZ", &HGCEERecHitFromHGCEEClusterZ, &b_HGCEERecHitFromHGCEEClusterZ);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner1Eta", &HGCEERecHitFromHGCHEBClusterCorner1Eta, &b_HGCEERecHitFromHGCHEBClusterCorner1Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner1Phi", &HGCEERecHitFromHGCHEBClusterCorner1Phi, &b_HGCEERecHitFromHGCHEBClusterCorner1Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner2Eta", &HGCEERecHitFromHGCHEBClusterCorner2Eta, &b_HGCEERecHitFromHGCHEBClusterCorner2Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner2Phi", &HGCEERecHitFromHGCHEBClusterCorner2Phi, &b_HGCEERecHitFromHGCHEBClusterCorner2Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner3Eta", &HGCEERecHitFromHGCHEBClusterCorner3Eta, &b_HGCEERecHitFromHGCHEBClusterCorner3Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner3Phi", &HGCEERecHitFromHGCHEBClusterCorner3Phi, &b_HGCEERecHitFromHGCHEBClusterCorner3Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner4Eta", &HGCEERecHitFromHGCHEBClusterCorner4Eta, &b_HGCEERecHitFromHGCHEBClusterCorner4Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCorner4Phi", &HGCEERecHitFromHGCHEBClusterCorner4Phi, &b_HGCEERecHitFromHGCHEBClusterCorner4Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterEnergy", &HGCEERecHitFromHGCHEBClusterEnergy, &b_HGCEERecHitFromHGCHEBClusterEnergy);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterEta", &HGCEERecHitFromHGCHEBClusterEta, &b_HGCEERecHitFromHGCHEBClusterEta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterPhi", &HGCEERecHitFromHGCHEBClusterPhi, &b_HGCEERecHitFromHGCHEBClusterPhi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterR", &HGCEERecHitFromHGCHEBClusterR, &b_HGCEERecHitFromHGCHEBClusterR);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterTime", &HGCEERecHitFromHGCHEBClusterTime, &b_HGCEERecHitFromHGCHEBClusterTime);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterX", &HGCEERecHitFromHGCHEBClusterX, &b_HGCEERecHitFromHGCHEBClusterX);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterY", &HGCEERecHitFromHGCHEBClusterY, &b_HGCEERecHitFromHGCHEBClusterY);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterZ", &HGCEERecHitFromHGCHEBClusterZ, &b_HGCEERecHitFromHGCHEBClusterZ);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner1Eta", &HGCEERecHitFromHGCHEFClusterCorner1Eta, &b_HGCEERecHitFromHGCHEFClusterCorner1Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner1Phi", &HGCEERecHitFromHGCHEFClusterCorner1Phi, &b_HGCEERecHitFromHGCHEFClusterCorner1Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner2Eta", &HGCEERecHitFromHGCHEFClusterCorner2Eta, &b_HGCEERecHitFromHGCHEFClusterCorner2Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner2Phi", &HGCEERecHitFromHGCHEFClusterCorner2Phi, &b_HGCEERecHitFromHGCHEFClusterCorner2Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner3Eta", &HGCEERecHitFromHGCHEFClusterCorner3Eta, &b_HGCEERecHitFromHGCHEFClusterCorner3Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner3Phi", &HGCEERecHitFromHGCHEFClusterCorner3Phi, &b_HGCEERecHitFromHGCHEFClusterCorner3Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner4Eta", &HGCEERecHitFromHGCHEFClusterCorner4Eta, &b_HGCEERecHitFromHGCHEFClusterCorner4Eta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCorner4Phi", &HGCEERecHitFromHGCHEFClusterCorner4Phi, &b_HGCEERecHitFromHGCHEFClusterCorner4Phi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterEnergy", &HGCEERecHitFromHGCHEFClusterEnergy, &b_HGCEERecHitFromHGCHEFClusterEnergy);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterEta", &HGCEERecHitFromHGCHEFClusterEta, &b_HGCEERecHitFromHGCHEFClusterEta);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterPhi", &HGCEERecHitFromHGCHEFClusterPhi, &b_HGCEERecHitFromHGCHEFClusterPhi);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterR", &HGCEERecHitFromHGCHEFClusterR, &b_HGCEERecHitFromHGCHEFClusterR);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterTime", &HGCEERecHitFromHGCHEFClusterTime, &b_HGCEERecHitFromHGCHEFClusterTime);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterX", &HGCEERecHitFromHGCHEFClusterX, &b_HGCEERecHitFromHGCHEFClusterX);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterY", &HGCEERecHitFromHGCHEFClusterY, &b_HGCEERecHitFromHGCHEFClusterY);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterZ", &HGCEERecHitFromHGCHEFClusterZ, &b_HGCEERecHitFromHGCHEFClusterZ);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner1Eta", &HGCHEBRecHitFromHGCEEClusterCorner1Eta, &b_HGCHEBRecHitFromHGCEEClusterCorner1Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner1Phi", &HGCHEBRecHitFromHGCEEClusterCorner1Phi, &b_HGCHEBRecHitFromHGCEEClusterCorner1Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner2Eta", &HGCHEBRecHitFromHGCEEClusterCorner2Eta, &b_HGCHEBRecHitFromHGCEEClusterCorner2Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner2Phi", &HGCHEBRecHitFromHGCEEClusterCorner2Phi, &b_HGCHEBRecHitFromHGCEEClusterCorner2Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner3Eta", &HGCHEBRecHitFromHGCEEClusterCorner3Eta, &b_HGCHEBRecHitFromHGCEEClusterCorner3Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner3Phi", &HGCHEBRecHitFromHGCEEClusterCorner3Phi, &b_HGCHEBRecHitFromHGCEEClusterCorner3Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner4Eta", &HGCHEBRecHitFromHGCEEClusterCorner4Eta, &b_HGCHEBRecHitFromHGCEEClusterCorner4Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCorner4Phi", &HGCHEBRecHitFromHGCEEClusterCorner4Phi, &b_HGCHEBRecHitFromHGCEEClusterCorner4Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterEnergy", &HGCHEBRecHitFromHGCEEClusterEnergy, &b_HGCHEBRecHitFromHGCEEClusterEnergy);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterEta", &HGCHEBRecHitFromHGCEEClusterEta, &b_HGCHEBRecHitFromHGCEEClusterEta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterPhi", &HGCHEBRecHitFromHGCEEClusterPhi, &b_HGCHEBRecHitFromHGCEEClusterPhi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterR", &HGCHEBRecHitFromHGCEEClusterR, &b_HGCHEBRecHitFromHGCEEClusterR);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterTime", &HGCHEBRecHitFromHGCEEClusterTime, &b_HGCHEBRecHitFromHGCEEClusterTime);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterX", &HGCHEBRecHitFromHGCEEClusterX, &b_HGCHEBRecHitFromHGCEEClusterX);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterY", &HGCHEBRecHitFromHGCEEClusterY, &b_HGCHEBRecHitFromHGCEEClusterY);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterZ", &HGCHEBRecHitFromHGCEEClusterZ, &b_HGCHEBRecHitFromHGCEEClusterZ);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner1Eta", &HGCHEBRecHitFromHGCHEBClusterCorner1Eta, &b_HGCHEBRecHitFromHGCHEBClusterCorner1Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner1Phi", &HGCHEBRecHitFromHGCHEBClusterCorner1Phi, &b_HGCHEBRecHitFromHGCHEBClusterCorner1Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner2Eta", &HGCHEBRecHitFromHGCHEBClusterCorner2Eta, &b_HGCHEBRecHitFromHGCHEBClusterCorner2Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner2Phi", &HGCHEBRecHitFromHGCHEBClusterCorner2Phi, &b_HGCHEBRecHitFromHGCHEBClusterCorner2Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner3Eta", &HGCHEBRecHitFromHGCHEBClusterCorner3Eta, &b_HGCHEBRecHitFromHGCHEBClusterCorner3Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner3Phi", &HGCHEBRecHitFromHGCHEBClusterCorner3Phi, &b_HGCHEBRecHitFromHGCHEBClusterCorner3Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner4Eta", &HGCHEBRecHitFromHGCHEBClusterCorner4Eta, &b_HGCHEBRecHitFromHGCHEBClusterCorner4Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCorner4Phi", &HGCHEBRecHitFromHGCHEBClusterCorner4Phi, &b_HGCHEBRecHitFromHGCHEBClusterCorner4Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterEnergy", &HGCHEBRecHitFromHGCHEBClusterEnergy, &b_HGCHEBRecHitFromHGCHEBClusterEnergy);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterEta", &HGCHEBRecHitFromHGCHEBClusterEta, &b_HGCHEBRecHitFromHGCHEBClusterEta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterPhi", &HGCHEBRecHitFromHGCHEBClusterPhi, &b_HGCHEBRecHitFromHGCHEBClusterPhi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterR", &HGCHEBRecHitFromHGCHEBClusterR, &b_HGCHEBRecHitFromHGCHEBClusterR);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterTime", &HGCHEBRecHitFromHGCHEBClusterTime, &b_HGCHEBRecHitFromHGCHEBClusterTime);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterX", &HGCHEBRecHitFromHGCHEBClusterX, &b_HGCHEBRecHitFromHGCHEBClusterX);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterY", &HGCHEBRecHitFromHGCHEBClusterY, &b_HGCHEBRecHitFromHGCHEBClusterY);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterZ", &HGCHEBRecHitFromHGCHEBClusterZ, &b_HGCHEBRecHitFromHGCHEBClusterZ);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner1Eta", &HGCHEBRecHitFromHGCHEFClusterCorner1Eta, &b_HGCHEBRecHitFromHGCHEFClusterCorner1Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner1Phi", &HGCHEBRecHitFromHGCHEFClusterCorner1Phi, &b_HGCHEBRecHitFromHGCHEFClusterCorner1Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner2Eta", &HGCHEBRecHitFromHGCHEFClusterCorner2Eta, &b_HGCHEBRecHitFromHGCHEFClusterCorner2Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner2Phi", &HGCHEBRecHitFromHGCHEFClusterCorner2Phi, &b_HGCHEBRecHitFromHGCHEFClusterCorner2Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner3Eta", &HGCHEBRecHitFromHGCHEFClusterCorner3Eta, &b_HGCHEBRecHitFromHGCHEFClusterCorner3Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner3Phi", &HGCHEBRecHitFromHGCHEFClusterCorner3Phi, &b_HGCHEBRecHitFromHGCHEFClusterCorner3Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner4Eta", &HGCHEBRecHitFromHGCHEFClusterCorner4Eta, &b_HGCHEBRecHitFromHGCHEFClusterCorner4Eta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCorner4Phi", &HGCHEBRecHitFromHGCHEFClusterCorner4Phi, &b_HGCHEBRecHitFromHGCHEFClusterCorner4Phi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterEnergy", &HGCHEBRecHitFromHGCHEFClusterEnergy, &b_HGCHEBRecHitFromHGCHEFClusterEnergy);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterEta", &HGCHEBRecHitFromHGCHEFClusterEta, &b_HGCHEBRecHitFromHGCHEFClusterEta);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterPhi", &HGCHEBRecHitFromHGCHEFClusterPhi, &b_HGCHEBRecHitFromHGCHEFClusterPhi);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterR", &HGCHEBRecHitFromHGCHEFClusterR, &b_HGCHEBRecHitFromHGCHEFClusterR);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterTime", &HGCHEBRecHitFromHGCHEFClusterTime, &b_HGCHEBRecHitFromHGCHEFClusterTime);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterX", &HGCHEBRecHitFromHGCHEFClusterX, &b_HGCHEBRecHitFromHGCHEFClusterX);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterY", &HGCHEBRecHitFromHGCHEFClusterY, &b_HGCHEBRecHitFromHGCHEFClusterY);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterZ", &HGCHEBRecHitFromHGCHEFClusterZ, &b_HGCHEBRecHitFromHGCHEFClusterZ);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner1Eta", &HGCHEFRecHitFromHGCEEClusterCorner1Eta, &b_HGCHEFRecHitFromHGCEEClusterCorner1Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner1Phi", &HGCHEFRecHitFromHGCEEClusterCorner1Phi, &b_HGCHEFRecHitFromHGCEEClusterCorner1Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner2Eta", &HGCHEFRecHitFromHGCEEClusterCorner2Eta, &b_HGCHEFRecHitFromHGCEEClusterCorner2Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner2Phi", &HGCHEFRecHitFromHGCEEClusterCorner2Phi, &b_HGCHEFRecHitFromHGCEEClusterCorner2Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner3Eta", &HGCHEFRecHitFromHGCEEClusterCorner3Eta, &b_HGCHEFRecHitFromHGCEEClusterCorner3Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner3Phi", &HGCHEFRecHitFromHGCEEClusterCorner3Phi, &b_HGCHEFRecHitFromHGCEEClusterCorner3Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner4Eta", &HGCHEFRecHitFromHGCEEClusterCorner4Eta, &b_HGCHEFRecHitFromHGCEEClusterCorner4Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCorner4Phi", &HGCHEFRecHitFromHGCEEClusterCorner4Phi, &b_HGCHEFRecHitFromHGCEEClusterCorner4Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterEnergy", &HGCHEFRecHitFromHGCEEClusterEnergy, &b_HGCHEFRecHitFromHGCEEClusterEnergy);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterEta", &HGCHEFRecHitFromHGCEEClusterEta, &b_HGCHEFRecHitFromHGCEEClusterEta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterPhi", &HGCHEFRecHitFromHGCEEClusterPhi, &b_HGCHEFRecHitFromHGCEEClusterPhi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterR", &HGCHEFRecHitFromHGCEEClusterR, &b_HGCHEFRecHitFromHGCEEClusterR);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterTime", &HGCHEFRecHitFromHGCEEClusterTime, &b_HGCHEFRecHitFromHGCEEClusterTime);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterX", &HGCHEFRecHitFromHGCEEClusterX, &b_HGCHEFRecHitFromHGCEEClusterX);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterY", &HGCHEFRecHitFromHGCEEClusterY, &b_HGCHEFRecHitFromHGCEEClusterY);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterZ", &HGCHEFRecHitFromHGCEEClusterZ, &b_HGCHEFRecHitFromHGCEEClusterZ);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner1Eta", &HGCHEFRecHitFromHGCHEBClusterCorner1Eta, &b_HGCHEFRecHitFromHGCHEBClusterCorner1Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner1Phi", &HGCHEFRecHitFromHGCHEBClusterCorner1Phi, &b_HGCHEFRecHitFromHGCHEBClusterCorner1Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner2Eta", &HGCHEFRecHitFromHGCHEBClusterCorner2Eta, &b_HGCHEFRecHitFromHGCHEBClusterCorner2Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner2Phi", &HGCHEFRecHitFromHGCHEBClusterCorner2Phi, &b_HGCHEFRecHitFromHGCHEBClusterCorner2Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner3Eta", &HGCHEFRecHitFromHGCHEBClusterCorner3Eta, &b_HGCHEFRecHitFromHGCHEBClusterCorner3Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner3Phi", &HGCHEFRecHitFromHGCHEBClusterCorner3Phi, &b_HGCHEFRecHitFromHGCHEBClusterCorner3Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner4Eta", &HGCHEFRecHitFromHGCHEBClusterCorner4Eta, &b_HGCHEFRecHitFromHGCHEBClusterCorner4Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCorner4Phi", &HGCHEFRecHitFromHGCHEBClusterCorner4Phi, &b_HGCHEFRecHitFromHGCHEBClusterCorner4Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterEnergy", &HGCHEFRecHitFromHGCHEBClusterEnergy, &b_HGCHEFRecHitFromHGCHEBClusterEnergy);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterEta", &HGCHEFRecHitFromHGCHEBClusterEta, &b_HGCHEFRecHitFromHGCHEBClusterEta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterPhi", &HGCHEFRecHitFromHGCHEBClusterPhi, &b_HGCHEFRecHitFromHGCHEBClusterPhi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterR", &HGCHEFRecHitFromHGCHEBClusterR, &b_HGCHEFRecHitFromHGCHEBClusterR);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterTime", &HGCHEFRecHitFromHGCHEBClusterTime, &b_HGCHEFRecHitFromHGCHEBClusterTime);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterX", &HGCHEFRecHitFromHGCHEBClusterX, &b_HGCHEFRecHitFromHGCHEBClusterX);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterY", &HGCHEFRecHitFromHGCHEBClusterY, &b_HGCHEFRecHitFromHGCHEBClusterY);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterZ", &HGCHEFRecHitFromHGCHEBClusterZ, &b_HGCHEFRecHitFromHGCHEBClusterZ);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner1Eta", &HGCHEFRecHitFromHGCHEFClusterCorner1Eta, &b_HGCHEFRecHitFromHGCHEFClusterCorner1Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner1Phi", &HGCHEFRecHitFromHGCHEFClusterCorner1Phi, &b_HGCHEFRecHitFromHGCHEFClusterCorner1Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner2Eta", &HGCHEFRecHitFromHGCHEFClusterCorner2Eta, &b_HGCHEFRecHitFromHGCHEFClusterCorner2Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner2Phi", &HGCHEFRecHitFromHGCHEFClusterCorner2Phi, &b_HGCHEFRecHitFromHGCHEFClusterCorner2Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner3Eta", &HGCHEFRecHitFromHGCHEFClusterCorner3Eta, &b_HGCHEFRecHitFromHGCHEFClusterCorner3Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner3Phi", &HGCHEFRecHitFromHGCHEFClusterCorner3Phi, &b_HGCHEFRecHitFromHGCHEFClusterCorner3Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner4Eta", &HGCHEFRecHitFromHGCHEFClusterCorner4Eta, &b_HGCHEFRecHitFromHGCHEFClusterCorner4Eta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCorner4Phi", &HGCHEFRecHitFromHGCHEFClusterCorner4Phi, &b_HGCHEFRecHitFromHGCHEFClusterCorner4Phi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterEnergy", &HGCHEFRecHitFromHGCHEFClusterEnergy, &b_HGCHEFRecHitFromHGCHEFClusterEnergy);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterEta", &HGCHEFRecHitFromHGCHEFClusterEta, &b_HGCHEFRecHitFromHGCHEFClusterEta);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterPhi", &HGCHEFRecHitFromHGCHEFClusterPhi, &b_HGCHEFRecHitFromHGCHEFClusterPhi);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterR", &HGCHEFRecHitFromHGCHEFClusterR, &b_HGCHEFRecHitFromHGCHEFClusterR);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterTime", &HGCHEFRecHitFromHGCHEFClusterTime, &b_HGCHEFRecHitFromHGCHEFClusterTime);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterX", &HGCHEFRecHitFromHGCHEFClusterX, &b_HGCHEFRecHitFromHGCHEFClusterX);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterY", &HGCHEFRecHitFromHGCHEFClusterY, &b_HGCHEFRecHitFromHGCHEFClusterY);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterZ", &HGCHEFRecHitFromHGCHEFClusterZ, &b_HGCHEFRecHitFromHGCHEFClusterZ);
   fChain->SetBranchAddress("HGCEEPFClusterEnergy", &HGCEEPFClusterEnergy, &b_HGCEEPFClusterEnergy);
   fChain->SetBranchAddress("HGCEEPFClusterEta", &HGCEEPFClusterEta, &b_HGCEEPFClusterEta);
   fChain->SetBranchAddress("HGCEEPFClusterPhi", &HGCEEPFClusterPhi, &b_HGCEEPFClusterPhi);
   fChain->SetBranchAddress("HGCEEPFClusterPt", &HGCEEPFClusterPt, &b_HGCEEPFClusterPt);
   fChain->SetBranchAddress("HGCEEPFClusterR", &HGCEEPFClusterR, &b_HGCEEPFClusterR);
   fChain->SetBranchAddress("HGCEEPFClusterTime", &HGCEEPFClusterTime, &b_HGCEEPFClusterTime);
   fChain->SetBranchAddress("HGCEEPFClusterX", &HGCEEPFClusterX, &b_HGCEEPFClusterX);
   fChain->SetBranchAddress("HGCEEPFClusterY", &HGCEEPFClusterY, &b_HGCEEPFClusterY);
   fChain->SetBranchAddress("HGCEEPFClusterZ", &HGCEEPFClusterZ, &b_HGCEEPFClusterZ);
   fChain->SetBranchAddress("HGCHEBPFClusterEnergy", &HGCHEBPFClusterEnergy, &b_HGCHEBPFClusterEnergy);
   fChain->SetBranchAddress("HGCHEBPFClusterEta", &HGCHEBPFClusterEta, &b_HGCHEBPFClusterEta);
   fChain->SetBranchAddress("HGCHEBPFClusterPhi", &HGCHEBPFClusterPhi, &b_HGCHEBPFClusterPhi);
   fChain->SetBranchAddress("HGCHEBPFClusterPt", &HGCHEBPFClusterPt, &b_HGCHEBPFClusterPt);
   fChain->SetBranchAddress("HGCHEBPFClusterR", &HGCHEBPFClusterR, &b_HGCHEBPFClusterR);
   fChain->SetBranchAddress("HGCHEBPFClusterTime", &HGCHEBPFClusterTime, &b_HGCHEBPFClusterTime);
   fChain->SetBranchAddress("HGCHEBPFClusterX", &HGCHEBPFClusterX, &b_HGCHEBPFClusterX);
   fChain->SetBranchAddress("HGCHEBPFClusterY", &HGCHEBPFClusterY, &b_HGCHEBPFClusterY);
   fChain->SetBranchAddress("HGCHEBPFClusterZ", &HGCHEBPFClusterZ, &b_HGCHEBPFClusterZ);
   fChain->SetBranchAddress("HGCHEFPFClusterEnergy", &HGCHEFPFClusterEnergy, &b_HGCHEFPFClusterEnergy);
   fChain->SetBranchAddress("HGCHEFPFClusterEta", &HGCHEFPFClusterEta, &b_HGCHEFPFClusterEta);
   fChain->SetBranchAddress("HGCHEFPFClusterPhi", &HGCHEFPFClusterPhi, &b_HGCHEFPFClusterPhi);
   fChain->SetBranchAddress("HGCHEFPFClusterPt", &HGCHEFPFClusterPt, &b_HGCHEFPFClusterPt);
   fChain->SetBranchAddress("HGCHEFPFClusterR", &HGCHEFPFClusterR, &b_HGCHEFPFClusterR);
   fChain->SetBranchAddress("HGCHEFPFClusterTime", &HGCHEFPFClusterTime, &b_HGCHEFPFClusterTime);
   fChain->SetBranchAddress("HGCHEFPFClusterX", &HGCHEFPFClusterX, &b_HGCHEFPFClusterX);
   fChain->SetBranchAddress("HGCHEFPFClusterY", &HGCHEFPFClusterY, &b_HGCHEFPFClusterY);
   fChain->SetBranchAddress("HGCHEFPFClusterZ", &HGCHEFPFClusterZ, &b_HGCHEFPFClusterZ);
   fChain->SetBranchAddress("PFAK1p5JetArea", &PFAK1p5JetArea, &b_PFAK1p5JetArea);
   fChain->SetBranchAddress("PFAK1p5JetEnergy", &PFAK1p5JetEnergy, &b_PFAK1p5JetEnergy);
   fChain->SetBranchAddress("PFAK1p5JetEta", &PFAK1p5JetEta, &b_PFAK1p5JetEta);
   fChain->SetBranchAddress("PFAK1p5JetNSubJ", &PFAK1p5JetNSubJ, &b_PFAK1p5JetNSubJ);
   fChain->SetBranchAddress("PFAK1p5JetP", &PFAK1p5JetP, &b_PFAK1p5JetP);
   fChain->SetBranchAddress("PFAK1p5JetPhi", &PFAK1p5JetPhi, &b_PFAK1p5JetPhi);
   fChain->SetBranchAddress("PFAK1p5JetPt", &PFAK1p5JetPt, &b_PFAK1p5JetPt);
   fChain->SetBranchAddress("PFAK1p5JetRCutFactors", &PFAK1p5JetRCutFactors, &b_PFAK1p5JetRCutFactors);
   fChain->SetBranchAddress("PFAK1p5JetRawMass", &PFAK1p5JetRawMass, &b_PFAK1p5JetRawMass);
   fChain->SetBranchAddress("PFAK1p5JetTau1", &PFAK1p5JetTau1, &b_PFAK1p5JetTau1);
   fChain->SetBranchAddress("PFAK1p5JetTau2", &PFAK1p5JetTau2, &b_PFAK1p5JetTau2);
   fChain->SetBranchAddress("PFAK1p5JetTau3", &PFAK1p5JetTau3, &b_PFAK1p5JetTau3);
   fChain->SetBranchAddress("PFCA4JetArea", &PFCA4JetArea, &b_PFCA4JetArea);
   fChain->SetBranchAddress("PFCA4JetEnergy", &PFCA4JetEnergy, &b_PFCA4JetEnergy);
   fChain->SetBranchAddress("PFCA4JetEta", &PFCA4JetEta, &b_PFCA4JetEta);
   fChain->SetBranchAddress("PFCA4JetNSubJ", &PFCA4JetNSubJ, &b_PFCA4JetNSubJ);
   fChain->SetBranchAddress("PFCA4JetP", &PFCA4JetP, &b_PFCA4JetP);
   fChain->SetBranchAddress("PFCA4JetPhi", &PFCA4JetPhi, &b_PFCA4JetPhi);
   fChain->SetBranchAddress("PFCA4JetPt", &PFCA4JetPt, &b_PFCA4JetPt);
   fChain->SetBranchAddress("PFCA4JetRCutFactors", &PFCA4JetRCutFactors, &b_PFCA4JetRCutFactors);
   fChain->SetBranchAddress("PFCA4JetRawMass", &PFCA4JetRawMass, &b_PFCA4JetRawMass);
   fChain->SetBranchAddress("PFCA4JetTau1", &PFCA4JetTau1, &b_PFCA4JetTau1);
   fChain->SetBranchAddress("PFCA4JetTau2", &PFCA4JetTau2, &b_PFCA4JetTau2);
   fChain->SetBranchAddress("PFCA4JetTau3", &PFCA4JetTau3, &b_PFCA4JetTau3);
   fChain->SetBranchAddress("PFCandEta", &PFCandEta, &b_PFCandEta);
   fChain->SetBranchAddress("PFCandPhi", &PFCandPhi, &b_PFCandPhi);
   fChain->SetBranchAddress("PFCandPt", &PFCandPt, &b_PFCandPt);
   fChain->SetBranchAddress("PFTauEta", &PFTauEta, &b_PFTauEta);
   fChain->SetBranchAddress("PFTauP", &PFTauP, &b_PFTauP);
   fChain->SetBranchAddress("PFTauPhi", &PFTauPhi, &b_PFTauPhi);
   fChain->SetBranchAddress("PFTauPt", &PFTauPt, &b_PFTauPt);
   fChain->SetBranchAddress("VertexChi2", &VertexChi2, &b_VertexChi2);
   fChain->SetBranchAddress("VertexNDF", &VertexNDF, &b_VertexNDF);
   fChain->SetBranchAddress("VertexRho", &VertexRho, &b_VertexRho);
   fChain->SetBranchAddress("VertexX", &VertexX, &b_VertexX);
   fChain->SetBranchAddress("VertexXErr", &VertexXErr, &b_VertexXErr);
   fChain->SetBranchAddress("VertexY", &VertexY, &b_VertexY);
   fChain->SetBranchAddress("VertexYErr", &VertexYErr, &b_VertexYErr);
   fChain->SetBranchAddress("VertexZ", &VertexZ, &b_VertexZ);
   fChain->SetBranchAddress("VertexZErr", &VertexZErr, &b_VertexZErr);
   fChain->SetBranchAddress("HGCEEPFClusterHGCEERecHitFraction", &HGCEEPFClusterHGCEERecHitFraction, &b_HGCEEPFClusterHGCEERecHitFraction);
   fChain->SetBranchAddress("HGCEEPFClusterHGCHEBRecHitFraction", &HGCEEPFClusterHGCHEBRecHitFraction, &b_HGCEEPFClusterHGCHEBRecHitFraction);
   fChain->SetBranchAddress("HGCEEPFClusterHGCHEFRecHitFraction", &HGCEEPFClusterHGCHEFRecHitFraction, &b_HGCEEPFClusterHGCHEFRecHitFraction);
   fChain->SetBranchAddress("HGCHEBPFClusterHGCEERecHitFraction", &HGCHEBPFClusterHGCEERecHitFraction, &b_HGCHEBPFClusterHGCEERecHitFraction);
   fChain->SetBranchAddress("HGCHEBPFClusterHGCHEBRecHitFraction", &HGCHEBPFClusterHGCHEBRecHitFraction, &b_HGCHEBPFClusterHGCHEBRecHitFraction);
   fChain->SetBranchAddress("HGCHEBPFClusterHGCHEFRecHitFraction", &HGCHEBPFClusterHGCHEFRecHitFraction, &b_HGCHEBPFClusterHGCHEFRecHitFraction);
   fChain->SetBranchAddress("HGCHEFPFClusterHGCEERecHitFraction", &HGCHEFPFClusterHGCEERecHitFraction, &b_HGCHEFPFClusterHGCEERecHitFraction);
   fChain->SetBranchAddress("HGCHEFPFClusterHGCHEBRecHitFraction", &HGCHEFPFClusterHGCHEBRecHitFraction, &b_HGCHEFPFClusterHGCHEBRecHitFraction);
   fChain->SetBranchAddress("HGCHEFPFClusterHGCHEFRecHitFraction", &HGCHEFPFClusterHGCHEFRecHitFraction, &b_HGCHEFPFClusterHGCHEFRecHitFraction);
   fChain->SetBranchAddress("PFAK1p5JetTrimmedMass", &PFAK1p5JetTrimmedMass, &b_PFAK1p5JetTrimmedMass);
   fChain->SetBranchAddress("PFAK1p5JetTrimmedMassDrop", &PFAK1p5JetTrimmedMassDrop, &b_PFAK1p5JetTrimmedMassDrop);
   fChain->SetBranchAddress("PFCA4JetTrimmedMass", &PFCA4JetTrimmedMass, &b_PFCA4JetTrimmedMass);
   fChain->SetBranchAddress("PFCA4JetTrimmedMassDrop", &PFCA4JetTrimmedMassDrop, &b_PFCA4JetTrimmedMassDrop);
   fChain->SetBranchAddress("GenParticleHasPartonDaughter", &GenParticleHasPartonDaughter, &b_GenParticleHasPartonDaughter);
   fChain->SetBranchAddress("GenParticleMother1Index", &GenParticleMother1Index, &b_GenParticleMother1Index);
   fChain->SetBranchAddress("GenParticleMother2Index", &GenParticleMother2Index, &b_GenParticleMother2Index);
   fChain->SetBranchAddress("GenParticleNumDaught", &GenParticleNumDaught, &b_GenParticleNumDaught);
   fChain->SetBranchAddress("GenParticleNumDaught3", &GenParticleNumDaught3, &b_GenParticleNumDaught3);
   fChain->SetBranchAddress("GenParticleNumMother", &GenParticleNumMother, &b_GenParticleNumMother);
   fChain->SetBranchAddress("GenParticlePdgId", &GenParticlePdgId, &b_GenParticlePdgId);
   fChain->SetBranchAddress("GenParticleStatus", &GenParticleStatus, &b_GenParticleStatus);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterCell", &HGCEERecHitFromHGCEEClusterCell, &b_HGCEERecHitFromHGCEEClusterCell);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterLayer", &HGCEERecHitFromHGCEEClusterLayer, &b_HGCEERecHitFromHGCEEClusterLayer);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterSector", &HGCEERecHitFromHGCEEClusterSector, &b_HGCEERecHitFromHGCEEClusterSector);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterSubSector", &HGCEERecHitFromHGCEEClusterSubSector, &b_HGCEERecHitFromHGCEEClusterSubSector);
   fChain->SetBranchAddress("HGCEERecHitFromHGCEEClusterSubdet", &HGCEERecHitFromHGCEEClusterSubdet, &b_HGCEERecHitFromHGCEEClusterSubdet);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterCell", &HGCEERecHitFromHGCHEBClusterCell, &b_HGCEERecHitFromHGCHEBClusterCell);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterLayer", &HGCEERecHitFromHGCHEBClusterLayer, &b_HGCEERecHitFromHGCHEBClusterLayer);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterSector", &HGCEERecHitFromHGCHEBClusterSector, &b_HGCEERecHitFromHGCHEBClusterSector);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterSubSector", &HGCEERecHitFromHGCHEBClusterSubSector, &b_HGCEERecHitFromHGCHEBClusterSubSector);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEBClusterSubdet", &HGCEERecHitFromHGCHEBClusterSubdet, &b_HGCEERecHitFromHGCHEBClusterSubdet);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterCell", &HGCEERecHitFromHGCHEFClusterCell, &b_HGCEERecHitFromHGCHEFClusterCell);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterLayer", &HGCEERecHitFromHGCHEFClusterLayer, &b_HGCEERecHitFromHGCHEFClusterLayer);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterSector", &HGCEERecHitFromHGCHEFClusterSector, &b_HGCEERecHitFromHGCHEFClusterSector);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterSubSector", &HGCEERecHitFromHGCHEFClusterSubSector, &b_HGCEERecHitFromHGCHEFClusterSubSector);
   fChain->SetBranchAddress("HGCEERecHitFromHGCHEFClusterSubdet", &HGCEERecHitFromHGCHEFClusterSubdet, &b_HGCEERecHitFromHGCHEFClusterSubdet);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterCell", &HGCHEBRecHitFromHGCEEClusterCell, &b_HGCHEBRecHitFromHGCEEClusterCell);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterLayer", &HGCHEBRecHitFromHGCEEClusterLayer, &b_HGCHEBRecHitFromHGCEEClusterLayer);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterSector", &HGCHEBRecHitFromHGCEEClusterSector, &b_HGCHEBRecHitFromHGCEEClusterSector);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterSubSector", &HGCHEBRecHitFromHGCEEClusterSubSector, &b_HGCHEBRecHitFromHGCEEClusterSubSector);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCEEClusterSubdet", &HGCHEBRecHitFromHGCEEClusterSubdet, &b_HGCHEBRecHitFromHGCEEClusterSubdet);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterCell", &HGCHEBRecHitFromHGCHEBClusterCell, &b_HGCHEBRecHitFromHGCHEBClusterCell);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterLayer", &HGCHEBRecHitFromHGCHEBClusterLayer, &b_HGCHEBRecHitFromHGCHEBClusterLayer);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterSector", &HGCHEBRecHitFromHGCHEBClusterSector, &b_HGCHEBRecHitFromHGCHEBClusterSector);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterSubSector", &HGCHEBRecHitFromHGCHEBClusterSubSector, &b_HGCHEBRecHitFromHGCHEBClusterSubSector);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEBClusterSubdet", &HGCHEBRecHitFromHGCHEBClusterSubdet, &b_HGCHEBRecHitFromHGCHEBClusterSubdet);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterCell", &HGCHEBRecHitFromHGCHEFClusterCell, &b_HGCHEBRecHitFromHGCHEFClusterCell);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterLayer", &HGCHEBRecHitFromHGCHEFClusterLayer, &b_HGCHEBRecHitFromHGCHEFClusterLayer);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterSector", &HGCHEBRecHitFromHGCHEFClusterSector, &b_HGCHEBRecHitFromHGCHEFClusterSector);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterSubSector", &HGCHEBRecHitFromHGCHEFClusterSubSector, &b_HGCHEBRecHitFromHGCHEFClusterSubSector);
   fChain->SetBranchAddress("HGCHEBRecHitFromHGCHEFClusterSubdet", &HGCHEBRecHitFromHGCHEFClusterSubdet, &b_HGCHEBRecHitFromHGCHEFClusterSubdet);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterCell", &HGCHEFRecHitFromHGCEEClusterCell, &b_HGCHEFRecHitFromHGCEEClusterCell);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterLayer", &HGCHEFRecHitFromHGCEEClusterLayer, &b_HGCHEFRecHitFromHGCEEClusterLayer);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterSector", &HGCHEFRecHitFromHGCEEClusterSector, &b_HGCHEFRecHitFromHGCEEClusterSector);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterSubSector", &HGCHEFRecHitFromHGCEEClusterSubSector, &b_HGCHEFRecHitFromHGCEEClusterSubSector);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCEEClusterSubdet", &HGCHEFRecHitFromHGCEEClusterSubdet, &b_HGCHEFRecHitFromHGCEEClusterSubdet);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterCell", &HGCHEFRecHitFromHGCHEBClusterCell, &b_HGCHEFRecHitFromHGCHEBClusterCell);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterLayer", &HGCHEFRecHitFromHGCHEBClusterLayer, &b_HGCHEFRecHitFromHGCHEBClusterLayer);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterSector", &HGCHEFRecHitFromHGCHEBClusterSector, &b_HGCHEFRecHitFromHGCHEBClusterSector);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterSubSector", &HGCHEFRecHitFromHGCHEBClusterSubSector, &b_HGCHEFRecHitFromHGCHEBClusterSubSector);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEBClusterSubdet", &HGCHEFRecHitFromHGCHEBClusterSubdet, &b_HGCHEFRecHitFromHGCHEBClusterSubdet);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterCell", &HGCHEFRecHitFromHGCHEFClusterCell, &b_HGCHEFRecHitFromHGCHEFClusterCell);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterLayer", &HGCHEFRecHitFromHGCHEFClusterLayer, &b_HGCHEFRecHitFromHGCHEFClusterLayer);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterSector", &HGCHEFRecHitFromHGCHEFClusterSector, &b_HGCHEFRecHitFromHGCHEFClusterSector);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterSubSector", &HGCHEFRecHitFromHGCHEFClusterSubSector, &b_HGCHEFRecHitFromHGCHEFClusterSubSector);
   fChain->SetBranchAddress("HGCHEFRecHitFromHGCHEFClusterSubdet", &HGCHEFRecHitFromHGCHEFClusterSubdet, &b_HGCHEFRecHitFromHGCHEFClusterSubdet);
   fChain->SetBranchAddress("HGCEEPFClusterLayer", &HGCEEPFClusterLayer, &b_HGCEEPFClusterLayer);
   fChain->SetBranchAddress("HGCHEBPFClusterLayer", &HGCHEBPFClusterLayer, &b_HGCHEBPFClusterLayer);
   fChain->SetBranchAddress("HGCHEFPFClusterLayer", &HGCHEFPFClusterLayer, &b_HGCHEFPFClusterLayer);
   fChain->SetBranchAddress("PFAK1p5JetRawNPFCands", &PFAK1p5JetRawNPFCands, &b_PFAK1p5JetRawNPFCands);
   fChain->SetBranchAddress("PFCA4JetRawNPFCands", &PFCA4JetRawNPFCands, &b_PFCA4JetRawNPFCands);
   fChain->SetBranchAddress("PFCandId", &PFCandId, &b_PFCandId);
   fChain->SetBranchAddress("PFTauPassAll", &PFTauPassAll, &b_PFTauPassAll);
   fChain->SetBranchAddress("PFTauPassDecayModeFinding", &PFTauPassDecayModeFinding, &b_PFTauPassDecayModeFinding);
   fChain->SetBranchAddress("PFTauPassLooseCombinedIsolation", &PFTauPassLooseCombinedIsolation, &b_PFTauPassLooseCombinedIsolation);
   fChain->SetBranchAddress("PFTauPassMuonRejection", &PFTauPassMuonRejection, &b_PFTauPassMuonRejection);
   fChain->SetBranchAddress("VertexNTracks", &VertexNTracks, &b_VertexNTracks);
   fChain->SetBranchAddress("VertexNTracksW05", &VertexNTracksW05, &b_VertexNTracksW05);
   fChain->SetBranchAddress("HGCEEPFClusterHGCEERecHitIndex", &HGCEEPFClusterHGCEERecHitIndex, &b_HGCEEPFClusterHGCEERecHitIndex);
   fChain->SetBranchAddress("HGCEEPFClusterHGCHEBRecHitIndex", &HGCEEPFClusterHGCHEBRecHitIndex, &b_HGCEEPFClusterHGCHEBRecHitIndex);
   fChain->SetBranchAddress("HGCEEPFClusterHGCHEFRecHitIndex", &HGCEEPFClusterHGCHEFRecHitIndex, &b_HGCEEPFClusterHGCHEFRecHitIndex);
   fChain->SetBranchAddress("HGCHEBPFClusterHGCEERecHitIndex", &HGCHEBPFClusterHGCEERecHitIndex, &b_HGCHEBPFClusterHGCEERecHitIndex);
   fChain->SetBranchAddress("HGCHEBPFClusterHGCHEBRecHitIndex", &HGCHEBPFClusterHGCHEBRecHitIndex, &b_HGCHEBPFClusterHGCHEBRecHitIndex);
   fChain->SetBranchAddress("HGCHEBPFClusterHGCHEFRecHitIndex", &HGCHEBPFClusterHGCHEFRecHitIndex, &b_HGCHEBPFClusterHGCHEFRecHitIndex);
   fChain->SetBranchAddress("HGCHEFPFClusterHGCEERecHitIndex", &HGCHEFPFClusterHGCEERecHitIndex, &b_HGCHEFPFClusterHGCEERecHitIndex);
   fChain->SetBranchAddress("HGCHEFPFClusterHGCHEBRecHitIndex", &HGCHEFPFClusterHGCHEBRecHitIndex, &b_HGCHEFPFClusterHGCHEBRecHitIndex);
   fChain->SetBranchAddress("HGCHEFPFClusterHGCHEFRecHitIndex", &HGCHEFPFClusterHGCHEFRecHitIndex, &b_HGCHEFPFClusterHGCHEFRecHitIndex);
   fChain->SetBranchAddress("PFAK1p5JetPFCandIndices", &PFAK1p5JetPFCandIndices, &b_PFAK1p5JetPFCandIndices);
   fChain->SetBranchAddress("PFAK1p5JetTrimmedNPFCands", &PFAK1p5JetTrimmedNPFCands, &b_PFAK1p5JetTrimmedNPFCands);
   fChain->SetBranchAddress("PFAK1p5JetTrimmedNSubjets", &PFAK1p5JetTrimmedNSubjets, &b_PFAK1p5JetTrimmedNSubjets);
   fChain->SetBranchAddress("PFCA4JetPFCandIndices", &PFCA4JetPFCandIndices, &b_PFCA4JetPFCandIndices);
   fChain->SetBranchAddress("PFCA4JetTrimmedNPFCands", &PFCA4JetTrimmedNPFCands, &b_PFCA4JetTrimmedNPFCands);
   fChain->SetBranchAddress("PFCA4JetTrimmedNSubjets", &PFCA4JetTrimmedNSubjets, &b_PFCA4JetTrimmedNSubjets);
   fChain->SetBranchAddress("PFCandHGCEEClusterIndex", &PFCandHGCEEClusterIndex, &b_PFCandHGCEEClusterIndex);
   fChain->SetBranchAddress("PFCandHGCHEBClusterIndex", &PFCandHGCHEBClusterIndex, &b_PFCandHGCHEBClusterIndex);
   fChain->SetBranchAddress("PFCandHGCHEFClusterIndex", &PFCandHGCHEFClusterIndex, &b_PFCandHGCHEFClusterIndex);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("run", &run, &b_run);
   Notify();
}

Bool_t HgcalTupleTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HgcalTupleTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HgcalTupleTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HgcalTupleTree_cxx
