#include "ComportementGregaire.h"


double ComportementGregaire::changeOrientation(Bestiole& b, list<Bestiole*>& listeBestiolesDetected)
{
    double orientationSum = 0.0;
    for (Bestiole* b2 : listeBestiolesDetected)
        orientationSum += b2->getOrientation();

    return orientationSum / listeBestiolesDetected.size();
}
