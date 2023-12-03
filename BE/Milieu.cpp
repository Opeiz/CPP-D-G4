#include <cstdlib>
#include <ctime>
#include <list>
#include <set>
#include <vector>
#include <cmath>

#include "Milieu.h"
#include "Comportement.h"
#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height){

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

   // Initialize vector of comportements
   Comportement* pCompGregaire = new ComportementGregaire;
   vecComportements.push_back(pCompGregaire);
   Comportement* pCompKamikaze = new ComportementKamikaze;
   vecComportements.push_back(pCompKamikaze);
   // TODO: The others
}


Milieu::~Milieu( void ){

   cout << "dest Milieu" << endl;

   // Free memory from comportements
   for (std::vector<Comportement*>::iterator comp_it = vecComportements.begin(); comp_it != vecComportements.end(); ++comp_it){
      delete *comp_it;
   }

}


void Milieu::step( void ){

   // For debugging
   // std::cout << "Bestioles alive at the start of the timestep: " << listeBestioles.size() << std::endl;
   
   // Draw all in the window
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   /*
   Each timestep implements the following loop:
   1 - Increase the age of all bestioles
   2 - Delete those who have reached their maximum age
   3 - Check for collisions between bestioles
   4 - Delete bestioles who died in collision and flip direction of those who didn't
   5 - Birth of new bestioles
   6 - Check detection between bestioles
   7 - Randomize the behaviour of multiple personality bestioles
   8 - Calculate next orientation and speed
   9 - Execute movement
   10 - Draw
   */

   // NOTE: listeBestioles gets automatically updated when bestioles are deleted, so by redeclaring the
   //       iterator we get the remaining one.

   // print("Number of bestioles at start of timestep: %ld", listeBestioles.size());

   // Iteration over bestioles who are alive at the beginning of the timestep
   for ( list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ){

      it->incAge();

      // Check if it is too old and release the memory calling the deconstructor      
      if (it->isTooOld()){
         it = listeBestioles.erase(it);
      }
   }


   // Iteration over bestioles who didn't die of old age to check collisions
   double collisionDist = 8;

   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ){
      // Step 3 and 4

      bool itCollided = False;
      for (std::list<Bestiole>::iterator it2 = it; it2 != listeBestioles.end(); ++it2){
         // Iterate over all bestioles to see if distance is too small
         if ((*it != *it2) && (it->distanceToBst(*it2) <= collisionDist)){
            // Check for death.
            itCollided = True;

            if (it2->diedInCollision()){
               it2 = listeBestioles.erase(it2);
            }
         }
      }

      if (itCollided && (it->diedInCollision())){ // Right side of && is not evaluated if itCollided == False
         it = listeBestioles.erase(it);
      }
   }

   // Bestiole Birth
   int const probBirth = 5;

   if ((std::rand() % 100) < probBirth){
      addMember(Bestiole(vecComportements));
   }

   // Iteration over bestioles who have survived this timestep (steps 6 to 10)
   // TODO 
   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ){

      // Step 6 - Detection between bestioles

      std::list<Bestiole*> perceivedBsts;

      // Check what each available capteur detects
      for (std::list<Capteur*>::const_iterator capt_it = (it->listeCapteurs).begin(); capt_it != it->listeCapteurs.end(); ++capt_it){
         std::list<Bestiole*> captPerceivedBsts = (*capt_it)->detecter(*it, listeBestioles);
         perceivedBsts.splice(perceivedBsts.end(), captPerceivedBsts, captPerceivedBsts.begin(), captPerceivedBsts.end());
      }

      // Remove possible duplicates
      perceivedBsts.sort();
      perceivedBsts.unique();
      it->perceivedBsts = perceivedBsts;

      // Step 7 - Changing the comportement of multiple personality bestioles

      if (it->isMultiplePerso){
         int probMulti = 5;
         if (std::rand() % 100 < probMulti){
            it->chooseComportement(vecComportements);
         }
      }

      // Step 8 - Calculate next orientation and speed

      double newOrientation = it->comportement->calculateOrientation(*it, it->perceivedBsts);
      it->setOrientation(newOrientation);
      double newVitesse = it->comportement->calculateVitesse(*it, it->perceivedBsts);
      it->setVitesse(newVitesse);

      // Steps 9 and 10
      it->action( *this );
      it->draw( *this );
   }
}


int Milieu::nbVoisins( const Bestiole & b ){

   int         nb = 0;

   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}

void Milieu::addMember(const Bestiole &b){
   std::cout << "Pushing back" << std::endl;
   listeBestioles.push_back(b); 
   listeBestioles.back().initCoords(width, height); 
}
