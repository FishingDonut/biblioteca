#ifndef HISTORICOS_H
#define HISTORICOS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef TAMANHO_HASH_HISTORICO
#define TAMANHO_HASH_HISTORICO 7
#endif

struct Historico
{
    int matricula;
    int livro;
    int usuario;
    bool alugado;
    std::string data_alugel;
};

struct NoHistorico {
    Historico valor;
    NoHistorico* proximo;
    NoHistorico* anterior;

    explicit NoHistorico(const Historico& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaHistorico {
    NoHistorico *inicio = nullptr;
    NoHistorico *fim = nullptr;

    void adicionar(Historico valor) {
        NoHistorico *novoNo = new NoHistorico(valor);
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
        NoHistorico *auxiliar = inicio;
        while (auxiliar != nullptr) {
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Usuario: " << auxiliar->valor.usuario << ", Livro: " << auxiliar->valor.livro;
            auxiliar = auxiliar->proximo;
        }
    }
};

struct Historicos
{
    ListaHistorico tabela[TAMANHO_HASH_HISTORICO];

    int funcaoHash(int usuario)
    {
        return std::abs(usuario % TAMANHO_HASH_HISTORICO);
    }

    bool criar(int livro, int usuario, bool alugado, std::string data_alugel) {
        Historico novoHistorico;
        novoHistorico.livro = livro;
        novoHistorico.usuario = usuario;
        novoHistorico.alugado = alugado;
        novoHistorico.data_alugel = data_alugel;
        novoHistorico.matricula = rand() % 100000;

        int indice = funcaoHash(novoHistorico.usuario);
        tabela[indice].adicionar(novoHistorico);
        return true;
    }

    void listar() {
        std::cout << "\n===== LISTA DE HISTORICOS =====\n";
        for (int i = 0; i < TAMANHO_HASH_HISTORICO; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "=================================\n";
    }

    bool editar(int matricula, int livro, int usuario, bool alugado, std::string data_alugel) {
        return false;
    }
};

#endif