#define _USE_MATH_DEFINES

#include "ComportementKamikaze.h"

#include <cmath>


double ComportementKamikaze::changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected)
{
	shared_ptr<Bestiole> bMin = *listeBestiolesDetected.begin();
	double dMin = sqrt((bMin->getX() - b.getX()) * (bMin->getX() - b.getX()) + (bMin->getY() - b.getY()) * (bMin->getY() - b.getY()));

	for (shared_ptr<Bestiole> b2 : listeBestiolesDetected) {
		double d = sqrt((b2->getX() - b.getX()) * (b2->getX() - b.getX()) + (b2->getY() - b.getY()) * (b2->getY() - b.getY()));
		if (d < dMin) {
			bMin = b2;
			dMin = d;
		}
	}

	double a = acos((bMin->getX() - b.getX()) / dMin);  // acos [0, pi]
	if (b.getOrientation() > M_PI) {
		a = 2 * M_PI - a;
	}

	return a;
}
