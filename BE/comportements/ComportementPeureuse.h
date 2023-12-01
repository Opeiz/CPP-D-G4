#ifndef __COMPORTEMENT_PEUREUSE_H__
#define __COMPORTEMENT_PEUREUSE_H__

#include <list>

#include "Bestiole.h"
#include "comportements/Comportement.h"

class ComportementPeureuse: public Comportement{
    private :
        T* Color;

    public :
        ComportementPeureuse( void );
        ~ComportementPeureuse( void );
        
        // std::tuple<int, int> get_orientation(std::list<Bestiole> perceivedBsts); 
        // double get_vitesse(std::list<Bestiole> perceivedBsts);
        // void   set_color(); 

        void execute();

};

#endif 