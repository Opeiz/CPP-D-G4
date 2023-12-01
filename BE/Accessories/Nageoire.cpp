#include "../Bestiole.h"
#include "Nageoire.h"

Nageoire::Nageoire( void ){
    name="Nageoire";
    speed=0;
}


float Nageoire::get_speed(){
    return speed;
}
void Nageoire::set_coef(int coef){
    speed=coef;
}