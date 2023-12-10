#pragma once

#include "IComportement.h"

class ComportementPeureuse : public IComportement
{
public:
	ComportementPeureuse() { couleurIdx = 2; };
	double changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected);
	double changeVitesse(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected);
};