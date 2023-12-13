#define _USE_MATH_DEFINES

#include "Bestiole.h"
#include "Milieu.h"
#include "Config.h"
#include "capteur/Yeux.h"
#include "capteur/Oreilles.h"
#include "comportement/ComportementGregaire.h"
#include "comportement/ComportementPeureuse.h"
#include "comportement/ComportementKamikaze.h"
#include "comportement/ComportementPrevoyante.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>


using namespace std;

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;

int               Bestiole::next = 0;


Bestiole::Bestiole(void)
{
	identite = ++next;

	cout << "const Bestiole (" << identite << ") par defaut" << endl;

	x = y = 0;
	cumulX = cumulY = 0.;
	orientation = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;  // [0, 2*pi]
	vitesse = static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE;

	couleur = new T[3];

	age = 0;
	maxAge = rand() % Config::MAX_AGE + Config::MIN_AGE;
	lastCollisionAge = 0;
	isAlive = true;
	isPeureuse = false;
	lastAgirAge = 0;

	setCapteurs();
	accessoires = Accessoires();

	isMultiple = (rand() % 5 == 0);
	setComportement();
}


Bestiole::Bestiole(const Bestiole& b)
{
	identite = ++next;

	cout << "const Bestiole (" << identite << ") par copie" << endl;

	x = b.x;
	y = b.y;
	cumulX = cumulY = 0.;
	orientation = b.orientation;
	vitesse = b.vitesse;
	couleur = new T[3];
	memcpy(couleur, b.couleur, 3 * sizeof(T));

	age = b.age;
	maxAge = b.maxAge;
	lastCollisionAge = b.lastCollisionAge;
	isAlive = b.isAlive;
	isMultiple = b.isMultiple;
	isPeureuse = b.isPeureuse;
	lastAgirAge = b.lastAgirAge;

	
	// capteurs = b.capteurs;
	// comportement = b.comportement

	for (shared_ptr<ICapteur> pCapteurB : b.capteurs) {
		shared_ptr<ICapteur>  pCapteur(pCapteurB->clone());
		capteurs.push_back(pCapteur);
	}

	accessoires = Accessoires(b.accessoires);

	shared_ptr<IComportement>  pComportement(b.comportement->clone());
	comportement = pComportement;
}


Bestiole::~Bestiole(void)
{

	delete[] couleur;
	
	cout << "dest Bestiole" << this << endl;
}


void Bestiole::initCoords(int xLim, int yLim)
{
	x = rand() % xLim;
	y = rand() % yLim;
}


void Bestiole::setCapteurs() {
	if (static_cast<double>(rand()) / RAND_MAX < 0.5) {
		shared_ptr<ICapteur> pCapteur(new Yeux());
		capteurs.push_back(pCapteur);
	}

	if (static_cast<double>(rand()) / RAND_MAX < 0.5) {
		shared_ptr<ICapteur> pCapteur(new Oreilles());
		capteurs.push_back(pCapteur);
	}
}


void Bestiole::setComportement() {
	int i = rand() % 4 + 1;
	switch (i) {
	case 1:
		comportement = make_shared<ComportementGregaire>();
		break;
	case 2:
		comportement = make_shared<ComportementPeureuse>();
		break;
	case 3:
		comportement = make_shared<ComportementKamikaze>();
		break;
	case 4:
		comportement = make_shared<ComportementPrevoyante>();
		break;
	default:
		cout << "Error: setComportement()" << endl;
	}

	setCouleur();
}


void Bestiole::setCouleur()
{
	// Choose color according to comportement
	int couleurIdx = comportement->getComportementIdx();

	switch (couleurIdx) {
	case 1:
		couleur[0] = 50;
		couleur[1] = 205;
		couleur[2] = 50;
		break;
	case 2:
		couleur[0] = 148;
		couleur[1] = 0;
		couleur[2] = 211;
		break;
	case 3:
		couleur[0] = 255;
		couleur[1] = 0;
		couleur[2] = 0;
		break;
	case 4:
		couleur[0] = 30;
		couleur[1] = 144;
		couleur[2] = 255;
		break;

	default:
		couleur[0] = 169;
		couleur[1] = 169;
		couleur[2] = 169;
	}
}


bool operator==(const Bestiole& b1, const Bestiole& b2)
{
	return (b1.identite == b2.identite);
}


double Bestiole::normalizeOrientation(double orientationNew) const {
	// Gets the orientation back in the [0, 2pi) range
	while (orientationNew < 0) {
		orientationNew += 2 * M_PI;
	}

	while (orientationNew >= 2 * M_PI) {
		orientationNew -= 2 * M_PI;
	}

	return orientationNew;
}


double Bestiole::getAngularDistance(const Bestiole& b2) const {
	// Get the angle of the segment between this bestiole and b2
	double angular = acos((b2.x - x) / getDistance(b2));  // acos [0, pi]
	if (orientation > M_PI) {
		angular = 2 * M_PI - angular;
	}
	return angular;
}


void Bestiole::bouge(int xLim, int yLim)
{	
	double vitesseWithCoeff = vitesse * accessoires.getVitesseCoeff();
	if (vitesseWithCoeff > MAX_VITESSE) vitesseWithCoeff = MAX_VITESSE;

	double         nx, ny;
	double         dx = cos(orientation) * vitesseWithCoeff;
	double         dy = -sin(orientation) * vitesseWithCoeff;
	int            cx, cy;

	cx = static_cast<int>(cumulX); cumulX -= cx;
	cy = static_cast<int>(cumulY); cumulY -= cy;

	nx = x + dx + cx;
	ny = y + dy + cy;

	// if x reached the bound
	if ((nx < 0) || (nx > xLim - 1)) {
		orientation = normalizeOrientation(M_PI - orientation);
		cumulX = 0.;
	}
	else {
		x = static_cast<int>(nx);
		cumulX += nx - x;
	}

	// if y reached the bound
	if ((ny < 0) || (ny > yLim - 1)) {
		orientation = normalizeOrientation(-orientation);
		cumulY = 0.;
	}
	else {
		y = static_cast<int>(ny);
		cumulY += ny - y;
	}
}


void Bestiole::action(Milieu& monMilieu) {
	/*
	Each bestiole goes through the following steps:
		1 - Aging and dying if too old
		2 - Checking for collisions with other bestioles
		3 - Reproducing with probability Config::CLONAGE_RATE
		4 - Moving with previous speed
		5 - Detect other bestioles and set next speed and orientation accordingly
	*/

	aging();
	if (isAlive == false) return;

	checkCollision(monMilieu.getListeBestioles());
	if (isAlive == false) return;

	cloner(monMilieu.getListeBestioles(), monMilieu.getWidth(), monMilieu.getHeight());
	bouge(monMilieu.getWidth(), monMilieu.getHeight());
	detecterEtAgir(monMilieu.getListeBestioles());

}


void Bestiole::draw(UImg& support)
{
	double         xt = x + cos(orientation) * AFF_SIZE / 2.1;
	double         yt = y - sin(orientation) * AFF_SIZE / 2.1;
	support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
	support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);

	string s = to_string(identite);
	if (isMultiple) s += " (m)";
	s += " " + accessoires.getAccessoiresInfo();
	char const* identiteChar = s.c_str();
	const T white[] = { (T)255, (T)255, (T)255 };
	support.draw_text(x-6, y + AFF_SIZE, identiteChar, 0, white);

	/* draw capteurs */
	for (shared_ptr<ICapteur> pCapteur : capteurs) {
		if (pCapteur->getAlpha() == 2 * M_PI) {
			// draw oreilles range
			support.draw_circle(x, y, pCapteur->getDelta(), couleur, 0.1);
		}
		else {
			// draw yeux range
			double x2 = x + cos(orientation + pCapteur->getAlpha() / 2) * pCapteur->getDelta();
			double y2 = y - sin(orientation + pCapteur->getAlpha() / 2) * pCapteur->getDelta();
			double x3 = x + cos(orientation - pCapteur->getAlpha() / 2) * pCapteur->getDelta();
			double y3 = y - sin(orientation - pCapteur->getAlpha() / 2) * pCapteur->getDelta();
			support.draw_line(x, y, x2, y2, couleur, 0.2);
			support.draw_line(x, y, x3, y3, couleur, 0.2);
		}
	}
}


void Bestiole::aging() {
	// Increases age and checks for death
	if (age >= maxAge) {
		cout << "aged death Bestiole(" << identite << ")" << endl;
		isAlive = false;
	}
	else
		++age;
}


void Bestiole::checkCollision(list<shared_ptr<Bestiole>>& listeBestioles) {
	for (shared_ptr<Bestiole>& b : listeBestioles) {
		// If b is not this, and is alive
		if (!(*this == *b) && b->isAlive) {
			// If en collision
			if (abs(x - b->x) <= Config::COLLISION_RANGE && abs(y - b->y) <= Config::COLLISION_RANGE && age - lastCollisionAge > 5) {
				cout << "collison entre Bestiole(" << identite << ") et Bestiole(" << b->identite << ")" << endl;
				// lastCollisionAge prevents double checking the same collision
				lastCollisionAge = age;
				b->lastCollisionAge = b->age;

				double r0 = static_cast<double>(rand()) / RAND_MAX;
				double r1 = static_cast<double>(rand()) / RAND_MAX;
				double deathRate0 = Config::COLLISION_DEATH_RATE * accessoires.getResistanceCoeff();
				double deathRate1 = Config::COLLISION_DEATH_RATE * b->accessoires.getResistanceCoeff();
				// cout << r0 << " " << r1 << endl;

				// Check death for both bestioles
				if (r0 < deathRate0) {
					cout << "collision death Bestiole(" << identite << ")" << endl;
					isAlive = false;
				}
				else
					rebondir();

				if (r1 < deathRate1) {
					cout << "collision death Bestiole(" << b->identite << ")" << endl;
					b->isAlive = false;
				}
				else
					b->rebondir();
			}
		}
	}
}


void Bestiole::rebondir() {
	cout << "rebondir Bestiole(" << identite << ")" << endl;
	orientation = normalizeOrientation(orientation + M_PI);
}


void Bestiole::cloner(list<shared_ptr<Bestiole>>& listeBestioles, int xLim, int yLim) {
	// Clones bestiole with probability Config::CLONAGE_RATE
	double r = static_cast<double>(rand()) / RAND_MAX;
	if (r < Config::CLONAGE_RATE && isAlive) {
		cout << "clonage Bestiole(" << identite << ")" << endl;
		shared_ptr<Bestiole> pBestiole(new Bestiole(*this));
		pBestiole->age = 0;
		pBestiole->initCoords(xLim, yLim);
		pBestiole->orientation = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
		pBestiole->lastCollisionAge = 0;
		pBestiole->isPeureuse = false;
		pBestiole->lastAgirAge = 0;
		listeBestioles.push_back(pBestiole);
	}
}


void Bestiole::detecterEtAgir(list<shared_ptr<Bestiole>>& listeBestioles) {
	/*
	Checks detection of other bestioles and then sets orientation and speed accordingly.
	For multiple personality bestioles it also reassigns its comportement with probability
	Config::COMPORTEMTNT_CHANGE_RATE
	*/

	set<shared_ptr<Bestiole>> bestiolesDetected;
	for (shared_ptr<ICapteur> pCapteur : capteurs) {
		for (shared_ptr<Bestiole>& b : listeBestioles) {
			if (!(*this == *b) && b->isAlive) {
				bool isdetected = pCapteur->isDetected(*this, *b);
				if (isdetected) {
					//system("pause");
					bestiolesDetected.insert(b);
				}
			}
		}
	}

	bool isSetComportement = false;
	if (isMultiple == true) {
		double r = static_cast<double>(rand()) / RAND_MAX;
		if (r < Config::COMPORTEMTNT_CHANGE_RATE) {
			// TODO: reduce speed if it's currently a peureuse bestiole that's scared
			cout << "changed comportement Bestiole(" << identite << ")" << endl;
			setComportement();
		}
	}

	// Check for the end of the scared state of peureuse bestioles
	if ((isPeureuse == true && age - lastAgirAge >= Config::PEUREUSE_DURATION) || isSetComportement) {
		cout << "end peureuse Bestiole(" << identite << ")" << endl;
		vitesse /= Config::FUITE_COEFF;
		isPeureuse = false;
	}

	if (bestiolesDetected.size() > 0 && age - lastAgirAge > 10) {
		double orientationNew = normalizeOrientation(comportement->changeOrientation(*this, bestiolesDetected));
		double vitesseNew = comportement->changeVitesse(*this, bestiolesDetected);

		if (orientation != orientationNew || vitesse != vitesseNew) {
			orientation = orientationNew;
			vitesse = vitesseNew;
			lastAgirAge = age;  // avoid getting stuck when repeatedly setting orientation
		}
	}
}
