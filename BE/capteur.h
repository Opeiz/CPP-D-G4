#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_

#define ALPHA_Y_MIN 30.0
#define ALPHA_Y_MAX 180.0
#define DELTA_Y_MIN 0.1
#define DELTA_Y_MAX 10.0
#define GAMMA_Y_MIN 0.01
#define GAMMA_Y_MAX 1.0

#define DELTA_O_MIN 0.1
#define DELTA_O_MAX 1.0
#define GAMMA_O_MIN 0.01
#define GAMMA_O_MAX 1.0
// Arbitrary values, they may change in the future and their location as well 

#include <iostream>
#include <cstdlib>

#include "UImg.h"
#include "Bestiole.h"

double bestiole_dist(Bestiole b1, Bestionle b2);

class Capteur{
    public:
        virtual void detecter(list<*Bestiole> Perceived_bsts)
}

class Yeux : public (Capteur){
    public:
        float alpha_y;
        float delta_y; 
        float gamma_y;

        void detecter(list<*Bestiole> Perceived_bsts)
}

class Oreilles : public (Capteur){
    public:
        float delta_o;
        float gamma_o;

        void detecter(list<*Bestiole> Perceived_bsts)
}


#endif