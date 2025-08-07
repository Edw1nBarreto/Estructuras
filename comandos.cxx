#include "comandos.h"
#include <iostream>

Comandos procesamiento(string linea)
{ //Esta funcion recibe una linea de texto y devuelve el comando correspondiente
    if(linea == "ayuda") 
        return AYUDA;
    if(linea == "cargar") 
        return CARGAR;
    if(linea == "listar_secuencias") 
        return LISTAR_SECUENCIAS;
    if(linea == "histograma") 
        return HISTOGRAMA;
    if(linea == "es_subsecuencia") 
        return ES_SUBSECUENCIA;
    if(linea == "enmascarar") 
        return ENMASCARAR;
    if(linea == "guardar") 
        return GUARDAR;
    if(linea == "codificar") 
        return CODIFICAR;
    if(linea == "decodificar") 
        return DECODIFICAR;
    if(linea == "ruta_mas_corta") 
        return RUTA_MAS_CORTA;
    if(linea == "base_remota") 
        return BASE_REMOTA;
    if(linea == "salir") 
        return SALIR;

    return INVALIDO;
}
bool validarParametros(Comandos cmd, int numParametros) {
    switch (cmd) {
        case AYUDA:
            if(numParametros == 0||numParametros == 1)
            {
                return true;
            }
        case CARGAR:
            if(numParametros == 1)
            {
                return true;
            }
        case LISTAR_SECUENCIAS:
            if(numParametros == 0)
            {
                return true;
            }
        case HISTOGRAMA:
            if(numParametros == 1)
            {
                return true;
            }
        case ES_SUBSECUENCIA:
            if(numParametros == 1)
            {
                return true;
            }
        case ENMASCARAR:
            if(numParametros == 1)
            {
                return true;
            }
        case GUARDAR:
            if(numParametros == 1)
            {
                return true;
            }
        case CODIFICAR:
            if(numParametros == 1)
            {
                return true;
            }
        case DECODIFICAR:
            if(numParametros == 1)
            {
                return true;
            }
        case RUTA_MAS_CORTA:
            if(numParametros == 5)
            {
                return true;
            }
        case BASE_REMOTA:
            if(numParametros == 3)
            {
                return true;
            }
        case SALIR:
            if(numParametros == 0)
            {
                return true;
            }
        default:
            return false;
    }
}
void mostrarAyudaComando(Comandos comando) {
    switch(comando) {
        case CARGAR:
            cout << "COMANDO: cargar" << endl;
            cout << "DESCRIPCIÓN: Carga en memoria los datos contenidos por nombre_archivo" << endl;
            cout << "SINTAXIS: cargar <nombre_archivo>" << endl;
            cout << "EJEMPLO: cargar secuencia.fasta" << endl;
            break;
        case LISTAR_SECUENCIAS:
            cout << "COMANDO: listar_secuencias" << endl;
            cout << "DESCRIPCIÓN: Imprime la cantidad de secuencias actualmente en memoria y la información                            basica de cada secuencia." << endl;
            cout << "SINTAXIS: listar_secuencias" << endl;
            cout << "EJEMPLO: listar_secuencias" << endl;
            break;
        case HISTOGRAMA:
            cout << "COMANDO: histograma" << endl;
            cout << "DESCRIPCIÓN: Imprime el histograma de una secuencia, en caso de que no exista." << endl;
            cout << "SINTAXIS: histograma <descripcion_secuencia>" << endl;
            cout << "EJEMPLO: histograma seq1" << endl;
            break;
        case ES_SUBSECUENCIA:
            cout << "COMANDO: es_subsecuencia" << endl;
            cout << "DESCRIPCIÓN: Verifica si una secuencia es subsecuencia de las secuencias cargadas en                             memoria." << endl;
            cout << "SINTAXIS: es_subsecuencia subsequencia" << endl;
            cout << "EJEMPLO: es_subsecuencia ATCGATCGATCG" << endl;
            break;
        case ENMASCARAR:
            cout << "COMANDO: enmascarar" << endl;
            cout << "DESCRIPCIÓN: Enmascara una subsecuencia dada por el usuario, si existe." << endl;
            cout << "SINTAXIS: enmascarar subsecuencia" << endl;
            cout << "EJEMPLO: enmascarar ATCGATCGATCG" << endl;
            break;
        case GUARDAR:
            cout << "COMANDO: guardar" << endl;
            cout << "DESCRIPCIÓN: Guarda en el archivo nombre_archivo las secuencias cargadas en memoria." <<                         endl;
            cout << "SINTAXIS: guardar<nombre_archivo>" << endl;
            cout << "EJEMPLO: guardar salida.fasta" << endl;
            break;
        case CODIFICAR:
            cout << "COMANDO: codificar" << endl;
            cout << "DESCRIPCIÓN: Genera el archivo binario con codificación Huffman y tipo de archivo .fabin" <<                     endl;
            cout << "SINTAXIS: codificar <nombre_archivo>" << endl;
            cout << "EJEMPLO: codificar huffman.fabin" << endl;
            break;
        case DECODIFICAR:
            cout << "COMANDO: decodificar" << endl;
            cout << "DESCRIPCIÓN: Cargar en memoria las secuencias contenidas en un archivo codificado .fabin" <<                     endl;
            cout << "SINTAXIS: decodificar <nombre_archivo>" << endl;
            cout << "EJEMPLO: decodificar huffman.fabin" << endl;
            break;
        case RUTA_MAS_CORTA:
            cout << "COMANDO: ruta_mas_corta" << endl;
            cout << "DESCRIPCIÓN: El comando debe imprimir en pantalla la secuencia de vértices (bases) del grafo                     que describen la ruta más corta entre la base ubicada en la posición [i ,j ] de la matriz de                      la secuencia descripcion_secuencia y la base ubicada en la posición [x ,y ] de la misma                           matriz. Así mismo, debe imprimir el costo total de la ruta, teniendo en cuenta el peso que                        tiene cada conexión entre bases." << endl;
            cout << "SINTAXIS: ruta_mas_corta descripcion_secuencia i j x y" << endl;
            cout << "EJEMPLO: ruta_mas_corta seq1 2 2 4 4" << endl;
            break;
        case BASE_REMOTA:
            cout << "COMANDO: base_remota" << endl;
            cout << "DESCRIPCIÓN: Para la base ubicada en la posición [i ,j ] de la matriz de la secuencia descripcion_secuencia,"
                    "el comando busca la ubicación de la misma base (misma letra) más lejana dentro de la matriz. Para esta"
                    "base remota, el comando debe imprimir en pantalla su ubicación, la secuencia de vértices (bases) que"
                    "describen la ruta entre la base origen y la base remota, y el costo total de la ruta, teniendo en cuenta"
                    "el peso que tiene cada conexión entre bases." << endl;
            cout << "SINTAXIS: base_remota descripcion_secuencia i j" << endl;
            cout << "EJEMPLO: base_remota buscar NCBI_ID" << endl;
            break;
        case SALIR:
            cout << "COMANDO: salir" << endl;
            cout << "DESCRIPCIÓN: Termina la ejecución del programa" << endl;
            cout << "SINTAXIS: salir" << endl;
            cout << "EJEMPLO: salir" << endl;
            break;
        case AYUDA:
            cout << "COMANDO: ayuda" << endl;
            cout << "DESCRIPCIÓN: Muestra información sobre los comandos disponibles" << endl;
            cout << "SINTAXIS: ayuda [comando]" << endl;
            cout << "EJEMPLO: ayuda cargar" << endl;
            break;
        default:
            cout << "ERROR: Comando no reconocido." << endl;
            cout << "Use 'ayuda' para ver todos los comandos disponibles." << endl;
            break;
    }
}

