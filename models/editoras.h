#ifndef EDITORAS_H
#define EDITORAS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <type_traits>
using namespace std;

#ifndef TAMANHO_HASH_EDITORA
#define TAMANHO_HASH_EDITORA 7
#endif

struct Editora
{
    int matricula;
    string nome;
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
            cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
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

    int funcaoHash(string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return abs(hash % TAMANHO_HASH_EDITORA);
    }

    Editora criar(string nome) {
        Editora novaEditora;
        novaEditora.nome = nome;
        novaEditora.matricula = rand() % 100000;

        int indice = funcaoHash(novaEditora.nome);
        tabela[indice].adicionar(novaEditora);
        return novaEditora;
    }

    bool listar() {
        cout << "\n===== LISTA DEEDITORAS =====\n";
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            cout << endl;
        }
        cout << "===============================\n";
        return true;
    }

    bool editar(int matricula, string novoNome) {
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            NoEditora* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Editora editoraParaAtualizar = no->valor;
                tabela[i].remover(matricula);
                
                if (!novoNome.empty()) {
                    editoraParaAtualizar.nome = novoNome;
                }
                
                int novoIndice = funcaoHash(editoraParaAtualizar.nome);
                tabela[novoIndice].adicionar(editoraParaAtualizar);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    Editora pesquisar(string campo, T valor) {
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            NoEditora* aux = tabela[i].inicio;
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

        // Se o loop terminar e nada for encontrado, retorna uma Editora "vazia"
        Editora editoraNaoEncontrada;
        editoraNaoEncontrada.matricula = -1;
        return editoraNaoEncontrada;
    }

    template <typename T>
    ListaEditora pesquisaLista(string campo, T valor) {
        ListaEditora resultados;
        for (int i = 0; i < TAMANHO_HASH_EDITORA; i++) {
            NoEditora* aux = tabela[i].inicio;
            while (aux != nullptr) {
                if (campo == "matricula") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.matricula == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                } else if (campo == "nome") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.nome == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                }
                aux = aux->proximo;
            }
        }
        cout << "\n===== RESULTADO DA PESQUISA =====\n";
        resultados.mostrar();
        cout << "\n==============================\n";
        return resultados;
    }
};

#endif
