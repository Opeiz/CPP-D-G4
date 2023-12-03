#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"
#include "Capteur.h"
#include "Comportement.h"

#include <list>
#include <vector>

#define PROB_MULTI 15 // Probability of being multiple personality

class Milieu;

class Bestiole{

   private :
      // Constant values
      static const double     AFF_SIZE;
      static const double     MAX_VITESSE;
      static const double     LIMITE_VUE;
      static const double     COLLISION_DEATH_RATE;

      static int              next;

      int               identite;

      // Variable attributes
      int               x, y;
      double            cumulX, cumulY;
      double            orientation;
      double            vitesse;

      T               * couleur;
      int               maxAge;
      int               age;

   public:
      bool              isMultiplePerso;
      Comportement*     comportement;

      // Perception attributes
      double            camouflage;
      std::list<Capteur*>   listeCapteurs;
      std::list<Bestiole*>  perceivedBsts;

   private :
      void bouge( int xLim, int yLim );

   public :                            // Forme canonique :
      Bestiole();                      // Constructeur par defaut
      Bestiole( const Bestiole & b );  // Constructeur de copies
      ~Bestiole(void);                 // Destructeur
                                                      // Operateur d'affectation binaire par defaut
      void action( Milieu & monMilieu );
      void draw( UImg & support );

      bool jeTeVois( const Bestiole & b ) const;

      void initCoords( int xLim, int yLim );

      void incAge();
      bool isTooOld();

      // General utility function
      friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
      friend bool operator!=( const Bestiole & b1, const Bestiole & b2 );
      double getOrientation() const {return orientation;}
      void setOrientation(double alpha_or);
      double getVitesse() const {return vitesse;}
      void setVitesse(double v);
      double angleToBst(const Bestiole &b);

      // Collision-related functions
      double distanceToBst(const Bestiole &b);
      bool diedInCollision();

      // Personality functions
      void chooseComportement();

      // Detection-related functions
      double relAngleToBst(const Bestiole &b);
};


#endif
