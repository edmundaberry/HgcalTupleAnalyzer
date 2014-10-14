import ROOT as r


r.gStyle.SetOptStat(0);
r.gStyle.SetOptTitle(0);

g_file = r.TFile("output_WJet.root");
q_file = r.TFile("output_WJet.root" );

r_cut_values = [ "R001", "R003", "R005", "R008", "R01", "R02", "R03", "R04", "R05", "R1", "R2", "R3", "R4", "R5" ]
r_cut_values = [  "R4", "R04", "R003" ]


variables = [ "nsubj"                 ,
              "mass"                  ,
              "nDaught"               ,
              "multi"                 ,
              "width"                 ,
              "depth"                 ,
              "depth_noEE"            ,
              "ptd"                   ,
              "like"                  ,
              "ee_energy_fraction"    ,
              "ee015_energy_fraction"    ,
              "ee1631_energy_fraction"    ,
              "heb_energy_fraction"   ,
              "hef_energy_fraction"   ,
              "hef11_energy_fraction" ,
              "hef22_energy_fraction" ,
              "hef34_energy_fraction" ,
              "hef56_energy_fraction" ,
              "hef712_energy_fraction" ]

d_variable_xmin = { "nsubj"                  : 0.,
                    "mass"                   : 0.,
                    "nDaught"                : 0.,
                    "multi"                  : 0.,
                    "width"                  : 0., 
                    "depth"                  : 0., 
                    "depth_noEE"             : 0.,
                    "ptd"                    : "NULL",
                    "like"                   : 0., 
                    "ee_energy_fraction"     : 0.,
                    "ee015_energy_fraction"  : 0.,
                    "ee1631_energy_fraction" : 0.,
                    "heb_energy_fraction"    : 0.,
                    "hef_energy_fraction"    : 0.,
                    "hef11_energy_fraction"  : 0.,
                    "hef22_energy_fraction"  : 0.,
                    "hef34_energy_fraction"  : 0.,
                    "hef56_energy_fraction"  : 0., 
                    "hef712_energy_fraction" : 0. };

d_variable_xmax = { "nsubj"                  : 2000.,
                    "mass"                   : 2000.,
                    "nDaught"                : 2000.,
                    "multi"                  : 2000.,
                    "width"                  : 0.4, 
                    "depth"                  : 1000., 
                    "depth_noEE"             : 1000.,
                    "ptd"                    : "NULL",
                    "like"                   : 1.0, 
                    "ee_energy_fraction"     : 1.0,
                    "ee015_energy_fraction"  : 1.0,
                    "ee1631_energy_fraction" : 1.0,
                    "heb_energy_fraction"    : 1.0,
                    "hef_energy_fraction"    : 1.0,
                    "hef11_energy_fraction"  : 1.0,
                    "hef22_energy_fraction"  : 1.0,
                    "hef34_energy_fraction"  : 1.0,
                    "hef56_energy_fraction"  : 1.0, 
                    "hef712_energy_fraction" : 1.0 };


for variable in variables:
    
    canvas = r.TCanvas();
    save_name = variable + ".pdf"
    if "energy_fraction" in variable:
        canvas.SetLogy()
    canvas.Print(save_name + "[")

    for r_cut_value in r_cut_values:
        
        r_cut_name = "0." + r_cut_value[1:]
        
        quark_name = variable + "_quarkPruned"+r_cut_value+"Jets"
        gluon_name = variable + "_gluonPruned"+r_cut_value+"Jets"
        
        h_quark = q_file.Get(quark_name)
        h_gluon = g_file.Get(gluon_name)

        h_quark.Sumw2();
        h_gluon.Sumw2();
    
        if (variable == "like"):
            h_quark.Rebin(50)
            h_gluon.Rebin(50)

        h_quark.SetLineColor(r.kRed);
        h_gluon.SetLineColor(r.kBlue);

        h_quark.SetFillColor(r.kRed);
        h_gluon.SetFillColor(r.kBlue);

        h_quark.SetFillStyle(3004);
        h_gluon.SetFillStyle(3005);

        i_quark = h_quark.Integral();
        i_gluon = h_gluon.Integral();

        if i_quark != 0: h_quark.Scale ( 1.0 / i_quark );
        if i_gluon != 0: h_gluon.Scale ( 1.0 / i_gluon );

        if ( d_variable_xmin[variable] != "NULL"):
            h_quark.GetXaxis().SetRangeUser(d_variable_xmin[variable], d_variable_xmax[variable])
            h_gluon.GetXaxis().SetRangeUser(d_variable_xmin[variable], d_variable_xmax[variable])

        h_quark.GetXaxis().SetTitle(variable);
        h_quark.GetYaxis().SetTitle("Unit-normalized [A. U.]");
        
        h_gluon.GetXaxis().SetTitle(variable);
        h_gluon.GetYaxis().SetTitle("Unit-normalized [A. U.]");

        h_quark.GetYaxis().SetTitleOffset(1.2);
        h_gluon.GetYaxis().SetTitleOffset(1.2);

        h_quark.Draw("HIST E");
        h_gluon.Draw("HIST E SAME");

        h_quark_max = h_quark.GetMaximum();
        h_gluon_max = h_gluon.GetMaximum();
        h_max = max ( h_quark_max, h_gluon_max ) * 1.5
        h_quark.SetMaximum(h_max);
        h_gluon.SetMaximum(h_max);
        h_quark.SetMinimum(0.0);
        h_gluon.SetMinimum(0.0);
        
        h_quark.Draw("HIST E");
        h_gluon.Draw("HIST E SAME");

        quark_l_name = "Pruned quark jets [R_{cut} = "+r_cut_name+", Z_{cut} = 0.1]"
        gluon_l_name = "Pruned gluon jets [R_{cut} = "+r_cut_name+", Z_{cut} = 0.1]"

        l = r.TLegend(0.3, 0.75, 0.85, 0.85);
        l.SetFillColor(r.kWhite);
        l.SetBorderSize(1);
        l.SetShadowColor(10);
        l.SetMargin(0.2);
        l.SetTextFont(42);
        l.AddEntry(h_quark, quark_l_name, "f");
        l.AddEntry(h_gluon, gluon_l_name, "f");
        l.Draw();
        canvas.SaveAs(variable + "_" + r_cut_name + ".pdf")
        canvas.Print(save_name)
    canvas.Print(save_name + "]");
