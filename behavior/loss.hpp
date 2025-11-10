#include "../entity/Loss.hpp"
#include "../entity/Data_types.hpp"

template <typename T>
Abstract_matrix<T> *Abstract_loss<T>::loss_derivative(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value) {
    /*
    auto differentiation implementation
    if user use implemented loss functions or declare a custom function
    with it's derivative,
    then the run and run_derivative of this functions use to calculate
    if use just declare activation function with no derivative declaration,
    then this method no over ride and use automatic differentiation to calculate
    derivative of custom activation
    */
}

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