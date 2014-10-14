import ROOT as r
from array import array

r.gStyle.SetOptStat(0);
r.gStyle.SetOptTitle(0);

g_file = r.TFile("output_WJet.root");
q_file = r.TFile("output_WJet.root" );

r_cut_values = [ "R001", "R003", "R04", "R4" ]

xmin = 0.0
xmax = 1.0
npoints = 51

save_name = "roc_curves.pdf"

graphs = []

canvas = r.TCanvas()
canvas.cd()
mg = r.TMultiGraph()


l = r.TLegend(0.6, 0.6, 0.85, 0.85);
l.SetFillColor(r.kWhite);
l.SetBorderSize(1);
l.SetShadowColor(10);
l.SetMargin(0.2);
l.SetTextFont(42);

for i_r_cut_value, r_cut_value in enumerate(r_cut_values):
    
    
    q_name = "like_quarkPruned"+r_cut_value+"Jets"
    g_name = "like_gluonPruned"+r_cut_value+"Jets"
    
    q_hist = q_file.Get(q_name)
    g_hist = q_file.Get(g_name)

    i_q_hist = q_hist.Integral()
    i_g_hist = g_hist.Integral()

    if i_q_hist == 0 or i_g_hist == 0: continue

    nbins = q_hist.GetNbinsX()

    l_effi = []
    l_fake = []
        
    for i in range(0, npoints):
        l_cut_value = float(i) * (xmax - xmin) / (float (npoints - 1))
        
        bin_number = q_hist.FindBin(l_cut_value);
        effi = q_hist.Integral(bin_number, nbins + 1 ) / i_q_hist
        fake = 1. - (g_hist.Integral(bin_number, nbins + 1 ) / i_g_hist)

        l_effi.append ( effi )
        l_fake.append ( fake )

    graphs.append(r.TGraph(npoints, array("f", l_effi), array("f", l_fake)))
    graphs[-1].SetLineColor(1 + i_r_cut_value)
    mg.Add(graphs[-1])

    r_cut_name = "0." + r_cut_value[1:]
    legend_name = "Pruned jets [R = "+r_cut_name+", Z = 0.1]"
    l.AddEntry(graphs[-1], legend_name, "l");

canvas.Print(save_name + "[")
mg.Draw("APL")
l.Draw();
mg.GetXaxis().SetTitle("Quark jet efficiency");
mg.GetYaxis().SetTitle("1 - Gluon jet fake rate");
canvas.Print(save_name)
canvas.Print(save_name + "]")
