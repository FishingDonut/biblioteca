#pragma once
#include <string>

struct autor
{
    int matricula = 0;
    std::string nome = "";
};

inline std::ostream& operator<<(std::ostream& os, const autor& a){
    os << a.nome;
    return os;
} 