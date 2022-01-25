//
// Created by Paul García on 19/09/21.
//

#ifndef ACTINTEGRADORA_REGISTRO_H
#define ACTINTEGRADORA_REGISTRO_H
#include <iostream>
#include <string>
#include "dateTime.h"
using namespace std;

class registro {
private:
    string ip, falla, mes, hora;
    int dia;
    dateTime fecha;
    long ipInt;
public:
    registro();
    registro(string _mes, int _dia, string _hora, string _ip, string _falla);
    void setFecha(dateTime);
    void setIp(string);
    void setFalla(string);
    void setMes(string);
    void setDia(int);
    void setHora(string);
    dateTime getFecha();
    string getIp();
    string getFalla();
    string getLine();
    void imprimir();
    long ipToInt();
    long getipInt();
    bool operator ==(const registro&);
    bool operator !=(const registro&);
    bool operator >(const registro&);
    bool operator <(const registro&);
};


#endif //ACTINTEGRADORA_REGISTRO_H
