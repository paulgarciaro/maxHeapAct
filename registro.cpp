//
// Created by Paul García on 19/09/21.
//

#include "registro.h"
#include <math.h>
#include <utility>

registro::registro() {
    this -> ip = "desconocido";
    this -> falla = "desconocida";
    this -> fecha = dateTime();
    this -> ipInt = 0;
}

registro::registro(string _mes, int _dia, string _hora, string _ip, string _falla) {
    this -> mes = _mes;
    this -> dia = _dia;
    this -> hora = _hora;
    this -> ip = _ip;
    this -> falla = _falla;
    std::string hh = hora.substr(0, 2);
    std::string mm = hora.substr(3, 2);
    std::string ssg = hora.substr(6, 2);
    dateTime _fecha(_mes, _dia, stoi(hh), stoi(mm), stoi(ssg));
    this -> fecha = _fecha;
    this -> ipInt = this -> ipToInt();
}

void registro::setFecha(dateTime _fecha) {
    this -> fecha = _fecha;
}

void registro::setIp(string _ip) {
    this -> ip = _ip;
}

void registro::setFalla(string _falla) {
    this -> falla = _falla;
}

dateTime registro::getFecha() {
    return this -> fecha;
}

string registro::getIp() {
    return this -> ip;
}

string registro::getFalla() {
    return this -> falla;
}

void registro::setMes(string _mes) {
    this -> mes = _mes;
}

void registro::setDia(int _dia) {
    this -> dia = _dia;
}

void registro::setHora(string _hora) {
    this -> hora = _hora;
}

//Complejidad O(n)
void registro::imprimir() {
    cout << this -> mes <<  " " << this -> dia << " " << this -> hora << " " << this -> ip << " " << this -> falla << endl;
}

//Complejidad O(n)
string registro::getLine() {
  string line;
  line += this->mes;
  line += " ";
  line += to_string(this->dia);
  line += " ";
  line += this -> hora;
  line += " ";
  line += this -> ip;
  line += " ";
  line += this -> falla;
  return line;
}

//Complejidad O(n)
long registro::ipToInt(){
  string ads;
  ads = ip.substr(0, ip.find(":"));
  long ip1 = stoi(ads.substr(0, ads.find(".")));
  ads = ads.erase(0, ads.find(".")+1);
  long ip2 = stoi(ads.substr(0, ads.find(".")));
  ads = ads.erase(0, ads.find(".")+1);
  long ip3 = stoi(ads.substr(0, ads.find(".")));
  ads = ads.erase(0, ads.find(".")+1);
  long ip4 = stoi(ads.substr(0, ads.find(":")));
  return ((ip1*pow(256,3))+(ip2*pow(256,2))+(ip3*pow(256,1))+(ip4*pow(256,0)));
}

//Complejidad O(1) para la sobrecarga de cada uno de los operadores
long registro::getipInt(){
  return this -> ipInt;
}

bool registro::operator==(const registro&other) {
    return this->ipInt == other.ipInt;
}

bool registro::operator!=(const registro&other) {
    return this->ipInt != other.ipInt;
}

bool registro::operator>(const registro&other) {
    return this->ipInt > other.ipInt;
}

bool registro::operator<(const registro&other) {
    return this->ipInt < other.ipInt;
}