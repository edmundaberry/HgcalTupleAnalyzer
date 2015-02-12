#include "likelihoodGetter.h"
#include <TMath.h>
#include <iostream>
#include <algorithm>

likelihoodGetter::likelihoodGetter ( std::string & file_name, 
				     std::string & rcut_factor,
				     std::vector<std::string> & variables, 
				     std::vector<std::string> & signals  ):
  m_file_name   ( file_name ),
  m_rcut_factor ( rcut_factor ),
  m_file        ( new TFile ( file_name.c_str() )),
  m_variables   ( variables ),
  m_signals     ( signals ),
  m_n_variables ( variables.size() ),
  m_n_signals   ( signals.size() ) {
  
  for (int i_variable = 0; i_variable < m_n_variables ; ++i_variable ) { 
    
    char background_hist_name[200]; sprintf( background_hist_name, "%s_gluonPruned%sJets", m_variables[i_variable].c_str(), rcut_factor.c_str());
    TH1F * background_hist = (TH1F*) m_file -> Get(background_hist_name);
    background_hist -> Sumw2();
    background_hist -> Scale ( 1.0 / background_hist -> Integral(0, background_hist -> GetNbinsX() + 1));
    
    if ( background_hist == 0 ){
      std::cout << "Can't find this histogram: " << background_hist_name << std::endl;
      std::cout << "File I checked was: " << m_file_name << std::endl;
      exit(0);
    }
      

    m_background_hists.push_back ( background_hist );
    m_signal_hists.push_back ( std::vector<TH1F*>() );
    
    for ( int i_signal = 0; i_signal < m_n_signals; ++i_signal ){
      char signal_hist_name[200]; sprintf( signal_hist_name, "%s_%s", m_variables[i_variable].c_str(), m_signals[i_signal].c_str());
      TH1F * signal_hist = (TH1F*) m_file -> Get(signal_hist_name);
      signal_hist -> Sumw2();
      signal_hist -> Scale ( 1.0 / signal_hist -> Integral());
      m_signal_hists[i_variable].push_back ( signal_hist );
    }
  }
}

likelihoodGetter::~likelihoodGetter(){}

double likelihoodGetter::getLikelihood ( std::vector<double> & values ){
  
  std::vector<std::string>::iterator it_signal = m_signals.begin();
  
  int i_signal = std::distance ( m_signals.begin(), it_signal );
  
  double total_signal_prob     = 1.0;
  double total_background_prob = 1.0;
  
  for (int i_variable = 0; i_variable < m_n_variables ; ++i_variable ) { 
    int    signal_bin      = m_signal_hists    [i_variable][i_signal] -> FindBin(values[i_variable]);
    double signal_prob     = m_signal_hists    [i_variable][i_signal] -> GetBinContent(signal_bin);
    int    background_bin  = m_background_hists[i_variable]           -> FindBin(values[i_variable]);
    double background_prob = m_background_hists[i_variable]           -> GetBinContent(background_bin);

    total_signal_prob     *= signal_prob;
    total_background_prob *= background_prob;
  }
  
  double numerator   = total_signal_prob;
  double denominator = total_signal_prob + total_background_prob;
  double likelihood  = -1.0;
  if (denominator > 0.0 ) likelihood = numerator / denominator;
			     
  return likelihood;
}


double likelihoodGetter::getLogLikelihood ( std::vector<double> & values ){
  
  std::vector<std::string>::iterator it_signal = m_signals.begin();
  
  int i_signal = std::distance ( m_signals.begin(), it_signal );
  
  double total_signal_prob     = 1.0;
  double total_background_prob = 1.0;
  
  for (int i_variable = 0; i_variable < m_n_variables ; ++i_variable ) { 
    int    signal_bin      = m_signal_hists    [i_variable][i_signal] -> FindBin(values[i_variable]);
    double signal_prob     = m_signal_hists    [i_variable][i_signal] -> GetBinContent(signal_bin);
    int    background_bin  = m_background_hists[i_variable]           -> FindBin(values[i_variable]);
    double background_prob = m_background_hists[i_variable]           -> GetBinContent(background_bin);

    total_signal_prob     *= signal_prob;
    total_background_prob *= background_prob;
  }
  
  double numerator   = total_signal_prob;
  double denominator = total_background_prob;

  double log_likelihood  = 0.0;
  if (denominator > 0.0 ) {
    double likelihood     = numerator / denominator;
    log_likelihood = TMath::Log ( likelihood );
  }
  
  return log_likelihood;
}
