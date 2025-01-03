#include "Matrix.hpp"
#include "Process.hpp"

class Pure_activation
{
    public:
    virtual long activation(long input);
    virtual long activation_derivative(long input);
    virtual ~Pure_activation();
};

class Sigmoid : public Pure_activation
{
    long activation(long input);
    long activation_derivative(long input);
};

class Relu : public Pure_activation
{
    long activation(long input);
    long activation_derivative(long input);
};

class Leaky_relu : public Pure_activation
{
    long activation(long input);
    long activation_derivative(long input);
};

class Tanh : public Pure_activation
{
    long activation(long input);
    long activation_derivative(long input);
};

template <typename T>
class Activation
{
public:
    Pure_activation *act;

    void set_activation(Pure_activation *act);

    Matrix<T> *run(Matrix *input);
    Matrix<T> *run_derivative(Matrix *input);
};