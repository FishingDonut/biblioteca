#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <type_traits>
#include "historicos.h"
using namespace std;

#ifndef TAMANHO_HASH_USUARIO
#define TAMANHO_HASH_USUARIO 7
#endif

struct Usuario
{
    int matricula;
    int livro_alugado;
    string nome;
    ListaHistorico historico;
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
            cout << " -> Matricula: " << auxiliar->valor.matricula << ", Nome: " << auxiliar->valor.nome;
            auxiliar = auxiliar->proximo;
        }
    }

    NoUsuario* buscar(int matricula) {
        NoUsuario *auxiliar = inicio;
        while (auxiliar != nullptr) {
            if (auxiliar->valor.matricula == matricula) {
                return auxiliar;
            }
            auxiliar = auxiliar->proximo;
        }
        return nullptr;
    }

    bool remover(int matricula) {
        NoUsuario* noParaRemover = buscar(matricula);
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

struct Usuarios
{
    ListaUsuario tabela[TAMANHO_HASH_USUARIO];

    int funcaoHash(string nome)
    {
        int hash = 0;
        for (char c : nome) {
            hash = (hash * 31 + c);
        }
        return abs(hash % TAMANHO_HASH_USUARIO);
    }

    Usuario criar(string nome) {
        Usuario novoUsuario;
        novoUsuario.nome = nome;
        novoUsuario.matricula = rand() % 100000;

        int indice = funcaoHash(novoUsuario.nome);
        tabela[indice].adicionar(novoUsuario);
        return novoUsuario;
    }

    bool listar() {
        cout << "\n===== LISTA DE USUARIOS =====\n";
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            cout << endl;
        }
        cout << "===============================\n";

        return true;
    }

    bool editar(int matricula, string novo_nome,int livro_alugado) {
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            NoUsuario* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Usuario usuarioParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                if (!novo_nome.empty()) {
                    usuarioParaAtualizar.nome = novo_nome;
                }

                if (livro_alugado != 0) {
                    usuarioParaAtualizar.livro_alugado = livro_alugado;
                }
                
                int novoIndice = funcaoHash(usuarioParaAtualizar.nome);
                tabela[novoIndice].adicionar(usuarioParaAtualizar);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    Usuario pesquisar(string campo, T valor) {
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            NoUsuario* aux = tabela[i].inicio;
            while (aux != nullptr) {
                if (campo == "matricula") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.matricula == valor) return aux->valor;
                    }
                } else if (campo == "nome") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.nome == valor) return aux->valor;
                    }
                } else if (campo == "livro_alugado") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.livro_alugado == valor) return aux->valor;
                    }
                }
                aux = aux->proximo;
            }
        }

        // Se o loop terminar e nada for encontrado, retorna um Usuario "vazio"
        Usuario usuarioNaoEncontrado;
        usuarioNaoEncontrado.matricula = -1;
        return usuarioNaoEncontrado;
    }

    template <typename T>
    ListaUsuario pesquisaLista(string campo, T valor) {
        ListaUsuario resultados;
        for (int i = 0; i < TAMANHO_HASH_USUARIO; i++) {
            NoUsuario* aux = tabela[i].inicio;
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
                } else if (campo == "livro_alugado") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.livro_alugado == valor) {
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
