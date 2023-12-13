
#define _USE_MATH_DEFINES

#include "ComportementPrevoyante.h"

#include <cmath>


double ComportementPrevoyante::changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected)
{
	double orientation = b.getOrientation();
	shared_ptr<Bestiole> bMin = *(bestiolesDetected.begin());
	double dMin = b.getDistance(*bMin);

	for (const shared_ptr<Bestiole>& b2 : bestiolesDetected) {
		double d = b.getDistance(*b2);
		if (d < dMin) {
			bMin = b2;
			dMin = d;
		}
	}

	double a1 = b.getAngularDistance(*bMin);

	double orientationMin = min(a1, bMin->getOrientation());
	double orientationMax = max(a1, bMin->getOrientation());
	double avoidRange = 0.3;

	if (orientationMax - orientationMin <= M_PI && orientation >= orientationMin - avoidRange && orientation <= orientationMax + avoidRange)
		orientation = -(orientationMax + orientationMin) / 2;
	else if (orientationMax - orientationMin > M_PI && orientation <= orientationMin + avoidRange && orientation >= orientationMax - avoidRange)
		orientation = (orientationMax + orientationMin) / 2;

	return orientation;
}
