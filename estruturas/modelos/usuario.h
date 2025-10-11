#pragma once
#include "historico.h"
#include "no.h"
#include <string>

struct Usuario
{
    int matricula = 0;
    std::string nome = "";
    No<Historico> historicoMatriculasLivros; 
};