#ifndef AUTORES_H
#define AUTORES_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <type_traits>

#ifndef TAMANHO_HASH_AUTOR
#define TAMANHO_HASH_AUTOR 7
#endif
using namespace std;

struct Autor
{
    int matricula;
    string nome;
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
            cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
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

    int funcaoHash(string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return abs(hash % TAMANHO_HASH_AUTOR);
    }

    Autor criar(string nome) {
        Autor novoAutor;
        novoAutor.nome = nome;
        novoAutor.matricula = rand() % 100000;

        int indice = funcaoHash(novoAutor.nome);
        tabela[indice].adicionar(novoAutor);
        return novoAutor;
    }

    bool listar() {
        cout << "\n===== LISTA DE AUTORES =====\n";
        for (int i = 0; i < TAMANHO_HASH_AUTOR; i++) {
            cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            cout << endl;
        }
        cout << "==============================\n";
        return true;
    }

    bool editar(int matricula, string novoNome) {
        for (int i = 0; i < TAMANHO_HASH_AUTOR; i++) {
            NoAutor* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Autor autorParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                if (!novoNome.empty()) {
                    autorParaAtualizar.nome = novoNome;
                }

                int novoIndice = funcaoHash(autorParaAtualizar.nome);
                tabela[novoIndice].adicionar(autorParaAtualizar);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    Autor pesquisar(string campo, T valor) {
        for (int i = 0; i < TAMANHO_HASH_AUTOR; i++) {
            NoAutor* aux = tabela[i].inicio;
            while (aux != nullptr) {
                if (campo == "matricula") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.matricula == valor) return aux->valor;
                    }
                } else if (campo == "nome") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.nome == valor) return aux->valor;
                    }
                }
                aux = aux->proximo;
            }
        }

        // Se o loop terminar e nada for encontrado, retorna um Autor "vazio"
        Autor autorNaoEncontrado;
        autorNaoEncontrado.matricula = -1;
        return autorNaoEncontrado;
    }
};

#endif