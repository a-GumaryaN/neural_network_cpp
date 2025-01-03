template <typename T>
class Matrix
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
    virtual void print() const = 0;
};