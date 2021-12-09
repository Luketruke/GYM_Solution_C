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
#include "../include/Clientes/Clientes_Presentacion.h"
#include "../include/Clientes/Clientes_Negocio.h"
#include "../include/Clientes/Clientes_Archivo.h"
#include "../include/Clientes/Cliente.h"
#include "FuncionesExtras.h"
#include "Validaciones.h"

Clientes_Presentacion::Clientes_Presentacion()
{
}

int Clientes_Presentacion::CargarClientesVista(int v)
{
    Clientes_Negocio cl_neg;
    Clientes_Presentacion cl_vista;
    FuncionesExtras fx;

    char nombreCompleto[100], direccion[100];
    int documento, codCliente;

    if(v==0)
    {
        system("cls");
        fx.Marco(3,3,0,60,20);
    }

    if(cl_vista.ValidarNombreCompleto(nombreCompleto,v))
    {
        if(cl_vista.ValidarIngresoDocumento(documento, v))
        {
            if(cl_vista.ValidarDireccionCliente(direccion, v))
            {
                codCliente = cl_neg.CargarCliente(documento,nombreCompleto,direccion);
                if(codCliente>0)
                {
                    gotoxy(34,13);
                    setColor(LIGHTGREEN);
                    cout <<"< CLIENTE AGREGADO CON EXITO >";
                    setColor(WHITE);
                    system("pause>nul");
                    return codCliente;
                }
            }
        }
    }
    gotoxy(34,18);
    setColor(RED);
    cout << "HUBO UN ERROR AL CARGAR EL CLIENTE";
    setColor(WHITE);
    system("pause>nul");
}

void Clientes_Presentacion::MostrarClientesVista()
{
    system("cls");

    Clientes_Negocio cl_neg;

    vector<Cliente> vClientes;
    cl_neg.obtenerRegistrosClientes(vClientes);
    int c=0;

    for(int i=0; i<vClientes.size(); i++)
    {
        gotoxy(45,1+(5*c));
        cout<<"CODIGO: "<<vClientes.at(i).getCodigo();
        gotoxy(45,1+(5*c+1));
        cout<<"CLIENTE: "<<vClientes.at(i).getNombreCompleto();
        gotoxy(45,1+(5*c+2));
        cout<<"DOCUMENTO: "<<vClientes.at(i).getDocumento();
        gotoxy(45,1+(5*c+3));
        cout<<"DIRECCION: "<<vClientes.at(i).getDireccion();
        gotoxy(35,1+(5*c+4));
        setColor(LIGHTGREEN);
        cout<<"-----------------------------------------------";
        setColor(WHITE);
        c++;
    }

    system("pause>nul");
}

int Clientes_Presentacion::ClienteEnFactura()
{
    Clientes_Presentacion cl_vista;
    Clientes_Negocio cl_neg;

    int codCliente, opcion;

    cout <<"CLIENTE NUEVO O EXISTENTE? N/E ";
    opcion = ValidarOpcionCliente();

    if(opcion=='n')
    {

        codCliente = cl_vista.CargarClientesVista(1);

    }
    else if(opcion=='e')
    {
        codCliente=ValidarIngresoCodigo();

        Cliente cl = cl_neg.ObtenerDatosClientesXCodigo(codCliente);
        gotoxy(37,12);
        cout<<"CLIENTE: "<<cl.getNombreCompleto();
        gotoxy(37,13);
        cout<<"DOCUMENTO: "<<cl.getDireccion();
        gotoxy(37,14);
        cout<<"DIRECCION: "<<cl.getDocumento();
    }
    return codCliente;
}

void Clientes_Presentacion::BajaClienteVista()
{

    Clientes_Negocio cl_neg;

    int codCliente;


    codCliente=ValidarIngresoCodigo();

    if(cl_neg.BajaClienteValidar(codCliente))
    {
        gotoxy(34,18);
        setColor(LIGHTGREEN);
        cout<<"< CLIENTE ELIMINADO CON EXITO >";
        setColor(WHITE);
    }
    else
    {
        gotoxy(34,18);
        setColor(RED);
        cout<<"< EL CLIENTE NO HA SIDO ELIMINADO >";
        setColor(WHITE);
    }
    system("pause>nul");
    system("cls");
}

void Clientes_Presentacion::SubMenuClientesVista()
{
    Clientes_Presentacion cl_vista;
    FuncionesExtras fx;
    int opcionSubMenus;

    do
    {
        fx.SubMenuCliente();
        opcionSubMenus=fx.validarOpcionesMenu(3);

        switch(opcionSubMenus)
        {
        case 1:
            cl_vista.CargarClientesVista(0);
            break;
        case 2:
            cl_vista.MostrarClientesVista();
            break;
        case 3:
            system("cls");
            cl_vista.BajaClienteVista();
            break;
        }
    }
    while(opcionSubMenus!=0);

    system("cls");
}

int Clientes_Presentacion::ValidarIngresoCodigo()
{
    Clientes_Negocio cl_neg;
    FuncionesExtras fx;
    int cliente;
    system("cls");
    do
    {
        fx.Marco(1,2,1,35,35);
        gotoxy(35,9);
        cout << " < INGRESAR CODIGO DE CLIENTE >";
        gotoxy(74,11);
        cin>>cliente;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            setColor(RED);
            gotoxy(34,18);
            cout <<"ERROR, INGRESE UN CODIGO DE CLIENTE VALIDO";
            setColor(WHITE);
            system("pause>nul");

            continue;
        }
        else if(cl_neg.ValidarCliente(cliente))
            break;
        else
        {
            setColor(RED);
            gotoxy(34,18);
            cout<<" < INGRESE UN CLIENTE EXISTENTE >";
            setColor(WHITE);
            system("pause>nul");
        }
        system("cls");
    }
    while(true);

    return cliente;
}

bool Clientes_Presentacion::ValidarIngresoDocumento(int &documento, int esFactura)
{
    Clientes_Negocio cl_neg;

    bool valido = false;

    do
    {
        if(esFactura==1)
            gotoxy(33,10);
        else
            gotoxy(20,10);
        cout <<"> DOCUMENTO: ";
        fflush(stdin);
        cin>>documento;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1,'\n');
            gotoxy(34,18);
            setColor(RED);
            cout << "ERROR, INGRESE UN DOCUMENTO VALIDO";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(33,10);
            cout<< "                                               ";
            gotoxy(34,18);
            cout<< "                                               ";
            gotoxy(67,10);
            cout<< "                                                      ";
            continue;
        }
        else if(cl_neg.ValidarDocumento(documento)==1)
        {
            valido=true;
            break;
        }
        else if(cl_neg.ValidarDocumento(documento)==2)
        {
            gotoxy(34,18);
            setColor(RED);
            cout<<"ERROR, EL DOCUMENTO YA EXISTE";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(34,18);
            cout<< "                                               ";
            gotoxy(67,10);
            cout<< "                                                      ";
        }
        else
        {
            gotoxy(34,18);
            setColor(RED);
            cout <<"ERROR, INGRESE UN DOCUMENTO VALIDO";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(34,18);
            cout<< "                                               ";
            gotoxy(67,10);
            cout<< "                                                      ";
        }
    }
    while(true);

    if(valido)
        return true;
    else
        return false;
}

char Clientes_Presentacion::ValidarOpcionCliente()
{
    string opcion;

    do
    {
        cin>>opcion;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1,'\n');
            cout << endl << "INGRESO ERRONEO, INGRESE UNA OPCION VALIDA!" << endl;
            system("pause>nul");
            continue;
        }
        else if(opcion.length()==1)
        {
            opcion = tolower(opcion[0]);
            if(opcion[0] == 'n' || opcion[0] == 'e')
                break;
        }
        else
        {
            cout<<endl<<"ERROR, INGRESE UNA OPCION VALIDA"<<endl;
            system("pause>nul");
        }
    }
    while(true);

    return opcion[0];
}

bool Clientes_Presentacion::ValidarDireccionCliente(char *direccion, int esFactura)
{
    string input;

    do
    {
        if(esFactura==1)
            gotoxy(33,11);
        else
            gotoxy(20,11);
        cout << "> DIRECCION: ";
        fflush(stdin);
        std::getline(std::cin, input);

        if(input.size()<101)
        {
            strcpy(direccion, input.c_str());
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100,'\n');
            gotoxy(34,18);
            setColor(RED);
            cout<<"ERROR, INGRESE UNA DIRECCION VALIDA";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(53,11);
            cout<<"                                                         ";
            gotoxy(34,18);
            cout<<"                                                         ";
            continue;
        }

    }
    while(true);
    return true;
}

bool Clientes_Presentacion::ValidarNombreCompleto(char *nombreCompleto, int esFactura)
{
    FuncionesExtras fx;
    char nombreValidar[100];
    bool noEsLetra;

    if(esFactura==1)
        system("cls");

    do
    {
        fx.Marco(3,1,2,35,34);
        noEsLetra = false;
        if(esFactura==1)
            gotoxy(33,9);
        else
            gotoxy(20,9);
        cout << "> NOMBRE COMPLETO: ";
        fflush(stdin);
        cin.getline(nombreValidar, 100);

        for(int i=0; i<strlen(nombreValidar); i++)
        {
            int uppercaseChar = toupper(nombreValidar[i]);
            if (uppercaseChar < 'A' || uppercaseChar > 'Z')
            {
                if(nombreValidar[i]!=' ')
                    noEsLetra = true;
            }
        }
        if(noEsLetra==true)
        {
            gotoxy(34,18);
            setColor(RED);
            cout<<"ERROR, INGRESE UN NOMBRE VALIDO";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(35,9);
            cout<<"                                ";
            gotoxy(34,18);
            cout<<"                                                ";
            continue;
        }
        else if(strlen(nombreValidar)<101 && noEsLetra==false)
        {
            strcpy(nombreCompleto, nombreValidar);
            break;
        }
        else
        {
            gotoxy(34,18);
            setColor(RED);
            cout<<"ERROR, INGRESE UN NOMBRE VALIDO"<<endl;
            setColor(WHITE);
            system("pause>nul");
            gotoxy(60,9);
            cout<<"                                                ";
            gotoxy(34,18);
            cout<<"                                                ";
            continue;
        }
    }
    while(true);

    if(noEsLetra==false)
        return true;
    else
        return false;
}
