#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_


// Arbitrary values, they may change in the future and their location as well 

#include <list>

#include "UImg.h"
#include "Bestiole.h"

class Capteur{
    public:
        virtual std::list<Bestiole*> detecter(Bestiole bes, std::list<Bestiole> listeBestioles)=0;
};

#endif