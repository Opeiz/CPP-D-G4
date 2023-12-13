#pragma once

#include <string>

using namespace std;


class IAccessoire
{
protected:
	string info;
	double viteCoeff;
	double lentCoeff;
	double resistanceCoeff;
	double camouflageCoeff;

public:
	virtual IAccessoire* clone() = 0;
	string getInfo() const { return info; };
	double getViteCoeff() const { return viteCoeff; };
	double getLentCoeff() const { return lentCoeff; };
	double getResistanceCoeff() const { return resistanceCoeff; };
	double getCamouflageCoeff() const { return camouflageCoeff; };
};