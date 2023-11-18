#ifndef _COMP_H_
#define _COMP_H_

class Comportement{

    public :                                                    
        virtual double get_orientation() = 0 ; 
        virtual double get_vitesse() = 0;
        virtual void set_color() = 0; // TODO: May need to take parameter to change a bestioles color                                    
};

#endif 