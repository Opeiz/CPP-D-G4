#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{
	Aquarium ecosysteme(640, 480, 30);
	for (int i = 1; i <= 10; ++i) {
		ecosysteme.getMilieu().addMember();
	}

	ecosysteme.run();

	return 0;

}
