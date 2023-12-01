#ifndef _NAGE_H_
#define _NAGE_H_

#include "../Bestiole.h"
#include "Accessory.h"

class Carapace: public Accessory{
    private :
        string name;
        float coef_prob;
        float speed;

    public :
        
        Carapace( void );                               // Constructeur par defaut
        ~Carapace ( void );    
        float get_speed();
        float get_coef();
        void set_coef(int coef);
        void set_speed(int coef);                                       

};

#endif 