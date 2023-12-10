#pragma once

#include "IComportement.h"

class ComportementGregaire : public IComportement
{
public:
	ComportementGregaire() { couleurIdx = 1; };
	double changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected);
	double changeVitesse(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected) { return b.getVitesse(); };
};