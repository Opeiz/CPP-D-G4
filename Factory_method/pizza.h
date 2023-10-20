#ifndef __PIZZA
#define __PIZZA

class Pizza {
    public:
        float price;
        int diameter;

        void eatPizza();

        Pizza();
}

class PizzaCalezone : Pizza {
    char* meat_type;
    char* cheese_type;
    char* dough_type;

    PizzaCalezone();
}

class PizzaVegetarian : Pizza {
    char* cheese_type;
    char* dough_type;

    PizzaVegetarian();
}

class PizzaVegan : Pizza {
    char* dough_type;

    PizzaVegan();
}

#endif