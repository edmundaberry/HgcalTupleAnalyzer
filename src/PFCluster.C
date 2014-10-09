#include "PFCluster.h"

PFCluster::PFCluster():
  Object(),
  m_et (-1.0) {}

PFCluster::PFCluster(Collection& c, unsigned short i, short j ):
  Object(c,i,"PFCluster"),
  m_et (-1.0) {}

double & PFCluster::Et() { 
  double energy = Energy();
  double eta    = Eta();
  m_et = energy * std::cosh ( eta );
  return m_et;
}
	
double PFCluster::D () { return ( sqrt(R()*R() + Z()*Z())); }
