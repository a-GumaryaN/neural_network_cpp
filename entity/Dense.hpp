#include "Layer.hpp"
#include "Optimizer.hpp"

template <typename T>
class Dense:public Layer<T>{
    Matrix<T> weight_matrix;
    Optimizer<T> *weight_optimizer;
    Optimizer<T> *bias_optimizer;

    void init_param(int layer_number, Matrix<T> prev_layer_shape);
    Matrix<T> *calculate(Matrix<T> *input){

    }


    void apply_delta(Matrix<T> *delta);
    Matrix<T> *calculate_delta();
    void update_param();
};