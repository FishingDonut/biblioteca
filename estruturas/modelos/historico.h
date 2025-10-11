#pragma once
#include <iostream>

enum Status{
    Retirada,
    Entrega
};

struct Historico
{
    int matriculaUsuario = 0;
    time_t horario;
    Status status = Retirada;
};