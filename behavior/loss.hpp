#include "Loss.hpp"

template <typename T>
Matrix<T> *MSE<T>::loss(Matrix<T> *actual_value, Matrix<T> *expected_value)
{
    this->number_of_data += 1;
    this->error = this->error + (actual_value - expected_value);
    return this->error / this->number_of_data;
}

template <typename T>
Matrix<T> *MSE<T>::loss_derivative(Matrix<T> *actual_value, Matrix<T> *expected_value)
{
}

template <typename T>
Matrix<T> *MAE<T>::loss(Matrix<T> *actual_value, Matrix<T> *expected_value)
{
}

template <typename T>
Matrix<T> *MAE<T>::loss_derivative(Matrix<T> *actual_value, Matrix<T> *expected_value)
{
}