//
//  Point.hpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifndef Point_hpp
#define Point_hpp

#include <iostream>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point();
    Point(double _x, double _y);
    void setX(double _x);
    void setY(double _y);
    
    double getX() const;
    double getY() const;
    
    void input(istream& inp);
    void output(ostream& out);
    
    bool operator != (const Point& a);
    
    Point operator +(const Point& a);
    Point operator -(const Point& a);
    Point operator /(const double a);
    Point operator *(const double a);
    
    Point& operator +=(const Point& a);
    Point& operator -=(const Point& a);
    Point& operator /=(const double a);
    Point& operator *=(const double a);
};

istream& operator >> (istream& inp, Point &p);
ostream& operator << (ostream& out, Point &p);

#endif /* Point_hpp */

