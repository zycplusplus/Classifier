#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct MatrixSize {
    int row_;
    int col_;

    MatrixSize(int row, int col) : row_(row), col_(col) {}

    void resize(int row, int col) {
        row_ = row;
        col_ = col;
    }

    bool operator==(const MatrixSize& lhs) const { return (row_ == lhs.row_ && col_ == lhs.col_); }

    bool operator!=(const MatrixSize& lhs) const { return !(*this == lhs); }
};

class MatrixSizeError : public std::runtime_error {
   public:
    MatrixSizeError(const std::string& msg) : std::runtime_error(msg + "size error") {}
};

template <typename T>
T dot(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        std::cerr << a.size() << ", " << b.size() << "\n";
        throw MatrixSizeError("dot ");
    }
    T ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret += a[i] * b[i];
    }
    return ret;
}

template <typename T>
class Matrix {
   private:
    MatrixSize size_;

   public:
    std::vector<std::vector<T>> data_;

    Matrix() : Matrix(0, 0) {}

    explicit Matrix(int row, int col) : Matrix(MatrixSize(row, col)) {}

    explicit Matrix(const MatrixSize& s) : size_(s) { resize(s); }

    void resize(const MatrixSize& s) { resize(s.row_, s.col_); }

    void resize(int row, int col) {
        data_.resize(row);
        for (auto& v : data_) {
            v.resize(col);
        }
        size_.resize(row, col);
    }

    MatrixSize size() const { return size_; }

    Matrix<T> operator*(const Matrix<T>& left) const {
        if (size_.col_ != left.size().row_) {
            throw MatrixSizeError("matrix multiple ");
        }
        Matrix<T> ret(size_.row_, left.size().col_);

        for (int i = 0; i < size_.row_; i++) {
            for (int j = 0; j < left.size().col_; j++) {
                for (int k = 0; k < left.size().row_; k++) {
                    ret.data_[i][j] += data_[i][k] * left.data_[k][j];
                }
            }
        }
        return ret;
    }

    Matrix<T> operator+(const Matrix<T>& left) const {
        if (size_ != left.size()) {
            throw MatrixSizeError("matrix add ");
        }
        Matrix<T> ret(size_);
        for (int i = 0; i < size_.row_; i++) {
            for (int j = 0; j < size_.col_; j++) {
                ret.data_[i][j] = data_[i][j] + left.data_[i][j];
            }
        }
        return ret;
    }

    Matrix<T> operator-(const Matrix<T>& left) const {
        if (size_ != left.size()) {
            throw MatrixSizeError("matrix subtract ");
        }
        Matrix<T> ret(size_);
        for (int i = 0; i < size_.row_; i++) {
            for (int j = 0; j < size_.col_; j++) {
                ret.data_[i][j] = data_[i][j] - left.data_[i][j];
            }
        }
        return ret;
    }

    void operator-=(const Matrix<T>& left) {
        if (size_ != left.size()) {
            throw MatrixSizeError("matrix subtract ");
        }
        Matrix<T> ret(size_);
        for (int i = 0; i < size_.row_; i++) {
            for (int j = 0; j < size_.col_; j++) {
                data_[i][j] -= left.data_[i][j];
            }
        }
    }
};