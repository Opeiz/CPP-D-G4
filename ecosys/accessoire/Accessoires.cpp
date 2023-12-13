#include "Accessoires.h"
#include "Nageoire.h"
#include "Carapace.h"
#include "Camouflage.h"


Accessoires::Accessoires()
{
	if (static_cast<double>(rand()) / RAND_MAX < 0.5) {
		shared_ptr<IAccessoire> pAccessoire(new Nageoire());
		accessoiresList.push_back(pAccessoire);
	}

	if (static_cast<double>(rand()) / RAND_MAX < 0.5) {
		shared_ptr<IAccessoire> pAccessoire(new Carapace());
		accessoiresList.push_back(pAccessoire);
	}

	if (static_cast<double>(rand()) / RAND_MAX < 0.5) {
		shared_ptr<IAccessoire> pAccessoire(new Camouflage());
		accessoiresList.push_back(pAccessoire);
	}
}


Accessoires::Accessoires(const Accessoires& accessoires)
{
	for (shared_ptr<IAccessoire> pAccessoireB : accessoires.accessoiresList) {
		shared_ptr<IAccessoire>  pAccessoire(pAccessoireB->clone());
		accessoiresList.push_back(pAccessoire);
	}
}


double Accessoires::getVitesseCoeff() const
{
	double vitesseCoeff = 1.0;
	for (shared_ptr<IAccessoire> accessoire : accessoiresList) {
		vitesseCoeff *= accessoire->getViteCoeff();
		vitesseCoeff /= accessoire->getLentCoeff();
	}
	return vitesseCoeff;
}


double Accessoires::getResistanceCoeff() const
{
	double resistanceCoeff = 1.0;
	for (shared_ptr<IAccessoire> accessoire : accessoiresList)
		resistanceCoeff *= accessoire->getResistanceCoeff();
	return resistanceCoeff;
}


double Accessoires::getCamouflageCoeff() const
{
	double camouflageCoeff = 0.0;
	for (shared_ptr<IAccessoire> accessoire : accessoiresList)
		if (accessoire->getCamouflageCoeff() > 0) {
			camouflageCoeff = accessoire->getCamouflageCoeff();
			break;
		}
	return camouflageCoeff;
}


string Accessoires::getAccessoiresInfo() const
{
	string info = "";
	for (shared_ptr<IAccessoire> accessoire : accessoiresList)
		info += accessoire->getInfo();
	return info;
}
