#pragma once

#include "IComportement.h"


class ComportementPeureuse : public IComportement
{
public:
	ComportementPeureuse() { couleurIdx = 2; };
	ComportementPeureuse(const ComportementPeureuse& c) { couleurIdx = c.couleurIdx; };
	IComportement* clone() { return new ComportementPeureuse(*this); }
	double changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected);
	double changeVitesse(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected);
};