#include "ComportementGregaire.h"


double ComportementGregaire::changeOrientation(Bestiole& b, set<shared_ptr<Bestiole>>& bestiolesDetected)
{
    double orientationSum = 0.0;
    for (const shared_ptr<Bestiole>& b2 : bestiolesDetected)
        orientationSum += b2->getOrientation();

    return orientationSum / bestiolesDetected.size();
}
