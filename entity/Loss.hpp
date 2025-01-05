#include "Data_types.hpp"

template <typename T>
class Loss
{

public:
    int number_of_data = 0;
    long error = 0;
    virtual AbstractMatrix<T> *loss(AbstractMatrix<T> *actual_value, AbstractMatrix<T> *expected_value);
    virtual AbstractMatrix<T> *loss_derivative(AbstractMatrix<T> *actual_value, AbstractMatrix<T> *expected_value);
    virtual ~Loss();
};

template <typename T>
class MSE : Loss<T>
{
public:
    AbstractMatrix<T> *loss(AbstractMatrix<T> *actual_value, AbstractMatrix<T> *expected_value) override;
    AbstractMatrix<T> *loss_derivative(AbstractMatrix<T> *actual_value, AbstractMatrix<T> *expected_value) override;
};

template <typename T>
class MAE : Loss<T>
{
public:
    AbstractMatrix<T> *loss(AbstractMatrix<T> *actual_value, AbstractMatrix<T> *expected_value) override;
    AbstractMatrix<T> *loss_derivative(AbstractMatrix<T> *actual_value, AbstractMatrix<T> *expected_value) override;
};