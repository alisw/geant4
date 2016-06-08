// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VertexPointCreator.hh,v 1.2 2000/01/21 13:45:39 gcosmo Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// ----------------------------------------------------------------------
// Class G4VertexPointCreator
//
// Class description:
//
//

// Authors: J.Sulkimo, P.Urban.
// Revisions by: L.Broglia, G.Cosmo.
//
// History:
//   18-Nov-1999: First step of re-engineering - G.Cosmo
// ----------------------------------------------------------------------
#ifndef G4VERTEXPOINTCREATOR_HH
#define G4VERTEXPOINTCREATOR_HH

#include "G4GeometryCreator.hh"

class G4VertexPointCreator: private G4GeometryCreator 
{
  public:

  // Constructor & destructor

    G4VertexPointCreator();
    ~G4VertexPointCreator();

  // Member functions

    void CreateG4Geometry(STEPentity&);
    void CreateSTEPGeometry(void* G4obj);
    G4String Name() { return "Vertex_Point"; }
    static G4VertexPointCreator GetInstance() { return csc; }

  // Members

  private:

    static G4VertexPointCreator csc;
};

#endif