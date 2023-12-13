#pragma once

#include "ICapteur.h"


class Yeux : public ICapteur
{
public:
	Yeux();
	Yeux(const Yeux& y);
	ICapteur* clone() { return new Yeux(*this); };
	bool isDetected(const Bestiole& b1, const Bestiole& b2) const;
};

