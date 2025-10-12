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
#include "models/revistas.h"

void testAutores() {
    std::cout << "\n--- Testando Autores ---\n";
    Autores autores;
    autores.criar("J.K. Rowling");
    Autor autorParaEditar = autores.criar("G.R.R. Martin");
    autores.listar();
    std::cout << "\n--- Editando Autor ---\n";
    autores.editar(autorParaEditar.matricula, "George R.R. Martin");
    autores.listar();
}

void testEditoras() {
    std::cout << "\n--- Testando Editoras ---\n";
    Editoras editoras;
    editoras.criar("Rocco");
    Editora editoraParaEditar = editoras.criar("Leay");
    editoras.listar();
    std::cout << "\n--- Editando Editora ---\n";
    editoras.editar(editoraParaEditar.matricula, "Leya");
    editoras.listar();
}

void testHistoricos() {
    std::cout << "\n--- Testando Historicos ---\n";
    Historicos historicos;
    historicos.criar(101, 201, true, "10/10/2025");
    Historico historicoParaEditar = historicos.criar(102, 201, true, "11/10/2025");
    historicos.listar();
    std::cout << "\n--- Editando Historico ---\n";
    historicos.editar(historicoParaEditar.matricula, 102, 203, false, "13/10/2025");
    historicos.listar();
}

void testLivros() {
    std::cout << "\n--- Testando Livros ---\n";
    Livros livros;
    livros.criar(1, 1, "Fantasia", "Livro", false, "");
    Livro livroParaEditar = livros.criar(2, 2, "Fantasia", "Livro", true, "10/10/2025");
    livros.listar();
    std::cout << "\n--- Editando Livro ---\n";
    livros.editar(livroParaEditar.matricula, 2, 2, "Sci-Fi", "Livro", false, "");
    livros.listar();
}

void testUsuarios() {
    std::cout << "\n--- Testando Usuarios ---\n";
    Usuarios usuarios;
    usuarios.criar("Daniel");
    Usuario usuarioParaEditar = usuarios.criar("Julina");
    usuarios.listar();
    std::cout << "\n--- Editando Usuario ---\n";
    usuarios.editar(usuarioParaEditar.matricula, "Juliana");
    usuarios.listar();
}

void testRevistas() {
    std::cout << "\n--- Testando Revistas ---\n";
    Revistas revistas;
    revistas.criar(1, "Ciencia", "Revista", false, "");
    Revista revistaParaEditar = revistas.criar(2, "Tecnologia", "Revista", true, "10/10/2025");
    revistas.listar();
    std::cout << "\n--- Editando Revista ---\n";
    revistas.editar(revistaParaEditar.matricula, 2, "Business", "Revista", false, "");
    revistas.listar();
}

int main() {
    srand(time(NULL));

    testAutores();
    testEditoras();
    testHistoricos();
    testLivros();
    testUsuarios();
    testRevistas();

    return 0;
}