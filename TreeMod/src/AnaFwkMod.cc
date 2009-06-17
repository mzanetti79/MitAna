// $Id: AnaFwkMod.cc,v 1.10 2009/03/28 14:39:56 loizides Exp $

#include "MitAna/TreeMod/interface/AnaFwkMod.h"
#include "MitAna/DataUtil/interface/Debug.h"
#include "MitAna/DataTree/interface/Names.h"
#include <TFile.h>
#include <TH1D.h>
#include <TStopwatch.h>
#include <TTree.h>

using namespace mithep;

ClassImp(mithep::AnaFwkMod)

//--------------------------------------------------------------------------------------------------
AnaFwkMod::AnaFwkMod(const char *name, const char *title) : 
  BaseMod(name,title),
  fAllHeadTreeName(Names::gkAllEvtTreeName),
  fAllHeadBrName(Names::gkAllEvtHeaderBrn),
  fSkipNEvents(0),
  fSWtotal(0),
  fSWevent(0),
  fAllHeaders(0,Names::gkSkimmedHeaders),
  fAllHeadTree(0),
  fAllEventHeader(0),
  fReload(kFALSE),
  fCurEnt(-2),
  fNEventsSkimmed(0),
  fNEventsSkipped(0)
{
  // Constructor.
}

//--------------------------------------------------------------------------------------------------
void AnaFwkMod::BeginRun()
{
  // Get HLT tree and set branches if new file was opened. Read next entry in HLT key
  // depending on entry in RunInfo.

  if (fReload) {
    // reset to be (re-)loaded variables
    fReload         = 0;
    fAllHeadTree    = 0;
    fAllEventHeader = 0;
    fCurEnt         = 0;

    // get current file
    TFile *file = GetCurrentFile();
    if (!file) 
      return;

    // get all event header tree
    fAllHeadTree = dynamic_cast<TTree*>(file->Get(fAllHeadTreeName));
    if (!fAllHeadTree) {
      SendError(kWarning, "BeginRun",
                "Cannot find tree '%s' in file '%s'", 
                fAllHeadTreeName.Data(),file->GetName());
      return;
    }

    // get all event header branch
    if (fAllHeadTree->GetBranch(fAllHeadBrName)) {
      fAllHeadTree->SetBranchAddress(fAllHeadBrName, &fAllEventHeader);
    } else {
      SendError(kWarning, "BeginRun",
                "Cannot find branch '%s' in tree '%s'", 
                fAllHeadBrName.Data(), fAllHeadTreeName.Data());
      return;
    }
  }
}

//--------------------------------------------------------------------------------------------------
void AnaFwkMod::CopyAllEventHeaders()
{
  // Deal with the headers from all events if needed.

  fAllHeaders.Reset();

  const EventHeader *curev = GetEventHeader();
  if (!curev) {
    SendError(kWarning, "CopyAllEventHeaders", "Cannot obtain current event");
    return;
  }

  if (fAllHeadTree) {
    const Int_t nemax = fAllHeadTree->GetEntries();
    if (fCurEnt == nemax) {
      SendError(kAbortEvent, "CopyAllEventHeaders", 
                "End of all events tree reached (%d=%d)", fCurEnt, nemax);
      return;
    }
    fAllHeadTree->GetEntry(fCurEnt++);
    while(fCurEnt<=nemax && fAllEventHeader->Skimmed()) {
      EventHeader *eh = fAllHeaders.AddNew();
      eh->SetRunNum(fAllEventHeader->RunNum());
      eh->SetEvtNum(fAllEventHeader->EvtNum());
      eh->SetLumiSec(fAllEventHeader->LumiSec());
      eh->SetRunEntry(fAllEventHeader->RunEntry());
      eh->SetSkimmed(fAllEventHeader->Skimmed());
      fAllHeadTree->GetEntry(fCurEnt++);
    }
    if ((fAllEventHeader->RunNum()!=curev->RunNum())   ||
        (fAllEventHeader->EvtNum()!=curev->EvtNum())   ||
        (fAllEventHeader->LumiSec()!=curev->LumiSec()) ||
        (fAllEventHeader->RunEntry()!=curev->RunEntry())) {
      SendError(kWarning, "CopyAllEventHeaders", 
                "Event header information for entry %d inconsistent: "
                "%d==%d, %d==%d, %d==%d, %d==%d",
                fCurEnt,
                fAllEventHeader->RunNum(),   curev->RunNum(), 
                fAllEventHeader->EvtNum(),   curev->EvtNum(),
                fAllEventHeader->LumiSec(),  curev->LumiSec(),
                fAllEventHeader->RunEntry(), curev->RunEntry());
      return;
    }

    // read-ahead to check if more events are coming
    if (fCurEnt<nemax) { 
      Int_t testEnt = fCurEnt;
      fAllHeadTree->GetEntry(testEnt++);
      while(testEnt<=nemax && fAllEventHeader->Skimmed())
        fAllHeadTree->GetEntry(testEnt++);
      if (testEnt==nemax+1) { // need to add remaining skimmed events
        fAllHeadTree->GetEntry(fCurEnt++);
        while(fCurEnt<=nemax) {
          EventHeader *eh = fAllHeaders.AddNew();
          eh->SetRunNum(fAllEventHeader->RunNum());
          eh->SetEvtNum(fAllEventHeader->EvtNum());
          eh->SetLumiSec(fAllEventHeader->LumiSec());
          eh->SetRunEntry(fAllEventHeader->RunEntry());
          eh->SetSkimmed(fAllEventHeader->Skimmed());
          fAllHeadTree->GetEntry(fCurEnt++);
        }
        if (fCurEnt != nemax+1) {
          SendError(kAbortEvent, "CopyAllEventHeaders", 
                    "End of all events tree unexpectedly not reached (%d!=%d)", fCurEnt, nemax);
          return;
        }
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------
Bool_t AnaFwkMod::Notify()
{
  // Make sure to get the new "AllEvents" tree when the file changes.

  fReload = kTRUE;
  return kTRUE;
}

//--------------------------------------------------------------------------------------------------
void AnaFwkMod::Process()
{
  // Do event skipping and counting and print out timing information.

  // counting processed events
  IncNEventsProcessed();
  
  // get skimmed event headers
  CopyAllEventHeaders();
  fNEventsSkimmed += fAllHeaders.GetEntries();

  // check if events should be skipped
  if (fNEventsSkipped<fSkipNEvents) {
    ++fNEventsSkipped;
    MDB(kAnalysis, 3) {
      Info("Process", "Skipping (aborting) %d out of %d first events.",
           fNEventsSkipped, fSkipNEvents);
    }
    AbortEvent();
    return;
  }

  // check if printout should be done
  Bool_t doPrint = 0;

  MDB(kAnalysis, 4) {
    if (GetNEventsProcessed() % 100  == 0) 
      doPrint = 1;
  } else {
    MDB(kAnalysis, 3) {
      if (GetNEventsProcessed() % 1000  == 0) 
        doPrint = 1;
    } else {
      MDB(kAnalysis, 2) {
        if (GetNEventsProcessed() % 10000  == 0) 
          doPrint = 1;
      } else {
        MDB(kAnalysis, 1) {
          if (GetNEventsProcessed() % 100000 == 0) 
            doPrint = 1;
        } 
      }
    }
  }

  if (doPrint) {
    fSWevent->Stop();
    Info("Process", 
         "Events %d -> %.2gs real, %.2gs cpu (%.2g real, %.2g cpu per event)", 
         GetNEventsProcessed(), fSWevent->RealTime(), fSWevent->CpuTime(),
         fSWevent->RealTime()/GetNEventsProcessed(), 
         fSWevent->CpuTime()/GetNEventsProcessed());
    fSWevent->Start();
  }  
}

//--------------------------------------------------------------------------------------------------
void AnaFwkMod::SlaveBegin()
{
  // Book our histogram and start the stop watches.

  fSWtotal = new TStopwatch;
  fSWevent = new TStopwatch;

  if (!PublishObj(&fAllHeaders)) {
    SendError(kAbortAnalysis, "SlaveBegin", 
              "Could not publish all event headers with name %s.", fAllHeaders.GetName());
    return;
  }
}

//--------------------------------------------------------------------------------------------------
void AnaFwkMod::SlaveTerminate()
{
  // Fill event histogram and printout timing information.

  RetractObj(fAllHeaders.GetName());

  SaveNEventsProcessed();
  TH1D *hDAllEvents = new TH1D("hDAllEvents","Sum of processed and skimmed events",1,-0.5,0.5);
  hDAllEvents->Fill(0.0,fNEventsSkimmed+GetNEventsProcessed());
  hDAllEvents->SetEntries(fNEventsSkimmed+GetNEventsProcessed());
  AddOutput(hDAllEvents);

  TH1D *hDSkippedEvents = new TH1D("hDSkippedEvents","Number of skipped events",1,-0.5,0.5);
  hDSkippedEvents->Fill(0.0,fNEventsSkipped);
  hDSkippedEvents->SetEntries(fNEventsSkipped);
  AddOutput(hDSkippedEvents);

  fSWtotal->Stop();
  fSWevent->Stop();

  MDB(kAnalysis, 1)
    Info("SlaveTerminate", 
         "Events %d -> %.2gs real, %.2gs cpu (%.2gs real, %.2gs cpu per event)",
         GetNEventsProcessed(), fSWtotal->RealTime(), fSWtotal->CpuTime(),
         fSWtotal->RealTime()/GetNEventsProcessed(), 
         fSWtotal->CpuTime()/GetNEventsProcessed());

  delete fSWtotal;
  delete fSWevent;
}
