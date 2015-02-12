#include "PFCluster.h"

PFCluster::PFCluster():
  Object(),
  m_et (-999.0),
  m_volume(-999.0),
  m_length(-999.0)
{}

PFCluster::PFCluster(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFCluster"),
  m_et (-999.0),
  m_volume(-999.0),
  m_length(-999.0)
{}

double & PFCluster::Et() { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
	
double PFCluster::D () { return ( sqrt(R()*R() + Z()*Z())); }

void PFCluster::calculateVolumeAndLength(){

  int nLayer = 54;
  
  std::vector<double> lengthRecHit(nLayer,0.);
  std::vector<double> rhoRecHit   (nLayer,0.);
  std::vector<double> rhoRecHitSqr(nLayer,0.);
  std::vector<int>    nRecHit     (nLayer,0);

  int nHGCEE  = getNHGCEERecHits ();
  int nHGCHEB = getNHGCHEBRecHits();
  int nHGCHEF = getNHGCHEFRecHits();

  int index;
  double rho, rhoSqr, length;
  
  for (int i = 0; i < nHGCEE; ++i){
    HGCEERecHit r = getHGCEERecHit(i);
    index  = r.Index();
    rhoSqr = r.RhoSqr();
    rho    = sqrt(rhoSqr);
    length = r.Length();

    lengthRecHit[index]  = length;
    rhoRecHit   [index] += rho;
    rhoRecHitSqr[index] += rhoSqr;
    nRecHit     [index] ++;
  }

  for (int i = 0; i < nHGCHEF; ++i){
    HGCHEFRecHit r = getHGCHEFRecHit(i);
    index  = r.Index();
    rhoSqr = r.RhoSqr();
    rho    = sqrt(rhoSqr);
    length = r.Length();
    
    lengthRecHit[index]  = length;
    rhoRecHit   [index] += rho;
    rhoRecHitSqr[index] += rhoSqr;
    nRecHit     [index] ++;
  }

  for (int i = 0; i < nHGCHEB; ++i){
    HGCHEBRecHit r = getHGCHEBRecHit(i);
    index  = r.Index();
    rhoSqr = r.RhoSqr();
    rho    = sqrt(rhoSqr);
    length = r.Length();
    
    lengthRecHit[index]  = length;
    rhoRecHit   [index] += rho;
    rhoRecHitSqr[index] += rhoSqr;
    nRecHit     [index] ++;
  }

  m_volume = 0.;
  m_length = 0.;
  
  for (int i = 0; i < nLayer; ++i){
    if ( nRecHit[i] < 1 ) continue;
    double averageRho    = rhoRecHit[i]    / nRecHit[i];
    double averageRhoSqr = rhoRecHitSqr[i] / nRecHit[i];
    double rhoDiff       = averageRhoSqr - (averageRho * averageRho);
    if(rhoDiff < 1.e-10) continue;
    m_volume += 3.14 * (rhoDiff) * lengthRecHit[i];
    m_length += lengthRecHit[i];
  }

  std::cout << "m_volume = " << m_volume << std::endl;
  
  return;
}



double PFCluster::getVolume(){
  if ( m_volume < -900. ) calculateVolumeAndLength();
  return m_volume;
}


double PFCluster::getLength(){
  if ( m_length < -900. ) calculateVolumeAndLength();
  return m_length;
}
