#include "Data_types.hpp"
#include "Layer.hpp"

template <typename T>
class Network
{
    ~Network();
    Abstract_array<Abstract_layer<T>> layers;
};