#include <iostream>
#include "Matrix.hpp"
#include "Activation.hpp"

template <typename T>
class Layer
{
public:
    // number of layer in network
    int layer_number = 0;
    //shape of layer
    Matrix<T> layer_shape;
    //activation function of layer
    Activation<T> *activation;
    //input value of layer in forward propagation process
    Matrix<T> layer_input;
    //activated value
    Matrix<T> activate_value;
    //output value of layer in forward propagation process
    Matrix<T> layer_output;
    //type of layer that can be convolutional, dense or etc
    std::string layer_type;
    //layer delta
    Matrix<T> delta;

    virtual void init_param(int layer_number, Matrix prev_layer_shape);
    virtual Matrix *calculate(Matrix *input);
    virtual void apply_delta(Matrix *delta);
    virtual Matrix *calculate_delta();
    virtual void update_param();
    virtual ~Layer();
};