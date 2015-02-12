#ifndef OBJECT_H
#define OBJECT_H

#include <ostream> 
#include <iostream>
#include "IDTypes.h"
#include "Collection.h"

class Object {
 public:
  Object();
  Object( const Object & );
  Object( Collection& collection,  int raw_index );
  Object( Collection& collection,  int raw_index, const char* name );

  Object( Collection& collection,  int raw_index,  int hlt_filter_index );
  Object( Collection& collection,  int raw_index,  int hlt_filter_index, const char* name );
  ~Object();
  
  const char* Name() const { return m_name; }
  virtual int GetRawIndex() { return m_raw_index; }
  
  virtual double & Pt()  = 0;
  virtual double & Phi() = 0;
  virtual double & Eta() = 0;

  virtual double EnergyResScaleFactor() { return 1.0; }
  virtual double EnergyScaleFactor   () { return 1.0; } 
  virtual double EnergyResScaleError () { return 0.0; }
  
  virtual bool   PassUserID ( ID id, bool verbose ) = 0;
    
  double DeltaR     ( Object * other_object );
  double DeltaPhi   ( Object * other_object );
  double Phi_mpi_pi ( double x ); 

  bool IsGenEBFiducial() ;
  bool IsGenEEFiducial() ;
  bool IsGenElectronFiducial() ;
  bool IsMuonFiducial() ;

  bool IsNULL() ;
  
  template <class AnotherObject>
    bool MatchByDR ( CollectionPtr c, AnotherObject & best_match, double max_dr ) { 
    int size = c -> GetSize();
    double min_dr = 9999.;
    bool match = false;
    for (int i = 0; i < size ; ++i){
      AnotherObject constituent = c -> GetConstituent<AnotherObject> ( i );
      double dr = DeltaR ( & constituent );
      if ( dr < max_dr ) { 
	if ( dr < min_dr ) { 
	  match = true;
	  min_dr = dr;
	  best_match = constituent;
	}
      }
    }
    return match;
  }
  
  
  template <class MyObject>
  CollectionPtr AllMatchesByDR ( CollectionPtr c, double max_dr ) { 
    CollectionPtr new_collection ( new Collection(*(m_collection -> GetData()) ,0 ));
    int size = c -> GetSize();
    double min_dr = 9999.;
    for (int i = 0; i < size ; ++i){
      MyObject constituent = c -> GetConstituent<MyObject> ( i );
      double dr = DeltaR ( & constituent );
      if ( dr < max_dr ) { 
	new_collection -> Append ( constituent.GetRawIndex() );
      }
    }
    return new_collection;
  }
  


 protected:

  Collection * m_collection;
  int m_raw_index;
  int m_hlt_filter_index;
  const char * m_name;

};



#endif 
