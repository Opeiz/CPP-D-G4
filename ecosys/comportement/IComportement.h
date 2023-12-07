#pragma once

#include "../Bestiole.h"


class IComportement
{
protected:
	int couleurIdx;

public:
	virtual double changeOrientation(Bestiole& b, list<Bestiole*>& listeBestiolesDetected) = 0;
	virtual double changeVitesse(Bestiole& b, list<Bestiole*>& listeBestiolesDetected) = 0;
	int getComportementIdx() const { return couleurIdx; }
};