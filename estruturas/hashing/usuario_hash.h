#pragma once

#ifndef TAMANHO
#define TAMANHO 7
#endif

#include "../estrutura_dados/lista.h"
#include "../estrutura_dados/no.h"
#include "../modelos/usuario.h"

#include <iostream>

struct UsuarioHash
{
    Lista<Usuario> tabela[TAMANHO];

    void adicionar(int chave, Usuario valor)
    {
        int indice = chave % TAMANHO;
        tabela[indice].adicionar(valor);
    }

    void mostrarTudo()
    {
        std::cout << "\n===== CONTEUDO DA TABELA HASH =====\n";
        for (int i = 0; i < TAMANHO; i++)
        {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "=====================================\n";
    }
};
