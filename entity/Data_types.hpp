#pragma once
#include <iostream>

typedef std::string String;

template <typename Value_type>
class Abstract_array
{
public:
    virtual void add(const Value_type &item) = 0;
    // virtual Value_type *operator()(int index) const = 0;
    virtual Value_type operator()(int index);
    virtual size_t size() const = 0;
    virtual ~Abstract_array() = default;
};

template <typename Key_type, typename Value_type>
class Abstract_map
{
public:
    // virtual void append(Key_type key, Value_type value);
    // virtual Value_type *operator()(Key_type key) const = 0;
    // virtual Value_type &operator()(Key_type key);
    // virtual void del(Key_type key);
};

template <typename T>
class Abstract_matrix
{
    Abstract_array<int> *dimensions = nullptr;

public:
    virtual ~Abstract_matrix() {}
    /*
    basics operations
    */
    virtual Abstract_matrix<T> *dot(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *multiply(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *operator+(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *operator+(const double &other) const = 0;
    virtual Abstract_matrix<T> *operator-(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *operator-(const double &other) const = 0;
    virtual Abstract_matrix<T> *operator/(double other) const = 0;
    virtual Abstract_matrix<T> *transpose();
    virtual Abstract_matrix<T> *inverse();
    /*
    scalar operation
    */
    virtual Abstract_matrix<T> *scalar_division(double scalar) const = 0;
    virtual Abstract_matrix<T> *scalar_addition(double scalar) const = 0;
    virtual Abstract_matrix<T> *scalar_substraction(double scalar) const = 0;
    virtual Abstract_matrix<T> *scalar_multiplication(double scalar) const = 0;
    virtual Abstract_matrix<T> *scalar_power(double scalar) const = 0;
    friend Abstract_matrix<T> *operator+(double scalar, const Abstract_matrix<T> &matrix) const = 0;
    friend Abstract_matrix<T> *operator-(double scalar, const Abstract_matrix<T> &matrix) const = 0;
    friend Abstract_matrix<T> *operator*(double scalar, const Abstract_matrix<T> &matrix) const = 0;
    friend Abstract_matrix<T> *operator/(double scalar, const Abstract_matrix<T> &matrix) const = 0;
    friend Abstract_matrix<T> *operator^(double scalar, const Abstract_matrix<T> &matrix) const = 0;
    virtual Abstract_matrix<T> *exp();
    virtual Abstract_matrix<T> *log();
    /*
    probability and statistics operations
    */
    virtual Abstract_matrix<T> *sum(int axis = 0, bool keepdims = true);
    virtual T *mean(int axis = 0, bool keepdims = true);
    virtual T *mean();
    virtual T *max();
    virtual T *min();
    virtual T *std();
    virtual T *variance();
    virtual int arg_min();
    virtual int arg_max();
    virtual Abstract_matrix<T> *entropy();
    virtual Abstract_matrix<T> *kl_divergence();
    /*
    linear algebra operation
    */
    virtual T svd();
    virtual Abstract_matrix<T> *lu_decomposition();
    virtual Abstract_matrix<T> *qr_decomposition();
    virtual Abstract_matrix<T> *solve(Abstract_matrix<T> *other);
    /*
    mathematics operations
    */
    virtual Abstract_matrix<T> *sigmoid();
    virtual Abstract_matrix<T> *relu();
    virtual Abstract_matrix<T> *leaky_relu();
    virtual Abstract_matrix<T> *tanh();

    /*
    allocation operations
    */
    virtual Abstract_matrix<T> *copy();
    virtual Abstract_matrix<T> full(Abstract_array<int> *shape);
    virtual Abstract_matrix<T> ones(Abstract_array<int> *shape);
    virtual Abstract_matrix<T> zeros(Abstract_array<int> *shape);
    virtual Abstract_matrix<T> *random(Abstract_array<T> shape);

    /*
    signal processing
    */
    virtual Abstract_matrix<T> *convolve(Abstract_matrix<T> *kernel, String mode = "valid", int stride = 1);
    virtual Abstract_matrix<T> *up_sampling(Abstract_array<int> *shape);
    virtual Abstract_matrix<T> *max_pooling(Abstract_array<int> *window_size, int stride = 1);
    virtual Abstract_matrix<T> *avg_pooling(Abstract_array<int> *window_size, int stride = 1);

    /*
    shaping and reshaping
    */
    virtual Abstract_array<int> *reshape() const = 0;
    virtual Abstract_array<int> *expand_dims(int axis=0) const = 0;
    virtual T operator()(Abstract_array<int> indexes) const = 0;
    virtual T &operator()(Abstract_array<int> indexes) = 0;
    virtual Abstract_matrix<T> *uniform(double min, double max, Abstract_array<T> input_shape);
    virtual Abstract_matrix<T> *maximize(double maximum_value);
    virtual double determinant();
    virtual void print() const = 0;
    virtual T sum_of_squared();
};