#include "Bestiole.h"
#include "Milieu.h"
#include "Accessories/Carapace.h"
#include "Accessories/Nageoire.h"
#include "Accessories/Camouflage.h"


#include <cstdlib>
#include <cmath>
#include "Oreilles.h"
#include "Yeux.h"

#include "Comportement.h"
#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementPeureuse.h"


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
const double      Bestiole::COLLISION_DEATH_RATE = 0.1; // Prob of dying in collision must be variable because of its use in 
//double Bestiole::collision=0.1;
int               Bestiole::next = 0;

Bestiole::Bestiole( void ){
   // Nageoire nageoire = new Nageoire();

   // Camouflage camouflage;
   // Carapace carapace;
   collider=1.0;
   age = 0;
   maxAge = rand() % 500 + 150; // range btw 50-400
   //COLLISION_DEATH_RATE=0.1;
   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   
   // Add eyes and ears to all bestioles
   // THIS IS JUST FOR TESTING
   Capteur* pOreilles = new Oreilles;
   listeCapteurs.push_back(pOreilles);
   Capteur* pYeux = new Yeux;
   listeCapteurs.push_back(pYeux);
   camouflage = 0;

   comportement = nullptr;
   couleur = new T[ 3 ]; // To be filled by chooseComportement()

   // Probability of being MultiPerso
   isMultiplePerso = std::rand() % 100 < PROB_MULTI;

   chooseComportement();
   chooseAccessory();
}

Bestiole::Bestiole(const Bestiole & b){
   
   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;
   collider=b.collider;
   age = b.age;
   maxAge = b.maxAge;
   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   isMultiplePerso = b.isMultiplePerso;
   comportement = b.comportement->clone();
   camouflage = b.camouflage;

   for (std::list<Capteur*>::const_iterator capt_it = (b.listeCapteurs).begin(); capt_it != b.listeCapteurs.end(); ++capt_it){
      // Iterate over capteurs of b and instantiate same type of capteurs in this
      listeCapteurs.push_back((*capt_it)->clone());
   }

   memcpy( couleur, b.couleur, 3*sizeof(T) );

}

Bestiole::~Bestiole( void ){

   delete[] couleur;

   for (std::list<Capteur*>::const_iterator capt_it = (this->listeCapteurs).begin(); capt_it != this->listeCapteurs.end(); ++capt_it){
      // Iterate over capteurs of b and instantiate same type of capteurs in this
      delete *capt_it;
   }

   delete comportement;

   cout << "dest Bestiole " << this->identite << endl;

}

void Bestiole::initCoords( int xLim, int yLim ){

   x = rand() % xLim;
   y = rand() % yLim;

}

void Bestiole::bouge( int xLim, int yLim ){

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;

   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

void Bestiole::action( Milieu & monMilieu ){

   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}

void Bestiole::draw( UImg & support ){

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


// General utility functions

bool operator==( const Bestiole & b1, const Bestiole & b2 ){

   return ( b1.identite == b2.identite );

}

bool operator!=( const Bestiole & b1, const Bestiole & b2 ){

   return ( b1.identite != b2.identite );

}

void Bestiole::setOrientation(double alpha_or){
   orientation = alpha_or;
}

void Bestiole::setVitesse(double v){
   vitesse = v;
}

bool Bestiole::jeTeVois( const Bestiole & b ) const{

   double         dist;

   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

void Bestiole::incAge(){
   this->age += 1;
}

bool Bestiole::isTooOld(){
   return ((this->age) >= (this->maxAge));
}

double Bestiole::distanceToBst(const Bestiole &b){
   double dist = sqrt(pow(this->x - b.x, 2) + pow(this->y - b.y, 2));
   return dist;
}

bool Bestiole::diedInCollision(){
   /* Called when the bestiole collides with another. It should either kill it or
   make it go in the opposite direction. It should also consider if the bestiole
   has a carapace equiped or not. */

   // TODO: Consider carapace

   if (((rand() % 1000) / 1000.0) <= (COLLISION_DEATH_RATE*(this->collider))){
      // Death
      return True;
   } else {
      // Survival
      double theta = this->orientation;
      this->orientation = (theta >= M_PI) ? (theta - M_PI) : (theta + M_PI);
      return False;
   }
}
 void Bestiole::chooseAccessory(){
   
   int choosePerso = std::rand() % 3;
   Nageoire nageoire;
   nageoire.set_coef(2.0);
   Camouflage camouflage;
   camouflage.set_coef(0.5);
   Carapace carapace;
   carapace.set_coef(1.5);
   carapace.set_speed(0.9);
   switch (choosePerso) {
      case 0:
         this->accessory = &nageoire;
         this->vitesse=(this->vitesse)*(nageoire.get_speed());
         printf("Nageoire!");
         break;
      case 1:
         this->accessory  = &camouflage;
         this->camouflage=camouflage.get_coef();
         printf("Camouflage!");
         break;
      case 2:
         this->accessory  = &carapace;
         this->collider=carapace.get_coef();
         this->vitesse=(this->vitesse)*(carapace.get_speed());
         printf("Carapace!");
         break;
   }

 }



void Bestiole::chooseComportement(){
   
   if (this->comportement != nullptr){
      delete this->comportement;
   }

   int choosePerso = std::rand() % NUM_COMPS;

   switch (choosePerso) {
      case 0:
         // Gregaire
         this->comportement = new ComportementGregaire;
         this->couleur[0] = 255;
         this->couleur[1] = 0;
         this->couleur[2] = 0;

         break;
      case 1:
         this->comportement = new ComportementKamikaze;
         this->couleur[0] = 0;
         this->couleur[1] = 0;
         this->couleur[2] = 255;

         break;
      case 2:
         this->comportement = new ComportementPeureuse;
         this->couleur[0] = 0;
         this->couleur[1] = 255;
         this->couleur[2] = 0;
         
         break;
      case 3:
         this->couleur[0] = 255;
         this->couleur[1] = 193;
         this->couleur[2] = 203;
         
         break;
      default:
         this->couleur[0] = 0;
         this->couleur[1] = 0;
         this->couleur[2] = 0;
   }
}

double Bestiole::angleToBst(const Bestiole &b){
    return std::atan2(-(b.y - this->y), b.x - this->x); // y axis points downwards
}

double Bestiole::relAngleToBst(const Bestiole &b){
   double absAngle = this->angleToBst(b);
   double relAngle = absAngle > M_PI ? absAngle - 2 * M_PI : absAngle;
   relAngle = relAngle < -M_PI ? relAngle + 2 * M_PI : relAngle;

   return relAngle;
}