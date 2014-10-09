import ROOT as r
from array import array
import sys
import pypdt

event_number = int(sys.argv[1])
phi_min = -r.TMath.Pi()
phi_max =  r.TMath.Pi()
eta_min = -5.0
eta_max =  5.0

depth = 1

mg = r.TMultiGraph("Event " + str(event_number),"Event "+ str(event_number))

jet_circles = []
rechit_graphs = []
gen_graphs = []
subjet_graphs = []
gen_texs = []
jet_flavor_texs = []
jet_texs = []
pfcand_graphs = []

l_GenPartPt  = []
l_GenPartEta = []
l_GenPartPhi = []
l_GenPartPdg = []
l_GenPartStatus = []


l_SubJetEta = []
l_SubJetPhi = []

pdg_table = pypdt.ParticleDataTable()

def drawPFJets ( tree, canvas ):

    canvas.cd()
    
    nGenPart = tree.GenParticlePt.size()
    nPFJet = tree.PFCA4PrunedJetRCut001Pt.size()
    cone_size = 0.4

    for iPFJet in range (0, nPFJet):
        pt   = tree.PFCA4PrunedJetRCut001Pt [iPFJet]
        eta  = tree.PFCA4PrunedJetRCut001Eta[iPFJet]
        phi  = tree.PFCA4PrunedJetRCut001Phi[iPFJet]
        mass = tree.PFCA4PrunedJetRCut001Mass[iPFJet] * 1000.
        
        v_jet = r.TLorentzVector()
        v_jet.SetPtEtaPhiM( pt, eta, phi, 0. )

        partons_eta = []
        partons_phi = []
        partons_pt  = []
        partons_pdg = []
        partons_absPdg = []
        
        print "Jet", iPFJet + 1, "(%1.1f," % pt, "%1.1f," % eta , "%1.1f\t),\t" % phi, "Mass = %1.1f,\t" % mass,
        
        for iGenPart in range(0, nGenPart):
            if tree.GenParticleHasPartonDaughter[iGenPart] == 1: continue
            gen_pt  = tree.GenParticlePt [iGenPart]
            gen_eta = tree.GenParticleEta[iGenPart]
            gen_phi = tree.GenParticlePhi[iGenPart]
            v_gen   = r.TLorentzVector()
            v_gen.SetPtEtaPhiM( gen_pt, gen_eta, gen_phi, 0. )
            deltaR  = v_gen.DeltaR ( v_jet ) 
            if deltaR > 0.3 : continue
            gen_pdg = tree.GenParticlePdgId[iGenPart]
            if gen_pdg >= 81 and gen_pdg <= 100: continue
            gen_absPdg = tree.GenParticlePdgId[iGenPart]
            partons_eta.append ( gen_eta )
            partons_phi.append ( gen_phi )
            partons_pt .append ( gen_pt  )
            partons_pdg.append ( gen_pdg  )
            partons_absPdg.append ( gen_absPdg )
        
            
        index = -999
        
        if 4 in partons_absPdg:
            index = parton_pdg.index( 4 ) 
        elif 5 in partons_absPdg:
            index = parton_pdg.index( 5 ) 
        else:
            index = partons_pt.index(max(partons_pt))

        parton_pdg = partons_pdg[index]
        parton_eta = partons_eta[index]
        parton_phi = partons_phi[index]
        parton_pt  = partons_pt [index]
            

        print "chose ",pdg_table[parton_pdg].name, "\t(%1.1f," % parton_pt, "%1.1f," % parton_eta , "%1.1f)" % parton_phi
        

        jet_flavor_texs.append ( r.TLatex ())
        jet_flavor_texs[-1].SetTextSize (0.033)
        jet_flavor_texs[-1].SetTextFont (42)
        jet_flavor_texs[-1].SetTextColor(r.kBlue)
        jet_flavor_texs[-1].DrawLatex( eta, phi -0.5, pdg_table[parton_pdg].name + " %1.1f" % parton_pt ) 
        
            
        if ( phi - cone_size < phi_min ):
            dTheta = r.TMath.ASin((abs(phi - phi_min)) / cone_size) * 180. / r.TMath.Pi()
            theta1 = - dTheta
            phi2   = phi + 2 * r.TMath.Pi()
        elif ( phi + cone_size > phi_max ):
            dTheta = r.TMath.ASin((abs(phi - phi_max)) / cone_size) * 180. / r.TMath.Pi()
            theta1 = 180. - dTheta
            phi2   = phi - 2 * r.TMath.Pi()
        else:
            dTheta = r.TMath.ASin((abs(phi - phi_min)) / cone_size) * 180. / r.TMath.Pi()
            theta1 = - dTheta
            phi2   = phi
    
        theta2 = theta1 + 180. + (2.0 * dTheta )
        theta3 = theta2 + 180. - (2.0 * dTheta )
        
        jet_circles.append ( r.TEllipse(eta, phi, cone_size, cone_size, theta1, theta2 ) )
        jet_circles[-1].SetNoEdges()
        jet_circles[-1].SetFillStyle(0)
        jet_circles[-1].SetLineStyle(r.kDashed)
        jet_circles[-1].Draw("SAME")
    
        jet_circles.append ( r.TEllipse(eta, phi2, cone_size, cone_size, theta2, theta3))
        jet_circles[-1].SetNoEdges()
        jet_circles[-1].SetFillStyle(0)
        jet_circles[-1].SetLineStyle(r.kDashed)
        jet_circles[-1].Draw("SAME")

        jet_texs.append ( r.TLatex ())
        jet_texs[-1].SetTextSize (0.033)
        jet_texs[-1].SetTextFont (42)
        jet_texs[-1].SetTextColor(r.kBlack)
        jet_texs[-1].DrawLatex( eta, phi + 0.5, "%1.1f" % pt )
        
    
def getRecHits( tree ):
    
    nHGCHEB = len ( tree.HGCHEBRecHitEta )
    nHGCHEF = len ( tree.HGCHEFRecHitEta )
    nHGCEE  = len ( tree.HGCEERecHitEta  )

    a_HGCHEB_eta = array ( "f", tree.HGCHEBRecHitEta )
    a_HGCHEB_phi = array ( "f", tree.HGCHEBRecHitPhi )
    a_HGCHEF_eta = array ( "f", tree.HGCHEFRecHitEta )
    a_HGCHEF_phi = array ( "f", tree.HGCHEFRecHitPhi )
    a_HGCEE_eta  = array ( "f", tree.HGCEERecHitEta  )
    a_HGCEE_phi  = array ( "f", tree.HGCEERecHitPhi  )

    rechit_graphs.append ( r.TGraph( nHGCHEB, a_HGCHEB_eta, a_HGCHEB_phi ) )
    rechit_graphs.append ( r.TGraph( nHGCHEF, a_HGCHEF_eta, a_HGCHEF_phi ) )
    rechit_graphs.append ( r.TGraph( nHGCEE , a_HGCEE_eta , a_HGCEE_phi  ) )
    
    rechit_graphs[0].SetLineColor(r.kBlue)
    rechit_graphs[1].SetLineColor(r.kCyan)
    rechit_graphs[2].SetLineColor(r.kRed) 
    
    rechit_graphs[0].SetMarkerColor(r.kBlue)
    rechit_graphs[1].SetMarkerColor(r.kCyan)
    rechit_graphs[2].SetMarkerColor(r.kRed) 

    mg.Add ( rechit_graphs[0] )
    mg.Add ( rechit_graphs[1] )
    mg.Add ( rechit_graphs[2] )

# def getSubJets ( tree ):
#     
#     nSubJets = len(tree.PFPrunedR5JetEta)
#     
#     for iSubJet in range (0, nSubJets):
#         eta     = tree.PFPrunedJetEta   [iSubJet]
#         phi     = tree.PFPrunedJetPhi   [iSubJet]
#         l_SubJetEta.append ( eta ) 
#         l_SubJetPhi.append ( phi )
# 
#     a_eta = array ( "f", l_SubJetEta )
#     a_phi = array ( "f", l_SubJetPhi )
#     n = len ( l_SubJetEta ) 
# 
#     subjet_graphs.append ( r.TGraph(n, a_eta, a_phi))
#     subjet_graphs[-1].SetMarkerColor(r.kGreen)
#     subjet_graphs[-1].SetMarkerStyle(2)
#     
#     mg.Add ( subjet_graphs[-1] )

def getPFCands( tree ):
    
    nPFCands = len ( tree.PFCandEta ) 
    
    a_PFCand_eta = array ( "f", tree.PFCandEta )
    a_PFCand_phi = array ( "f", tree.PFCandPhi )

    pfcand_graphs.append ( r.TGraph( nPFCands, a_PFCand_eta, a_PFCand_phi ) )
    
    pfcand_graphs[0].SetLineColor  (r.kBlack)
    pfcand_graphs[0].SetMarkerColor(r.kBlack)
    
    mg.Add ( pfcand_graphs[0] )


def getGenParts ( tree ):
    
    nGenParts = tree.GenParticlePt.size()
    
    for iGenPart in range (0, nGenParts):
        pt      = tree.GenParticlePt    [iGenPart]
        eta     = tree.GenParticleEta   [iGenPart]
        phi     = tree.GenParticlePhi   [iGenPart]
        pdg     = tree.GenParticlePdgId [iGenPart]
        status  = tree.GenParticleStatus[iGenPart]
        ndaught = tree.GenParticleNumDaught3[iGenPart]

        if status != 3 : continue
        if ndaught != 0: continue
        
        l_GenPartStatus.append ( status )
        l_GenPartPt .append ( pt  ) 
        l_GenPartEta.append ( eta ) 
        l_GenPartPhi.append ( phi )
        l_GenPartPdg.append ( pdg )

    a_eta = array ( "f", l_GenPartEta )
    a_phi = array ( "f", l_GenPartPhi )
    n = len ( l_GenPartEta ) 

    gen_graphs.append ( r.TGraph(n, a_eta, a_phi))
    gen_graphs[-1].SetMarkerColor(r.kBlue)
    gen_graphs[-1].SetMarkerStyle(3)
    mg.Add ( gen_graphs[-1] )

def drawGenLabels ():
    
    nGenParts = len ( l_GenPartEta )
    
    for iGenPart in range ( 0, nGenParts ):
        pt = l_GenPartPt[iGenPart]
        gen_texs.append ( r.TLatex ())
        gen_texs[-1].SetTextSize (0.033)
        gen_texs[-1].SetTextFont (42)
        gen_texs[-1].SetTextColor(r.kBlue)
        gen_texs[-1].DrawLatex( l_GenPartEta[iGenPart] + 0.1,
                                l_GenPartPhi[iGenPart],
                                pdg_table[l_GenPartPdg[iGenPart]].name )

        

    
file = r.TFile("data/HGCAL_QQH_output.root");
tree = file.Get("hgcalTupleTree/tree")
tree.GetEntry(event_number)

r.gStyle.SetOptStat(0)
canvas = r.TCanvas()
canvas.cd()

getPFCands ( tree ) 
# getRecHits ( tree )
getGenParts( tree )
# getSubJets ( tree )

mg.Draw("AP")
mg.GetXaxis().SetLimits(eta_min, eta_max)
mg.GetXaxis().SetTitle("#eta")
mg.GetYaxis().SetTitle("#phi")
mg.GetHistogram().SetMinimum(phi_min)
mg.GetHistogram().SetMaximum(phi_max)
mg.Draw("AP")

drawPFJets  ( tree, canvas )

drawGenLabels()

canvas.SaveAs("plot_"+str(event_number)+".pdf");
