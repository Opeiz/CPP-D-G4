#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"
#include "Config.h"
#include "accessoire/Accessoires.h"

#include <iostream>
#include <memory>
#include <list>
#include <map>
#include <set>
#include <string>

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

	int               identite;
	int               x, y;
	double            cumulX, cumulY;
	double            orientation;
	double            vitesse;
	int age;
	int maxAge;
	T* couleur;

	bool isAlive;
	bool isMultiple;
	bool isPeureuse;
	int lastCollisionAge;
	int lastAgirAge;

	list<shared_ptr<ICapteur>> capteurs;
	Accessoires accessoires;
	shared_ptr<IComportement> comportement;

private:
	void setCapteurs();
	void setComportement();
	void setCouleur();
	void aging();
	void checkCollision(list<shared_ptr<Bestiole>>& listeBestioles);
	void rebondir();
	void cloner(list<shared_ptr<Bestiole>>& listeBestioles, int xLim, int yLim);
	void detecterEtAgir(list<shared_ptr<Bestiole>>& listeBestioles);
	void bouge(int xLim, int yLim);

public:                                           // Forme canonique :
	Bestiole(void);                               // Constructeur par defaut
	Bestiole(const Bestiole& b);                 // Constructeur de copies
	~Bestiole(void);                              // Destructeur
	
	friend bool operator==(const Bestiole& b1, const Bestiole& b2);

	void initCoords(int xLim, int yLim);
	void action(Milieu& monMilieu);
	void draw(UImg& support);

	int getIdentite() const { return identite; }
	bool getIsAlive() const { return isAlive; }
	double getOrientation() const { return normalizeOrientation(orientation); }
	double getVitesse() const { return vitesse; }
	double getDistance(const Bestiole& b2) const { return sqrt((b2.x - x) * (b2.x - x) + (b2.y - y) * (b2.y - y)); };
	double getAngularDistance(const Bestiole& b2) const;
	double normalizeOrientation(double orientationNew) const;
	bool getIsPeureuse() const { return isPeureuse; }
	void setIsPeureuse(const bool res) { isPeureuse = res; }
	double getCamouflageCoeff() const { return accessoires.getCamouflageCoeff(); }

	int getComportementInfo() const;
	list<int> getCapteurInfo() const;
	string getAccessoiresInfo() const;
};


#endif
