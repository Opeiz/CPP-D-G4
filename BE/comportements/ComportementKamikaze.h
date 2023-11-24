#ifndef _COMP_KAMI_H_
#define _COMP_KAMI_H_

#include <list>

#include "Bestiole.h"
#include "comportements/Comportement.h"

class ComportementKamikaze: public Comportement{
    private :
        T* Color;

    public :                                 
        double get_orientation(std::list<Bestiole> perceivedBsts); 
        double get_vitesse(std::list<Bestiole> perceivedBsts);
        void   set_color();                                          

};

#endif 