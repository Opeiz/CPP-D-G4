#include "Aquarium.h"
#include "Comportement.h"
#include "Milieu.h"
#include "Bestiole.h"



int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 40; ++i ){
      ecosysteme.getMilieu().addMember(Bestiole());
   }
      
   ecosysteme.run();


   return 0;

}
