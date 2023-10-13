#include "tree.h"
#include "pine.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    Tree *pOne = new Tree;
    Tree *pTwo = new Tree;
    Pine *pOneP = new Pine;
 
    // One.setHeight(6.25);
    cout << pOne->getHeight() << "\n";
    cout << pOne->isEvergreen() << "\n";

    cout << pTwo->getHeight() << "\n";
    cout << pTwo->isEvergreen() << "\n" ;

    pOne->draw();
    pOneP->draw();

    return 0;
}
