#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
width(_width), height(_height)
{

	cout << "const Milieu" << endl;

	std::srand(time(NULL));

}


Milieu::~Milieu(void)
{

	cout << "dest Milieu" << endl;

}


void Milieu::step(void)
{
	cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

	for (list<shared_ptr<Bestiole>>::iterator it = listeBestioles.begin(); it != listeBestioles.end();)
	{
		(*it)->action(*this);

		if ((*it)->getIsAlive() == false) {
			it = listeBestioles.erase(it);
		}
		else {
			(*it)->draw(*this);
			++it;
		}
	}
}

