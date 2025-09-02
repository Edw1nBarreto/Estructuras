#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <vector>
#include "secuencia.h"
#include "genoma.h"     

class Sistema {
private:
    std::vector<Genoma> genomas;

public:

    void cargarArchivo(std::string nombreArchivo);
    void listarSecuencias();
    void mostrarHistograma(std::string descripcion);
    void buscarSubsecuencia(std::string subsecuencia);
    void enmascararSubsecuencia(std::string subsecuencia);
    void guardarArchivo(std::string nombreArchivo);
};

#endif

