#pragma once


class IAccessoire
{
protected:
	double viteCoeff;
	double lentCoeff;
	double resistanceCoeff;
	double camouflageCoeff;

public:
	virtual IAccessoire* doCopy() = 0;
	double getViteCoeff() const { return viteCoeff; };
	double getLentCoeff() const { return lentCoeff; };
	double getResistanceCoeff() const { return resistanceCoeff; };
	double getCamouflageCoeff() const { return camouflageCoeff; };
};