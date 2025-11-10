#pragma once
#include "../utils/Data_types.hpp"

template <typename T>
class Abstract_activation
{
public:
    Abstract_matrix<T> *run(Abstract_matrix<T> *input);
    Abstract_matrix<T> *run_derivative(Abstract_matrix<T> *input);
};

template <typename T>
class Softmax : public Abstract_activation<T>
{
    Abstract_matrix<T> *run(Abstract_matrix<T> *input) override;
    Abstract_matrix<T> *run_derivative(Abstract_matrix<T> *input) override;
};

template <typename T>
class Sigmoid : public Abstract_activation<T>
{
    Abstract_matrix<T> *run(Abstract_matrix<T> *input) override;
    Abstract_matrix<T> *run_derivative(Abstract_matrix<T> *input) override;
};

template <typename T>
class Relu : public Abstract_activation<T>
{
    Abstract_matrix<T> *run(Abstract_matrix<T> *input) override;
    Abstract_matrix<T> *run_derivative(Abstract_matrix<T> *input) override;
};

template <typename T>
class Leaky_relu : public Abstract_activation<T>
{
    Abstract_matrix<T> *run(Abstract_matrix<T> *input) override;
    Abstract_matrix<T> *run_derivative(Abstract_matrix<T> *input) override;
};

template <typename T>
class Tanh : public Abstract_activation<T>
{
    Abstract_matrix<T> *run(Abstract_matrix<T> *input) override;
    Abstract_matrix<T> *run_derivative(Abstract_matrix<T> *input) override;
};