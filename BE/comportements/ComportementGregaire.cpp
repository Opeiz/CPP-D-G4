#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "UImg.h"
#include "ComportementGregaire.h"


double ComportementKamikaze::get_orientation(std::list<Bestiole> perceivedBsts){
    
    // For all the bestioles in the list, calculate the average orientation
    // and return it as a tuple
    double avgOrientation = 0;
    for (std::list<Bestiole>::iterator it = perceivedBsts.begin(); it != perceivedBsts.end(); ++it){
        avgOrientation += it->orientation;
    }
    avgOrientation /= perceivedBsts.size();
    return avgOrientation;
};

// double ComportementKamikaze::get_vitesse(std::list<Bestiole> perceivedBsts){
//     // TODO
//     return 0;
// }

ComportementGregaire::ComportementGregaire(void){
    printf("Creation of a Gregaire Bestiole \n");
}
ComportementGregaire::~ComportementGregaire(void){
    printf("Destruction of Gregaire Bestiole \n"); 
}

void ComportementGregaire::execute(){
}