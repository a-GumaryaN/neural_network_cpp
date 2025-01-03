#include <vector>
#include "Matrix.hpp"


template <typename T>
class Initializer{
    public:
    Initializer();
    virtual Matrix<T> *run(std::vector<int> input_shape);
};

template <typename T>
class Random:public Initializer{
    Matrix<T> *run(std::vector<int> input_shape)override;
};

template <typename T>
class Xavier:public Initializer{};