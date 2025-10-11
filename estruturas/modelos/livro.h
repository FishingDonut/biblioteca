#pragma once
#include "autor.h"
#include <iostream>

struct Livro
{
    int matricula = 0;
    int matriculaAutor = 0;
    int matriculaEditora = 0;
    int matriculaUsuario = 0;
    std::string titulo = ""; 
    std::string assunto = ""; 
    bool ocupado = false;
    time_t dataDevolucao;
};



// inline std::ostream& operator<<(std::ostream& os, const livros& b){
//     os << b.nome;
//     return os;
// } 
