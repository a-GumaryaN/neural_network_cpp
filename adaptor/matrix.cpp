#ifndef ABSTRACT_MATRIX_H
#define ABSTRACT_MATRIX_H

template <typename T>
class AbstractMatrix
{
public:
    virtual ~AbstractMatrix() {}

    // متدهای مجازی خالص
    virtual int get_rows() const = 0;
    virtual int get_cols() const = 0;
    virtual T operator()(int row, int col) const = 0;
    virtual T &operator()(int row, int col) = 0;
    virtual AbstractMatrix<T> *dot(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *multiply(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *operator+(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *operator-(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *operator/(double other) const = 0;
    virtual void print() const = 0;
};

#endif // ABSTRACT_MATRIX_H

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
// #include "AbstractMatrix.h"

template <typename T>
class Matrix : public AbstractMatrix<T>
{
private:
    int rows, cols;
    std::vector<std::vector<T>> data;

public:
    // سازنده‌های ماتریس
    Matrix(int rows, int cols, T initial_value = 0)
        : rows(rows), cols(cols), data(rows, std::vector<T>(cols, initial_value)) {}

    // گرفتن تعداد سطرها و ستون‌ها
    int get_rows() const override { return rows; }
    int get_cols() const override { return cols; }

    // دسترسی به عناصر ماتریس
    T operator()(int row, int col) const override
    {
        return data[row][col];
    }

    T &operator()(int row, int col) override
    {
        return data[row][col];
    }

    AbstractMatrix<T> *dot(const AbstractMatrix<T> &other) const override
    {
        if (cols != other.get_rows())
        {
            throw std::invalid_argument("Matrix dimensions are not compatible for dot product");
        }

        Matrix<T> *result = new Matrix<T>(rows, other.get_cols());

        for (int i = 0; i < rows; ++i)
        { // حلقه برای سطرهای ماتریس اول
            for (int j = 0; j < other.get_cols(); ++j)
            { // حلقه برای ستون‌های ماتریس دوم
                T sum = 0;
                for (int k = 0; k < cols; ++k)
                { // حلقه برای ضرب و جمع سطر و ستون
                    sum += data[i][k] * other(k, j);
                }
                (*result)(i, j) = sum;
            }
        }
        return result;
    }

    // ضرب عنصر به عنصر (element-wise multiplication)
    AbstractMatrix<T> *multiply(const AbstractMatrix<T> &other) const override
    {
        if (rows != other.get_rows() || cols != other.get_cols())
        {
            throw std::invalid_argument("Matrix dimensions must be the same for element-wise multiplication");
        }

        Matrix<T> *result = new Matrix<T>(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                (*result)(i, j) = data[i][j] * other(i, j);
            }
        }
        return result;
    }

    AbstractMatrix<T> *operator/(double other) const override{
        Matrix<T> *result = new Matrix<T>(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                (*result)(i, j) = data[i][j] / other;
            }
        }
        return result;
    }

    AbstractMatrix<T> *operator+(const AbstractMatrix<T> &other) const override
    {
        if (rows != other.get_rows() || cols != other.get_cols())
        {
            throw std::invalid_argument("Matrix dimensions must be the same for addition");
        }

        Matrix<T> *result = new Matrix<T>(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                (*result)(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
    }

    AbstractMatrix<T> *operator-(const AbstractMatrix<T> &other) const override
    {
        if (rows != other.get_rows() || cols != other.get_cols())
        {
            throw std::invalid_argument("Matrix dimensions must be the same for subtraction");
        }

        Matrix<T> *result = new Matrix<T>(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                (*result)(i, j) = data[i][j] - other(i, j);
            }
        }
        return result;
    }

    void print() const override
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // MATRIX_H

int main()
{
    Matrix<double> mat1(2, 2, 3);
    Matrix<double> mat2(2, 2, 1);

    AbstractMatrix<double> *mat3 = mat1 / 2;
    // AbstractMatrix<int> *mat4 = mat1 - mat2;
    // AbstractMatrix<int> *mat5 = mat1.dot(mat2);
    // AbstractMatrix<int> *mat6 = mat1.multiply(mat2);

    // Matrix<int> mat7=Matrix<int>(3,3,1);

    // std::cout << "mat1:" << std::endl;
    // mat1.print();

    // std::cout << "mat2:" << std::endl;
    // mat2.print();

    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    mat3->print();

    // std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    // mat4->print();

    // std::cout << "Matrix 1 dot Matrix 2:" << std::endl;
    // mat5->print();

    // std::cout << "Matrix 1 multiply Matrix 2:" << std::endl;
    // mat6->print();

    delete mat3;
    // delete mat4;

    return 0;
}