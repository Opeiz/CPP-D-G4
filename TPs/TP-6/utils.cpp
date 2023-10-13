#include "utils.h"

void buildImage(Pixel* image,const int width,const int height, const unsigned int* texture, const Pixel color) {
    //builds the image line by line
    for(int k=0;k<height;k++){
        //the integer of the texture corresponding to the line is read from right to left (least significant bit first)
        for (int j =width-1;j>=0;j--){
            //If the bit is 1, the default pixel (white) is changed to a color, otherwise it remains white
            if(texture[k]&1<<j){
                //Only the last line has a fixed color corresponding to the trunk of the tree, otherwise the leaves take the color passed in parameter
                if (k<height-1) {
                    image[(k+1)*width-1-j]=color;
                } else {
                    image[(k+1)*width-1-j]=Pixel(59,23,0);
                }
            }
        }
    }

}