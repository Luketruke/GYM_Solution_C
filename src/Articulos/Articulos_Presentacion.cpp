#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <vector>
#include <rlutil.h>
using namespace rlutil;
using namespace std;
#include "../include/Articulos/Articulos_Presentacion.h"
#include "../include/Articulos/Articulos_Negocio.h"
#include "../include/Stock/Stock_Presentacion.h"
#include "FuncionesExtras.h"

Articulos_Presentacion::Articulos_Presentacion()
{
}

///VISTAS

void Articulos_Presentacion::VistaCargarArticulo()
{
    system("cls");
    FuncionesExtras fx;
    Articulos_Negocio art_neg;

    char descripcionArticulo[100];
    float precio;

    if(ValidarDescripcionArticulo(descripcionArticulo))
    {
        precio = ValidarIngresoPrecio();
        if(art_neg.CargarArticulo(descripcionArticulo, precio))
           fx.CargaArticuloExitosa();
    }
}

void Articulos_Presentacion::MostrarArticulosVista()
{

    system("cls");

    Articulos_Negocio art_neg;
    FuncionesExtras fx;

    vector<Articulo> vArticulos;
    art_neg.obtenerRegistrosArticulos(vArticulos);
     int c=0;

    for(int i=0; i<vArticulos.size(); i++)
   {
        gotoxy(45,1+(5*c));
        cout<<"CODIGO: "<<vArticulos.at(i).getCodigo();
        gotoxy(45,1+(5*c+1));
        cout<<"ARTICULO: "<<vArticulos.at(i).getDescripcion();
        gotoxy(45,1+(5*c+2));
        cout<<"PRECIO: $"<<vArticulos.at(i).getPrecio();
        gotoxy(35,1+(5*c+3));
        setColor(LIGHTGREEN);
        cout<<"-----------------------------------------------";
        setColor(WHITE);
        c++;
    }
    system("pause>nul");
}

void Articulos_Presentacion::MostrarArticuloXCodigo(int codArt)
{
    Articulos_Negocio art_neg;
    Articulo a = art_neg.ObtenerDatosArticuloXCodigo(codArt);

    if(a.getCodigo()>0 && a.getCodigo() <99000)
    {

        cout<<"    CODIGO: "<<a.getCodigo()<<endl;
        cout<<"                                    ARTICULO: "<<a.getDescripcion()<<endl;
        cout<<"                                    PRECIO: $"<<a.getPrecio()<<endl;
    }
    else
        cout<<"                                  ARTICULO NO ENCONTRADO"<<endl;

    system("pause>nul");
}

void Articulos_Presentacion::VistaBajaArticulo()
{
    system("cls");
    Articulos_Negocio art_neg;
    int codArt;

    codArt = ValidarArticuloEliminar();

    if(art_neg.BajaArticulo(codArt)){

        gotoxy(37,15);
        setColor(LIGHTGREEN);
        cout<<"ARTICULO ELIMINADO CON EXITO";
        setColor(WHITE);
        }
    else{
        gotoxy(37,15);
    setColor(RED);
        cout<<"EL ARTICULO NO EXISTE...";
    setColor(WHITE);
    }
    system("pause>nul");
    system("cls");
}

///SUB MENU INICIO

void Articulos_Presentacion::SubMenuArticulosVista()
{
    Articulos_Presentacion art_vista;
    Stock_Presentacion st_vista;
    FuncionesExtras fx;

    int opcionSubMenus;
    do
    {
        fx.SubMenuArt();
        opcionSubMenus=fx.validarOpcionesMenu(5);

        switch(opcionSubMenus)
        {
        case 1:
            art_vista.VistaCargarArticulo();
            break;
        case 2:
            art_vista.MostrarArticulosVista();
            break;
        case 3:
            art_vista.VistaBajaArticulo();
            break;
        case 4:
            st_vista.ModificarStockVista();
            break;
        case 5:
            st_vista.MostrarStockVista();
            break;
        }
    }
    while(opcionSubMenus!=0);
}

///VALIDACIONES

float Articulos_Presentacion::ValidarIngresoPrecio()
{
    float precio;

    do
    {
        gotoxy(35,10);
        cout << "INGRESE PRECIO: $";
        fflush(stdin);
        cin>>precio;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            gotoxy(30, 18);
            setColor(RED);
            cout <<"INGRESO ERRONEO, INGRESE UN PRECIO VALIDO" << endl;
            system("pause>nul");
            setColor(WHITE);
            gotoxy(52, 10);
            cout<<"               ";
            gotoxy(30, 18);
            cout<<"                                                      ";

            continue;
        }
        else if(precio > 0)
        {
            break;
        }
        else
        {
            gotoxy(30, 18);
            setColor(RED);
            cout <<"INGRESO ERRONEO, INGRESE UN PRECIO VALIDO" << endl;
            system("pause>nul");
            setColor(WHITE);
            gotoxy(52, 10);
            cout<<"               ";
            gotoxy(30, 18);
            cout<<"                                                      ";
        }

    }
    while(true);

    return precio;
}

bool Articulos_Presentacion::ValidarDescripcionArticulo(char *descripcion)
{
    string input;
    FuncionesExtras fx;
    do
    {
        /*fx.Marco(2,1,0,35,35)*/
        fx.MarcoArt();
        gotoxy(35,9);
        cout << "INGRESE DESCRIPCION: ";
        fflush(stdin);
        std::getline(std::cin, input);

        if(input.size()<101)
        {
            strcpy(descripcion, input.c_str());
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100,'\n');
            setColor(RED);
            gotoxy(35,12);
            cout<<"INGRESO ERRONEO, INGRESE UNA DESCRIPCION VALIDA"<<endl;
            setColor(WHITE);
            system("pause>nul");
            system("cls");
            continue;
        }
    }
    while(true);
    return true;
}

int Articulos_Presentacion::ValidarArticuloEliminar()
{
    Articulos_Negocio art_neg;
    FuncionesExtras fx;

    int codArt;

    do
    {
        fx.Marco(1,2,1,35,35);
        gotoxy (37,9);

        cout << "   < CODIGO DE ART ELIMINAR >";
        gotoxy (74,11);
        cin>>codArt;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            gotoxy (37,15);
            cout << "INGRESO ERRONEO, INGRESE UN CODIGO DE ARTICULO VALIDO";
            system("pause>nul");
            gotoxy (74,11);
            cout<< "   ";
            continue;
        }
        else if(art_neg.ValidarCodigo(codArt))
            break;
        else
        {
            gotoxy (37,15);
            setColor(RED);
            cout<< "< INGRESE UN CODIGO DE ARTICULO EXISTENTE >";
            setColor(RED);
            system("pause>nul");
            gotoxy (74,11);
            cout<< "   ";
            gotoxy (37,15);
            setColor(WHITE);
            cout<<"                                             ";
        }
    }
    while(true);

    return codArt;
}
