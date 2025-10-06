// feito por:
// Daniel Uesler de Brito (daniel.8071330@edu.univali.br) - 8071330
// Wallacy Alvarenga (wallacyalvarenga@univali.br) - 6916694
// Mude o valor abaixo para alterar o tamanho da lista hashing
#define TAM 5
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
#include "biblioteca.h"

int main() {
    SetConsoleOutputCP(65001);
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int opcoes = 0;




//  Cadastro de livros e revistas, com possiblidade de alteração (não precisa remover);
//  Cada livro pode ter apenas um autor;
//  Pesquisar qualquer item armazenado por matrícula, título, autor, editora ou
// assunto;
//  Deve haver um cadastro de autores (dos livros) e editoras (livros e revistas), com
// a possibilidade de incluir e alterar;
//  Deve haver um cadastro de usuário que podem retirar livros para devolução após
// 7 dias;
//  Listagens necessárias (relatórios em tela):
// o Livros/Revistas de um autor ou editora
// o Livros/Revistas de um assunto
// o Livros/Revistas em atraso de devolução
// o Histórico de retiradas de um usuário 








    do{
        cout << "\033c";
        opcoes = ImprimeRetorna<int>("Selecione uma das opções a seguir: \n 1 • Iniciar ▷\n 2 • Sobre ⁉️ \n 3 • Fim 𝕏\n");
        system("cls");
        
        switch (opcoes){
            case 1:
                /* Executa a bibiloteca*/
                if(libs()){
                    cout << "Você retornou para o menu inicial, precisone qualquer tecla para prosseguir:\n";
                    cin.ignore();
                    cout<< cin.get();
                    cout<<"\033c";
                    opcoes = 0;
                }
                break;
            case 2:
                /* Sobre */
                mostrarInformacoes();
            break;
            default:
                cout << "A aplicação será encerrada, até a proxima :)\n";
                opcoes = 3;
            break;
        }

    } while (opcoes != 3);

    return 0;
}