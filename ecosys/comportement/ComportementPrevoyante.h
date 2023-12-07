#pragma once

#include "IComportement.h"

class ComportementPrevoyante : public IComportement
{
public:
	ComportementPrevoyante() { couleurIdx = 4; };
	double changeOrientation(Bestiole& b, list<Bestiole*>& listeBestiolesDetected);
	double changeVitesse(Bestiole& b, list<Bestiole*>& listeBestiolesDetected) { return b.getVitesse(); };
};