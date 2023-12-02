#ifndef __COMPORTEMENT_GREGAIRE_H__
#define __COMPORTEMENT_GREGAIRE_H__

#include <list>

#include "Bestiole.h"
#include "Comportement.h"

class ComportementGregaire: public Comportement {
    private :
        T* Color;

    public :
        ComportementGregaire(void);
        ~ComportementGregaire(void);
        
        double get_orientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts);
        double get_vitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts);
};

#endif 