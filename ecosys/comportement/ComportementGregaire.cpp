#include "ComportementGregaire.h"


double ComportementGregaire::changeOrientation(Bestiole& b, list<shared_ptr<Bestiole>>& listeBestiolesDetected)
{
    double orientationSum = 0.0;
    for (shared_ptr<Bestiole> b2 : listeBestiolesDetected)
        orientationSum += b2->getOrientation();

    return orientationSum / listeBestiolesDetected.size();
}
