//--------------------------------------------------------------------------------------------------
// $Id: GenRelValMod.h,v 1.3 2008/09/10 03:33:29 loizides Exp $
//
// GenRelValMod
//
// This is an analysis module which is used to validate the genparticles filled into the tree.
//
// Authors: C.Loizides
//--------------------------------------------------------------------------------------------------

#ifndef MITANA_VALIDATION_GENRELVAL_H
#define MITANA_VALIDATION_GENRELVAL_H

#include <Riostream.h>
#include "MitAna/TreeMod/interface/BaseMod.h"
#include "MitAna/DataTree/interface/Collections.h"

namespace mithep
{
  class GenRelValMod : public BaseMod
  {
    public:
      GenRelValMod(const char *name  = "GenRelValMod",
                   const char *title = "Analysis Module for GenParticles validation");
      ~GenRelValMod() {}

      void             Process();
      void             SetPrint(Bool_t b) { fPrint = b; }
      void             SetWrite(Bool_t b) { fWrite = b; }
      void             SlaveBegin();
      void             SlaveTerminate();

    protected:
      TString          fMCPartName;   //name of particle collection
      TString          fFileName;     //filename of output
      Bool_t           fPrint;        //=true then print to screen (def=1)
      Bool_t           fWrite;        //=true then write to file (def=0)
      MCParticleCol   *fParticles;    //!particle branch
      std::ofstream   *ofile;         //!output text file

      ClassDef(GenRelValMod,1) // GenParticle validation module
  };
}
#endif
