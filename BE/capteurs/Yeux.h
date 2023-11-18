#ifndef _YEUX_H_
#define _YEUX_H_

#include "capteurs/Capteur.h"

// Arbitrary values
#define ALPHA_Y_MIN 30.0
#define ALPHA_Y_MAX 180.0
#define DELTA_Y_MIN 0.1
#define DELTA_Y_MAX 10.0
#define GAMMA_Y_MIN 0.01
#define GAMMA_Y_MAX 1.0

class Yeux : public Capteur{
    private:
        float alpha_y;
        float delta_y; 
        float gamma_y;

    public:
        Yeux();
        Yeux(float alpha, float delta, float gamma);
        void detecter(std::list<Bestiole*> perceivedBsts);
};

#endif