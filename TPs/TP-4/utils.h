#ifndef UTILS
#define UTILS

#include <random>
#include "pixel.h"


//Template function to générate random number between range_from and range_to
template<typename T>
T alea(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

/* Image construction function from a texture defined by an array of integers
   The integers are read in their binary form for example 8 = [0 0 0 0 1 0 0 0]

   Thus the texture of the tree [8,28,62,8] represents in its binary version the matrix 4x8
   |0 0 0 0 1 0 0 0| = 8
   |0 0 0 1 1 1 0 0| = 28
   |0 0 1 1 1 1 1 0| = 62
   |0 0 0 0 1 0 0 0| = 8
    
    /!\ Works only if the texture size matches the width/height parameters and the image is an array of size width*height
*/
void buildImage(Pixel* image,const int width,const int height, const unsigned int* texture, const Pixel color);

#endif