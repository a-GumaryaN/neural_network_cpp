#include "Matrix.hpp"

template <typename T>
class Loss
{

public:
    int number_of_data = 0;
    long error = 0;
    virtual Matrix<T> *loss(Matrix<T> *actual_value, Matrix<T> *expected_value);
    virtual Matrix<T> *loss_derivative(Matrix<T> *actual_value, Matrix<T> *expected_value);
    virtual ~Loss();
};

template <typename T>
class MSE : Loss
{
public:
    Matrix<T> *loss(Matrix<T> *actual_value, Matrix<T> *expected_value) override;
    Matrix<T> *loss_derivative(Matrix<T> *actual_value, Matrix<T> *expected_value) override;
};

template <typename T>
class MAE : Loss
{
public:
    Matrix<T> *loss(Matrix<T> *actual_value, Matrix<T> *expected_value) override;
    Matrix<T> *loss_derivative(Matrix<T> *actual_value, Matrix<T> *expected_value) override;
};