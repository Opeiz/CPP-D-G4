#ifndef _COMP_H_
#define _COMP_H_
#include "../Bestiole.h"
class Comportement{

    public : 
        Bestiole mybestiole ;                                                   
        virtual double get_orientation() = 0 ; 
        virtual double get_vitesse() = 0;
        virtual void set_color() = 0; // TODO: May need to take parameter to change a bestioles color                                    
};

#endif