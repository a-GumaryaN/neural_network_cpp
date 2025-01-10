#pragma once
#include "Layer.hpp"
#include "Optimizer.hpp"

template <typename T>
class Abstract_network
{
    ~Abstract_network();
    Abstract_array<Abstract_layer<T>> layers;
    Abstract_optimizer<T> *optimizer;
};