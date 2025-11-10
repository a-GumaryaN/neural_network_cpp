#pragma once
#include "../entity/Data_types.hpp"
#include <vector>
#include <stdexcept>

template <typename Value_type>
class Concrete_array : public Abstract_array<Value_type>
{
private:
    std::vector<Value_type> data;

public:
    void add(const Value_type &item) override
    {
        data.push_back(item);
    }
    // Value_type *operator()(int index) const override
    // {
    //     if (index < 0 || index >= static_cast<int>(data.size()))
    //     {
    //         throw std::out_of_range("Index out of range");
    //     }
    //     return const_cast<Value_type *>(&data[index]);
    // }

    Value_type operator()(int index)
    {
        if (index < 0 || index >= static_cast<int>(data.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    size_t size() const override
    {
        return data.size();
    }
};
