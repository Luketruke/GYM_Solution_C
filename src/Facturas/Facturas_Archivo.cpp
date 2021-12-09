#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <rlutil.h>

using namespace std;
#include "../include/Facturas/Facturas_Archivo.h"
#include "Fecha/Fecha.h"

Facturas_Archivo::Facturas_Archivo()
{
    _descuento = 0.00;
    _totalFactura = 0.00;
}

void Facturas_Archivo::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

void Facturas_Archivo::setVendedor(int vendedor)
{
    _vendedor = vendedor;
}

void Facturas_Archivo::setSubtotalFactura(float subtotalFactura)
{
    _subtotalFactura = subtotalFactura;
}

void Facturas_Archivo::setTotalFactura(float totalFactura)
{
    _totalFactura = totalFactura;
}

void Facturas_Archivo::setComisiones(float comisiones)
{
    _comisionesVendedor = comisiones;
}

void Facturas_Archivo::setDescuento(float descuento)
{
    _descuento = descuento;
}

void Facturas_Archivo::setIDFactura(int idFactura)
{
    _idFactura = idFactura;
}

void Facturas_Archivo::setCodigoCliente(int codigoCliente)
{
    _codigoCliente = codigoCliente;
}

int Facturas_Archivo::getIDFactura()
{
    FILE* p;
    Facturas_Archivo reg;
    int i = 0, cont=1;
    p = fopen("Database/facturas.dat", "rb");

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

bool Facturas_Archivo::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/facturas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Facturas_Archivo), 1, p))
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

bool Facturas_Archivo::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/facturas.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Facturas_Archivo) * pos, 0);

    if (fread(this, sizeof(Facturas_Archivo), 1, p))
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
