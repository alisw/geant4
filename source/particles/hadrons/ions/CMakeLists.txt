#------------------------------------------------------------------------------
# CMakeLists.txt
# Module : G4ions
# Package: Geant4.src.G4particles..G4ions
#
# CMakeLists.txt for building a single granular library.
#
# Generated on : 24/9/2010
#
#
#------------------------------------------------------------------------------

if(GEANT4_BUILD_GRANULAR_LIBS)
    include(Geant4MacroLibraryTargets)
    GEANT4_GRANULAR_LIBRARY_TARGET(COMPONENT sources.cmake)
endif()

