#pragma once

#include "IComportement.h"

class ComportementKamikaze : public IComportement
{
public:
	ComportementKamikaze() { couleurIdx = 3; };
	double changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected);
	double changeVitesse(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected) { return b.getVitesse(); };
};