#ifndef DDAlgorithm_presh_detectors_h
#define DDAlgorithm_presh_detectors_h

#include "DetectorDescription/ExprAlgo/interface/AlgoImpl.h"
//#include "CLHEP/Units/GlobalSystemOfUnits.h"
#define MAX_DOUBLE DBL_MAX
//#include <climits>
//#include <cfloat>

#include <iostream>
#include <vector>
#include <string>

#include "DetectorDescription/Core/interface/DDTransform.h"

class AlgoPos;

//! Algorithm generating rotation, translation & copy-numbers for the ECal-Preshower detectors
class presh_detectors : public AlgoImpl
{
public:

  //! initializes the algorithm 
  /**
    currently, the constructor also builds the various layers of preshower tubes.
    Rotations & translations generated by this algorithm are the ones used for
    placing the wedges & sensitive detectors inside the two 'active' layers of
    the preshower
  */
  presh_detectors(AlgoPos*,std::string label);
  
  //! your comment here ...
  ~presh_detectors();
  
  bool checkParameters();
  
  DDTranslation translation();
  
  DDRotationMatrix rotation();

  int copyno() const;
  
  //void checkTermination();
  
  void stream(std::ostream &) const;
  
private:
  void defineConstants();
  void topHalfXPlane();
  double ZLEAD_;
  double waf_intra_col_sep_, waf_inter_col_sep_;
  double waf_active_, wedge_length_, wedge_offset_, zwedge_ceramic_diff_;
  DDRotation rot_;
  double y_offset_, z_offset_;
  std::vector<int> IQUAD_MAX_, IQUAD_MIN_;
};


#include "DetectorDescription/ExprAlgo/interface/AlgoCheck.h"

class presh_detectorsChecker : public AlgoCheck
{
public:
  presh_detectorsChecker();
  ~presh_detectorsChecker();
};


#endif
