#pragma once
#include "autor.h"
#include <iostream>

struct livros
{
    int matricula = 0;
    std::string nome; 
};

inline std::ostream& operator<<(std::ostream& os, const livros& b){
    os << b.nome;
    return os;
} 
