#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "Capteur.h"

class Bestiole;

// Arbitrary values
#define DELTA_O_MIN 30.0
#define DELTA_O_MAX 40.0
#define GAMMA_O_MIN 0.3
#define GAMMA_O_MAX 0.9

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