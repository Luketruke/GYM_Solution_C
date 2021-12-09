#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;
#include "../include/Articulos/Articulos_Archivo.h"

Articulos_Archivo::Articulos_Archivo()
{
}

void Articulos_Archivo::setPrecio(float precio)
{
    _precio = precio;
}

void Articulos_Archivo::setEstado(bool estado)
{
    _estado = estado;
}

void Articulos_Archivo::setCodigoArticulo(int codigoArticulo)
{
    _codigoArticulo = codigoArticulo;
}

int Articulos_Archivo::getIDArticulo()
{
    FILE* p;
    Articulos_Archivo reg;
    int i = 0, cont=1;
    p = fopen("Database/articulos.dat", "rb");

    if (p == NULL)
    {
        return 1;
    }

    while (reg.leerDeDisco(i) == true)
    {
        i++;
        cont++;
    }
    fclose(p);
    return cont;
}

bool Articulos_Archivo::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/articulos.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Articulos_Archivo), 1, p))
    {
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}

bool Articulos_Archivo::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/articulos.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Articulos_Archivo) * pos, 0);

    if (fread(this, sizeof(Articulos_Archivo), 1, p))
    {
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}

bool Articulos_Archivo::modificarEnDisco(int pos){
    FILE* p;
    p = fopen("Database/articulos.dat", "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Articulos_Archivo) * pos, 0);

    if (fwrite(this, sizeof(Articulos_Archivo), 1, p))
    {
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}
