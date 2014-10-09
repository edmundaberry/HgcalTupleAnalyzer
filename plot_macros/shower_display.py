#--------------------------------------------------------------------------------
# Imports
#--------------------------------------------------------------------------------

import ROOT as r
import sys
from objects      import *
from draw_tool    import *
from physics_tool import *

#--------------------------------------------------------------------------------
# Load ROOT settings
#--------------------------------------------------------------------------------

r.gStyle.SetOptStat(0)
r.gROOT.LoadMacro("stl_loader.h+")

#--------------------------------------------------------------------------------
# User-defined values
#--------------------------------------------------------------------------------

file    = r.TFile("data/HGCAL_QQH_output.root");
tree    = file.Get("hgcalTupleTree/tree")
event   = int(sys.argv[1])
rcut    = "4" 
verbose = False
    
#--------------------------------------------------------------------------------
# Initialize the tree for a given event
#--------------------------------------------------------------------------------

tree.GetEntry(event)

#--------------------------------------------------------------------------------
# Get a list of all of the GEN particles
#--------------------------------------------------------------------------------

gen_particles = []
n_gen_particles = len(tree.GenParticlePt)
for i in range(0, n_gen_particles):
    gen_particles.append(GenParticle(tree, i))

#--------------------------------------------------------------------------------
# Save the canvas
#--------------------------------------------------------------------------------

save_name = "plot_event" + str(event) + ".pdf"
canvas = r.TCanvas()
canvas.Print(save_name+"[")

#--------------------------------------------------------------------------------
# Loop over the jets
#--------------------------------------------------------------------------------

jet_name = "PFCA4PrunedJetRCut" + rcut
njet = len(getattr(tree, jet_name + "P"))

for ijet in range (0, njet):

    #--------------------------------------------------------------------------------
    # Start by clearing the canvas
    #--------------------------------------------------------------------------------
    
    canvas.Clear()

    #--------------------------------------------------------------------------------
    # Get the jet 
    #--------------------------------------------------------------------------------

    jet  = PFJet ( tree, ijet, jet_name )

    #--------------------------------------------------------------------------------
    # Make graphs of the shower from the jet.  Bail if there aren't any showers.
    #--------------------------------------------------------------------------------

    tool = DrawTool()
    tool.makeGraphs( jet ) 
    if not tool.draw: continue

    #--------------------------------------------------------------------------------
    # Do flavor-matching
    #--------------------------------------------------------------------------------
    
    flavor = getFlavor ( jet, gen_particles ) 
    
    #--------------------------------------------------------------------------------
    # Tell the user what's up
    #--------------------------------------------------------------------------------

    if verbose:
        print "Drawing shower display for jet #" + str(ijet+1) + " from event #" + str(event)
        print "GEN parton =", flavor.name
        print "GEN pt     = %1.2f" % flavor.pt
        print "GEN eta    = %1.2f" % flavor.eta
        print "GEN phi    = %1.2f" % flavor.phi
        print "Jet Pt     = %1.2f" % jet.pt
        print "Jet Eta    = %1.2f" % jet.eta
        print "Jet Phi    = %1.2f" % jet.phi
        print "Jet mass   = %1.2f" % jet.mass
        print "N(PFCands) =", jet.ncands
        print "N(SubJets) =", jet.nsubjets
        
    #--------------------------------------------------------------------------------
    # Draw the plots
    #--------------------------------------------------------------------------------

    canvas.Divide(1,5)
    
    canvas.GetPad(1).SetRightMargin(0.4)
    canvas.GetPad(2).SetRightMargin(0.4)
    canvas.GetPad(3).SetRightMargin(0.4)
    canvas.GetPad(4).SetRightMargin(0.4)
    canvas.GetPad(5).SetRightMargin(0.4)
    
    canvas.cd(1)
    tool.multigraph_ep_final.Draw("AP")
    tool.multigraph_ep_final.GetXaxis().SetTitle("#eta");
    tool.multigraph_ep_final.GetYaxis().SetTitle("#phi");
    tool.multigraph_ep_final.Draw("AP")
    
    canvas.cd(2)
    tool.multigraph_xy.Draw("AP")
    tool.multigraph_xy.GetXaxis().SetTitle("X [cm]")
    tool.multigraph_xy.GetYaxis().SetTitle("Y [cm]")
    tool.multigraph_xy.Draw("AP")
    
    canvas.cd(3)
    tool.multigraph_xz.Draw("AP")
    tool.multigraph_xz.GetXaxis().SetTitle("|Z| [cm]")
    tool.multigraph_xz.GetYaxis().SetTitle("X [cm]")
    tool.multigraph_xz.Draw("AP")
    
    canvas.cd(4)
    tool.multigraph_yz.Draw("AP")
    tool.multigraph_yz.GetXaxis().SetTitle("|Z| [cm]")
    tool.multigraph_yz.GetYaxis().SetTitle("Y [cm]")
    tool.multigraph_yz.Draw("AP")
    
    canvas.cd(5)
    tool.multigraph_ep.Draw("AP")
    tool.multigraph_ep.GetXaxis().SetTitle("#eta");
    tool.multigraph_ep.GetYaxis().SetTitle("#phi");
    tool.multigraph_ep.Draw("AP")

    #--------------------------------------------------------------------------------
    # Draw the legend
    #--------------------------------------------------------------------------------
    
    canvas.cd()
    tool.legend.SetX1(0.65)
    tool.legend.SetX2(0.95)
    tool.legend.SetY1(0.05)
    tool.legend.SetY2(0.9588)
    tool.legend.Draw("SAME")

    #--------------------------------------------------------------------------------
    # Save the canvas
    #--------------------------------------------------------------------------------
    
    canvas.Print(save_name)


#--------------------------------------------------------------------------------
# Close the canvas
#--------------------------------------------------------------------------------

canvas.Print(save_name+"]")
