// $Id: Muon.h,v 1.1 2008/06/04 09:08:36 loizides Exp $

#ifndef DATATREE_MUON_H
#define DATATREE_MUON_H
 
#include "MitAna/DataTree/interface/Lepton.h"

//--------------------------------------------------------------------------------------------------
//
// Muon
//
// Details to be worked out...
//
// Authors: C.Loizides, J. Bendavid
//
//--------------------------------------------------------------------------------------------------

namespace mithep 
{
  class Muon : public Lepton
  {
    public:
      Muon() {}
      ~Muon() {}
      
      Muon(Double_t x, Double_t y, Double_t z, Double_t t) {fFourVector.SetXYZT(x,y,z,t);}
      
      ClassDef(Muon, 1) // Muon class
  };
   
} /*namespace mithep*/

#endif /*DATATREE_MUON_H*/
