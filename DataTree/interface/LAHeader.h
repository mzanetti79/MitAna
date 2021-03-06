//--------------------------------------------------------------------------------------------------
// $Id: LAHeader.h,v 1.6 2008/12/09 17:47:00 loizides Exp $
//
// LAHeader
//
// Look-ahead header information in a very compressed way. Just enough information to figure
// out if the run ends. This class is stored in a dedicated tree.
//
// Authors: C.Loizides
//--------------------------------------------------------------------------------------------------

#ifndef MITANA_DATATREE_LAHEADER_H
#define MITANA_DATATREE_LAHEADER_H
 
#include "MitAna/DataTree/interface/DataBase.h"

namespace mithep 
{
  class LAHeader : public DataBase
  {
    public:
      LAHeader() : fRunNum(0) {}
      LAHeader(UInt_t run) : fRunNum(run) {}

      EObjType            ObjType()      const { return kLAHeader; }      
      UInt_t              RunNum()       const { return fRunNum; }
      void                SetRunNum(UInt_t i)  { fRunNum=i; }

    protected:
      UInt_t              fRunNum;          //run number
      
    ClassDef(LAHeader, 1) // Look-ahead event header class
  };
}
#endif
