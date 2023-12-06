#ifndef __COMPORTEMENT_PREVOYANTE_H__
#define __COMPORTEMENT_PREVOYANTE_H__

#include <list>

#include "Bestiole.h"
#include "comportements/Comportement.h"

class ComportementPrevoyante: public Comportement{
    private :
        T* Color;

    public :
        ComportementPrevoyante( void );
        ~ComportementPrevoyante( void );
        
        // std::tuple<int, int> get_orientation(std::list<Bestiole> perceivedBsts); 
        // double get_vitesse(std::list<Bestiole> perceivedBsts);
        // void   set_color(); 

        void execute();

};

#endif 