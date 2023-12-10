#include "ComportementPeureuse.h"


double ComportementPeureuse::changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected)
{
	double orientation = b.getOrientation();

	if (listeBestiolesDetected.size() >= Config::N_AUTOUR) {
		double orientationSum = 0.0;
		for (shared_ptr<Bestiole> b2 : listeBestiolesDetected)
			orientationSum += b2->getOrientation();
		orientation = -(orientationSum / listeBestiolesDetected.size());
	}

	return orientation;
}

double ComportementPeureuse::changeVitesse(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected)
{
	double vitesse = b.getVitesse();

	if (listeBestiolesDetected.size() >= Config::N_AUTOUR && b.getIsPeureuse() == false) {
		cout << "peureuse Bestiole(" << b.getIdentite() << ")" << endl;
		b.setIsPeureuse(true);
		vitesse *= Config::FUITE_COEFF;
	}
	return vitesse;
}
