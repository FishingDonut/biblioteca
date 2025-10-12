#pragma once
#include <string>
#include <random>
#include <ostream>

struct Editora
{
    int matricula = rand() % 100000;
    std::string nome = "";
};

inline std::ostream& operator<<(std::ostream& os, const Editora& e){
    os << e.nome;
    return os;
}