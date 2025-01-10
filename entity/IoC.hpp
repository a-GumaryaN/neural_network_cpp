#pragma once
#include "Data_types.hpp"
#include "Loss.hpp"
#include "Initializer.hpp"
#include "Activation.hpp"
#include "Optimizer.hpp"
#include "Regularization.hpp"

template <typename Dependency_type>
class Abstract_container
{
    Abstract_map<String, Dependency_type> *registered_dependencies;
    virtual void set(String name, Dependency_type custom_dependency);
    virtual Dependency_type *get(String name) const = 0;
};

/*
Loss_selector :
this class is a IoC container for initializer object
*/
template <typename Loss_value_type>
class Loss_selector : public Abstract_container<Abstract_loss<Loss_value_type>>
{
    Abstract_map<String, Abstract_loss<Loss_value_type>> *registered_dependencies;
    void set(String name, Abstract_loss<Loss_value_type> custom_loss) override;
    Abstract_loss<Loss_value_type> *get(String name) override;
};

/*
Initializer_selector :
this class is a IoC container for initializer object
*/
template <typename Initialized_value_type>
class Initializer_selector : public Abstract_container<Abstract_initializer<Initialized_value_type>>
{
    Abstract_map<String, Abstract_initializer<Initialized_value_type>> *registered_dependencies;
    void set(String name, Abstract_initializer<Initialized_value_type> custom_initializer) override;
    Abstract_initializer<Initialized_value_type> *get(String name) override;
};

/*
Activation_selector :
this class is a IoC container for initializer object
*/
template <typename Activation_value_type>
class Activation_selector : public Abstract_container<Abstract_activation<Activation_value_type>>
{
    Abstract_map<String, Abstract_activation<Activation_value_type>> *registered_dependencies;
    void set(String name, Abstract_activation<Activation_value_type> custom_pure_activation) override;
    Abstract_activation<Activation_value_type> *get(String name) override;
};

/*
Optimizer_selector :
this class is a IoC container for optimizer object
*/
template <typename Optimizer_value_type>
class Optimizer_selector : public Abstract_container<Abstract_optimizer<Optimizer_value_type>>
{
    Abstract_map<String, Abstract_optimizer<Optimizer_value_type>> *registered_dependencies;
    void set(String name, Abstract_optimizer<Optimizer_value_type> custom_pure_activation) override;
    Abstract_optimizer<Optimizer_value_type> *get(String name) override;
};

/*
Regularization_selector :
this class is a IoC container for optimizer object
*/
template <typename Output_type>
class regularization_selector : public Abstract_container<Abstract_regularization<Output_type>>
{
    Abstract_map<String, Abstract_regularization<Output_type>> *registered_dependencies;
    void set(String name, Abstract_regularization<Output_type> custom_regularization) override;
    Abstract_regularization<Output_type> *get(String name) override;
};
