// Deficion de la clase 
#ifndef __TREE
#define __TREE

class Tree {
    bool evergreen;
    double height;

    public: 

        void setHeight(double h);
        double getHeight() const;
        void setEvergreen(bool p);
        bool isEvergreen() const;

        void draw();

        Tree (); // Asigna la memoria a la clase
        ~Tree(); // Libera la memoria de la clase
};

#endif