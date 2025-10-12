#pragma once

#include "no.h"
#include <iostream>

template <typename T>
struct Lista
{
    No<T> *inicio = nullptr;
    No<T> *fim = nullptr;

    void adicionar(T valor)
    {
        No<T> *novoNo = new No<T>(valor);

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

    void editar(T valor){
        
    }

    bool buscar(T valor)
    {
        No<T> *auxiliar = inicio;
        while (auxiliar != nullptr)
        {
            if (auxiliar->valor == valor)
            {
                return true;
            }
            auxiliar = auxiliar->proximo;
        }
        return false;
    }

    void mostrar()
    {
        No<T> *auxiliar = inicio;
        while (auxiliar != nullptr)
        {
            std::cout << " -> " << auxiliar->valor;
            auxiliar = auxiliar->proximo;
        }
    }
};