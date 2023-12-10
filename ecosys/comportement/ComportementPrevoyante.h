#pragma once

#include "IComportement.h"

class ComportementPrevoyante : public IComportement
{
public:
	ComportementPrevoyante() { couleurIdx = 4; };
	double changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected);
	double changeVitesse(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected) { return b.getVitesse(); };
};