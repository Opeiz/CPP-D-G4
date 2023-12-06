#include "Nageoire.h"

Nageoire::Nageoire(){
    speed=0;
}
Nageoire::~Nageoire(){
}

float Nageoire::get_speed(){
    return speed;
}
void Nageoire::set_coef(int coef){
    speed=coef;
}