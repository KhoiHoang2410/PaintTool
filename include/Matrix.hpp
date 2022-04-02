//
//  Matrix.hpp
//  Lab03
//
//  Created by Nguyen-Khoi Hoang on 28/04/2021.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <vector>
using namespace std;

class Matrix {
protected:
    int n, m;
    vector<vector<double> > arr;
public:
    Matrix() = default;
    Matrix(int n, int m, bool isBase = 1);
    Matrix(vector<double> src, int n, int m);
    
    void clear();
    double get(int i, int j) const;
    double& set(int i, int j);
    pair<int, int> getSize() const;
    
    virtual bool operator ==(const Matrix& src);
    virtual bool operator !=(const Matrix& src);

    virtual Matrix operator *(const Matrix& src);
    virtual Matrix operator +(const Matrix& src);
    virtual Matrix operator -(const Matrix& src);
    
    virtual Matrix operator +=(const Matrix& src);
    virtual Matrix operator -=(const Matrix& src);
    virtual Matrix operator *=(const Matrix& src);

    virtual Matrix operator *(const double a);
    virtual Matrix operator /(const double a);
    virtual Matrix operator *=(const double a);
    virtual Matrix operator /=(const double a);
};

#endif /* Matrix_hpp */



