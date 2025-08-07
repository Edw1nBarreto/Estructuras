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
            cout << "DESCRIPCIÓN: Carga una secuencia de ADN desde un archivo FASTA" << endl;
            cout << "SINTAXIS: cargar <nombre_archivo>" << endl;
            cout << "EJEMPLO: cargar secuencia.fasta" << endl;
            break;
        case LISTAR_SECUENCIAS:
            cout << "COMANDO: listar_secuencias" << endl;
            cout << "DESCRIPCIÓN: Lista todas las secuencias de ADN cargadas en memoria" << endl;
            cout << "SINTAXIS: listar_secuencias" << endl;
            cout << "EJEMPLO: listar_secuencias" << endl;
            break;
        case HISTOGRAMA:
            cout << "COMANDO: histograma" << endl;
            cout << "DESCRIPCIÓN: Genera un histograma de bases nitrogenadas de una secuencia" << endl;
            cout << "SINTAXIS: histograma <nombre_secuencia>" << endl;
            cout << "EJEMPLO: histograma seq1" << endl;
            break;
        case ES_SUBSECUENCIA:
            cout << "COMANDO: es_subsecuencia" << endl;
            cout << "DESCRIPCIÓN: Verifica si una secuencia es subsecuencia de otra" << endl;
            cout << "SINTAXIS: es_subsecuencia <secuencia1> <secuencia2>" << endl;
            cout << "EJEMPLO: es_subsecuencia ATCG ATCGATCG" << endl;
            break;
        case ENMASCARAR:
            cout << "COMANDO: enmascarar" << endl;
            cout << "DESCRIPCIÓN: Enmascara una región específica de una secuencia de ADN" << endl;
            cout << "SINTAXIS: enmascarar <nombre_secuencia> <inicio> <fin>" << endl;
            cout << "EJEMPLO: enmascarar seq1 10 20" << endl;
            break;
        case GUARDAR:
            cout << "COMANDO: guardar" << endl;
            cout << "DESCRIPCIÓN: Guarda una secuencia de ADN en un archivo FASTA" << endl;
            cout << "SINTAXIS: guardar <nombre_secuencia> <nombre_archivo>" << endl;
            cout << "EJEMPLO: guardar seq1 salida.fasta" << endl;
            break;
        case CODIFICAR:
            cout << "COMANDO: codificar" << endl;
            cout << "DESCRIPCIÓN: Codifica una secuencia de ADN usando un método específico" << endl;
            cout << "SINTAXIS: codificar <nombre_secuencia> <metodo>" << endl;
            cout << "EJEMPLO: codificar seq1 huffman" << endl;
            break;
        case DECODIFICAR:
            cout << "COMANDO: decodificar" << endl;
            cout << "DESCRIPCIÓN: Decodifica una secuencia de ADN previamente codificada" << endl;
            cout << "SINTAXIS: decodificar <secuencia_codificada> <metodo>" << endl;
            cout << "EJEMPLO: decodificar 101010 huffman" << endl;
            break;
        case RUTA_MAS_CORTA:
            cout << "COMANDO: ruta_mas_corta" << endl;
            cout << "DESCRIPCIÓN: Encuentra la ruta más corta entre dos secuencias de ADN" << endl;
            cout << "SINTAXIS: ruta_mas_corta <secuencia1> <secuencia2>" << endl;
            cout << "EJEMPLO: ruta_mas_corta seq1 seq2" << endl;
            break;
        case BASE_REMOTA:
            cout << "COMANDO: base_remota" << endl;
            cout << "DESCRIPCIÓN: Accede a una base de datos remota de secuencias de ADN" << endl;
            cout << "SINTAXIS: base_remota <operacion> [parámetros]" << endl;
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

