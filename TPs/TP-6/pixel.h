#ifndef PIXEL
#define PIXEL

#include <iostream>


class Pixel {
public:
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    Pixel():red(0),green(0),blue(0){}
    Pixel(unsigned char r, unsigned char g, unsigned char b):red(r),green(g),blue(b){}
};

//Draw a pixel in the console using the ANSI escape code
inline std::ostream& operator<< (std::ostream& flot , const Pixel& p)
{
    flot << "[38;2;" << p.red << ";" << p.green << ";" << p.blue << "m▓" ;
    return flot ;
}

#endif