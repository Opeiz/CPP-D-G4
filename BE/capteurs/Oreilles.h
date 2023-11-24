#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "capteurs/Capteur.h"

// Arbitrary values
#define DELTA_O_MIN 0.1
#define DELTA_O_MAX 1.0
#define GAMMA_O_MIN 0.01
#define GAMMA_O_MAX 1.0

class Oreilles : public Capteur{
    private:
        float delta_o;
        float gamma_o;

    public:
        Oreilles();
        Oreilles(float delta, float gamma);
        void detecter(std::list<Bestiole*> perceivedBsts, Bestiole bes, list<Bestiole> listeBestioles);
};

#endif