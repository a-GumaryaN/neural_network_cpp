#include "../entity/Activation.hpp"

template <typename T>
Abstract_matrix<T> *Abstract_activation<T>::run_derivative(Abstract_matrix<T> *input)
{
    /*
    auto differentiation implementation
    if user use implemented activations functions or declare a custom function
    with it's derivative,
    then the run and run_derivative of this functions use to calculate
    if use just declare activation function with no derivative declaration,
    then this method no over ride and use automatic differentiation to calculate
    derivative of custom activation
    */
}

template <typename T>
Abstract_matrix<T> *Sigmoid<T>::run(Abstract_matrix<T> *input)
{
    return 1 / (input->exp() + 1);
}
template <typename T>
Abstract_matrix<T> *Sigmoid<T>::run_derivative(Abstract_matrix<T> *input)
{
    Abstract_matrix<T> *temp = this->run(input);
    return temp * (temp - 1);
}

template <typename T>
Abstract_matrix<T> *Relu<T>::run(Abstract_matrix<T> *input)
{
    return input->maximize(0);
}
template <typename T>
Abstract_matrix<T> *Relu<T>::run_derivative(Abstract_matrix<T> *input)
{
}

template <typename T>
Abstract_matrix<T> *Softmax<T>::run(Abstract_matrix<T> *input)
{
}
template <typename T>
Abstract_matrix<T> *Softmax<T>::run_derivative(Abstract_matrix<T> *input)
{
}

template <typename T>
Abstract_matrix<T> *Leaky_relu<T>::run(Abstract_matrix<T> *input)
{
}
template <typename T>
Abstract_matrix<T> *Leaky_relu<T>::run_derivative(Abstract_matrix<T> *input)
{
}

template <typename T>
Abstract_matrix<T> *Tanh<T>::run(Abstract_matrix<T> *input)
{
}
template <typename T>
Abstract_matrix<T> *Tanh<T>::run_derivative(Abstract_matrix<T> *input)
{
}