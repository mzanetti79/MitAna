//--------------------------------------------------------------------------------------------------
// $Id: Collections.h,v 1.21 2008/09/06 18:02:22 sixie Exp $
//
// Collections
//
// This header file defines the standard types for the collections we want to use.
//
// Authors: C.Loizides
//--------------------------------------------------------------------------------------------------

#ifndef MITANA_DATATREE_COLLECTIONS_H
#define MITANA_DATATREE_COLLECTIONS_H
 
#include "MitAna/DataCont/interface/Collection.h"
#include "MitAna/DataCont/interface/Array.h"
#include "MitAna/DataCont/interface/ObjArray.h"
#include "MitAna/DataCont/interface/RefArray.h"
#include "MitAna/DataCont/interface/Vector.h"

#include "MitAna/DataTree/interface/DataObject.h"
#include "MitAna/DataTree/interface/Track.h"
#include "MitAna/DataTree/interface/BasicCluster.h"
#include "MitAna/DataTree/interface/SuperCluster.h"
#include "MitAna/DataTree/interface/CaloTower.h"
#include "MitAna/DataTree/interface/Particle.h"
#include "MitAna/DataTree/interface/ChargedParticle.h"
#include "MitAna/DataTree/interface/Muon.h"
#include "MitAna/DataTree/interface/Electron.h"
#include "MitAna/DataTree/interface/Jet.h"
#include "MitAna/DataTree/interface/Met.h"
#include "MitAna/DataTree/interface/CompositeParticle.h"
#include "MitAna/DataTree/interface/MCParticle.h"
#include "MitAna/DataTree/interface/DecayParticle.h"
#include "MitAna/DataTree/interface/Conversion.h"
#include "MitAna/DataTree/interface/Photon.h"
#include "MitAna/DataTree/interface/StableParticle.h"
#include "MitAna/DataTree/interface/StableDaughter.h"

namespace mithep 
{
  typedef Collection<DataObject>        DataObjectCol;
  typedef Collection<Track>             TrackCol;
  typedef Collection<BasicCluster>      BasicClusterCol;
  typedef Collection<SuperCluster>      SuperClusterCol;
  typedef Collection<CaloTower>         CaloTowerCol;
  typedef Collection<Particle>          ParticleCol;
  typedef Collection<ChargedParticle>   ChargedParticleCol;
  typedef Collection<Muon>              MuonCol;
  typedef Collection<Electron>          ElectronCol;
  typedef Collection<Jet>               JetCol;
  typedef Collection<Met>               MetCol;
  typedef Collection<CompositeParticle> CompositeParticleCol;
  typedef Collection<MCParticle>        MCParticleCol;
  typedef Collection<DecayParticle>     DecayParticleCol;
  typedef Collection<Conversion>        ConversionCol;
  typedef Collection<Photon>            PhotonCol;
  typedef Collection<StableParticle>    StableParticleCol;
  typedef Collection<StableDaughter>    StableDaughterCol;

  typedef Array<DataObject>             DataObjectArr;
  typedef Array<Track>                  TrackArr;
  typedef Array<BasicCluster>           BasicClusterArr;
  typedef Array<SuperCluster>           SuperClusterArr;
  typedef Array<CaloTower>              CaloTowerArr; 
  typedef Array<Particle>               ParticleArr;
  typedef Array<ChargedParticle>        ChargedParticleArr;
  typedef Array<Muon>                   MuonArr;
  typedef Array<Electron>               ElectronArr;
  typedef Array<Jet>                    JetArr;
  typedef Array<Met>                    MetArr;
  typedef Array<MCParticle>             MCParticleArr;
  typedef Array<CompositeParticle>      CompositeParticleArr;
  typedef Array<DecayParticle>          DecayParticleArr;
  typedef Array<Conversion>             ConversionArr;
  typedef Array<Photon>                 PhotonArr;
  typedef Array<StableParticle>         StableParticleArr;
  typedef Array<StableDaughter>         StableDaughterArr;
}
#endif
