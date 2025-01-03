#include "Network.hpp"

template <typename T>
Network<T>::Network(std::vector<Layer<T>> *layers, Matrix<T> input_shape)
{
    this->layers = layers;
    Matrix<T> shape = input_shape;
    int layer_number = 1;

    for (auto &layer : *this->layers)
    {
        layer.init_param(layer_number, shape);
        shape = layer.layer_shape;
    }
}


template <typename T>
Matrix<T> *Network<T>::forward_propagation(Matrix<T> *input_value)
{
    Matrix *temp = input_value;
    for (auto &layer : *this->layers)
    {
        temp = layer.calculate(temp);
    }
    this->network_output = temp;
    return temp;
}


template <typename T>
Matrix<T> *Network<T>::backward_propagation(Matrix<T> *expected_value)
{
    Matrix<T> *error = this->loss_function->loss_derivative(this->network_output, expected_value);

    for (auto layer = this->layers->rbegin(); layer != this->layers->rend(); ++layer)
    {
       layer->apply_delta(error);
       error=layer->calculate_delta();
    }

    for (auto &layer : *this->layers)
    {
        layer.update_param();
    }
}

