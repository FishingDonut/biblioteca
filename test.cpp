#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "models/autores.h"
#include "models/editoras.h"
#include "models/historicos.h"
#include "models/livros.h"
#include "models/usuarios.h"

void testAutores() {
    std::cout << "\n--- Testando Autores ---\n";
    Autores autores;
    autores.criar("J.K. Rowling");
    autores.criar("George R.R. Martin");
    autores.criar("Tolkien");
    autores.listar();
}

void testEditoras() {
    std::cout << "\n--- Testando Editoras ---\n";
    Editoras editoras;
    editoras.criar("Rocco");
    editoras.criar("Leya");
    editoras.criar("HarperCollins");
    editoras.listar();
}

void testHistoricos() {
    std::cout << "\n--- Testando Historicos ---\n";
    Historicos historicos;
    historicos.criar(101, 201, true, "10/10/2025");
    historicos.criar(102, 201, true, "11/10/2025");
    historicos.criar(101, 202, false, "12/10/2025");
    historicos.listar();
}

void testLivros() {
    std::cout << "\n--- Testando Livros ---\n";
    Livros livros;
    livros.criar(1, 1, "Fantasia", "Livro", false, "");
    livros.criar(2, 2, "Fantasia", "Livro", true, "10/10/2025");
    livros.criar(3, 3, "Ficcao", "Livro", false, "");
    livros.listar();
}

void testUsuarios() {
    std::cout << "\n--- Testando Usuarios ---\n";
    Usuarios usuarios;
    usuarios.criar(0, "", "Daniel");
    usuarios.criar(102, "10/10/2025", "Juliana");
    usuarios.criar(0, "", "Carlos");
    usuarios.listar();
}

int main() {
    srand(time(NULL));

    testAutores();
    testEditoras();
    testHistoricos();
    testLivros();
    testUsuarios();

    return 0;
}