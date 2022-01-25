//
// Created by Paul García on 11/10/21.
//

#ifndef ACTINTEGRAL3_4_BITACORA_H
#define ACTINTEGRAL3_4_BITACORA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "registro.h"
#include "dateTime.h"
#include "MaxHeap.h"
#include "IP.h"

using namespace std;

class Bitacora {
private:
    vector<registro> bit;
    MaxHeap<registro> bitHeap;
    int size;
public:
    Bitacora();
    void leerDatos(); //Complejidad O(n)
    void sort(); //Complejidad O(n log n)
    void crearBitacoraOrdenada(); //Complejidad O(n)
    void ipsMayorAcceso();// Complejidad O(n)
};

Bitacora::Bitacora() {
    this -> size = (bit.size()-1);
    bitHeap.setCapacity(17000);
}

//Complejidad O(n)
void Bitacora::leerDatos() {
  string mes, dia, hora, ip, razon, razon1, razon2, razon3, razon4, razon5, line;
  ifstream infile("bitacoraHeap.txt");
  int i = 0;
  if(infile.is_open()){
    while (getline(infile, line)) {
        istringstream ss(line);

        ss >> mes >> dia >> hora >> ip >> razon >> razon1 >> razon2 >> razon3 >> razon4 >> razon5;

        string razonFinal;
        razonFinal = razon + " " + razon1 + " " + razon2 + " " + razon3 + " " + razon4 + " " + razon5;

        string hh = hora.substr(0, 2);
        string mm = hora.substr(3, 2);
        string ssg = hora.substr(6, 2);
        string ads = ip.substr(0, ip.find(":"));
        string pto = ip.substr(ip.find(":") + 1, 6);
        registro bitT(mes, stoi(dia), hora, ip, razonFinal);
        bit.push_back(bitT);
        i++;
    }
    this -> size = (bit.size()-1);
    infile.close();
  }else{
    std::cout << "El archivo no ha abierto correctamente" << std::endl;
  }if(!infile.is_open()){
    std::cout << "El archivo 'bitacoraHeap.txt' ha cerrado correctamente\n";
  }
}

//Complejidad O(n log n)
void Bitacora::sort() {
  int c = 0;
  while(c<=this->size){
    bitHeap.push(bit[c]);
    c++;
  }
}

//Complejidad O(n)
void Bitacora::crearBitacoraOrdenada() {
  int contador = 1;
  MaxHeap<IP> masAccesos;
  masAccesos.setCapacity(17000);
  ofstream bitOrdenada("bitacora_ordenada.txt");
  ofstream ipsMayorAcceso("ips_con_mayor_acceso.txt");
  string lineaRegistro;
  long ipA = bitHeap.top().getipInt();
  long ipN;
  string ipAnterior = bitHeap.top().getIp();
  if(bitOrdenada.is_open()){
    for(int i = 0; i<=this->size; i++){
      ipN = bitHeap.top().getipInt();
      lineaRegistro = bitHeap.top().getLine();
      bitOrdenada << lineaRegistro << "\n";
      if(ipA==ipN){
        contador++;
      }else{
        IP newIP(ipAnterior, contador);
        masAccesos.push(newIP);
        contador = 1;
      }
      ipA = ipN;
      ipAnterior = bitHeap.top().getIp();
      bitHeap.pop();
    }
    if(ipsMayorAcceso.is_open()){
      std::cout << "El archivo 'ips_con_mayor_acceso.txt' se ha creado correctamente\n";
      for(int i=0; i<5; i++){
      string registerLine = masAccesos.top().getAll();
      ipsMayorAcceso << registerLine << "\n";
      masAccesos.pop();
      }
    }else{
      std::cout << "El archivo con las ips con mayor acceso no se ha creado correctamente\n" << std::endl;
    }
  }else{
    std::cout << "El archivo con la bitácora ordenada no se ha creado correctamente\n";
  }
  bitOrdenada.close();
  if(!bitOrdenada.is_open()){
    std::cout << "El archivo 'bitacora_ordenada.txt' ha cerrado correctamente\n";
  }else{
    std::cout<<"WARN: El archivo 'bitacora_ordenada.txt' no ha cerrado correctamente\n";
  }
  ipsMayorAcceso.close();
  if(!ipsMayorAcceso.is_open()){
    std::cout << "El archivo 'ips_con_mayor_acceso.txt' ha cerrado correctamente\n";
  }else{
    std::cout<<"WARN: El archivo 'ips_con_mayor_acceso.txt' no ha cerrado correctamente\n";
  }
}

void Bitacora::ipsMayorAcceso(){
  ifstream infile("ips_con_mayor_acceso.txt");
  string line;
  if(infile.is_open()){
    //format: IP: 10.15.187.246:4668 Occurrences: 37
    std::cout << "IP's con más accesos (ignorar los puertos): \n";
    for(int i=0; i<5; i++) {
      getline(infile, line);
      std::cout << line << std::endl;
      }
  }else{
    std::cout << "El archivo 'ips_con_mayor_acceso.txt' no ha abierto correctamente\n";
  }
  infile.close();
  if(!infile.is_open()){
    std::cout << "El archivo 'ips_con_mayor_acceso.txt' ha cerrado correctamente\n";
  }else{
    std::cout << "WARN: El archivo 'ips_con_mayor_acceso.txt' no ha cerrado correctamente\n";
  }
}
#endif //ACTINTEGRAL3_4_BITACORA_H