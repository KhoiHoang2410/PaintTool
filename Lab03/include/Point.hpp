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
    Point(int _x, int _y);
    
    void setX(int _x);
    void setY(int _y);
    
    int getX() const;
    int getY() const;
    
    void input(istream& inp);
    void output(ostream& out);
    
    bool operator != (Point& a);
};

istream& operator >> (istream& inp, Point &p);
ostream& operator << (ostream& out, Point &p);

#endif /* Point_hpp */
