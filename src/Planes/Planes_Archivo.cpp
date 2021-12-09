#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace std;
#include "../include/Planes/Planes_Negocio.h"
#include "../include/Planes/Planes_Archivo.h"
#include "../include/Planes/Planes_Presentacion.h"

Planes_Archivo::Planes_Archivo()
{
}

void Planes_Archivo::setPrecio(float precio)
{
    _precio = precio;
}

void Planes_Archivo::setEstadoPlan(bool estado)
{
    _estado = estado;
}

void Planes_Archivo::setCodigoPlan(int codigoPlan)
{
    _codigoPlan = codigoPlan;
}

int Planes_Archivo::getIDPlan()
{
    FILE* p;
    Planes_Archivo reg;
    int i = 0, cont=1;
    p = fopen("Database/planes.dat", "rb");

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

bool Planes_Archivo::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/planes.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Planes_Archivo), 1, p))
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

bool Planes_Archivo::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/planes.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Planes_Archivo) * pos, 0);

    if (fread(this, sizeof(Planes_Archivo), 1, p))
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

bool Planes_Archivo::modificarEnDisco(int pos)
{
    FILE* p;
    p = fopen("Database/planes.dat", "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Planes_Archivo) * pos, 0);

    if (fwrite(this, sizeof(Planes_Archivo), 1, p))
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
