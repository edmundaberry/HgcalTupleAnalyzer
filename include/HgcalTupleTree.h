//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep  1 13:13:02 2014 by ROOT version 5.34/07
// from TTree tree/
// found on file: data/HGCAL_QQH_output.root
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

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class HgcalTupleTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
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
   vector<double>  *HGCEERecHitCorner1Eta;
   vector<double>  *HGCEERecHitCorner1Phi;
   vector<double>  *HGCEERecHitCorner2Eta;
   vector<double>  *HGCEERecHitCorner2Phi;
   vector<double>  *HGCEERecHitCorner3Eta;
   vector<double>  *HGCEERecHitCorner3Phi;
   vector<double>  *HGCEERecHitCorner4Eta;
   vector<double>  *HGCEERecHitCorner4Phi;
   vector<double>  *HGCEERecHitEnergy;
   vector<double>  *HGCEERecHitEta;
   vector<double>  *HGCEERecHitPhi;
   vector<double>  *HGCEERecHitR;
   vector<double>  *HGCEERecHitTime;
   vector<double>  *HGCEERecHitX;
   vector<double>  *HGCEERecHitY;
   vector<double>  *HGCEERecHitZ;
   vector<double>  *HGCHEBRecHitCorner1Eta;
   vector<double>  *HGCHEBRecHitCorner1Phi;
   vector<double>  *HGCHEBRecHitCorner2Eta;
   vector<double>  *HGCHEBRecHitCorner2Phi;
   vector<double>  *HGCHEBRecHitCorner3Eta;
   vector<double>  *HGCHEBRecHitCorner3Phi;
   vector<double>  *HGCHEBRecHitCorner4Eta;
   vector<double>  *HGCHEBRecHitCorner4Phi;
   vector<double>  *HGCHEBRecHitEnergy;
   vector<double>  *HGCHEBRecHitEta;
   vector<double>  *HGCHEBRecHitPhi;
   vector<double>  *HGCHEBRecHitR;
   vector<double>  *HGCHEBRecHitTime;
   vector<double>  *HGCHEBRecHitX;
   vector<double>  *HGCHEBRecHitY;
   vector<double>  *HGCHEBRecHitZ;
   vector<double>  *HGCHEFRecHitCorner1Eta;
   vector<double>  *HGCHEFRecHitCorner1Phi;
   vector<double>  *HGCHEFRecHitCorner2Eta;
   vector<double>  *HGCHEFRecHitCorner2Phi;
   vector<double>  *HGCHEFRecHitCorner3Eta;
   vector<double>  *HGCHEFRecHitCorner3Phi;
   vector<double>  *HGCHEFRecHitCorner4Eta;
   vector<double>  *HGCHEFRecHitCorner4Phi;
   vector<double>  *HGCHEFRecHitEnergy;
   vector<double>  *HGCHEFRecHitEta;
   vector<double>  *HGCHEFRecHitPhi;
   vector<double>  *HGCHEFRecHitR;
   vector<double>  *HGCHEFRecHitTime;
   vector<double>  *HGCHEFRecHitX;
   vector<double>  *HGCHEFRecHitY;
   vector<double>  *HGCHEFRecHitZ;
   vector<double>  *PFCA4JetEnergy;
   vector<double>  *PFCA4JetEta;
   vector<double>  *PFCA4JetMass;
   vector<double>  *PFCA4JetNSubJ;
   vector<double>  *PFCA4JetP;
   vector<double>  *PFCA4JetPhi;
   vector<double>  *PFCA4JetPt;
   vector<double>  *PFCA4JetTau1;
   vector<double>  *PFCA4JetTau2;
   vector<double>  *PFCA4JetTau3;
   vector<double>  *PFCA4PrunedJetRCut001Energy;
   vector<double>  *PFCA4PrunedJetRCut001Eta;
   vector<double>  *PFCA4PrunedJetRCut001Mass;
   vector<double>  *PFCA4PrunedJetRCut001MassDrop;
   vector<double>  *PFCA4PrunedJetRCut001NSubJ;
   vector<double>  *PFCA4PrunedJetRCut001P;
   vector<double>  *PFCA4PrunedJetRCut001Phi;
   vector<double>  *PFCA4PrunedJetRCut001Pt;
   vector<double>  *PFCA4PrunedJetRCut001Tau1;
   vector<double>  *PFCA4PrunedJetRCut001Tau2;
   vector<double>  *PFCA4PrunedJetRCut001Tau3;
   vector<double>  *PFCA4PrunedJetRCut003Energy;
   vector<double>  *PFCA4PrunedJetRCut003Eta;
   vector<double>  *PFCA4PrunedJetRCut003Mass;
   vector<double>  *PFCA4PrunedJetRCut003MassDrop;
   vector<double>  *PFCA4PrunedJetRCut003NSubJ;
   vector<double>  *PFCA4PrunedJetRCut003P;
   vector<double>  *PFCA4PrunedJetRCut003Phi;
   vector<double>  *PFCA4PrunedJetRCut003Pt;
   vector<double>  *PFCA4PrunedJetRCut003Tau1;
   vector<double>  *PFCA4PrunedJetRCut003Tau2;
   vector<double>  *PFCA4PrunedJetRCut003Tau3;
   vector<double>  *PFCA4PrunedJetRCut005Energy;
   vector<double>  *PFCA4PrunedJetRCut005Eta;
   vector<double>  *PFCA4PrunedJetRCut005Mass;
   vector<double>  *PFCA4PrunedJetRCut005MassDrop;
   vector<double>  *PFCA4PrunedJetRCut005NSubJ;
   vector<double>  *PFCA4PrunedJetRCut005P;
   vector<double>  *PFCA4PrunedJetRCut005Phi;
   vector<double>  *PFCA4PrunedJetRCut005Pt;
   vector<double>  *PFCA4PrunedJetRCut005Tau1;
   vector<double>  *PFCA4PrunedJetRCut005Tau2;
   vector<double>  *PFCA4PrunedJetRCut005Tau3;
   vector<double>  *PFCA4PrunedJetRCut008Energy;
   vector<double>  *PFCA4PrunedJetRCut008Eta;
   vector<double>  *PFCA4PrunedJetRCut008Mass;
   vector<double>  *PFCA4PrunedJetRCut008MassDrop;
   vector<double>  *PFCA4PrunedJetRCut008NSubJ;
   vector<double>  *PFCA4PrunedJetRCut008P;
   vector<double>  *PFCA4PrunedJetRCut008Phi;
   vector<double>  *PFCA4PrunedJetRCut008Pt;
   vector<double>  *PFCA4PrunedJetRCut008Tau1;
   vector<double>  *PFCA4PrunedJetRCut008Tau2;
   vector<double>  *PFCA4PrunedJetRCut008Tau3;
   vector<double>  *PFCA4PrunedJetRCut01Energy;
   vector<double>  *PFCA4PrunedJetRCut01Eta;
   vector<double>  *PFCA4PrunedJetRCut01Mass;
   vector<double>  *PFCA4PrunedJetRCut01MassDrop;
   vector<double>  *PFCA4PrunedJetRCut01NSubJ;
   vector<double>  *PFCA4PrunedJetRCut01P;
   vector<double>  *PFCA4PrunedJetRCut01Phi;
   vector<double>  *PFCA4PrunedJetRCut01Pt;
   vector<double>  *PFCA4PrunedJetRCut01Tau1;
   vector<double>  *PFCA4PrunedJetRCut01Tau2;
   vector<double>  *PFCA4PrunedJetRCut01Tau3;
   vector<double>  *PFCA4PrunedJetRCut02Energy;
   vector<double>  *PFCA4PrunedJetRCut02Eta;
   vector<double>  *PFCA4PrunedJetRCut02Mass;
   vector<double>  *PFCA4PrunedJetRCut02MassDrop;
   vector<double>  *PFCA4PrunedJetRCut02NSubJ;
   vector<double>  *PFCA4PrunedJetRCut02P;
   vector<double>  *PFCA4PrunedJetRCut02Phi;
   vector<double>  *PFCA4PrunedJetRCut02Pt;
   vector<double>  *PFCA4PrunedJetRCut02Tau1;
   vector<double>  *PFCA4PrunedJetRCut02Tau2;
   vector<double>  *PFCA4PrunedJetRCut02Tau3;
   vector<double>  *PFCA4PrunedJetRCut03Energy;
   vector<double>  *PFCA4PrunedJetRCut03Eta;
   vector<double>  *PFCA4PrunedJetRCut03Mass;
   vector<double>  *PFCA4PrunedJetRCut03MassDrop;
   vector<double>  *PFCA4PrunedJetRCut03NSubJ;
   vector<double>  *PFCA4PrunedJetRCut03P;
   vector<double>  *PFCA4PrunedJetRCut03Phi;
   vector<double>  *PFCA4PrunedJetRCut03Pt;
   vector<double>  *PFCA4PrunedJetRCut03Tau1;
   vector<double>  *PFCA4PrunedJetRCut03Tau2;
   vector<double>  *PFCA4PrunedJetRCut03Tau3;
   vector<double>  *PFCA4PrunedJetRCut04Energy;
   vector<double>  *PFCA4PrunedJetRCut04Eta;
   vector<double>  *PFCA4PrunedJetRCut04Mass;
   vector<double>  *PFCA4PrunedJetRCut04MassDrop;
   vector<double>  *PFCA4PrunedJetRCut04NSubJ;
   vector<double>  *PFCA4PrunedJetRCut04P;
   vector<double>  *PFCA4PrunedJetRCut04Phi;
   vector<double>  *PFCA4PrunedJetRCut04Pt;
   vector<double>  *PFCA4PrunedJetRCut04Tau1;
   vector<double>  *PFCA4PrunedJetRCut04Tau2;
   vector<double>  *PFCA4PrunedJetRCut04Tau3;
   vector<double>  *PFCA4PrunedJetRCut05Energy;
   vector<double>  *PFCA4PrunedJetRCut05Eta;
   vector<double>  *PFCA4PrunedJetRCut05Mass;
   vector<double>  *PFCA4PrunedJetRCut05MassDrop;
   vector<double>  *PFCA4PrunedJetRCut05NSubJ;
   vector<double>  *PFCA4PrunedJetRCut05P;
   vector<double>  *PFCA4PrunedJetRCut05Phi;
   vector<double>  *PFCA4PrunedJetRCut05Pt;
   vector<double>  *PFCA4PrunedJetRCut05Tau1;
   vector<double>  *PFCA4PrunedJetRCut05Tau2;
   vector<double>  *PFCA4PrunedJetRCut05Tau3;
   vector<double>  *PFCA4PrunedJetRCut1Energy;
   vector<double>  *PFCA4PrunedJetRCut1Eta;
   vector<double>  *PFCA4PrunedJetRCut1Mass;
   vector<double>  *PFCA4PrunedJetRCut1MassDrop;
   vector<double>  *PFCA4PrunedJetRCut1NSubJ;
   vector<double>  *PFCA4PrunedJetRCut1P;
   vector<double>  *PFCA4PrunedJetRCut1Phi;
   vector<double>  *PFCA4PrunedJetRCut1Pt;
   vector<double>  *PFCA4PrunedJetRCut1Tau1;
   vector<double>  *PFCA4PrunedJetRCut1Tau2;
   vector<double>  *PFCA4PrunedJetRCut1Tau3;
   vector<double>  *PFCA4PrunedJetRCut2Energy;
   vector<double>  *PFCA4PrunedJetRCut2Eta;
   vector<double>  *PFCA4PrunedJetRCut2Mass;
   vector<double>  *PFCA4PrunedJetRCut2MassDrop;
   vector<double>  *PFCA4PrunedJetRCut2NSubJ;
   vector<double>  *PFCA4PrunedJetRCut2P;
   vector<double>  *PFCA4PrunedJetRCut2Phi;
   vector<double>  *PFCA4PrunedJetRCut2Pt;
   vector<double>  *PFCA4PrunedJetRCut2Tau1;
   vector<double>  *PFCA4PrunedJetRCut2Tau2;
   vector<double>  *PFCA4PrunedJetRCut2Tau3;
   vector<double>  *PFCA4PrunedJetRCut3Energy;
   vector<double>  *PFCA4PrunedJetRCut3Eta;
   vector<double>  *PFCA4PrunedJetRCut3Mass;
   vector<double>  *PFCA4PrunedJetRCut3MassDrop;
   vector<double>  *PFCA4PrunedJetRCut3NSubJ;
   vector<double>  *PFCA4PrunedJetRCut3P;
   vector<double>  *PFCA4PrunedJetRCut3Phi;
   vector<double>  *PFCA4PrunedJetRCut3Pt;
   vector<double>  *PFCA4PrunedJetRCut3Tau1;
   vector<double>  *PFCA4PrunedJetRCut3Tau2;
   vector<double>  *PFCA4PrunedJetRCut3Tau3;
   vector<double>  *PFCA4PrunedJetRCut4Energy;
   vector<double>  *PFCA4PrunedJetRCut4Eta;
   vector<double>  *PFCA4PrunedJetRCut4Mass;
   vector<double>  *PFCA4PrunedJetRCut4MassDrop;
   vector<double>  *PFCA4PrunedJetRCut4NSubJ;
   vector<double>  *PFCA4PrunedJetRCut4P;
   vector<double>  *PFCA4PrunedJetRCut4Phi;
   vector<double>  *PFCA4PrunedJetRCut4Pt;
   vector<double>  *PFCA4PrunedJetRCut4Tau1;
   vector<double>  *PFCA4PrunedJetRCut4Tau2;
   vector<double>  *PFCA4PrunedJetRCut4Tau3;
   vector<double>  *PFCA4PrunedJetRCut5Energy;
   vector<double>  *PFCA4PrunedJetRCut5Eta;
   vector<double>  *PFCA4PrunedJetRCut5Mass;
   vector<double>  *PFCA4PrunedJetRCut5MassDrop;
   vector<double>  *PFCA4PrunedJetRCut5NSubJ;
   vector<double>  *PFCA4PrunedJetRCut5P;
   vector<double>  *PFCA4PrunedJetRCut5Phi;
   vector<double>  *PFCA4PrunedJetRCut5Pt;
   vector<double>  *PFCA4PrunedJetRCut5Tau1;
   vector<double>  *PFCA4PrunedJetRCut5Tau2;
   vector<double>  *PFCA4PrunedJetRCut5Tau3;
   vector<double>  *PFCandEta;
   vector<double>  *PFCandPhi;
   vector<double>  *PFCandPt;
   vector<vector<double> > *PFCA4PrunedJetRCut001DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut001DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut001DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut001DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut003DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut003DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut003DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut003DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut005DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut005DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut005DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut005DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut008DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut008DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut008DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut008DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut01DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut01DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut01DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut01DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut02DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut02DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut02DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut02DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut03DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut03DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut03DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut03DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut04DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut04DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut04DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut04DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut05DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut05DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut05DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut05DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut1DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut1DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut1DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut1DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut2DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut2DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut2DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut2DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut3DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut3DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut3DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut3DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut4DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut4DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut4DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut4DaughterPt;
   vector<vector<double> > *PFCA4PrunedJetRCut5DaughterEta;
   vector<vector<double> > *PFCA4PrunedJetRCut5DaughterMass;
   vector<vector<double> > *PFCA4PrunedJetRCut5DaughterPhi;
   vector<vector<double> > *PFCA4PrunedJetRCut5DaughterPt;
   vector<vector<double> > *PFCandHGCEERecHitFraction;
   vector<vector<double> > *PFCandHGCHEBRecHitFraction;
   vector<vector<double> > *PFCandHGCHEFRecHitFraction;
   vector<int>     *GenParticleHasPartonDaughter;
   vector<int>     *GenParticleMother1Index;
   vector<int>     *GenParticleMother2Index;
   vector<int>     *GenParticleNumDaught;
   vector<int>     *GenParticleNumDaught3;
   vector<int>     *GenParticleNumMother;
   vector<int>     *GenParticlePdgId;
   vector<int>     *GenParticleStatus;
   vector<int>     *HGCEERecHitCell;
   vector<int>     *HGCEERecHitLayer;
   vector<int>     *HGCEERecHitSector;
   vector<int>     *HGCEERecHitSubSector;
   vector<int>     *HGCEERecHitSubdet;
   vector<int>     *HGCHEBRecHitCell;
   vector<int>     *HGCHEBRecHitLayer;
   vector<int>     *HGCHEBRecHitSector;
   vector<int>     *HGCHEBRecHitSubSector;
   vector<int>     *HGCHEBRecHitSubdet;
   vector<int>     *HGCHEFRecHitCell;
   vector<int>     *HGCHEFRecHitLayer;
   vector<int>     *HGCHEFRecHitSector;
   vector<int>     *HGCHEFRecHitSubSector;
   vector<int>     *HGCHEFRecHitSubdet;
   vector<int>     *PFCA4PrunedJetRCut001NDaughters;
   vector<int>     *PFCA4PrunedJetRCut003NDaughters;
   vector<int>     *PFCA4PrunedJetRCut005NDaughters;
   vector<int>     *PFCA4PrunedJetRCut008NDaughters;
   vector<int>     *PFCA4PrunedJetRCut01NDaughters;
   vector<int>     *PFCA4PrunedJetRCut02NDaughters;
   vector<int>     *PFCA4PrunedJetRCut03NDaughters;
   vector<int>     *PFCA4PrunedJetRCut04NDaughters;
   vector<int>     *PFCA4PrunedJetRCut05NDaughters;
   vector<int>     *PFCA4PrunedJetRCut1NDaughters;
   vector<int>     *PFCA4PrunedJetRCut2NDaughters;
   vector<int>     *PFCA4PrunedJetRCut3NDaughters;
   vector<int>     *PFCA4PrunedJetRCut4NDaughters;
   vector<int>     *PFCA4PrunedJetRCut5NDaughters;
   vector<int>     *PFCandId;
   vector<vector<int> > *PFCA4JetPFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut001PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut003PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut005PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut008PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut01PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut02PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut03PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut04PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut05PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut1PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut2PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut3PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut4PFCandIndices;
   vector<vector<int> > *PFCA4PrunedJetRCut5PFCandIndices;
   vector<vector<int> > *PFCandHGCEERecHitIndex;
   vector<vector<int> > *PFCandHGCHEBRecHitIndex;
   vector<vector<int> > *PFCandHGCHEFRecHitIndex;
   UInt_t          event;
   UInt_t          ls;
   UInt_t          run;

   // List of branches
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
   TBranch        *b_HGCEERecHitCorner1Eta;   //!
   TBranch        *b_HGCEERecHitCorner1Phi;   //!
   TBranch        *b_HGCEERecHitCorner2Eta;   //!
   TBranch        *b_HGCEERecHitCorner2Phi;   //!
   TBranch        *b_HGCEERecHitCorner3Eta;   //!
   TBranch        *b_HGCEERecHitCorner3Phi;   //!
   TBranch        *b_HGCEERecHitCorner4Eta;   //!
   TBranch        *b_HGCEERecHitCorner4Phi;   //!
   TBranch        *b_HGCEERecHitEnergy;   //!
   TBranch        *b_HGCEERecHitEta;   //!
   TBranch        *b_HGCEERecHitPhi;   //!
   TBranch        *b_HGCEERecHitR;   //!
   TBranch        *b_HGCEERecHitTime;   //!
   TBranch        *b_HGCEERecHitX;   //!
   TBranch        *b_HGCEERecHitY;   //!
   TBranch        *b_HGCEERecHitZ;   //!
   TBranch        *b_HGCHEBRecHitCorner1Eta;   //!
   TBranch        *b_HGCHEBRecHitCorner1Phi;   //!
   TBranch        *b_HGCHEBRecHitCorner2Eta;   //!
   TBranch        *b_HGCHEBRecHitCorner2Phi;   //!
   TBranch        *b_HGCHEBRecHitCorner3Eta;   //!
   TBranch        *b_HGCHEBRecHitCorner3Phi;   //!
   TBranch        *b_HGCHEBRecHitCorner4Eta;   //!
   TBranch        *b_HGCHEBRecHitCorner4Phi;   //!
   TBranch        *b_HGCHEBRecHitEnergy;   //!
   TBranch        *b_HGCHEBRecHitEta;   //!
   TBranch        *b_HGCHEBRecHitPhi;   //!
   TBranch        *b_HGCHEBRecHitR;   //!
   TBranch        *b_HGCHEBRecHitTime;   //!
   TBranch        *b_HGCHEBRecHitX;   //!
   TBranch        *b_HGCHEBRecHitY;   //!
   TBranch        *b_HGCHEBRecHitZ;   //!
   TBranch        *b_HGCHEFRecHitCorner1Eta;   //!
   TBranch        *b_HGCHEFRecHitCorner1Phi;   //!
   TBranch        *b_HGCHEFRecHitCorner2Eta;   //!
   TBranch        *b_HGCHEFRecHitCorner2Phi;   //!
   TBranch        *b_HGCHEFRecHitCorner3Eta;   //!
   TBranch        *b_HGCHEFRecHitCorner3Phi;   //!
   TBranch        *b_HGCHEFRecHitCorner4Eta;   //!
   TBranch        *b_HGCHEFRecHitCorner4Phi;   //!
   TBranch        *b_HGCHEFRecHitEnergy;   //!
   TBranch        *b_HGCHEFRecHitEta;   //!
   TBranch        *b_HGCHEFRecHitPhi;   //!
   TBranch        *b_HGCHEFRecHitR;   //!
   TBranch        *b_HGCHEFRecHitTime;   //!
   TBranch        *b_HGCHEFRecHitX;   //!
   TBranch        *b_HGCHEFRecHitY;   //!
   TBranch        *b_HGCHEFRecHitZ;   //!
   TBranch        *b_PFCA4JetEnergy;   //!
   TBranch        *b_PFCA4JetEta;   //!
   TBranch        *b_PFCA4JetMass;   //!
   TBranch        *b_PFCA4JetNSubJ;   //!
   TBranch        *b_PFCA4JetP;   //!
   TBranch        *b_PFCA4JetPhi;   //!
   TBranch        *b_PFCA4JetPt;   //!
   TBranch        *b_PFCA4JetTau1;   //!
   TBranch        *b_PFCA4JetTau2;   //!
   TBranch        *b_PFCA4JetTau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut001MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut001NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut001P;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut001Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut003MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut003NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut003P;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut003Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut005MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut005NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut005P;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut005Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut008MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut008NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut008P;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut008Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut01MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut01NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut01P;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut01Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut02MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut02NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut02P;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut02Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut03MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut03NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut03P;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut03Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut04MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut04NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut04P;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut04Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut05MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut05NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut05P;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut05Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut1MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut1NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut1P;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut1Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut2MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut2NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut2P;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut2Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut3MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut3NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut3P;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut3Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut4MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut4NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut4P;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut4Tau3;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Energy;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Eta;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Mass;   //!
   TBranch        *b_PFCA4PrunedJetRCut5MassDrop;   //!
   TBranch        *b_PFCA4PrunedJetRCut5NSubJ;   //!
   TBranch        *b_PFCA4PrunedJetRCut5P;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Phi;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Pt;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Tau1;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Tau2;   //!
   TBranch        *b_PFCA4PrunedJetRCut5Tau3;   //!
   TBranch        *b_PFCandEta;   //!
   TBranch        *b_PFCandPhi;   //!
   TBranch        *b_PFCandPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut001DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut001DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut001DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut001DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut003DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut003DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut003DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut003DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut005DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut005DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut005DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut005DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut008DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut008DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut008DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut008DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut01DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut01DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut01DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut01DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut02DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut02DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut02DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut02DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut03DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut03DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut03DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut03DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut04DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut04DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut04DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut04DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut05DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut05DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut05DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut05DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut1DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut1DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut1DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut1DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut2DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut2DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut2DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut2DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut3DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut3DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut3DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut3DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut4DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut4DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut4DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut4DaughterPt;   //!
   TBranch        *b_PFCA4PrunedJetRCut5DaughterEta;   //!
   TBranch        *b_PFCA4PrunedJetRCut5DaughterMass;   //!
   TBranch        *b_PFCA4PrunedJetRCut5DaughterPhi;   //!
   TBranch        *b_PFCA4PrunedJetRCut5DaughterPt;   //!
   TBranch        *b_PFCandHGCEERecHitFraction;   //!
   TBranch        *b_PFCandHGCHEBRecHitFraction;   //!
   TBranch        *b_PFCandHGCHEFRecHitFraction;   //!
   TBranch        *b_GenParticleHasPartonDaughter;   //!
   TBranch        *b_GenParticleMother1Index;   //!
   TBranch        *b_GenParticleMother2Index;   //!
   TBranch        *b_GenParticleNumDaught;   //!
   TBranch        *b_GenParticleNumDaught3;   //!
   TBranch        *b_GenParticleNumMother;   //!
   TBranch        *b_GenParticlePdgId;   //!
   TBranch        *b_GenParticleStatus;   //!
   TBranch        *b_HGCEERecHitCell;   //!
   TBranch        *b_HGCEERecHitLayer;   //!
   TBranch        *b_HGCEERecHitSector;   //!
   TBranch        *b_HGCEERecHitSubSector;   //!
   TBranch        *b_HGCEERecHitSubdet;   //!
   TBranch        *b_HGCHEBRecHitCell;   //!
   TBranch        *b_HGCHEBRecHitLayer;   //!
   TBranch        *b_HGCHEBRecHitSector;   //!
   TBranch        *b_HGCHEBRecHitSubSector;   //!
   TBranch        *b_HGCHEBRecHitSubdet;   //!
   TBranch        *b_HGCHEFRecHitCell;   //!
   TBranch        *b_HGCHEFRecHitLayer;   //!
   TBranch        *b_HGCHEFRecHitSector;   //!
   TBranch        *b_HGCHEFRecHitSubSector;   //!
   TBranch        *b_HGCHEFRecHitSubdet;   //!
   TBranch        *b_PFCA4PrunedJetRCut001NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut003NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut005NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut008NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut01NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut02NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut03NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut04NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut05NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut1NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut2NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut3NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut4NDaughters;   //!
   TBranch        *b_PFCA4PrunedJetRCut5NDaughters;   //!
   TBranch        *b_PFCandId;   //!
   TBranch        *b_PFCA4JetPFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut001PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut003PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut005PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut008PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut01PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut02PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut03PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut04PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut05PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut1PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut2PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut3PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut4PFCandIndices;   //!
   TBranch        *b_PFCA4PrunedJetRCut5PFCandIndices;   //!
   TBranch        *b_PFCandHGCEERecHitIndex;   //!
   TBranch        *b_PFCandHGCHEBRecHitIndex;   //!
   TBranch        *b_PFCandHGCHEFRecHitIndex;   //!
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/HGCAL_QQH_output.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("data/HGCAL_QQH_output.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("data/HGCAL_QQH_output.root:/hgcalTupleTree");
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
   HGCEERecHitCorner1Eta = 0;
   HGCEERecHitCorner1Phi = 0;
   HGCEERecHitCorner2Eta = 0;
   HGCEERecHitCorner2Phi = 0;
   HGCEERecHitCorner3Eta = 0;
   HGCEERecHitCorner3Phi = 0;
   HGCEERecHitCorner4Eta = 0;
   HGCEERecHitCorner4Phi = 0;
   HGCEERecHitEnergy = 0;
   HGCEERecHitEta = 0;
   HGCEERecHitPhi = 0;
   HGCEERecHitR = 0;
   HGCEERecHitTime = 0;
   HGCEERecHitX = 0;
   HGCEERecHitY = 0;
   HGCEERecHitZ = 0;
   HGCHEBRecHitCorner1Eta = 0;
   HGCHEBRecHitCorner1Phi = 0;
   HGCHEBRecHitCorner2Eta = 0;
   HGCHEBRecHitCorner2Phi = 0;
   HGCHEBRecHitCorner3Eta = 0;
   HGCHEBRecHitCorner3Phi = 0;
   HGCHEBRecHitCorner4Eta = 0;
   HGCHEBRecHitCorner4Phi = 0;
   HGCHEBRecHitEnergy = 0;
   HGCHEBRecHitEta = 0;
   HGCHEBRecHitPhi = 0;
   HGCHEBRecHitR = 0;
   HGCHEBRecHitTime = 0;
   HGCHEBRecHitX = 0;
   HGCHEBRecHitY = 0;
   HGCHEBRecHitZ = 0;
   HGCHEFRecHitCorner1Eta = 0;
   HGCHEFRecHitCorner1Phi = 0;
   HGCHEFRecHitCorner2Eta = 0;
   HGCHEFRecHitCorner2Phi = 0;
   HGCHEFRecHitCorner3Eta = 0;
   HGCHEFRecHitCorner3Phi = 0;
   HGCHEFRecHitCorner4Eta = 0;
   HGCHEFRecHitCorner4Phi = 0;
   HGCHEFRecHitEnergy = 0;
   HGCHEFRecHitEta = 0;
   HGCHEFRecHitPhi = 0;
   HGCHEFRecHitR = 0;
   HGCHEFRecHitTime = 0;
   HGCHEFRecHitX = 0;
   HGCHEFRecHitY = 0;
   HGCHEFRecHitZ = 0;
   PFCA4JetEnergy = 0;
   PFCA4JetEta = 0;
   PFCA4JetMass = 0;
   PFCA4JetNSubJ = 0;
   PFCA4JetP = 0;
   PFCA4JetPhi = 0;
   PFCA4JetPt = 0;
   PFCA4JetTau1 = 0;
   PFCA4JetTau2 = 0;
   PFCA4JetTau3 = 0;
   PFCA4PrunedJetRCut001Energy = 0;
   PFCA4PrunedJetRCut001Eta = 0;
   PFCA4PrunedJetRCut001Mass = 0;
   PFCA4PrunedJetRCut001MassDrop = 0;
   PFCA4PrunedJetRCut001NSubJ = 0;
   PFCA4PrunedJetRCut001P = 0;
   PFCA4PrunedJetRCut001Phi = 0;
   PFCA4PrunedJetRCut001Pt = 0;
   PFCA4PrunedJetRCut001Tau1 = 0;
   PFCA4PrunedJetRCut001Tau2 = 0;
   PFCA4PrunedJetRCut001Tau3 = 0;
   PFCA4PrunedJetRCut003Energy = 0;
   PFCA4PrunedJetRCut003Eta = 0;
   PFCA4PrunedJetRCut003Mass = 0;
   PFCA4PrunedJetRCut003MassDrop = 0;
   PFCA4PrunedJetRCut003NSubJ = 0;
   PFCA4PrunedJetRCut003P = 0;
   PFCA4PrunedJetRCut003Phi = 0;
   PFCA4PrunedJetRCut003Pt = 0;
   PFCA4PrunedJetRCut003Tau1 = 0;
   PFCA4PrunedJetRCut003Tau2 = 0;
   PFCA4PrunedJetRCut003Tau3 = 0;
   PFCA4PrunedJetRCut005Energy = 0;
   PFCA4PrunedJetRCut005Eta = 0;
   PFCA4PrunedJetRCut005Mass = 0;
   PFCA4PrunedJetRCut005MassDrop = 0;
   PFCA4PrunedJetRCut005NSubJ = 0;
   PFCA4PrunedJetRCut005P = 0;
   PFCA4PrunedJetRCut005Phi = 0;
   PFCA4PrunedJetRCut005Pt = 0;
   PFCA4PrunedJetRCut005Tau1 = 0;
   PFCA4PrunedJetRCut005Tau2 = 0;
   PFCA4PrunedJetRCut005Tau3 = 0;
   PFCA4PrunedJetRCut008Energy = 0;
   PFCA4PrunedJetRCut008Eta = 0;
   PFCA4PrunedJetRCut008Mass = 0;
   PFCA4PrunedJetRCut008MassDrop = 0;
   PFCA4PrunedJetRCut008NSubJ = 0;
   PFCA4PrunedJetRCut008P = 0;
   PFCA4PrunedJetRCut008Phi = 0;
   PFCA4PrunedJetRCut008Pt = 0;
   PFCA4PrunedJetRCut008Tau1 = 0;
   PFCA4PrunedJetRCut008Tau2 = 0;
   PFCA4PrunedJetRCut008Tau3 = 0;
   PFCA4PrunedJetRCut01Energy = 0;
   PFCA4PrunedJetRCut01Eta = 0;
   PFCA4PrunedJetRCut01Mass = 0;
   PFCA4PrunedJetRCut01MassDrop = 0;
   PFCA4PrunedJetRCut01NSubJ = 0;
   PFCA4PrunedJetRCut01P = 0;
   PFCA4PrunedJetRCut01Phi = 0;
   PFCA4PrunedJetRCut01Pt = 0;
   PFCA4PrunedJetRCut01Tau1 = 0;
   PFCA4PrunedJetRCut01Tau2 = 0;
   PFCA4PrunedJetRCut01Tau3 = 0;
   PFCA4PrunedJetRCut02Energy = 0;
   PFCA4PrunedJetRCut02Eta = 0;
   PFCA4PrunedJetRCut02Mass = 0;
   PFCA4PrunedJetRCut02MassDrop = 0;
   PFCA4PrunedJetRCut02NSubJ = 0;
   PFCA4PrunedJetRCut02P = 0;
   PFCA4PrunedJetRCut02Phi = 0;
   PFCA4PrunedJetRCut02Pt = 0;
   PFCA4PrunedJetRCut02Tau1 = 0;
   PFCA4PrunedJetRCut02Tau2 = 0;
   PFCA4PrunedJetRCut02Tau3 = 0;
   PFCA4PrunedJetRCut03Energy = 0;
   PFCA4PrunedJetRCut03Eta = 0;
   PFCA4PrunedJetRCut03Mass = 0;
   PFCA4PrunedJetRCut03MassDrop = 0;
   PFCA4PrunedJetRCut03NSubJ = 0;
   PFCA4PrunedJetRCut03P = 0;
   PFCA4PrunedJetRCut03Phi = 0;
   PFCA4PrunedJetRCut03Pt = 0;
   PFCA4PrunedJetRCut03Tau1 = 0;
   PFCA4PrunedJetRCut03Tau2 = 0;
   PFCA4PrunedJetRCut03Tau3 = 0;
   PFCA4PrunedJetRCut04Energy = 0;
   PFCA4PrunedJetRCut04Eta = 0;
   PFCA4PrunedJetRCut04Mass = 0;
   PFCA4PrunedJetRCut04MassDrop = 0;
   PFCA4PrunedJetRCut04NSubJ = 0;
   PFCA4PrunedJetRCut04P = 0;
   PFCA4PrunedJetRCut04Phi = 0;
   PFCA4PrunedJetRCut04Pt = 0;
   PFCA4PrunedJetRCut04Tau1 = 0;
   PFCA4PrunedJetRCut04Tau2 = 0;
   PFCA4PrunedJetRCut04Tau3 = 0;
   PFCA4PrunedJetRCut05Energy = 0;
   PFCA4PrunedJetRCut05Eta = 0;
   PFCA4PrunedJetRCut05Mass = 0;
   PFCA4PrunedJetRCut05MassDrop = 0;
   PFCA4PrunedJetRCut05NSubJ = 0;
   PFCA4PrunedJetRCut05P = 0;
   PFCA4PrunedJetRCut05Phi = 0;
   PFCA4PrunedJetRCut05Pt = 0;
   PFCA4PrunedJetRCut05Tau1 = 0;
   PFCA4PrunedJetRCut05Tau2 = 0;
   PFCA4PrunedJetRCut05Tau3 = 0;
   PFCA4PrunedJetRCut1Energy = 0;
   PFCA4PrunedJetRCut1Eta = 0;
   PFCA4PrunedJetRCut1Mass = 0;
   PFCA4PrunedJetRCut1MassDrop = 0;
   PFCA4PrunedJetRCut1NSubJ = 0;
   PFCA4PrunedJetRCut1P = 0;
   PFCA4PrunedJetRCut1Phi = 0;
   PFCA4PrunedJetRCut1Pt = 0;
   PFCA4PrunedJetRCut1Tau1 = 0;
   PFCA4PrunedJetRCut1Tau2 = 0;
   PFCA4PrunedJetRCut1Tau3 = 0;
   PFCA4PrunedJetRCut2Energy = 0;
   PFCA4PrunedJetRCut2Eta = 0;
   PFCA4PrunedJetRCut2Mass = 0;
   PFCA4PrunedJetRCut2MassDrop = 0;
   PFCA4PrunedJetRCut2NSubJ = 0;
   PFCA4PrunedJetRCut2P = 0;
   PFCA4PrunedJetRCut2Phi = 0;
   PFCA4PrunedJetRCut2Pt = 0;
   PFCA4PrunedJetRCut2Tau1 = 0;
   PFCA4PrunedJetRCut2Tau2 = 0;
   PFCA4PrunedJetRCut2Tau3 = 0;
   PFCA4PrunedJetRCut3Energy = 0;
   PFCA4PrunedJetRCut3Eta = 0;
   PFCA4PrunedJetRCut3Mass = 0;
   PFCA4PrunedJetRCut3MassDrop = 0;
   PFCA4PrunedJetRCut3NSubJ = 0;
   PFCA4PrunedJetRCut3P = 0;
   PFCA4PrunedJetRCut3Phi = 0;
   PFCA4PrunedJetRCut3Pt = 0;
   PFCA4PrunedJetRCut3Tau1 = 0;
   PFCA4PrunedJetRCut3Tau2 = 0;
   PFCA4PrunedJetRCut3Tau3 = 0;
   PFCA4PrunedJetRCut4Energy = 0;
   PFCA4PrunedJetRCut4Eta = 0;
   PFCA4PrunedJetRCut4Mass = 0;
   PFCA4PrunedJetRCut4MassDrop = 0;
   PFCA4PrunedJetRCut4NSubJ = 0;
   PFCA4PrunedJetRCut4P = 0;
   PFCA4PrunedJetRCut4Phi = 0;
   PFCA4PrunedJetRCut4Pt = 0;
   PFCA4PrunedJetRCut4Tau1 = 0;
   PFCA4PrunedJetRCut4Tau2 = 0;
   PFCA4PrunedJetRCut4Tau3 = 0;
   PFCA4PrunedJetRCut5Energy = 0;
   PFCA4PrunedJetRCut5Eta = 0;
   PFCA4PrunedJetRCut5Mass = 0;
   PFCA4PrunedJetRCut5MassDrop = 0;
   PFCA4PrunedJetRCut5NSubJ = 0;
   PFCA4PrunedJetRCut5P = 0;
   PFCA4PrunedJetRCut5Phi = 0;
   PFCA4PrunedJetRCut5Pt = 0;
   PFCA4PrunedJetRCut5Tau1 = 0;
   PFCA4PrunedJetRCut5Tau2 = 0;
   PFCA4PrunedJetRCut5Tau3 = 0;
   PFCandEta = 0;
   PFCandPhi = 0;
   PFCandPt = 0;
   PFCA4PrunedJetRCut001DaughterEta = 0;
   PFCA4PrunedJetRCut001DaughterMass = 0;
   PFCA4PrunedJetRCut001DaughterPhi = 0;
   PFCA4PrunedJetRCut001DaughterPt = 0;
   PFCA4PrunedJetRCut003DaughterEta = 0;
   PFCA4PrunedJetRCut003DaughterMass = 0;
   PFCA4PrunedJetRCut003DaughterPhi = 0;
   PFCA4PrunedJetRCut003DaughterPt = 0;
   PFCA4PrunedJetRCut005DaughterEta = 0;
   PFCA4PrunedJetRCut005DaughterMass = 0;
   PFCA4PrunedJetRCut005DaughterPhi = 0;
   PFCA4PrunedJetRCut005DaughterPt = 0;
   PFCA4PrunedJetRCut008DaughterEta = 0;
   PFCA4PrunedJetRCut008DaughterMass = 0;
   PFCA4PrunedJetRCut008DaughterPhi = 0;
   PFCA4PrunedJetRCut008DaughterPt = 0;
   PFCA4PrunedJetRCut01DaughterEta = 0;
   PFCA4PrunedJetRCut01DaughterMass = 0;
   PFCA4PrunedJetRCut01DaughterPhi = 0;
   PFCA4PrunedJetRCut01DaughterPt = 0;
   PFCA4PrunedJetRCut02DaughterEta = 0;
   PFCA4PrunedJetRCut02DaughterMass = 0;
   PFCA4PrunedJetRCut02DaughterPhi = 0;
   PFCA4PrunedJetRCut02DaughterPt = 0;
   PFCA4PrunedJetRCut03DaughterEta = 0;
   PFCA4PrunedJetRCut03DaughterMass = 0;
   PFCA4PrunedJetRCut03DaughterPhi = 0;
   PFCA4PrunedJetRCut03DaughterPt = 0;
   PFCA4PrunedJetRCut04DaughterEta = 0;
   PFCA4PrunedJetRCut04DaughterMass = 0;
   PFCA4PrunedJetRCut04DaughterPhi = 0;
   PFCA4PrunedJetRCut04DaughterPt = 0;
   PFCA4PrunedJetRCut05DaughterEta = 0;
   PFCA4PrunedJetRCut05DaughterMass = 0;
   PFCA4PrunedJetRCut05DaughterPhi = 0;
   PFCA4PrunedJetRCut05DaughterPt = 0;
   PFCA4PrunedJetRCut1DaughterEta = 0;
   PFCA4PrunedJetRCut1DaughterMass = 0;
   PFCA4PrunedJetRCut1DaughterPhi = 0;
   PFCA4PrunedJetRCut1DaughterPt = 0;
   PFCA4PrunedJetRCut2DaughterEta = 0;
   PFCA4PrunedJetRCut2DaughterMass = 0;
   PFCA4PrunedJetRCut2DaughterPhi = 0;
   PFCA4PrunedJetRCut2DaughterPt = 0;
   PFCA4PrunedJetRCut3DaughterEta = 0;
   PFCA4PrunedJetRCut3DaughterMass = 0;
   PFCA4PrunedJetRCut3DaughterPhi = 0;
   PFCA4PrunedJetRCut3DaughterPt = 0;
   PFCA4PrunedJetRCut4DaughterEta = 0;
   PFCA4PrunedJetRCut4DaughterMass = 0;
   PFCA4PrunedJetRCut4DaughterPhi = 0;
   PFCA4PrunedJetRCut4DaughterPt = 0;
   PFCA4PrunedJetRCut5DaughterEta = 0;
   PFCA4PrunedJetRCut5DaughterMass = 0;
   PFCA4PrunedJetRCut5DaughterPhi = 0;
   PFCA4PrunedJetRCut5DaughterPt = 0;
   PFCandHGCEERecHitFraction = 0;
   PFCandHGCHEBRecHitFraction = 0;
   PFCandHGCHEFRecHitFraction = 0;
   GenParticleHasPartonDaughter = 0;
   GenParticleMother1Index = 0;
   GenParticleMother2Index = 0;
   GenParticleNumDaught = 0;
   GenParticleNumDaught3 = 0;
   GenParticleNumMother = 0;
   GenParticlePdgId = 0;
   GenParticleStatus = 0;
   HGCEERecHitCell = 0;
   HGCEERecHitLayer = 0;
   HGCEERecHitSector = 0;
   HGCEERecHitSubSector = 0;
   HGCEERecHitSubdet = 0;
   HGCHEBRecHitCell = 0;
   HGCHEBRecHitLayer = 0;
   HGCHEBRecHitSector = 0;
   HGCHEBRecHitSubSector = 0;
   HGCHEBRecHitSubdet = 0;
   HGCHEFRecHitCell = 0;
   HGCHEFRecHitLayer = 0;
   HGCHEFRecHitSector = 0;
   HGCHEFRecHitSubSector = 0;
   HGCHEFRecHitSubdet = 0;
   PFCA4PrunedJetRCut001NDaughters = 0;
   PFCA4PrunedJetRCut003NDaughters = 0;
   PFCA4PrunedJetRCut005NDaughters = 0;
   PFCA4PrunedJetRCut008NDaughters = 0;
   PFCA4PrunedJetRCut01NDaughters = 0;
   PFCA4PrunedJetRCut02NDaughters = 0;
   PFCA4PrunedJetRCut03NDaughters = 0;
   PFCA4PrunedJetRCut04NDaughters = 0;
   PFCA4PrunedJetRCut05NDaughters = 0;
   PFCA4PrunedJetRCut1NDaughters = 0;
   PFCA4PrunedJetRCut2NDaughters = 0;
   PFCA4PrunedJetRCut3NDaughters = 0;
   PFCA4PrunedJetRCut4NDaughters = 0;
   PFCA4PrunedJetRCut5NDaughters = 0;
   PFCandId = 0;
   PFCA4JetPFCandIndices = 0;
   PFCA4PrunedJetRCut001PFCandIndices = 0;
   PFCA4PrunedJetRCut003PFCandIndices = 0;
   PFCA4PrunedJetRCut005PFCandIndices = 0;
   PFCA4PrunedJetRCut008PFCandIndices = 0;
   PFCA4PrunedJetRCut01PFCandIndices = 0;
   PFCA4PrunedJetRCut02PFCandIndices = 0;
   PFCA4PrunedJetRCut03PFCandIndices = 0;
   PFCA4PrunedJetRCut04PFCandIndices = 0;
   PFCA4PrunedJetRCut05PFCandIndices = 0;
   PFCA4PrunedJetRCut1PFCandIndices = 0;
   PFCA4PrunedJetRCut2PFCandIndices = 0;
   PFCA4PrunedJetRCut3PFCandIndices = 0;
   PFCA4PrunedJetRCut4PFCandIndices = 0;
   PFCA4PrunedJetRCut5PFCandIndices = 0;
   PFCandHGCEERecHitIndex = 0;
   PFCandHGCHEBRecHitIndex = 0;
   PFCandHGCHEFRecHitIndex = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

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
   fChain->SetBranchAddress("HGCEERecHitCorner1Eta", &HGCEERecHitCorner1Eta, &b_HGCEERecHitCorner1Eta);
   fChain->SetBranchAddress("HGCEERecHitCorner1Phi", &HGCEERecHitCorner1Phi, &b_HGCEERecHitCorner1Phi);
   fChain->SetBranchAddress("HGCEERecHitCorner2Eta", &HGCEERecHitCorner2Eta, &b_HGCEERecHitCorner2Eta);
   fChain->SetBranchAddress("HGCEERecHitCorner2Phi", &HGCEERecHitCorner2Phi, &b_HGCEERecHitCorner2Phi);
   fChain->SetBranchAddress("HGCEERecHitCorner3Eta", &HGCEERecHitCorner3Eta, &b_HGCEERecHitCorner3Eta);
   fChain->SetBranchAddress("HGCEERecHitCorner3Phi", &HGCEERecHitCorner3Phi, &b_HGCEERecHitCorner3Phi);
   fChain->SetBranchAddress("HGCEERecHitCorner4Eta", &HGCEERecHitCorner4Eta, &b_HGCEERecHitCorner4Eta);
   fChain->SetBranchAddress("HGCEERecHitCorner4Phi", &HGCEERecHitCorner4Phi, &b_HGCEERecHitCorner4Phi);
   fChain->SetBranchAddress("HGCEERecHitEnergy", &HGCEERecHitEnergy, &b_HGCEERecHitEnergy);
   fChain->SetBranchAddress("HGCEERecHitEta", &HGCEERecHitEta, &b_HGCEERecHitEta);
   fChain->SetBranchAddress("HGCEERecHitPhi", &HGCEERecHitPhi, &b_HGCEERecHitPhi);
   fChain->SetBranchAddress("HGCEERecHitR", &HGCEERecHitR, &b_HGCEERecHitR);
   fChain->SetBranchAddress("HGCEERecHitTime", &HGCEERecHitTime, &b_HGCEERecHitTime);
   fChain->SetBranchAddress("HGCEERecHitX", &HGCEERecHitX, &b_HGCEERecHitX);
   fChain->SetBranchAddress("HGCEERecHitY", &HGCEERecHitY, &b_HGCEERecHitY);
   fChain->SetBranchAddress("HGCEERecHitZ", &HGCEERecHitZ, &b_HGCEERecHitZ);
   fChain->SetBranchAddress("HGCHEBRecHitCorner1Eta", &HGCHEBRecHitCorner1Eta, &b_HGCHEBRecHitCorner1Eta);
   fChain->SetBranchAddress("HGCHEBRecHitCorner1Phi", &HGCHEBRecHitCorner1Phi, &b_HGCHEBRecHitCorner1Phi);
   fChain->SetBranchAddress("HGCHEBRecHitCorner2Eta", &HGCHEBRecHitCorner2Eta, &b_HGCHEBRecHitCorner2Eta);
   fChain->SetBranchAddress("HGCHEBRecHitCorner2Phi", &HGCHEBRecHitCorner2Phi, &b_HGCHEBRecHitCorner2Phi);
   fChain->SetBranchAddress("HGCHEBRecHitCorner3Eta", &HGCHEBRecHitCorner3Eta, &b_HGCHEBRecHitCorner3Eta);
   fChain->SetBranchAddress("HGCHEBRecHitCorner3Phi", &HGCHEBRecHitCorner3Phi, &b_HGCHEBRecHitCorner3Phi);
   fChain->SetBranchAddress("HGCHEBRecHitCorner4Eta", &HGCHEBRecHitCorner4Eta, &b_HGCHEBRecHitCorner4Eta);
   fChain->SetBranchAddress("HGCHEBRecHitCorner4Phi", &HGCHEBRecHitCorner4Phi, &b_HGCHEBRecHitCorner4Phi);
   fChain->SetBranchAddress("HGCHEBRecHitEnergy", &HGCHEBRecHitEnergy, &b_HGCHEBRecHitEnergy);
   fChain->SetBranchAddress("HGCHEBRecHitEta", &HGCHEBRecHitEta, &b_HGCHEBRecHitEta);
   fChain->SetBranchAddress("HGCHEBRecHitPhi", &HGCHEBRecHitPhi, &b_HGCHEBRecHitPhi);
   fChain->SetBranchAddress("HGCHEBRecHitR", &HGCHEBRecHitR, &b_HGCHEBRecHitR);
   fChain->SetBranchAddress("HGCHEBRecHitTime", &HGCHEBRecHitTime, &b_HGCHEBRecHitTime);
   fChain->SetBranchAddress("HGCHEBRecHitX", &HGCHEBRecHitX, &b_HGCHEBRecHitX);
   fChain->SetBranchAddress("HGCHEBRecHitY", &HGCHEBRecHitY, &b_HGCHEBRecHitY);
   fChain->SetBranchAddress("HGCHEBRecHitZ", &HGCHEBRecHitZ, &b_HGCHEBRecHitZ);
   fChain->SetBranchAddress("HGCHEFRecHitCorner1Eta", &HGCHEFRecHitCorner1Eta, &b_HGCHEFRecHitCorner1Eta);
   fChain->SetBranchAddress("HGCHEFRecHitCorner1Phi", &HGCHEFRecHitCorner1Phi, &b_HGCHEFRecHitCorner1Phi);
   fChain->SetBranchAddress("HGCHEFRecHitCorner2Eta", &HGCHEFRecHitCorner2Eta, &b_HGCHEFRecHitCorner2Eta);
   fChain->SetBranchAddress("HGCHEFRecHitCorner2Phi", &HGCHEFRecHitCorner2Phi, &b_HGCHEFRecHitCorner2Phi);
   fChain->SetBranchAddress("HGCHEFRecHitCorner3Eta", &HGCHEFRecHitCorner3Eta, &b_HGCHEFRecHitCorner3Eta);
   fChain->SetBranchAddress("HGCHEFRecHitCorner3Phi", &HGCHEFRecHitCorner3Phi, &b_HGCHEFRecHitCorner3Phi);
   fChain->SetBranchAddress("HGCHEFRecHitCorner4Eta", &HGCHEFRecHitCorner4Eta, &b_HGCHEFRecHitCorner4Eta);
   fChain->SetBranchAddress("HGCHEFRecHitCorner4Phi", &HGCHEFRecHitCorner4Phi, &b_HGCHEFRecHitCorner4Phi);
   fChain->SetBranchAddress("HGCHEFRecHitEnergy", &HGCHEFRecHitEnergy, &b_HGCHEFRecHitEnergy);
   fChain->SetBranchAddress("HGCHEFRecHitEta", &HGCHEFRecHitEta, &b_HGCHEFRecHitEta);
   fChain->SetBranchAddress("HGCHEFRecHitPhi", &HGCHEFRecHitPhi, &b_HGCHEFRecHitPhi);
   fChain->SetBranchAddress("HGCHEFRecHitR", &HGCHEFRecHitR, &b_HGCHEFRecHitR);
   fChain->SetBranchAddress("HGCHEFRecHitTime", &HGCHEFRecHitTime, &b_HGCHEFRecHitTime);
   fChain->SetBranchAddress("HGCHEFRecHitX", &HGCHEFRecHitX, &b_HGCHEFRecHitX);
   fChain->SetBranchAddress("HGCHEFRecHitY", &HGCHEFRecHitY, &b_HGCHEFRecHitY);
   fChain->SetBranchAddress("HGCHEFRecHitZ", &HGCHEFRecHitZ, &b_HGCHEFRecHitZ);
   fChain->SetBranchAddress("PFCA4JetEnergy", &PFCA4JetEnergy, &b_PFCA4JetEnergy);
   fChain->SetBranchAddress("PFCA4JetEta", &PFCA4JetEta, &b_PFCA4JetEta);
   fChain->SetBranchAddress("PFCA4JetMass", &PFCA4JetMass, &b_PFCA4JetMass);
   fChain->SetBranchAddress("PFCA4JetNSubJ", &PFCA4JetNSubJ, &b_PFCA4JetNSubJ);
   fChain->SetBranchAddress("PFCA4JetP", &PFCA4JetP, &b_PFCA4JetP);
   fChain->SetBranchAddress("PFCA4JetPhi", &PFCA4JetPhi, &b_PFCA4JetPhi);
   fChain->SetBranchAddress("PFCA4JetPt", &PFCA4JetPt, &b_PFCA4JetPt);
   fChain->SetBranchAddress("PFCA4JetTau1", &PFCA4JetTau1, &b_PFCA4JetTau1);
   fChain->SetBranchAddress("PFCA4JetTau2", &PFCA4JetTau2, &b_PFCA4JetTau2);
   fChain->SetBranchAddress("PFCA4JetTau3", &PFCA4JetTau3, &b_PFCA4JetTau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Energy", &PFCA4PrunedJetRCut001Energy, &b_PFCA4PrunedJetRCut001Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Eta", &PFCA4PrunedJetRCut001Eta, &b_PFCA4PrunedJetRCut001Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Mass", &PFCA4PrunedJetRCut001Mass, &b_PFCA4PrunedJetRCut001Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001MassDrop", &PFCA4PrunedJetRCut001MassDrop, &b_PFCA4PrunedJetRCut001MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001NSubJ", &PFCA4PrunedJetRCut001NSubJ, &b_PFCA4PrunedJetRCut001NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001P", &PFCA4PrunedJetRCut001P, &b_PFCA4PrunedJetRCut001P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Phi", &PFCA4PrunedJetRCut001Phi, &b_PFCA4PrunedJetRCut001Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Pt", &PFCA4PrunedJetRCut001Pt, &b_PFCA4PrunedJetRCut001Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Tau1", &PFCA4PrunedJetRCut001Tau1, &b_PFCA4PrunedJetRCut001Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Tau2", &PFCA4PrunedJetRCut001Tau2, &b_PFCA4PrunedJetRCut001Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001Tau3", &PFCA4PrunedJetRCut001Tau3, &b_PFCA4PrunedJetRCut001Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Energy", &PFCA4PrunedJetRCut003Energy, &b_PFCA4PrunedJetRCut003Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Eta", &PFCA4PrunedJetRCut003Eta, &b_PFCA4PrunedJetRCut003Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Mass", &PFCA4PrunedJetRCut003Mass, &b_PFCA4PrunedJetRCut003Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003MassDrop", &PFCA4PrunedJetRCut003MassDrop, &b_PFCA4PrunedJetRCut003MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003NSubJ", &PFCA4PrunedJetRCut003NSubJ, &b_PFCA4PrunedJetRCut003NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003P", &PFCA4PrunedJetRCut003P, &b_PFCA4PrunedJetRCut003P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Phi", &PFCA4PrunedJetRCut003Phi, &b_PFCA4PrunedJetRCut003Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Pt", &PFCA4PrunedJetRCut003Pt, &b_PFCA4PrunedJetRCut003Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Tau1", &PFCA4PrunedJetRCut003Tau1, &b_PFCA4PrunedJetRCut003Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Tau2", &PFCA4PrunedJetRCut003Tau2, &b_PFCA4PrunedJetRCut003Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003Tau3", &PFCA4PrunedJetRCut003Tau3, &b_PFCA4PrunedJetRCut003Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Energy", &PFCA4PrunedJetRCut005Energy, &b_PFCA4PrunedJetRCut005Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Eta", &PFCA4PrunedJetRCut005Eta, &b_PFCA4PrunedJetRCut005Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Mass", &PFCA4PrunedJetRCut005Mass, &b_PFCA4PrunedJetRCut005Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005MassDrop", &PFCA4PrunedJetRCut005MassDrop, &b_PFCA4PrunedJetRCut005MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005NSubJ", &PFCA4PrunedJetRCut005NSubJ, &b_PFCA4PrunedJetRCut005NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005P", &PFCA4PrunedJetRCut005P, &b_PFCA4PrunedJetRCut005P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Phi", &PFCA4PrunedJetRCut005Phi, &b_PFCA4PrunedJetRCut005Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Pt", &PFCA4PrunedJetRCut005Pt, &b_PFCA4PrunedJetRCut005Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Tau1", &PFCA4PrunedJetRCut005Tau1, &b_PFCA4PrunedJetRCut005Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Tau2", &PFCA4PrunedJetRCut005Tau2, &b_PFCA4PrunedJetRCut005Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005Tau3", &PFCA4PrunedJetRCut005Tau3, &b_PFCA4PrunedJetRCut005Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Energy", &PFCA4PrunedJetRCut008Energy, &b_PFCA4PrunedJetRCut008Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Eta", &PFCA4PrunedJetRCut008Eta, &b_PFCA4PrunedJetRCut008Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Mass", &PFCA4PrunedJetRCut008Mass, &b_PFCA4PrunedJetRCut008Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008MassDrop", &PFCA4PrunedJetRCut008MassDrop, &b_PFCA4PrunedJetRCut008MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008NSubJ", &PFCA4PrunedJetRCut008NSubJ, &b_PFCA4PrunedJetRCut008NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008P", &PFCA4PrunedJetRCut008P, &b_PFCA4PrunedJetRCut008P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Phi", &PFCA4PrunedJetRCut008Phi, &b_PFCA4PrunedJetRCut008Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Pt", &PFCA4PrunedJetRCut008Pt, &b_PFCA4PrunedJetRCut008Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Tau1", &PFCA4PrunedJetRCut008Tau1, &b_PFCA4PrunedJetRCut008Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Tau2", &PFCA4PrunedJetRCut008Tau2, &b_PFCA4PrunedJetRCut008Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008Tau3", &PFCA4PrunedJetRCut008Tau3, &b_PFCA4PrunedJetRCut008Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Energy", &PFCA4PrunedJetRCut01Energy, &b_PFCA4PrunedJetRCut01Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Eta", &PFCA4PrunedJetRCut01Eta, &b_PFCA4PrunedJetRCut01Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Mass", &PFCA4PrunedJetRCut01Mass, &b_PFCA4PrunedJetRCut01Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01MassDrop", &PFCA4PrunedJetRCut01MassDrop, &b_PFCA4PrunedJetRCut01MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01NSubJ", &PFCA4PrunedJetRCut01NSubJ, &b_PFCA4PrunedJetRCut01NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01P", &PFCA4PrunedJetRCut01P, &b_PFCA4PrunedJetRCut01P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Phi", &PFCA4PrunedJetRCut01Phi, &b_PFCA4PrunedJetRCut01Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Pt", &PFCA4PrunedJetRCut01Pt, &b_PFCA4PrunedJetRCut01Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Tau1", &PFCA4PrunedJetRCut01Tau1, &b_PFCA4PrunedJetRCut01Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Tau2", &PFCA4PrunedJetRCut01Tau2, &b_PFCA4PrunedJetRCut01Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01Tau3", &PFCA4PrunedJetRCut01Tau3, &b_PFCA4PrunedJetRCut01Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Energy", &PFCA4PrunedJetRCut02Energy, &b_PFCA4PrunedJetRCut02Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Eta", &PFCA4PrunedJetRCut02Eta, &b_PFCA4PrunedJetRCut02Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Mass", &PFCA4PrunedJetRCut02Mass, &b_PFCA4PrunedJetRCut02Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02MassDrop", &PFCA4PrunedJetRCut02MassDrop, &b_PFCA4PrunedJetRCut02MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02NSubJ", &PFCA4PrunedJetRCut02NSubJ, &b_PFCA4PrunedJetRCut02NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02P", &PFCA4PrunedJetRCut02P, &b_PFCA4PrunedJetRCut02P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Phi", &PFCA4PrunedJetRCut02Phi, &b_PFCA4PrunedJetRCut02Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Pt", &PFCA4PrunedJetRCut02Pt, &b_PFCA4PrunedJetRCut02Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Tau1", &PFCA4PrunedJetRCut02Tau1, &b_PFCA4PrunedJetRCut02Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Tau2", &PFCA4PrunedJetRCut02Tau2, &b_PFCA4PrunedJetRCut02Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02Tau3", &PFCA4PrunedJetRCut02Tau3, &b_PFCA4PrunedJetRCut02Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Energy", &PFCA4PrunedJetRCut03Energy, &b_PFCA4PrunedJetRCut03Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Eta", &PFCA4PrunedJetRCut03Eta, &b_PFCA4PrunedJetRCut03Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Mass", &PFCA4PrunedJetRCut03Mass, &b_PFCA4PrunedJetRCut03Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03MassDrop", &PFCA4PrunedJetRCut03MassDrop, &b_PFCA4PrunedJetRCut03MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03NSubJ", &PFCA4PrunedJetRCut03NSubJ, &b_PFCA4PrunedJetRCut03NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03P", &PFCA4PrunedJetRCut03P, &b_PFCA4PrunedJetRCut03P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Phi", &PFCA4PrunedJetRCut03Phi, &b_PFCA4PrunedJetRCut03Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Pt", &PFCA4PrunedJetRCut03Pt, &b_PFCA4PrunedJetRCut03Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Tau1", &PFCA4PrunedJetRCut03Tau1, &b_PFCA4PrunedJetRCut03Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Tau2", &PFCA4PrunedJetRCut03Tau2, &b_PFCA4PrunedJetRCut03Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03Tau3", &PFCA4PrunedJetRCut03Tau3, &b_PFCA4PrunedJetRCut03Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Energy", &PFCA4PrunedJetRCut04Energy, &b_PFCA4PrunedJetRCut04Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Eta", &PFCA4PrunedJetRCut04Eta, &b_PFCA4PrunedJetRCut04Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Mass", &PFCA4PrunedJetRCut04Mass, &b_PFCA4PrunedJetRCut04Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04MassDrop", &PFCA4PrunedJetRCut04MassDrop, &b_PFCA4PrunedJetRCut04MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04NSubJ", &PFCA4PrunedJetRCut04NSubJ, &b_PFCA4PrunedJetRCut04NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04P", &PFCA4PrunedJetRCut04P, &b_PFCA4PrunedJetRCut04P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Phi", &PFCA4PrunedJetRCut04Phi, &b_PFCA4PrunedJetRCut04Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Pt", &PFCA4PrunedJetRCut04Pt, &b_PFCA4PrunedJetRCut04Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Tau1", &PFCA4PrunedJetRCut04Tau1, &b_PFCA4PrunedJetRCut04Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Tau2", &PFCA4PrunedJetRCut04Tau2, &b_PFCA4PrunedJetRCut04Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04Tau3", &PFCA4PrunedJetRCut04Tau3, &b_PFCA4PrunedJetRCut04Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Energy", &PFCA4PrunedJetRCut05Energy, &b_PFCA4PrunedJetRCut05Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Eta", &PFCA4PrunedJetRCut05Eta, &b_PFCA4PrunedJetRCut05Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Mass", &PFCA4PrunedJetRCut05Mass, &b_PFCA4PrunedJetRCut05Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05MassDrop", &PFCA4PrunedJetRCut05MassDrop, &b_PFCA4PrunedJetRCut05MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05NSubJ", &PFCA4PrunedJetRCut05NSubJ, &b_PFCA4PrunedJetRCut05NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05P", &PFCA4PrunedJetRCut05P, &b_PFCA4PrunedJetRCut05P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Phi", &PFCA4PrunedJetRCut05Phi, &b_PFCA4PrunedJetRCut05Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Pt", &PFCA4PrunedJetRCut05Pt, &b_PFCA4PrunedJetRCut05Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Tau1", &PFCA4PrunedJetRCut05Tau1, &b_PFCA4PrunedJetRCut05Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Tau2", &PFCA4PrunedJetRCut05Tau2, &b_PFCA4PrunedJetRCut05Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05Tau3", &PFCA4PrunedJetRCut05Tau3, &b_PFCA4PrunedJetRCut05Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Energy", &PFCA4PrunedJetRCut1Energy, &b_PFCA4PrunedJetRCut1Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Eta", &PFCA4PrunedJetRCut1Eta, &b_PFCA4PrunedJetRCut1Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Mass", &PFCA4PrunedJetRCut1Mass, &b_PFCA4PrunedJetRCut1Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1MassDrop", &PFCA4PrunedJetRCut1MassDrop, &b_PFCA4PrunedJetRCut1MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1NSubJ", &PFCA4PrunedJetRCut1NSubJ, &b_PFCA4PrunedJetRCut1NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1P", &PFCA4PrunedJetRCut1P, &b_PFCA4PrunedJetRCut1P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Phi", &PFCA4PrunedJetRCut1Phi, &b_PFCA4PrunedJetRCut1Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Pt", &PFCA4PrunedJetRCut1Pt, &b_PFCA4PrunedJetRCut1Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Tau1", &PFCA4PrunedJetRCut1Tau1, &b_PFCA4PrunedJetRCut1Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Tau2", &PFCA4PrunedJetRCut1Tau2, &b_PFCA4PrunedJetRCut1Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1Tau3", &PFCA4PrunedJetRCut1Tau3, &b_PFCA4PrunedJetRCut1Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Energy", &PFCA4PrunedJetRCut2Energy, &b_PFCA4PrunedJetRCut2Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Eta", &PFCA4PrunedJetRCut2Eta, &b_PFCA4PrunedJetRCut2Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Mass", &PFCA4PrunedJetRCut2Mass, &b_PFCA4PrunedJetRCut2Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2MassDrop", &PFCA4PrunedJetRCut2MassDrop, &b_PFCA4PrunedJetRCut2MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2NSubJ", &PFCA4PrunedJetRCut2NSubJ, &b_PFCA4PrunedJetRCut2NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2P", &PFCA4PrunedJetRCut2P, &b_PFCA4PrunedJetRCut2P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Phi", &PFCA4PrunedJetRCut2Phi, &b_PFCA4PrunedJetRCut2Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Pt", &PFCA4PrunedJetRCut2Pt, &b_PFCA4PrunedJetRCut2Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Tau1", &PFCA4PrunedJetRCut2Tau1, &b_PFCA4PrunedJetRCut2Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Tau2", &PFCA4PrunedJetRCut2Tau2, &b_PFCA4PrunedJetRCut2Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2Tau3", &PFCA4PrunedJetRCut2Tau3, &b_PFCA4PrunedJetRCut2Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Energy", &PFCA4PrunedJetRCut3Energy, &b_PFCA4PrunedJetRCut3Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Eta", &PFCA4PrunedJetRCut3Eta, &b_PFCA4PrunedJetRCut3Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Mass", &PFCA4PrunedJetRCut3Mass, &b_PFCA4PrunedJetRCut3Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3MassDrop", &PFCA4PrunedJetRCut3MassDrop, &b_PFCA4PrunedJetRCut3MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3NSubJ", &PFCA4PrunedJetRCut3NSubJ, &b_PFCA4PrunedJetRCut3NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3P", &PFCA4PrunedJetRCut3P, &b_PFCA4PrunedJetRCut3P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Phi", &PFCA4PrunedJetRCut3Phi, &b_PFCA4PrunedJetRCut3Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Pt", &PFCA4PrunedJetRCut3Pt, &b_PFCA4PrunedJetRCut3Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Tau1", &PFCA4PrunedJetRCut3Tau1, &b_PFCA4PrunedJetRCut3Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Tau2", &PFCA4PrunedJetRCut3Tau2, &b_PFCA4PrunedJetRCut3Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3Tau3", &PFCA4PrunedJetRCut3Tau3, &b_PFCA4PrunedJetRCut3Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Energy", &PFCA4PrunedJetRCut4Energy, &b_PFCA4PrunedJetRCut4Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Eta", &PFCA4PrunedJetRCut4Eta, &b_PFCA4PrunedJetRCut4Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Mass", &PFCA4PrunedJetRCut4Mass, &b_PFCA4PrunedJetRCut4Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4MassDrop", &PFCA4PrunedJetRCut4MassDrop, &b_PFCA4PrunedJetRCut4MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4NSubJ", &PFCA4PrunedJetRCut4NSubJ, &b_PFCA4PrunedJetRCut4NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4P", &PFCA4PrunedJetRCut4P, &b_PFCA4PrunedJetRCut4P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Phi", &PFCA4PrunedJetRCut4Phi, &b_PFCA4PrunedJetRCut4Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Pt", &PFCA4PrunedJetRCut4Pt, &b_PFCA4PrunedJetRCut4Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Tau1", &PFCA4PrunedJetRCut4Tau1, &b_PFCA4PrunedJetRCut4Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Tau2", &PFCA4PrunedJetRCut4Tau2, &b_PFCA4PrunedJetRCut4Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4Tau3", &PFCA4PrunedJetRCut4Tau3, &b_PFCA4PrunedJetRCut4Tau3);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Energy", &PFCA4PrunedJetRCut5Energy, &b_PFCA4PrunedJetRCut5Energy);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Eta", &PFCA4PrunedJetRCut5Eta, &b_PFCA4PrunedJetRCut5Eta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Mass", &PFCA4PrunedJetRCut5Mass, &b_PFCA4PrunedJetRCut5Mass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5MassDrop", &PFCA4PrunedJetRCut5MassDrop, &b_PFCA4PrunedJetRCut5MassDrop);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5NSubJ", &PFCA4PrunedJetRCut5NSubJ, &b_PFCA4PrunedJetRCut5NSubJ);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5P", &PFCA4PrunedJetRCut5P, &b_PFCA4PrunedJetRCut5P);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Phi", &PFCA4PrunedJetRCut5Phi, &b_PFCA4PrunedJetRCut5Phi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Pt", &PFCA4PrunedJetRCut5Pt, &b_PFCA4PrunedJetRCut5Pt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Tau1", &PFCA4PrunedJetRCut5Tau1, &b_PFCA4PrunedJetRCut5Tau1);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Tau2", &PFCA4PrunedJetRCut5Tau2, &b_PFCA4PrunedJetRCut5Tau2);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5Tau3", &PFCA4PrunedJetRCut5Tau3, &b_PFCA4PrunedJetRCut5Tau3);
   fChain->SetBranchAddress("PFCandEta", &PFCandEta, &b_PFCandEta);
   fChain->SetBranchAddress("PFCandPhi", &PFCandPhi, &b_PFCandPhi);
   fChain->SetBranchAddress("PFCandPt", &PFCandPt, &b_PFCandPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001DaughterEta", &PFCA4PrunedJetRCut001DaughterEta, &b_PFCA4PrunedJetRCut001DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001DaughterMass", &PFCA4PrunedJetRCut001DaughterMass, &b_PFCA4PrunedJetRCut001DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001DaughterPhi", &PFCA4PrunedJetRCut001DaughterPhi, &b_PFCA4PrunedJetRCut001DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001DaughterPt", &PFCA4PrunedJetRCut001DaughterPt, &b_PFCA4PrunedJetRCut001DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003DaughterEta", &PFCA4PrunedJetRCut003DaughterEta, &b_PFCA4PrunedJetRCut003DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003DaughterMass", &PFCA4PrunedJetRCut003DaughterMass, &b_PFCA4PrunedJetRCut003DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003DaughterPhi", &PFCA4PrunedJetRCut003DaughterPhi, &b_PFCA4PrunedJetRCut003DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003DaughterPt", &PFCA4PrunedJetRCut003DaughterPt, &b_PFCA4PrunedJetRCut003DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005DaughterEta", &PFCA4PrunedJetRCut005DaughterEta, &b_PFCA4PrunedJetRCut005DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005DaughterMass", &PFCA4PrunedJetRCut005DaughterMass, &b_PFCA4PrunedJetRCut005DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005DaughterPhi", &PFCA4PrunedJetRCut005DaughterPhi, &b_PFCA4PrunedJetRCut005DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005DaughterPt", &PFCA4PrunedJetRCut005DaughterPt, &b_PFCA4PrunedJetRCut005DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008DaughterEta", &PFCA4PrunedJetRCut008DaughterEta, &b_PFCA4PrunedJetRCut008DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008DaughterMass", &PFCA4PrunedJetRCut008DaughterMass, &b_PFCA4PrunedJetRCut008DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008DaughterPhi", &PFCA4PrunedJetRCut008DaughterPhi, &b_PFCA4PrunedJetRCut008DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008DaughterPt", &PFCA4PrunedJetRCut008DaughterPt, &b_PFCA4PrunedJetRCut008DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01DaughterEta", &PFCA4PrunedJetRCut01DaughterEta, &b_PFCA4PrunedJetRCut01DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01DaughterMass", &PFCA4PrunedJetRCut01DaughterMass, &b_PFCA4PrunedJetRCut01DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01DaughterPhi", &PFCA4PrunedJetRCut01DaughterPhi, &b_PFCA4PrunedJetRCut01DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01DaughterPt", &PFCA4PrunedJetRCut01DaughterPt, &b_PFCA4PrunedJetRCut01DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02DaughterEta", &PFCA4PrunedJetRCut02DaughterEta, &b_PFCA4PrunedJetRCut02DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02DaughterMass", &PFCA4PrunedJetRCut02DaughterMass, &b_PFCA4PrunedJetRCut02DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02DaughterPhi", &PFCA4PrunedJetRCut02DaughterPhi, &b_PFCA4PrunedJetRCut02DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02DaughterPt", &PFCA4PrunedJetRCut02DaughterPt, &b_PFCA4PrunedJetRCut02DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03DaughterEta", &PFCA4PrunedJetRCut03DaughterEta, &b_PFCA4PrunedJetRCut03DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03DaughterMass", &PFCA4PrunedJetRCut03DaughterMass, &b_PFCA4PrunedJetRCut03DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03DaughterPhi", &PFCA4PrunedJetRCut03DaughterPhi, &b_PFCA4PrunedJetRCut03DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03DaughterPt", &PFCA4PrunedJetRCut03DaughterPt, &b_PFCA4PrunedJetRCut03DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04DaughterEta", &PFCA4PrunedJetRCut04DaughterEta, &b_PFCA4PrunedJetRCut04DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04DaughterMass", &PFCA4PrunedJetRCut04DaughterMass, &b_PFCA4PrunedJetRCut04DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04DaughterPhi", &PFCA4PrunedJetRCut04DaughterPhi, &b_PFCA4PrunedJetRCut04DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04DaughterPt", &PFCA4PrunedJetRCut04DaughterPt, &b_PFCA4PrunedJetRCut04DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05DaughterEta", &PFCA4PrunedJetRCut05DaughterEta, &b_PFCA4PrunedJetRCut05DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05DaughterMass", &PFCA4PrunedJetRCut05DaughterMass, &b_PFCA4PrunedJetRCut05DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05DaughterPhi", &PFCA4PrunedJetRCut05DaughterPhi, &b_PFCA4PrunedJetRCut05DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05DaughterPt", &PFCA4PrunedJetRCut05DaughterPt, &b_PFCA4PrunedJetRCut05DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1DaughterEta", &PFCA4PrunedJetRCut1DaughterEta, &b_PFCA4PrunedJetRCut1DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1DaughterMass", &PFCA4PrunedJetRCut1DaughterMass, &b_PFCA4PrunedJetRCut1DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1DaughterPhi", &PFCA4PrunedJetRCut1DaughterPhi, &b_PFCA4PrunedJetRCut1DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1DaughterPt", &PFCA4PrunedJetRCut1DaughterPt, &b_PFCA4PrunedJetRCut1DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2DaughterEta", &PFCA4PrunedJetRCut2DaughterEta, &b_PFCA4PrunedJetRCut2DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2DaughterMass", &PFCA4PrunedJetRCut2DaughterMass, &b_PFCA4PrunedJetRCut2DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2DaughterPhi", &PFCA4PrunedJetRCut2DaughterPhi, &b_PFCA4PrunedJetRCut2DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2DaughterPt", &PFCA4PrunedJetRCut2DaughterPt, &b_PFCA4PrunedJetRCut2DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3DaughterEta", &PFCA4PrunedJetRCut3DaughterEta, &b_PFCA4PrunedJetRCut3DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3DaughterMass", &PFCA4PrunedJetRCut3DaughterMass, &b_PFCA4PrunedJetRCut3DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3DaughterPhi", &PFCA4PrunedJetRCut3DaughterPhi, &b_PFCA4PrunedJetRCut3DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3DaughterPt", &PFCA4PrunedJetRCut3DaughterPt, &b_PFCA4PrunedJetRCut3DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4DaughterEta", &PFCA4PrunedJetRCut4DaughterEta, &b_PFCA4PrunedJetRCut4DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4DaughterMass", &PFCA4PrunedJetRCut4DaughterMass, &b_PFCA4PrunedJetRCut4DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4DaughterPhi", &PFCA4PrunedJetRCut4DaughterPhi, &b_PFCA4PrunedJetRCut4DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4DaughterPt", &PFCA4PrunedJetRCut4DaughterPt, &b_PFCA4PrunedJetRCut4DaughterPt);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5DaughterEta", &PFCA4PrunedJetRCut5DaughterEta, &b_PFCA4PrunedJetRCut5DaughterEta);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5DaughterMass", &PFCA4PrunedJetRCut5DaughterMass, &b_PFCA4PrunedJetRCut5DaughterMass);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5DaughterPhi", &PFCA4PrunedJetRCut5DaughterPhi, &b_PFCA4PrunedJetRCut5DaughterPhi);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5DaughterPt", &PFCA4PrunedJetRCut5DaughterPt, &b_PFCA4PrunedJetRCut5DaughterPt);
   fChain->SetBranchAddress("PFCandHGCEERecHitFraction", &PFCandHGCEERecHitFraction, &b_PFCandHGCEERecHitFraction);
   fChain->SetBranchAddress("PFCandHGCHEBRecHitFraction", &PFCandHGCHEBRecHitFraction, &b_PFCandHGCHEBRecHitFraction);
   fChain->SetBranchAddress("PFCandHGCHEFRecHitFraction", &PFCandHGCHEFRecHitFraction, &b_PFCandHGCHEFRecHitFraction);
   fChain->SetBranchAddress("GenParticleHasPartonDaughter", &GenParticleHasPartonDaughter, &b_GenParticleHasPartonDaughter);
   fChain->SetBranchAddress("GenParticleMother1Index", &GenParticleMother1Index, &b_GenParticleMother1Index);
   fChain->SetBranchAddress("GenParticleMother2Index", &GenParticleMother2Index, &b_GenParticleMother2Index);
   fChain->SetBranchAddress("GenParticleNumDaught", &GenParticleNumDaught, &b_GenParticleNumDaught);
   fChain->SetBranchAddress("GenParticleNumDaught3", &GenParticleNumDaught3, &b_GenParticleNumDaught3);
   fChain->SetBranchAddress("GenParticleNumMother", &GenParticleNumMother, &b_GenParticleNumMother);
   fChain->SetBranchAddress("GenParticlePdgId", &GenParticlePdgId, &b_GenParticlePdgId);
   fChain->SetBranchAddress("GenParticleStatus", &GenParticleStatus, &b_GenParticleStatus);
   fChain->SetBranchAddress("HGCEERecHitCell", &HGCEERecHitCell, &b_HGCEERecHitCell);
   fChain->SetBranchAddress("HGCEERecHitLayer", &HGCEERecHitLayer, &b_HGCEERecHitLayer);
   fChain->SetBranchAddress("HGCEERecHitSector", &HGCEERecHitSector, &b_HGCEERecHitSector);
   fChain->SetBranchAddress("HGCEERecHitSubSector", &HGCEERecHitSubSector, &b_HGCEERecHitSubSector);
   fChain->SetBranchAddress("HGCEERecHitSubdet", &HGCEERecHitSubdet, &b_HGCEERecHitSubdet);
   fChain->SetBranchAddress("HGCHEBRecHitCell", &HGCHEBRecHitCell, &b_HGCHEBRecHitCell);
   fChain->SetBranchAddress("HGCHEBRecHitLayer", &HGCHEBRecHitLayer, &b_HGCHEBRecHitLayer);
   fChain->SetBranchAddress("HGCHEBRecHitSector", &HGCHEBRecHitSector, &b_HGCHEBRecHitSector);
   fChain->SetBranchAddress("HGCHEBRecHitSubSector", &HGCHEBRecHitSubSector, &b_HGCHEBRecHitSubSector);
   fChain->SetBranchAddress("HGCHEBRecHitSubdet", &HGCHEBRecHitSubdet, &b_HGCHEBRecHitSubdet);
   fChain->SetBranchAddress("HGCHEFRecHitCell", &HGCHEFRecHitCell, &b_HGCHEFRecHitCell);
   fChain->SetBranchAddress("HGCHEFRecHitLayer", &HGCHEFRecHitLayer, &b_HGCHEFRecHitLayer);
   fChain->SetBranchAddress("HGCHEFRecHitSector", &HGCHEFRecHitSector, &b_HGCHEFRecHitSector);
   fChain->SetBranchAddress("HGCHEFRecHitSubSector", &HGCHEFRecHitSubSector, &b_HGCHEFRecHitSubSector);
   fChain->SetBranchAddress("HGCHEFRecHitSubdet", &HGCHEFRecHitSubdet, &b_HGCHEFRecHitSubdet);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001NDaughters", &PFCA4PrunedJetRCut001NDaughters, &b_PFCA4PrunedJetRCut001NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003NDaughters", &PFCA4PrunedJetRCut003NDaughters, &b_PFCA4PrunedJetRCut003NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005NDaughters", &PFCA4PrunedJetRCut005NDaughters, &b_PFCA4PrunedJetRCut005NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008NDaughters", &PFCA4PrunedJetRCut008NDaughters, &b_PFCA4PrunedJetRCut008NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01NDaughters", &PFCA4PrunedJetRCut01NDaughters, &b_PFCA4PrunedJetRCut01NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02NDaughters", &PFCA4PrunedJetRCut02NDaughters, &b_PFCA4PrunedJetRCut02NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03NDaughters", &PFCA4PrunedJetRCut03NDaughters, &b_PFCA4PrunedJetRCut03NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04NDaughters", &PFCA4PrunedJetRCut04NDaughters, &b_PFCA4PrunedJetRCut04NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05NDaughters", &PFCA4PrunedJetRCut05NDaughters, &b_PFCA4PrunedJetRCut05NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1NDaughters", &PFCA4PrunedJetRCut1NDaughters, &b_PFCA4PrunedJetRCut1NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2NDaughters", &PFCA4PrunedJetRCut2NDaughters, &b_PFCA4PrunedJetRCut2NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3NDaughters", &PFCA4PrunedJetRCut3NDaughters, &b_PFCA4PrunedJetRCut3NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4NDaughters", &PFCA4PrunedJetRCut4NDaughters, &b_PFCA4PrunedJetRCut4NDaughters);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5NDaughters", &PFCA4PrunedJetRCut5NDaughters, &b_PFCA4PrunedJetRCut5NDaughters);
   fChain->SetBranchAddress("PFCandId", &PFCandId, &b_PFCandId);
   fChain->SetBranchAddress("PFCA4JetPFCandIndices", &PFCA4JetPFCandIndices, &b_PFCA4JetPFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut001PFCandIndices", &PFCA4PrunedJetRCut001PFCandIndices, &b_PFCA4PrunedJetRCut001PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut003PFCandIndices", &PFCA4PrunedJetRCut003PFCandIndices, &b_PFCA4PrunedJetRCut003PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut005PFCandIndices", &PFCA4PrunedJetRCut005PFCandIndices, &b_PFCA4PrunedJetRCut005PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut008PFCandIndices", &PFCA4PrunedJetRCut008PFCandIndices, &b_PFCA4PrunedJetRCut008PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut01PFCandIndices", &PFCA4PrunedJetRCut01PFCandIndices, &b_PFCA4PrunedJetRCut01PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut02PFCandIndices", &PFCA4PrunedJetRCut02PFCandIndices, &b_PFCA4PrunedJetRCut02PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut03PFCandIndices", &PFCA4PrunedJetRCut03PFCandIndices, &b_PFCA4PrunedJetRCut03PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut04PFCandIndices", &PFCA4PrunedJetRCut04PFCandIndices, &b_PFCA4PrunedJetRCut04PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut05PFCandIndices", &PFCA4PrunedJetRCut05PFCandIndices, &b_PFCA4PrunedJetRCut05PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut1PFCandIndices", &PFCA4PrunedJetRCut1PFCandIndices, &b_PFCA4PrunedJetRCut1PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut2PFCandIndices", &PFCA4PrunedJetRCut2PFCandIndices, &b_PFCA4PrunedJetRCut2PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut3PFCandIndices", &PFCA4PrunedJetRCut3PFCandIndices, &b_PFCA4PrunedJetRCut3PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut4PFCandIndices", &PFCA4PrunedJetRCut4PFCandIndices, &b_PFCA4PrunedJetRCut4PFCandIndices);
   fChain->SetBranchAddress("PFCA4PrunedJetRCut5PFCandIndices", &PFCA4PrunedJetRCut5PFCandIndices, &b_PFCA4PrunedJetRCut5PFCandIndices);
   fChain->SetBranchAddress("PFCandHGCEERecHitIndex", &PFCandHGCEERecHitIndex, &b_PFCandHGCEERecHitIndex);
   fChain->SetBranchAddress("PFCandHGCHEBRecHitIndex", &PFCandHGCHEBRecHitIndex, &b_PFCandHGCHEBRecHitIndex);
   fChain->SetBranchAddress("PFCandHGCHEFRecHitIndex", &PFCandHGCHEFRecHitIndex, &b_PFCandHGCHEFRecHitIndex);
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
