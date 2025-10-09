
#ifndef G4FluenceWeightCalculator_h
#define G4FluenceWeightCalculator_h

#include "G4Types.hh"
#include "G4ParticleDefinition.hh"

class G4FluenceWeightCalculator {
public:
    virtual ~G4FluenceWeightCalculator() = default;

    virtual G4double GetWeight(const G4ParticleDefinition*, G4double) const = 0;

    static void SetInstance(G4FluenceWeightCalculator* instance);
    static const G4FluenceWeightCalculator* GetInstance();

private:
    static G4FluenceWeightCalculator* fInstance;
};

class G4DefaultFluenceWeightCalculator : public G4FluenceWeightCalculator {
public:
    virtual G4double GetWeight(const G4ParticleDefinition*, G4double) const override {
        return 1.0;
    }
};

#endif
