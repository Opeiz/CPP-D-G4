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
        ~ComportementKamikaze( void );

        double calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts);
        double calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts);

};

#endif 