#include "Loss.hpp"
#include "Data_types.hpp"

template <typename T>
Abstract_matrix<T> *MSE<T>::loss(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value)
{
}

template <typename T>
Abstract_matrix<T> *MSE<T>::loss_derivative(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value)
{
}

template <typename T>
Abstract_matrix<T> *MAE<T>::loss(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value)
{
}

template <typename T>
Abstract_matrix<T> *MAE<T>::loss_derivative(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value)
{
}