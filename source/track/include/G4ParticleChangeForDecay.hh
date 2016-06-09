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
// $Id: G4ParticleChangeForDecay.hh,v 1.10 2010/07/21 09:30:15 gcosmo Exp $
// GEANT4 tag $Name: geant4-09-04 $

//
// 
// ------------------------------------------------------------
//	GEANT 4 class header file 
//
// 
// ------------------------------------------------------------
//   Implemented for the new scheme                 23 Mar. 1998  H.Kurahige
//
// Class Description 
//  This class is a concrete class for ParticleChange which
//  has functionality for G4Decay.
//
//  This class contains the results after invocation of the decay process.
//  This includes secondary particles generated by the interaction.
// ------------------------------------------------------------
#ifndef G4ParticleChangeForDecay_h
#define G4ParticleChangeForDecay_h 1

#include "globals.hh"
#include "G4ios.hh"
#include "G4ThreeVector.hh"
class G4DynamicParticle;
#include "G4VParticleChange.hh"

class G4ParticleChangeForDecay: public G4VParticleChange
{
   public:
    // default constructor
    G4ParticleChangeForDecay();

    // destructor
    virtual ~G4ParticleChangeForDecay();

  protected:
    // hide copy constructor and assignment operaor as protected
    G4ParticleChangeForDecay(const G4ParticleChangeForDecay &right);
    G4ParticleChangeForDecay & operator=(const G4ParticleChangeForDecay &right);

  public:
    // equal/unequal operator
    G4bool operator==(const G4ParticleChangeForDecay &right) const;
    G4bool operator!=(const G4ParticleChangeForDecay &right) const;

  public: // with description
    // ----------------------------------------------------
    // --- the following methods are for updating G4Step -----   
    // Return the pointer to the G4Step after updating the Step information
    // by using final state information of the track given by a physics
    // process    
 
    // !!! No effect for  AlongSteyp
    // virtual G4Step* UpdateStepForAlongStep(G4Step* Step);

    virtual G4Step* UpdateStepForAtRest(G4Step* Step);
    virtual G4Step* UpdateStepForPostStep(G4Step* Step);
 
    virtual void Initialize(const G4Track&);
    // Initialize all propoerties by using G4Track information

    G4double GetGlobalTime() const;
    void     ProposeGlobalTime(G4double t);
    //  Get/Propose the final GlobalTime

    G4double GetGlobalTime(G4double timeDelay) const;
    //  Convert the time delay to the global time.

    const G4ThreeVector* GetPolarization() const;
    void  ProposePolarization(G4double Px, G4double Py, G4double Pz);
    void  ProposePolarization(const G4ThreeVector& finalPoralization);
    // Get/Propose the final Polarization vector.

  public:
    virtual void DumpInfo() const;

  protected:
    G4double theTimeChange;
    //  The change of global time of a given particle.

    G4ThreeVector thePolarizationChange;
    //  The changed (final) polarization of a given track
 
 public:
    // for Debug 
    virtual G4bool CheckIt(const G4Track&);
};

inline 
  G4double G4ParticleChangeForDecay::GetGlobalTime() const
{
  return  theTimeChange;
}

inline 
  void G4ParticleChangeForDecay::ProposeGlobalTime(G4double t)
{
  theTimeChange = t;
}
   
inline
 G4double  G4ParticleChangeForDecay::GetGlobalTime(G4double timeDelay) const
{
  //  Convert the time delay to the global time.
  return theTimeChange + timeDelay;
}

inline
 const G4ThreeVector* G4ParticleChangeForDecay::GetPolarization() const
{
  return &thePolarizationChange;
}

inline
 void G4ParticleChangeForDecay::ProposePolarization(const G4ThreeVector& finalPoralization)
{
  thePolarizationChange = finalPoralization;
}

inline
 void G4ParticleChangeForDecay::ProposePolarization(
                                                G4double Px,
                                                G4double Py,
                                                G4double Pz     )
{
  thePolarizationChange.setX(Px);
  thePolarizationChange.setY(Py);
  thePolarizationChange.setZ(Pz);
}

#endif
