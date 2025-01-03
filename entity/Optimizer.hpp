#include "Matrix.hpp"

template <typename T>
class Optimizer{
    long learning_rate=0;
    void run(Matrix *parameter,Matrix *gradin);
};

template <typename T>
class Adam:Optimizer{
    long learning_rate=0;
    int t=0;
    long beta1=0.9;
    long beta2=0.9999;
    long epsilon=0.00000001;
};

template <typename T>
class GD:Optimizer{};