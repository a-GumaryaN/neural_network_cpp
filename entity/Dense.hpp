#pragma once
#include "Layer.hpp"
#include "Optimizer.hpp"

template <typename T>
class Dense : public Abstract_layer<T>
{
    Abstract_matrix<T> *weight_matrix;
    Abstract_optimizer<T> *optimizer;

    void init_param(int layer_number, Abstract_matrix<T> prev_layer_shape) override;
    Abstract_matrix<T> *calculate(Abstract_matrix<T> *input) override;

    void apply_delta(Abstract_matrix<T> *delta) override;
    Abstract_matrix<T> *calculate_delta() override;
    void update_param() override;
    Abstract_matrix<T> *get_weights() override;
};