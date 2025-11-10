#include "../entity/Dense.hpp"

template <typename T>
Dense<T>::Dense(int length, String activation = "sigmoid", String initializer = "random")
{
    this->layer_shape = length;
    // useing IoC container get proper registered activation object with it's name
    // this->activation = activation_selector->get(activation)
    // this->initializer = initializer_selector->get(initializer)
}

template <typename T>
void Dense<T>::init_param(int layer_number, int prev_layer_shape)
{
    this->layer_number = layer_number;
    this->prev_layer_shape = prev_layer_shape;
    // create weight matrix with matrix library
    //  this->weight_matrix = new Matrix(this->layer_shape,this->prev_layer_shape)
    //  this->bias = new Matrix(0,this->layer_shape)
}

template <typename T>
Abstract_matrix<T> *Dense<T>::calculate(Abstract_matrix<T> *input)
{
    this->layer_input = input;
    this->activate_value = this->layer_input->dot(this->weight_matrix);
    this->layer_output = this->activation->run(this->activate_value);
    return this->layer_output;
}

template <typename T>
void Dense<T>::apply_delta(Abstract_matrix<T> *delta)
{
    this->delta = this->activation->run_derivative(delta);
}

template <typename T>
Abstract_matrix<T> *Dense<T>::calculate_delta()
{
    return this->delta->dot(this->weight_matrix->transpose());
}

template <typename T>
void Dense<T>::update_param()
{
    Abstract_matrix<T> *weight_gradients = this->layer_input->transpose()->dot(this->delta);
    Abstract_matrix<T> *bias_gradients = this->delta->sum();

    this->weight_matrix = this->optimizer->run(this->weight_matrix, weight_gradients);
    this->bias = this->optimizer->run(this->bias, bias_gradients);
}