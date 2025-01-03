#include "Initializer.hpp"

template <typename T>
Matrix<T> *Random::run(std:vector<int> input_shape){
    return new Matrix<T>.random(input_shape);
}


template <typename T>
Matrix<T> *Xavier::run(std:vector<int> input_shape){
    return new Matrix<T>.random(input_shape);
}