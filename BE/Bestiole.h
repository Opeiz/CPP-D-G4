#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"
#include "comportements/Comportement.h"

class Milieu;

class Bestiole{

   private :
      static const double     AFF_SIZE;
      static const double     MAX_VITESSE;
      static const double     LIMITE_VUE;
      static const double     COLLISION_DEATH_RATE;

      static int              next; 

   private :
      int               identite;
      int               x, y;
      double            cumulX, cumulY;
      double            orientation;
      double            vitesse;

      T               * couleur;
      int               maxAge;
      int               age;

   public:
      bool              isMultiplePerso;
      Comportement    * comportement;

   private :
      void bouge( int xLim, int yLim );

   public :                                           // Forme canonique :
      Bestiole( void );                               // Constructeur par defaut
      Bestiole( const Bestiole & b );                 // Constructeur de copies
      ~Bestiole( void );                              // Destructeur
                                                      // Operateur d'affectation binaire par defaut
      void action( Milieu & monMilieu );
      void draw( UImg & support );

      bool jeTeVois( const Bestiole & b ) const;

      void initCoords( int xLim, int yLim );

      void incAge();
      bool isTooOld();

      friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
      friend bool operator!=( const Bestiole & b1, const Bestiole & b2 );

      // Collision-related functions
      double distanceToBst(const Bestiole &b);
      bool diedInCollision();
      void chooseComportement();
      void changeComportement();
};


#endif
