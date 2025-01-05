#include "Data_types.hpp"
#include "IoC.hpp"

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

/*
Initializer_selector :
this class is a IoC container for initializer object
*/
template <typename Initialized_value_type>
class Initializer_selector : public Abstract_container<Abstract_initializer<Initialized_value_type>>
{
};