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
// $Id: G4CascadePiPlusNChannel.hh,v 1.3 2010/06/25 09:42:34 gunter Exp $
// GEANT4 tag: $Name: geant4-09-04-beta-01 $

#ifndef G4_CASCADE_PIPLUSN_CHANNEL_HH
#define G4_CASCADE_PIPLUSN_CHANNEL_HH

#include "G4CascadeData.hh"
#include "G4CascadeFunctions.hh"
#include "G4PionNucSampler.hh"

struct G4CascadePiPlusNChannelData {
  typedef G4CascadeData<30,5,13,22,31,6,7,8,9> data_t;
  static data_t data;
};

typedef G4CascadeFunctions<G4CascadePiPlusNChannelData,G4PionNucSampler> G4CascadePiPlusNChannel;

#endif	/* G4_CASCADE_PIPLUSN_CHANNEL_HH */
