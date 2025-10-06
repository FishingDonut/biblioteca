#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "models/autores.h"
#include "models/editoras.h"
#include "models/livros.h"
#include "models/usuarios.h"

string obterDataFormatada(int diasParaSubtrair = 0) {
    time_t tempoAtual = time(nullptr);
    time_t segundosParaSubtrair = diasParaSubtrair * 86400;
    time_t tempoAlvo = tempoAtual - segundosParaSubtrair;
    tm* tempoLocal = localtime(&tempoAlvo);
    char buffer[11];
    // Formata a data no formato "dd/mm/YYYY"
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", tempoLocal);
    // Retorna a data formatada como uma string
    return string(buffer);
}

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

int ImprimeRetornaMatricula(string texto = "Digite o valor da matricula:"){
    int maricula = 0;
    do{
        maricula = ImprimeRetorna<int>(texto);

        if(maricula <= 0 || maricula > 99999){
            cout << "Valor digitado invalido para matricula, digite novamente \n";
        }
    } while (maricula >= 0 && maricula <= 99999);
    
    return maricula;
}

void mostrarInformacoes() {
    cout << "\n\n--- ⭐ SOBRE O PROJETO ⭐ ---\n\n";

    cout << "🎓 DISCIPLINA:\n";
    cout << " - Estrutura de Dados\n\n";

    cout << "👨‍🏫 PROFESSOR RESPONSÁVEL:\n";
    cout << " - Marcos Carrard\n\n";

    cout << "👥 INTEGRANTES DO GRUPO:\n";
    cout << " - Daniel Uesler de Brito\n";
    cout << " - Wallacy Alvarenga\n\n"; // Adicione mais linhas conforme necessário

    cout << "-----------------------------------------------------\n";
    cout << "--- 📚 Sistema de Biblioteca com Hashing 📚 ---\n";
    cout << "-----------------------------------------------------\n\n";

    cout << "Bem-vindo! Este sistema foi desenvolvido como um projeto para a disciplina de Estrutura de Dados,\n";
    cout << "com o objetivo de gerenciar de forma eficiente o acervo e os empréstimos de uma biblioteca,\n";
    cout << "utilizando tabelas de hash para otimizar as operações de busca e inserção de dados.\n\n";

    cout << "--- ⚙️ FUNCIONALIDADES IMPLEMENTADAS ⚙️ ---\n\n";

    cout << "O sistema permite realizar o controle completo de empréstimos e do acervo, dividido nos seguintes módulos:\n\n";

    cout << "   📘 Livros e Revistas\n";
    cout << "   ✍️ Autores\n";
    cout << "   🏢 Editoras\n";
    cout << "   👥 Usuários\n\n";

    cout << "Para cada um dos módulos acima, as seguintes operações estão disponíveis:\n\n";
    cout << "   ✨ Inserir: Cadastra um novo registro no sistema.\n";
    cout << "   📋 Listar: Exibe todos os registros cadastrados no módulo.\n";
    cout << "   🔎 Pesquisar: Busca por um registro específico utilizando sua chave.\n";
    cout << "   ✏️ Editar: Altera os dados de um registro já existente.\n\n";

    cout << "Além do gerenciamento dos dados, as operações centrais da biblioteca são:\n\n";
    cout << "   🚀 Alugar um Livro/Revista: Realiza o empréstimo de um item do acervo para um usuário.\n";
    cout << "   ✅ Devolver um Livro/Revista: Registra a devolução de um item, tornando-o disponível novamente.\n\n";
    
    cout << "Pressione qualquer tecla para voltar ao menu principal...\n";
    cin.ignore();
    cout<< cin.get();
    cout<<"\033c";
};

bool libs(){
    int opcoesLib = 0;
    int opcoesInter = 0;
    // Usuarios usuarios;
    // Livros livros;
    // Editoras editoras;
    // Autores autores;
    
    // usuarios.inicializar();
    // livros.inicializar();
    // editoras.inicializar();
    // autores.inicializar();

    string txtAutor = "Informe o nome do autor:";
    string txtEditora = "Informe o nome da editora:";
    string txtAssunto = "Informe o assunto:";
    string txtTipo = "Informe o tipo (Livro - 1, Revista - 2):";
    string txtNome = "Informe o nome:";
    string autor;
    string editora;
    string assunto;
    string nome;
    int matricula;
    int matricula2;

    do{
        opcoesLib = ImprimeRetorna<int>("Selecione oque deseja gerenciar: \n 1 • Livros/Revistas \n 2 • Autores \n 3 • Editora \n 4 • Usuarios \n 5 • Voltar");
        switch (opcoesLib){
            //Livros/Revistas
            case 1:
                //LPCE
                do{
                    opcoesInter = ImprimeRetorna<int>("Selecione oque deseja interagir: \n 1 • Listar \n 2 • Pesquisar \n 3 • Criar \n 4 • Editar \n 5 • Aluguel/Devolução \n 6• Voltar");
                    switch (opcoesInter){
                        //Listar
                        case 1:
                            // if(livros.listar()){
                                cout << "Você ira retornar para o menu de interagir, precisone qualquer tecla para prosseguir:\n";
                                cin.ignore();
                                cout<< cin.get();
                                cout<<"\033c";
                                opcoesInter = 0;
                            // }
                        break;
                        //Pesquisar
                        case 2:
                            /* Pesquisa de Autores*/
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
                            cout << "Você ira retornar para o menu de interagir, precisone qualquer tecla para prosseguir:\n";
                            cin.ignore();
                            cout<< cin.get();
                            cout<<"\033c";
                            opcoesInter = 0;
                        break;
                        //Criar
                        case 3:
                            autor = ImprimeRetorna<string>(txtAutor);
                            editora = ImprimeRetorna<string>(txtEditora);
                            assunto = ImprimeRetorna<string>(txtAssunto);
                            int tipo = ImprimeRetorna<int>(txtTipo);
                            //livros.criar(autor,editora,assunto,tipo,editoras,autores);
                        break;
                        //Editar
                        case 4:
                            matricula = ImprimeRetornaMatricula("Digite a matricula do item que deseja editar, caso não queira editar um campo deixe vazio:");
                            autor = ImprimeRetorna<string>(txtAutor);
                            editora = ImprimeRetorna<string>(txtEditora);
                            assunto = ImprimeRetorna<string>(txtAssunto);
                            int tipo = ImprimeRetorna<int>(txtTipo);
                            //livros.editar(matricula,autor,editora,assunto,tipo,editoras,autores);
                        break;
                        //Aluguel/Devolução
                        case 5:
                            matricula = ImprimeRetornaMatricula("Digite a matricula do usuario que ira alugar o livro:");
                            // usuarios.pesquisaLista("matricula",matricula);
                            // if(usuario.livro_alugado){
                                // livros.editar(usuario.livro_alugado,"","","","",false,editoras,autores);
                                // usuarios.editar(matricula,"",NULL,NULL);
                            // }else{
                                //matricula2 = ImprimeRetornaMatricula("Digite a matricula do livro que sera alugado:");
                                //livros.pesquisaLista("matricula",matricula2);
                                //livros.editar(matricula2,"","","","",true,editoras,autores);
                                //usuarios.editar(matricula,"",matricula2,obterDataFormatada());
                            //}
                        break;
                        default:
                            cout << "Você ira retornar para o menu de gerenciar, precisone qualquer tecla para prosseguir:\n";
                            cin.ignore();
                            cout<< cin.get();
                            cout<<"\033c";
                            opcoesInter = 5;
                            opcoesLib = 0;
                        break;
                    }
                } while (opcoesInter != 5);
            break;
            //Autores
            case 2:
                //LPCE
                do{
                    opcoesInter = ImprimeRetorna<int>("Selecione oque deseja interagir: \n 1 • Listar \n 2 • Pesquisar \n 3 • Criar \n 4 • Editar \n 5• Voltar");
                    switch (opcoesInter){
                        //Listar
                        case 1:
                            /* Listagem de Autores*/
                            // if(autores.listar()){
                                cout << "Você ira retornar para o menu de interagir, precisone qualquer tecla para prosseguir:\n";
                                cin.ignore();
                                cout<< cin.get();
                                cout<<"\033c";
                                opcoesInter = 0;
                            // }
                        break;
                        //Pesquisar
                        case 2:
                            /* Pesquisa de Autores*/
                            int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n");
                            switch (pesquisa){
                                case 1:
                                    // autores.pesquisaLista("matricula",ImprimeRetornaMatricula());
                                break;
                                default:
                                    // autores.pesquisaLista("nome",ImprimeRetorna<string>("Digite o nome do autor:"));
                                break;
                            }

                            cout << "Você ira retornar para o menu de interagir, precisone qualquer tecla para prosseguir:\n";
                            cin.ignore();
                            cout<< cin.get();
                            cout<<"\033c";
                            opcoesInter = 0;
                        break;
                        //Criar
                        case 3:
                            nome = ImprimeRetorna<string>(txtNome);
                            //autores.criar(nome);
                        break;
                        //Editar
                        case 4:
                            matricula = ImprimeRetornaMatricula("Digite a matricula do item que deseja editar, caso não queira editar um campo deixe vazio:");
                            nome = ImprimeRetorna<string>(txtNome);
                            //autores.editar(matricula,nome);
                        break;
                        default:
                            cout << "Você ira retornar para o menu de gerenciar, precisone qualquer tecla para prosseguir:\n";
                            cin.ignore();
                            cout<< cin.get();
                            cout<<"\033c";
                            opcoesInter = 5;
                            opcoesLib = 0;
                        break;
                    }
                } while (opcoesInter != 5);
            break;
            //Editora
            case 3:
                do{
                    opcoesInter = ImprimeRetorna<int>("Selecione oque deseja interagir: \n 1 • Listar \n 2 • Pesquisar \n 3 • Criar \n 4 • Editar \n 5• Voltar");
                    switch (opcoesInter){
                        //Listar
                        case 1:
                            // if(editoras.listar()){
                                cout << "Você ira retornar para o menu de interagir, precisone qualquer tecla para prosseguir:\n";
                                cin.ignore();
                                cout<< cin.get();
                                cout<<"\033c";
                                opcoesInter = 0;
                            // }
                        break;
                        //Pesquisar
                        case 2:
                            /* Pesquisa de Autores*/
                            int pesquisa = ImprimeRetorna<int>("Deseja pesquisar por: \n 1 • Matricula \n 2 • Nome \n");
                            switch (pesquisa){
                                case 1:
                                    // editoras.pesquisaLista("matricula",ImprimeRetornaMatricula());
                                break;
                                default:
                                    // editoras.pesquisaLista("nome",ImprimeRetorna<string>("Digite o nome do autor:"));
                                break;
                            }
                            cout << "Você ira retornar para o menu de interagir, precisone qualquer tecla para prosseguir:\n";
                            cin.ignore();
                            cout<< cin.get();
                            cout<<"\033c";
                            opcoesInter = 0;
                        break;
                        //Criar
                        case 3:
                            nome = ImprimeRetorna<string>(txtNome);
                            //editoras.criar(nome);
                        break;
                        //Editar
                        case 4:
                            matricula = ImprimeRetornaMatricula("Digite a matricula do item que deseja editar, caso não queira editar um campo deixe vazio:");
                            nome = ImprimeRetorna<string>(txtNome);
                            //editoras.editar(matricula,nome);
                        break;
                        default:
                            cout << "Você ira retornar para o menu de gerenciar, precisone qualquer tecla para prosseguir:\n";
                            cin.ignore();
                            cout<< cin.get();
                            cout<<"\033c";
                            opcoesInter = 5;
                            opcoesLib = 0;
                        break;
                    }
                } while (opcoesInter != 5);
            break;
            //Usuarios
            case 4:
                do{
                    opcoesInter = ImprimeRetorna<int>("Selecione oque deseja interagir: \n 1 • Listar \n 2 • Pesquisar \n 3 • Criar \n 4 • Editar \n 5 • Aluguel/Devolução \n 6• Voltar");
                    