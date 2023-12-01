#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "UImg.h"
#include "ComportementKamikaze.h"

ComportementKamikaze::ComportementKamikaze(void){
    printf("Creation of a Kamikaze Bestiole \n");
}
ComportementKamikaze::~ComportementKamikaze(void){
    printf("Destruction of Kamikaze Bestiole \n");
}

double ComportementKamikaze::get_orientation(Bestiole & current, std::list<Bestiole> perceivedBsts){
    
    // For all the bestioles in the list, search for the closest one
    Bestiole * closest = nullptr;
    double minDist = 1000;

    for (std::list<Bestiole>::iterator it = perceivedBsts.begin(); it != perceivedBsts.end(); ++it){
        double distance = it->distanceToBst(*it);
        if (distance < minDist){
            minDist = distance;
            closest = &(*it);
        }
    }

    double newOrientation = current.calculateAngle(*closest);
    return newOrientation;
};

void ComportementKamikaze::execute(){
}