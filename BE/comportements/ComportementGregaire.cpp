#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "UImg.h"
#include "ComportementGregaire.h"

ComportementGregaire::ComportementGregaire(void){
    printf("Creation of ComportementGregaire\n");
}
ComportementGregaire::~ComportementGregaire(void){
    printf("Destruction of ComportementGregaire\n"); 
}

double ComportementGregaire::calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts){
    
    // For all the bestioles in the list, calculate the average orientation
    // and return it as a tuple

    if (!perceivedBsts.size()){
        // If list is empty keep going straight
        return b.getOrientation();
    }

    double avgOrientation = 0;
    for (std::list<Bestiole*>::iterator it = perceivedBsts.begin(); it != perceivedBsts.end(); ++it){
        avgOrientation += (*it)->getOrientation();
    }
    avgOrientation /= perceivedBsts.size();
    return avgOrientation;
}

double ComportementGregaire::calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts){
    return b.getVitesse();
}