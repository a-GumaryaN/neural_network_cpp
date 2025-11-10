#include "../entity/Convolutional.hpp"

// template <typename T>
// Convolutional<T>::Convolutional(int filters, int kernel_size = 3, int stride = 1, Abstract_array<int> padding = {0, 0}, String mode = "valid", String activation = "relu")
// {
// }

// template <typename T>
// void Convolutional<T>::init_param(int layer_number, Abstract_matrix<T> prev_layer_shape)
// {
//     this->layer_number = layer_number;
// }

template <typename T>
Abstract_matrix<T> *Convolutional<T>::calculate(Abstract_matrix<T> *input)
{
    this->layer_input = input;
    this->layer_output = this->bias->copy();
    for (int i = 0; i < this->input_depth; i++)
    {
        for (int j = 0; j < this->layer_depth; j++)
        {
            this->layer_output(i, j) += this->layer_input(i)->convolve(this->kernels(j));
        }
    }
}

template <typename T>
void Convolutional<T>::apply_delta(Abstract_matrix<T> *delta)
{
    this->delta = delta;
}

template <typename T>
Abstract_matrix<T> *Convolutional<T>::calculate_delta()
{
}

template <typename T>
void Convolutional<T>::update_param()
{
    this->kernels = this->optimizer->run(this->kernels, this->kernels_gradients);
    this->bias = this->optimizer->run(this->bias, this->delta);
}