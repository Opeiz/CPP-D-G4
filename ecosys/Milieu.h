#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <list>
#include <memory>

using namespace std;


class Milieu : public UImg
{

private:
	static const T          white[];

	int                     width, height;
	list<shared_ptr<Bestiole>>   listeBestioles;

public:
	Milieu(int _width, int _height);
	~Milieu(void);

	int getWidth(void) const { return width; };
	int getHeight(void) const { return height; };

	void step(void);

	void addMember() { 
		shared_ptr<Bestiole> b_ptr(new Bestiole());
		listeBestioles.push_back(b_ptr);
		listeBestioles.back()->initCoords(width, height); 
	}

	list<shared_ptr<Bestiole>>& getListeBestioles() { return listeBestioles; };
};


#endif
