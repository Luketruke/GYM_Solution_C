#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <rlutil.h>
#include <vector>
#include <iomanip>

using namespace rlutil;
using namespace std;
#include "../include/Facturas/Facturas_Presentacion.h"
#include "../include/Facturas/Facturas_Negocio.h"
#include "../include/Facturas/Facturas_Archivo.h"
#include "../include/Facturas/Factura.h"
#include "../include/Usuarios/Usuarios_Presentacion.h"
#include "../include/Usuarios/Usuarios_Negocio.h"
#include "../include/Clientes/Clientes_Presentacion.h"
#include "../include/Clientes/Clientes_Negocio.h"
#include "../include/Clientes/Cliente.h"
#include "../include/Items_Facturas/Items_Facturas_Presentacion.h"
#include "../include/Items_Facturas/Items_Facturas_Negocio.h"
#include "../include/Items_Facturas/Items_Facturas_Archivo.h"
#include "../include/Fecha/Fecha.h"
#include "FuncionesExtras.h"

Facturas_Presentacion::Facturas_Presentacion()
{
}

void Facturas_Presentacion::VistaCargarFacturas()
{
    system("cls");

    Usuarios_Presentacion user_vista;
    Facturas_Presentacion fc_vista;
    Facturas_Negocio fc_neg;
    Items_Facturas_Presentacion ifc_vista;
    Clientes_Presentacion cl_vista;
    Fecha fecha;

    //VARIABLES CARGA FC
    float auxTotal = 0, descuento=0, pXVenta, comision=0, total=0;
    int vendedor, codCliente, dia, mes, anio, idFactura;
    string opcion, nro_fc;

    idFactura = fc_neg.obtenerIDFacturaActual();
    setColor(LIGHTGREEN);
    gotoxy (75,4);
    cout<<"EMPRESA: ZABALETT S.A." ;
    gotoxy (75,5);
    cout<<"SUCURSAL: LUKETRUKE" ;
    gotoxy (75,6);
    cout<<"DIRECCION: AV CAZON" ;
    gotoxy (75,7);
    cout<<"RESPONSABLE INSCRIPTO"<<endl;
    setColor(YELLOW);
    gotoxy(2,1);
    cout<<"   <<<   LISTA DE VENDEDORES    >>>  "<<endl;
    gotoxy(3,2);
    user_vista.MostrarVendedoresVista();
     setColor(WHITE);

    vendedor = fc_vista.IngresoVendedor();

    pXVenta = fc_neg.obtenerPorcentajeXVentaVendedor(vendedor);
    system("cls");
    gotoxy(34,9);
    cout<< "<<<------CARGA COMPROBANTE------>>>" ;
    gotoxy(37,10);
    nro_fc = fc_neg.CalcularNumeroFC(idFactura);
    gotoxy(37,11);
    cout << "NRO FACTURA: "<<nro_fc<<idFactura;
    gotoxy(37,12);
    cout<<"FECHA: "<<fecha.MostrarFecha();
    gotoxy(34,14);
    cout<<"  <<<------DATOS CLIENTE------>>>";
    gotoxy(37,16);
    codCliente = cl_vista.ClienteEnFactura();

    //ITEMS DE LA FACTURA

    ifc_vista.CargarItemsFacturas(idFactura);


    //CALCULO DE VALORES DE LA FACTURA

    auxTotal = ifc_vista.MostrarItemsFacturas(idFactura);

    cout <<endl << setw(47) <<"SUBTOTAL: $" << auxTotal;
    descuento = fc_vista.CargarDescuento(auxTotal);
    total = fc_neg.CalcularTotalFC(auxTotal,descuento);

    cout <<endl << setw(44) <<"TOTAL: $" << total ;
    system("pause>nul");
    comision = fc_neg.CalcularComision(total,pXVenta);
    if(fc_neg.CargarDatosFactura(auxTotal,descuento,total,vendedor,comision,codCliente,fecha,idFactura)){

        setColor(LIGHTGREEN);
        cout <<endl << endl << setw(61) <<"FACTURA CARGADA CON EXITO" ;
           setColor(WHITE);
           }
    else{

         setColor(RED);
         cout <<endl << setw(61) <<"LA FACTURA NO SE CARGO CORRECTAMENTE" ;
         setColor(WHITE);
     }
    system("pause>nul");
}

void Facturas_Presentacion::VistaMostrarFacturas()
{
    system("cls");

    Facturas_Negocio fc_neg;
    Clientes_Negocio cl_neg;

    string nro_fc;

    vector<Factura> vFacturas;
    fc_neg.obtenerRegistrosFacturas(vFacturas);

    for(int i=0; i<vFacturas.size(); i++)
    {
        nro_fc = fc_neg.CalcularNumeroFC(vFacturas.at(i).getIdFactura_Realizada());

        int dia = vFacturas.at(i).getDia();
        int mes = vFacturas.at(i).getMes();
        int anio = vFacturas.at(i).getAnio();

        cout<<"NRO FACTURA: "<<nro_fc<<vFacturas.at(i).getIdFactura_Realizada()<<endl;
        cout<<"FECHA: "<<fc_neg.MostrarFechasFacturas(dia,mes,anio)<<endl;
        cout<<"TOTAL FC: $"<<vFacturas.at(i).getTotal()<<endl;
        cout<<"CLIENTE: "<<vFacturas.at(i).getNombreCompletoCliente()<<endl;
        cout<<"DIRECCION: "<<vFacturas.at(i).getDireccionCliente()<<endl;
        cout<<"DOCUMENTO: "<<vFacturas.at(i).getDocumentoCliente()<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }

    system("pause>nul");
}

float Facturas_Presentacion::CargarDescuento(float totalFC)
{
    Facturas_Presentacion fc_vista;

    float descuento=0;
    string opcion;
    opcion = fc_vista.ValidarIngresoOpcion();

    if(opcion=="si")
    {
        descuento = ValidarIngresoDescuento(totalFC);
        return descuento;
    }
}

void Facturas_Presentacion::VistaExportToExcel()
{
    Facturas_Negocio fc_neg;

    system("cls");

    fc_neg.ExportToExcel();

    cout<<"REPORTADO EXPORTADO A EXCEL CON EXITO"<<endl;
    system("pause>nul");
}

void Facturas_Presentacion::MostrarFacturaDetallada()
{
    system("cls");

    Facturas_Presentacion fc_vista;
    FuncionesExtras fx;

    int cod;

    cod=fc_vista.ValidarIngresoCodigo();

    system("cls");

    fx.DibujarFactura(cod);

    system("pause>nul");
    system("cls");
}

void Facturas_Presentacion::VistaComisionesVendedores()
{
    system("cls");
    Facturas_Negocio fc_neg;
    Clientes_Negocio cl_neg;

    string nro_fc;

    vector<Factura> vFacturas;
    fc_neg.obtenerRegistrosFacturas(vFacturas);

    for(int i=0; i<vFacturas.size(); i++)
    {
        nro_fc = fc_neg.CalcularNumeroFC(vFacturas.at(i).getIdFactura_Realizada());

        int dia = vFacturas.at(i).getDia();
        int mes = vFacturas.at(i).getMes();
        int anio = vFacturas.at(i).getAnio();

        cout<<"NRO FACTURA: "<<nro_fc<<vFacturas.at(i).getIdFactura_Realizada()<<endl;
        cout<<"VENDEDOR: "<<vFacturas.at(i).getNombreCompletoVendedor() << endl;
        cout<<"FECHA: "<<fc_neg.MostrarFechasFacturas(dia,mes,anio)<<endl;
        cout<<"COMISION: $"<<vFacturas.at(i).getComisiones()<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }

    system("pause>nul");
}

void Facturas_Presentacion::SubMenuFacturasVista()
{
    system("cls");

    Facturas_Presentacion fc_vista;
    FuncionesExtras fx;

    int opcionSubMenus;

    do
    {
        fx.SubMenuFactura();
        opcionSubMenus=fx.validarOpcionesMenu(5);

        switch(opcionSubMenus)
        {
        case 1:
            fc_vista.VistaCargarFacturas();
            break;
        case 2:
            fc_vista.VistaMostrarFacturas();
            break;
        case 3:
            fc_vista.MostrarFacturaDetallada();
            break;
        case 4:
            fc_vista.VistaExportToExcel();
            break;
        case 5:
            fc_vista.VistaComisionesVendedores();
            break;
        }
    }
    while(opcionSubMenus!=0);
}

int Facturas_Presentacion::IngresoVendedor()
{
    Usuarios_Negocio user_neg;

    int vendedor;
    do
    {
        gotoxy(56,10);
        cout << "SELECCIONAR CODIGO VENDEDOR: ";
        fflush(stdin);
        cin>>vendedor;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(100,'\n');
            gotoxy(56,15);
            setColor(RED);
            cout << "INGRESO ERRONEO, INGRESE UN CODIGO DE VENDEDOR" ;
            setColor(WHITE);
            system("pause>nul");
            gotoxy(84,10);
            cout << "                  ";
             gotoxy(56,15);
            cout << "                                                " ;
            continue;
        }
        else if(user_neg.ValidarVendedor(vendedor))
            break;
        else
        {
            gotoxy(56,15);
            setColor(RED);
            cout<<"INGRESE UN VENDEDOR EXISTENTE";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(84,10);
            cout << "                  ";
            gotoxy(56,15);
            cout << "                                                " ;
        }
    }
    while(true);

    return vendedor;
}

string Facturas_Presentacion::ValidarIngresoOpcion()
{
    string opcion;
    do
    {
        cout <<endl << setw(55) <<"INGRESA DESCUENTO? ";
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
                cout <<endl << setw(55) <<"INGRESO ERRONEO, SELECCIONE UNA OPCION VALIDA" << endl;
                system("pause>nul");
                continue;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(2,'\n');
            cout <<endl << setw(55) <<"INGRESO ERRONEO, SELECCIONE UNA OPCION VALIDA" << endl;
            system("pause>nul");
            continue;
        }
    }
    while(true);
}

float Facturas_Presentacion::ValidarIngresoDescuento(float valor)
{
    float descuento;

    do
    {
        cout <<endl << setw(48) <<"DESCUENTO: $";
        fflush(stdin);
        cin>>descuento;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << endl << "                                       INGRESO ERRONEO, INGRESE UN DESCUENTO VALIDO" << endl;
            system("pause>nul");
            continue;
        }
        else if((valor-descuento)>=0 && descuento > 0)
        {
            break;
        }
        else
        {
            cout << endl << "                                       INGRESO ERRONEO, INGRESE UN DESCUENTO VALIDO" << endl;
            system("pause>nul");
        }

    }
    while(true);

    return descuento;
}

int Facturas_Presentacion::ValidarIngresoCodigo()
{
    Facturas_Negocio fc_neg;
    FuncionesExtras fx;

    int idFactura;

    do
    {
        fx.Marco(1,1,1,35,35);
        gotoxy(37,9);
        cout << " < NGRESAR NUMERO DE FACTURA >";
        fflush(stdin);
        gotoxy(74,11);
        cin>>idFactura;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            setColor(RED);
            gotoxy(37,15);
            cout << "INGRESO ERRONEO, INGRESE UN NUMERO DE FACTURA VALIDO" ;
            setColor(WHITE);
            system("pause>nul");
            gotoxy(37,15);
            cout << "                                                     " ;
            gotoxy(74,11);
            cout << "   ";
            continue;
        }
        else if(fc_neg.ValidarFactura(idFactura))
            break;
        else
        {
            gotoxy(37,15);
            setColor(RED);
            cout<<"INGRESE UN NUMERO DE FACTURA EXISTENTE";
            setColor(WHITE);
             system("pause>nul");
            gotoxy(37,15);
            cout << "                                                     " ;
            gotoxy(74,11);
            cout << "   ";
        }
    }
    while(true);

    return idFactura;
}
