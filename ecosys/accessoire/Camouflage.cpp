#define _USE_MATH_DEFINES

#include "Camouflage.h"
#include "../Config.h"

#include <cmath>


Camouflage::Camouflage()
{
	info = "F";
	viteCoeff = 1.0;
	lentCoeff = 1.0;
	resistanceCoeff = 1.0;
	camouflageCoeff = static_cast<double>(rand()) / RAND_MAX * (Config::PSI_MAX - Config::PSI_MIN) + Config::PSI_MIN;
}


Camouflage::Camouflage(const Camouflage& camouflage)
{
	info = camouflage.info;
	viteCoeff = camouflage.viteCoeff;
	lentCoeff = camouflage.lentCoeff;
	resistanceCoeff = camouflage.resistanceCoeff;
	camouflageCoeff = camouflage.camouflageCoeff;
}
