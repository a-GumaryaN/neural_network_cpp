#pragma once
#include <iostream>

typedef std::string String;

template <typename Value_type>
class Abstract_array
{
public:
    virtual void add(const Value_type &item) = 0;
    virtual Value_type *operator()(int index) const = 0;
    virtual Value_type &operator()(int index);
    virtual size_t size() const = 0;
    virtual ~Abstract_array() = default;
};

template <typename Key_type, typename Value_type>
class Abstract_map
{
public:
    virtual void append(Key_type key, Value_type value);
    virtual Value_type *operator()(Key_type key) const = 0 ;
    virtual Value_type &operator()(Key_type key);
    virtual void del(Key_type key);
};

template <typename T>
class Abstract_matrix
{
    int dimension = 1;

public:
    virtual ~Abstract_matrix() {}
    virtual int get_rows() const = 0;
    virtual int get_cols() const = 0;
    virtual T operator()(Abstract_array<int> indexes) const = 0;
    virtual T &operator()(Abstract_array<int> indexes) = 0;
    virtual Abstract_matrix<T> *dot(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *multiply(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *operator+(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *operator+(const double &other) const = 0;
    virtual Abstract_matrix<T> *operator-(const Abstract_matrix<T> &other) const = 0;
    virtual Abstract_matrix<T> *operator-(const double &other) const = 0;
    virtual Abstract_matrix<T> *operator/(double other) const = 0;
    virtual Abstract_matrix<T> *sum(int axis = 0, bool keepdims = true);
    virtual Abstract_matrix<T> *random(Abstract_array<T> shape);
    virtual Abstract_matrix<T> *exp_powered();
    virtual Abstract_matrix<T> *uniform(double min, double max, Abstract_array<T> input_shape);
    virtual Abstract_matrix<T> *transpose();
    virtual Abstract_matrix<T> *maximize(double maximum_value);
    virtual double determinant();
    virtual Abstract_matrix<T> *convolve(Abstract_matrix<T> *kernel, String mode = "valid", int stride = 1);
    virtual void print() const = 0;
    virtual T sum_of_squared();
};