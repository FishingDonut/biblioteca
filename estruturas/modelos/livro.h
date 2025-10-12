#pragma once
#include "autor.h"
#include <iostream>
#include <string>
#include <random>
#include <ostream>

struct Livro
{
    int matricula = rand() % 100000;
    int matriculaAutor = 0;
    int matriculaEditora = 0;
    int matriculaUsuario = 0;
    std::string titulo = ""; 
    std::string assunto = ""; 
    bool ocupado = false;
    time_t dataDevolucao;
};

inline std::ostream& operator<<(std::ostream& os, const Livro& l){
    os << l.titulo;
    return os;
}
