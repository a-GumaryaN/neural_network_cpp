#include "IoC.hpp"
#include "Loss.hpp"

template <typename Loss_value_type>
void Loss_selector<Loss_value_type>::set(String name, Abstract_loss<Loss_value_type> custom_dependency)
{
    this->registered_dependencies.append(name, custom_dependency);
}

template <typename Loss_value_type>
Abstract_loss<Loss_value_type> *Loss_selector<Loss_value_type>::get(String name)
{
    return new this->registered_dependencies(name)();
}