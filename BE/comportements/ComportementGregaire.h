#ifndef __COMPORTEMENT_GREGAIRE_H__
#define __COMPORTEMENT_GREGAIRE_H__

#include <list>

#include "Bestiole.h"
#include "comportements/Comportement.h"

class ComportementGregaire: public Comportement{
    private :
        T* Color;

    public :
        ComportementGregaire( void );
        ~ComportementGregaire( void );
        
        // std::tuple<int, int> get_orientation(std::list<Bestiole> perceivedBsts); 
        // double get_vitesse(std::list<Bestiole> perceivedBsts);
        // void   set_color(); 

        void execute();

};

#endif 