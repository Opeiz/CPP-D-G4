#include "Statistics.h"

#include <iostream>
#include <fstream>
#include <string>


map<string,int> Statistics::data;


void Statistics::doStatistics(Milieu& monMilieu)
{
    data.clear();

    data.insert(pair<string, int>(" step", monMilieu.getNStep()));
    data.insert(pair<string, int>("Bestioles", monMilieu.getListeBestioles().size()));

    int nOreilles = 0, nYeux = 0, nNoCapteur = 0;
    int nNageoire = 0, nCarapace = 0, nCamouflage = 0;
    int nGregaire = 0, nPeureuse = 0, nKamikaze = 0, nPrevoyante = 0, nMultiple = 0;

    for (shared_ptr<Bestiole>& b : monMilieu.getListeBestioles()) {
        // capteur
        for (int capteurIdx : b->getCapteurInfo()) {
            switch (capteurIdx) {
            case 0:
                nNoCapteur++;
                break;
            case 1:
                nOreilles++;
                break;
            case 2:
                nYeux++;
            }
        }

        // accessoires
        for (char accessoireIdx : b->getAccessoiresInfo()) {
            switch (accessoireIdx) {
            case 'N':
                nNageoire++;
                break;
            case 'P':
                nCarapace++;
                break;
            case 'F':
                nCamouflage++;
            }
        }

        // comportement
        switch (b->getComportementInfo()) {
        case 1:
            nGregaire++;
            break;

        case 2:
            nPeureuse++;
            break;

        case 3:
            nKamikaze++;
            break;
        case 4:
            nPrevoyante++;
            break;
        case 5:
            nMultiple++;
        }
    }

    data.insert(pair<string, int>("Nageoire", nNageoire));
    data.insert(pair<string, int>("Carapace", nCarapace));
    data.insert(pair<string, int>("Camouflage", nCamouflage));

    data.insert(pair<string, int>("Oreilles", nOreilles));
    data.insert(pair<string, int>("Yeux", nYeux));

    data.insert(pair<string, int>("Gregaire", nGregaire));
    data.insert(pair<string, int>("Peureuse", nPeureuse));
    data.insert(pair<string, int>("Kamikaze", nKamikaze));
    data.insert(pair<string, int>("Prevoyante", nPrevoyante));
    data.insert(pair<string, int>("Multiple", nMultiple));

    writeStatistics();
}


void Statistics::writeStatistics()
{
    ofstream csvFile("statistics.csv", ios::app);

    if (csvFile.is_open()) {
        // write headers
        if (data[" step"] == 0) {
            for (const auto& pair : data) {
                csvFile << pair.first << ",";
            }
            csvFile.seekp(-1, ios_base::end);
            csvFile << endl;
        }

        // write values
        for (const auto& pair : data) {
            csvFile << pair.second << ",";
        }
        csvFile.seekp(-1, ios_base::end);
        csvFile << endl;

        csvFile.close();
    }
}
