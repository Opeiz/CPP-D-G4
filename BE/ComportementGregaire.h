#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <iostream>

using namespace std;

class ComportementGregaire : public Comportement{
    private :
         T     * Color;

    public :                                 
        Comportement( void );                  
        double get_orientation(); 
        double get_vitesse();
        T set_color();                                          

};

#endif 