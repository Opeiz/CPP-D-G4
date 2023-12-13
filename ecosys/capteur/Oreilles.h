#pragma once

#include "ICapteur.h"


class Oreilles : public ICapteur
{
public:
	Oreilles();
	Oreilles(const Oreilles& oreilles);
	ICapteur* clone() { return new Oreilles(*this); };
	bool isDetected(const Bestiole& b1, const Bestiole& b2) const;
};
