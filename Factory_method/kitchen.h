#ifndef __KITCHEN
#define __KITCHEN

#include "pizza.h"

class PizzaKitchen{
    public:
        virtual Pizza* cookPizza()=0;
}

class PizzaCalezoneKitchen : PizzaKitchen {
    PizzaCalezone* cookPizza();
}

class PizzaVegetarianKitchen : PizzaKitchen {
    PizzaVegetarian* cookPizza();
}

class PizzaVeganKitchen : PizzaKitchen {
    PizzaVegan* cookPizza();
}

#endif
