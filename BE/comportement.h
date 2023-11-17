#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <iostream>

using namespace std;


class Comportement{
   private :
      void bouge( int xLim, int yLim );

   public :                                           // Forme canonique :
      Comportement( void );                  
      ~Comportement( void );                              // Destructeur
                                                      // Operateur d'affectation binaire par defaut


};


#endif