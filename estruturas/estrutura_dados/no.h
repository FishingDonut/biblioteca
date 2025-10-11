#pragma once

template <typename T>
struct No
{
    T valor;
    No<T>* proximo;
    No<T>* anterior;

    explicit No(const T& val)
    {
        valor = val;
        proximo = nullptr;
        anterior = nullptr;
    }
};