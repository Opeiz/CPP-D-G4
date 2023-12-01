#ifndef _ACCE_H_
#define _ACCE_H_
#include "../Bestiole.h"
#include <string>

class Accessory{
    private :
        string name;
    public :
        // Bestiole mybestiole ;                                                   
        string get_accessory_name()=0; 
};

#endif