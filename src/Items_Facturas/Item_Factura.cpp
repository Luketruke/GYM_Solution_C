#include <iostream>

using namespace std;
#include "Items_Facturas/Item_Factura.h"

Item_Factura::Item_Factura()
{
}

void Item_Factura::setDescuento(float descuento)
{
    _descuento = descuento;
}

void Item_Factura::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}

void Item_Factura::setTotal(float total)
{
    _total = total;
}

void Item_Factura::setIDFactura(int idFactura)
{
    _idFactura = idFactura;
}

void Item_Factura::setCategoriaItem(int categoriaItem)
{
    _categoriaItem = categoriaItem;
}
