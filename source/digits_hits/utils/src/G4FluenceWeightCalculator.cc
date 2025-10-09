#include "G4FluenceWeightCalculator.hh"

G4FluenceWeightCalculator* G4FluenceWeightCalculator::fInstance = nullptr;

const G4FluenceWeightCalculator* G4FluenceWeightCalculator::GetInstance() {
    if (!fInstance) {
        static G4DefaultFluenceWeightCalculator defaultCalculator;
        fInstance = &defaultCalculator;
    }
    return fInstance;
}

void G4FluenceWeightCalculator::SetInstance(G4FluenceWeightCalculator* instance) {
    fInstance = instance;
}
