#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "Capteur.h"

class Bestiole;

// Arbitrary values
#define DELTA_O_MIN 100.0
#define DELTA_O_MAX 200.0
#define GAMMA_O_MIN 0.80
#define GAMMA_O_MAX 1.0

class Oreilles : public Capteur{
    private:
        float delta_o;
        float gamma_o;

    public:
        Oreilles();
        Oreilles(float delta, float gamma);
        std::list<Bestiole*> detecter(Bestiole &bes, std::list<Bestiole> &listeBestioles) const;
        Capteur* clone() const;
};

#endif