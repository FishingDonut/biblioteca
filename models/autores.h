#ifndef AUTORES_H
#define AUTORES_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef TAMANHO_HASH_AUTOR
#define TAMANHO_HASH_AUTOR 7
#endif

struct Autor
{
    int matricula;
    std::string nome;
};

struct NoAutor {
    Autor valor;
    NoAutor* proximo;
    NoAutor* anterior;

    explicit NoAutor(const Autor& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaAutor {
    NoAutor *inicio = nullptr;
    NoAutor *fim = nullptr;

    void adicionar(Autor valor) {
        NoAutor *novoNo = new NoAutor(valor);
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
        NoAutor *auxiliar = inicio;
        while (auxiliar != nullptr) {
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
            auxiliar = auxiliar->proximo;
        }
    }
    
    NoAutor* buscar(int matricula) {
        NoAutor *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoAutor* noParaRemover = buscar(matricula);
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

struct Autores
{
    ListaAutor tabela[TAMANHO_HASH_AUTOR];

    int funcaoHash(std::string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return std::abs(hash % TAMANHO_HASH_AUTOR);
    }

    Autor criar(std::string nome) {
        Autor novoAutor;
        novoAutor.nome = nome;
        novoAutor.matricula = rand() % 100000;

        int indice = funcaoHash(novoAutor.nome);
        tabela[indice].adicionar(novoAutor);
        return novoAutor;
    }

    void listar() {
        std::cout << "\n===== LISTA DE AUTORES =====\n";
        for (int i = 0; i < TAMANHO_HASH_AUTOR; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "==============================\n";
    }

    bool editar(int matricula, std::string novoNome) {
        for (int i = 0; i < TAMANHO_HASH_AUTOR; i++) {
            NoAutor* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Autor autorParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                autorParaAtualizar.nome = novoNome;
                
                int novoIndice = funcaoHash(autorParaAtualizar.nome);
                tabela[novoIndice].adicionar(autorParaAtualizar);
                return true;
            }
        }
        return false;
    }
};

#endif