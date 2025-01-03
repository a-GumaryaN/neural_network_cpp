#include <vector>
#include "Layer.hpp"
#include "Matrix.hpp"
#include "loss.hpp"

template <typename T>
class Network
{
    std::vector<Layer> *layers;
    Matrix<T> *Network_error;
    Loss *loss_function;
    Matrix<T> *network_output;


    Network(std::vector<Layer<T>> *layers,Matrix<T> input_shape);
    Matrix<T> *forward_propagation(Matrix<T> *input_value);
    Matrix<T> *backward_propagation(Matrix<T> *expected_value);
    void learn(Matrix<T> *input_value,Matrix<T> *expected_value);
};