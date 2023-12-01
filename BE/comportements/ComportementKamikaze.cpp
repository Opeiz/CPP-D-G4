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

double ComportementKamikaze::get_orientation(std::list<Bestiole> perceivedBsts){
    
    // For all the bestioles in the list, search for the closest one
    double avgOrientation = 0;
    for (std::list<Bestiole>::iterator it = perceivedBsts.begin(); it != perceivedBsts.end(); ++it){
        avgOrientation += it->orientation;
    }
    avgOrientation /= perceivedBsts.size();
    return avgOrientation;
};

double ComportementKamikaze::calculateAngle(Bestiole * b){
    return std::atan2(b->y - this->y, b->x - this->x);
}

void ComportementKamikaze::execute(){
}