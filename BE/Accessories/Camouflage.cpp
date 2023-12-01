#include "Camouflage.h"

Camouflage::Camouflage( void ){
    coef_camouflage=0;
}


float Camouflage::get_coef(){
    return coef_camouflage;
}
void Camouflage::set_coef(int coef){
    coef_camouflage=coef;
}