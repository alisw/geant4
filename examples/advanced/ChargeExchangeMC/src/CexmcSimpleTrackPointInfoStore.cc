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
/*
 * ============================================================================
 *
 *       Filename:  CexmcSimpleTrackPointInfoStore.cc
 *
 *    Description:  serialization helper for track point info objects
 *
 *        Version:  1.0
 *        Created:  31.12.2009 14:07:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexey Radkov (), 
 *        Company:  PNPI
 *
 * ============================================================================
 */

#ifdef CEXMC_USE_PERSISTENCY

#include <G4ParticleTable.hh>
#include "CexmcSimpleTrackPointInfoStore.hh"
#include "CexmcTrackPointInfo.hh"
#include "CexmcException.hh"


CexmcSimpleTrackPointInfoStore::CexmcSimpleTrackPointInfoStore()
{
}


CexmcSimpleTrackPointInfoStore::CexmcSimpleTrackPointInfoStore(
                                        const CexmcTrackPointInfo &  tpInfo )
{
    positionLocal = tpInfo.positionLocal;
    positionWorld = tpInfo.positionWorld;
    directionLocal = tpInfo.directionLocal;
    directionWorld = tpInfo.directionWorld;
    momentumAmp = tpInfo.momentumAmp;
    if ( tpInfo.trackId == CexmcInvalidTrackId )
        particlePDGEncoding = 0;
    else
        particlePDGEncoding = tpInfo.particle->GetPDGEncoding();
    trackId = tpInfo.trackId;
    trackType = tpInfo.trackType;
}


CexmcSimpleTrackPointInfoStore::operator CexmcTrackPointInfo() const
{
    G4ParticleDefinition *  particleDefinition(
                    G4ParticleTable::GetParticleTable()->FindParticle(
                                                        particlePDGEncoding ) );
    if ( ! particleDefinition && trackId != CexmcInvalidTrackId )
        throw CexmcException( CexmcWeirdException );

    return CexmcTrackPointInfo( positionLocal, positionWorld, directionLocal,
                        directionWorld, momentumAmp, particleDefinition,
                        trackId, trackType );
}

#endif

