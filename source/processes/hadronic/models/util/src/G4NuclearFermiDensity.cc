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
//

#include "G4NuclearFermiDensity.hh"

G4NuclearFermiDensity::G4NuclearFermiDensity(G4int anA, G4int aZ) 
  :  theA(anA), theZ(aZ), a(0.545 * fermi) 
{
//        const G4double r0=1.14*fermi;
	const G4double r0=1.16 * ( 1. - 1.16 * std::pow(G4double(anA), -2./3.)) * fermi;
	theR= r0 * std::pow(anA, 1./3. );
	Setrho0(3./ (4. * pi * std::pow(r0,3.) * theA * ( 1. + sqr(a/theR)*pi2 )));
}

G4NuclearFermiDensity::~G4NuclearFermiDensity() {}
        

