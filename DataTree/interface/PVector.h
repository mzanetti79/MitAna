//--------------------------------------------------------------------------------------------------
// $Id: PVector.h,v 1.7 2008/06/18 19:08:14 loizides Exp $
//
// Implementation of Collection interface using std:vector class for pointers pointing
// to allocated objects on heap.
//
// Persistency not tested, likely to not work, ask Constantin for help if you are in trouble.
//
// Authors: C.Loizides
//--------------------------------------------------------------------------------------------------

#ifndef DATATREE_PVECTOR_H
#define DATATREE_PVECTOR_H
 
#include "MitAna/DataTree/interface/Vector.h"

namespace mithep 
{
  template<class ArrayElement>
  class PVector : public Vector<ArrayElement>
  {
    public:
      PVector(UInt_t rsv=0) : Vector<ArrayElement>(0) {}
      PVector(std::vector<ArrayElement> &v) : Vector<ArrayElement>(v) {}
      ~PVector() { Delete(); }

      void                             Reset()                             { Delete(); }

    protected:
      void                             Delete();

    ClassDefT(PVector, 1) // Wrapper around std::vector class
  };
}

//__________________________________________________________________________________________________
template<class ArrayElement>
inline void mithep::PVector<ArrayElement>::Delete()
{
  for (UInt_t i=0; i<Vector<ArrayElement>::GetEntries(); ++i) {
    delete Vector<ArrayElement>::fV[i];
  }
  Vector<ArrayElement>::fV.clear();
}
#endif
