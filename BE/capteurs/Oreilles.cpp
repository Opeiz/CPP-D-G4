#include "capteurs/Oreilles.h"

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

void Oreilles::detecter(std::list<Bestiole*> perceivedBsts, Bestiole bes, list<Bestiole> listeBestioles)
{
    
}

