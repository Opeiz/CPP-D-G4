#ifndef __PIZZA
#define __PIZZA

class Pizza {
    public:
        float price;
        int size;

        void eat_pizza();

        Pizza();
        ~Pizza()
}

class PizzaCalzone : Pizza {
    char* meat_type;
    char* cheese_type;
    char* dough_type;

    PizzaCalzone();
    ~PizzaCalzone();
}

class PizzaVegetarian : Pizza {
    char* cheese_type;
    char* dough_type;

    PizzaVegetarian();
    ~PizzaVegetarian();    
}

class PizzaVegan : Pizza {
    char* dough_type;

    PizzaVegan();
    ~PizzaVegan();
}

#endif