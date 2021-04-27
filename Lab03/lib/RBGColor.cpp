//
//  RBGColor.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#include "RBGColor.hpp"

RGBColor::RGBColor() {
    r = g = b = 255;
}

RGBColor::RGBColor(unsigned char a) {
    r = g = b = a;
}

RGBColor::RGBColor(unsigned char R, unsigned char G, unsigned char B) {
    r = R; g = G; b = B;
}


bool RGBColor::operator !=(const RGBColor& src) const {
    return r != src.r || g != src.g || b != src.b;
}

bool RGBColor::operator ==(const RGBColor& src) const {
    return r == src.r && g == src.g && b == src.b;
}

RGBColor RGBColor::operator =(unsigned char src) {
    RGBColor res(src, src, src);
    return res;
}
