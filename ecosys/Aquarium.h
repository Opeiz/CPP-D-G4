#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#include "CImg.h"
#include "Config.h"

#include <iostream>

using namespace std;
using namespace cimg_library;

class Milieu;


class Aquarium : public CImgDisplay
{
private:
	Milieu* flotte;

	int            delay;

public:
	Config config;

	Aquarium(int width, int height, int _delay);
	~Aquarium(void);

	Milieu& getMilieu(void) { return *flotte; }
	void run(void);

};


#endif
