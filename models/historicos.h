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

    NoHistorico* buscar(int matricula) {
        NoHistorico *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoHistorico* noParaRemover = buscar(matricula);
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

struct Historicos
{
    ListaHistorico tabela[TAMANHO_HASH_HISTORICO];

    int funcaoHash(int usuario)
    {
        return std::abs(usuario % TAMANHO_HASH_HISTORICO);
    }

    Historico criar(int livro, int usuario, bool alugado, std::string data_alugel) {
        Historico novoHistorico;
        novoHistorico.livro = livro;
        novoHistorico.usuario = usuario;
        novoHistorico.alugado = alugado;
        novoHistorico.data_alugel = data_alugel;
        novoHistorico.matricula = rand() % 100000;

        int indice = funcaoHash(novoHistorico.usuario);
        tabela[indice].adicionar(novoHistorico);
        return novoHistorico;
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

    bool editar(int matricula, int novoLivro, int novoUsuario, bool novoAlugado, std::string novaData) {
        for (int i = 0; i < TAMANHO_HASH_HISTORICO; i++) {
            NoHistorico* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Historico historicoParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                historicoParaAtualizar.livro = novoLivro;
                historicoParaAtualizar.usuario = novoUsuario;
                historicoParaAtualizar.alugado = novoAlugado;
                historicoParaAtualizar.data_alugel = novaData;
                
                int novoIndice = funcaoHash(historicoParaAtualizar.usuario);
                tabela[novoIndice].adicionar(historicoParaAtualizar);
                return true;
            }
        }
        return false;
    }
};

#endif
