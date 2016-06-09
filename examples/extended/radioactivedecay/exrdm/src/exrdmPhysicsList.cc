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
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "exrdmPhysicsList.hh"
#include "exrdmPhysicsListMessenger.hh"

#include "exrdmPhysListParticles.hh"
#include "exrdmPhysListGeneral.hh"
#include "G4EmStandardPhysics.hh"
#include "exrdmPhysListEmLowEnergy.hh"
#include "exrdmPhysListHadron.hh"
#include "G4RegionStore.hh"
#include "G4Region.hh"
#include "G4ProductionCuts.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"

#include "G4UnitsTable.hh"
#include "G4LossTableManager.hh"

#include "HadronPhysicsQGSP_BERT.hh"
#include "HadronPhysicsQGSP_BIC.hh"
#include "HadronPhysicsQGSP_HP.hh"
#include "HadronPhysicsLHEP_BERT.hh"
#include "HadronPhysicsLHEP_BERT_HP.hh"
#include "HadronPhysicsLHEP_BIC.hh"
#include "HadronPhysicsLHEP_BIC_HP.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

exrdmPhysicsList::exrdmPhysicsList() : G4VModularPhysicsList()
{
  G4LossTableManager::Instance();
  defaultCutValue = 1.*mm;
  cutForGamma     = defaultCutValue;
  cutForElectron  = defaultCutValue;
  cutForPositron  = defaultCutValue;

  DetectorCuts = 0;
  TargetCuts   = 0;

  pMessenger = new exrdmPhysicsListMessenger(this);

  SetVerboseLevel(2);
  //default physics
   // Particles
  particleList = new exrdmPhysListParticles("particles");

  // EM physics
  emPhysicsList = new G4EmStandardPhysics("em-standard");
  
  // Had physics (no hadron as default)
  hadPhysicsList =  0;

  // General exrdmPhysics
  generalPhysicsList = new exrdmPhysListGeneral("general");

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

exrdmPhysicsList::~exrdmPhysicsList()
{
  delete pMessenger;
  delete generalPhysicsList;
  delete emPhysicsList;
  if (hadPhysicsList) delete hadPhysicsList;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::ConstructParticle()
{
  particleList->ConstructParticle();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::ConstructProcess()
{
  AddTransportation();
  // em
  emPhysicsList->ConstructProcess();
  //general
  generalPhysicsList->ConstructProcess();
  // had
  if (hadPhysicsList) hadPhysicsList->ConstructProcess();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SelectPhysicsList(const G4String& name)
{
  if (verboseLevel>1) {
    G4cout << "exrdmPhysicsList::SelectPhysicsList: <" << name << ">" << G4endl;
  }
  // default  Had physics
  if (name == "Hadron") {
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new exrdmPhysListHadron("hadron");
  } else if (name == "QGSP_BERT") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsQGSP_BERT("std-hadron");
  } else if (name == "QGSP_BIC") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsQGSP_BIC("std-hadron");
  } else if (name == "QGSP_HP") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsQGSP_HP("std-hadron");
  } else if (name == "LHEP_BERT") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsLHEP_BERT("std-hadron");
  } else if (name == "LHEP_BERT_HP") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsLHEP_BERT_HP("std-hadron");
  } else if (name == "LHEP_BIC") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsLHEP_BIC("std-hadron");
  } else if (name == "LHEP_BIC_HP") {
    if (emPhysicsList) delete emPhysicsList;
    emPhysicsList = new G4EmStandardPhysics();
    if (hadPhysicsList) delete hadPhysicsList;
    hadPhysicsList = new HadronPhysicsLHEP_BIC_HP("std-hadron");
  } else if (name == "LowEnergy_EM") {
    if (!hadPhysicsList ||(hadPhysicsList->GetPhysicsName()=="hadron") ) { 
      if (emPhysicsList) delete emPhysicsList;
      emPhysicsList = new exrdmPhysListEmLowEnergy("lowe-em");
    } else {
      G4cout << "exrdmPhysicsList: using EM comes with Std-hadron" <<G4endl;
    }     
  } else if (name == "Standard_EM") {
    if (!hadPhysicsList ||(hadPhysicsList->GetPhysicsName()=="hadron") ) { 
      if (emPhysicsList) delete emPhysicsList;
      emPhysicsList = new G4EmStandardPhysics();
    } else {
      G4cout << "exrdmPhysicsList: using EM comes with Std-hadron" <<G4endl;
    }
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SetCuts()
{

  SetCutValue(cutForGamma, "gamma");
  SetCutValue(cutForElectron, "e-");
  SetCutValue(cutForPositron, "e+");
  G4cout << "world cuts are set" << G4endl;

  if( !TargetCuts ) SetTargetCut(cutForElectron);
  G4Region* region = (G4RegionStore::GetInstance())->GetRegion("Target");
  region->SetProductionCuts(TargetCuts);
  G4cout << "Target cuts are set" << G4endl;

  if( !DetectorCuts ) SetDetectorCut(cutForElectron);
  region = (G4RegionStore::GetInstance())->GetRegion("Detector");
  region->SetProductionCuts(DetectorCuts);
  G4cout << "Detector cuts are set" << G4endl;

  if (verboseLevel>0) DumpCutValuesTable();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SetCutForGamma(G4double cut)
{
  cutForGamma = cut;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SetCutForElectron(G4double cut)
{
  cutForElectron = cut;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SetCutForPositron(G4double cut)
{
  cutForPositron = cut;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SetTargetCut(G4double cut)
{
  if( !TargetCuts ) TargetCuts = new G4ProductionCuts();

  TargetCuts->SetProductionCut(cut, idxG4GammaCut);
  TargetCuts->SetProductionCut(cut, idxG4ElectronCut);
  TargetCuts->SetProductionCut(cut, idxG4PositronCut);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void exrdmPhysicsList::SetDetectorCut(G4double cut)
{
  if( !DetectorCuts ) DetectorCuts = new G4ProductionCuts();

  DetectorCuts->SetProductionCut(cut, idxG4GammaCut);
  DetectorCuts->SetProductionCut(cut, idxG4ElectronCut);
  DetectorCuts->SetProductionCut(cut, idxG4PositronCut);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
