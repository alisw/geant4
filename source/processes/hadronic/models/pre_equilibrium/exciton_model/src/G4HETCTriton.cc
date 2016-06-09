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
// $Id: G4HETCTriton.cc,v 1.4 2010/08/28 15:16:55 vnivanch Exp $
// GEANT4 tag $Name: geant4-09-04 $
//
// by V. Lara
//
// Modified:
// 23.08.2010 V.Ivanchenko general cleanup, move constructor and destructor 
//            the source, use G4Pow

#include "G4HETCTriton.hh"
#include "G4Triton.hh"

G4HETCTriton::G4HETCTriton() 
  : G4HETCChargedFragment(G4Triton::Triton(), &theTritonCoulombBarrier)
{}

G4HETCTriton::~G4HETCTriton() 
{}

G4double G4HETCTriton::GetAlpha()
{
  G4double C = 0.0;
  G4int aZ = GetZ() + GetRestZ();
  if (aZ >= 70) 
    {
      C = 0.10;
    } 
  else 
    {
      C = ((((0.15417e-06*aZ) - 0.29875e-04)*aZ + 0.21071e-02)*aZ - 0.66612e-01)*aZ + 0.98375; 
    }
  
  return 1.0 + C/3.0;
}
  
G4double G4HETCTriton::GetBeta()
{
  return -GetCoulombBarrier();
}

G4double G4HETCTriton::GetSpinFactor()
{
  // 2s+1
  return 2.0;
}

G4double G4HETCTriton::K(const G4Fragment & aFragment)
{
  // Number of protons in emitted fragment
  G4int Pa = GetZ();
  // Number of neutrons in emitted fragment 
  G4int Na = GetA() - Pa;

  G4int TargetZ = GetRestZ();
  G4int TargetA = GetRestA();
  G4double r = G4double(TargetZ)/G4double(TargetA);

  G4int P = aFragment.GetNumberOfParticles();
  G4int H = aFragment.GetNumberOfHoles();

  G4double result = 0.0;
  if (P > 2)
    {
      result = 3.0/(P*(P-1.0)*(P-2.0)) * 
	(H*(H-1.0)*(H-2.0)*r*(r-1.0)*(r-1.0) +
	 H*(H-1.0)*(2.0*Na*r*(1.0-r)+Pa*(1.0-r)*(1.0-r)) +
	 H*(Na*(Na-1.0)*r+2.0*Na*Pa*(1.0-r)) +
	 Pa*Na*(Na-1.0));

      result /= 3.0*r*(1.0 - r)*(1.0 - r);
    }
  return std::max(0.0,result);
}
