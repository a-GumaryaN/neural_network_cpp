#pragma once
#include "Layer.hpp"
#include "Initializer.hpp"

template <typename T>
class Embedding : public Abstract_layer<T>
{
private:
    Abstract_matrix<T> *embedding_weights;
    int vocab_size;
    int embedding_dim;
    Abstract_initializer<T> *embedding_weights_initializer;

public:
    Embedding(int vocab_size, int embedding_dim);

    void init_param(int layer_number, Abstract_matrix<T> prev_layer_len);
};