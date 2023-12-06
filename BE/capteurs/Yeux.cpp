#include "Yeux.h"
#include "Bestiole.h"

#include <cmath>
#include <iostream>

Yeux::Yeux(){
    alpha_y = ALPHA_Y_MIN + (ALPHA_Y_MAX-ALPHA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
    delta_y = DELTA_Y_MIN + (DELTA_Y_MAX-DELTA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
    gamma_y = GAMMA_Y_MIN + (GAMMA_Y_MAX-GAMMA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
}

Yeux::Yeux(float alpha, float delta, float gamma){
    alpha_y = (alpha > ALPHA_Y_MIN) ? alpha : ALPHA_Y_MIN;
    alpha_y = (alpha_y < ALPHA_Y_MAX) ? alpha_y : ALPHA_Y_MAX;
    
    delta_y = (delta > DELTA_Y_MIN) ? delta : DELTA_Y_MIN;
    delta_y = (delta_y < DELTA_Y_MAX) ? delta_y : DELTA_Y_MAX;

    gamma_y = (gamma > GAMMA_Y_MIN) ? gamma : GAMMA_Y_MIN;
    gamma_y = (gamma_y < GAMMA_Y_MAX) ? gamma_y : GAMMA_Y_MAX;

}

std::list<Bestiole*> Yeux::detecter(Bestiole &bes, std::list<Bestiole> &listeBestioles) const {
    
    std::list<Bestiole*> perceivedBsts = {};

    // Iterate over all bestioles to see if distance is inside detection range
    for (std::list<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it){

        if ((bes != *it) && (bes.distanceToBst(*it) <= this->delta_y) && (fabs(bes.relAngleToBst(*it)) < fabs(alpha_y / 2))){
            // Check if detection power is greater that the camouflage of the other
            if ((this->gamma_y ) > (it->camouflage)){
                perceivedBsts.push_back(&(*it));
            }
        }
    }
    return perceivedBsts;
}

Capteur* Yeux::clone() const {
    return new Yeux(*this);
}