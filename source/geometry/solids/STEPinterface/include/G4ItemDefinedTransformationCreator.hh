// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4ItemDefinedTransformationCreator.hh,v 1.2 2000/01/21 13:45:27 gcosmo Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// ----------------------------------------------------------------------
// Class G4ItemDefinedTransformationCreator
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
#ifndef G4ITEMDEFINEDTRANSFORMATIONCREATOR_HH
#define G4ITEMDEFINEDTRANSFORMATIONCREATOR_HH

#include "G4GeometryCreator.hh"

class G4ItemDefinedTransformationCreator: private G4GeometryCreator 
{
  public:

  // Constructor & destructor

    G4ItemDefinedTransformationCreator();
    ~G4ItemDefinedTransformationCreator();

  // Member functions

    void CreateG4Geometry(STEPentity&);
    void CreateSTEPGeometry(void*);
    G4String Name() { return "Item_Defined_Transformation"; }
    static G4ItemDefinedTransformationCreator GetInstance() { return csc; }

  // Members
  
  private:

    static G4ItemDefinedTransformationCreator csc;
};

#endif