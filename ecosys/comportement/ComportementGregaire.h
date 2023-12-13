#pragma once

#include "IComportement.h"


class ComportementGregaire : public IComportement
{
public:
	ComportementGregaire() { couleurIdx = 1; };
	ComportementGregaire(const ComportementGregaire& c) { couleurIdx = c.couleurIdx; };
	IComportement* clone() { return new ComportementGregaire(*this); }
	double changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected);
	double changeVitesse(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected) { return b.getVitesse(); };
};