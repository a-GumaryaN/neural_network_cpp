#include "Data_types.hpp"

template <typename T>
class Abstract_loss
{

public:
    int number_of_data = 0;
    Abstract_matrix<T> error = 0;
    virtual Abstract_matrix<T> *loss(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value);
    virtual Abstract_matrix<T> *loss_derivative(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value);
    virtual ~Loss();
};

template <typename T>
class MSE : Abstract_loss<T>
{
public:
    Abstract_matrix<T> *loss(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value) override;
    Abstract_matrix<T> *loss_derivative(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value) override;
};

template <typename T>
class MAE : public Abstract_loss<T>
{
public:
    Abstract_matrix<T> *loss(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value) override;
    Abstract_matrix<T> *loss_derivative(Abstract_matrix<T> *actual_value, Abstract_matrix<T> *expected_value) override;
};