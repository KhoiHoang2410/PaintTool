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

Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}

void Point::setX(double _x) {
    x = _x;
}

void Point::setY(double _y) {
    y = _y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::input(istream& inp) {
    inp >> x >> y;
}

void Point::output(ostream& out) {
    cout << x << " " << y << endl;
}

bool Point::operator!=(const Point &a) {
    return x != a.getX() || y != a.getY();
}

Point Point::operator +(const Point& a) {
    return Point(x + a.getX(), y + a.getY());
}

Point Point::operator -(const Point& a) {
    return Point(x - a.getX(), y - a.getY());
}

Point Point::operator /(const double a) {
    if (a == 0) {
        cout << "Divide Point with 0\n";
        exit(0);
    }
    return Point(x / a, y / a);
}

Point Point::operator *(const double a) {
    return Point(x * a, y * a);
}

Point& Point::operator +=(const Point& a) {
    *this = *this + a;
    return *this;
}

Point& Point::operator -=(const Point& a) {
    *this = *this - a;
    return *this;
}

Point& Point::operator /=(const double a) {
    *this = *this / a;
    return *this;
}

Point& Point::operator *=(const double a) {
    *this = *this * a;
    return *this;
}

istream& operator >> (istream& inp, Point &p) {
    p.input(inp);
    return inp;
}

ostream& operator << (ostream& out, Point &p) {
    p.output(out);
    return out;
}


