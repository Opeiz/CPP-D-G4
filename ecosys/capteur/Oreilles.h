#pragma once

#include "ICapteur.h"


class Oreilles : public ICapteur
{
public:
	Oreilles();
	Oreilles(Oreilles& oreilles);
	ICapteur* doCopy();
	bool isDetected(const Bestiole& b1, const Bestiole& b2) const;
};
