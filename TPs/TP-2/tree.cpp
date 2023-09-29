// Code de methode

#include "tree.h"

#include <iostream>

using namespace std;

Tree::Tree(){
    cout << "Construire " << this << endl;
}

void Tree::draw(){
    cout << R"(
               ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
jgs \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_   
)" << endl;
}

Tree::~Tree(){ // Ultima wea que haces antes de destruir
    cout << "Deconstruire " << this <<endl;
}
