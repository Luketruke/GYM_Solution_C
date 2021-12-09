#include <iostream>
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
#include "../include/Planes/Planes_Negocio.h"
#include "../include/Planes/Planes_Archivo.h"
#include "../include/Planes/Planes_Presentacion.h"
#include "../include/Planes/Plan.h"
#include "../include/Articulos/Articulos_Presentacion.h"
#include "FuncionesExtras.h"

Planes_Presentacion::Planes_Presentacion()
{
}

void Planes_Presentacion::CargarPlanVista()
{
    Planes_Negocio plan_neg;
    Articulos_Presentacion art_vista;

    char nombrePlan[100], infoPlan[1000];
    float precio;

    if(ValidarNombrePlan(nombrePlan))
    {
        precio = ValidarIngresoPrecio();

        if(ValidarInfoPlan(infoPlan))
        {
            if(plan_neg.CargarPlan(nombrePlan,infoPlan,precio)){
                gotoxy(37,18);
                setColor(LIGHTGREEN);
                cout << "< PLAN AGREGADO CON EXITO >";
                setColor(WHITE);
                }
            else{
                gotoxy(37,18);
                setColor(RED);
                cout << "< EL PLAN NO SE HA AGREGADO >";
                setColor(WHITE);
                }
        }
    }
    system("pause>nul");
    system("cls");
}

void Planes_Presentacion::MostrarPlanesVista()
{
    system("cls");

    Planes_Negocio pl_neg;

    vector<Plan> vPlanes;
    pl_neg.obtenerRegistrosPlanes(vPlanes);
    int c=0;
    for(int i=0; i<vPlanes.size(); i++)
    {
        int cont=0;
        setColor(YELLOW);
        cout<<"                             CODIGO: "<<vPlanes.at(i).getCodigo()<<endl;
        cout<<"                             NOMBRE: " <<vPlanes.at(i).getDescripcion()<<endl;
        cout<<"                             PRECIO: $" <<vPlanes.at(i).getPrecio()<<endl;
        cout<<"                             INFO: ";

        for(int x=0; x<strlen(vPlanes.at(i).getInfo()); x++)
        {
            cout<<vPlanes.at(i).getInfo()[x];

            if(vPlanes.at(i).getInfo()[x]==' ' && cont > 80)
            {
                cont = 0;
                cout <<endl;
            }
            else
                cont++;
        }
        setColor(LIGHTGREEN);
        cout<<endl<<".....................---------------------------------------------------------------------------......................"<<endl;
        setColor(WHITE);
        c++;
    }
    system("pause>nul");
    system("cls");
}

void Planes_Presentacion::MostrarPlanXCodigo(int codPlan)
{
    Planes_Negocio pl_neg;

    Plan p = pl_neg.ObtenerDatosPlanXCodigo(codPlan);

    if(p.getCodigo()>0)
    {
        cout<<"                                    CODIGO: "<<p.getCodigo()<<endl;
        cout<<"                                    PLAN: "<<p.getDescripcion()<<endl;
        cout<<"                                    PRECIO: $"<<p.getPrecio()<<endl;
    }
    else{
        setColor(RED);
        cout<<"                                    PLAN NO ENCONTRADO"<<endl<<endl;
        setColor(WHITE);
        }
}

void Planes_Presentacion::BajaPlanVista()
{
    system("cls");

    Planes_Negocio plan_neg;

    int codPlan;

    codPlan = ValidarIngresoPlan();

    if(plan_neg.BajaPlan(codPlan)){
        gotoxy(34,18);
        setColor(LIGHTGREEN);
        cout<<" < EL PLAN SE ELIMINO CON EXITO >";
        setColor(WHITE);
        }
    else{
        gotoxy(34,18);
        setColor(RED);
        cout<<" < EL PLAN NO SE HA ELIMINADO >";
        setColor(WHITE);
        }
    system("pause>nul");
    system("cls");
}

void Planes_Presentacion::SubMenuPlanesVista()
{
    Planes_Presentacion pl_vista;
    FuncionesExtras fx;
    int opcionSubMenus;

    do
    {
        fx.SubMenuPlan();
        opcionSubMenus=fx.validarOpcionesMenu(3);

        system("cls");

        switch(opcionSubMenus)
        {
        case 1:
            pl_vista.CargarPlanVista();
            break;
        case 2:
            pl_vista.MostrarPlanesVista();
            break;
        case 3:
            pl_vista.BajaPlanVista();
            break;
        }
    }
    while(opcionSubMenus!=0);
    system("cls");
}

bool Planes_Presentacion::ValidarNombrePlan(char *nombrePlan)
{
    string input;
    FuncionesExtras fx;
    fx.DibujarMarcoPlan();
    do
    {
        gotoxy(37,9);
        cout << "INGRESE NOMBRE DEL PLAN: ";
        fflush(stdin);
        std::getline(std::cin, input);

        if(input.size()<101)
        {
            strcpy(nombrePlan, input.c_str());
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100,'\n');
            gotoxy(37,18);
            setColor(RED);
            cout<<"> INGRESO ERRONEO, INGRESE UN NOMBRE VALIDO <";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(37,18);
            cout<<"                                              ";
            gotoxy(37,9);
            cout<<"                                                                         ";
            continue;
        }
    }
    while(true);
    return true;
}

bool Planes_Presentacion::ValidarInfoPlan(char *infoPlan)
{
    string input;

    do
    {
        gotoxy(37,11);
        cout << "INGRESE INFO: ";
        fflush(stdin);
        std::getline(std::cin, input);

        if(input.size()<1001)
        {
            strcpy(infoPlan, input.c_str());
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100,'\n');
            gotoxy(34,18);
            setColor(RED);
            cout<<"INGRESO ERRONEO, INGRESE UNA INFORMACION VALIDA";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(34,18);
            cout<<"                                                  ";
            gotoxy(37,11);
            cout << "                                                                          ";
            continue;
        }
    }
    while(true);
    return true;
}

int Planes_Presentacion::ValidarIngresoPlan()
{
    int codPlan;
    FuncionesExtras fx;
    do
    {
        fx.Marco(1,2,1,35,35);
        gotoxy(37,9);
        cout <<"<INGRESE CODIGO DE PLAN>";
        gotoxy(74,11);
        cin>>codPlan;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            gotoxy(34,18);
            setColor(RED);
            cout << "INGRESO ERRONEO, INGRESE UN CODIGO DE PLAN VALIDO";
            setColor(WHITE);
            system("pause>nul");
            gotoxy(34,18);
            cout<<"                                                     ";
            gotoxy(74,11);
            cout<< "                               ";
            continue;
        }
        else
            break;
    }
    while(true);

    return codPlan;
}

float Planes_Presentacion::ValidarIngresoPrecio()
{
    float precio;

    do
    {
        gotoxy(37,10);
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
