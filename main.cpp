#include <iostream>
#include <sstream>
#include <string>
#include "comandos.h"
using namespace std;

int main()
{
    int numParametros = 0;
    string linea;
    cout << "------------------SISTEMA DE MANIPULACION DE CADENAS DE ADN FASTA------------------" << endl;
    cout << "Escriba 'ayuda' para ver los comandos disponibles." << endl;


    while (true) // Asegurarse de que salga del ciclo solo cuando se ingrese el comando salir
    {
        cout << "Ingrese un comando: " << endl;
        cout<< "$";
        getline(cin,linea); //si captura toda la linea de texto

        istringstream iss(linea);
        string cmd; // Se separa el comando de los parametros y se guarda en la variable cmd
        iss>> cmd;
        int numParametros = -1;
        string primerParametro;
        iss >> primerParametro; //Utilizado para comando "ayuda por comando"
        istringstream iss2(linea);
        string  temp;
        while(iss2 >> temp)
            {
                numParametros++;
            }
        cout<<"Parametros leidos: "<<numParametros<<" "<<temp<<endl;
        
        

        Comandos comando = procesamiento(cmd);
       
        switch (comando)  // Cambiado a switch p
            {
            case AYUDA:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 0)
                    {
                        cout<<"------------------AYUDA------------------"<<endl;
                        cout<<"Usted ha solicitado ayuda."<<endl;
                        cout<<"Comandos disponibles:" << endl;
                        cout<<"- Ayuda" << endl;
                        cout<<"- Cargar" << endl;
                        cout<<"- Listar_secuencias" << endl;
                        cout<<"- Histograma" << endl;
                        cout<<"- Es_subsecuencia" << endl;
                        cout<<"- Enmascarar" << endl;
                        cout<<"- Guardar" << endl;
                        cout<<"- Codificar" << endl;
                        cout<<"- Decodificar" << endl;
                        cout<<"- Ruta_mas_corta" << endl;
                        cout<<"- Base_remota" << endl;
                        cout<<"- Salir" << endl;
                        cout<<"Para obtener ayuda sobre un comando en especifico, escriba 'ayuda <comando>'."<<endl;
                        cout<<"----------------FIN AYUDA----------------"<<endl<<endl;
                    }
                    else if (numParametros == 1)
                    {
                        Comandos comandoAyuda = procesamiento(primerParametro);
                        if(comandoAyuda != INVALIDO)
                        {
                            cout<<"------------------AYUDA X COMANDO------------------"<<endl;
                            mostrarAyudaComando(comandoAyuda);
                        } 
                        else {
                            cout << "ERROR: '" << primerParametro << "' no es un comando valido." << endl;
                            cout << "Use 'ayuda' para ver todos los comandos disponibles." << endl;
                        }
                    }
                }
                break;

            case CARGAR:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 1)
                    {
                        cout<<"------------------CARGAR------------------"<<endl;
                        cout<<"Usted ha solicitado cargar una secuencia de ADN (FASTA)"<<endl;
                        //Llamar a la funcion que carga la secuencia de ADN
                        cout<<"---------------FIN CARGAR----------------"<<endl<<endl;
                    }
                    else
                    {
                        cout<<"ERROR: El comando 'cargar' requiere un parametro."<<endl;
                    }
                }
                break;
                

            case LISTAR_SECUENCIAS:
                cout<<"------------------LISTAR SECUENCIAS------------------"<<endl;
                cout<<"Usted ha solicitado listar las secuencias de ADN"<<endl;
                //Llamar a la funcion que lista las secuencias de ADN
                cout<<"---------------FIN LISTAR SECUENCIAS----------------"<<endl<<endl;
                break;

            case HISTOGRAMA:
                if(validarParametros(comando,numParametros) == true)
                 {
                    if(numParametros == 1)
                     {
                        cout<<"------------------HISTOGRAMA------------------"<<endl;
                        cout<<"Usted ha solicitado generar un histograma"<<endl;
                        //Llamar a la funcion que genera el histograma
                        cout<<"---------------FIN HISTOGRAMA----------------"<<endl<<endl;
                    }
                     else
                     {
                         cout<<"ERROR: El comando 'histograma' requiere un parametro."<<endl;
                     }
                 }
                break;

            case ES_SUBSECUENCIA:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 1)
                    {
                        cout<<"------------------ES SUBSECUENCIA------------------"<<endl;
                        cout<<"Usted ha solicitado verificar si una secuencia es subsecuencia de otra"<<endl;
                        //Llamar a la funcion que verifica si una secuencia es subsecuencia de otra
                        cout<<"---------------FIN ES SUBSECUENCIA----------------"<<endl<<endl;
                    }
                    else
                        {
                            cout<<"ERROR: El comando 'es_subsecuencia' requiere un parametro."<<endl;
                        }
                }
                break;

            case ENMASCARAR:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 1)
                    {
                        cout<<"------------------ENMASCARAR------------------"<<endl;
                        cout<<"Usted ha solicitado enmascarar una secuencia de ADN"<<endl;
                        //Llamar a la funcion que enmascara una secuencia de ADN
                        cout<<"---------------FIN ENMASCARAR----------------"<<endl<<endl;
                    }
                    else
                        {
                            cout<<"ERROR: El comando 'enmascarar' requiere un parametro."<<endl;
                        }
                }
                break;

            case GUARDAR:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 1)
                    {
                        cout<<"------------------GUARDAR------------------"<<endl;
                        cout<<"Usted ha solicitado guardar una secuencia de ADN"<<endl;
                        //Llamar a la funcion que guarda una secuencia de ADN
                        cout<<"---------------FIN GUARDAR----------------"<<endl<<endl;
                    }
                    else
                        {
                            cout<<"ERROR: El comando 'guardar' requiere un parametro."<<endl;
                        }
                }
                break;

            case CODIFICAR:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 1)
                    {
                        cout<<"------------------CODIFICAR------------------"<<endl;
                        cout<<"Usted ha solicitado codificar una secuencia de ADN"<<endl;
                        //Llamar a la funcion que codifica una secuencia de ADN
                        cout<<"---------------FIN CODIFICAR----------------"<<endl<<endl;
                    }
                    else
                        {
                             cout<<"ERROR: El comando 'codificar' requiere un parametro."<<endl;
                        }
                }
                break;

            case DECODIFICAR:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 1)
                    {
                        cout<<"------------------DECODIFICAR------------------"<<endl;
                        cout<<"Usted ha solicitado decodificar una secuencia de ADN"<<endl;
                        //Llamar a la funcion que decodifica una secuencia de ADN
                        cout<<"---------------FIN DECODIFICAR----------------"<<endl<<endl;
                    }
                    else
                        {
                             cout<<"ERROR: El comando 'decodificar' requiere un parametro."<<endl;
                        }
                }
                break;

            case RUTA_MAS_CORTA:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 5)
                    {
                        cout<<"------------------RUTA MAS CORTA------------------"<<endl;
                        cout<<"Usted ha solicitado encontrar la ruta mas corta entre dos secuencias de ADN"<<endl;
                        //Llamar a la funcion que encuentra la ruta más corta entre dos secuencias de ADN
                        cout<<"---------------FIN RUTA MAS CORTA----------------"<<endl<<endl;
                    }
                    else
                        {
                             cout<<"ERROR: El comando 'ruta_mas_corta' requiere un parametro."<<endl;
                        }
                }
                break;

            case BASE_REMOTA:
                if(validarParametros(comando,numParametros) == true)
                {
                    if(numParametros == 3)
                    {
                        cout<<"------------------BASE REMOTA------------------"<<endl;
                        cout<<"Usted ha solicitado acceder a una base de datos remota"<<endl;
                        //Llamar a la funcion que accede a una base de datos remota
                        cout<<"---------------FIN BASE REMOTA----------------"<<endl<<endl;
                    }
                    else
                        {
                             cout<<"ERROR: El comando 'base_remota' requiere un parametro."<<endl;
                        }
                }
                break;

            case SALIR:
                cout<<"------------------SALIR------------------"<<endl;
                cout<<"Usted ha solicitado salir del programa."<<endl;
                cout<<"Saliendo del programa..."<<endl;
                exit(1);

            default:
                cout << "------------------ERROR------------------" <<endl;
                cout << "Comando no valido. Escriba 'ayuda' para ver los comandos disponibles." << endl;
                cout << "---------------FIN ERROR----------------" << endl << endl;
                break;
            }
            //cout<<"Este es el comando seleccionado:" <<comando<<endl;
    }
    return 0;
}
