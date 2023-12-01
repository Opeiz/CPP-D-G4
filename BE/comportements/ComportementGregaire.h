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
        
        double get_orientation(std::list<Bestiole> perceivedBsts);

        void execute();

};

#endif 