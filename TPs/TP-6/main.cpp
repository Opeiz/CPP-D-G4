#include <iostream>

#include "utils.h"
#include "pine.h"

using namespace std;

int main(int argc, char** argv){
    cout << "Launching Program " << endl;

    Pine a;
    Pine b;

    cout << "a size " << a.height <<" & b size " << b.height << endl ;
    // cout << "Is a smaller than b ? " << smallerThan <Pine >(a, b) << endl ;

    cout << "End of main program - destroying heap objects " << endl ;
    cout << "End of main program - destroying stack objects " << endl ;

}