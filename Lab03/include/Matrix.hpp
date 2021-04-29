//
//  Matrix.hpp
//  Lab03
//
//  Created by Nguyen-Khoi Hoang on 28/04/2021.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <vector>
#include "Point.hpp"
using namespace std;

class Matrix {
private:
    int n, m;
    vector<vector<double> > arr;
public:
    Matrix() = default;
    Matrix(int n, int m);
    Matrix(const Point& src);
    Matrix(vector<double> src, int n, int m);
    
    void clear();
    double get(int i, int j) const;
    double& set(int i, int j);
    pair<int, int> getSize() const;

    Matrix operator *(const Matrix& src);
    Matrix operator +(const Matrix& src);
    Matrix operator -(const Matrix& src);
};

#endif /* Matrix_hpp */



