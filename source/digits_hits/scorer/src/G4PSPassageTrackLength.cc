//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G4PSPassageTrackLength.cc,v 1.2 2010/07/22 07:23:45 taso Exp $
// GEANT4 tag $Name: geant4-09-04 $
//
// G4PSPassageTrackLength
#include "G4PSPassageTrackLength.hh"
#include "G4StepStatus.hh"
#include "G4Track.hh"
#include "G4UnitsTable.hh"

////////////////////////////////////////////////////////////////////////////////
// (Description)
//   This is a primitive scorer class for scoring only track length.
//   The tracks which passed a geometry is taken into account.
// 
//
// Created: 2005-11-14  Tsukasa ASO, Akinori Kimura.
// 2010-07-22   Introduce Unit specification.
// 
///////////////////////////////////////////////////////////////////////////////

G4PSPassageTrackLength::G4PSPassageTrackLength(G4String name, G4int depth)
  :G4VPrimitiveScorer(name,depth),HCID(-1),fCurrentTrkID(-1),fTrackLength(0.),
   weighted(false)
{
    SetUnit("mm");
}

G4PSPassageTrackLength::G4PSPassageTrackLength(G4String name, 
					       const G4String& unit, 
					       G4int depth)
  :G4VPrimitiveScorer(name,depth),HCID(-1),fCurrentTrkID(-1),fTrackLength(0.),
   weighted(false)
{
    SetUnit(unit);
}


G4PSPassageTrackLength::~G4PSPassageTrackLength()
{;}

G4bool G4PSPassageTrackLength::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{

  if ( IsPassed(aStep) ) {
    G4int index = GetIndex(aStep);
    EvtMap->add(index,fTrackLength);
  }

  return TRUE;
}

G4bool G4PSPassageTrackLength::IsPassed(G4Step* aStep){
  G4bool Passed = FALSE;

  G4bool IsEnter = aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary;
  G4bool IsExit  = aStep->GetPostStepPoint()->GetStepStatus() == fGeomBoundary;

  G4int  trkid  = aStep->GetTrack()->GetTrackID();
  G4double trklength  = aStep->GetStepLength();
  if(weighted) trklength *= aStep->GetPreStepPoint()->GetWeight();

  if ( IsEnter &&IsExit ){         // Passed at one step
    fTrackLength = trklength;      // Track length is absolutely given.
    Passed = TRUE;                 
  }else if ( IsEnter ){            // Enter a new geometry
    fCurrentTrkID = trkid;         // Resetting the current track.
    fTrackLength  = trklength;     
  }else if ( IsExit ){             // Exit a current geometry
    if ( fCurrentTrkID == trkid ) {
      fTrackLength  += trklength;  // Adding the track length to current one,
      Passed = TRUE;               // if the track is same as entered.
    }
  }else{                           // Inside geometry
    if ( fCurrentTrkID == trkid ){ // Adding the track length to current one ,
      fTrackLength  += trklength;  // if the track is same as entered.
    }
  }

  return Passed;
}

void G4PSPassageTrackLength::Initialize(G4HCofThisEvent* HCE)
{
  fCurrentTrkID = -1;

  EvtMap = new G4THitsMap<G4double>(detector->GetName(),GetName());
  if ( HCID < 0 ) HCID = GetCollectionID(0);
  HCE->AddHitsCollection(HCID,EvtMap);
}

void G4PSPassageTrackLength::EndOfEvent(G4HCofThisEvent*)
{;}

void G4PSPassageTrackLength::clear(){
  EvtMap->clear();
}

void G4PSPassageTrackLength::DrawAll()
{;}

void G4PSPassageTrackLength::PrintAll()
{
  G4cout << " MultiFunctionalDet  " << detector->GetName() << G4endl;
  G4cout << " PrimitiveSenstivity " << GetName() << G4endl;
  G4cout << " Number of entries " << EvtMap->entries() << G4endl;
  std::map<G4int,G4double*>::iterator itr = EvtMap->GetMap()->begin();
  for(; itr != EvtMap->GetMap()->end(); itr++) {
    G4cout << "  copy no.: " << itr->first
	   << "  track length : " 
	   << *(itr->second)/GetUnitValue()
	   << " [" << GetUnit()<< "]"
	   << G4endl;
  }
}

void G4PSPassageTrackLength::SetUnit(const G4String& unit)
{
    CheckAndSetUnit(unit,"Length");
}
