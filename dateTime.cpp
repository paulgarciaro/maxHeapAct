//
// Created by Paul García on 19/09/21.
//
#include "dateTime.h"
dateTime::dateTime() {
    dateStruct.tm_sec = 0;
    dateStruct.tm_min = 0;
    dateStruct.tm_hour = 0;
    dateStruct.tm_mday = 0;
    dateStruct.tm_mon = 1;
    dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
    // Obtener el Unix timestamp a partir del struct tm anterior
    date = mktime(&dateStruct);
}

dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos) {
    // Almacenar los campos de la fecha-hora en el struct tm
    dateStruct.tm_sec = segundos;
    dateStruct.tm_min = minutos;
    dateStruct.tm_hour = horas;
    dateStruct.tm_mday = dia;
    for (int i=0; i < meses.size(); i++) {
        if (meses[i]==mes)
            dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
    // Obtener el Unix timestamp a partir del struct tm anterior
    date = mktime(&dateStruct);
}

time_t dateTime::getDate() {
    return this -> date;
}

bool dateTime::operator==(const dateTime &other) {
    return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other) {
    return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other) {
    return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
    return this->date < other.date;
}


