#define _USE_MATH_DEFINES

#include "ComportementKamikaze.h"

#include <cmath>


double ComportementKamikaze::changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected)
{
	shared_ptr<Bestiole> bMin = *(bestiolesDetected.begin());  // the nearest bestiole of b
	double dMin = b.getDistance(*bMin);
	for (const shared_ptr<Bestiole>& b2 : bestiolesDetected) {
		double d = b.getDistance(*b2);
		if (d < dMin) {
			bMin = b2;
			dMin = d;
		}
	}

	double a = b.getAngularDistance(*bMin);

	return a;
}
