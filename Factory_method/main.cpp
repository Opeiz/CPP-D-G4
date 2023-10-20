#include "pizza.h"
#include "kitchen.h"

int main(){
    // Instantiate all kitchens
    PizzaCalezoneKitchen pizzaCalezoneK;
    PizzaVegetarianKitchen PizzaVegetarianK;
    PizzaVeganKitchen PizzaVeganK;

    // Client chooses a type of pizza and the factory cooks it
    PizzaKitchen& pizzaK = PizzaVegetarianK;
    Pizza* pizza = pizzaK.cookPizza();

    // Bon appetit!
    pizza->eatPizza();
    
    delete pizza;
    return 0;
}