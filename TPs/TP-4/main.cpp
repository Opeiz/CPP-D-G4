#include <iostream>

#include "pine.h"


int main(int argc, char** argv) {
	std::cout << "Launching the main program - copy constructor" << std::endl;
	//Pine creation
	Pine p1;
	Pine p2;

	// Pine copy
	std :: cout << " Attempt to copy first Pine using the Copy constructor " << std :: endl ;
	Pine p3(p1) ;

	//Pine drawing
	p1.draw();
	p2.draw();
	p3.draw();

	//Pine info

	p1.info();
	p2.info();
	p3.info();

	std::cout << "End of main program - destroying heap objects" << std::endl;

	std::cout << "End of main program - destroying stack objects" << std::endl;
	return 0;
}