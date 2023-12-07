#define _USE_MATH_DEFINES

#include "Yeux.h"
#include <cmath>

Yeux::Yeux() {
	alpha = static_cast<double>(rand()) / RAND_MAX * (Config::ALPHA_MAX - Config::ALPHA_MIN) + Config::ALPHA_MIN;
	delta = static_cast<double>(rand()) / RAND_MAX * (Config::DELTA_Y_MAX - Config::DELTA_Y_MIN) + Config::DELTA_Y_MIN;
	gamma = static_cast<double>(rand()) / RAND_MAX * (Config::GAMMA_Y_MAX - Config::GAMMA_Y_MIN) + Config::GAMMA_Y_MIN;
}

Yeux::Yeux(Yeux& y) {
	alpha = y.alpha;
	delta = y.delta;
	gamma = y.gamma;
}

ICapteur* Yeux::doCopy() {
	return new Yeux(*this);
}

bool Yeux::isDetected(const Bestiole& b1, const Bestiole& b2) const {
	bool isdetected = false;
	double d = sqrt((b2.getX() - b1.getX()) * (b2.getX() - b1.getX()) + (b2.getY() - b1.getY()) * (b2.getY() - b1.getY()));
	double a = acos((b2.getX() - b1.getX()) / d);  // acos [0, pi]
	if (b1.getOrientation() > M_PI) {
		a = 2 * M_PI - a;
	}
	double a_max = b1.getOrientation() + alpha / 2;
	double a_min = b1.getOrientation() - alpha / 2;
	double g = static_cast<double>(rand()) / RAND_MAX;

	//if (d <= delta && a >= a_min && a <= a_max) {
	//	cout << "Bestiole(" << b1.getIdentite() << ") has yeux range Bestiole("  << b2.getIdentite() << ")";
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
	if (d <= delta && a >= a_min && a <= a_max && g <= gamma && gamma > b2.getCamouflageCoeff()) {
		cout << "Bestiole(" << b1.getIdentite() << ") saw Bestiole(" << b2.getIdentite() << ")" << endl;
		isdetected = true;
	}

	return isdetected;
}
