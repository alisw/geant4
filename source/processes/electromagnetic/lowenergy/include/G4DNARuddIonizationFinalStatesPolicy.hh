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
// $Id: G4DNARuddIonizationFinalStatesPolicy, 2005/09/19 19:06:45 Ziad FRANCIS
// GEANT4 tag $Name: emlowen-V07-01-10

#ifndef  G4DNARuddIonizationFinalStatesPolicy_HH
#define  G4DNARuddIonizationFinalStatesPolicy_HH 1

 #include "G4DNACrossSectionDataSet.hh"

 // IncomingParticlePolicy must provide:
 //  - [protected] const G4ParticleDefinition * IncomingParticleDefinition(void);

 // EnergyLimitsPolicy must provide:
 //  - [protected] const double lowEnergyLimit
 //  - [protected] const double zeroBelowLowEnergyLimit
 //  - [protected] const double highEnergyLimit
 //  - [protected] const double zeroAboveLowEnergyLimit

 template <typename EnergyLimitsPolicy, typename IncomingParticlePolicy>
 class G4DNARuddIonizationFinalStatesPolicy : public EnergyLimitsPolicy, public IncomingParticlePolicy
 {
  protected:
                                        G4DNARuddIonizationFinalStatesPolicy() {}
                                       ~G4DNARuddIonizationFinalStatesPolicy() {}


  G4bool                                KillIncomingParticle(G4double energy) const;
  void                                  BuildFinalStatesData(void) const;
  G4double                              RandomizeEjectedElectronEnergy(G4double incomingParticleEnergy, G4int shell) const;
  void                                  RandomizeEjectedElectronDirection(G4double incomingParticleEnergy, G4double
                                        outgoingParticleEnergy, G4double & cosTheta, G4double & phi ) const;
  G4double                              EnergyConstant(G4int ionizationLevel) const;

  private:
  G4double                             DifferentialCrossSection(G4double k, G4double energyTransfer, G4int shell) const;
  G4double                             CorrectionFactor(G4double k) const;

   // Hides default constructor and assignment operator as private
                                        G4DNARuddIonizationFinalStatesPolicy(const G4DNARuddIonizationFinalStatesPolicy & copy);
   G4DNARuddIonizationFinalStatesPolicy & operator=(const G4DNARuddIonizationFinalStatesPolicy & right);
 };

 #include "G4DNARuddIonizationFinalStatesPolicy.icc"
#endif /* G4DNARuddIonizationFinalStatesPolicy_HH */

