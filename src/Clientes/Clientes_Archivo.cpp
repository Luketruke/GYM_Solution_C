#include <iostream>

using namespace std;
#include "../include/Clientes/Clientes_Negocio.h"
#include "../include/Clientes/Clientes_Archivo.h"

Clientes_Archivo::Clientes_Archivo()
{
    for(int i=0; i<100; i++)
    {
        _nombreCompleto[i]= {';'};
    }
    for(int i=0; i<50; i++)
    {
        _direccion[i]= {';'};
    }
}

void Clientes_Archivo::setEstadoCliente(bool estado)
{
    _estado = estado;
}

void Clientes_Archivo::setCodigoCliente(int codigoCliente)
{
    _codigoCliente = codigoCliente;
}


void Clientes_Archivo::setDocumentoCliente(int documento)
{
    _documento = documento;
}

int Clientes_Archivo::getIDCliente()
{
    FILE* p;
    Clientes_Archivo reg;
    int i = 0, cont=1;
    p = fopen("Database/clientes.dat", "rb");

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

bool Clientes_Archivo::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/clientes.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Clientes_Archivo), 1, p))
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

bool Clientes_Archivo::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/clientes.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Clientes_Archivo) * pos, 0);

    if (fread(this, sizeof(Clientes_Archivo), 1, p))
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

bool Clientes_Archivo::modificarEnDisco(int pos)
{
    FILE* p;
    p = fopen("Database/clientes.dat", "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Clientes_Archivo) * pos, 0);

    if (fwrite(this, sizeof(Clientes_Archivo), 1, p))
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

