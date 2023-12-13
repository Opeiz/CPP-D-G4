#define _USE_MATH_DEFINES

#include "Nageoire.h"
#include "../Config.h"

#include <cmath>


Nageoire::Nageoire()
{
	info = "N";
	viteCoeff = static_cast<double>(rand()) / RAND_MAX * (Config::NU_MAX - Config::NU_MIN) + Config::NU_MIN;
	lentCoeff = 1.0;
	resistanceCoeff = 1.0;
	camouflageCoeff = 0;
}


Nageoire::Nageoire(const Nageoire& nageoire)
{
	info = nageoire.info;
	viteCoeff = nageoire.viteCoeff;
	lentCoeff = nageoire.lentCoeff;
	resistanceCoeff = nageoire.resistanceCoeff;
	camouflageCoeff = nageoire.camouflageCoeff;
}