
#include "Carapace.h"

Carapace::Carapace( ){
    coef_prob=0;
    speed=0;
}
Carapace::~Carapace( ){

}

float Carapace::get_speed(){
    return speed;
}
void Carapace::set_speed(int coef){
    speed=coef;
}
float Carapace::get_coef(){
    return coef_prob;
}
void Carapace::set_coef(int coef){
    coef_prob=coef;
}