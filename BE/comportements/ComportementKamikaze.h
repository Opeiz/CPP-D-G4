#ifndef _COMPORTEMENT_KAMIKAZE_H_
#define _COMPORTEMENT_KAMIKAZE_H_

#include <list>

#include "Bestiole.h"
#include "Comportement.h"

class ComportementKamikaze: public Comportement{
    private :
        T* Color;

    public :
        ComportementKamikaze( void );
        // ~ComportementKamikaze( void );

        // std::tuple<int, int> get_orientation(std::list<Bestiole> perceivedBsts); 
        // double get_vitesse(std::list<Bestiole> perceivedBsts);
        // void   set_color(); 

        // void execute();

};

#endif 