#include <capteur.h>
#include <algorithm>

Yeux::Yeux(){
    alpha_y = ALPHA_Y_MIN + (ALPHA_Y_MAX-ALPHA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
    delta_y = DELTA_Y_MIN + (DELTA_Y_MAX-DELTA_Y_MIN)*((float) rand()) / (float) RAND_MAX;
    gamma_y = GAMMA_Y_MIN + (GAMMA_Y_MAX-GAMMA_Y_MIN)*((float) rand()) / (float) RAND_MAX;

}

Yeux::Yeux(float alpha, float delta, float gamma){
    alpha_y = min(max(alpha, ALPHA_Y_MIN),ALPHA_Y_MAX); //assert?
    delta_y = min(max(delta, DELTA_Y_MIN),DELTA_Y_MAX);
    gamma_y = min(max(gamma, GAMMA_Y_MIN),GAMMA_Y_MAX);

}

Oreilles::Oreilles(){
    delta_o = DELTA_O_MIN + (DELTA_O_MAX-DELTA_O_MIN)*((float) rand()) / (float) RAND_MAX;
    gamma_o = GAMMA_O_MIN + (GAMMA_O_MAX-GAMMA_O_MIN)*((float) rand()) / (float) RAND_MAX;

}

Oreilles::Oreilles(float delta, float gamma){
    delta_o = min(max(delta, DELTA_O_MIN),DELTA_O_MAX); //assert?
    gamma_o = min(max(gamma, GAMMA_O_MIN),GAMMA_O_MAX);

}

