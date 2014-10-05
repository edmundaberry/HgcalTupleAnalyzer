#include "PFPrunedJet.h"
#include "TMatrixDSym.h"
#include "TMatrixDSymEigen.h"

PFPrunedJet::PFPrunedJet():
  Object(),
  m_sigma ( -999.0 ),
  m_ptd   ( -999.0 )
{}

PFPrunedJet::PFPrunedJet(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFPrunedJet"),
  m_sigma ( -999.0 ),
  m_ptd   ( -999.0 )
{}

double PFPrunedJet::getWidth() { 
  if ( m_sigma < -10. ) calculateDiscriminants();
  return m_sigma;
}


double PFPrunedJet::getPTD() { 
  if ( m_ptd < -10. ) calculateDiscriminants();
  return m_ptd;
}


void PFPrunedJet::calculateDiscriminants() { 

  // Zero-out sums
  double M11    = 0.;
  double M12    = 0.;
  double M22    = 0.;
  double sumPt2 = 0.;
  double sumPt  = 0.;
  
  // Loop over constituents
  int n = getNPFCandidates();
  for (int i = 0; i < n; ++i){
    PFCand c = getPFCandidate(i);
    
    double dEta  = c.Eta() - Eta();
    double dPhi  = c.DeltaPhi (this);
    double pt2   = pow (c.Pt(), 2);
    double dEta2 = pow ( dEta, 2 );
    double dPhi2 = pow ( dPhi, 2 );
    M11 += ( pt2 * dEta2 );
    M22 += ( pt2 * dPhi2 );
    M12 -= ( pt2 * dEta * dPhi );

    sumPt  += c.Pt();
    sumPt2 += pt2;
    
  }
  
  // Calculate axes
  double sigma_major = 0.;
  double sigma_minor = 0.;
  
  if ( sumPt2 > 0. ){

    // Make matrix
    double matrix_entries[4] = { M11, M12, M12, M22 };
    TMatrixDSym matrix ( 2, matrix_entries );
    TMatrixDSymEigen eigen_matrix ( matrix );
  
    // Get eigen values
    TVectorD eigen_values = eigen_matrix.GetEigenValues();
    double eigen_value1 = eigen_values[0];
    double eigen_value2 = eigen_values[1];
    
    double sigma_major = sqrt(eigen_value1 / sumPt2);
    double sigma_minor = sqrt(eigen_value1 / sumPt2);
    m_sigma = sqrt( sigma_major * sigma_major + sigma_minor * sigma_minor );  
  }
  
  else { 
    m_sigma = -1.0;
  }

  // Calculate ptD
  if ( sumPt > 0. ){
    m_ptd = sqrt ( sumPt2 ) / sumPt;  
  }
  
  else { 
    m_ptd = -1.0;
  }
}