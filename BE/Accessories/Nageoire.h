#ifndef _NAGE_H_
#define _NAGE_H_


#include "../Bestiole.h"
#include "Accessory.h"

class Nageoire: public Accessory{
    private :
        string name;
        float speed;

    public :
        
        Nageoire( void );                               // Constructeur par defaut
        ~Nageoire ( void );    
        float get_speed();
        void set_coef(int coef);                                       

};

#endif 