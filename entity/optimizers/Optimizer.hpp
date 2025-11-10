#pragma once
#include "../utils/Data_types.hpp"

template <typename Optimized_value_type>
class Abstract_optimizer
{
    Abstract_map<String, long> *optimizer_parameter;
    Abstract_optimizer(Abstract_map<String, long> *optimizer_parameter);
    virtual ~Abstract_optimizer();
    virtual void *run(Abstract_matrix<Optimized_value_type> *parameter, Abstract_matrix<Optimized_value_type> *gradin);
};

template <typename Optimized_value_type>
class Adam : Abstract_optimizer<Optimized_value_type>
{
    long beta1 = 0.9;
    long beta2 = 0.99999;
    long epsilon = 0.00000001;
    int t = 0;
    void *run(Abstract_matrix<Optimized_value_type> *parameter, Abstract_matrix<Optimized_value_type> *gradin) override;
};

template <typename Optimized_value_type>
class Adagrad : Abstract_optimizer<Optimized_value_type>
{
    void *run(Abstract_matrix<Optimized_value_type> *parameter, Abstract_matrix<Optimized_value_type> *gradin) override;
};

template <typename Optimized_value_type>
class RMSprop : Abstract_optimizer<Optimized_value_type>
{
    void *run(Abstract_matrix<Optimized_value_type> *parameter, Abstract_matrix<Optimized_value_type> *gradin) override;
};

template <typename Optimized_value_type>
class GD : Abstract_optimizer<Optimized_value_type>
{
    void *run(Abstract_matrix<Optimized_value_type> *parameter, Abstract_matrix<Optimized_value_type> *gradin) override;
};