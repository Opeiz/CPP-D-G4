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
	std::list<Bestiole>   listeBestioles;

public:
	Milieu(int _width, int _height);
	~Milieu(void);

	int getWidth(void) const { return width; };
	int getHeight(void) const { return height; };

	void step(void);

	void addMember() { 
		listeBestioles.push_back(Bestiole());
		listeBestioles.back().initCoords(width, height); 
	}

	list<Bestiole>& getListeBestioles() { return listeBestioles; };
};


#endif
