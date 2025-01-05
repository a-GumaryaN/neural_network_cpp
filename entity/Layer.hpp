#include "Data_types.hpp"
#include "Activation.hpp"

template <typename T>
class Layer
{
public:
    // number of layer in network
    int layer_number = 0;
    //shape of layer
    AbstractMatrix<T> layer_shape;
    //activation function of layer
    Activation<T> *activation;
    //input value of layer in forward propagation process
    AbstractMatrix<T> *layer_input;
    //activated value
    AbstractMatrix<T> *activate_value;
    //output value of layer in forward propagation process
    AbstractMatrix<T> *layer_output;
    //type of layer that can be convolutional, dense or etc
    String layer_type;
    //layer delta
    AbstractMatrix<T> *delta;
    //layer bias
    AbstractMatrix <T> *bias;

    virtual void init_param(int layer_number, AbstractMatrix<T> prev_layer_shape);
    virtual AbstractMatrix<T> *calculate(AbstractMatrix<T> *input);
    virtual void apply_delta(AbstractMatrix<T> *delta);
    virtual AbstractMatrix<T> *calculate_delta();
    virtual void update_param();
    virtual ~Layer();
};