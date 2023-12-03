#ifndef __COMPORTEMENT_PEUREUSE_H__
#define __COMPORTEMENT_PEUREUSE_H__

#include <list>

#include "Bestiole.h"
#include "comportements/Comportement.h"

#define LIM_PEUREUSE 2 // Max number of detected bestioles before running away

class ComportementPeureuse: public Comportement{
    private :
        T* Color;

    public :
        ComportementPeureuse( void );
        ~ComportementPeureuse( void );
        
        double calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts);

        double calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts);

};

#endif 