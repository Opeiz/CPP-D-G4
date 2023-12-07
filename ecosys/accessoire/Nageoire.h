#pragma once

#include "IAccessoire.h"


class Nageoire : public IAccessoire
{
public:
	Nageoire();
	Nageoire(Nageoire& nageoire);
	IAccessoire* doCopy();
};