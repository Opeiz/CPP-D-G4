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

double ComportementPeureuse::calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts){

    if (perceivedBsts.size() <= LIM_PEUREUSE) return b.getOrientation();

    return -b.getOrientation();
};

double ComportementPeureuse::calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts){
    return b.getVitesse();
}