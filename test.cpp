#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#define TAM 5

#include "models/autores.h"
#include "models/editoras.h"
#include "models/historicos.h"
#include "models/livros.h"
#include "models/usuarios.h"
#include "models/revistas.h"
using namespace std;

void testAutores() {
    cout << "\n--- Testando Autores ---\n";
    Autores autores;
    autores.criar("J.K. Rowling");
    Autor autorParaEditar = autores.criar("G.R.R. Martin");
    autores.listar();
    cout << "\n--- Editando Autor ---\n";
    autores.editar(autorParaEditar.matricula, "George R.R. Martin");
    autores.listar();
}

void testPesquisa() {
    cout << "\n--- Pesquisando Autores por Nome ---\n";
    Autores autores;
    autores.criar("J.K. Rowling");
    autores.criar("J.K. Rowling");
    autores.listar();
    autores.pesquisaLista("nome", string("J.K. Rowling"));
}

void testEditoras() {
    cout << "\n--- Testando Editoras ---\n";
    Editoras editoras;
    editoras.criar("Rocco");
    Editora editoraParaEditar = editoras.criar("Leay");
    editoras.listar();
    cout << "\n--- Editando Editora ---\n";
    editoras.editar(editoraParaEditar.matricula, "Leya");
    editoras.listar();
}

void testHistoricos() {
    cout << "\n--- Testando Historicos ---\n";
    Historicos historicos;
    historicos.criar(101, 201, true, "10/10/2025");
    Historico historicoParaEditar = historicos.criar(102, 201, true, "11/10/2025");
    historicos.listar();
    cout << "\n--- Editando Historico ---\n";
    historicos.editar(historicoParaEditar.matricula, 102, 203, false, "13/10/2025");
    historicos.listar();
}

void testLivros() {
    cout << "\n--- Testando Livros ---\n";
    Livros livros;
    livros.criar(1, 1, "Fantasia", 1, false, "");
    Livro livroParaEditar = livros.criar(2, 2, "Fantasia", 1, true, "10/10/2025");
    livros.listar();
    cout << "\n--- Editando Livro ---\n";
    livros.editar(livroParaEditar.matricula, 2, 2, "Sci-Fi", 1, false, "");
    livros.listar();
}

void testUsuarios() {
    cout << "\n--- Testando Usuarios ---\n";
    Usuarios usuarios;
    usuarios.criar("Daniel");
    Usuario usuarioParaEditar = usuarios.criar("Julina");
    usuarios.listar();
    cout << "\n--- Editando Usuario ---\n";
    usuarios.editar(usuarioParaEditar.matricula, "Juliana",0);
    usuarios.listar();
}

void testRevistas() {
    cout << "\n--- Testando Revistas ---\n";
    Revistas revistas;
    revistas.criar(1, "Ciencia", "Revista", false, "");
    Revista revistaParaEditar = revistas.criar(2, "Tecnologia", "Revista", true, "10/10/2025");
    revistas.listar();
    cout << "\n--- Editando Revista ---\n";
    revistas.editar(revistaParaEditar.matricula, 2, "Business", "Revista", false, "");
    revistas.listar();
}

void testPesquisaEditoras() {
    cout << "\n--- Pesquisando Editoras por Nome ---\n";
    Editoras editoras;
    editoras.criar("Editora A");
    editoras.criar("Editora A");
    editoras.listar();
    editoras.pesquisaLista("nome", string("Editora A"));
}

void testPesquisaHistoricos() {
    cout << "\n--- Pesquisando Históricos por Usuario ---\n";
    Historicos historicos;
    historicos.criar(1, 101, true, "10/10/2025");
    historicos.criar(2, 101, true, "11/10/2025");
    historicos.listar();
    historicos.pesquisaLista("usuario", 101);
}

void testPesquisaLivros() {
    cout << "\n--- Pesquisando Livros por Assunto ---\n";
    Livros livros;
    livros.criar(1, 1, "Fantasia", 1, false, "");
    livros.criar(2, 2, "Fantasia", 1, true, "10/10/2025");
    livros.listar();
    livros.pesquisaLista("assunto", string("Fantasia"));
}

void testPesquisaRevistas() {
    cout << "\n--- Pesquisando Revistas por Assunto ---\n";
    Revistas revistas;
    revistas.criar(1, "Ciencia", "Revista", false, "");
    revistas.criar(2, "Ciencia", "Revista", true, "10/10/2025");
    revistas.listar();
    revistas.pesquisaLista("assunto", string("Ciencia"));
}

void testPesquisaUsuarios() {
    cout << "\n--- Pesquisando Usuários por Nome ---\n";
    Usuarios usuarios;
    usuarios.criar("Daniel");
    usuarios.criar("marcos");
    usuarios.criar("Mendonsa");
    usuarios.criar("pedro");
    usuarios.listar();
    usuarios.pesquisaLista("nome", string("Jerson"));
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