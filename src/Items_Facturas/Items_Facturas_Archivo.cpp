#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace std;
#include "../include/Items_Facturas/Items_Facturas_Archivo.h"

Items_Facturas_Archivo::Items_Facturas_Archivo()
{
    _descuento = 0.00;
}

void Items_Facturas_Archivo::setCodigoItem(int codigoItem)
{
    _codigoItem = codigoItem;
}

void Items_Facturas_Archivo::setDescuento(float descuento)
{
    _descuento = descuento;
}

void Items_Facturas_Archivo::setPrecioItem(float precio)
{
    _precio = precio;
}

void Items_Facturas_Archivo::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}

void Items_Facturas_Archivo::setIDFactura(int idFactura)
{
    _idFactura = idFactura;
}

void Items_Facturas_Archivo::setCategoriaItem(int categoriaItem)
{
    _categoriaItem = categoriaItem;
}

bool Items_Facturas_Archivo::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/items_facturas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Items_Facturas_Archivo), 1, p))
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

bool Items_Facturas_Archivo::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/items_facturas.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Items_Facturas_Archivo) * pos, 0);

    if (fread(this, sizeof(Items_Facturas_Archivo), 1, p))
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
