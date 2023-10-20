#include <iostream>
#include "pizza.h"

/* Pizza class */

Pizza:Pizza(){
    std::cout << "Cooking a pizza at address: " << this << std::endl;
    std::cout << "Using standard diameter and price" << std::endl;
}

Pizza:Pizza(float p, int d): diameter(d), price(p){
    std::cout << "Cooking a pizza at address: " << this << std::endl;
}

void Pizza::eatPizza(){
    std::cout << "Eating the pizza at address: " << this << std::endl;
    std::cout << :"Yummy!" << std::endl;
}

/* Calezone class */

PizzaCalezone::PizzaCalezone(float p, int d) :
    Pizza(p, d), meat_type("beef"), cheese_type("mozzarella"), dough_type("classic"){
        std::cout << "Calezone coming up!" << std::cout;
}

/* Vegetarian class */

PizzaVegetarian::PizzaVegetarian(float p, int d) :
    Pizza(p,d), cheese_type("mozzarella"), dough_type("classic"){
        std::cout << "Vegetarian coming up!" << std::endl;
    }

/* Vegan class */

PizzaVegan::PizzaVegan(float p, int d) :
    Pizza(p, d), dough_type("classic"){
        std::cout << "Vegan coming up!" << std:cout;
    }