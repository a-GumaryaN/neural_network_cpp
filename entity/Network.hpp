#include "Data_types.hpp"
#include "Layer.hpp"
#include "Loss.hpp"

template <typename T>
class Network
{
    Abstract_array<Layer> *layers;
    AbstractMatrix<T> *Network_error;
    Loss<T> *loss_function;
    AbstractMatrix<T> *network_output;

    Network(Abstract_array<Layer<T>> *layers, AbstractMatrix<T> input_shape);
    AbstractMatrix<T> *forward_propagation(AbstractMatrix<T> *input_value);
    AbstractMatrix<T> *backward_propagation(AbstractMatrix<T> *expected_value);
    void learn(AbstractMatrix<T> *input_value, AbstractMatrix<T> *expected_value);
};