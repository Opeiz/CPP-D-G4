#include <iostream>
#include <vector>

#include "pine.h"

using namespace std;

int main(int argc, char** argv) {
	cout << "Launching the main program" << endl;
	//Pine creation
	Pine p1;
	Pine p2;

	p1.info();
	p2.info();

	vector<Pine> forest;

	forest.push_back(p1);
	forest.push_back(p2);

	cout << "End of main program - destroying heap objects" << endl;

	cout << "End of main program - destroying stack objects" << endl;
	return 0;
}