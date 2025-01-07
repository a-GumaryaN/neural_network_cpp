#include "Dense.hpp"

template <typename T>
Abstract_matrix<T> *Dense<T>::calculate(Abstract_matrix<T> *input)
{
    this->layer_input = input;
    this->activate_value = dot(this->weight_matrix, this->layer_input);
    this->layer_output = this->activation->run(this->activate_value);
    return this->layer_output;
}

// self.delta = error * self.activation_derivative(self.layer_activation)
template <typename T>
void Dense<T>::apply_delta(Abstract_matrix<T> *delta)
{
    this->delta = this->activation->run_derivative(delta);
}

template <typename T>
Abstract_matrix<T> *Dense<T>::calculate_delta()
{
    return this->delta * this->weight_matrix.T
}

template <typename T>
void Dense<T>::update_param()
{
    Abstract_matrix<T> *weight_grad = this->layer_input.T * this->delta;
    this->weight_matrix = this->weight_optimizer->run(this->weight_matrix, weight_grad)

    Abstract_matrix<T> *bias_grad = this->delta->sum(1,true);
    this->bias_optimizer->run(this->bias,bias_grad);
}