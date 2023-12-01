#include <cstdlib>
#include <list>
#include <cmath>

#include "Bestiole.h"
#include "UImg.h"
#include "ComportementPrevoyante.h"


// std::tuple<int, int> ComportementKamikaze::get_orientation(std::list<Bestiole> perceivedBsts){
//     //iterate on bestiole to know the nearest 
//     Bestiole nearest=perceivedBsts[0];
//     for (nbbestiole , nbbestiole <len(perceivedBsts), nbbestiole++){
        
//         distance=Bestiole.distanceToBst(perceivedBsts[nbbestiole]);
//         if ((perceivedBsts[nbbestiole].x)<min || nbbestiole==0){
//             min=distance
//             nearest= perceivedBsts[nbbestiole];
//         }

//     } 
//     return  std::make_tuple(nearest.x, nearest.y);
// };

// double ComportementKamikaze::get_vitesse(std::list<Bestiole> perceivedBsts){
//     // TODO
//     return 0;
// }

// void ComportementKamikaze::set_color(){
//     // TODO
// }
ComportementPrevoyante::ComportementPrevoyante(void){
    printf("Creation of a Prevoyante Bestiole \n");
}
ComportementPrevoyante::~ComportementPrevoyante(void){
    printf("Destruction of Prevoyante Bestiole \n");
}

void ComportementPrevoyante::execute(){
    printf("TEST QLO DE MIERDA LARGO");
}