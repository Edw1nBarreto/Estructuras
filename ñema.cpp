#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

enum Comandos  //Un tipo de estructura de constantes, en este caso, el nombre de los comandos
{
    AYUDA,
    CARGAR,
    LISTAR_SECUENCIAS,
    HISTOGRAMA,
    ES_SUBSECUENCIA,
    ENMASCARAR,
    GUARDAR,
    CODIFICAR,
    DECODIFICAR,
    RUTA_MAS_CORTA,
    BASE_REMOTA,
    SALIR,
    INVALIDO
};

Comandos procesamiento (string cmd);

int main()
{
    string linea;
    cout<<"------------------SISTEMA DE MANIPULACIÓN DE CADENAS DE ADN FASTA------------------"<<endl;
    cout<<"Escriba 'ayuda' para ver los comandos disponibles."<<endl;
    while(true) //Asegurarse de que salga del ciclo solo cuando se ingrese el comando salir y de que salga el simbolo $ para ingresar comandos
    {
        int parametros = 0; //Toda esta parte fue generada por IA, se encarga de contar los parametros que se ingresan en la linea de comandos y separarlos del comando en si
        cout<<"$";
        cin>>linea;
        istringstream iss(linea);
        string cmd; //Se separa el comando de los parametros y se guarda en la variable cmd
        iss >> cmd;
        string temp; //Se guarda el resto de la linea en la variable temp
        while(iss >> temp)
            {
                parametros++;
            }
        
        Comandos comando = procesamiento(cmd);
        cout<<"Este es el comando: "<<comando<<endl; //El comando digitado se transforma en un entero, haciendo mas facil el procesamiento para el resto del programa 0 = AYUDA, 1 = CARGAR, etc.
        

    }
    return 0;
}

Comandos procesamiento(string linea)
{
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