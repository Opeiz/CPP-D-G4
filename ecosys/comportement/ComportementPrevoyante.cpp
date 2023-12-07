
#define _USE_MATH_DEFINES

#include "ComportementPrevoyante.h"

#include <cmath>


double ComportementPrevoyante::changeOrientation(Bestiole& b, list<Bestiole*>& listeBestiolesDetected)
{
	double orientation = b.getOrientation();
	Bestiole* bMin = *listeBestiolesDetected.begin();
	double dMin = sqrt((bMin->getX() - b.getX()) * (bMin->getX() - b.getX()) + (bMin->getY() - b.getY()) * (bMin->getY() - b.getY()));

	for (Bestiole* b2 : listeBestiolesDetected) {
		double d = sqrt((b2->getX() - b.getX()) * (b2->getX() - b.getX()) + (b2->getY() - b.getY()) * (b2->getY() - b.getY()));
		if (d < dMin) {
			bMin = b2;
		}
	}

	double a1 = acos((bMin->getX() - b.getX()) / dMin);  // acos [0, pi]
	if (b.getOrientation() > M_PI) {
		a1 = 2 * M_PI - a1;
	}
	double a2 = acos((b.getX() - bMin->getX()) / dMin);  // acos [0, pi]
	if (bMin->getOrientation() > M_PI) {
		a2 = 2 * M_PI - a2;
	}

	double orientationMin = min(a1, bMin->getOrientation());
	double orientationMax = max(a1, bMin->getOrientation());
	double avoidRange = 0.3;

	if (orientationMax - orientationMin <= M_PI && orientation >= orientationMin - avoidRange && orientation <= orientationMax + avoidRange)
		orientation = -(orientationMax + orientationMin) / 2;
	else if (orientationMax - orientationMin > M_PI && orientation <= orientationMin + avoidRange && orientation >= orientationMax - avoidRange)
		orientation = (orientationMax + orientationMin) / 2;

	return orientation;
}
