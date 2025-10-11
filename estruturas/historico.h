#pragma once
#include <iostream>

enum Status{
    Retirada,
    Entrega
};

struct historico
{
    int matriculaUsuario = 0;
    time_t horario;
    Status status = Retirada;
};