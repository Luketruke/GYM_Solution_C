#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;
#include "../../include/Usuarios/Usuarios_Archivo.h"

Usuarios_Archivo::Usuarios_Archivo()
{
    _estado = true;
    _porcentajeXVenta = 0;
}

void Usuarios_Archivo::setCodigoUsuario(int codigoUsuario)
{
    _codigoUsuario = codigoUsuario;
}

void Usuarios_Archivo::setPorcentajeXVenta(float porcentajeXVenta)
{
    _porcentajeXVenta = porcentajeXVenta;
}

void Usuarios_Archivo::setTipoUsuario(int tipoUsuario)
{
    _tipoUsuario = tipoUsuario;
}

void Usuarios_Archivo::setEstadoUsuario(bool estado)
{
    _estado = estado;
}

int Usuarios_Archivo::getIDUsuario()
{
    FILE* p;
    Usuarios_Archivo reg;
    int i = 0, cont=1;
    p = fopen("Database/usuarios.dat", "rb");

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

bool Usuarios_Archivo::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/usuarios.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Usuarios_Archivo), 1, p))
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

bool Usuarios_Archivo::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/usuarios.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Usuarios_Archivo) * pos, 0);

    if (fread(this, sizeof(Usuarios_Archivo), 1, p))
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

bool Usuarios_Archivo::modificarEnDisco(int pos)
{
    FILE* p;
    p = fopen("Database/usuarios.dat", "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Usuarios_Archivo) * pos, 0);

    if (fwrite(this, sizeof(Usuarios_Archivo), 1, p))
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
