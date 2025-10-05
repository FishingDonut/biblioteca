// feito por:
// Daniel Uesler de Brito (daniel.8071330@edu.univali.br) - 8071330
// Wallacy Alvarenga (wallacyalvarenga@univali.br) - 6916694
// Mude o valor abaixo para alterar o tamanho da lista hashing
#define TAM 5
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "biblioteca.h"

int main() {
    SetConsoleOutputCP(65001);
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int opcoes = 0;
    do{
        cout << "\033c";
        // cout << "Selecione uma das opções a seguir: \n 1 • Jogar ▷\n 2 • Sobre ⁉️\n 3 • Jogadores \n 4 • Fim 𝕏\n";
        cin >> opcoes;
        system("cls");
        //Listagem 
        //Cadastro de livros e revistas, com edicao


    } while (opcoes != 4);

    return 0;
}