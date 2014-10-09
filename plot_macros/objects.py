import ROOT as r
import pypdt

pdg_table = pypdt.ParticleDataTable()

d_pfCandId_pfCandName = {
    1 : "Undefined",
    2 : "Charged hadron",
    3 : "Electron",
    4 : "Muon",
    5 : "Photon",
    6 : "Neutral hadron",
    7 : "HF hadron",
    8 : "HF e/gamma"
}

class GenParticle:
    def __init__(self,tree, index):
        self.tree = tree
        self.index = index
        self.pt = tree.GenParticlePt[index]
        self.eta = tree.GenParticleEta[index]
        self.phi = tree.GenParticlePhi[index]
        self.pdg = tree.GenParticlePdgId[index]
        self.status = tree.GenParticleStatus[index]
        self.name = pdg_table[self.pdg].name
        self.hasPartonDaughter = bool (tree.GenParticleHasPartonDaughter[index] == 1)

class RecHit: 
    def __init__ (self, tree, index, detector):
        self.tree = tree
        self.index = index
        self.detector = detector
        
        if detector == 0:
            self.X   = tree.HGCEERecHitX[index]
            self.Y   = tree.HGCEERecHitY[index]
            self.Z   = tree.HGCEERecHitZ[index]
            self.Eta = tree.HGCEERecHitEta[index]
            self.Phi = tree.HGCEERecHitPhi[index]
            self.energy = tree.HGCEERecHitEnergy[index]

        elif detector == 1:
            self.X = tree.HGCHEFRecHitX[index]
            self.Y = tree.HGCHEFRecHitY[index]
            self.Z = tree.HGCHEFRecHitZ[index]
            self.Eta = tree.HGCHEFRecHitEta[index]
            self.Phi = tree.HGCHEFRecHitPhi[index]
            self.energy = tree.HGCHEFRecHitEnergy[index]

        elif detector == 2:
            self.X = tree.HGCHEBRecHitX[index]
            self.Y = tree.HGCHEBRecHitY[index]
            self.Z = tree.HGCHEBRecHitZ[index]
            self.Eta = tree.HGCHEBRecHitEta[index]
            self.Phi = tree.HGCHEBRecHitPhi[index]
            self.energy = tree.HGCHEBRecHitEnergy[index]
            

class PFCluster: 
    def __init__ (self,tree, index, detector):
        self.tree  = tree
        self.index = index
        self.detector = detector
        
        if detector == 0:
            self.X = tree.HGCEEPFClusterX[index]
            self.Y = tree.HGCEEPFClusterY[index]
            self.Z = tree.HGCEEPFClusterZ[index]
            self.Eta = tree.HGCEEPFClusterEta[index]
            self.Phi = tree.HGCEEPFClusterPhi[index]
            self.energy = tree.HGCEEPFClusterEnergy[index]
            self.rh_indices = tree.HGCEEPFClusterRecHitIndex[index]
        elif detector == 1:
            self.X = tree.HGCHEFPFClusterX[index]
            self.Y = tree.HGCHEFPFClusterY[index]
            self.Z = tree.HGCHEFPFClusterZ[index]
            self.Eta = tree.HGCHEFPFClusterEta[index]
            self.Phi = tree.HGCHEFPFClusterPhi[index]
            self.energy = tree.HGCHEFPFClusterEnergy[index]
            self.rh_indices = tree.HGCHEFPFClusterRecHitIndex[index]
        elif detector == 2:
            self.X = tree.HGCHEBPFClusterX[index]
            self.Y = tree.HGCHEBPFClusterY[index]
            self.Z = tree.HGCHEBPFClusterZ[index]
            self.Eta = tree.HGCHEBPFClusterEta[index]
            self.Phi = tree.HGCHEBPFClusterPhi[index]
            self.energy = tree.HGCHEBPFClusterEnergy[index]
            self.rh_indices = tree.HGCHEBPFClusterRecHitIndex[index]

        self.rechits = []
            
        self.makeRecHits()
        
    def makeRecHits ( self ):
        for index in self.rh_indices:
            self.rechits.append ( RecHit(self.tree, index, self.detector))
        

class PFCand:
    def __init__ (self, tree, index):
        self.tree  = tree
        self.index = index
        self.pt    = tree.PFCandPt [index]
        self.eta   = tree.PFCandEta[index]
        self.phi   = tree.PFCandPhi[index]
        self.hgcee_cluster_indices  = tree.PFCandHGCEEClusterIndex [index]
        self.hgchef_cluster_indices = tree.PFCandHGCHEFClusterIndex[index]
        self.hgcheb_cluster_indices = tree.PFCandHGCHEBClusterIndex[index]
        self.idnumber = tree.PFCandId[index]
        self.idname = d_pfCandId_pfCandName[self.idnumber]
        self.clusters = []
        
        self.makeClusters()
    
    def makeClusters(self):
        for index in self.hgcee_cluster_indices:
            self.clusters.append ( PFCluster (self.tree, index, 0 ))
        for index in self.hgchef_cluster_indices:
            self.clusters.append ( PFCluster (self.tree, index, 1 ))
        for index in self.hgcheb_cluster_indices:
            self.clusters.append ( PFCluster (self.tree, index, 2 ))

class PFSubJet:
    def __init__ (self, tree, jet_index, subjet_index, name ):
        self.tree = tree
        self.jet_index = jet_index
        self.subjet_index = subjet_index
        self.name = name
        self.pt   = getattr(tree, name + "DaughterPt"  )[jet_index][subjet_index]
        self.eta  = getattr(tree, name + "DaughterEta" )[jet_index][subjet_index]
        self.phi  = getattr(tree, name + "DaughterPhi" )[jet_index][subjet_index]
        self.mass = getattr(tree, name + "DaughterMass")[jet_index][subjet_index]
        
class PFJet:
    def __init__(self, tree, index, name):
        self.tree  = tree
        self.index = index
        self.name = name
        self.cand_indices = getattr(tree, name + "PFCandIndices")[index]
        self.pt           = getattr(tree, name + "Pt"           )[index]
        self.p            = getattr(tree, name + "P"            )[index]
        self.eta          = getattr(tree, name + "Eta"          )[index]
        self.phi          = getattr(tree, name + "Phi"          )[index]
        self.e            = getattr(tree, name + "Energy"       )[index]
        self.mass         = getattr(tree, name + "Mass"         )[index]
        self.nsubjets     = getattr(tree, name + "NDaughters"   )[index]
        self.ncands       = len(self.cand_indices)
        self.cands   = []
        self.subjets = []
        
        self.makeCands()
        self.makeDaughters()
    
    def makeCands(self):
        for index in self.cand_indices:
            self.cands.append ( PFCand ( self.tree, index ) )
                           
    def makeDaughters(self):
        for i in range(0, self.nsubjets):
            self.subjets.append ( PFSubJet( self.tree, self.index, i, self.name ))
            
    def massFromSubjets(self):
        v_total = r.TLorentzVector()
        for subjet in self.subjets:
            v_subjet = r.TLorentzVector()
            v_subjet.SetPtEtaPhiM( subjet.pt, subjet.eta, subjet.phi, subjet.mass)
            v_total += v_subjet
        return v_total.M()
            
        
