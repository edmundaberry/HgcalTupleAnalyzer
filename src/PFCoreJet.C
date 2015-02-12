#include "PFCoreJet.h"
#include "TMatrixDSym.h"
#include "TMatrixDSymEigen.h"

// Constructors

PFCoreJet::PFCoreJet():
  Object(),
  m_sigma ( -999.0 ),
  m_ptd   ( -999.0 ),
  m_pt    ( -999.0 )
{}

PFCoreJet::PFCoreJet(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFCoreJet"),
  m_sigma ( -999.0 ),
  m_ptd   ( -999.0 ),
  m_pt    ( -999.0 )
{}

// Kinematic variables

double & PFCoreJet::Rho               ()      { return m_collection -> GetData() -> rho; }
double & PFCoreJet::Area              ()      { return m_collection -> GetData() -> PFAK1p5JetArea            -> at ( m_raw_index );    }
double & PFCoreJet::PtRaw             ()      { return m_collection -> GetData() -> PFAK1p5JetPt              -> at ( m_raw_index );    }
double & PFCoreJet::Pt                ()      { m_pt = ( PtRaw() - ( Area() * Rho ())); return m_pt; }
double & PFCoreJet::Eta               ()      { return m_collection -> GetData() -> PFAK1p5JetEta             -> at ( m_raw_index );    } 
double & PFCoreJet::Phi               ()      { return m_collection -> GetData() -> PFAK1p5JetPhi             -> at ( m_raw_index );    }
double & PFCoreJet::RawMass           ()      { return m_collection -> GetData() -> PFAK1p5JetRawMass         -> at ( m_raw_index );    }
double & PFCoreJet::Energy            ()      { return m_collection -> GetData() -> PFAK1p5JetEnergy          -> at ( m_raw_index );    }

// PF Candidate variables

PFCand PFCoreJet::getPFCandidate ( int i ){
  int pf_cand_index = m_collection -> GetData() -> PFAK1p5JetPFCandIndices -> at ( m_raw_index )[i];
  PFCand retval ( * m_collection, pf_cand_index );
  return retval;
}

int PFCoreJet::getNPFCandidates(){
  return m_collection -> GetData() -> PFAK1p5JetPFCandIndices -> at ( m_raw_index ).size();
}

double PFCoreJet::getWidth() { 
  if ( m_sigma < -10. ) calculateDiscriminants();
  return m_sigma;
}

double PFCoreJet::getChargedWidth() { 
  if ( m_sigma_charged < -10. ) calculateDiscriminants();
  return m_sigma_charged;
}

double PFCoreJet::getNeutralWidth() { 
  if ( m_sigma_neutral < -10. ) calculateDiscriminants();
  return m_sigma_neutral;
}

double PFCoreJet::getPTD() { 
  if ( m_ptd < -10. ) calculateDiscriminants();
  return m_ptd;
}

double PFCoreJet::getWeightedDepth(){
  /*
  int nPFCand = getNPFCandidates();

  double sumE2xD = 0.;
  double sumE2   = 0.;

  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){

    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCEEClusters  = pfcand.getNHGCEEClusters  ();
    int nHGCHEFClusters = pfcand.getNHGCHEFClusters ();
    int nHGCHEBClusters = pfcand.getNHGCHEBClusters ();

    for (int iHGCEECluster = 0; iHGCEECluster < nHGCEEClusters; ++iHGCEECluster){
      HGCEECluster cluster = pfcand.getHGCEECluster(iHGCEECluster);
      int nRecHits = cluster.getNHGCEERecHits();
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCEERecHit r = cluster.getHGCEERecHit(iRecHit);
	sumE2    += ( r.EnergyCorr() * r.EnergyCorr() );
	sumE2xD  += ( r.EnergyCorr() * r.EnergyCorr() * fabs(r.Z()) );
      }
    }

    for (int iHGCHEBCluster = 0; iHGCHEBCluster < nHGCHEBClusters; ++iHGCHEBCluster){
      HGCHEBCluster cluster = pfcand.getHGCHEBCluster(iHGCHEBCluster);
      int nRecHits = cluster.getNHGCHEBRecHits();
      double energy_sum = 0.;
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCHEBRecHit r = cluster.getHGCHEBRecHit(iRecHit);
	sumE2    += ( r.EnergyCorr() * r.EnergyCorr() );
	sumE2xD  += ( r.EnergyCorr() * r.EnergyCorr() * fabs(r.Z()) );
	energy_sum  += r.EnergyCorr();
      }
    }

    for (int iHGCHEFCluster = 0; iHGCHEFCluster < nHGCHEFClusters; ++iHGCHEFCluster){
      HGCHEFCluster cluster = pfcand.getHGCHEFCluster(iHGCHEFCluster);
      int nRecHits = cluster.getNHGCHEFRecHits();
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCHEFRecHit r = cluster.getHGCHEFRecHit(iRecHit);
	sumE2    += ( r.EnergyCorr() * r.EnergyCorr() );
	sumE2xD  += ( r.EnergyCorr() * r.EnergyCorr() * fabs(r.Z()) );
      }
    }
  }

  if ( sumE2 > 0 ){ 
    return sumE2xD / sumE2;
  }
  */
  return -1;
}

double PFCoreJet::getWeightedDepthNoEE(){
  /*
  int nPFCand = getNPFCandidates();

  double sumE2xD = 0.;
  double sumE2   = 0.;

  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){

    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCHEFClusters = pfcand.getNHGCHEFClusters ();
    int nHGCHEBClusters = pfcand.getNHGCHEBClusters ();

    for (int iHGCHEBCluster = 0; iHGCHEBCluster < nHGCHEBClusters; ++iHGCHEBCluster){
      HGCHEBCluster cluster = pfcand.getHGCHEBCluster(iHGCHEBCluster);
      int nRecHits = cluster.getNHGCHEBRecHits();
      double energy_sum = 0.;
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCHEBRecHit r = cluster.getHGCHEBRecHit(iRecHit);
	sumE2    += ( r.EnergyCorr() * r.EnergyCorr() );
	sumE2xD  += ( r.EnergyCorr() * r.EnergyCorr() * fabs(r.Z()) );
	energy_sum  += r.EnergyCorr();
      }
    }

    for (int iHGCHEFCluster = 0; iHGCHEFCluster < nHGCHEFClusters; ++iHGCHEFCluster){
      HGCHEFCluster cluster = pfcand.getHGCHEFCluster(iHGCHEFCluster);
      int nRecHits = cluster.getNHGCHEFRecHits();
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCHEFRecHit r = cluster.getHGCHEFRecHit(iRecHit);
	sumE2    += ( r.EnergyCorr() * r.EnergyCorr() );
	sumE2xD  += ( r.EnergyCorr() * r.EnergyCorr() * fabs(r.Z()) );
      }
    }
  }

  if ( sumE2 > 0 ){ 
    return sumE2xD / sumE2;
  }
  */
  return -1;
}

double PFCoreJet::getMaxRHDepth(){ 
  int nPFCand = getNPFCandidates();
  double max = -1.;
  /*
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCEE  = pfcand.getNHGCEEClusters  ();
    int nHGCHEF = pfcand.getNHGCHEFClusters ();
    int nHGCHEB = pfcand.getNHGCHEBClusters ();
    
    for (int iHGCEE = 0; iHGCEE < nHGCEE; ++iHGCEE){
      HGCEECluster r = pfcand.getHGCEECluster(iHGCEE);
      if ( fabs(r.D()) > max ) max = fabs(r.D());
    }

    for (int iHGCHEB = 0; iHGCHEB < nHGCHEB; ++iHGCHEB){
      HGCHEBCluster r = pfcand.getHGCHEBCluster(iHGCHEB);
      if ( fabs(r.D()) > max ) max = fabs(r.D());
    }

    for (int iHGCHEF = 0; iHGCHEF < nHGCHEF; ++iHGCHEF){
      HGCHEFCluster r = pfcand.getHGCHEFCluster(iHGCHEF);
      if ( fabs(r.D()) > max ) max = fabs(r.D());
    }
  }
  */
  return max;
}

void PFCoreJet::calculateDiscriminants() { 
  
  // Zero-out sums
  double M11    = 0.;
  double M12    = 0.;
  double M22    = 0.;

  double M11_charged    = 0.;
  double M12_charged    = 0.;
  double M22_charged    = 0.;

  double M11_neutral    = 0.;
  double M12_neutral    = 0.;
  double M22_neutral    = 0.;

  double sumPt2 = 0.;
  double sumPt  = 0.;

  double sumPt2_charged = 0.;
  double sumPt_charged  = 0.;
  double sumPt2_neutral = 0.;
  double sumPt_neutral  = 0.;
  
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


    if ( c.PassUserID_IsCharged(false) ) {
      M11_charged += ( pt2 * dEta2 );
      M22_charged += ( pt2 * dPhi2 );
      M12_charged -= ( pt2 * dEta * dPhi );
      sumPt_charged  += c.Pt();
      sumPt2_charged += pt2;
    } 
    if ( c.PassUserID_IsNeutral(false) ) {
      M11_neutral += ( pt2 * dEta2 );
      M22_neutral += ( pt2 * dPhi2 );
      M12_neutral -= ( pt2 * dEta * dPhi );
      sumPt_neutral  += c.Pt();
      sumPt2_neutral += pt2;
    }


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

  if ( sumPt2_charged > 0. ){

    // Make matrix
    double matrix_entries[4] = { M11_charged, M12_charged, M12_charged, M22_charged };
    TMatrixDSym matrix ( 2, matrix_entries );
    TMatrixDSymEigen eigen_matrix ( matrix );
  
    // Get eigen values
    TVectorD eigen_values = eigen_matrix.GetEigenValues();
    double eigen_value1 = eigen_values[0];
    double eigen_value2 = eigen_values[1];
    
    double sigma_major = sqrt(eigen_value1 / sumPt2);
    double sigma_minor = sqrt(eigen_value1 / sumPt2);
    m_sigma_charged = sqrt( sigma_major * sigma_major + sigma_minor * sigma_minor );  
  }
  
  else { 
    m_sigma_charged = -1.0;
  }


  if ( sumPt2_neutral > 0. ){

    // Make matrix
    double matrix_entries[4] = { M11_neutral, M12_neutral, M12_neutral, M22_neutral };
    TMatrixDSym matrix ( 2, matrix_entries );
    TMatrixDSymEigen eigen_matrix ( matrix );
  
    // Get eigen values
    TVectorD eigen_values = eigen_matrix.GetEigenValues();
    double eigen_value1 = eigen_values[0];
    double eigen_value2 = eigen_values[1];
    
    double sigma_major = sqrt(eigen_value1 / sumPt2);
    double sigma_minor = sqrt(eigen_value1 / sumPt2);
    m_sigma_neutral = sqrt( sigma_major * sigma_major + sigma_minor * sigma_minor );  
  }
  
  else { 
    m_sigma_neutral = -1.0;
  }

  // Calculate ptD
  if ( sumPt > 0. ){
    m_ptd = sqrt ( sumPt2 ) / sumPt;  
  }
  
  else { 
    m_ptd = -1.0;
  }
}

double PFCoreJet::getEEEnergy(){

  int nPFCand = getNPFCandidates();
  double max = -1.;
  
  double HGCEE_energy = 0.;
  /*
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCEEClusters = pfcand.getNHGCEEClusters();
    
    for (int iHGCEECluster = 0; iHGCEECluster < nHGCEEClusters; ++iHGCEECluster){
      HGCEECluster cluster = pfcand.getHGCEECluster(iHGCEECluster);
      HGCEE_energy += cluster.Energy();
    }
  }
  */
  return HGCEE_energy;
    
}


double PFCoreJet::getHEBEnergy(){

  int nPFCand = getNPFCandidates();
  double max = -1.;
  
  double HGCHEB_energy = 0.;
  /*
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);

    int nHGCHEBClusters = pfcand.getNHGCHEBClusters();

    for (int iHGCHEBCluster = 0; iHGCHEBCluster < nHGCHEBClusters; ++iHGCHEBCluster){
      HGCHEBCluster cluster = pfcand.getHGCHEBCluster(iHGCHEBCluster);
      HGCHEB_energy += cluster.Energy();
    }
  }
  */
  return HGCHEB_energy;
    
}

double PFCoreJet::getHEFEnergy(){

  int nPFCand = getNPFCandidates();
  double max = -1.;
  
  double HGCHEF_energy = 0.;
  /*
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCHEFClusters = pfcand.getNHGCHEFClusters();
    
    for (int iHGCHEFCluster = 0; iHGCHEFCluster < nHGCHEFClusters; ++iHGCHEFCluster){
      HGCHEFCluster cluster = pfcand.getHGCHEFCluster(iHGCHEFCluster);
      HGCHEF_energy += cluster.Energy();
    }
  }
  */
  return HGCHEF_energy;
    
}


double PFCoreJet::getHEFEnergy(int min_layer, int max_layer){

  int nPFCand = getNPFCandidates();
  double max = -1.;
  
  double HGCHEF_energy = 0.;
  /*
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCHEFClusters = pfcand.getNHGCHEFClusters();
    
    for (int iHGCHEFCluster = 0; iHGCHEFCluster < nHGCHEFClusters; ++iHGCHEFCluster){
      HGCHEFCluster cluster = pfcand.getHGCHEFCluster(iHGCHEFCluster);
      
      int nRecHits = cluster.getNHGCHEFRecHits();
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCHEFRecHit r = cluster.getHGCHEFRecHit(iRecHit); 
	if ( r.Layer() < min_layer ) continue;
	if ( r.Layer() > max_layer ) continue;
	HGCHEF_energy += r.EnergyCorr();
      }
    }
  }
  */
  return HGCHEF_energy;
    
}


double PFCoreJet::getEEEnergy(int min_layer, int max_layer){

  int nPFCand = getNPFCandidates();
  double max = -1.;
  
  double HGCEE_energy = 0.;
  /*
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    
    int nHGCEEClusters = pfcand.getNHGCEEClusters();
    
    for (int iHGCEECluster = 0; iHGCEECluster < nHGCEEClusters; ++iHGCEECluster){
      HGCEECluster cluster = pfcand.getHGCEECluster(iHGCEECluster);
      
      int nRecHits = cluster.getNHGCEERecHits();
      for (int iRecHit = 0; iRecHit < nRecHits; ++iRecHit){
	HGCEERecHit r = cluster.getHGCEERecHit(iRecHit); 
	if ( r.Layer() < min_layer ) continue;
	if ( r.Layer() > max_layer ) continue;
	HGCEE_energy += r.EnergyCorr();
      }
    }
  }
  */
  return HGCEE_energy;
    
}


double PFCoreJet::getHGCALEnergy(){
  return getEEEnergy () + getHEFEnergy () + getHEBEnergy ();
}

void PFCoreJet::getProfile ( const int n_radii, double * radii, double * profile ) { 
  
  for (int i_radius = 0; i_radius < n_radii; ++i_radius){
    profile[i_radius] = 0.;
  }
  
  int nPFCand = getNPFCandidates();
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate( iPFCand );
    double dr = DeltaR ( & pfcand );
    for (int i_radius = 0; i_radius < n_radii; ++i_radius){
      double radius = radii[i_radius];
      if ( dr > radius ) continue;
      profile[i_radius] += pfcand.Pt();
    }
  }
  
  for (int i_radius = 0; i_radius < n_radii; ++i_radius){
    profile[i_radius] /= Pt();
  }
 
  return;
}

double PFCoreJet::getProfileRadius( const int n_radii, double * radii, double * profile, double fraction ) { 
  for (int i_radius = 0; i_radius < n_radii; ++i_radius){
    if ( profile[i_radius] > fraction ){
      return radii[i_radius];
    }
  }
  return 0.;
}


double PFCoreJet::getChargedFraction() { 

  double charged_pt = 0.;
  int nPFCand = getNPFCandidates();
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    if ( !pfcand.PassUserID_IsCharged(false)) continue;
    charged_pt += pfcand.Pt();
  }
  if ( Pt() > 0 ) return charged_pt / Pt();
  return 0.;
}

double PFCoreJet::getNeutralFraction() { 

  double neutral_pt = 0.;
  int nPFCand = getNPFCandidates();
  for (int iPFCand = 0; iPFCand < nPFCand; ++iPFCand){
    PFCand pfcand = getPFCandidate(iPFCand);
    if ( !pfcand.PassUserID_IsNeutral(false)) continue;
    neutral_pt += pfcand.Pt();
  }
  if ( Pt() > 0 ) return neutral_pt / Pt();
  return 0.;
}
