
void jet_width( const char * name){
  
  gStyle -> SetOptStat(0);
  gStyle -> SetOptTitle(0);

  TCanvas * canvas = new TCanvas();

  TFile * wjet_file = new TFile("output_QQH.root");
  TFile * qqh_file  = new TFile("output_QQH.root" );

  char quark_name[100]; sprintf(quark_name, "width_quarkPrunedR%sJets", name );
  char gluon_name[100]; sprintf(gluon_name, "width_gluonPrunedR%sJets", name );

  TH1F * h_quark = (TH1F*) qqh_file  -> Get(quark_name);
  TH1F * h_gluon = (TH1F*) qqh_file  -> Get(gluon_name);
  
  h_quark -> Sumw2();
  h_gluon -> Sumw2();

  h_quark -> Rebin(5);
  h_gluon -> Rebin(5);

  h_quark -> SetLineColor(kRed);
  h_gluon -> SetLineColor(kBlue);

  h_quark -> SetFillColor(kRed);
  h_gluon -> SetFillColor(kBlue);

  h_quark -> SetFillStyle(3004);
  h_gluon -> SetFillStyle(3005);

  double i_quark = h_quark -> Integral();
  double i_gluon = h_gluon -> Integral();

  h_quark -> Scale ( 1.0 / i_quark );
  h_gluon -> Scale ( 1.0 / i_gluon );

  h_quark -> GetXaxis() -> SetRangeUser(0, 0.4);
  h_gluon -> GetXaxis() -> SetRangeUser(0, 0.4);

  h_quark -> GetXaxis() -> SetTitle("Jet width");
  h_quark -> GetYaxis() -> SetTitle("Unit-normalized [A. U.]");

  h_gluon -> GetXaxis() -> SetTitle("Jet width");
  h_gluon -> GetYaxis() -> SetTitle("Unit-normalized [A. U.]");

  h_quark -> GetYaxis() -> SetTitleOffset(1.2);
  h_gluon -> GetYaxis() -> SetTitleOffset(1.2);

  h_quark -> Draw("HIST E");
  h_gluon -> Draw("HIST E SAME");

  sprintf(quark_name, "Pruned quark jets [R_{cut} = 0.%s, Z_{cut} = 0.1]", name );
  sprintf(gluon_name, "Pruned gluon jets [R_{cut} = 0.%s, Z_{cut} = 0.1]", name );

  TLegend * l = new TLegend(0.3, 0.75, 0.85, 0.85);
  l -> SetFillColor(kWhite);
  l -> SetBorderSize(1);
  l -> SetShadowColor(10);
  l -> SetMargin(0.2);
  l -> SetTextFont(42);
  l -> AddEntry(h_quark, quark_name, "f");
  l -> AddEntry(h_gluon, gluon_name, "f");
  l -> Draw();

  canvas -> SaveAs("jet_width.pdf");
  
}
