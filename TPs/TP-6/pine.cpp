#include "pine.h"
#include "utils.h"
#include <iostream>
#include <cstring>


Pine::Pine(){
	std::cout << "Planting a Pine - at address : " << this<<std::endl;
	width = 8;
	height = 4;
	image = new Pixel[width*height]; // Es un pixel porque con new es un puntero
	unsigned int texture[]={8,28,62,8};
	Pixel color = Pixel(0,alea(20,255),0);
	buildImage(image,width,height,texture, color);
}

Pine::~Pine(){
	std::cout << "Cutting down a pine - at address : " << this  <<std::endl;
	free(this->image);
}

Pine:: Pine(const Pine& s){
	std::cout << "Copy Constructor" << std::endl;
	width = s.width;
	height = s.height;	
	image = new Pixel[width*height];

}

void Pine::draw(){
	for (int i=0;i<width*height;i++){
        std::cout << image[i] ;
        if (i%width==0) {
			std::cout << std::endl;
		}
    }
    std::cout << "[0m"<< std::endl;
}

void Pine::info(){
	std::cout << "Pine address : " << this <<std::endl;
	std::cout << "Pine's image address : " << image << std::endl;
}