# - G4emdna-models module build definition

# Define the Geant4 Module.
geant4_add_module(G4emdna-models
  PUBLIC_HEADERS
    G4DNABornAngle.hh
    G4DNABornExcitationModel.hh
    G4DNABornExcitationModel1.hh
    G4DNABornExcitationModel2.hh
    G4DNABornIonisationModel.hh
    G4DNABornIonisationModel1.hh
    G4DNABornIonisationModel2.hh
    G4DNAChampionElasticModel.hh
    G4DNACPA100ElasticModel.hh
    G4DNACPA100ExcitationModel.hh
    G4DNACPA100IonisationModel.hh
    G4DNASmoluchowskiDiffusion.hh
    G4DNASmoluchowskiReactionModel.hh
    G4DNADingfelderChargeDecreaseModel.hh
    G4DNADingfelderChargeIncreaseModel.hh
    G4DNAEmfietzoglouExcitationModel.hh
    G4DNAEmfietzoglouIonisationModel.hh
    G4DNAELSEPAElasticModel.hh
    G4DNAIonElasticModel.hh
    G4DNAIRT.hh
    G4DNAIRTMoleculeEncounterStepper.hh
    G4DNAMeltonAttachmentModel.hh
    G4DNAMillerGreenExcitationModel.hh
    G4DNAMolecularIRTModel.hh
    G4DNAMolecularReaction.hh
    G4DNAMolecularStepByStepModel.hh
    G4DNAMoleculeEncounterStepper.hh
    G4DNARuddAngle.hh
    G4DNARuddIonisationExtendedModel.hh
    G4DNARuddIonisationModel.hh
    G4DNASancheExcitationModel.hh
    G4DNAOneStepThermalizationModel.hh
    G4DNAOneStepThermalizationModel.hpp
    G4DNAPTBIonisationModel.hh
    G4DNAPTBElasticModel.hh
    G4DNAPTBExcitationModel.hh
    G4DNAPTBAugerModel.hh
    G4DNAScreenedRutherfordElasticModel.hh
    G4DNATransformElectronModel.hh
    G4DNAUeharaScreenedRutherfordElasticModel.hh
    G4DNAVacuumModel.hh
    G4LEPTSAttachmentModel.hh
    G4LEPTSDissociationModel.hh
    G4LEPTSElasticModel.hh
    G4LEPTSIonisationModel.hh
    G4LEPTSPositroniumModel.hh
    G4LEPTSRotExcitationModel.hh
    G4LEPTSVibExcitationModel.hh
    G4VLEPTSModel.hh
    G4LEPTSDiffXS.hh
    G4LEPTSDistribution.hh
    G4LEPTSElossDistr.hh
    G4LEPTSExcitationModel.hh
    G4VDNAModel.hh
    G4DNAModelInterface.hh
    G4DNADummyModel.hh
    G4DNADiracRMatrixExcitationModel.hh
    G4DNAQuinnPlasmonExcitationModel.hh
    G4DNARelativisticIonisationModel.hh
    G4DiffusionControlledReactionModel.hh
    G4DNAIndependentReactionTimeModel.hh
    G4DNAIndependentReactionTimeStepper.hh
    G4DNAMakeReaction.hh
    G4DNAUpdateSystemModel.hh
    G4DNAGillespieDirectMethod.hh
    G4VUpdateSystemModel.hh
    G4DNAUpdateSystemModel.hh
    G4DNAEventScheduler.hh
    G4DNARPWBAExcitationModel.hh
    G4DNARPWBAIonisationModel.hh
    G4VDNAHitModel.hh
  SOURCES
    G4DNABornAngle.cc
    G4DNABornExcitationModel1.cc
    G4DNABornExcitationModel2.cc
    G4DNABornIonisationModel1.cc
    G4DNABornIonisationModel2.cc
    G4DNAChampionElasticModel.cc
    G4DNACPA100ElasticModel.cc
    G4DNACPA100ExcitationModel.cc
    G4DNACPA100IonisationModel.cc
    G4DNASmoluchowskiDiffusion.cc
    G4DNASmoluchowskiReactionModel.cc
    G4DNADingfelderChargeDecreaseModel.cc
    G4DNADingfelderChargeIncreaseModel.cc
    G4DNAELSEPAElasticModel.cc
    G4DNAEmfietzoglouExcitationModel.cc
    G4DNAEmfietzoglouIonisationModel.cc
    G4DNAIonElasticModel.cc
    G4DNAIRT.cc
    G4DNAIRTMoleculeEncounterStepper.cc
    G4DNAMeltonAttachmentModel.cc
    G4DNAMillerGreenExcitationModel.cc
    G4DNAMolecularIRTModel.cc
    G4DNAMolecularReaction.cc
    G4DNAMolecularStepByStepModel.cc
    G4DNAMoleculeEncounterStepper.cc
    G4DNARuddAngle.cc
    G4DNARuddIonisationExtendedModel.cc
    G4DNARuddIonisationModel.cc
    G4DNASancheExcitationModel.cc
    G4DNAOneStepThermalizationModel.cc
    G4DNAPTBIonisationModel.cc
    G4DNAPTBElasticModel.cc
    G4DNAPTBExcitationModel.cc
    G4DNAPTBAugerModel.cc
    G4DNAScreenedRutherfordElasticModel.cc
    G4DNATransformElectronModel.cc
    G4DNAUeharaScreenedRutherfordElasticModel.cc
    G4DNAVacuumModel.cc
    G4LEPTSElossDistr.cc
    G4LEPTSAttachmentModel.cc
    G4LEPTSDissociationModel.cc
    G4LEPTSElasticModel.cc
    G4LEPTSDistribution.cc
    G4LEPTSIonisationModel.cc
    G4LEPTSPositroniumModel.cc
    G4LEPTSRotExcitationModel.cc
    G4LEPTSVibExcitationModel.cc
    G4VLEPTSModel.cc
    G4LEPTSExcitationModel.cc
    G4LEPTSDiffXS.cc
    G4VDNAModel.cc
    G4DNAModelInterface.cc
    G4DNADummyModel.cc
    G4DNADiracRMatrixExcitationModel.cc
    G4DNAQuinnPlasmonExcitationModel.cc
    G4DNARelativisticIonisationModel.cc
    G4DiffusionControlledReactionModel.cc
    G4DNAIndependentReactionTimeModel.cc
    G4DNAIndependentReactionTimeStepper.cc
    G4DNAMakeReaction.cc
    G4DNAUpdateSystemModel.cc
    G4DNAGillespieDirectMethod.cc
    G4DNAUpdateSystemModel.cc
    G4DNAEventScheduler.cc
    G4DNARPWBAExcitationModel.cc
    G4DNARPWBAIonisationModel.cc
    G4VDNAHitModel.cc)

geant4_module_link_libraries(G4emdna-models
  PUBLIC
    G4baryons
    G4bosons
    G4cuts
    G4emdna-man
    G4emdna-molman
    G4emdna-moltypes
    G4emdna-utils
    G4emlowenergy
    G4emutils
    G4globman
    G4heprandom
    G4leptons
    G4materials
    G4navigation
    G4partman
    G4track
  PRIVATE
    G4emstandard
    G4ions)
