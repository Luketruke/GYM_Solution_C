#include <iostream>

using namespace std;
#include "Item.h"

Item::Item()
{
}

void Item::setPrecio(float precio)
{
    _precio = precio;
}

void Item::setEstado(bool estado)
{
    _estado = estado;
}

void Item::setCodigo(int codigo)
{
    _codigo = codigo;
}
