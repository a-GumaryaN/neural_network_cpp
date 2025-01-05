#include "Data_types.hpp"
#include "IoC.hpp"

template <typename T>
class Abstract_loss
{

public:
    int number_of_data = 0;
    AbstractMatrix<T> error = 0;
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

/*
Loss_selector :
this class is a IoC container for initializer object
*/
template <typename Loss_value_type>
class Loss_selector : public Abstract_container<Abstract_loss<Loss_value_type>>
{
};