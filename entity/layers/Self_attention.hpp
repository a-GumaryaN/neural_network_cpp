#pragma once
#include <vector>
#include "../utils/Matematics.hpp"
#include "../utils/Data_types.hpp"
#include "Layer.hpp"
#include "../activatios/Activation.hpp"

template <typename T>
class Self_attention : public Abstract_layer<T>
{
private:
    Abstract_matrix<T> *W_q;
    Abstract_matrix<T> *W_k;
    Abstract_matrix<T> *W_v;
    double scale;

    Abstract_activation<T> *activation;

public:
    Self_attention(int input_dim, int head_dim) override;

    void init_param(int layer_number, Abstract_matrix<T> prev_layer_length) override;

    Abstract_matrix<T> calculate(const Abstract_matrix<T> *input) override;

    void apply_delta(const Abstract_matrix<T> *d_output) override;

    Abstract_matrix<T> *calculate_delta() override;

    void update_param() override;
};