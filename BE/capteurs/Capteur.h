#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_


// Arbitrary values, they may change in the future and their location as well 

#include <list>

#include "UImg.h"

class Bestiole;

class Capteur{
    public:
        virtual std::list<Bestiole*> detecter(Bestiole &bes, std::list<Bestiole> &listeBestioles) const = 0;
        virtual Capteur* clone() const = 0;
        virtual ~Capteur(){};
};

#endif