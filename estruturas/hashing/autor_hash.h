#ifndef TAMANHO
#define TAMANHO 7
#endif

#include <iostream>
#include <string>
#include "../modelos/autor.h"
#include "../estrutura_dados/lista.h"

using namespace std;

struct AutorHash
{
    Lista<Autor> tabela[TAMANHO];

    void adicionar(int chave, Autor valor)
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