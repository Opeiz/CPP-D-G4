#pragma once

class Config
{
public:
	/* Bestiole */
	static const int MAX_AGE, MIN_AGE;
	static const double COLLISION_RANGE;
	static const double COLLISION_DEATH_RATE;
	static const double CLONAGE_RATE;

	/* Yeux */
	static const double ALPHA_MIN, ALPHA_MAX;
	static const double DELTA_Y_MIN, DELTA_Y_MAX;
	static const double GAMMA_Y_MIN, GAMMA_Y_MAX;

	/* Oreilles */
	static const double DELTA_O_MIN, DELTA_O_MAX;
	static const double GAMMA_O_MIN, GAMMA_O_MAX;

	/* Nageoire */
	static const double NU_MIN, NU_MAX;

	/* Carapace */
	static const double ETA_MIN, ETA_MAX;
	static const double OMEGA_MIN, OMEGA_MAX;

	/* Camouflage */
	static const double PSI_MIN, PSI_MAX;

	/* ComportementPeureuse */
	static const int N_AUTOUR, PEUREUSE_DURATION;
	static const double FUITE_COEFF;

	/* Comportement Multiple */
	static const double COMPORTEMTNT_CHANGE_RATE;
};



