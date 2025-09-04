#include "secuencia.h"

Secuencia::Secuencia(std::string descripcion, std::vector<char> bases)
    : descripcion(descripcion), bases(bases) {}

std::string Secuencia::getDescripcion() const {
    return descripcion;
}

std::vector<char> Secuencia::getBases() const{
    return bases;
}

int Secuencia::contarBases() const{
    int total = 0;
    for (char base : bases) 
    {
        if (base != '-') 
        {
            total++;
        }
    }
   return total;
}