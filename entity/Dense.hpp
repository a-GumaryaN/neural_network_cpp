#include "Layer.hpp"
#include "Optimizer.hpp"

template <typename T>
class Dense:public Layer<T>{
    AbstractMatrix<T> weight_matrix;
    Optimizer<T> *weight_optimizer;
    Optimizer<T> *bias_optimizer;

    void init_param(int layer_number, AbstractMatrix<T> prev_layer_shape);
    AbstractMatrix<T> *calculate(AbstractMatrix<T> *input){

    }


    void apply_delta(AbstractMatrix<T> *delta);
    AbstractMatrix<T> *calculate_delta();
    void update_param();
};