#include <iostream>

typedef std::string String;

template <typename Value_type>
class Abstract_array
{
public:
    virtual void add(const T &item) = 0;
    virtual const T &get(int index) const = 0;
    virtual size_t size() const = 0;
    virtual ~Abstract_array() = default;
};

template <typename Key_type, typename Value_type>
class Abstract_paired_value
{
public:
    Key_type key;
    Value_type *value;
    Abstract_paired_value(Key_type key, Value_type value);
};

template <typename Key_type, typename Value_type>
class Abstract_map
{
public:
    virtual void append(Key_type key, Value_type value);
    virtual Value_type *operator()(Key_type key) const = 0;
    virtual void del(Key_type key);
};

template <typename T>
class AbstractMatrix
{
public:
    virtual ~AbstractMatrix() {}

    virtual int get_rows() const = 0;
    virtual int get_cols() const = 0;
    virtual T operator()(int row, int col) const = 0;
    virtual T &operator()(int row, int col) = 0;
    virtual AbstractMatrix<T> *dot(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *multiply(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *operator+(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *operator-(const AbstractMatrix<T> &other) const = 0;
    virtual AbstractMatrix<T> *sum(int axis = 0, bool keepdims = true);
    virtual void print() const = 0;
};