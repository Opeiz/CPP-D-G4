#pragma once

#include "IAccessoire.h"


class Carapace : public IAccessoire
{
public:
	Carapace();
	Carapace(Carapace& carapace);
	IAccessoire* doCopy();
};