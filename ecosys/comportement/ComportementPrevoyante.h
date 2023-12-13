#pragma once

#include "IComportement.h"


class ComportementPrevoyante : public IComportement
{
public:
	ComportementPrevoyante() { couleurIdx = 4; };
	ComportementPrevoyante(const ComportementPrevoyante& c) { couleurIdx = c.couleurIdx; };
	IComportement* clone() { return new ComportementPrevoyante(*this); }
	double changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected);
	double changeVitesse(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected) { return b.getVitesse(); };
};