#include "ComportementPeureuse.h"


double ComportementPeureuse::changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected)
{
	double orientation = b.getOrientation();

	if (bestiolesDetected.size() >= static_cast<size_t>(Config::N_AUTOUR)) {
		double orientationSum = 0.0;
		for (const shared_ptr<Bestiole>& b2 : bestiolesDetected)
			orientationSum += b2->getOrientation();
		orientation = -(orientationSum / bestiolesDetected.size());
	}

	return orientation;
}


double ComportementPeureuse::changeVitesse(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected)
{
	double vitesse = b.getVitesse();

	if (bestiolesDetected.size() >= static_cast<size_t>(Config::N_AUTOUR) && b.getIsPeureuse() == false) {
		cout << "peureuse Bestiole(" << b.getIdentite() << ")" << endl;
		b.setIsPeureuse(true);
		vitesse *= Config::FUITE_COEFF;
	}
	return vitesse;
}
