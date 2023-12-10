#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"
#include "Config.h"

#include <iostream>
#include <memory>
#include <list>
#include <map>
#include <vector>

#include "accessoire/IAccessoire.h"

using namespace std;

class Milieu;
class ICapteur;
class IComportement;


class Bestiole
{

private:
	static const double     AFF_SIZE;
	static const double     MAX_VITESSE;
	static const double     LIMITE_VUE;

	static int              next;

private:
	int               identite;
	int               x, y;
	double            cumulX, cumulY;
	double            orientation;
	double            vitesse;
	int age;
	int maxAge;

	bool isAlive;
	int lastCollisionAge;

	bool isMultiple;
	bool isPeureuse;
	int lastAgirAge;

	T* couleur;

	list<shared_ptr<ICapteur>> capteurs;
	map<string, shared_ptr<IAccessoire>> accessoires;
	shared_ptr<IComportement> comportement;


private:
	void setCapteursEtAccessoires();
	void setComportement();
	void setCouleur();
	void aging();
	void checkCollision(list<Bestiole>& listeBestioles);
	void rebondir();
	void cloner(list<Bestiole>& listeBestioles, int xLim, int yLim);
	void detecterEtAgir(list<Bestiole>& listeBestioles);
	void bouge(int xLim, int yLim);

public:                                           // Forme canonique :
	Bestiole(void);                               // Constructeur par defaut
	Bestiole(const Bestiole& b);                 // Constructeur de copies
	~Bestiole(void);                              // Destructeur
	
	friend bool operator==(const Bestiole& b1, const Bestiole& b2);

	void initCoords(int xLim, int yLim);
	void action(Milieu& monMilieu);
	void draw(UImg& support);

	double getVitesseCoeff() const;
	double getResistanceCoeff() const;
	double getCamouflageCoeff() const;

	int getIdentite() const { return identite; }
	bool getIsAlive() const { return isAlive; }
	double getX() const { return x * 1.0; }
	double getY() const { return y * 1.0; }
	double getOrientation() const { return normalizeRadian(orientation); }
	double getVitesse() const { return vitesse; }
	double normalizeRadian(double radian) const;
	bool getIsPeureuse() const { return isPeureuse; }
	void setIsPeureuse(const bool res) { isPeureuse = res; }
	double distanceToBst(const Bestiole &b);
};


#endif
