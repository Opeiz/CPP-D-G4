#ifndef _CAM_H_
#define _CAM_H_


#include "Accessory.h"

class Camouflage: public Accessory{
    private :
        float coef_camouflage;

    public :
        
        Camouflage( void );                               // Constructeur par defaut
        ~Camouflage ( void );    
        float get_coef();
        void set_coef(int coef);                                       

};

#endif 