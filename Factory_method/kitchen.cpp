#include "kitchen.h"

PizzaCalezone* PizzaCalezoneKitchen::cookPizza(){
    // Pizza parameters (price and diameter)
    // Not chosen by the client, they are set beforehand

    float p = 14.99;
    int d = 24;
    return &PizzaCalezone(p, d);
}

PizzaVegetarian* PizzaVegetarianKitchen::cookPizza(){
    // Pizza parameters (price and diameter)
    // Not chosen by the client, they are set beforehand

    float p = 12.99;
    int d = 20;
    return &PizzaVegetarian(p, d);
}

PizzaVegan* PizzaVeganKitchen::cookPizza(){
    // Pizza parameters (price and diameter)
    // Not chosen by the client, they are set beforehand

    float p = 8.99;
    int d = 16;
    return &PizzaVegan(p, d);
}