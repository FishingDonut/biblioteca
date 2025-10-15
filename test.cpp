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

void testPesquisa() {
    std::cout << "\n--- Pesquisando Autores por Nome ---\n";
    Autores autores;
    autores.criar("J.K. Rowling");
    autores.criar("J.K. Rowling");
    autores.listar();
    autores.pesquisaLista("nome", std::string("J.K. Rowling"));
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
    livros.criar(1, 1, "Fantasia", 1, false, "");
    Livro livroParaEditar = livros.criar(2, 2, "Fantasia", 1, true, "10/10/2025");
    livros.listar();
    std::cout << "\n--- Editando Livro ---\n";
    livros.editar(livroParaEditar.matricula, 2, 2, "Sci-Fi", 1, false, "");
    livros.listar();
}

void testUsuarios() {
    std::cout << "\n--- Testando Usuarios ---\n";
    Usuarios usuarios;
    usuarios.criar("Daniel");
    Usuario usuarioParaEditar = usuarios.criar("Julina");
    usuarios.listar();
    std::cout << "\n--- Editando Usuario ---\n";
    usuarios.editar(usuarioParaEditar.matricula, "Juliana",0);
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

void testPesquisaEditoras() {
    std::cout << "\n--- Pesquisando Editoras por Nome ---\n";
    Editoras editoras;
    editoras.criar("Editora A");
    editoras.criar("Editora A");
    editoras.listar();
    editoras.pesquisaLista("nome", std::string("Editora A"));
}

void testPesquisaHistoricos() {
    std::cout << "\n--- Pesquisando Históricos por Usuario ---\n";
    Historicos historicos;
    historicos.criar(1, 101, true, "10/10/2025");
    historicos.criar(2, 101, true, "11/10/2025");
    historicos.listar();
    historicos.pesquisaLista("usuario", 101);
}

void testPesquisaLivros() {
    std::cout << "\n--- Pesquisando Livros por Assunto ---\n";
    Livros livros;
    livros.criar(1, 1, "Fantasia", 1, false, "");
    livros.criar(2, 2, "Fantasia", 1, true, "10/10/2025");
    livros.listar();
    livros.pesquisaLista("assunto", std::string("Fantasia"));
}

void testPesquisaRevistas() {
    std::cout << "\n--- Pesquisando Revistas por Assunto ---\n";
    Revistas revistas;
    revistas.criar(1, "Ciencia", "Revista", false, "");
    revistas.criar(2, "Ciencia", "Revista", true, "10/10/2025");
    revistas.listar();
    revistas.pesquisaLista("assunto", std::string("Ciencia"));
}

void testPesquisaUsuarios() {
    std::cout << "\n--- Pesquisando Usuários por Nome ---\n";
    Usuarios usuarios;
    usuarios.criar("Daniel");
    usuarios.criar("marcos");
    usuarios.criar("Mendonsa");
    usuarios.criar("pedro");
    usuarios.listar();
    usuarios.pesquisaLista("nome", std::string("Jerson"));
}

int main() {
    srand(time(NULL));

    testPesquisa();
    testPesquisaEditoras();
    testPesquisaHistoricos();
    testPesquisaLivros();
    testPesquisaRevistas();
    testPesquisaUsuarios();

    return 0;
}