//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 20 15:44:16 2014 by ROOT version 5.34/07
// from TTree tree/
// found on file: data/HGCAL_output.root
//////////////////////////////////////////////////////////

#ifndef HgcalTupleTree_h
#define HgcalTupleTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class HgcalTupleTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   std::vector<double>  *CaloJetEnergy;
   std::vector<double>  *CaloJetEta;
   std::vector<double>  *CaloJetP;
   std::vector<double>  *CaloJetPhi;
   std::vector<double>  *CaloJetPt;
   std::vector<double>  *GenJetEMF;
   std::vector<double>  *GenJetEnergy;
   std::vector<double>  *GenJetEta;
   std::vector<double>  *GenJetHADF;
   std::vector<double>  *GenJetP;
   std::vector<double>  *GenJetPhi;
   std::vector<double>  *GenJetPt;
   std::vector<double>  *GenParticleEnergy;
   std::vector<double>  *GenParticleEta;
   std::vector<double>  *GenParticleP;
   std::vector<double>  *GenParticlePhi;
   std::vector<double>  *GenParticlePt;
   std::vector<double>  *GenParticlePx;
   std::vector<double>  *GenParticlePy;
   std::vector<double>  *GenParticlePz;
   std::vector<double>  *GenParticleVX;
   std::vector<double>  *GenParticleVY;
   std::vector<double>  *GenParticleVZ;
   std::vector<double>  *PFJetEnergy;
   std::vector<double>  *PFJetEta;
   std::vector<double>  *PFJetP;
   std::vector<double>  *PFJetPhi;
   std::vector<double>  *PFJetPt;
   std::vector<double>  *PFJetTau1;
   std::vector<double>  *PFJetTau2;
   std::vector<double>  *PFJetTau3;
   std::vector<int>     *GenParticleMother1Index;
   std::vector<int>     *GenParticleMother2Index;
   std::vector<int>     *GenParticleNumDaught;
   std::vector<int>     *GenParticleNumMother;
   std::vector<int>     *GenParticlePdgId;
   std::vector<int>     *GenParticleStatus;
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
   TBranch        *b_PFJetEnergy;   //!
   TBranch        *b_PFJetEta;   //!
   TBranch        *b_PFJetP;   //!
   TBranch        *b_PFJetPhi;   //!
   TBranch        *b_PFJetPt;   //!
   TBranch        *b_PFJetTau1;   //!
   TBranch        *b_PFJetTau2;   //!
   TBranch        *b_PFJetTau3;   //!
   TBranch        *b_GenParticleMother1Index;   //!
   TBranch        *b_GenParticleMother2Index;   //!
   TBranch        *b_GenParticleNumDaught;   //!
   TBranch        *b_GenParticleNumMother;   //!
   TBranch        *b_GenParticlePdgId;   //!
   TBranch        *b_GenParticleStatus;   //!
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/HGCAL_output.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("data/HGCAL_output.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("data/HGCAL_output.root:/hgcalTupleTree");
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
   PFJetEnergy = 0;
   PFJetEta = 0;
   PFJetP = 0;
   PFJetPhi = 0;
   PFJetPt = 0;
   PFJetTau1 = 0;
   PFJetTau2 = 0;
   PFJetTau3 = 0;
   GenParticleMother1Index = 0;
   GenParticleMother2Index = 0;
   GenParticleNumDaught = 0;
   GenParticleNumMother = 0;
   GenParticlePdgId = 0;
   GenParticleStatus = 0;
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
   fChain->SetBranchAddress("PFJetEnergy", &PFJetEnergy, &b_PFJetEnergy);
   fChain->SetBranchAddress("PFJetEta", &PFJetEta, &b_PFJetEta);
   fChain->SetBranchAddress("PFJetP", &PFJetP, &b_PFJetP);
   fChain->SetBranchAddress("PFJetPhi", &PFJetPhi, &b_PFJetPhi);
   fChain->SetBranchAddress("PFJetPt", &PFJetPt, &b_PFJetPt);
   fChain->SetBranchAddress("PFJetTau1", &PFJetTau1, &b_PFJetTau1);
   fChain->SetBranchAddress("PFJetTau2", &PFJetTau2, &b_PFJetTau2);
   fChain->SetBranchAddress("PFJetTau3", &PFJetTau3, &b_PFJetTau3);
   fChain->SetBranchAddress("GenParticleMother1Index", &GenParticleMother1Index, &b_GenParticleMother1Index);
   fChain->SetBranchAddress("GenParticleMother2Index", &GenParticleMother2Index, &b_GenParticleMother2Index);
   fChain->SetBranchAddress("GenParticleNumDaught", &GenParticleNumDaught, &b_GenParticleNumDaught);
   fChain->SetBranchAddress("GenParticleNumMother", &GenParticleNumMother, &b_GenParticleNumMother);
   fChain->SetBranchAddress("GenParticlePdgId", &GenParticlePdgId, &b_GenParticlePdgId);
   fChain->SetBranchAddress("GenParticleStatus", &GenParticleStatus, &b_GenParticleStatus);
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
