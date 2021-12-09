#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace std;
#include "../include/Items_Facturas/Items_Facturas_Negocio.h"
#include "../include/Items_Facturas/Items_Facturas_Presentacion.h"
#include "../include/Items_Facturas/Items_Facturas_Archivo.h"
#include "../include/Articulos/Articulos_Archivo.h"
#include "../include/Planes/Planes_Archivo.h"

Items_Facturas_Negocio::Items_Facturas_Negocio()
{
}

bool Items_Facturas_Negocio::CargarItem(int idFactura,int categoriaItem,int codigoItem,
                                        int cantidad,float precio,float descuento,const char *nombrePlan)
{
    Items_Facturas_Archivo ifc_db;

    ifc_db.setIDFactura(idFactura);
    ifc_db.setCategoriaItem(categoriaItem);
    ifc_db.setCodigoItem(codigoItem);
    ifc_db.setCantidad(cantidad);
    ifc_db.setPrecioItem(precio);
    ifc_db.setDescuento(descuento);
    ifc_db.setDescripcionItem(nombrePlan);

    if(ifc_db.grabarEnDisco())
        return true;
    else
        return false;
}

bool Items_Facturas_Negocio::llenarValoresItem(int categoriaItem,
        int codigoItem, int cantidad, int idFactura)
{
    Items_Facturas_Presentacion ifc_vista;

    float precio, descuento=0.00;
    char nombrePlan[50];
    int i=0;

    precio = leerArchivoItems(nombrePlan,categoriaItem,codigoItem);
    descuento = ifc_vista.setDescuentoItem(precio);

    CargarItem(idFactura,categoriaItem,codigoItem,cantidad,precio,descuento,nombrePlan);
}

void Items_Facturas_Negocio::obtenerRegistrosItemsFacturas(vector<Item_Factura>& vItemsFacturas, int idFactura)
{
    Items_Facturas_Archivo ifc_db;

    int pos=0;

    while(ifc_db.leerDeDisco(pos))
    {
        if(ifc_db.getIDFactura()==idFactura)
        {
            Item_Factura ifc;

            ifc.setCodigo(ifc_db.getCodigoItem());
            ifc.setDescripcion(ifc_db.getDescripcionItem());
            ifc.setPrecio(ifc_db.getPrecio());
            ifc.setCantidad(ifc_db.getCantidad());
            ifc.setDescuento(ifc_db.getDescuento());
            ifc.setCategoriaItem(ifc_db.getCategoriaItem());
            ifc.setTotal((ifc_db.getPrecio()-ifc_db.getDescuento())*ifc_db.getCantidad());
            vItemsFacturas.push_back(ifc);
        }
        pos++;
    }
}

float Items_Facturas_Negocio::leerArchivoItems(char *descripcion, int categoria, int codigoItem)
{
    Articulos_Archivo art_db;
    Planes_Archivo plan_db;

    float precio = 0.00;
    int i=0;

    if(categoria==1)
    {
        while (plan_db.leerDeDisco(i)== true)
        {
            if(codigoItem==plan_db.getCodigoPlan())
            {
                precio=plan_db.getPrecio();
                strcpy(descripcion,plan_db.getNombrePlan());
                return precio;
            }
            i++;
        }
    }
    else if(categoria==2)
    {
        while (art_db.leerDeDisco(i)== true)
        {
            if(codigoItem==art_db.getCodigoArticulo())
            {
                precio=art_db.getPrecio();
                strcpy(descripcion,art_db.getDescripcionArticulo());
                return precio;
            }
            i++;
        }
    }
}
