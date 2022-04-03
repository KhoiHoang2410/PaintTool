//
//  RightTriangle.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 21/04/2021.
//

#include "../include/Canvas.hpp"
#include <math.h>

void Canvas::generateRightTriangle(Point a, Point b) {
    Point c;

    if ((b.getX() > a.getX()) ^ (b.getY() < a.getY()))
        c = Point(b.getX(), a.getY());
    else
        c = Point(a.getX(), b.getY());
    
    generateLine(a, b);
    generateLine(b, c);
    generateLine(c, a);
}

void Canvas::generateEquilateralTriangle(Point a, Point b) {
    int delta = abs(a.getX() - b.getX()) - abs(a.getY() - b.getY());
    
    Point u, v, z;
    double aa, ah, d;
    
    if (delta <= 0) { // dx = length side of triangle
        aa = abs(a.getX() - b.getX());
        ah = aa * sqrt(3) / 2.;
    }
    else { // height of triangle = dy
        ah = abs(a.getY() - b.getY());
        aa = 2. * ah / sqrt(3);
    }
    
    if (b.getY() < a.getY()) {
        if (a.getX() < b.getX()) d = 1;
        else d = -1;
    
        z = Point(a.getX() + aa / 2. * d, a.getY());
        u = Point(a.getX(), a.getY() - ah);
        v = Point(a.getX() + aa * d, a.getY() - ah);
    }
    else {
        if (a.getX() < b.getX()) d = 1;
        else d = -1;
        
        u = a;
        v = Point(a.getX() + aa * d, a.getY());
        z = Point(a.getX() + aa / 2 * d, a.getY() + ah);
    }
    
    generateLine(u, v);
    generateLine(z, v);
    generateLine(u, z);
}
