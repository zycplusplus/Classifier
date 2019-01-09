#pragma once

template <typename T>
class Matrix {
   public:
    int row_;
    int col_;
    T** data_;

   public:
    explicit Matrix(int row, int col) : row_(row), col_(col) {}

    Matrix<T> operator*(const Matrix<T>& left) const { return Matrix<T>(1, 1); }

    Matrix<T> operator+(const Matrix<T>& left) const { return Matrix<T>(1, 1); }

    Matrix<T> operator-(const Matrix<T>& left) const { return Matrix<T>(1, 1); }

    void operator-=(const Matrix<T>& left) {}
};