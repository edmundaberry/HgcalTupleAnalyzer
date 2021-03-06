#include "GenParticle.h"
#include "Object.h"
#include "IDTypes.h"

// Constructors
GenParticle::GenParticle():
  Object() {}

GenParticle::GenParticle(Collection& c, unsigned int i, int j ):
  Object(c,i,"GenParticle") {}

// Kinematic variables

double & GenParticle::Pt             (){ return m_collection -> GetData() -> GenParticlePt                -> at ( m_raw_index ); }
double & GenParticle::Eta            (){ return m_collection -> GetData() -> GenParticleEta               -> at ( m_raw_index ); } 
double & GenParticle::Phi            (){ return m_collection -> GetData() -> GenParticlePhi               -> at ( m_raw_index ); } 
				     								          
// ID variables		                                                            		          
				     								          
int    GenParticle::PdgId            (){ return m_collection -> GetData() -> GenParticlePdgId             -> at ( m_raw_index ); }
int    GenParticle::Mother1Index     (){ return m_collection -> GetData() -> GenParticleMother1Index      -> at ( m_raw_index ); }
int    GenParticle::Mother2Index     (){ return m_collection -> GetData() -> GenParticleMother2Index      -> at ( m_raw_index ); }
int    GenParticle::Status           (){ return m_collection -> GetData() -> GenParticleStatus            -> at ( m_raw_index ); }
int    GenParticle::NumMother        (){ return m_collection -> GetData() -> GenParticleNumMother         -> at ( m_raw_index ); }
int    GenParticle::HasPartonDaughter(){ return m_collection -> GetData() -> GenParticleHasPartonDaughter -> at ( m_raw_index ); }

int    GenParticle::Mother1PdgId(){ 
  if (NumMother() < 1) return 0;
  return m_collection -> GetData() -> GenParticlePdgId -> at ( Mother1Index());
}

int    GenParticle::Mother2PdgId(){ 
  if (NumMother() < 2) return 0;
  return m_collection -> GetData() -> GenParticlePdgId -> at ( Mother2Index());
}

std::ostream& operator<<(std::ostream& stream, GenParticle& object) {
  stream << object.Name() << " " << ": "
	 << "PDG = " << object.PdgId () << ",\t"
         << "Status = " << object.Status () << ",\t"
	 << "Pt = "  << object.Pt ()    << ",\t"
	 // << "Eta = " << object.Eta()    << ", "
	 // << "Phi = " << object.Phi()    << ", "
	 << "Mother 1 = " << object.Mother1PdgId() << "(" << object.Mother1Index() << "),\t" 
	 << "Mother 2 = " << object.Mother2PdgId() << "(" << object.Mother2Index() << ")";
  return stream;
}

