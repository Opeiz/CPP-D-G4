#include "Bestiole.h"
#include "Milieu.h"
#include "comportements/ComportementKamikaze.h"
#include "comportements/ComportementPeureuse.h"
#include "comportements/ComportementGregaire.h"
#include "comportements/ComportementPrevoyante.h"
#include <cstdlib>
#include <cmath>

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
const double      Bestiole::COLLISION_DEATH_RATE = 0.1; // Prob of dying in collision

int               Bestiole::next = 0;

Bestiole::Bestiole( void ){
   age = 0;
   maxAge = rand() % 500 + 150; // range btw 50-400
   
   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];

   couleur[ 0 ] = 0;
   couleur[ 1 ] = 0;
   couleur[ 2 ] = 0;

   // Probability of being MultiPerso
   int probMulti = std::rand() % 100; // Number between 0 and 99
   int threshMulti = 85;
   
   if (probMulti > threshMulti){
      isMultiplePerso = true;
      printf("Bestiole %d is a MultiPerso\n", identite);
   } else {
      isMultiplePerso = false;
   }

   chooseComportement();

}

Bestiole::Bestiole( const Bestiole & b ){
   
   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;
   age = b.age;
   maxAge = b.maxAge;
   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   isMultiplePerso = b.isMultiplePerso;
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}

Bestiole::~Bestiole( void ){

   delete[] couleur;
   delete comportement; // Delete comportement

   cout << "dest Bestiole" << endl;

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

bool operator==( const Bestiole & b1, const Bestiole & b2 ){

   return ( b1.identite == b2.identite );

}

bool operator!=( const Bestiole & b1, const Bestiole & b2 ){

   return ( b1.identite != b2.identite );

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

   if (((rand() % 1000) / 1000.0) <= COLLISION_DEATH_RATE){
      // Death
      return True;
   } else {
      // Survival
      double theta = this->orientation;
      this->orientation = (theta >= M_PI) ? (theta - M_PI) : (theta + M_PI);
      return False;
   }
}

void Bestiole::chooseComportement(){
   
   int choosePerso = std::rand() % 4;

   switch (choosePerso) {
      case 0:
         this->comportement  = new ComportementKamikaze();
         this->couleur[0] = 255;
         this->couleur[1] = 0;
         this->couleur[2] = 0;

         break;
      case 1:
         this->comportement  = new ComportementGregaire();
         this->couleur[0] = 0;
         this->couleur[1] = 0;
         this->couleur[2] = 255;

         break;
      case 2:
         this->comportement  = new ComportementPeureuse();
         this->couleur[0] = 0;
         this->couleur[1] = 255;
         this->couleur[2] = 0;
         
         break;
      case 3:
         this->comportement  = new ComportementPrevoyante();
         this->couleur[0] = 255;
         this->couleur[1] = 193;
         this->couleur[2] = 203;
         
         break;
   }
}

void Bestiole::changeComportement(){
   delete this->comportement;
   this->chooseComportement();
}

double Bestiole::calculateAngle(const Bestiole &b){
   return std::atan2(b.y - this->y, b.x - this->x);
}