#ifndef _MILIEU_H_
#define _MILIEU_H_

#include <iostream>
#include <list>
#include <vector>

#include "UImg.h"
#include "Bestiole.h"
#include "Comportement.h"

#define PROB_BIRTH 10   // Probability of a bestiole being born at each timestep
#define PROB_MULTI 5    // Prob of changing personality

using namespace std;

class Milieu : public UImg{

   private :
      static const T          white[];

      int                     width, height;
      std::list<Bestiole>     listeBestioles;
      std::vector<Comportement*> vecComportements;

   public :
      Milieu( int _width, int _height );
      ~Milieu( void );

      int getWidth( void ) const { return width; };
      int getHeight( void ) const { return height; };
      const std::vector<Comportement*> getVecComportements() const {return this->vecComportements;} 

      void step( void );

      void addMember( const Bestiole & b );

      int nbVoisins( const Bestiole & b );

};


#endif
