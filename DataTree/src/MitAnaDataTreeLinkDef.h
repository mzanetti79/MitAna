// $Id: MitAnaDataTreeLinkDef.h,v 1.36 2008/09/16 22:08:46 ksung Exp $

#ifndef MITANA_DATATREE_LINKDEF_H
#define MITANA_DATATREE_LINKDEF_H

#include <string>
#include <vector>

#include "MitAna/DataTree/interface/Types.h"
#include "MitAna/DataTree/interface/Names.h"
#include "MitAna/DataTree/interface/Collections.h"

#include "MitAna/DataTree/interface/BitMask.h"
//#include "MitAna/DataTree/interface/BitMask32.h"
//#include "MitAna/DataTree/interface/BitMask64.h"
#include "MitAna/DataTree/interface/EventHeader.h"
#include "MitAna/DataTree/interface/LAHeader.h"
#include "MitAna/DataTree/interface/TriggerName.h"
#include "MitAna/DataTree/interface/RunInfo.h"
#include "MitAna/DataTree/interface/MCEventInfo.h"

#include "MitAna/DataTree/interface/DataObject.h"
#include "MitAna/DataTree/interface/Vertex.h"
#include "MitAna/DataTree/interface/FitVertex.h"
#include "MitAna/DataTree/interface/Track.h"
#include "MitAna/DataTree/interface/BasicCluster.h"
#include "MitAna/DataTree/interface/SuperCluster.h"
#include "MitAna/DataTree/interface/CaloTower.h"

#include "MitAna/DataTree/interface/Particle.h"
#include "MitAna/DataTree/interface/ChargedParticle.h"
#include "MitAna/DataTree/interface/Muon.h"
#include "MitAna/DataTree/interface/Electron.h"
#include "MitAna/DataTree/interface/Jet.h"
#include "MitAna/DataTree/interface/GenJet.h"
#include "MitAna/DataTree/interface/Met.h"
#include "MitAna/DataTree/interface/TriggerObject.h"
#include "MitAna/DataTree/interface/MCParticle.h"
#include "MitAna/DataTree/interface/CompositeParticle.h"
#include "MitAna/DataTree/interface/DecayParticle.h"
#include "MitAna/DataTree/interface/Conversion.h"
#include "MitAna/DataTree/interface/Photon.h"
#include "MitAna/DataTree/interface/StableParticle.h"
#include "MitAna/DataTree/interface/StableDaughter.h"
#endif

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace mithep;

#pragma link C++ class mithep::Names+;

#pragma link C++ class mithep::BitMask<1>+;
#pragma link C++ class mithep::BitMask<2>+;
#pragma link C++ class mithep::BitMask<4>+;
#pragma link C++ class mithep::BitMask<5>+;
#pragma link C++ class mithep::BitMask<6>+;
#pragma link C++ class mithep::BitMask<7>+;
#pragma link C++ class mithep::BitMask<8>+;
#pragma link C++ class mithep::BitMask<32>+;
#pragma link C++ typedef mithep::BitMask8;
#pragma link C++ typedef mithep::BitMask16;
#pragma link C++ typedef mithep::BitMask32;
#pragma link C++ typedef mithep::BitMask40;
#pragma link C++ typedef mithep::BitMask48;
#pragma link C++ typedef mithep::BitMask56;
#pragma link C++ typedef mithep::BitMask64;
#pragma link C++ typedef mithep::BitMask256;
#pragma link C++ class mithep::BitMask32+;
#pragma link C++ class mithep::BitMask64+;
#pragma link C++ class mithep::EventHeader+;
#pragma link C++ class mithep::LAHeader+;
#pragma link C++ class mithep::TriggerName+;
#pragma link C++ class mithep::RunInfo+;
#pragma link C++ class mithep::MCEventInfo+;

#pragma link C++ class mithep::Collection<TRef>+;
#pragma link C++ class mithep::Collection<std::string>+;
#pragma link C++ class mithep::Vector<std::string>+;

#pragma link C++ class mithep::DataObject+;
#pragma link C++ class mithep::Collection<mithep::DataObject>+;
#pragma link C++ class mithep::Array<mithep::DataObject>+;
#pragma link C++ class mithep::ObjArray<mithep::DataObject>+;
#pragma link C++ typedef mithep::DataObjectCol;
#pragma link C++ typedef mithep::DataObjectArr;

#pragma link C++ class mithep::Vertex+;
#pragma link C++ class mithep::FitVertex+;

#pragma link C++ class mithep::Track+;
#pragma link C++ class mithep::Collection<mithep::Track>+;
#pragma link C++ class mithep::Array<mithep::Track>+;
#pragma link C++ class mithep::ObjArray<mithep::Track>+;
#pragma link C++ typedef mithep::TrackCol;
#pragma link C++ typedef mithep::TrackArr;
#pragma link C++ enum mithep::Track::EHitLayer;

#pragma link C++ class mithep::BasicCluster+;
#pragma link C++ class mithep::Collection<mithep::BasicCluster>+;
#pragma link C++ class mithep::Array<mithep::BasicCluster>+;
#pragma link C++ class mithep::ObjArray<mithep::BasicCluster>+;
#pragma link C++ class mithep::RefArray<mithep::BasicCluster>-;
#pragma link C++ typedef mithep::BasicClusterCol;
#pragma link C++ typedef mithep::BasicClusterArr;
#pragma link C++ class mithep::SuperCluster+;
#pragma link C++ class mithep::Collection<mithep::SuperCluster>+;
#pragma link C++ class mithep::Array<mithep::SuperCluster>+;
#pragma link C++ class mithep::ObjArray<mithep::SuperCluster>+;
#pragma link C++ typedef mithep::SuperClusterCol;
#pragma link C++ typedef mithep::SuperClusterArr;

#pragma link C++ class mithep::CaloTower+;
#pragma link C++ class mithep::Collection<mithep::CaloTower>+;
#pragma link C++ class mithep::Array<mithep::CaloTower>+;
#pragma link C++ class mithep::ObjArray<mithep::CaloTower>+;
#pragma link C++ class mithep::RefArray<mithep::CaloTower>-;
#pragma link C++ typedef mithep::CaloTowerCol;
#pragma link C++ typedef mithep::CaloTowerArr;

#pragma link C++ class mithep::Particle+;
#pragma link C++ class mithep::Collection<mithep::Particle>+;
#pragma link C++ class mithep::RefArray<mithep::Particle>-;
#pragma link C++ typedef mithep::ParticleCol;
#pragma link C++ typedef mithep::ParticleArr;

#pragma link C++ class mithep::ChargedParticle+;
#pragma link C++ class mithep::Collection<mithep::ChargedParticle>+;
#pragma link C++ class mithep::ObjArray<mithep::ChargedParticle>+;
#pragma link C++ typedef mithep::ChargedParticleCol;
#pragma link C++ typedef mithep::ChargedParticleArr;

#pragma link C++ class mithep::Muon+;
#pragma link C++ class mithep::Collection<mithep::Muon>+;
#pragma link C++ class mithep::Array<mithep::Muon>+;
#pragma link C++ class mithep::ObjArray<mithep::Muon>+;
#pragma link C++ typedef mithep::MuonCol;
#pragma link C++ typedef mithep::MuonArr;

#pragma link C++ class mithep::Electron+;
#pragma link C++ class mithep::Collection<mithep::Electron>+;
#pragma link C++ class mithep::Array<mithep::Electron>+;
#pragma link C++ class mithep::ObjArray<mithep::Electron>+;
#pragma link C++ typedef mithep::ElectronCol;
#pragma link C++ typedef mithep::ElectronArr;

#pragma link C++ class mithep::Jet+;
#pragma link C++ class mithep::Collection<mithep::Jet>+;
#pragma link C++ class mithep::Array<mithep::Jet>+;
#pragma link C++ class mithep::ObjArray<mithep::Jet>+;
#pragma link C++ typedef mithep::JetCol;
#pragma link C++ typedef mithep::JetArr;

#pragma link C++ class mithep::GenJet+;
#pragma link C++ class mithep::Collection<mithep::GenJet>+;
#pragma link C++ class mithep::Array<mithep::GenJet>+;
#pragma link C++ class mithep::ObjArray<mithep::GenJet>+;
#pragma link C++ typedef mithep::GenJetCol;
#pragma link C++ typedef mithep::GenJetArr;

#pragma link C++ class mithep::Met+;
#pragma link C++ class mithep::Collection<mithep::Met>+;
#pragma link C++ class mithep::Array<mithep::Met>+;
#pragma link C++ class mithep::ObjArray<mithep::Met>+;
#pragma link C++ typedef mithep::MetCol;
#pragma link C++ typedef mithep::MetArr;

#pragma link C++ class mithep::TriggerObjectRel+;
#pragma link C++ class mithep::Collection<mithep::TriggerObjectRel>+;
#pragma link C++ class mithep::Array<mithep::TriggerObjectRel>+;
#pragma link C++ typedef mithep::TriggerObjectRelCol;
#pragma link C++ typedef mithep::TriggerObjectRelArr;

#pragma link C++ class mithep::TriggerObjectBase+;
#pragma link C++ class mithep::Collection<mithep::TriggerObjectBase>+;
#pragma link C++ class mithep::Array<mithep::TriggerObjectBase>+;
#pragma link C++ typedef mithep::TriggerObjectBaseCol;
#pragma link C++ typedef mithep::TriggerObjectBaseArr;

#pragma link C++ class mithep::TriggerObject+;
#pragma link C++ class mithep::Collection<mithep::TriggerObject>+;
#pragma link C++ class mithep::Array<mithep::TriggerObject>+;
#pragma link C++ class mithep::ObjArray<mithep::TriggerObject>+;
#pragma link C++ typedef mithep::TriggerObjectCol;
#pragma link C++ typedef mithep::TriggerObjectArr;
#pragma link C++ enum mithep::TriggerObject::ETriggerObject;

#pragma link C++ class mithep::CompositeParticle+;
#pragma link C++ class mithep::Collection<mithep::CompositeParticle>+;
#pragma link C++ class mithep::Array<mithep::CompositeParticle>+;
#pragma link C++ class mithep::ObjArray<mithep::CompositeParticle>+;
#pragma link C++ typedef mithep::CompositeParticleCol;
#pragma link C++ typedef mithep::CompositeParticleArr;

#pragma link C++ class mithep::MCParticle+;
#pragma link C++ class mithep::Collection<mithep::MCParticle>+;
#pragma link C++ class mithep::Array<mithep::MCParticle>+;
#pragma link C++ class mithep::ObjArray<mithep::MCParticle>+;
#pragma link C++ typedef mithep::MCParticleCol;
#pragma link C++ typedef mithep::MCParticleArr;
#pragma link C++ enum mithep::MCParticle::EPartType;

#pragma link C++ class mithep::DecayParticle+;
#pragma link C++ class mithep::Collection<mithep::DecayParticle>+;
#pragma link C++ class mithep::Array<mithep::DecayParticle>+;
#pragma link C++ class mithep::ObjArray<mithep::DecayParticle>+;
#pragma link C++ typedef mithep::DecayParticleCol;
#pragma link C++ typedef mithep::DecayParticleArr;

#pragma link C++ class mithep::Conversion+;
#pragma link C++ class mithep::Collection<mithep::Conversion>+;
#pragma link C++ class mithep::Array<mithep::Conversion>+;
#pragma link C++ class mithep::ObjArray<mithep::Conversion>+;
#pragma link C++ class mithep::RefArray<mithep::Conversion>-;
#pragma link C++ typedef mithep::ConversionArr;
#pragma link C++ typedef mithep::ConversionCol;

#pragma link C++ class mithep::Photon+;
#pragma link C++ class mithep::Collection<mithep::Photon>+;
#pragma link C++ class mithep::Array<mithep::Photon>+;
#pragma link C++ class mithep::ObjArray<mithep::Photon>+;
#pragma link C++ typedef mithep::PhotonCol;
#pragma link C++ typedef mithep::PhotonArr;

#pragma link C++ class mithep::StableParticle+;
#pragma link C++ class mithep::Collection<mithep::StableParticle>+;
#pragma link C++ class mithep::Array<mithep::StableParticle>+;
#pragma link C++ class mithep::ObjArray<mithep::StableParticle>+;
#pragma link C++ typedef mithep::StableParticleCol;
#pragma link C++ typedef mithep::StableParticleArr;
#pragma link C++ class mithep::StableDaughter+;
#pragma link C++ class mithep::Collection<mithep::StableDaughter>+;
#pragma link C++ class mithep::Array<mithep::StableDaughter>+;
#pragma link C++ class mithep::ObjArray<mithep::StableDaughter>+;
#pragma link C++ typedef mithep::StableDaughterCol;
#pragma link C++ typedef mithep::StableDaughterArr;

#endif
