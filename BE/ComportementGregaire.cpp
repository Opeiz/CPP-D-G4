#include "Milieu.h"
#include "ComportementGregaire.h"
#include <cstdlib>
#include <ctime>


const T    white[] =    { (T)255,   (T)255, (T)255 };
const T    black[] =    { (T)0,     (T)0,   (T)0 };
const T    red[] =      { (T)255,   (T)0,   (T)0 };
const T    blue[] =     { (T)0,     (T)0,   (T)255 };
const T    green[] =    { (T)0,     (T)255, (T)0 };
const T    rose[] =     { (T)255,   (T)193, (T)203 };
const T    purple[] =   { (T)128,   (T)0,   (T)128 };
const T    orange[] =   { (T)255,   (T)165, (T)0 };

ComportementGregaire::ComportementGregaire(){}


double ComportementGraigaire::get_orientation(list<Bestiole> Perceived_bsts){
    return 0;
}

double ComportementGraigaire::get_vitesse(list<Bestiole> Perceived_bsts){
    return 0;
}

T* ComportementGraigaire::get_color(list<Bestiole> Perceived_bsts){
    return black[];
}

