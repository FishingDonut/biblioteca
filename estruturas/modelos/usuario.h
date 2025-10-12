#pragma once
#include "historico.h"
#include <string>
#include <random>
#include <ostream>

struct Usuario
{
    int matricula = rand() % 100000;
    std::string nome = "";
    // No<Historico> historicoMatriculasLivros; 
};

inline std::ostream& operator<<(std::ostream& os, const Usuario& u){
    os << u.nome;
    return os;
}