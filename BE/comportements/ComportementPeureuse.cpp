#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "ComportementPeureuse.h"

double ComportementPeureuse::calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts){

    // Already scared
    if (fearTimesteps > 0){
        return b.getOrientation();
    }

    if (perceivedBsts.size() <= LIM_PEUREUSE) return b.getOrientation();

    fearTimesteps = DURATION_PEUREUSE;
    return -b.getOrientation();
};

double ComportementPeureuse::calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts){
    /*
    Current implementation increases speed at the start of the scared state and halves it at the
    end. However, this poses a problem for multiple personality bestioles, as they may change
    personalities when scared and retain their "scared velocity" throughout their next personalities.
    */

    double vitesse = b.getVitesse();
    switch (fearTimesteps){
    
    case 0:
        // Not scared
        break;

    case DURATION_PEUREUSE:
        // Just got scared
        vitesse = SPEEDBOOST_PEUREUSE * b.getVitesse();
        fearTimesteps--;
        break;

    case 1:
        // Last scared timestep
        vitesse = b.getVitesse() / SPEEDBOOST_PEUREUSE;
        fearTimesteps--;
        break;

    default:
        // Running away
        fearTimesteps--;
        break;
    }

    return vitesse;
}

Comportement* ComportementPeureuse::clone() const {
    return new ComportementPeureuse(*this);
}