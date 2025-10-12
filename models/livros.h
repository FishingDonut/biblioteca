#ifndef LIVROS_H
#define LIVROS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <type_traits>
using namespace std;

#ifndef TAMANHO_HASH_LIVRO
#define TAMANHO_HASH_LIVRO 7
#endif

struct Livro
{
    int matricula;
    int autor;
    int editora;
    string assunto;
    int tipo;
    bool alugado;
    string data_alugel;
};

struct NoLivro {
    Livro valor;
    NoLivro* proximo;
    NoLivro* anterior;

    explicit NoLivro(const Livro& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaLivro {
    NoLivro *inicio = nullptr;
    NoLivro *fim = nullptr;

    void adicionar(Livro valor) {
        NoLivro *novoNo = new NoLivro(valor);
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
        NoLivro *auxiliar = inicio;
        while (auxiliar != nullptr) {
            cout << " -> Matricula: " << auxiliar->valor.matricula << ", Assunto: " << auxiliar->valor.assunto;
            auxiliar = auxiliar->proximo;
        }
    }

    NoLivro* buscar(int matricula) {
        NoLivro *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoLivro* noParaRemover = buscar(matricula);
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

struct Livros
{
    ListaLivro tabela[TAMANHO_HASH_LIVRO];

    int funcaoHash(string assunto)
    {
        int hash = 0;
        for (char c : assunto) {
            hash = (hash * 31 + c);
        }
        return abs(hash % TAMANHO_HASH_LIVRO);
    }

    Livro criar(int autor, int editora, string assunto, int tipo, bool alugado, string data_alugel) {
        Livro novoLivro;
        novoLivro.autor = autor;
        novoLivro.editora = editora;
        novoLivro.assunto = assunto;
        novoLivro.tipo = tipo;
        novoLivro.alugado = alugado;
        novoLivro.data_alugel = data_alugel;
        novoLivro.matricula = rand() % 100000;

        int indice = funcaoHash(novoLivro.assunto);
        tabela[indice].adicionar(novoLivro);
        return novoLivro;
    }

    bool listar() {
        cout << "\n===== LISTA DE LIVROS =====\n";
        for (int i = 0; i < TAMANHO_HASH_LIVRO; i++) {
            cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            cout << endl;
        }
        cout << "=============================\n";
        return true;
    }

    bool editar(int matricula, int novoAutor, int novaEditora, string novoAssunto, int novoTipo, bool novoAlugado, string novaData) {
        for (int i = 0; i < TAMANHO_HASH_LIVRO; i++) {
            NoLivro* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Livro livroParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                if (novoAutor != 0) {
                    livroParaAtualizar.autor = novoAutor;
                }
                if (novaEditora != 0) {
                    livroParaAtualizar.editora = novaEditora;
                }
                if (novoTipo != 0) {
                    livroParaAtualizar.tipo = novoTipo;
                }

                if (!novoAssunto.empty()) {
                    livroParaAtualizar.assunto = novoAssunto;
                }
                if (!novaData.empty()) {
                    livroParaAtualizar.data_alugel = novaData;
                }
                
                livroParaAtualizar.alugado = novoAlugado;
                
                int novoIndice = funcaoHash(livroParaAtualizar.assunto);
                tabela[novoIndice].adicionar(livroParaAtualizar);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    Livro pesquisar(string campo, T valor) {
        for (int i = 0; i < TAMANHO_HASH_LIVRO; i++) {
            NoLivro* aux = tabela[i].inicio;
            while (aux != nullptr) {
                if (campo == "matricula") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.matricula == valor) return aux->valor;
                    }
                } else if (campo == "autor") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.autor == valor) return aux->valor;
                    }
                } else if (campo == "editora") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.editora == valor) return aux->valor;
                    }
                } else if (campo == "assunto") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.assunto == valor) return aux->valor;
                    }
                } else if (campo == "tipo") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.tipo == valor) return aux->valor;
                    }
                } else if (campo == "alugado") {
                    if constexpr (is_same_v<T, bool>) {
                        if (aux->valor.alugado == valor) return aux->valor;
                    }
                }
                aux = aux->proximo;
            }
        }

        // Se o loop terminar e nada for encontrado, retorna um Livro "vazio"
        Livro livroNaoEncontrado;
        livroNaoEncontrado.matricula = -1;
        return livroNaoEncontrado;
    }
};

#endif
