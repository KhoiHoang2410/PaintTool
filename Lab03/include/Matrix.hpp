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
private:
    int n, m;
    vector<vector<int> > arr;
public:
    Matrix(int n, int m);

    void clear();
    int& get(int i, int j);

    Matrix operator *(const Matrix& src);
    Matrix operator +(const Matrix& src);
    Matrix operator -(const Matrix& src);
};

#endif /* Matrix_hpp */
