#define _USE_MATH_DEFINES

#include "Oreilles.h"
#include <cmath>


Oreilles::Oreilles() {
	alpha = 2 * M_PI;
	delta = static_cast<double>(rand()) / RAND_MAX * (Config::DELTA_O_MAX - Config::DELTA_O_MIN) + Config::DELTA_O_MIN;
	gamma = static_cast<double>(rand()) / RAND_MAX * (Config::GAMMA_O_MAX - Config::GAMMA_O_MIN) + Config::GAMMA_O_MIN;
}


Oreilles::Oreilles(const Oreilles& oreilles) {
	alpha = oreilles.alpha;
	delta = oreilles.delta;
	gamma = oreilles.gamma;
}


bool Oreilles::isDetected(const Bestiole& b1, const Bestiole& b2) const {
	bool isdetected = false;
	double d = b1.getDistance(b2);
	double g = static_cast<double>(rand()) / RAND_MAX;

	//if (d <= delta) {
	//	cout << "Bestiole(" << b1.getIdentite() << ") has oreilles range Bestiole(" << b2.getIdentite() << ")";
	//	if (g <= gamma) {
	//		if (gamma > b2.getCamouflageCoeff()) {
	//			cout << ", detected";
	//			isdetected = true;
	//		}
	//		else cout << ", CamouflageCoeff miss";
	//	}
	//	else cout << ", gamma miss";

	//	cout << endl;
	//}
	if (d <= delta && g <= gamma && gamma > b2.getCamouflageCoeff()) {
		cout << "Bestiole(" << b1.getIdentite() << ") heard Bestiole(" << b2.getIdentite() << ")" << endl;
		isdetected = true;
	}
	return isdetected;
}
