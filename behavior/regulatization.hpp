#include "Regularization.hpp"

template <typename T>
T L1_regularization<T>::run(Abstract_matrix<T> *loss, Network<T> *network)
{
    // collecting weights
}

template <typename T>
T L2_regularization<T>::run(Abstract_matrix<T> *loss, Network<T> *network)
{
    double regularization_term = 0.0;
    for (const Abstract_layer<T> &layer : network->layers)
    {
        regularization_term += layer.get_weights()->sum_of_squared();
    }

    return loss + (this->lambda * regularization_term);
}
