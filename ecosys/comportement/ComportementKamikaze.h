#pragma once

#include "IComportement.h"


class ComportementKamikaze : public IComportement
{
public:
	ComportementKamikaze() { couleurIdx = 3; };
	ComportementKamikaze(const ComportementKamikaze& c) { couleurIdx = c.couleurIdx; };
	IComportement* clone() { return new ComportementKamikaze(*this); }
	double changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected);
	double changeVitesse(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected) { return b.getVitesse(); };
};