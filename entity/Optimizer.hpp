#include "Data_types.hpp"

template <typename T>
class Optimizer
{
    Abstract_map<String, long> *optimizer_parameter;
    virtual Optimizer(Abstract_map<String, long> *optimizer_parameter);
    virtual ~Optimizer();
    virtual void *run(AbstractMatrix<T> *parameter, AbstractMatrix<T> *gradin);
};

template <typename T>
class Adam : Optimizer
{
};

template <typename T>
class GD : Optimizer
{
};