#ifndef TAMANHO
#define TAMANHO 7
#endif

#include "Lista.h"
#include "No.h"

#include <iostream>

using namespace std;

template <typename T>
struct TabelaHash
{
    Lista<T> tabela[TAMANHO];

    void adicionar(int chave, T valor)
    {
        int indice = chave % TAMANHO;
        cout << "Valor de hashing adicionado na posicao: " << indice << endl;
        tabela[indice].adicionar(valor);
    }

    void mostrarTudo()
    {
        cout << "\n===== CONTEUDO DA TABELA HASH =====\n";
        for (int i = 0; i < TAMANHO; i++)
        {
            cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            cout << endl;
        }
        cout << "=====================================\n";
    }
};