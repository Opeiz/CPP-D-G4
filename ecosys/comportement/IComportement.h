#ifndef ICOMPORT_H
#define ICOMPORT_H

#include "../Bestiole.h"


class IComportement
{
protected:
	int couleurIdx;

public:
	virtual IComportement* clone() = 0;
	virtual double changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected) = 0;
	virtual double changeVitesse(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected) = 0;
	int getComportementIdx() const { return couleurIdx; }
};


#endif // ICOMPORT_H