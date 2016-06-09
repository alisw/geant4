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
// $Id: ExTGTrackerHit.cc,v 1.2 2010/11/05 08:52:34 gcosmo Exp $
// GEANT4 tag $Name: geant4-09-04 $
//
// ---------------------------------------------------------------------------

#include "ExTGTrackerHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

G4Allocator<ExTGTrackerHit> ExTGTrackerHitAllocator;

// ---------------------------------------------------------------------------

ExTGTrackerHit::ExTGTrackerHit()
{
}

// ---------------------------------------------------------------------------

ExTGTrackerHit::~ExTGTrackerHit()
{
}

// ---------------------------------------------------------------------------

ExTGTrackerHit::ExTGTrackerHit(const ExTGTrackerHit& right)
  : G4VHit()
{
  trackID   = right.trackID;
  chamberNb = right.chamberNb;
  edep      = right.edep;
  pos       = right.pos;
}

// ---------------------------------------------------------------------------

const ExTGTrackerHit& ExTGTrackerHit::operator=(const ExTGTrackerHit& right)
{
  trackID   = right.trackID;
  chamberNb = right.chamberNb;
  edep      = right.edep;
  pos       = right.pos;
  return *this;
}

// ---------------------------------------------------------------------------

G4int ExTGTrackerHit::operator==(const ExTGTrackerHit& right) const
{
  return (this==&right) ? 1 : 0;
}

// ---------------------------------------------------------------------------

void ExTGTrackerHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    G4Circle circle(pos);
    circle.SetScreenSize(2.);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}

// ---------------------------------------------------------------------------

void ExTGTrackerHit::Print()
{
  G4cout << "  trackID: " << trackID << "  chamberNb: " << chamberNb
         << "  energy deposit: " << G4BestUnit(edep,"Energy")
	 << "  position: " << G4BestUnit(pos,"Length") << G4endl;
}

// ---------------------------------------------------------------------------

