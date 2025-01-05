#include "Data_types.hpp"

template <typename Initialized_value_type>
class Abstract_initializer
{
public:
    Initializer();
    virtual AbstractMatrix<Initialized_value_type> *run(Abstract_array<inInitialized_value_type> input_shape);
};

template <typename Initialized_value_type>
class Random : public Abstract_initializer
{
    AbstractMatrix<Initialized_value_type> *run(Abstract_array<inInitialized_value_type> input_shape) override;
};

template <typename Initialized_value_type>
class Xavier : public Abstract_initializer
{
    AbstractMatrix<Initialized_value_type> *run(Abstract_array<inInitialized_value_type> input_shape) override;
};

template <typename Initialized_value_type>
class Normal : public Abstract_initializer
{
    AbstractMatrix<Initialized_value_type> *run(Abstract_array<inInitialized_value_type> input_shape) override;
};

template <typename Initialized_value_type>
class initializer_selector
{
    Abstract_map<String,Abstract_initializer<Initialized_value_type>> *registered;
};