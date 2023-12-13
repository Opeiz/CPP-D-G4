#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <list>

using namespace std;


class Milieu : public UImg
{

private:
	static const T          white[];

	int                     width, height;
	list<shared_ptr<Bestiole>>   listeBestioles;

	int nStep;

public:
	Milieu(int _width, int _height);
	~Milieu(void);

	int getWidth(void) const { return width; };
	int getHeight(void) const { return height; };

	void step(void);

	void addMember() { 
		shared_ptr<Bestiole> pBestiole(new Bestiole());
		listeBestioles.push_back(pBestiole);
		listeBestioles.back()->initCoords(width, height); 
	}

	list<shared_ptr<Bestiole>>& getListeBestioles() { return listeBestioles; };
	int getNStep() const { return nStep; }
};


#endif
