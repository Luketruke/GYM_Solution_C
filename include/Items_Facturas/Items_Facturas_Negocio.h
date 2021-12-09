#ifndef ITEMS_FACTURAS_NEGOCIO_H
#define ITEMS_FACTURAS_NEGOCIO_H
#include <cstring>
#include "Item_Factura.h"

class Items_Facturas_Negocio
{
public:
    Items_Facturas_Negocio();

    bool llenarValoresItem(int,int,int,int);

    float leerArchivoItems(char *,int,int);

    bool CargarItem(int,int,int,int,float,float,const char*);

    void obtenerRegistrosItemsFacturas(vector<Item_Factura>&, int);

};

#endif // ITEMS_FACTURAS_NEGOCIO_H
