#pragma once
#include "IAccessoire.h"

#include <memory>
#include <list>

using namespace std;


class Accessoires
{
private:
	list<shared_ptr<IAccessoire>> accessoiresList;

public:
	Accessoires();
	Accessoires(const Accessoires& accessoires);
	double getVitesseCoeff() const;
	double getResistanceCoeff() const;
	double getCamouflageCoeff() const;
	string getAccessoiresInfo() const;
};

