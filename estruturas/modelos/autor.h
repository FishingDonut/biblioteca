#pragma once
#include <string>
#include <random>
#include <ostream>

struct Autor
{
    int matricula = rand() % 100000;
    std::string nome = "";
};

inline std::ostream& operator<<(std::ostream& os, const Autor& a){
    os << a.matricula;
    return os;
} 