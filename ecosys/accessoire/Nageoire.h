#pragma once

#include "IAccessoire.h"


class Nageoire : public IAccessoire
{
public:
	Nageoire();
	Nageoire(const Nageoire& nageoire);
	IAccessoire* clone() { return new Nageoire(*this); }
};