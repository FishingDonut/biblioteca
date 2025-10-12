#pragma once
#include <iostream>
#include <random>
#include <ostream>
#include <ctime>

enum Status{
    Retirada,
    Entrega
};

struct Historico
{
    int id = rand() % 100000;
    int matriculaUsuario = 0;
    time_t horario;
    Status status = Retirada;
};

inline std::ostream& operator<<(std::ostream& os, const Historico& h){
    char buf[100];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&h.horario));
    os << "Usuario(" << h.matriculaUsuario << "): " << (h.status == Retirada ? "Retirada" : "Entrega") << " em " << buf;
    return os;
}