#pragma once

#include "IAccessoire.h"


class Camouflage : public IAccessoire
{
public:
	Camouflage();
	Camouflage(const Camouflage& camouflage);
	IAccessoire* clone() { return new Camouflage(*this); };
};