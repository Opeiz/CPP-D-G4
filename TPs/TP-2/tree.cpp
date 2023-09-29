// Code de methode

#include "tree.h"

#include <iostream>

using namespace std;

Tree::Tree(){
    cout << "Construire " << this << endl;
}

void Tree::draw(){
    cout << "tree.cpp draw" << endl;
}

Tree::~Tree(){ // Ultima wea que haces antes de destruir
    cout << "Deconstruire " << this <<endl;
}
