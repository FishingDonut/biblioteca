#ifndef REVISTAS_H
#define REVISTAS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef TAMANHO_HASH_REVISTA
#define TAMANHO_HASH_REVISTA 7
#endif

struct Revista
{
    int matricula;
    int editora;
    std::string assunto;
    std::string tipo;
    bool alugado;
    std::string data_alugel;
};

struct NoRevista {
    Revista valor;
    NoRevista* proximo;
    NoRevista* anterior;

    explicit NoRevista(const Revista& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaRevista {
    NoRevista *inicio = nullptr;
    NoRevista *fim = nullptr;

    void adicionar(Revista valor) {
        NoRevista *novoNo = new NoRevista(valor);
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
        NoRevista *auxiliar = inicio;
        while (auxiliar != nullptr) {
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Assunto: " << auxiliar->valor.assunto;
            auxiliar = auxiliar->proximo;
        }
    }

    NoRevista* buscar(int matricula) {
        NoRevista *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoRevista* noParaRemover = buscar(matricula);
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

struct Revistas
{
    ListaRevista tabela[TAMANHO_HASH_REVISTA];

    int funcaoHash(std::string assunto)
    {
        int hash = 0;
        for (char c : assunto) {
            hash = (hash * 31 + c);
        }
        return std::abs(hash % TAMANHO_HASH_REVISTA);
    }

    Revista criar(int editora, std::string assunto, std::string tipo, bool alugado, std::string data_alugel) {
        Revista novaRevista;
        novaRevista.editora = editora;
        novaRevista.assunto = assunto;
        novaRevista.tipo = tipo;
        novaRevista.alugado = alugado;
        novaRevista.data_alugel = data_alugel;
        novaRevista.matricula = rand() % 100000;

        int indice = funcaoHash(novaRevista.assunto);
        tabela[indice].adicionar(novaRevista);
        return novaRevista;
    }

    void listar() {
        std::cout << "\n===== LISTA DE REVISTAS =====\n";
        for (int i = 0; i < TAMANHO_HASH_REVISTA; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "=============================\n";
    }

    bool editar(int matricula, int novaEditora, std::string novoAssunto, std::string novoTipo, bool novoAlugado, std::string novaData) {
        for (int i = 0; i < TAMANHO_HASH_REVISTA; i++) {
            NoRevista* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Revista revistaParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                revistaParaAtualizar.editora = novaEditora;
                revistaParaAtualizar.assunto = novoAssunto;
                revistaParaAtualizar.tipo = novoTipo;
                revistaParaAtualizar.alugado = novoAlugado;
                revistaParaAtualizar.data_alugel = novaData;
                
                int novoIndice = funcaoHash(revistaParaAtualizar.assunto);
                tabela[novoIndice].adicionar(revistaParaAtualizar);
                return true;
            }
        }
        return false;
    }
};

#endif
