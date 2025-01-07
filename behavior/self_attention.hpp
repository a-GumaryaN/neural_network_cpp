#include "Self_attention.hpp"

template <typename T>
Self_attention<T>::Self_attention(int input_dim, int head_dim)
{
    scale = sqrt(head_dim);
    W_q = Abstract_matrix<T>::random(input_dim, head_dim);
    W_k = Abstract_matrix<T>::random(input_dim, head_dim);
    W_v = Abstract_matrix<T>::random(input_dim, head_dim);
}
template <typename T>
void init_param(int layer_number, Abstract_matrix<T> prev_layer_length)
{
    return;
}

template <typename T>
Abstract_matrix<T> Self_attention<T>::calculate(const Abstract_matrix<T> &input)
{
    Abstract_matrix<T> Q = input.dot(this->W_q);
    Abstract_matrix<T> K = input.dot(this->W_k);
    Abstract_matrix<T> V = input.dot(this->W_v);

    Abstract_matrix<T> scores = Q.dot(K.transpose()) / this->scale;
    // activation for self attention layer usually is softmax
    Abstract_matrix<T> attention_weights = this->activation->run(scores);

    Abstract_matrix<T> output = attention_weights.dot(V);
    return output;
}
template <typename T>
void Self_attention<T>::apply_delta(const Abstract_matrix<T> &d_output)
{
    Abstract_matrix<T> d_attention_weights = *d_output.dot(this->W_v.transpose());
    Abstract_matrix<T> this->d_V = d_attention_weights.dot(this->W_v);
}
template <typename T>
Abstract_matrix<T> Self_attention<T>::*calculate_delta()
{
    Abstract_matrix<T> d_scores = d_attention_weights.dot(W_k.transpose());
    Abstract_matrix<T> d_Q = d_scores.dot(W_q);
    Abstract_matrix<T> d_K = d_scores.dot(W_k);
    Abstract_matrix<T> delta; // three dimensional matrix
    // delta => concat of d_Q, d_K and d_V
    return delta
}
template <typename T>
void Self_attention<T>::update_param()
{
    return;
}