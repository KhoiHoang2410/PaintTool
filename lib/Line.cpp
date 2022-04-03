//
//  Line.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#include "../include/Canvas.hpp"
#define fi first
#define se second

void Canvas::generateLine(Point a, Point b) {
    double dx = abs(b.getX() - a.getX());
    double dy = abs(b.getY() - a.getY());

    if (dx >= dy) {
        if (a.getX() > b.getX()) swap(a, b);
        
        dy = b.getY() - a.getY();
        double p = 2 * abs(dy) - dx;
        double c1 = 2 * abs(dy);
        double c2 = 2 * (abs(dy) - dx);
        double x = a.getX(), y = a.getY();
        
        do {
            putPixel(x, y);
            
            if (p < 0)
                p += c1;
            else {
                p += c2;
                y += (dy >= 0) ? 1 : -1;
            }
            x += 1;
        } while (x <= b.getX());
    }
    else {
        if (a.getY() > b.getY()) swap(a, b);
        
        dx = b.getX() - a.getX();
        double p = 2 * abs(dx) - dy;
        double c1 = 2 * abs(dx);
        double c2 = 2 * (abs(dx) - dy);
        double x = a.getX(), y = a.getY();
                
        do {
            putPixel(x, y);
            
            if (p < 0)
                p += c1;
            else {
                p += c2;
                x += (dx >= 0) ? 1 : -1;
            }
            y += 1;
        } while (y <= b.getY());
    }
}
