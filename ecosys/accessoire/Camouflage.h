#pragma once

#include "IAccessoire.h"


class Camouflage : public IAccessoire
{
public:
	Camouflage();
	Camouflage(Camouflage& camouflage);
	IAccessoire* doCopy();
};