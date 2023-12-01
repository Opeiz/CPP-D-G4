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
        
        double get_orientation(std::list<Bestiole> perceivedBsts);

        void execute();

};

#endif 