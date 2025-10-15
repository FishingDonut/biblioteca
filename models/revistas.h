#ifndef REVISTAS_H
#define REVISTAS_H

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <type_traits>
using namespace std;

#ifndef TAM
#define TAM 7
#endif

struct Revista
{
    int matricula;
    int editora;
    string assunto;
    string tipo;
    bool alugado;
    string data_alugel;
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
            cout << " -> Matricula: " << auxiliar->valor.matricula << ", Assunto: " << auxiliar->valor.assunto;
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
    ListaRevista tabela[TAM];

    int funcaoHash(string assunto)
    {
        int hash = 0;
        for (char c : assunto) {
            hash = (hash * 31 + c);
        }
        return abs(hash % TAM);
    }

    Revista criar(int editora, string assunto, string tipo, bool alugado, string data_alugel) {
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

    bool listar() {
        cout << "\n===== LISTA DE REVISTAS =====\n";
        for (int i = 0; i < TAM; i++) {
            cout << "Indice [" << i << "]:";
            tabela[i].mostrar();
            cout << endl;
        }
        cout << "=============================\n";
        return true;
    }

    bool editar(int matricula, int novaEditora, string novoAssunto, string novoTipo, bool novoAlugado, string novaData) {
        for (int i = 0; i < TAM; i++) {
            NoRevista* no = tabela[i].buscar(matricula);
            if (no != nullptr) {
                Revista revistaParaAtualizar = no->valor;
                tabela[i].remover(matricula);

                if (novaEditora != 0) {
                    revistaParaAtualizar.editora = novaEditora;
                }

                if (!novoAssunto.empty()) {
                    revistaParaAtualizar.assunto = novoAssunto;
                }

                if (novoAssunto.empty()) {
                    revistaParaAtualizar.tipo = novoTipo;
                }

                revistaParaAtualizar.alugado = novoAlugado;

                if (!novaData.empty()) {
                    revistaParaAtualizar.data_alugel = novaData;
                }
                
                int novoIndice = funcaoHash(revistaParaAtualizar.assunto);
                tabela[novoIndice].adicionar(revistaParaAtualizar);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    Revista pesquisar(string campo, T valor) {
        for (int i = 0; i < TAM; i++) {
            NoRevista* aux = tabela[i].inicio;
            while (aux != nullptr) {
                if (campo == "matricula") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.matricula == valor) return aux->valor;
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
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.tipo == valor) return aux->valor;
                    }
                } else if (campo == "alugado") {
                    if constexpr (is_same_v<T, bool>) {
                        if (aux->valor.alugado == valor) return aux->valor;
                    }
                } else if (campo == "data_alugel") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.data_alugel == valor) return aux->valor;
                    }
                }
                aux = aux->proximo;
            }
        }

        // Se o loop terminar e nada for encontrado, retorna uma Revista "vazia"
        Revista revistaNaoEncontrada;
        revistaNaoEncontrada.matricula = -1;
        return revistaNaoEncontrada;
    }

    template <typename T>
    ListaRevista pesquisaLista(string campo, T valor) {
        ListaRevista resultados;
        for (int i = 0; i < TAM; i++) {
            NoRevista* aux = tabela[i].inicio;
            while (aux != nullptr) {
                if (campo == "matricula") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.matricula == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                } else if (campo == "editora") {
                    if constexpr (is_same_v<T, int>) {
                        if (aux->valor.editora == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                } else if (campo == "assunto") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.assunto == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                } else if (campo == "tipo") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.tipo == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                } else if (campo == "alugado") {
                    if constexpr (is_same_v<T, bool>) {
                        if (aux->valor.alugado == valor) {
                            resultados.adicionar(aux->valor);
                        }
                    }
                } else if (campo == "data_alugel") {
                    if constexpr (is_same_v<T, string>) {
                        if (aux->valor.data_alugel == valor) {
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
