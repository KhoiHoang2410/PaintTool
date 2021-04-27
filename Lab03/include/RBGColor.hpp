//
//  RBGColor.hpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifndef RBGColor_hpp
#define RBGColor_hpp

#include <stdio.h>

class RGBColor {
public:
    unsigned char r, g, b;
    
    RGBColor();
    
    RGBColor(unsigned char a);
    
    RGBColor(unsigned char R, unsigned char G, unsigned char B);
    
    bool operator !=(const RGBColor& src) const;
    bool operator ==(const RGBColor& src) const;
    RGBColor operator =(unsigned char src);
};

#endif /* RBGColor_hpp */
