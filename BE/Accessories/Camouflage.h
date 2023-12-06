#ifndef _CAM_H_
#define _CAM_H_


#include "Accessory.h"

class Camouflage: public Accessory{
    private :
        float coef_camouflage;

    public :
        
        Camouflage();                               // Constructeur par defaut
        ~Camouflage ();    
        float get_coef();
        void set_coef(int coef);                                       

};

#endif 