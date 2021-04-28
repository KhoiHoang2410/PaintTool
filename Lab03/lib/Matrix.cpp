//
//  Matrix.cpp
//  Lab03
//
//  Created by Nguyen-Khoi Hoang on 28/04/2021.
//

#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    arr.resize(n, vector<int>(m));
}

void Matrix::clear() {
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            arr[i][j] = 0;
}

int& Matrix::get(int i, int j) {
    return arr[i][j];
}

Matrix Matrix::operator *(const Matrix& src) {
    if (m != src.n) {
        cout << "Error multiply matrix.\n";
        exit(1);
    }
    
    Matrix res(n, src.m);
    for (int i=0; i<n; ++i)
        for (int j=0; j<src.m; ++j)
            for (int k=0; k< m; ++k)
                res.arr[i][j] += arr[i][k] * src.arr[k][j];
    
    return res;
}

Matrix Matrix::operator +(const Matrix& src) {
    if (m != src.m || n != src.n) {
        cout << "Error plus matrix.\n";
        exit(1);
    }
    
    Matrix res(n, m);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            res.arr[i][j] = arr[i][j] + src.arr[i][j];
    
    return res;
}

Matrix Matrix::operator -(const Matrix& src) {
    if (m != src.m || n != src.n) {
        cout << "Error minus matrix.\n";
        exit(1);
    }
    
    Matrix res(n, m);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            res.arr[i][j] = arr[i][j] - src.arr[i][j];
    
    return res;
}
