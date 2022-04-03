//
//  Point.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#include "../include/Point.hpp"

Point::Point() {
    n = 1; m = 2;
    arr.resize(1, vector<double>(2, 0));
}

Point::Point(double x, double y, bool isBase) {
    if (!isBase) {
        n = 1; m = 2;
        arr.resize(1, vector<double>(2, 0));
        arr[0][0] = x;
        arr[0][1] = y;
    }
}

Point::Point(const Matrix& src) {
    n = src.getSize().first;
    m = src.getSize().second;

    if (n != 1 || m != 2) {
        cout << "Error cast from Matrix to Point.\n";
        exit(1);
    }
    
    arr.resize(1, vector<double>(2, 0));
    arr[0][0] = src.get(0, 0);
    arr[0][1] = src.get(0, 1);
}

void Point::setX(double x) {
    arr[0][0] = x;
}

void Point::setY(double y) {
    arr[0][1] = y;
}

double Point::getX() const {
    return arr[0][0];
}

double Point::getY() const {
    return arr[0][1];
}

void Point::input(istream& inp) {
    inp >> arr[0][0] >> arr[0][1];
}

void Point::output(ostream& out) {
    cout << arr[0][0] << " " << arr[0][1] << endl;
}

istream& operator >> (istream& inp, Point &p) {
    p.input(inp);
    return inp;
}

ostream& operator << (ostream& out, Point &p) {
    p.output(out);
    return out;
}
