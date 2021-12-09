#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace rlutil;
using namespace std;
#include "../include/Items_Facturas/Items_Facturas_Negocio.h"
#include "../include/Items_Facturas/Items_Facturas_Presentacion.h"
#include "../include/Items_Facturas/Items_Facturas_Archivo.h"
#include "../include/Items_Facturas/Item_Factura.h"
#include "../include/Facturas/Facturas_Presentacion.h"
#include "../include/Articulos/Articulos_Presentacion.h"
#include "../include/Articulos/Articulos_Negocio.h"
#include "../include/Planes/Planes_Presentacion.h"
#include "../include/Planes/Planes_Negocio.h"
#include "../include/Stock/Stock_Presentacion.h"
#include "../include/Stock/Stock_Negocio.h"

Items_Facturas_Presentacion::Items_Facturas_Presentacion()
{
}

void Items_Facturas_Presentacion::CargarItemsFacturasVista(int idFactura)
{
    Items_Facturas_Negocio ifc_neg;
    Articulos_Presentacion art_vista;
    Planes_Presentacion pl_vista;

    int i=0, categoriaItem, codigoItem, cantidad;
    string opcion;

    categoriaItem = ValidarCategoriaItem();

    if(categoriaItem==1)
    {
        codigoItem=ValidarCodigoPlan();
        cout << endl;
        pl_vista.MostrarPlanXCodigo(codigoItem);
        cantidad=ValidarCantidad();
        ifc_neg.llenarValoresItem(categoriaItem,codigoItem,cantidad,idFactura);
    }
    if(categoriaItem==2)
    {
        codigoItem=ValidarCodigoArticulo();
        cout << endl<< "                                ";
        art_vista.MostrarArticuloXCodigo(codigoItem);
        cantidad=ValidarCantidad();
        ifc_neg.llenarValoresItem(categoriaItem,codigoItem,cantidad,idFactura);
    }
}

void Items_Facturas_Presentacion::CargarItemsFacturas(int idFactura)
{
    Items_Facturas_Presentacion ifc_vista;
    string opcion;
    do
    {
        ifc_vista.CargarItemsFacturasVista(idFactura);
        opcion=ValidarIngresoOpcion();
    }
    while(opcion=="si");
}

float Items_Facturas_Presentacion::MostrarItemsFacturas(int &idFactura)
{
    Items_Facturas_Negocio ifc_neg;
    Stock_Presentacion st_vista;

    float totalFactura=0;
    string nro_fc;

    vector<Item_Factura> vItemFactura;
    ifc_neg.obtenerRegistrosItemsFacturas(vItemFactura,idFactura);

    for(int i=0; i<vItemFactura.size(); i++)
    {
        cout << endl;
        cout << setw(49) <<"DESCRIPCION: "<<vItemFactura.at(i).getDescripcion()<<endl;
        cout << setw(54) <<"PRECIO UNITARIO: $" <<vItemFactura.at(i).getPrecio()<<endl;
        cout << setw(46) <<"CANTIDAD: "<<vItemFactura.at(i).getCantidad()<<endl;
        cout << setw(55) <<"DESCUENTO X ITEM: $"<<vItemFactura.at(i).getDescuento()<<endl;
        cout << setw(51) <<"PRECIO FINAL: $" <<vItemFactura.at(i).getTotal()<<endl;

        totalFactura+=vItemFactura.at(i).getTotal();

        if(vItemFactura.at(i).getCategoriaItem()==2)
        {
            st_vista.DescontarStockVista(vItemFactura.at(i).getCodigo(),vItemFactura.at(i).getCantidad());
            cout<<endl;
        }
    }
    return totalFactura;
}

float Items_Facturas_Presentacion::setDescuentoItem(float precioItem)
{
    Items_Facturas_Presentacion ifc_vista;
    Facturas_Presentacion fc_vista;

    float descuento;
    string opcion;

    opcion=ValidarIngresoOpcionDescuento();
    if(opcion=="si")
    {
        descuento= fc_vista.ValidarIngresoDescuento(precioItem);
    }
    return descuento;
}

int Items_Facturas_Presentacion::ValidarCategoriaItem()
{
    int categoriaItem;

    do
    {
        cout<<endl<<endl;
        cout << "                                    DESEA CARGA UN PLAN O UN ARTICULO? 1/2 ";
        fflush(stdin);
        cin >> categoriaItem;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout <<endl<< "INGRESO ERRONEO, INGRESE UNA CATEGORIA VALIDA" << endl;
            system("pause>nul");
            continue;
        }
        else if(categoriaItem==1 || categoriaItem==2)
            break;
        else
        {
            cout << endl << "INGRESO ERRONEO, INGRESE UNA CATEGORIA VALIDA" << endl;
            system("pause>nul");
        }
    }
    while(true);

    return categoriaItem;
}

int Items_Facturas_Presentacion::ValidarCodigoArticulo()
{
    Articulos_Negocio art_neg;

    int codArt;

    do
    {
        cout << "                                    INGRESE CODIGO DE ARTICULO: ";
        cin>>codArt;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            setColor(RED);
            cout << endl << "                                         INGRESO ERRONEO, INGRESE UN CODIGO DE ARTICULO VALIDO" << endl;
            setColor(WHITE);
            system("pause>nul");
            continue;
        }
        else if(art_neg.ValidarCodigo(codArt))
            break;
        else
        {
            setColor(RED);
            cout <<"                                          INGRESE UN CODIGO DE ARTICULO EXISTENTE" << endl;
             setColor(WHITE);
            system("pause>nul");
        }
    }
    while(true);

    return codArt;
}

int Items_Facturas_Presentacion::ValidarCodigoPlan()
{
    Planes_Negocio plan_neg;

    int codPlan;

    do{

        cout << "                                    INGRESE CODIGO DE PLAN: ";
        cin>>codPlan;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            setColor(RED);
            cout << endl << "                                     INGRESO ERRONEO, INGRESE UN CODIGO DE PLAN VALIDO" << endl;
            setColor(WHITE);
            system("pause>nul");
            continue;
        }
        else if(plan_neg.ValidarCodigo(codPlan))
            break;
        else
        {
            setColor(RED);
            cout<<endl<<"                                        INGRESE UN CODIGO DE PLAN EXISTENTE"<<endl;
            setColor(WHITE);
            system("pause>nul");
        }
    }
    while(true);

    return codPlan;
}

int Items_Facturas_Presentacion::ValidarCantidad()
{
    int cantidad;

    do{

        cout << endl << "                                    INGRESE CANTIDAD: ";
        fflush(stdin);
        cin>>cantidad;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << endl << "                                 INGRESO ERRONEO, INGRESE UNA CANTIDAD VALIDA" << endl;
            system("pause>nul");
            continue;
        }
        else if(cantidad>0)
            break;
        else
        {
            cout << endl << "                                 INGRESO ERRONEO, INGRESE UNA CANTIDAD VALIDA" << endl;
            system("pause>nul");
        }
    }
    while(true);

    return cantidad;
}

string Items_Facturas_Presentacion::ValidarIngresoOpcion()
{
    string opcion;

    do
    {
        cout << "                                    DESEA CARGAR OTRO ITEM? ";
        fflush(stdin);
        cin>>opcion;

        if(opcion.length()==2)
        {
            opcion[0]=tolower(opcion[0]);
            opcion[1]=tolower(opcion[1]);
            if (opcion=="si")
            {
                return opcion;
            }
            else if(opcion=="no")
            {
                return opcion;
            }
            else
            {
                cin.clear();
                cin.ignore(2,'\n');
                cout << endl << "                                                INGRESO ERRONEO, INGRESE UNA OPCION VALIDA" << endl;
                system("pause>nul");
                continue;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(2,'\n');
            cout << endl << "                                                    INGRESO ERRONEO, INGRESE UNA OPCION VALIDA" << endl;
            system("pause>nul");
            continue;
        }
    }
    while(true);
}


string Items_Facturas_Presentacion::ValidarIngresoOpcionDescuento()
{
    string opcion;

    do
    {
        cout<<"                                    DESEA INGRESAR DESCUENTO? ";
        fflush(stdin);
        cin>>opcion;

        if(opcion.length()==2)
        {
            opcion[0]=tolower(opcion[0]);
            opcion[1]=tolower(opcion[1]);
            if (opcion=="si")
            {
                return opcion;
            }
            else if(opcion=="no")
            {
                return opcion;
            }
            else
            {
                cin.clear();
                cin.ignore(2,'\n');
                cout << endl << "                                    INGRESO ERRONEO, INGRESE UNA OPCION VALIDA" << endl;
                system("pause>nul");
                continue;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(2,'\n');
            cout << endl << "                                        INGRESO ERRONEO, INGRESE UNA OPCION VALIDA" << endl;
            system("pause>nul");
            continue;
        }
    }
    while(true);
}
