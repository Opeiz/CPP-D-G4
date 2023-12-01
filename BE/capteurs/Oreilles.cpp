#include "Oreilles.h"
#include "Bestiole.h"

#include <iostream>

Oreilles::Oreilles(){
    delta_o = DELTA_O_MIN + (DELTA_O_MAX-DELTA_O_MIN)*((float) rand()) / (float) RAND_MAX;
    gamma_o = GAMMA_O_MIN + (GAMMA_O_MAX-GAMMA_O_MIN)*((float) rand()) / (float) RAND_MAX;

}

Oreilles::Oreilles(float delta, float gamma){
    delta_o = (delta > DELTA_O_MIN) ? delta : DELTA_O_MIN;
    delta_o = (delta_o < DELTA_O_MAX) ? delta_o : DELTA_O_MAX;

    gamma_o = (gamma > GAMMA_O_MIN) ? gamma : GAMMA_O_MIN;
    gamma_o = (gamma_o < GAMMA_O_MAX) ? gamma_o : GAMMA_O_MAX;
}

std::list<Bestiole*> Oreilles::detecter(Bestiole &bes, std::list<Bestiole> &listeBestioles) const{
    
    std::list<Bestiole*> perceivedBsts = {};

    // Iterate over all bestioles to see if distance is inside detection range
    for (std::list<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it){
        if ((bes != *it) && (bes.distanceToBst(*it) <= this->delta_o)){
            // Check if detection power is greater that the camouflage of the other
            if ((this->gamma_o ) > (it->camouflage)){
                perceivedBsts.push_back(&(*it));
            }
        }
    }

    return perceivedBsts;
}

Capteur* Oreilles::clone() const {
    return new Oreilles(*this);
}
