#define _USE_MATH_DEFINES

#include "Camouflage.h"
#include "../Config.h"
#include <cmath>

Camouflage::Camouflage()
{
	viteCoeff = 1.0;
	lentCoeff = 1.0;
	resistanceCoeff = 1.0;
	camouflageCoeff = static_cast<double>(rand()) / RAND_MAX * (Config::PSI_MAX - Config::PSI_MIN) + Config::PSI_MIN;
}

Camouflage::Camouflage(Camouflage& camouflage)
{
	viteCoeff = camouflage.viteCoeff;
	lentCoeff = camouflage.lentCoeff;
	resistanceCoeff = camouflage.resistanceCoeff;
	camouflageCoeff = camouflage.camouflageCoeff;
}

IAccessoire* Camouflage::doCopy()
{
	return new Camouflage(*this);
}
