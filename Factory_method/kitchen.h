#ifndef __KITCHEN
#define __KITCHEN

#include "pizza.h"

class PizzaKitchen{
    public:
        virtual Pizza* cookPizza()=0;
};

class PizzaCalezoneKitchen : public PizzaKitchen {
    public:
        Pizza* cookPizza();
};

class PizzaVegetarianKitchen : public PizzaKitchen {
    public:
        Pizza* cookPizza();
};

class PizzaVeganKitchen : public PizzaKitchen {
    public:
        Pizza* cookPizza();
};

#endif
