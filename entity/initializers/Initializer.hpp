#pragma once
#include "../utils/Data_types.hpp"

template <typename Initialized_value_type>
class Abstract_initializer
{
public:
    Abstract_initializer();
    Abstract_map<String, double> *param;
    virtual Abstract_matrix<Initialized_value_type> *run(Abstract_array<Initialized_value_type> input_shape);
};

template <typename Initialized_value_type>
class Random : public Abstract_initializer<Initialized_value_type>
{
    Abstract_matrix<Initialized_value_type> *run(Abstract_array<Initialized_value_type> input_shape) override;
};

template <typename Initialized_value_type>
class Xavier : public Abstract_initializer<Initialized_value_type>
{
    Abstract_matrix<Initialized_value_type> *run(Abstract_array<Initialized_value_type> input_shape) override;
};

template <typename Initialized_value_type>
class Normal : public Abstract_initializer<Initialized_value_type>
{
    Abstract_matrix<Initialized_value_type> *run(Abstract_array<Initialized_value_type> input_shape) override;
};