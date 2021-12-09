#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;
#include "../include/Articulos/Articulos_Negocio.h"
#include "../include/Articulos/Articulos_Archivo.h"
#include "../include/Stock/Stock_Database.h"
#include "../include/Stock/Stock_Negocio.h"
#include "../include/Articulos/Articulo.h"

Articulos_Negocio::Articulos_Negocio()
{
}

///CARGA REGISTROS EN ARCHIVO

bool Articulos_Negocio::CargarArticulo(const char *descripcionArticulo, float precio)
{
    Articulos_Archivo art_db;
    Stock_Database st_db;

    int codArt = art_db.getIDArticulo();
    bool validacion = false;

    art_db.setCodigoArticulo(codArt);
    art_db.setDescripcionArticulo(descripcionArticulo);
    art_db.setPrecio(precio);
    art_db.setEstado(true);

    if(art_db.grabarEnDisco())
        validacion=true;

    if(validacion==true)
    {
        st_db.setStock(0);
        st_db.setCodigoArticulo(codArt);
        if(st_db.grabarEnDisco())
            return true;
    }
}

void Articulos_Negocio::obtenerRegistrosArticulos(vector<Articulo>& vArticulos)
{
    Articulos_Archivo art_db;
    Stock_Negocio st_neg;

    int pos=0, idArticulo;

    while(art_db.leerDeDisco(pos))
    {
            if(art_db.getEstado()==true)
            {
                Articulo art;

                idArticulo = art_db.getCodigoArticulo();

                art.setCodigo(idArticulo);
                art.setDescripcion(art_db.getDescripcionArticulo());
                art.setPrecio(art_db.getPrecio());
                art.setStock(st_neg.ObtenerStockXArticulo(idArticulo));
                vArticulos.push_back(art);
            }
        pos++;
    }
}
bool Articulos_Negocio::ObtenerArticuloXCodigo(int idArticulo){
     Articulos_Archivo art_db;
    Stock_Negocio st_neg;
    Articulo art;

    int pos=0;

 while(art_db.leerDeDisco(pos))
    {
        if(idArticulo==art_db.getCodigoArticulo() && art_db.getEstado() == true)
        {
            art.setCodigo(art_db.getCodigoArticulo());
            art.setDescripcion(art_db.getDescripcionArticulo());
            art.setEstado(art_db.getEstado());
            art.setPrecio(art_db.getPrecio());
            art.setStock(st_neg.ObtenerStockXArticulo(idArticulo));
            return true;
        }
        pos++;
    }
    return false;

}
Articulo Articulos_Negocio::ObtenerDatosArticuloXCodigo(int idArticulo)
{
    Articulos_Archivo art_db;
    Stock_Negocio st_neg;
    Articulo art;

    int pos=0;

    while(art_db.leerDeDisco(pos))
    {
        if(idArticulo==art_db.getCodigoArticulo() && art_db.getEstado() == true)
        {
            art.setCodigo(art_db.getCodigoArticulo());
            art.setDescripcion(art_db.getDescripcionArticulo());
            art.setEstado(art_db.getEstado());
            art.setPrecio(art_db.getPrecio());
            art.setStock(st_neg.ObtenerStockXArticulo(idArticulo));
        }
        pos++;
    }
    return art;
}

bool Articulos_Negocio::BajaArticulo(int codArt)
{
    Articulos_Archivo art_db;

    int i= 0;

    while (art_db.leerDeDisco(i)== true)
    {
        if(art_db.getCodigoArticulo()==codArt && art_db.getEstado()==true)
        {
            art_db.setEstado(false);
            if(art_db.modificarEnDisco(i))
                return true;
        }
        i++;
    }
    return false;
}

bool Articulos_Negocio::ValidarCodigo(int codArt)
{
    Articulos_Archivo art_db;

    int i=0;

    while(art_db.leerDeDisco(i))
    {
        while(art_db.getCodigoArticulo()==codArt)
        {
            return true;
        }
        i++;
    }
    return false;
}
