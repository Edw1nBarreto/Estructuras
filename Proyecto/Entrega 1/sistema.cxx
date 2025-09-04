
#include "sistema.h"
#include <fstream>
#include <iostream>
#include <vector>

void Sistema::cargarArchivo(std::string nombreArchivo) {
    // esto es para cargar el archivo
   std::ifstream archivo(nombreArchivo);
   if (!archivo.is_open()) {
       std::cerr << nombreArchivo << " no se encuentra o no puede leerse" << std::endl;
       return;
   }


   //limpiar vector de genomas
   genomas.clear();

   //si lo que entra en el archivo es un nuevo genoma, hay que crear un objeto genoma que se guarde 
   Genoma nuevoGenoma(nombreArchivo); 
   std::string nombreGenoma = nombreArchivo; // Asigna el nombre del genoma basado en el nombre del archivo
   std::string linea; //almacenar cada linea del archivo
   std::string descripcion = ""; //var temporal - contiene lo que va después de '>'
   std::string bases = ""; //var temporal - contiene ATCGGAT.... o sea, las bases

   int cantidadSecuencias = 0;

   while(std::getline(archivo, linea)) 
   { // Procesar cada línea del archivo
    if (linea.empty()) 
    {
        continue; // Saltar líneas vacías aunque no deberían tener (por si)
    }
       if (linea[0] == '>') //detecta inicio de nueva secuencia, es la primera letra de la línea actual 
       {
            // Si ya había una secuencia cargando, guardarla antes de iniciar la nueva
            if (!descripcion.empty()) //esto es para si hay más de 1 secuencia ya que la primera no cuenta
            {
                std::vector<char> vectorBases(bases.begin(), bases.end()); //convierte el string "bases" a un vector char
                Secuencia secuencia(descripcion, vectorBases); //crea un objeto secuencia
                nuevoGenoma.agregarSecuencia(secuencia);
                cantidadSecuencias++;
            }

            // Nueva secuencia
            descripcion = linea.substr(1); // Quitar '>' y guarda el nombre "Full_SEQUENCE"
            bases = ""; // Reiniciar bases
        } 
        else 
        {
            // Agregar las bases de la linea en la que esté
            bases += linea; //CTCCGGTGAGAAATTTT.... y esto CONCATENA, o sea, todo es la misma secuencia, las va uniendo hasta encontrar otro '>
        } //todavía no se guarda
    }

    // Guardar última secuencia
    if (!descripcion.empty()) //
    {
        std::vector<char> vectorBases(bases.begin(), bases.end());
        Secuencia secuencia(descripcion, vectorBases); //Crea la secuencia(Full_SEQUENCE, CTCCGGTGAGAAATTTT....GAAGCTATTA)
        nuevoGenoma.agregarSecuencia(secuencia);
        cantidadSecuencias++;
    }

    if (cantidadSecuencias == 0) // si no encontró ningún '>'
    {
        std::cout<< nombreArchivo<< " no contiene ninguna secuencia."<< std::endl;
        return;
    }

    genomas.push_back(nuevoGenoma);

    if (cantidadSecuencias == 1) {
        std::cout<< "1 secuencia cargada correctamente desde "<< nombreArchivo<< "." << std::endl;
    } 
    else 
    {
        std::cout<< cantidadSecuencias<< " secuencias cargadas correctamente desde "<< nombreArchivo<< "." << std::endl;
    }

    //recorrer el vector de genomas para ir imprimiendo las secuencias cargadas
    for(std::vector<Genoma>::const_iterator itGenoma = genomas.begin(); itGenoma != genomas.end(); ++itGenoma)
    {
        const std::vector<Secuencia> &secuencias = itGenoma->getSecuencias(); //obtiene el vector de secuencias por referencia
        int i = 1;

        //recorrer el vector de secuencias en el genoma actual
        for(std::vector<Secuencia>::const_iterator itSecuencia = secuencias.begin(); itSecuencia != secuencias.end(); ++itSecuencia)
        {
            std::cout << "Secuencia #" << i++ << ": " << itSecuencia->getDescripcion() << std::endl;
        }
    }
}

void Sistema::listarSecuencias() {

    if(genomas.empty())
    {
        std::cout<<"No hay genomas ni secuencias cargados en el sistema"<<std::endl;
        return; // Salir de la función si no hay genomas
    }

    std::cout<<"Resultado exitoso"<<std::endl;

    int totalSecuencias = 0;

    for (std::vector<Genoma>::const_iterator itGenoma = genomas.begin(); itGenoma != genomas.end(); ++itGenoma) 
    {
        totalSecuencias += itGenoma->getSecuencias().size();
    }
    //Mostrar total solo una vez
    std::cout<< "Hay " << totalSecuencias<< " secuencias cargadas en memoria"<< std::endl;

    //recorrer todos los genomas
    for(std::vector<Genoma>::const_iterator itGenoma = genomas.begin(); itGenoma != genomas.end(); ++itGenoma)
    {
        const std::vector<Secuencia> &secuencias = itGenoma->getSecuencias();

    //recorrer cada secuencia 
    for(std::vector<Secuencia>::const_iterator itSecuencia = secuencias.begin(); itSecuencia != secuencias.end(); ++itSecuencia)
    {
        int totalBases = 0;
        bool incompleta = false; //siempre serán completas de inicio

        const std::vector<char> &bases = itSecuencia->getBases(); //vector llamado bases

        for(char base: bases)
        {
            if(base == '-')
            {
                incompleta = true;
            }
            else
            {
                totalBases++;
            }
        }

        //mostrar todas las secuencias con sus totales de bases
        if (incompleta)
        {
            std::cout<<"Secuencia incompleta: "<< itSecuencia->getDescripcion()<<" contiene al menos "<<totalBases<<" bases"<<std::endl;
        }
            else
            {
                std::cout<<"Secuencia completa: "<< itSecuencia->getDescripcion()<<" contiene "<<totalBases<<" bases"<<std::endl;
            }

        }

    }
}

void Sistema::mostrarHistograma(std::string descripcion) {
    if (genomas.empty()) {
        std::cout << "No hay secuencias cargadas en memoria." << std::endl;
        return;
    }

    bool secuenciaEncontrada = false;
    std::vector<char> basesSecuencia; // Vector para almacenar las bases de la secuencia encontrada
    std::vector<char> ordenCodigos; // Vector para almacenar el orden de los códigos (en el orden que se hicieron push back es el orden en el que se imprimen).
    ordenCodigos.push_back('A');
    ordenCodigos.push_back('C');
    ordenCodigos.push_back('G');
    ordenCodigos.push_back('T');
    ordenCodigos.push_back('U');
    ordenCodigos.push_back('R');
    ordenCodigos.push_back('Y');
    ordenCodigos.push_back('K');
    ordenCodigos.push_back('M');
    ordenCodigos.push_back('S');
    ordenCodigos.push_back('W');
    ordenCodigos.push_back('B');
    ordenCodigos.push_back('D');
    ordenCodigos.push_back('H');
    ordenCodigos.push_back('V');
    ordenCodigos.push_back('N');
    ordenCodigos.push_back('X');
    ordenCodigos.push_back('-');

    std::vector<int> contadores(18, 0); // Vector para almacenar los contadores de cada código, inicializados en 0
    std::vector<Genoma>::iterator itGenoma = genomas.begin(); // Iterador para recorrer los genomas

    for (; itGenoma != genomas.end(); ++itGenoma) 
    {
        std::vector<Secuencia> secuencias = itGenoma->getSecuencias(); // Obtener el vector de secuencias del genoma actual
        std::vector<Secuencia>::iterator itSecuencia = secuencias.begin(); // Iterador para recorrer las secuencias del genoma actual

        for (; itSecuencia != secuencias.end(); ++itSecuencia) 
        {
            std::string descEncontrada = itSecuencia->getDescripcion(); // Obtener la descripción de la secuencia actual
            if (descEncontrada.find(descripcion) != std::string::npos) //IMPORTANTE:Si encuentra la descripción puesta como parámetro en la descripción de la secuencia  se entra al if
                //npos significa que no se encontró, al usar != significa que sí se encontró
            {
                basesSecuencia = itSecuencia->getBases();
                secuenciaEncontrada = true;
                break;
            }
        }
        if (secuenciaEncontrada) break;
    }

    if (!secuenciaEncontrada) {
        std::cout << "ERROR: No se encontro ninguna coincidencia" << std::endl;
        return;
    }

    std::vector<char>::iterator itEncontrada; 
    std::vector<char>::iterator itBase = basesSecuencia.begin();

    for (; itBase != basesSecuencia.end(); ++itBase) 
    {
        char base = *itBase;
        itEncontrada = ordenCodigos.begin();
        std::vector<int>::iterator itContador = contadores.begin();

        for (; itEncontrada != ordenCodigos.end(); ++itEncontrada, ++itContador) 
        {
            if (*itEncontrada == base) {
                (*itContador)++;
                break;
            }
        }
    }
    std::vector<char>::iterator itCodigo = ordenCodigos.begin();
    std::vector<int>::iterator itContador = contadores.begin();

    for (; itCodigo != ordenCodigos.end() && itContador != contadores.end(); ++itCodigo, ++itContador)  //hasta que no se acabe el vector de (que recorra los 18 códigos)
    {
        std::cout << *itCodigo << " : " << *itContador << std::endl;
    }
}

void Sistema::buscarSubsecuencia(std::string subsecuencia) {
    // Implementación para buscar subsecuencia
}

void Sistema::enmascararSubsecuencia(std::string subsecuencia) {
    // Implementación para enmascarar subsecuencia
}

void Sistema::guardarArchivo(std::string nombreArchivo) {
    // Implementación para guardar archivo
}
