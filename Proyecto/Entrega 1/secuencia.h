#ifndef SECUENCIA_H
#define SECUENCIA_H

#include <string>

class Secuencia {
private:

    std::string descripcion;
    std::string bases;

public:

    Secuencia(std::string descripcion, std::string bases);
    std::string getDescripcion();
    std::string getBases();
    int contarBases();
};

#endif
