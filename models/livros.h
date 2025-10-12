#ifndef LIVROS_H
#define LIVROS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef TAMANHO_HASH_LIVRO
#define TAMANHO_HASH_LIVRO 7
#endif

struct Livro
{
    int matricula;
    int autor;
    int editora;
    std::string assunto;
    std::string tipo;
    bool alugado;
    std::string data_alugel;
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
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Assunto: " << auxiliar->valor.assunto;
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

    int funcaoHash(std::string assunto)
    {
        int hash = 0;
        for (char c : assunto) {
            hash = (hash * 31 + c);
        }
        return std::abs(hash % TAMANHO_HASH_LIVRO);
    }

    Livro criar(int autor, int editora, std::string assunto, std::string tipo, bool alugado, std::string data_alugel) {
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

    void listar() {
        std::cout << "\n===== LISTA DE LIVROS =====\n";
        for (int i = 0; i < TAMANHO_HASH_LIVRO; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "=============================\n";
    }

    bool editar(int matricula, int novoAutor, int novaEditora, std::string novoAssunto, std::string novoTipo, bool novoAlugado, std::string novaData) {
        for (int i = 0; i < TAMANHO_HASH_LIVRO; i++) {
            NoLivro* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Livro livroParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                livroParaAtualizar.autor = novoAutor;
                livroParaAtualizar.editora = novaEditora;
                livroParaAtualizar.assunto = novoAssunto;
                livroParaAtualizar.tipo = novoTipo;
                livroParaAtualizar.alugado = novoAlugado;
                livroParaAtualizar.data_alugel = novaData;
                
                int novoIndice = funcaoHash(livroParaAtualizar.assunto);
                tabela[novoIndice].adicionar(livroParaAtualizar);
                return true;
            }
        }
        return false;
    }
};

#endif
