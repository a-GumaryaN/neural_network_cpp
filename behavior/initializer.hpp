#include "Data_types.hpp"
#include "Initializer.hpp"
#include "Matematics.hpp"

template <typename T>
Abstract_matrix<T> Random<T>::*run(Abstract_array<T> input_shape)
{
    Abstract_matrix<T> *output = new Abstract_matrix<T>->random(input_shape);
    return output;
}

template <typename T>
Abstract_matrix<T> Xavier<T>::*run(Abstract_array<T> input_shape)
{
    double layer_length = this->param("layer_length");
    double prev_layer_length = this->param("prev_layer_length");
    double limit = sqrt(6 / (layer_length + prev_layer_length));
    Abstract_matrix<T> *output = new Abstract_matrix<T>();
    output->uniform(-1 * limit, limit, input_shape);
    return output;
}