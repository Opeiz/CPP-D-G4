#define _USE_MATH_DEFINES

#include "Carapace.h"
#include "../Config.h"
#include <cmath>

Carapace::Carapace()
{
	viteCoeff = 1.0;
	lentCoeff = static_cast<double>(rand()) / RAND_MAX * (Config::ETA_MAX - Config::ETA_MIN) + Config::ETA_MIN;
	resistanceCoeff = static_cast<double>(rand()) / RAND_MAX * (Config::OMEGA_MAX - Config::OMEGA_MIN) + Config::OMEGA_MIN;
	camouflageCoeff = 0;
}

Carapace::Carapace(Carapace& carapace)
{
	viteCoeff = carapace.viteCoeff;
	lentCoeff = carapace.lentCoeff;
	resistanceCoeff = carapace.resistanceCoeff;
	camouflageCoeff = carapace.camouflageCoeff;
}

IAccessoire* Carapace::doCopy()
{
	return new Carapace(*this);
}
