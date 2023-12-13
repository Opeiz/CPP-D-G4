#pragma once

#include "IAccessoire.h"


class Carapace : public IAccessoire
{
public:
	Carapace();
	Carapace(const Carapace& carapace);
	IAccessoire* clone() { return new Carapace(*this); };
};