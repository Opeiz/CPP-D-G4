#ifndef _YEUX_H_
#define _YEUX_H_

#include "Capteur.h"

class Bestiole;

// Arbitrary values
#define ALPHA_Y_MIN 60.0
#define ALPHA_Y_MAX 90.0
#define DELTA_Y_MIN 30.0
#define DELTA_Y_MAX 50.0
#define GAMMA_Y_MIN 0.5
#define GAMMA_Y_MAX 0.9

class Yeux : public Capteur{
    private:
        float alpha_y;
        float delta_y; 
        float gamma_y;

    public:
        Yeux();
        Yeux(float alpha, float delta, float gamma);
        std::list<Bestiole*> detecter(Bestiole &bes, std::list<Bestiole> &listeBestioles) const;
        Capteur* clone() const;
};

#endif