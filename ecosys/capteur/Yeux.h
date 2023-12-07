#pragma once

#include "ICapteur.h"


class Yeux : public ICapteur
{
public:
	Yeux();
	Yeux(Yeux& y);
	ICapteur* doCopy();
	bool isDetected(const Bestiole& b1, const Bestiole& b2) const;
};

