#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <iostream>

using namespace std;

class Comportement{

    public :                                                    
        virtual double get_orientation() = 0 ; 
        virtual double get_vitesse() = 0;
        virtual T * get_color() = 0;      
        virtual ~Comportement() {};                                      

};

#endif 