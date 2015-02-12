#ifndef LIKELIHOOD_GETTER_H
#define LIKELIHOOD_GETTER_H

#include <vector>
#include <string>

#include "TFile.h"
#include "TH1F.h"

class likelihoodGetter  {
  
 public:
  likelihoodGetter ( std::string & file_name, std::string & m_rcut_factor, std::vector<std::string> & variables, std::vector<std::string> & signals );
  ~likelihoodGetter();
  
  double getLikelihood    ( std::vector<double> & values );
  double getLogLikelihood ( std::vector<double> & values );

 private:
  
  const int m_n_variables;
  const int m_n_signals;

  std::vector<std::string> m_variables;  
  std::vector<std::string> m_signals;
  
  TFile * m_file;
  std::string m_file_name ;
  std::string m_rcut_factor; 
  
  std::vector<TH1F*> m_background_hists;  
  std::vector<std::vector<TH1F*> > m_signal_hists;
  
};

#endif
