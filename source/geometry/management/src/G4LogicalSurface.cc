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
// $Id: G4LogicalSurface.cc,v 1.1 2010/07/05 09:22:58 gcosmo Exp $
// GEANT4 tag $Name: geant4-09-04 $
//
////////////////////////////////////////////////////////////////////////
// G4LogicalSurface Class Implementation
////////////////////////////////////////////////////////////////////////

#include "G4LogicalSurface.hh"

  ////////////////////////////
  // Constructors & Destructor
  ////////////////////////////

G4LogicalSurface::G4LogicalSurface(const G4String& name,
                                         G4SurfaceProperty* surfaceProperty) 
  : theName(name), theSurfaceProperty(surfaceProperty), theTransRadSurface(0)
{
}

G4LogicalSurface::G4LogicalSurface(const G4LogicalSurface &r)
  : theName(r.theName), theSurfaceProperty(r.theSurfaceProperty),
    theTransRadSurface(r.theTransRadSurface)
{
}

G4LogicalSurface::~G4LogicalSurface()
{
}
