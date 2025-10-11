#pragma once
#include "historico.h"
#include "no.h"
#include <string>

struct usuario
{
    int matricula = 0;
    std::string nome = "";
    No<historico> historicoMatriculasLivros; 
};