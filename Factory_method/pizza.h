#ifndef __PIZZA
#define __PIZZA

#include <string>

class Pizza {
    public:
        float price;
        int diameter;

        void eatPizza();

        Pizza();
        Pizza(float price, int diameter);
};

class PizzaCalezone : public Pizza {
    std::string meat_type;
    std::string cheese_type;
    std::string dough_type;
    
    public:
        PizzaCalezone(float price, int diameter);
};

class PizzaVegetarian : public Pizza {
    std::string cheese_type;
    std::string dough_type;

    public:
        PizzaVegetarian(float price, int diameter);
};

class PizzaVegan : public Pizza {
    std::string dough_type;

    public:
        PizzaVegan(float price, int diameter);
};

#endif