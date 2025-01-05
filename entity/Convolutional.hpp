#include "Layer.hpp"

template <typename T>
class Convolutional : Layer
{
    AbstractMatrix<T> *kernels;
    void init_param(int layer_number, AbstractMatrix<T> prev_layer_shape);
    AbstractMatrix<T> *calculate(Matrix<T> *input);
    void apply_delta(AbstractMatrix<T> *delta);
    AbstractMatrix<T> *calculate_delta();
    void update_param();
};