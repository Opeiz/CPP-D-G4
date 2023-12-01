#ifndef _NAGE_H_
#define _NAGE_H_


#include "../Bestiole.h"
#include "Accessory.h"

class Camouflage: public Accessory{
    private :
        string name;
        float coef_camouflage;

    public :
        
        Camouflage( void );                               // Constructeur par defaut
        ~Camouflage ( void );    
        float get_coef();
        void set_coef(int coef);                                       

};

#endif 