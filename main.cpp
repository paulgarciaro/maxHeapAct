/* 
 Viernes, 5 de noviembre del 2021
 A01639631 Alan Paul García Rosales
 
 Compilacion para debug:  
    g++ -std=c++17 -g -o main *.cpp 
  Ejecucion con valgrind:
    valgrind --leak-check=full -v ./main
  
  Compilacion para ejecucion:  
    g++ -std=c++17 -O3 -o main *.cpp 
  Ejecucion:
    ./main
 
*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "dateTime.h"
#include "registro.h"
#include "Bitacora.h"
#include "MaxHeap.h"

using namespace std;

int main() {
    //Creamos un vector donde se guardaran los registros de la bitácora desordenada
    Bitacora binnacle;
    binnacle.leerDatos(); // Leemos los datos del archivo bitacora.txt
    binnacle.sort();//Funcion para ordenar la DoubleLinkedList de tipo registro
    binnacle.crearBitacoraOrdenada();//Funcion para crear el archivo con la bitacora ordenada
    binnacle.ipsMayorAcceso();
    return 0;
}
