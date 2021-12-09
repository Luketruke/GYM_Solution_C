#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace std;
#include "../include/Stock/Stock_Negocio.h"
#include "../include/Stock/Stock_Database.h"
#include "../include/Stock/Stock_Presentacion.h"
#include "../include/Articulos/Articulos_Archivo.h"
#include "../include/Articulos/Articulos_Negocio.h"
#include "../include/Articulos/Articulos_Presentacion.h"

Stock_Negocio::Stock_Negocio()
{
}

bool Stock_Negocio::ModificarStock(int codArt, int stock)
{
    Articulos_Archivo a;

    Stock_Database st_db;

    int i=0;

    while (a.leerDeDisco(i))
    {
        if(a.getCodigoArticulo() == codArt)
        {
            st_db.setStock(stock);
            st_db.setCodigoArticulo(codArt);
            if(st_db.grabarEnDisco())
                return true;
        }
        i++;
    }
    return false;
}

int Stock_Negocio::ObtenerStockXArticulo(int codArt)
{
    Stock_Database st_db;

    int i=0, stock=0;

    while(st_db.leerDeDisco(i))
    {
        if(st_db.getCodigoArticulo()==codArt)
            stock+=st_db.getStock();
        i++;
    }
    return stock;
}

bool Stock_Negocio::DescontarStock(int cod, int stock)
{
    Stock_Database st_db;

    st_db.setStock(stock);
    st_db.setCodigoArticulo(cod);
    if(st_db.grabarEnDisco())
        return true;
    else
        return false;
}
