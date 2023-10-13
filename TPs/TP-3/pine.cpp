#include "pine.h"

#include <iostream>

using namespace std;

Pine::Pine(){
    cout << "Construire Pine " << this <<  endl;
}

void Pine::draw(){
    cout << "Pine draw"  << endl;
}

Pine::~Pine(){
    cout << "Deconstruire Pine" << endl;
}