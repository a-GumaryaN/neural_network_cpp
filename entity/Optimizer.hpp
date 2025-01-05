#include "Data_types.hpp"
#include "IoC.hpp"

template <typename Optimized_value_type>
class Abstract_optimizer
{
    Abstract_map<String, long> *optimizer_parameter;
    virtual Optimizer(Abstract_map<String, long> *optimizer_parameter);
    virtual ~Optimizer();
    virtual void *run(AbstractMatrix<T> *parameter, AbstractMatrix<Optimized_value_type> *gradin);
};

template <typename Optimized_value_type>
class Adam : Abstract_optimizer<Optimized_value_type>
{
};

template <typename Optimized_value_type>
class GD : Abstract_optimizer<Optimized_value_type>
{
};

/*
Optimizer_selector :
this class is a IoC container for optimizer object
*/
template <typename Optimizer_value_type>
class Optimizer_selector : public Abstract_container<Abstract_optimizer<Optimizer_value_type>>
{
};