#pragma once

#include "IComportement.h"

class ComportementKamikaze : public IComportement
{
public:
	ComportementKamikaze() { couleurIdx = 3; };
	double changeOrientation(Bestiole& b, list<Bestiole*>& listeBestiolesDetected);
	double changeVitesse(Bestiole& b, list<Bestiole*>& listeBestiolesDetected) { return b.getVitesse(); };
};