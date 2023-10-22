#ifndef __PIZZA
#define __PIZZA

#include <string>

class Pizza {
    protected:
        float price;
        int diameter;
    public:
        void eatPizza();

        Pizza();
        Pizza(float price, int diameter);
        virtual ~Pizza();
};

class PizzaCalezone : public Pizza {
    std::string meat_type;
    std::string cheese_type;
    std::string dough_type;
    
    public:
        PizzaCalezone(float price, int diameter);
        ~PizzaCalezone();
};

class PizzaVegetarian : public Pizza {
    std::string cheese_type;
    std::string dough_type;

    public:
        PizzaVegetarian(float price, int diameter);
        ~PizzaVegetarian();
};

class PizzaVegan : public Pizza {
    std::string dough_type;

    public:
        PizzaVegan(float price, int diameter);
        ~PizzaVegan();
};

#endif