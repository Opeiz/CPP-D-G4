#ifndef _CARA_H_
#define _CARA_H_

#include "Accessory.h"

class Carapace: public Accessory{
    private :
        float coef_prob;
        float speed;

    public :
        
        Carapace();                               // Constructeur par defaut
        ~Carapace ();    
        float get_speed();
        float get_coef();
        void set_coef(int coef);
        void set_speed(int coef);                                       

};

#endif 