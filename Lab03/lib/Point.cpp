//
//  Point.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#include "Point.hpp"

Point::Point() {
    x = y = 0;
}

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

void Point::setX(int _x) {
    x = _x;
}

void Point::setY(int _y) {
    y = _y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::input(istream& inp) {
    inp >> x >> y;
}

void Point::output(ostream& out) {
    cout << x << " " << y << endl;
}

bool Point::operator!=(Point &a) {
    return x != a.getX() || y != a.getY();
}

istream& operator >> (istream& inp, Point &p) {
    p.input(inp);
    return inp;
}

ostream& operator << (ostream& out, Point &p) {
    p.output(out);
    return out;
}
