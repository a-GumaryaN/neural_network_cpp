#pragma once
#include "Data_types.hpp"
#include "Network.hpp"

template <typename T>
class Abstract_regularization
{
    T run(Abstract_matrix<T> *loss, Abstract_network<T> *network) const = 0;
};

template <typename T>
class L1_regularization : public Abstract_regularization<T>
{
    T run(Abstract_matrix<T> *loss, Abstract_network<T> *network) override;
};

template <typename T>
class L2_regularization : public Abstract_regularization<T>
{
    double lambda;
    T run(Abstract_matrix<T> *loss, Abstract_network<T> *network) override;
};