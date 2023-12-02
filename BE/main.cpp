#include "Aquarium.h"
#include "Comportement.h"
#include "Milieu.h"
#include "Bestiole.h"



int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   const std::vector<Comportement*>& vecComp = ecosysteme.getMilieu().getVecComportements();

   for ( int i = 1; i <= 15; ++i ){
      ecosysteme.getMilieu().addMember(Bestiole(vecComp));
   }
      
   ecosysteme.run();


   return 0;

}
