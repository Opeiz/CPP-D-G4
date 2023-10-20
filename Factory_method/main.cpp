#include "pizza.h"
#include "kitchen.h"

int main(){
    PizzaKitchen& pizzaK;
    
    // Instantiate all kitchens
    PizzaCalezoneKitchen pizzaCalezoneK;
    PizzaVegetarianKitchen PizzaVegetarianK;
    PizzaVeganKitchen PizzaVeganK;

    // Client chooses a type of pizza and the factory cooks it
    pizzaK = PizzaVegetarianK;
    Pizza& pizza = pizzaK.cookPizza;

    // Bon appetit!
    pizza.eatPizza();
    
    return 0;
}