#include <cstdlib>
#include <list>
#include <cmath>
#include "Bestiole.h"
#include "UImg.h"
#include "ComportementKamikaze.h"

const T    red[] =      { (T)255,   (T)0,   (T)0 };
// const T    blue[] =     { (T)0,     (T)0,   (T)255 };
// const T    green[] =    { (T)0,     (T)255, (T)0 };
// const T    rose[] =     { (T)255,   (T)193, (T)203 };
// const T    purple[] =   { (T)128,   (T)0,   (T)128 };
// const T    orange[] =   { (T)255,   (T)165, (T)0 };
// const T    white[] =    { (T)255,   (T)255, (T)255 };
// const T    black[] =    { (T)0,     (T)0,   (T)0 };

double ComportementKamikaze::get_orientation(std::list<Bestiole> perceivedBsts){
    //iterate on bestiole to know the nearest 
    for (nbbestiole , nbbestiole <len(perceivedBsts), nbbestiole++){
        if ((perceivedBsts[nbbestiole].x)<min){
            
        }

    } 
    return 0;
};

double ComportementKamikaze::get_vitesse(std::list<Bestiole> perceivedBsts){
    // TODO
    return 0;
}

void ComportementKamikaze::set_color(){
    // TODO
}
int ComportementKamikaze::distance(Bestiole bestiole1,Bestiole bestiole2){
    return sqrt();
}