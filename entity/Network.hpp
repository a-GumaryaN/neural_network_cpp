#pragma once
#include "./layers/Layer.hpp"
#include "./optimizers/Optimizer.hpp"

template <typename T>
class Abstract_network
{
    ~Abstract_network();
    Abstract_array<Abstract_layer<T>> layers;
    Abstract_optimizer<T> *optimizer;
};