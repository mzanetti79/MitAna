// $Id: TrackingParticleColLinkDef.h,v 1.1 2009/06/15 15:00:15 loizides Exp $

#ifndef MITANA_DATATREE_TRACKINGPARTICLECOLLINKDEF_H
#define MITANA_DATATREE_TRACKINGPARTICLECOLLINKDEF_H

#include "MitAna/DataCont/interface/Ref.h"
#include "MitAna/DataTree/interface/TrackingParticleCol.h"
#endif

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace mithep;

#pragma link C++ class mithep::Ref<mithep::TrackingParticle>+;
#pragma link C++ class mithep::TrackingParticle+;
#pragma link C++ class mithep::Collection<mithep::TrackingParticle>+;
#pragma link C++ class mithep::Array<mithep::TrackingParticle>+;
#pragma link C++ class mithep::ObjArray<mithep::TrackingParticle>+;
#pragma link C++ typedef mithep::TrackingParticleCol;
#pragma link C++ typedef mithep::TrackingParticleArr;
#pragma link C++ typedef mithep::TrackingParticleOArr;
#endif
