#include "Camouflage.h"

Camouflage::Camouflage(){
    coef_camouflage=0;
}
Camouflage::~Camouflage(){
}


float Camouflage::get_coef(){
    return coef_camouflage;
}
void Camouflage::set_coef(int coef){
    coef_camouflage=coef;
}