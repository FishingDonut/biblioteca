#include <iostream>
#include <string>
#include <random>
#include <ctime>

// Include all models and hash structures
#include "estruturas/modelos/autor.h"
#include "estruturas/hashing/autor_hash.h"
#include "estruturas/modelos/editora.h"
#include "estruturas/hashing/editora_hash.h"
#include "estruturas/modelos/livro.h"
#include "estruturas/hashing/livro_hash.h"
#include "estruturas/modelos/historico.h"
#include "estruturas/hashing/historico_hash.h"
#include "estruturas/modelos/usuario.h"
#include "estruturas/hashing/usuario_hash.h"

void testAutorHash() {
    std::cout << "\n--- Testando AutorHash ---\n";
    AutorHash ah;
    std::string nomes[7] = {"Autor A", "Autor B", "Autor C", "Autor D", "Autor E", "Autor F", "Autor G"};
    for (int i = 0; i < 7; i++) {
        Autor a;
        a.nome = nomes[i];
        ah.adicionar(a.matricula, a);
    }
    ah.mostrarTudo();
}

void testEditoraHash() {
    std::cout << "\n--- Testando EditoraHash ---\n";
    EditoraHash eh;
    std::string nomes[5] = {"Editora X", "Editora Y", "Editora Z", "Editora W", "Editora K"};
    for (int i = 0; i < 5; i++) {
        Editora e;
        e.nome = nomes[i];
        eh.adicionar(e.matricula, e);
    }
    eh.mostrarTudo();
}

void testLivroHash() {
    std::cout << "\n--- Testando LivroHash ---\n";
    LivroHash lh;
    std::string titulos[4] = {"Livro 1", "Livro 2", "Livro 3", "Livro 4"};
    for (int i = 0; i < 4; i++) {
        Livro l;
        l.titulo = titulos[i];
        lh.adicionar(l.matricula, l);
    }
    lh.mostrarTudo();
}

void testHistoricoHash() {
    std::cout << "\n--- Testando HistoricoHash ---\n";
    HistoricoHash hh;
    for (int i = 0; i < 5; i++) {
        Historico h;
        h.matriculaUsuario = 100 + i;
        h.horario = time(0);
        h.status = (i % 2 == 0) ? Retirada : Entrega;
        hh.adicionar(h.id, h);
    }
    hh.mostrarTudo();
}

void testUsuarioHash() {
    std::cout << "\n--- Testando UsuarioHash ---\n";
    UsuarioHash uh;
    std::string nomes[3] = {"Usuario 1", "Usuario 2", "Usuario 3"};
    for (int i = 0; i < 3; i++) {
        Usuario u;
        u.nome = nomes[i];
        uh.adicionar(u.matricula, u);
    }
    uh.mostrarTudo();
}

int main() {
    srand(time(NULL));

    testAutorHash();
    testEditoraHash();
    testLivroHash();
    testHistoricoHash();
    testUsuarioHash();

    return 0;
}
