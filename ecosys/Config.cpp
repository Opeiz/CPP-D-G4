#define _USE_MATH_DEFINES

#include "Config.h"
#include <cmath>

/* Bestiole */
const int Config::MAX_AGE = 10000, Config::MIN_AGE = 500;
const double Config::COLLISION_RANGE = 8.;
const double Config::COLLISION_DEATH_RATE = 0.2;
const double Config::CLONAGE_RATE = 0.0005;
const double Config::EYES_PROBABILITY = 0.001;  // (0, 1]
const double Config::EARS_PROBABILITY = 1.0;  // (0, 1]
const double Config::NAGEOIRE_PROBABILITY = 0.001;  // (0, 1]
const double Config::CARAPACE_PROBABILITY = 0.001;  // (0, 1]
const double Config::CAMOUFLAGE_PROBABILITY = 0.001;  // (0, 1]

/* Yeux */
const double Config::ALPHA_MIN = 0.1 * M_PI, Config::ALPHA_MAX = 0.75 * M_PI;  // [0, 2*pi]
const double Config::DELTA_Y_MIN = 30, Config::DELTA_Y_MAX = 100;  // (0, )
const double Config::GAMMA_Y_MIN = 0.1, Config::GAMMA_Y_MAX = 1;  // (0, 1]

/* Oreilles */
const double Config::DELTA_O_MIN = 20, Config::DELTA_O_MAX = 50;  // (0, )
const double Config::GAMMA_O_MIN = 0.1, Config::GAMMA_O_MAX = 1;  // (0, 1]

/* Nageoire */
const double Config::NU_MIN = 1.0, Config::NU_MAX = 1.5;  // [1, )

/* Carapace */
const double Config::ETA_MIN = 1.0, Config::ETA_MAX = 20.0;  // [1, )
const double Config::OMEGA_MIN = 1.0, Config::OMEGA_MAX = 10.0;  // [1, )

/* Camouflage */
const double Config::PSI_MIN = 0.1, Config::PSI_MAX = 1.0;  // (0, 1]

/* ComportementPeureuse */
const int Config::N_AUTOUR = 1, Config::PEUREUSE_DURATION = 50;
const double Config::FUITE_COEFF = 8.0;

/* Comportement Multiple */
const double Config::COMPORTEMTNT_CHANGE_RATE = 0.002;





