#ifndef __COMPORTEMENT_PEUREUSE_H__
#define __COMPORTEMENT_PEUREUSE_H__

#include <list>

#include "Bestiole.h"
#include "comportements/Comportement.h"

#define LIM_PEUREUSE 2 // Max number of detected bestioles before running away
#define DURATION_PEUREUSE 30 // Amount of timesteps of fleeing when scared
#define SPEEDBOOST_PEUREUSE 2.0  // Speed increase factor when fleeing.

class ComportementPeureuse: public Comportement{
    private:
        int fearTimesteps = 0;
    public:
        double calculateOrientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts);
        double calculateVitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts);

        Comportement* clone() const;
};

#endif 