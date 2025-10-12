#ifndef EDITORAS_H
#define EDITORAS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef TAMANHO_HASH_EDITORA
#define TAMANHO_HASH_EDITORA 7
#endif

struct Editora
{
    int matricula;
    std::string nome;
};

struct NoEditora {
    Editora valor;
    NoEditora* proximo;
    NoEditora* anterior;

    explicit NoEditora(const Editora& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaEditora {
    NoEditora *inicio = nullptr;
    NoEditora *fim = nullptr;

    void adicionar(Editora valor) {
        NoEditora *novoNo = new NoEditora(valor);
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
        NoEditora *auxiliar = inicio;
        while (auxiliar != nullptr) {
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
            auxiliar = auxiliar->proximo;
        }
    }
};

struct Editoras
{
    ListaEditora tabela[TAMANHO_HASH_EDITORA];

    int funcaoHash(std::string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return std::abs(hash % TAMANHO_HASH_EDITORA);
    }

    bool criar(std::string nome) {
        Editora novaEditora;
        novaEditora.nome = nome;
        novaEditora.matricula = rand() % 100000;

        int indice = funcaoHash(novaEditora.nome);
        tabela[indice].adicionar(novaEditora);
        return true;
    }

    void listar() {
        std::cout << "\n===== LISTA DE EDITORAS =====\n";
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "===============================\n";
    }

    bool editar(int matricula, std::string nome) {
        return false;
    }
};

#endif