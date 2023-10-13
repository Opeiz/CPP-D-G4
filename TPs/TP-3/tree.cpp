// Code de methode

#include "tree.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

Tree::Tree():height(10.0),evergreen(0){
  cout << "Construire " << this << endl;
}

void Tree::setEvergreen (bool p){
  evergreen = p;
}

bool Tree::isEvergreen () const{
  return evergreen;
}

void Tree::setHeight (double h){
    height = h;
}

double Tree::getHeight () const{
  return height;
}

void Tree::draw(){
  cout << "Tree Draw" << endl;
}

Tree::~Tree(){ // Ultima wea que haces antes de destruir
    cout << "Deconstruire " << this <<endl;
}
