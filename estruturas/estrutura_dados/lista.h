#pragma once

#include "no.h"
#include <iostream>

template <typename T>
struct Lista
{
    No<T>* inicio = nullptr;
    No<T>* fim = nullptr;

    void adicionar(T valor)
    {
        No<T>* novoNo = new No<T>(valor);
        
        if (inicio == nullptr) 
        {
            inicio = novoNo;
            fim = novoNo;
        } 
        else 
        {
            fim->proximo = novoNo;
            novoNo->anterior = fim;
            fim = novoNo;
        }
    }

    void mostrar()
    {
        No<T>* auxiliar = inicio;
        while (auxiliar != nullptr)
        {
            std::cout << " -> " << auxiliar->valor;
            auxiliar = auxiliar->proximo;
        }
    }
};