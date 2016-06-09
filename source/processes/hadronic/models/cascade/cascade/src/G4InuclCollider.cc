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
// $Id: G4InuclCollider.cc,v 1.52 2010/11/24 21:16:17 mkelsey Exp $
// Geant4 tag: $Name: geant4-09-04 $
//
// 20100114  M. Kelsey -- Remove G4CascadeMomentum, use G4LorentzVector directly
// 20100309  M. Kelsey -- Eliminate some unnecessary std::pow()
// 20100413  M. Kelsey -- Pass G4CollisionOutput by ref to ::collide()
// 20100418  M. Kelsey -- Move lab-frame transformation code to G4CollisonOutput
// 20100429  M. Kelsey -- Change "photon()" to "isPhoton()"
// 20100517  M. Kelsey -- Inherit from common base class, make other colliders
//		simple data members, consolidate code
// 20100620  M. Kelsey -- Reorganize top level if-blocks to reduce nesting,
//		use new four-vector conservation check.
// 20100701  M. Kelsey -- Bug fix energy-conservation after equilibrium evap,
//		pass verbosity through to G4CollisionOutput
// 20100714  M. Kelsey -- Move conservation checking to base class, report
//		number of iterations at end
// 20100715  M. Kelsey -- Remove all the "Before xxx" and "After xxx"
//		conservation checks, as the colliders now all do so.  Move
//		local buffers outside while() loop, use new "combined add()"
//		interface for copying local buffers to global.
// 20100716  M. Kelsey -- Drop G4IntraNucleiCascader::setInteractionCase()
// 20100720  M. Kelsey -- Make all the collders pointer members (to reducde
//		external compile dependences).
// 20100915  M. Kelsey -- Move post-cascade colliders to G4CascadeDeexcitation,
//		simplify operational code somewhat
// 20100922  M. Kelsey -- Add functions to select de-excitation method;
//		default is G4CascadeDeexcitation (i.e., built-in modules)
// 20100924  M. Kelsey -- Migrate to integer A and Z
// 20101019  M. Kelsey -- CoVerity report: check dynamic_cast<> for null

#include "G4InuclCollider.hh"
#include "G4CascadeDeexcitation.hh"
#include "G4PreCompoundDeexcitation.hh"
#include "G4CollisionOutput.hh"
#include "G4ElementaryParticleCollider.hh"
#include "G4IntraNucleiCascader.hh"
#include "G4InuclElementaryParticle.hh"
#include "G4InuclNuclei.hh"
#include "G4LorentzConvertor.hh"


G4InuclCollider::G4InuclCollider()
  : G4CascadeColliderBase("G4InuclCollider"),
    theElementaryParticleCollider(new G4ElementaryParticleCollider),
    theIntraNucleiCascader(new G4IntraNucleiCascader),
    theDeexcitation(new G4CascadeDeexcitation) {}

G4InuclCollider::~G4InuclCollider() {
  delete theElementaryParticleCollider;
  delete theIntraNucleiCascader;
  delete theDeexcitation;
}


// Select post-cascade processing (default will be CascadeDeexcitation)

void G4InuclCollider::useCascadeDeexcitation() {
  delete theDeexcitation;
  theDeexcitation = new G4CascadeDeexcitation;
}

void G4InuclCollider::usePreCompoundDeexcitation() {
  delete theDeexcitation;
  theDeexcitation = new G4PreCompoundDeexcitation;
}


// Main action

void G4InuclCollider::collide(G4InuclParticle* bullet, G4InuclParticle* target,
			      G4CollisionOutput& globalOutput) {
  if (verboseLevel) G4cout << " >>> G4InuclCollider::collide" << G4endl;

  // Initialize colliders verbosity
  theElementaryParticleCollider->setVerboseLevel(verboseLevel);
  theIntraNucleiCascader->setVerboseLevel(verboseLevel);
  theDeexcitation->setVerboseLevel(verboseLevel);

  output.setVerboseLevel(verboseLevel);
  DEXoutput.setVerboseLevel(verboseLevel);

  const G4int itry_max = 1000;

  // Particle-on-particle collision; no nucleus involved
  if (useEPCollider(bullet,target)) {
    if (verboseLevel > 2)
      G4cout << " InuclCollider -> particle on particle collision" << G4endl;
 
    theElementaryParticleCollider->collide(bullet, target, globalOutput);
    return;
  }
  
  interCase.set(bullet,target);		// Classify collision type
  if (verboseLevel > 2) {
    G4cout << " InuclCollider -> inter case " << interCase.code() << G4endl;
  }

  if (!interCase.valid()) {
    if (verboseLevel > 1)
      G4cerr << " InuclCollider -> no collision possible " << G4endl;

    globalOutput.trivialise(bullet, target);
    return;
  }

  // Target must be a nucleus
  G4InuclNuclei* ntarget = dynamic_cast<G4InuclNuclei*>(interCase.getTarget());
  if (!ntarget) {
    G4cerr << " InuclCollider -> ERROR target is not a nucleus " << G4endl;

    globalOutput.trivialise(bullet, target);
    return;
  }

  G4int btype = 0;
  G4int ab = 0;
  G4int zb = 0;
  
  if (interCase.hadNucleus()) { 	// particle with nuclei
    G4InuclElementaryParticle* pbullet = 
      dynamic_cast<G4InuclElementaryParticle*>(interCase.getBullet());
    if (!pbullet) {
      G4cerr << " InuclCollider -> ERROR bullet is not a hadron " << G4endl;
      globalOutput.trivialise(bullet, target);
      return;
    } else if (pbullet->isPhoton()) {
      G4cerr << " InuclCollider -> can not collide with photon " << G4endl;
      globalOutput.trivialise(bullet, target);
      return;
    } else {
      btype = pbullet->type();
    } 
  } else { 				// nuclei with nuclei
    G4InuclNuclei* nbullet = 
      dynamic_cast<G4InuclNuclei*>(interCase.getBullet());
    if (!nbullet) {
      G4cerr << " InuclCollider -> ERROR bullet is not a nucleus " << G4endl;
      globalOutput.trivialise(bullet, target);
      return;
    }
    
    ab = nbullet->getA();
    zb = nbullet->getZ();
  }

  G4LorentzConvertor convertToTargetRestFrame(bullet, ntarget);
  G4double ekin = convertToTargetRestFrame.getKinEnergyInTheTRS();
  
  if (verboseLevel > 3) G4cout << " ekin in trs " << ekin << G4endl;

  if (!inelasticInteractionPossible(bullet, target, ekin)) {
    if (verboseLevel > 3)
      G4cout << " InuclCollider -> inelastic interaction is impossible\n"
	     << " due to the coulomb barirer " << G4endl;

    globalOutput.trivialise(bullet, target);
    return;
  }

  // Generate interaction secondaries in rest frame of target nucleus
  convertToTargetRestFrame.toTheTargetRestFrame();
  if (verboseLevel > 3) {
    G4cout << " degenerated? " << convertToTargetRestFrame.trivial()
	   << G4endl;
  }
  
  G4LorentzVector bmom;			// Bullet is along local Z
  bmom.setZ(convertToTargetRestFrame.getTRSMomentum());

  // Need to make copy of bullet with momentum realigned
  G4InuclParticle* zbullet = 0;
  if (interCase.hadNucleus())
    zbullet = new G4InuclElementaryParticle(bmom, btype);
  else
    zbullet = new G4InuclNuclei(bmom, ab, zb);

  G4int itry = 0;
  while (itry < itry_max) {
    itry++;
    if (verboseLevel > 2)
      G4cout << " IntraNucleiCascader itry " << itry << G4endl;

    globalOutput.reset();		// Clear buffers for this attempt
    output.reset();	
    DEXoutput.reset();

    theIntraNucleiCascader->collide(zbullet, target, output);
    
    if (verboseLevel > 1) G4cout << " After Cascade " << G4endl;

    // FIXME:  The code below still does too much copying!  Would rather
    //         remove initial fragment from list (or get it a different way)
    DEXoutput.addOutgoingParticles(output.getOutgoingParticles());
    
    if (output.numberOfOutgoingNuclei() == 1) {	// Residual fragment
      // FIXME:  Making a copy here because of constness issues
      G4InuclNuclei recoil_nucleus = output.getOutgoingNuclei()[0];
      theDeexcitation->collide(0, &recoil_nucleus, DEXoutput);
    }

    if (verboseLevel > 2)
      G4cout << " itry " << itry << " finished, moving to lab frame" << G4endl;

    // convert to the LAB frame and add to final result
    DEXoutput.boostToLabFrame(convertToTargetRestFrame);
    globalOutput.add(DEXoutput);

    // Adjust final state particles to balance momentum and energy
    // FIXME:  This should no longer be necessary!
    globalOutput.setOnShell(bullet, target);
    if (globalOutput.acceptable()) {
      if (verboseLevel) 
	G4cout << " InuclCollider output after trials " << itry << G4endl;
      delete zbullet;
      return;
    }
  }	// while (itry < itry_max)
  
  if (verboseLevel) {
    G4cout << " InuclCollider -> can not generate acceptable inter. after " 
	   << itry_max << " attempts " << G4endl;
  }
  
  globalOutput.trivialise(bullet, target);

  delete zbullet;
  return;
}
