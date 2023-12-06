#ifndef _NAGE_H_
#define _NAGE_H_


#include "Accessory.h"

class Nageoire: public Accessory{
    private :
        float speed;
    public :
        Nageoire();                               // Constructeur par defaut
        ~Nageoire ();    
        float get_speed();
        void set_coef(int coef);                                       

};

#endif 