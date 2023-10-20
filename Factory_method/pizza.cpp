#include <iostream>
#include "pizza.h"

/* Pizza class */

Pizza::Pizza(){
    std::cout << "Cooking a pizza at address: " << this << std::endl;
    std::cout << "Using standard diameter and price" << std::endl;
}

Pizza::Pizza(float price, int diameter): diameter(diameter), price(price){
    std::cout << "Cooking a pizza at address: " << this << std::endl;
}

void Pizza::eatPizza(){
    std::cout << "Eating the pizza at address: " << this << std::endl;
    std::cout << "Yummy!" << std::endl;
}

/* Calezone class */

PizzaCalezone::PizzaCalezone(float price, int diameter) :
    Pizza::Pizza(price, diameter), meat_type("beef"), cheese_type("mozzarella"), dough_type("classic"){
        std::cout << "Calezone coming up!" << std::endl;
}

/* Vegetarian class */

PizzaVegetarian::PizzaVegetarian(float price, int diameter) :
    Pizza::Pizza(price,diameter), cheese_type("mozzarella"), dough_type("classic"){
        std::cout << "Vegetarian coming up!" << std::endl;
    }

/* Vegan class */

PizzaVegan::PizzaVegan(float price, int diameter) :
    Pizza::Pizza(price, diameter), dough_type("classic"){
        std::cout << "Vegan coming up!" << std::endl;
    }