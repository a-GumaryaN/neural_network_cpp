#include "Layer.hpp"

template <typename T>
class Convolutional : Layer
{
    Matrix<T> kernels;
    void init_param(int layer_number, Matrix<T> prev_layer_shape);
    Matrix<T> *calculate(Matrix<T> *input);
    void apply_delta(Matrix<T> *delta);
    Matrix<T> *calculate_delta();
    void update_param();
};