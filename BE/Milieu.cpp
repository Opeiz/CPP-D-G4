#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <list>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height){

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void ){

   cout << "dest Milieu" << endl;

}


void Milieu::step( void ){

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

   // printf("Number of bestioles after age check: %d", listeBestioles.size());

   // Iteration over bestioles who didn't die of old age to check collisions
   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ){
      // Step 3 and 4
      // TODO
      // Compute distance matrix between all bestioles
   }

   // Bestiole birth
   // TODO

   // Iteration over bestioles who have survived this timestep (steps 6 to 10)
   // TODO
   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ){
      


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
