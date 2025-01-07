#include "Layer.hpp"

template <typename T>
class Convolutional : public Abstract_layer<T>
{
    int layer_depth;
    int input_depth;
    Abstract_matrix<T> *kernels;
    void init_param(int layer_number, Abstract_matrix<T> prev_layer_shape) override;
    Abstract_matrix<T> *calculate(Abstract_matrix<T> *input) override;
    void apply_delta(Abstract_matrix<T> *delta) override;
    Abstract_matrix<T> *calculate_delta() override;
    void update_param() override;
    Abstract_matrix<T> *get_weights() override;
    Convolutional(int filters,int kernel_size=3,int stride=1,Abstract_array<int> padding,String mode="valid",String activation="relu");
};