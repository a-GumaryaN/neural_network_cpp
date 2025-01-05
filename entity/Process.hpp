#include "Data_types.hpp"

class Task
{
};

class Parallel
{
    Abstract_array<Task> *tasks;
};

class Sequential
{
    Abstract_array<Task> *tasks;
};