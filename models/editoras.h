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

    NoEditora* buscar(int matricula) {
        NoEditora *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoEditora* noParaRemover = buscar(matricula);
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

    Editora criar(std::string nome) {
        Editora novaEditora;
        novaEditora.nome = nome;
        novaEditora.matricula = rand() % 100000;

        int indice = funcaoHash(novaEditora.nome);
        tabela[indice].adicionar(novaEditora);
        return novaEditora;
    }

    void listar() {
        std::cout << "\n===== LISTA DEEDITORAS =====\n";
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "===============================\n";
    }

    bool editar(int matricula, std::string novoNome) {
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            NoEditora* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Editora editoraParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                editoraParaAtualizar.nome = novoNome;
                
                int novoIndice = funcaoHash(editoraParaAtualizar.nome);
                tabela[novoIndice].adicionar(editoraParaAtualizar);
                return true;
            }
        }
        return false;
    }
};

#endif
