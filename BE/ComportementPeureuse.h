#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <iostream>

using namespace std;

class Comportement{
    private :
         T     * Color;

    public :                                 
        virtual Comportement( void );                  
        virtual ~Comportement();  
        virtual double get_orientation(); 
        virtual double get_vitesse();
        virtual T set_color();                                          

};

#endif 