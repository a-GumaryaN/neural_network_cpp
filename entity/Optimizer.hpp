#include "Data_types.hpp"

template <typename Optimized_value_type>
class Abstract_optimizer
{
    Abstract_map<String, long> *optimizer_parameter;
    virtual Optimizer(Abstract_map<String, long> *optimizer_parameter);
    virtual ~Optimizer();
    virtual void *run(Abstract_matrix<T> *parameter, Abstract_matrix<Optimized_value_type> *gradin);
};

template <typename Optimized_value_type>
class Adam : Abstract_optimizer<Optimized_value_type>
{
};

template <typename Optimized_value_type>
class GD : Abstract_optimizer<Optimized_value_type>
{
};