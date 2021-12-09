#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>
#include <vector>
using namespace rlutil;
using namespace std;
#include "../../include/Usuarios/Usuario.h"
#include "../../include/Usuarios/Usuarios_Presentacion.h"
#include "../../include/Usuarios/Usuarios_Negocio.h"
#include "../../include/FuncionesExtras.h"

Usuarios_Presentacion::Usuarios_Presentacion()
{
}

enum Opciones
{
    User=3,
    Password=4
};

void Usuarios_Presentacion::CargarUsuarioVista()
{
    FuncionesExtras fx;
    Usuarios_Negocio user_neg;
    Usuarios_Presentacion user_vista;

    string passValidar;
    char user[30], pass[30], nombreCompleto[100];
    int codigoUsuario, tipoUsuario;
    float porcentajeXVenta;

    tipoUsuario = ValidarTipoVendedor();
    gotoxy(37,14);
    setColor(WHITE);
    cout << "--INGRESE USUARIO--";
    setColor(LIGHTGREEN);
    gotoxy(37,15);
    cin >> user;
    gotoxy(37,16);
    setColor(WHITE);
    cout << "--INGRESE PASSWORD-- ";
    gotoxy(37,17);
    setColor(LIGHTGREEN);
    cin >> pass;
    setColor(WHITE);
    gotoxy(37,18);
    cout << "--INGRESE NUEVAMENTE LA PASSWORD-- ";
    gotoxy(37,19);
    setColor(LIGHTGREEN);
    cin >> passValidar;
    if(user_vista.ValidarNombreCompleto(nombreCompleto))
    {
        if(tipoUsuario==3)
        {
            porcentajeXVenta=user_vista.ValidarPorcentajeXVenta();
        }
        if(pass==passValidar)
        {
            if(user_neg.CargarUsuario(user, pass, passValidar, nombreCompleto, codigoUsuario, tipoUsuario, porcentajeXVenta))
                fx.CargaUsuarioExitosa(user, pass, nombreCompleto);
        }
        else
        {
            gotoxy(34,25);
            setColor(RED);
            cout<<"<<< LAS PASSWORD NO COINCIDEN  >>>";
            gotoxy(28,17);
            std::cout <<"Check "<<(char) 175<<(char)175;
            gotoxy(28,19);
            std::cout <<"Check "<<(char) 175<<(char)175;
            system("pause>nul");
            system("cls");
        }
    }
}

bool Usuarios_Presentacion::IngresarUsuario()
{
    FuncionesExtras fx;
    Usuarios_Negocio user_neg;

    string user, pass;
    int y=0;

    fx.Marco(4,1,2,35,35);
    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);

    fx.showInput("USUARIO: ", 45, 10, y == User);
    fx.showInput("PASSWORD: ", 45, 11, y == Password);

    rlutil::locate(51, 10 + y);
    cin >> user; //USUARIO
    rlutil::locate(52, 11 + y);
    cin >> pass; //CONTRASENIA
    if(user_neg.ValidarIngresoUsuario(user, pass))
        return true;
    else
        return false;
}

void Usuarios_Presentacion::MostrarVendedoresVista()
{
    Usuarios_Negocio user_neg;

    vector<Usuario> vUsuarios;

    user_neg.obtenerRegistrosUsuarios(vUsuarios);

    for(int i=0; i<vUsuarios.size(); i++)
    {
        if(vUsuarios.at(i).getTipoUsuario()==3)
        {
            cout<<"CODIGO: "<<vUsuarios.at(i).getCodigo()<<endl;
            cout<<"VENDEDOR: "<<vUsuarios.at(i).getNombreCompleto()<<endl;
            cout<<"-----------------------------------------------"<<endl;
        }
    }
}

void Usuarios_Presentacion::MostrarVendedorXCodigo(int codUsuario)
{
    Usuarios_Negocio user_neg;

    char nombreCompleto[50];

    Usuario user = user_neg.ObtenerDatosUsuarioXCodigo(codUsuario);

    cout<<"VENDEDOR: "<<user.getNombreCompleto()<<endl;

    system("pause>nul");
}

void Usuarios_Presentacion::MostrarUsuariosVista()
{
    system("cls");

    Usuarios_Negocio user_neg;
    int c=0;
    vector<Usuario> vUsuarios;
    user_neg.obtenerRegistrosUsuarios(vUsuarios);

    for(int i=0; i<vUsuarios.size(); i++)
    {
        gotoxy(45,1+(5*c));
        cout<<"CODIGO: "<<vUsuarios.at(i).getCodigo();
        gotoxy(45,1+(5*c+1));
        cout<<"USUARIO: "<<vUsuarios.at(i).getUsuario();
        gotoxy(45,1+(5*c+2));
        cout<<"TIPO DE USUARIO: "<<vUsuarios.at(i).getNombreTipoUsuario();
        gotoxy(35,1+(5*c+3));
        setColor(LIGHTGREEN);
        cout<<"-----------------------------------------------";
        setColor(WHITE);
        c++;
    }
    system("pause>nul");
}

void Usuarios_Presentacion::BajaUsuario()
{
    FuncionesExtras fx;
    system("cls");
    Usuarios_Negocio user_neg;
    int cod;
    fx.Marco(1,2,1,35,35);
    gotoxy(37,9);
    cout << " <INGRESE CODIGO USUARIO>";
    gotoxy(74,11);
    cin >> cod;

    if(user_neg.BajaLogicaUsuario(cod))
    {
        gotoxy(34,18);
        setColor(LIGHTGREEN);
        cout<<"USUARIO ELIMINADO CON EXITO";
        setColor(WHITE);
    }
    else
    {
        gotoxy(34,18);
        setColor(RED);
        cout<<"EL USUARIO NO HA SIDO ELIMINADO";
        setColor(WHITE);
    }
    system("pause>nul");
}

void Usuarios_Presentacion::SubMenusUsuariosVista()
{
    system("cls");

    Usuarios_Presentacion user_vista;
    FuncionesExtras fx;

    int opcionSubMenus;

    do
    {
        fx.SubMenuUsuario();
        opcionSubMenus= fx.validarOpcionesMenu(3);
        switch(opcionSubMenus)
        {
        case 1:
            user_vista.CargarUsuarioVista();
            break;
        case 2:
            user_vista.MostrarUsuariosVista();
            break;
        case 3:
            user_vista.BajaUsuario();
            break;
        }
    }
    while(opcionSubMenus!=0);
}

bool Usuarios_Presentacion::ValidarNombreCompleto(char *nombreCompleto)
{
    char nombreValidar[100];
    bool noEsLetra;

    do
    {
        noEsLetra = false;
        gotoxy(37,20);
        setColor(WHITE);
        cout << "--INGRESE NOMBRE COMPLETO-- ";
        setColor(LIGHTGREEN);
        fflush(stdin);
        gotoxy(37,21);
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
            gotoxy(37,23);
            setColor(RED);
            cout<<"INGRESO ERRONEO, INGRESE UN NOMBRE VALIDO...";
            system("pause>nul");
            gotoxy(37,21);
            cout<<"                                                   ";
            gotoxy(37,23);
            cout<<"                                                  ";
            continue;
        }
        else if(strlen(nombreValidar)<101 && noEsLetra==false)
        {
            strcpy(nombreCompleto, nombreValidar);
            break;
        }
        else

        {
            gotoxy(37,23);
            setColor(RED);
            cout<<"INGRESO ERRONEO, INGRESE UN NOMBRE VALIDO...";
            system("pause>nul");
            gotoxy(37,21);
            cout<<"                                                   ";
            gotoxy(37,23);
            cout<<"                                                  ";
            continue;
        }
    }
    while(true);

    if(noEsLetra==false)
        return true;
    else
        return false;
}

int Usuarios_Presentacion::ValidarTipoVendedor()
{
    system("cls");
    FuncionesExtras fx;
    int tipoVendedor;

    do
    {
        setColor(GREEN);
        gotoxy(30,7);
        cout << "   ----------------REGISTRO-------------"<<endl;
        setColor(WHITE);
        gotoxy(37,9);
        cout << "SELECCIONE TIPO DE USUARIO: "<<endl;
        gotoxy(37,10);
        cout <<"1. ADMINISTRADOR"<<endl;
        gotoxy(37,11);
        cout <<"2. ADMINISTRATIVO"<<endl;
        gotoxy(37,12);
        cout<< "3. VENDEDOR"<<endl;
        setColor(LIGHTGREEN);
        fx.Marco(4,1,1,35,35);
        cin>>tipoVendedor;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << endl << "INGRESO ERRONEO, INGRESE UN TIPO DE VENDEDOR EXISTENTE" << endl;
            system("pause>nul");
            continue;
        }
        else if(tipoVendedor>0 && tipoVendedor<4)break;
        else
        {
            gotoxy(31,15);
            setColor(RED);
            cout<<"INGRESO ERRONEO, INGRESE UN TIPO DE VENDEDOR CORRECTO...";
            setColor(WHITE);
            gotoxy(74,11);
            cout<<"   ";
            system("pause>nul");
            system("cls");
            continue;
        }
    }
    while(true);

    return tipoVendedor;
}

float Usuarios_Presentacion::ValidarPorcentajeXVenta()
{
    float pXventa = 0;

    do
    {
        gotoxy(37,22);
        setColor(WHITE);
        cout << "--SELECCIONE PORCENTAJE X VENTA-- ";
        gotoxy(37,23);
        setColor(LIGHTGREEN);
        cin >> pXventa;
        setColor(WHITE);

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            gotoxy(32,25);
            setColor(RED);
            cout<< "INGRESO ERRONEO, INGRESE UN PORCENTAJE X VENTA VALIDO...";
            system("pause>nul");
            gotoxy(32,25);
            cout<< "                                                         ";
            gotoxy(32,23);
            cout<< "                                                         ";
            continue;
        }
        else if(pXventa>=0 && pXventa <=100)
            break;
        else
        {
            gotoxy(32,25);
            setColor(RED);
            cout<< "INGRESO ERRONEO, INGRESE UN PORCENTAJE X VENTA VALIDO...";
            system("pause>nul");
            gotoxy(32,25);
            cout<< "                                                         ";
            gotoxy(32,23);
            cout<< "                                                         ";
            continue;
        }
    }
    while(true);

    return pXventa;
}
