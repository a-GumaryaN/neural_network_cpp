#include "Data_types.hpp"

template <typename Dependency_type>
class Abstract_container
{
    Abstract_map<String, Dependency_type> *registered_dependencies;
    virtual void set(String name, Dependency_type custom_dependency);
    virtual Dependency_type *set(String name) const = 0;
};