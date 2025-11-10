#pragma once
#include "../layers/Layer.hpp"
#include "../loss's/Loss.hpp"
#include "Network.hpp"

template <typename T>
class Sequential : public Abstract_network<T>
{
    Abstract_array<Abstract_layer<T>> *layers;
    Abstract_matrix<T> *Network_error;
    Abstract_loss<T> *loss_function;
    Abstract_matrix<T> *network_output;

    Sequential(Abstract_array<Abstract_layer<T>> *layers, Abstract_matrix<T> input_shape, String initializer_name = "xavier");
    Abstract_matrix<T> *forward_propagation(Abstract_matrix<T> *input_value);
    Abstract_matrix<T> *backward_propagation(Abstract_matrix<T> *expected_value);
    void learn(Abstract_matrix<T> *input_value, Abstract_matrix<T> *expected_value, String optimizer_name = "adam");
};