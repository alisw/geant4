// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4ShapeRepresentationCreator.cc,v 1.3 2000/02/25 16:36:20 gcosmo Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 
// ----------------------------------------------------------------------
// Class G4ShapeDefinitionRepresentationCreator
//
// Authors: J.Sulkimo, P.Urban.
// Revisions by: L.Broglia, G.Cosmo.
//
// History:
//   18-Nov-1999: First step of re-engineering - G.Cosmo
// ----------------------------------------------------------------------

#include "G4ShapeRepresentationCreator.hh"
#include "G4GeometryTable.hh"
#include "G4PlacementVector.hh"

G4ShapeRepresentationCreator G4ShapeRepresentationCreator::csc;

G4ShapeRepresentationCreator::G4ShapeRepresentationCreator()
{
  G4GeometryTable::RegisterObject(this);
}

G4ShapeRepresentationCreator::~G4ShapeRepresentationCreator() {}

void G4ShapeRepresentationCreator::CreateG4Geometry(STEPentity& Ent)
{
  STEPentity* TmpEnt = 0;
  G4String attrName("items");
  STEPattribute *Attr = GetNamedAttribute(attrName, Ent);
  EntityAggregate *ea = (EntityAggregate*)Attr->ptr.a;
  void *tmp=0;

  G4int placementCount = ea->EntryCount();
  EntityNode* en = (EntityNode*)ea->GetHead();
  G4PlacementVector *placements = new G4PlacementVector();

  // L. Broglia
  // G4Placement* place;
  G4Axis2Placement3D* place;

  for(G4int a=0;a<placementCount;a++)
    {
      TmpEnt = en->node;

      // L. Broglia
      // place =(G4Placement*)G4GeometryTable::CreateObject(*TmpEnt);
      place =(G4Axis2Placement3D*)G4GeometryTable::CreateObject(*TmpEnt);

      if (place)
        placements->append(place);
      en = (EntityNode*)en->NextNode();
    }
  
  G4int placementNum = placements->entries();
  if (placementNum != placementCount)
    G4cerr << "WARNING - G4ShapeRepresentationCreator::CreateG4Geometry" << G4endl
           << "\tTotal of " << placementNum << " G4Axis2Placement3D components created, out of "
	   << placementCount << " expected !" << G4endl
	   << "\tEntity not correctly instantiated." << G4endl;

  attrName="context_of_items";
  Attr = GetNamedAttribute(attrName, Ent);
  TmpEnt = *Attr->ptr.c;
  tmp =G4GeometryTable::CreateObject(*TmpEnt);

  createdObject = placements;
}

void G4ShapeRepresentationCreator::CreateSTEPGeometry(void* G4obj)
{
}