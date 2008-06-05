// $Id: ParticleExampleMod.h,v 1.3 2008/06/05 07:54:21 loizides Exp $

#ifndef TREEMOD_PARTICLEXAMPLEMOD_H
#define TREEMOD_PARTICLEXAMPLEMOD_H

#include "MitAna/TAM/interface/TAModule.h" 
#include "MitAna/DataTree/interface/Collections.h"

class TH1D;

//--------------------------------------------------------------------------------------------------
//
// THIExampleAnaMod
//
// This TAM module shows how to use TAM:
//   See http://www.cmsaf.mit.edu/twiki/bin/view/Software/TAM
//
// Authors: C.Loizides, J.Bendavid
//
//--------------------------------------------------------------------------------------------------

namespace mithep 
{
  class ParticleExampleMod : public TAModule 
  {
    public:
      ParticleExampleMod(const char *name="ParticleExampleMod", 
                         const char *title="Particle example analysis module");
      ~ParticleExampleMod() {}

      void                     Begin();
      void                     Process();
      void                     SlaveBegin();
      void                     SlaveTerminate();
      void                     Terminate();

      void                     SetPartName(const char *n)       { fGenPartName=n; }

    protected:
      GenParticleCol          *fParticles;  //!point to particle branch
      TrackCol		      *fTracks;	//!point to track branch
      MuonCol		      *fMuons;  //!point to muon branch
      ElectronCol	      *fElectrons;  //!point to electron branch

      TString                  fGenPartName;   //name of particle collection
      TString                  fTrackName;   //name of track collection
      TString                  fMuonName;   //name of muon collection
      TString                  fElectronName;   //name of electron collection
      
      TH1D                    *fGenPtHist;     //!Gen pt histogram
      TH1D                    *fGenEtaHist;    //!Gen eta histogram
      TH1D                    *fTrackPtHist;	//!generic track pt histogram
      TH1D                    *fMuonPtHist;     //!Muon pt histogram
      TH1D                    *fMuonEtaHist;    //!Muon eta histogram
      TH1D                    *fMuonTrackPtHist;    //!Muon track pt histogram
      TH1D                    *fMuonTrackPtErrHist;    //!Muon track pt histogram
      TH1D                    *fElectronPtHist;	//!generic electron pt histogram

      ClassDef(ParticleExampleMod,1) // TAM example analysis module
  };

} /*namespace mithep*/

#endif /*TREEMOD_PARTICLEXAMPLEMOD_H*/
