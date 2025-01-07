#include "Data_types.hpp"
#include "Activation.hpp"

template <typename T>
class Abstract_layer
{
public:
    // number of layer in network
    int layer_number = 0;
    // shape of layer
    Abstract_matrix<T> layer_shape;
    // activation function of layer
    Abstract_activation<T> *activation;
    // input value of layer in forward propagation process
    Abstract_matrix<T> *layer_input;
    // activated value
    Abstract_matrix<T> *activate_value;
    // output value of layer in forward propagation process
    Abstract_matrix<T> *layer_output;
    // type of layer that can be convolutional, dense or etc
    String layer_type;
    // layer delta
    Abstract_matrix<T> *delta;
    // layer bias
    Abstract_matrix<T> *bias;

    virtual void init_param(int layer_number, Abstract_matrix<T> prev_layer_shape);
    virtual Abstract_matrix<T> *calculate(Abstract_matrix<T> *input);
    virtual void apply_delta(Abstract_matrix<T> *delta);
    virtual Abstract_matrix<T> *calculate_delta();
    virtual void update_param();
    virtual void set_initializer(Abstract_initializer *initializer);
    virtual Abstract_matrix<T> *get_weights() const = 0;
    virtual ~Layer();
};