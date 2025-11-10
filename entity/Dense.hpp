#pragma once
#include "Layer.hpp"
#include "Optimizer.hpp"
#include "Activation.hpp"

template <typename T>
class Dense : public Abstract_layer<T>
{
    Abstract_matrix<T> *weight_matrix;
    Abstract_optimizer<T> *optimizer;
    Abstract_initializer<T> *initializer;
    Abstract_activation<T> *activation = nullptr;
    Abstract_matrix<T> *layer_input = nullptr;
    Abstract_matrix<T> *activate_value = nullptr;
    Abstract_matrix<T> *layer_output = nullptr;
    Abstract_matrix<T> *delta = nullptr;

    int layer_shape;
    int prev_layer_shape;
    const String layer_type = "dense";

    Dense(int length, String activation = "sigmoid", String initializer = "random");

    void init_param(int layer_number, int prev_layer_shape) override;
    Abstract_matrix<T> *calculate(Abstract_matrix<T> *input) override;

    void apply_delta(Abstract_matrix<T> *delta) override;
    Abstract_matrix<T> *calculate_delta() override;
    void update_param() override;
    Abstract_matrix<T> *get_weights() override;
};