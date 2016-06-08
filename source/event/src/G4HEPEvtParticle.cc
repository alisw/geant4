// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4HEPEvtParticle.cc,v 1.2 1999/12/15 14:49:40 gunter Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
//

#include "G4HEPEvtParticle.hh"

G4Allocator<G4HEPEvtParticle> aHEPEvtParticleAllocator;

G4HEPEvtParticle::G4HEPEvtParticle()
{;}

G4HEPEvtParticle::G4HEPEvtParticle(G4PrimaryParticle* pp,
        G4int isthep, G4int jdahep1, G4int jdahep2)
:theParticle(pp),ISTHEP(isthep),JDAHEP1(jdahep1),JDAHEP2(jdahep2)
{;}

G4HEPEvtParticle::~G4HEPEvtParticle()
{;}

const G4HEPEvtParticle & 
G4HEPEvtParticle::operator=(const G4HEPEvtParticle &right)
{ return *this; }

int G4HEPEvtParticle::operator==(const G4HEPEvtParticle &right) const
{ return false; }
int G4HEPEvtParticle::operator!=(const G4HEPEvtParticle &right) const
{ return true; }



