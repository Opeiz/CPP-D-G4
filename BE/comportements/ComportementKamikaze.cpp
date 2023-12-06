#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "ComportementKamikaze.h"

double ComportementKamikaze::calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts){
    // Check that perceivedBsts is not empty
    if (!perceivedBsts.size()){
        return b.getOrientation();
    }

    // For all the bestioles in the list, search for the closest one
    Bestiole* closest = nullptr;
    double minDist = 1000;

    for (std::list<Bestiole*>::iterator it = perceivedBsts.begin(); it != perceivedBsts.end(); ++it){
        double distance = b.distanceToBst(**it);
        if (distance < minDist){
            minDist = distance;
            closest = *it;
        }
    }

    double newOrientation = b.angleToBst(*closest);
    return newOrientation;
};

double ComportementKamikaze::calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts){
    return b.getVitesse();
}

Comportement* ComportementKamikaze::clone() const {
    return new ComportementKamikaze(*this);
}