//
//  Point.hpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifndef Point_hpp
#define Point_hpp

#include "Matrix.hpp"
#include <iostream>
using namespace std;

class Point : public Matrix {
public:
    Point();
    Point(const Matrix& src);
    Point(double x, double y, bool isBase = 0);
    
    void setX(double x);
    void setY(double y);
    
    double getX() const;
    double getY() const;
    
    void input(istream& inp);
    void output(ostream& out);
};

istream& operator >> (istream& inp, Point &p);
ostream& operator << (ostream& out, Point &p);

#endif /* Point_hpp */

