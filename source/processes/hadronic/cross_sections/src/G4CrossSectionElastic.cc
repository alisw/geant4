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
// $Id: G4CrossSectionElastic.cc,v 1.2 2010/11/19 11:12:11 vnivanch Exp $
// GEANT4 tag $Name: geant4-09-04 $
//
// -------------------------------------------------------------------
//
// GEANT4 Class file
//
//
// File name:     G4CrossSectionElastic
//
// Author:        Vladimir Ivanchenko
//
// Creation date: 19.11.2010
// Modifications:
//
// Class Description:
//
// Wrapper for elastic cross section build from a component
//
// -------------------------------------------------------------------
//

#include "G4CrossSectionElastic.hh"
#include "G4VComponentCrossSection.hh"
#include "G4ParticleDefinition.hh"

G4CrossSectionElastic::G4CrossSectionElastic(const G4ParticleDefinition* p, 
					     G4VComponentCrossSection* c,
					     G4int zmin, G4int zmax, 
					     G4double Emin, G4double Emax)
  : G4VCrossSectionDataSet(c->GetName()),particle(p), component(c),
    Zmin(zmin),Zmax(zmax)
{
  SetMinKinEnergy(Emin);
  SetMaxKinEnergy(Emax);
}

G4CrossSectionElastic::~G4CrossSectionElastic()
{
  delete component;
}
   
G4bool G4CrossSectionElastic::IsApplicable(const G4DynamicParticle* p, 
					   const G4Element* elm)
{
  return IsIsoApplicable(p, G4int(elm->GetZ()), 0); 
}

G4bool 
G4CrossSectionElastic::IsIsoApplicable(const G4DynamicParticle* p, 
				       G4int Z, G4int)
{
  G4double e = p->GetKineticEnergy();
  return 
    (Z >= Zmin && Z <= Zmax && e >= GetMinKinEnergy() && e <= GetMaxKinEnergy()); 
}


G4double 
G4CrossSectionElastic::GetCrossSection(const G4DynamicParticle* p, 
				       const G4Element* elm, G4double)
{
  return component->GetElasticCrossSection(p->GetDefinition(), 
					   p->GetKineticEnergy(), elm);
}

G4double 
G4CrossSectionElastic::GetZandACrossSection(const G4DynamicParticle* p, G4int Z,
					      G4int A, G4double)
{
  return component->GetElasticZandACrossSection(p->GetDefinition(), 
						p->GetKineticEnergy(), 
						Z, A);
}
