#ifndef COMANDOS_H
#define COMANDOS_H
#include <string>

using namespace std;

enum Comandos  //Un tipo de estructura de constantes, en este caso, el nombre de los comandos
{//enum enumera xd
    AYUDA, //0
    CARGAR, //1
    LISTAR_SECUENCIAS, //2
    HISTOGRAMA, //3
    ES_SUBSECUENCIA, //4
    ENMASCARAR, //5
    GUARDAR, //6
    CODIFICAR, //7
    DECODIFICAR, //8
    RUTA_MAS_CORTA, //9
    BASE_REMOTA, //10
    SALIR, //11
    INVALIDO //12
};

Comandos procesamiento (string cmd);
bool validarParametros(Comandos cmd, int numParametros);
void mostrarAyudaComando(Comandos comando);

 #endif // COMANDOS_H