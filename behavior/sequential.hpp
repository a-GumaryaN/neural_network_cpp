#include "../entity/Data_types.hpp"
#include "../entity/Sequential.hpp"

template <typename T>
Sequential<T>::Sequential(Abstract_array<Abstract_layer<T>> *layers, Abstract_matrix<T> input_shape, String initializer = "xavier")
{
    this->layers = layers;
    Abstract_matrix<T> shape = input_shape;
    int layer_number = 1;

    for (auto &layer : *this->layers)
    {
        layer.init_param(layer_number, shape);
        shape = layer.layer_shape;
    }
}

template <typename T>
Abstract_matrix<T> *Sequential<T>::forward_propagation(Abstract_matrix<T> *input_value)
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
Abstract_matrix<T> *Sequential<T>::backward_propagation(Abstract_matrix<T> *expected_value)
{
    Abstract_matrix<T> *error = this->loss_function->loss_derivative(this->network_output, expected_value);

    for (auto layer = this->layers->rbegin(); layer != this->layers->rend(); ++layer)
    {
        layer->apply_delta(error);
        error = layer->calculate_delta();
    }

    for (auto &layer : *this->layers)
    {
        layer.update_param();
    }
}
