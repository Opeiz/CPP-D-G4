#include "kitchen.h"

Pizza* PizzaCalezoneKitchen::cookPizza(){
    // Pizza parameters (price and diameter)
    // Not chosen by the client, they are set beforehand

    float price = 14.99;
    int diameter = 24;
    return new PizzaCalezone(price, diameter);
}

Pizza* PizzaVegetarianKitchen::cookPizza(){
    // Pizza parameters (price and diameter)
    // Not chosen by the client, they are set beforehand

    float price = 12.99;
    int diameter = 20;
    return new PizzaVegetarian(price, diameter);
}

Pizza* PizzaVeganKitchen::cookPizza(){
    // Pizza parameters (price and diameter)
    // Not chosen by the client, they are set beforehand

    float price = 8.99;
    int diameter = 16;
    return new PizzaVegan(price, diameter);
}