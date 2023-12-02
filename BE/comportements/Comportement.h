#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <list>

class Bestiole;

class Comportement{

    public:
        virtual double get_orientation(Bestiole &b, std::list<Bestiole*> &perceivedBsts) = 0 ; 
        virtual double get_vitesse(Bestiole &b, std::list<Bestiole*> &perceivedBsts) = 0;
        virtual ~Comportement(){};
};

#endif