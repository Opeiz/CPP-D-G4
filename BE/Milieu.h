#ifndef _MILIEU_H_
#define _MILIEU_H_

#include <iostream>
#include <list>

#include "UImg.h"
#include "Bestiole.h"

using namespace std;

class Milieu : public UImg{

   private :
      static const T          white[];

      int                     width, height;
      std::list<Bestiole>   listeBestioles;

   public :
      Milieu( int _width, int _height );
      ~Milieu( void );

      int getWidth( void ) const { return width; };
      int getHeight( void ) const { return height; };

      void step( void );

      void addMember( const Bestiole & b );

      int nbVoisins( const Bestiole & b );

};


#endif
