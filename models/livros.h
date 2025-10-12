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

    bool criar(int autor, int editora, std::string assunto, std::string tipo, bool alugado, std::string data_alugel) {
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
        return true;
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

    bool editar(int matricula, int autor, int editora, std::string assunto, std::string tipo, bool alugado, std::string data_alugel) {
        return false;
    }
};

#endif