#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef TAMANHO_HASH_USUARIO
#define TAMANHO_HASH_USUARIO 7
#endif

struct Usuario
{
    int matricula;
    int livro_alugado;
    std::string data_alugel;
    std::string nome;
};

struct NoUsuario {
    Usuario valor;
    NoUsuario* proximo;
    NoUsuario* anterior;

    explicit NoUsuario(const Usuario& val) : valor(val), proximo(nullptr), anterior(nullptr) {}
};

struct ListaUsuario {
    NoUsuario *inicio = nullptr;
    NoUsuario *fim = nullptr;

    void adicionar(Usuario valor) {
        NoUsuario *novoNo = new NoUsuario(valor);
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
        NoUsuario *auxiliar = inicio;
        while (auxiliar != nullptr) {
            std::cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
            auxiliar = auxiliar->proximo;
        }
    }
};

struct Usuarios
{
    ListaUsuario tabela[TAMANHO_HASH_USUARIO];

    int funcaoHash(std::string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return std::abs(hash % TAMANHO_HASH_USUARIO);
    }

    bool criar(int livro_alugado, std::string data_alugel, std::string nome) {
        Usuario novoUsuario;
        novoUsuario.livro_alugado = livro_alugado;
        novoUsuario.data_alugel = data_alugel;
        novoUsuario.nome = nome;
        novoUsuario.matricula = rand() % 100000;

        int indice = funcaoHash(novoUsuario.nome);
        tabela[indice].adicionar(novoUsuario);
        return true;
    }

    void listar() {
        std::cout << "\n===== LISTA DE USUARIOS =====\n";
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            std::cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            std::cout << std::endl;
        }
        std::cout << "===============================\n";
    }

    bool editar(int matricula, int livro_alugado, std::string data_alugel, std::string nome) {
        return false;
    }
};

#endif