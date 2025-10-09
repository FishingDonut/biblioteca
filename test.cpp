// test.cpp
//-----------------------------//
#include "estruturas/lista.h"
#include "estruturas/hash_fechado.h"
#include "estruturas/livros.h"
#include "estruturas/autor.h"
//-----------------------------//
#include <iostream>
#include <string>
#include <random>
#include <ctime> // Necessário para a função time()
//-----------------------------//

int main()
{
    // Inicializa o gerador de números aleatórios para não repetir
    srand(time(NULL));

    std::string lista_db_livros[7] = {
        "Don Quixote",
        "Pride and Prejudice",
        "Moby Dick",
        "War and Peace",
        "To Kill a Mockingbird",
        "The Great Gatsby",
        "One Hundred Years of Solitude"};

    std::string lista_db_autor[7] = {
        "Miguel de Cervantes",
        "Jane Austen",
        "Herman Melville",
        "Leo Tolstoy",
        "Harper Lee",
        "F. Scott Fitzgerald",
        "Gabriel García Márquez"};

    TabelaHash<livros> biblioteca;
    TabelaHash<autor> publicadora;

    for (size_t i = 0; i < 7; i++)
    {
        // 1. Criar o objeto AUTOR (sem 'new')
        autor novoAutor;
        novoAutor.matricula = rand() % 10000;
        novoAutor.nome = lista_db_autor[i];
        
        // Adicionar o objeto autor na sua tabela hash
        publicadora.adicionar(novoAutor.matricula, novoAutor);

        // 2. Criar o objeto LIVRO (sem 'new')
        livros novoLivro;
        novoLivro.matricula = rand() % 10000;
        novoLivro.nome = lista_db_livros[i];
        novoLivro.autorDoLivro = novoAutor; // Associar o autor ao livro

        // Adicionar o objeto livro na sua tabela hash
        biblioteca.adicionar(novoLivro.matricula, novoLivro);
    }
    
    // Mostra o resultado para confirmar que funcionou
    std::cout << "\n--- AUTORES CADASTRADOS ---";
    publicadora.mostrarTudo();

    std::cout << "\n--- BIBLIOTECA DE LIVROS ---";
    biblioteca.mostrarTudo();

    return 0;
}