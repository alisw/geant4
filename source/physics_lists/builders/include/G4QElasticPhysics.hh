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
// $Id: G4QElasticPhysics.hh,v 1.2 2010/06/04 10:22:14 mkossov Exp $
// GEANT4 tag $Name: geant4-09-04-beta-01 $
//
//---------------------------------------------------------------------------
//
// ClassName:   G4QElasticPhysics
//
// Author: 3 Nov 2010 M. Kossov
//
// Modified:
//
//----------------------------------------------------------------------------
//

#ifndef G4QElasticPhysics_h
#define G4QElasticPhysics_h 1

#include "globals.hh"
#include "G4VPhysicsConstructor.hh"

class G4HadronElastic;
class G4QElastic;

class G4QElasticPhysics : public G4VPhysicsConstructor
{
public: 
  G4QElasticPhysics(const G4String& name = "elastic",
			  G4int ver = 1);
  virtual ~G4QElasticPhysics(){};

public: 
  // This method will be invoked in the Construct() method. 
  // each particle type will be instantiated
  virtual void ConstructParticle();
 
  // This method will be invoked in the Construct() method.
  // each physics process will be instantiated and
  // registered to the process manager of each particle type 
  virtual void ConstructProcess();

private:

  G4HadronElastic* model;
  G4QElastic*      process;

  G4String mname;

  G4int    verbose;
  G4bool   wasActivated;
};

#endif




