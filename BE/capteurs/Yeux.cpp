#include "capteurs/Yeux.h"

Yeux::Yeux(){
    alpha_y = ALPHA_Y_MIN + (ALPHA_Y_MAX-ALPHA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
    delta_y = DELTA_Y_MIN + (DELTA_Y_MAX-DELTA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
    gamma_y = GAMMA_Y_MIN + (GAMMA_Y_MAX-GAMMA_Y_MIN)*((float) rand()) / (float) RAND_MAX;

}

Yeux::Yeux(float alpha, float delta, float gamma){
    alpha_y = (alpha > ALPHA_Y_MIN) ? alpha : ALPHA_Y_MIN;
    alpha_y = (alpha_y < ALPHA_Y_MAX) ? alpha_y : ALPHA_Y_MAX;
    
    delta_y = (delta > DELTA_Y_MIN) ? delta : DELTA_Y_MIN;
    delta_y = (delta_y < DELTA_Y_MAX) ? delta_y : DELTA_Y_MAX;

    gamma_y = (gamma > GAMMA_Y_MIN) ? gamma : GAMMA_Y_MIN;
    gamma_y = (gamma_y < GAMMA_Y_MAX) ? gamma_y : GAMMA_Y_MAX;

}