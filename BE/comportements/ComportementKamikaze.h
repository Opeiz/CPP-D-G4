#ifndef __COMPORTEMENT_KAMIKAZE_H__
#define __COMPORTEMENT_KAMIKAZE_H__

#include <list>

#include "Bestiole.h"
#include "Comportement.h"

class ComportementKamikaze: public Comportement{
    public:
        double calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts);
        double calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts);

        Comportement* clone() const;
};

#endif 