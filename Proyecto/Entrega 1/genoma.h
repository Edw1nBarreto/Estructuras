#ifndef GENOMA_H
#define GENOMA_H

#include <string>
#include <vector>
#include "secuencia.h"

class Genoma {
private:

    std::string nombre;                  
    std::vector<Secuencia> secuencias;  

public:

    Genoma(std::string nombre);
    std::string getNombre();
    void agregarSecuencia(Secuencia secuencia);
    int obtenerNumeroDeSecuencias();
    void guardarSecuencias(std::string nombreArchivo);
};

#endif
