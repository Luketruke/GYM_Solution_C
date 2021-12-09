#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>
#include <iomanip>

using namespace rlutil;
using namespace std;

#include "../include/Articulos/Articulos_Negocio.h"
#include "../include/Stock/Stock_Presentacion.h"
#include "../include/Stock/Stock_Database.h"
#include "../include/Stock/Stock_Negocio.h"
#include "FuncionesExtras.h"

Stock_Presentacion::Stock_Presentacion()
{
}

void Stock_Presentacion::MostrarStockVista()
{
    system("cls");

    Articulos_Negocio art_neg;
    Stock_Negocio st_neg;

    int codArt;

    codArt = ValidarCodigoArticulo();

    Articulo a = art_neg.ObtenerDatosArticuloXCodigo(codArt);

    if(a.getCodigo()>0 && a.getCodigo()<2000){

        setColor(YELLOW);
        gotoxy(37,12);
        cout<<"CODIGO: "<<a.getCodigo();
        gotoxy(37,13);
        cout<<"ARTICULO: "<<a.getDescripcion();
        gotoxy(37,14);
        cout<<"STOCK: "<<a.getStock();
        setColor(WHITE);
    }

    else{
        gotoxy(37,18);
       setColor(RED);
        cout<<"ARTICULO NO ENCONTRADO";
         setColor(WHITE);
             }

    system("pause>nul");

    system("cls");
}

void Stock_Presentacion::ModificarStockVista()
{
    system("cls");

    Articulos_Negocio art_neg;
    Stock_Negocio st_neg;

    int codArt, newStock;

    codArt = ValidarCodigoArticulo();

    Articulo a = art_neg.ObtenerDatosArticuloXCodigo(codArt);

    if(a.getCodigo()>0 )
    if (art_neg.ObtenerArticuloXCodigo(codArt)){
    {
        gotoxy(37,13);
        cout<<"CODIGO: "<<a.getCodigo();
        gotoxy(37,14);
        cout<<"ARTICULO: "<<a.getDescripcion();
        gotoxy(37,15);
        cout<<"STOCK: "<<a.getStock();

        newStock = validarNuevoStock();

        if(st_neg.ModificarStock(codArt,newStock)){
            gotoxy(37,18);
            setColor(LIGHTGREEN);
            cout<<"EL STOCK SE HA MODIFICADO CON EXITO";
            setColor(WHITE);
            }
        else
        {


        gotoxy(37,18);
        setColor(RED);
            cout<<"EL STOCK NO SE HA MODIFICADO";
            setColor(WHITE);
             }
    }
    }
    else{
        gotoxy(37,18);
        setColor(RED);
        cout<<"ARTICULO NO ENCONTRADO";
       setColor(WHITE);
       }

    system("pause>nul");

    system("cls");
}

void Stock_Presentacion::DescontarStockVista(int codArt, int cant)
{
    Stock_Negocio st_neg;

    int stock;

    stock = cant*-1;
    if(st_neg.DescontarStock(codArt,stock))
        cout << setw(54) <<"STOCK DESCONTADO: "<< stock;
    else
        cout << setw(51) <<"<<EL STOCK NO SE HA DESCONTADO"<< endl;

    system("pause>nul");
}

int Stock_Presentacion::ValidarCodigoArticulo()
{
    Articulos_Negocio art_neg;
    FuncionesExtras fx;
    int codArt;

    do
    {
        fx.Marco(1,1,1,35,35);
        gotoxy(37,9);
        cout << "< INGRESE CODIGO DE ARTICULO >";
        gotoxy(74,11);
        cin>>codArt;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1,'\n');
            gotoxy(34,15);
            setColor(RED);
            cout << "INGRESO ERRONEO, INGRESE UN CODIGO VALIDO!";
            system("pause>nul");
            gotoxy(74,11);
            cout<< "   ";
            gotoxy(34,15);
            cout <<"                                            ";
            continue;
        }
        else
            break;
    }
    while(true);

    return codArt;
}

int Stock_Presentacion::validarNuevoStock()
{
    int stock;

    do
    {
        gotoxy(37,16);
        cout << "AGREGAR/RESTAR STOCK: ";
        cin >> stock;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            gotoxy(37,18);
            setColor(RED);
            cout <<"INGRESO ERRONEO, INGRESE UNA CANTIDAD DE STOCK VALIDA" ;
            setColor(WHITE);
            system("pause>nul");
            continue;
        }
        else
            break;

    }
    while(true);

    return stock;
}
