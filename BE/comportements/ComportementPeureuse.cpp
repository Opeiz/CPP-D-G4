#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "UImg.h"
#include "ComportementPeureuse.h"

ComportementPeureuse::ComportementPeureuse(void){
    printf("Creation of a Peureuse Bestiole \n");
}
ComportementPeureuse::~ComportementPeureuse(void){
    printf("Destruction of Peureuse Bestiole \n");
}

double ComportementPeureuse::get_orientation(std::list<Bestiole> perceivedBsts){

    double avgOrientation = 0;
    for (std::list<Bestiole>::iterator it = perceivedBsts.begin(); it != perceivedBsts.end(); ++it){
        avgOrientation += it->getOrientation();
    }
    avgOrientation /= perceivedBsts.size();

    avgOrientation = (avgOrientation >= M_PI) ? (avgOrientation - M_PI) : (avgOrientation + M_PI);
    return avgOrientation;
};

void ComportementPeureuse::execute(){
}