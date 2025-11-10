#pragma once
#include "../entity/Data_types.hpp"
#include <unordered_map>
#include <stdexcept>

template <typename Key_type, typename Value_type>
class Concrete_map : public Abstract_map<Key_type, Value_type> {
private:
    std::unordered_map<Key_type, Value_type> data;

public:
    void append(Key_type key, Value_type value) {
        data[key] = value;
    }

    Value_type *operator()(Key_type key) const {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::out_of_range("Key not found");
        }
        return const_cast<Value_type *>(&(it->second));
    }

    Value_type &operator()(Key_type key) {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::out_of_range("Key not found");
        }
        return it->second;
    }

    void del(Key_type key) {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::out_of_range("Key not found");
        }
        data.erase(it);
    }
};
