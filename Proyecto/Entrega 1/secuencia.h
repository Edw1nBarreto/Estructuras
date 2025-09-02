#ifndef SECUENCIA_H
#define SECUENCIA_H

#include <string>

class Secuencia {
private:

    std::string descripcion;
    std::vector<char> bases;

public:

    Secuencia(std::string descripcion, std::vector<char> bases);
    std::string getDescripcion();
    std::vector<char> getBases();
    int contarBases();
};

#endif
