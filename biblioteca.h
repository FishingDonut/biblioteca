#include <iostream>
#include <string>
using namespace std;
#include "models/autores.h"
#include "models/editoras.h"
#include "models/livros.h"
#include "models/usuarios.h"

template <typename T>
T ImprimeRetorna(string imprime) {
    T retorna;
    cout << imprime << endl;
    if constexpr (is_same<T, string>::value) {
        if (cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        getline(cin, retorna);
    } else {
        cin >> retorna;
    }
    
    return retorna;
};

int ImprimeRetornaMatricula(){
    int maricula = 0;
    do{
        maricula = ImprimeRetorna<int>("Digite o valor da matricula:");

        if(maricula <= 0 || maricula > 99999){
            cout << "Valor digitado invalido para matricula, digite novamente \n";
        }
    } while (maricula >= 0 && maricula <= 99999);
    
    return maricula;
}

void mostrarInformacoes() {
    cout << "\n--- 🃏 Regras do Truco Mineiro 🃏 ---\n\n";
    
    cout << "O objetivo do jogo é ser a primeira dupla ou jogador a atingir 12 pontos.\n\n";

    cout << "🎴 BARALHO E CARTAS:\n";
    cout << " - Cartas em Jogo: Utiliza-se um baralho normal, retirando as cartas 8, 9 e 10.\n\n";

    cout << " ✨ MANILHAS (As cartas mais fortes):\n";
    cout << " - A ordem de força das manilhas é fixa, sendo sempre a seguinte:\n";
    cout << "   1º (Maior): 4 de Paus (Zap) ♣️\n";
    cout << "   2º: 7 de Copas ♥️\n";
    cout << "   3º: Ás de Espadas (Espadilha) ♠️\n";
    cout << "   4º: 7 de Ouros (Pica-fumo) ♦️\n\n";

    cout << " 💪 ORDEM DE FORÇA (Cartas Comuns):\n";
    cout << " - Para as demais cartas, a ordem de força é:\n";
    cout << "   3 > 2 > A > K > J > Q > 7 > 6 > 5 > 4\n\n";

    cout << "🎮 JOGABILIDADE E PONTUAÇÃO:\n";
    cout << " - Jogadores: Pode ser jogado em 2 (1x1) ou 4 jogadores (em duplas 2x2).\n";
    cout << " - Cartas por Mão: Cada jogador recebe 3 cartas no início de cada mão.\n";
    cout << " - Rodadas: Uma \"mão\" é disputada em até 3 rodadas. Quem joga a carta mais forte vence a rodada.\n";
    cout << " - Vencedor da Mão: A dupla que vencer duas rodadas leva os pontos da mão.\n";
    cout << " - Pontuação: Uma mão inicia valendo 2 pontos. A primeira equipe a fazer 12 pontos vence o jogo.\n\n";
    
    cout << "🤝 EMPATES:\n";
    cout << " - Se uma rodada terminar empatada, a rodada seguinte decide o vencedor da mão.\n";
    cout << " - Se todas as três rodadas empatarem, ninguém ganha os pontos e uma nova mão é iniciada.\n\n";
    
    cout << "Pressione qualquer tecla para voltar ao menu principal...\n";
    cin.ignore();
    cout<< cin.get();
    cout<<"\033c";
};

bool libs(){
    int opcoesLib = 0;
    // Usuarios usuarios;
    // Livros livros;
    // Editoras editoras;
    // Autores autores;
    
    // usuarios.inicializar();
    // livros.inicializar();
    // editoras.inicializar();
    // autores.inicializar();

    do{
        opcoesLib = ImprimeRetorna<int>("Selecione oque deseja fazer: \n 1 • Listar \n 2 • Gerenciar(Criar/Editar) \n 3 • Voltar");
        switch (opcoesLib){
            case 1:
                /* Executa a Listagem da bibiloteca*/
                // if(listagem(usuarios,livros,editoras,autores)){
                if(listagem()){
                    cout << "Você retornou para o menu da bibiloteca, precisone qualquer tecla para prosseguir:\n";
                    cin.ignore();
                    cout<< cin.get();
                    cout<<"\033c";
                    opcoesLib = 0;
                }
                break;
            case 2:
                /* Executa a gerencia*/
                if(gerenciar()){
                // if(gerenciar(usuarios,livros,editoras,autores)){
                    cout << "Você retornou para o menu da bibiloteca, precisone qualquer tecla para prosseguir:\n";
                    cin.ignore();
                    cout<< cin.get();
                    cout<<"\033c";
                    opcoesLib = 0;
                }
            break;
            default:
                opcoesLib = ImprimeRetorna<int>("Você ira voltar ao menu inicial, todos os dados serão perdidos digite 1 se realmente deseja continuar:");
                if(opcoesLib == 1){
                    opcoesLib = 3;
                }else{
                    opcoesLib = 0;
                }
            break;
        }

    } while (opcoesLib != 3);

    return true;
};

// bool listagem(Usuarios &usuarios,Livros &livros,Editoras &editoras,Autores &autores){
bool listagem(){
    int opcoesList = 0;
    do{
        opcoesList = ImprimeRetorna<int>("Selecione oque deseja Listar/Pesquisar: \n 1 • Livros/Revistas \n 2 • Autores \n 3 • Editora \n 4 • Usuarios \n 5 • Voltar");
        switch (opcoesList){
            case 1:
                /* Listagem/Pesquisa de Livros/Revistas*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar os Livros/Revistas:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Autor \n 3 • Editora \n 4 • Assunto \n 5 • Alugado");
                    switch (pesquisa){
                        case 1:
                            // livros.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        case 2:
                            // livros.pesquisaLista("autor",ImprimeRetorna<string>("Digite o autor:"));
                        break;
                        case 3:
                            // livros.pesquisaLista("editora",ImprimeRetorna<string>("Digite a editora:"));
                        break;
                        case 4:
                            // livros.pesquisaLista("assunto",ImprimeRetorna<string>("Digite o assunto:"));
                        break;
                        default:
                            // livros.pesquisaLista("alugado",true);
                        break;
                    }
                }else{
                    // livros.listar();
                }
            break;
            case 2:
                /* Listagem/Pesquisa de Autores*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar os Autores:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n");
                    switch (pesquisa){
                        case 1:
                            // autores.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        default:
                            // autores.pesquisaLista("nome",ImprimeRetorna<string>("Digite o nome do autor:"));
                        break;
                    }
                }else{
                    //lista
                    // autores.listar();
                }
            break;
            case 3:
                /* Listagem/Pesquisa de Editora*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar as Editora:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n");
                    switch (pesquisa){
                        case 1:
                            // editoras.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        default:
                            // editoras.pesquisaLista("nome",ImprimeRetorna<string>("Digite o nome do autor:"));
                        break;
                    }
                }else{
                    //lista
                    // editoras.listar();
                }
            break;
            case 4:
                /* Listagem/Pesquisa de Usuarios*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar os Usuarios:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n 3 • Data de Alugel \n 4 • Tem livro alugado");
                    switch (pesquisa){
                        case 1:
                            // usuarios.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        case 2:
                            // usuarios.pesquisaLista("autor",ImprimeRetorna<string>("Digite o autor:"));
                        break;
                        case 3:
                            // usuarios.pesquisaLista("editora",ImprimeRetorna<string>("Digite a editora:"));
                        break;
                        case 4:
                            // usuarios.pesquisaLista("data_alugel",ImprimeRetorna<string>("Digite a data de alugel (DD/MM/YYYY):"));
                        break;
                        default:
                            // usuarios.pesquisaLista("alugado",true);
                        break;
                    }
                }else{
                    //lista
                    // usuarios.listar();
                }
            break;
            default:
                cout << "Você ira retornar para o menu da bibiloteca:\n";
                cin.ignore();
                cout<< cin.get();
                cout<<"\033c";
                opcoesList = 5;
            break;
        }

        cout << "Você ira retornar para o menu da bibiloteca, precisone qualquer tecla para prosseguir:\n";
        cin.ignore();
        cout<< cin.get();
        cout<<"\033c";
        opcoesList = 5;
    } while (opcoesList != 5);


}

// bool gerenciar(Usuarios &usuarios,Livros &livros,Editoras &editoras,Autores &autores){
bool gerenciar(){
    int opcoesGen = 0;
    do{
        opcoesGen = ImprimeRetorna<int>("Selecione oque deseja gerenciar: \n 1 • Livros/Revistas \n 2 • Autores \n 3 • Editora \n 4 • Usuarios \n 5 • Voltar");
        int matricula = ImprimeRetorna<int>("Se deseja editar digite a matricula, caso queira adicionar um novo digite 0:");
        switch (opcoesGen){
            case 1:
                /* Listagem/Pesquisa de Livros/Revistas*/
                if( matricula == 0){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Autor \n 3 • Editora \n 4 • Assunto \n 5 • Alugado");
                    switch (pesquisa){
                        case 1:
                            // livros.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        case 2:
                            // livros.pesquisaLista("autor",ImprimeRetorna<string>("Digite o autor:"));
                        break;
                        case 3:
                            // livros.pesquisaLista("editora",ImprimeRetorna<string>("Digite a editora:"));
                        break;
                        case 4:
                            // livros.pesquisaLista("assunto",ImprimeRetorna<string>("Digite o assunto:"));
                        break;
                        default:
                            // livros.pesquisaLista("alugado",true);
                        break;
                    }
                }else{
                    // livros.listar();
                }
            break;
            case 2:
                /* Listagem/Pesquisa de Autores*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar os Autores:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n");
                    switch (pesquisa){
                        case 1:
                            // autores.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        default:
                            // autores.pesquisaLista("nome",ImprimeRetorna<string>("Digite o nome do autor:"));
                        break;
                    }
                }else{
                    //lista
                    // autores.listar();
                }
            break;
            case 3:
                /* Listagem/Pesquisa de Editora*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar as Editora:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n");
                    switch (pesquisa){
                        case 1:
                            // editoras.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        default:
                            // editoras.pesquisaLista("nome",ImprimeRetorna<string>("Digite o nome do autor:"));
                        break;
                    }
                }else{
                    //lista
                    // editoras.listar();
                }
            break;
            case 4:
                /* Listagem/Pesquisa de Usuarios*/
                if(ImprimeRetorna<int>("Se deseja pesquisar digite 1 qualquer outro valor irá listar os Usuarios:") == 1){
                    //faz a solicitacao do que pesquisar
                    int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n 3 • Data de Alugel \n 4 • Tem livro alugado");
                    switch (pesquisa){
                        case 1:
                            // usuarios.pesquisaLista("matricula",ImprimeRetornaMatricula());
                        break;
                        case 2:
                            // usuarios.pesquisaLista("autor",ImprimeRetorna<string>("Digite o autor:"));
                        break;
                        case 3:
                            // usuarios.pesquisaLista("editora",ImprimeRetorna<string>("Digite a editora:"));
                        break;
                        case 4:
                            // usuarios.pesquisaLista("data_alugel",ImprimeRetorna<string>("Digite a data de alugel (DD/MM/YYYY):"));
                        break;
                        default:
                            // usuarios.pesquisaLista("alugado",true);
                        break;
                    }
                }else{
                    //lista
                    // usuarios.listar();
                }
            break;
            default:
                cout << "Você ira retornar para o menu da bibiloteca:\n";
                cin.ignore();
                cout<< cin.get();
                cout<<"\033c";
                opcoesList = 5;
            break;
        }

        cout << "Você ira retornar para o menu da bibiloteca, precisone qualquer tecla para prosseguir:\n";
        cin.ignore();
        cout<< cin.get();
        cout<<"\033c";
        opcoesList = 5;
    } while (opcoesList != 5);
}