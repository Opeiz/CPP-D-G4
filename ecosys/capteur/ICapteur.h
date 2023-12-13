#pragma once

#include "../Bestiole.h"


class ICapteur
{
protected:
	double alpha;
	double delta;
	double gamma;

public:
	virtual ICapteur* clone()=0;
	virtual bool isDetected(const Bestiole& b1, const Bestiole& b2) const = 0;
	double getAlpha() const { return alpha; }
	double getDelta() const { return delta; }
	double getGamma() const { return gamma; }
};

