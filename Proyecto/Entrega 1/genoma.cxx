//definiciones de métodos para la clase Genoma

#include <iostream>
#include "genoma.h"

Genoma::Genoma(std::string nombre) 
{
    this->nombre = nombre;
}

std::string Genoma::getNombre() const 
{
    return nombre;
}

void Genoma::agregarSecuencia(Secuencia s) 
{
    secuencias.push_back(s);
}

int Genoma::obtenerNumeroDeSecuencias() const 
{
    return secuencias.size();
}

const std::vector<Secuencia>& Genoma::getSecuencias() const
{
    return secuencias;
}