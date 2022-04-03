//
//  Quadrilateral.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 21/04/2021.
//

#include "../include/Canvas.hpp"

vector<Point> Canvas::generateRectangle(Point a, Point b) {
    Point c = Point(a.getX(), b.getY());
    Point d = Point(b.getX(), a.getY());
    
    generateLine(a, c);
    generateLine(c, b);
    generateLine(b, d);
    generateLine(a, d);
    
    return vector<Point>{a, c, b, d};
}

vector<Point> Canvas::generateSquare(Point a, Point b) {
    Point c = Point(a.getX(), b.getY());
    
    int r = min(abs(a.getX() - b.getX()), abs(a.getY() - b.getY()));
    if (a.getX() < b.getX())
        if (a.getY() < b.getY())
            c = Point(a.getX() + r, a.getY() + r);
        else
            c = Point(a.getX() + r, a.getY() - r);
    else if (a.getY() < b.getY())
        c = Point(a.getX() - r, a.getY() + r);
    else
        c = Point(a.getX() - r, a.getY() - r);
    
    Point d = Point(c.getX(), a.getY());
    b = Point(a.getX(), c.getY());
    
    generateLine(a, b);
    generateLine(c, b);
    generateLine(c, d);
    generateLine(a, d);
    
    return vector<Point>{a, b, c, d};
}
