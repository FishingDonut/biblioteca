#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "historicos.h"

#ifndef TAMANHO_HASH_USUARIO
#define TAMANHO_HASH_USUARIO 7
#endif

struct Usuario
{
    int matricula;
    std::string nome;
    ListaHistorico historico;
};

struct NoUsuario {
    Usuario valor;
    NoUsuario* proximo;
    NoUsuario* anterior;

    explicit NoUsuario(const Usuario& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaUsuario {
    NoUsuario *inicio = nullptr;
    NoUsuario *fim = nullptr;

    void adicionar(Usuario valor) {
        NoUsuario *novoNo = new NoUsuario(valor);
        if (inicio == nullptr) {
            inicio = novoNo;
            fim = novoNo;
        } else {
            fim->proximo = novoNo;
            novoNo->anterior = fim;
            fim = novoNo;
        }
    }

    void mostrar() {
        NoUsuario *auxiliar = inicio;
        while (auxiliar != nullptr) {
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
            auxiliar = auxiliar->proximo;
        }
    }

    NoUsuario* buscar(int matricula) {
        NoUsuario *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoUsuario* noParaRemover = buscar(matricula);
        if (noParaRemover == nullptr) {
            return false;
        }

        if (noParaRemover == inicio) {
            inicio = noParaRemover->proximo;
        }
        if (noParaRemover == fim) {
            fim = noParaRemover->anterior;
        }
        if (noParaRemover->proximo != nullptr) {
            noParaRemover->proximo->anterior = noParaRemover->anterior;
        }
        if (noParaRemover->anterior != nullptr) {
            noParaRemover->anterior->proximo = noParaRemover->proximo;
        }

        delete noParaRemover;
        return true;
    }
};

struct Usuarios
{
    ListaUsuario tabela[TAMANHO_HASH_USUARIO];

    int funcaoHash(std::string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return std::abs(hash % TAMANHO_HASH_USUARIO);
    }

    Usuario criar(std::string nome) {
        Usuario novoUsuario;
        novoUsuario.nome = nome;
        novoUsuario.matricula = rand() % 100000;

        int indice = funcaoHash(novoUsuario.nome);
        tabela[indice].adicionar(novoUsuario);
        return novoUsuario;
    }

    void listar() {
        std::cout << "\n===== LISTA DE USUARIOS =====\n";
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "===============================\n";
    }

    bool editar(int matricula, std::string novo_nome) {
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            NoUsuario* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Usuario usuarioParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                usuarioParaAtualizar.nome = novo_nome;
                
                int novoIndice = funcaoHash(usuarioParaAtualizar.nome);
                tabela[novoIndice].adicionar(usuarioParaAtualizar);
                return true;
            }
        }
        return false;
    }
};

#endif
