#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
#include "../../include/Fecha/Fecha.h"

Fecha::Fecha()
{
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
}

//Muestra la fecha en formato número. EJ: 15/10/2021
string Fecha::MostrarFecha()
{
    string fecha, _dia, _mes, _anio;

    ostringstream diaAux;
    diaAux<<dia;
    _dia = diaAux.str();

    ostringstream mesAux;
    mesAux<<mes;
    _mes = mesAux.str();

    ostringstream anioAux;
    anioAux<<anio;
    _anio = anioAux.str();

    if(dia<10)
    {
        fecha = {"0"};
        fecha+= _dia;
        fecha+= {"/"};
        fecha+= _mes;
        fecha+= {"/"};
        fecha+= _anio;
    }
    else
    {
        fecha+= _dia;
        fecha+= {"/"};
        fecha+= _mes;
        fecha+= {"/"};
        fecha+= _anio;
    }
    return fecha;
}


