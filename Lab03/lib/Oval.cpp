//
//  Line.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#include <stdio.h>
#include "Canvas.hpp"

void Canvas::generateCircle(Point a, Point b) {
    int r = min(abs(a.getX() - b.getX()), abs(a.getY() - b.getY())) / 2;
    Point center;
    if (a.getX() <= b.getX())
        if (a.getY() < b.getY())
            center = Point(a.getX() + r, a.getY() + r);
        else
            center = Point(a.getX() + r, a.getY() - r);
    else if (a.getY() < b.getY())
        center = Point(a.getX() - r, a.getY() + r);
    else
        center = Point(a.getX() - r, a.getY() - r);
    
    int x = r, y = 0;
    int p = 1 - r;
    
    do {
        for (int i=-1;i<=1;i+=2)
        for (int j=-1;j<=1;j+=2) {
            putPixel(center.getX() + x * i, center.getY() + y * j);
            putPixel(center.getX() + y * i, center.getY() + x * j);
        }
        
        ++y;
        if (p <= 0)
            p += 2 * y + 1;
        else {
            --x;
            p += 2 * y - 2 * x + 1;
        }
    } while (x >= y);
}

void Canvas::generateElippse(Point a, Point b) {
    int r1 = abs(a.getX() - b.getX()) / 2;
    int r2 = abs(a.getY() - b.getY()) / 2;
    
    Point center;
    if (a.getX() < b.getX())
        if (a.getY() < b.getY())
            center = Point(a.getX() + r1, a.getY() + r2);
        else
            center = Point(a.getX() + r1, a.getY() - r2);
    else if (a.getY() < b.getY())
        center = Point(a.getX() - r1, a.getY() + r2);
    else
        center = Point(a.getX() - r1, a.getY() - r2);
    
    int x = 0, y = r2;
    int d1 = r2 * r2 - r1 * r1 * r2 + 0.25 * r1 * r1;
    int dx = 2 * r2 * r2 * x;
    int dy = 2 * r1 * r1 * y;
    
    while (dx < dy) {
        for (int i=-1;i<=1;i+=2)
        for (int j=-1;j<=1;j+=2){
            putPixel(center.getX() + x * i, center.getY() + y * j);
        }
        
        ++x;
        dx += 2 * r2 * r2;
        
        if (d1 < 0)
            d1 += dx + r2 * r2;
        else {
            --y;
            dy -= 2 * r1 * r1;
            d1 += dx - dy + r2 * r2;
        }
    }
    
    int d2 = (r2 * r2 * (x + 0.5) * (x + 0.5)) + (r1 * r1 * (y - 1) * (y - 1)) - r1 * r1 * r2 * r2;
    
    while (y >= 0) {
        for (int i=-1;i<=1;i+=2)
        for (int j=-1;j<=1;j+=2){
            putPixel(center.getX() + x * i, center.getY() + y * j);
        }
        
        --y;
        dy -= 2 * r1 * r1;

        if (d2 > 0)
            d2 += r1 * r1 - dy;
        else {
            ++x;
            dx += 2 * r2 * r2;
            d2 += dx - dy + r1 * r1;
        }
    }
}
