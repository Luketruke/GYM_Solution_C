#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <rlutil.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
using namespace rlutil;
#include "../include/Facturas/Facturas_Archivo.h"
#include "../include/Facturas/Facturas_Negocio.h"
#include "../include/Articulos/Articulos_Archivo.h"
#include "../include/Clientes/Clientes_Negocio.h"
#include "../include/Clientes/Clientes_Archivo.h"
#include "../include/Items_Facturas/Items_Facturas_Archivo.h"
#include "../include/Items_Facturas/Items_Facturas_Negocio.h"
#include "../include/Items_Facturas/Items_Facturas_Presentacion.h"
#include "../include/Planes/Planes_Archivo.h"
#include "FuncionesExtras.h"
#include <rlutil.h>

FuncionesExtras::FuncionesExtras()
{
}

void FuncionesExtras::showItem(const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTGREEN);
        rlutil::locate(posx - 3, posy);
        setColor(BLACK);
        std::cout <<" " <<(char)175 << " " << text << " " << (char)174 <<" " <<std::endl;
        setColor(WHITE);

    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posx-3, posy);
        std::cout << "   " << text << "   "<< std::endl;
    }

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}
void  FuncionesExtras::MarcoArt(){
for(int i=35; i<80; i++)
    {
        setColor(LIGHTGREEN);
        gotoxy(i,8);
        cout<<"=";
        gotoxy(i,11);
        cout<<"=";
    }
    for(int i=9; i<11; i++)
    {
        gotoxy(34,i);
        cout<<"|";
        gotoxy(81,i);
        cout<<"|";
    }
     setColor(WHITE);
}

void FuncionesExtras::Marco(int Altura, int Color, int Cuadro, int Ancho, int Ubicacion)
{
    // Cuadro=1 SI  /// 2=NO
    //1> Verde    2>Rojo     3>Amarillo   4>White
    string C;
    switch (Color)
    {
    case 1:
        setColor(LIGHTGREEN);
        break;
    case 2:
        setColor(RED);
        break;
    case 3:
        setColor(YELLOW);
        break;
    case 4:
        setColor(WHITE);
        break;
    }
    for(int i=Ubicacion; i<68; i++)
    {
        gotoxy(i,8);
        cout<<"=";
        gotoxy(i,9+Altura);
        cout<<"=";
    }
    for(int i=9; i<9+Altura; i++)
    {
        gotoxy(Ubicacion-1,i);
        cout<<"|";
        gotoxy(68,i);
        cout<<"|";
    }
    if (Cuadro==1)
    {
        gotoxy( 72, 10);
        cout<<"-----";
        gotoxy( 72, 12);
        cout<<"-----";
        gotoxy( 71, 11);
        cout<<"|";
        gotoxy( 77, 11);
        cout<<"|";

        gotoxy(74,11);
    }
    setColor(WHITE);
}


void FuncionesExtras::showInput(const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::locate(posx - 3, posy);
        std::cout <<" " <<(char)175 << " " << text << " " << (char)174 <<" " <<std::endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posx-3, posy);
        std::cout << text << std::endl;
    }

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void FuncionesExtras::DibujarFactura(int nroFC)
{
    int f=0, c, i, x, z, cont, dia, mes, anio;
    bool entro = false;
    string nro_fc;
    Facturas_Archivo fc_db;
    Facturas_Negocio fc_neg;
    Clientes_Archivo cl_db;
    Items_Facturas_Archivo ifc_db;
    Articulos_Archivo a;
    Planes_Archivo plan_db;
    rlutil::hidecursor();
    while (fc_db.leerDeDisco(f)==true)
    {
        if(fc_db.getIdFactura_Realizada()==nroFC)
        {
            entro=true;

            c=0, i=0, cont=15;

            dia = fc_db.getFecha().getDia();
            mes = fc_db.getFecha().getMes();
            anio = fc_db.getFecha().getAnio();

            nro_fc = fc_neg.CalcularNumeroFC(fc_db.getIdFactura_Realizada());

            while(cl_db.leerDeDisco(c)==true)
            {
                if(cl_db.getCodigoCliente()==fc_db.getCodigoCliente())
                {
                    rlutil::locate(17,8);
                    cout << "DATOS CLIENTE";
                    rlutil::locate(17,9);
                    cout << "RAZON SOCIAL: "<<cl_db.getNombreCompletoCliente();
                    rlutil::locate(17,10);
                    cout << "DIRECCION: "<<cl_db.getDireccionCliente();
                    rlutil::locate(17,11);
                    cout << "DOCUMENTO: "<<cl_db.getDocumentoCliente();
                }
                c++;
            }
            while(ifc_db.leerDeDisco(i)==true)
            {
                x=0, z=0;
                if(fc_db.getIdFactura_Realizada()==ifc_db.getIDFactura())
                {
                    gotoxy(17,cont);
                    cout<<ifc_db.getCantidad();

                    if(ifc_db.getCategoriaItem()==1)
                    {
                        while(plan_db.leerDeDisco(x)==true)
                        {
                            if(ifc_db.getCodigoItem()==plan_db.getCodigoPlan()) //ITEMS DE LA FACTURA
                            {
                                gotoxy(38,cont);
                                cout<<plan_db.getNombrePlan();
                                gotoxy(65,cont);
                                cout<<"$"<<plan_db.getPrecio();
                                gotoxy(78,cont);
                                cout<<"$"<<ifc_db.getCantidad()*plan_db.getPrecio();
                                cont++;
                            }
                            x++;
                        }
                    }
                    else
                    {
                        while(a.leerDeDisco(z)==true)
                        {
                            if(ifc_db.getCodigoItem()==a.getCodigoArticulo()) //ITEMS DE LA FACTURA
                            {
                                gotoxy(38,cont);
                                cout<<a.getDescripcionArticulo();
                                gotoxy(65,cont);
                                cout<<"$"<<ifc_db.getPrecio();
                                gotoxy(78,cont);
                                cout<<"$"<<(ifc_db.getPrecio()-ifc_db.getDescuento())*ifc_db.getCantidad();
                                cont++;
                            }
                            z++;
                        }
                    }
                    cont++;
                }
                i++;
            }

            rlutil::locate(17,3);
            cout << "DATOS EMPRESA";
            rlutil::locate(17,4);
            cout << "EMPRESA: ZABALETT S.A.";
            rlutil::locate(17,5);
            cout << "SUCURSAL: LUKETRUKE";
            rlutil::locate(17,6);
            cout << "DIRECCION: AV CAZON";
            rlutil::locate(65,3);
            cout << "DOCUMENTO: FACTURA B";
            rlutil::locate(65,4);
            cout << "FC NRO: "<<nro_fc<<fc_db.getIdFactura_Realizada();
            rlutil::locate(65,5);
            cout<<"FECHA: "<< fc_neg.MostrarFechasFacturas(dia,mes,anio)<<endl;
            rlutil::locate(65,9);
            cout << "SUBTOTAL: $"<<fc_db.getSubtotal();
            rlutil::locate(65,10);
            cout << "DESCUENTO: $"<<fc_db.getDescuento();
            rlutil::locate(65,11);
            cout << "TOTAL: $"<<fc_db.getTotal();
            gotoxy(17,13);
            rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
            cout<<"CANT";
            gotoxy(38,13);
            //  rlutil::setBackgroundColor(rlutil::COLOR::LIGHTGREEN)
            cout<<"DESCRIPCION";
            gotoxy(65,13);
            // rlutil::setBackgroundColor(rlutil::COLOR::LIGHTGREEN)
            cout<<"PRECIO";
            // rlutil::setBackgroundColor(rlutil::COLOR::LIGHTGREEN)
            gotoxy(78,13);
            cout<<"IMPORTE";
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);


            DibujarBordesFactura();
        }
        f++;
    }
    if(entro==false)
    {
        cout << "NUMERO DE FACTURA NO ENCONTRADO";
    }
}

void FuncionesExtras::DibujarBordesFactura()
{



    setColor(LIGHTGREEN);

    for(int i=50; i<55; i++)
    {
        gotoxy(i,3);
        cout<<"-";
        gotoxy(i,5);
        cout<<"-";
    }
    gotoxy(52,4);
    cout<<"B";
    gotoxy(49,4);
    cout<<"|";
    gotoxy(55,4);
    cout<<"|";

    for(int i=15; i<87; i++)
    {
        gotoxy(i,2);
        cout<<"-";
        gotoxy(i,35);
        cout<<"-";
        gotoxy(i,12);
        cout<<"-";
        gotoxy(i,14);
        cout<<"-";
    }
    for(int i=3; i<35; i++)
    {
        gotoxy(14,i);
        cout<<"|";
        gotoxy(87,i);
        cout<<"|";
    }
    setColor(WHITE);
}


int FuncionesExtras::validarOpcionesMenu(int SubMenus)
{
    int opcionSubMenus;
    do
    {
        gotoxy(74,11);
        cin>>opcionSubMenus;

        if(cin.fail()==true)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            setColor(RED);
            gotoxy(35,18);
            cout<< "VALOR INVALIDO, INGRESE UNA OPCION NUEVAMENTE" << endl << endl;
            setColor(WHITE);
            gotoxy(74,11);
            system("pause>nul");
            continue;
        }
        else if(opcionSubMenus>-1 && opcionSubMenus<SubMenus+1)
            break;
        else
        {
            setColor(RED);
            gotoxy(35,18);
            cout<< "VALOR INVALIDO, INGRESE UNA OPCION NUEVAMENTE" << endl << endl;
            gotoxy(38,19);
            cout<< "   pulse una tecla para continuar..." << endl << endl;
            setColor(WHITE);
            gotoxy(74,11);
            cout<< "   ";
            system("pause>nul");
            gotoxy(35,18);
            cout<< "                                               ";
            gotoxy(38,19);
            cout<< "                                      ";
            gotoxy(74,11);
            setColor(WHITE);
            continue;
        }
    }
    while(true);
    setColor(WHITE);
    return opcionSubMenus;
}


void FuncionesExtras::DibujarMain()
{

    setColor (LIGHTGREEN);
    gotoxy(28,4);
    cout<<" ===============================================";
    gotoxy(28,6);
    cout<<" =============================================== ";
    gotoxy(29, 5);
    cout<<"|                                             | ";

    gotoxy(41, 8);
    cout<<"*--------------------*";
    gotoxy(40, 9);
    cout<<"/";
    gotoxy(39, 10);
    cout<<"/";
    gotoxy(38, 11);
    cout<<"(";
    gotoxy(39, 12);
    cout<<"\\";
    gotoxy(40, 13);
    cout<<"\\";
    gotoxy(41, 14);
    cout<<"*--------------------*";
    gotoxy(63, 9);
    cout<<"\\";
    gotoxy(64, 10);
    cout<<"\\";
    gotoxy(65, 11);
    cout<<")";
    gotoxy(64, 12);
    cout<<"/";
    gotoxy(63, 13);
    cout<<"/";
    setColor(WHITE);
    gotoxy(30, 5);

    cout<<"     BIENVENIDO! SELECCIONE UNA OPCION";

}


void FuncionesExtras::MenuPrincipalVista()
{
    system("cls");
    gotoxy(37,9);
    cout << "1. ARTICULOS Y STOCK" << endl;
    gotoxy(37,10);
    cout << "2. PLANES Y SERVICIOS" << endl;
    gotoxy(37,11);
    cout << "3. GESTION DE CLIENTES" << endl;
    gotoxy(37,12);
    cout << "4. COBROS Y FACTURACION" << endl;
    gotoxy(37,13);
    cout << "5. GESTION DE USUARIOS" << endl;
    gotoxy(37,14);
    cout << "0. CERRAR SESION" << endl;
    Marco(6,1,1,35,35);
}


void FuncionesExtras::DibujarMarcoPlan(){
for(int i=35; i<80; i++)
    {
        setColor(LIGHTGREEN);
        gotoxy(i,8);
        cout<<"=";
        gotoxy(i,16);
        cout<<"=";
    }
    for(int i=9; i<12; i++)
    {
        gotoxy(34,i);
        cout<<"|";
        gotoxy(81,i);
        cout<<"|";
    }
     setColor(WHITE);
}
void FuncionesExtras::Marco()
{
    for(int i=35; i<68; i++)
    {
        setColor(LIGHTGREEN);
        gotoxy(i,8);
        cout<<"=";
        gotoxy(i,16);
        cout<<"=";
    }
    for(int i=9; i<16; i++)
    {
        gotoxy(34,i);
        cout<<"|";
        gotoxy(68,i);
        cout<<"|";
    }
    gotoxy( 72, 10);
    cout<<"-----";
    gotoxy( 72, 12);
    cout<<"-----";
    gotoxy( 71, 11);
    cout<<"|";
    gotoxy( 77, 11);
    cout<<"|";
    setColor(WHITE);
    gotoxy(74,11);
}



void FuncionesExtras::SubMenuArt()
{
    system("cls");
    gotoxy(37,9);
    cout << "1. CARGAR ARTICULO" << endl;
    gotoxy(37,10);
    cout << "2. MOSTRAR ARTICULOS" << endl;
    gotoxy(37,11);
    cout << "3. ELIMINAR ARTICULO" << endl;
    gotoxy(37,12);
    cout << "4. MODIFICAR STOCK" << endl;
    gotoxy(37,13);
    cout << "5. MOSTRAR STOCK" << endl;
    gotoxy(37,14);
    cout << "0. MENU PRINCIPAL" << endl;
    Marco(6,1,1,35,35);
}


void FuncionesExtras::SubMenuPlan()
{

    system("cls");
    gotoxy(37,9);
    cout << "1. CARGAR PLAN" << endl;
    gotoxy(37,10);
    cout << "2. INFO PLANES" << endl;
    gotoxy(37,11);
    cout << "3. ELIMINAR PLAN" << endl;
    gotoxy(37,12);
    cout << "0. MENU PRINCIPAL" << endl;
    Marco(4,1,1,35,35);

}


void FuncionesExtras::SubMenuCliente()
{
    system("cls");
    gotoxy(37,9);
    cout << "1. CARGAR CLIENTE" << endl;
    gotoxy(37,10);
    cout << "2. MOSTRAR CLIENTES" << endl;
    gotoxy(37,11);
    cout << "3. ELIMINAR CLIENTE" << endl;
    gotoxy(37,12);
    cout << "0. MENU PRINCIPAL" << endl;
    Marco(4,1,1,35,35);
}

void FuncionesExtras::SubMenuFactura()
{
    system("cls");
    gotoxy(37,9);
    cout << "1. CARGAR FACTURA" << endl;
    gotoxy(37,10);
    cout << "2. MOSTRAR FACTURAS" << endl;
    gotoxy(37,11);
    cout << "3. MOSTRAR FACTURA DETALLADA" << endl;
    gotoxy(37,12);
    cout << "4. EXPORTAR FACTURAS" << endl;
    gotoxy(37,13);
    cout << "5. COMISIONES VENDEDORES" << endl;
    gotoxy(37,14);
    cout << "0. MENU PRINCIPAL" << endl;
    Marco(6,1,1,35,35);
}

void FuncionesExtras::SubMenuUsuario()
{
    system("cls");
    gotoxy(37,9);
    cout << "1. CARGAR USUARIO" << endl;
    gotoxy(37,10);
    cout << "2. MOSTRAR USUARIOS" << endl;
    gotoxy(37,11);
    cout << "3. ELIMINAR USUARIOS" << endl;
    gotoxy(37,12);
    cout << "0. MENU PRINCIPAL" << endl;
    Marco(4,1,1,35,35);
}
void FuncionesExtras::CargaUsuarioExitosa(const char *user,const char *pass, const char *nombreCompleto)
{
    int i;

    setColor(YELLOW);
    gotoxy(39+strlen(user),15);
    Sleep(100);
    cout<< " + Checked";
    gotoxy(39+strlen(pass),17);
    Sleep(100);
    cout<< " + Checked";
    gotoxy(39+strlen(pass),19);
    Sleep(100);
    cout<< " + Checked";
    gotoxy(39+strlen(nombreCompleto),21);
    Sleep(100);
    cout<< " + Checked";
    gotoxy(40,23);
    Sleep(100);
    cout<< " + Checked";

    while (kbhit()==0)
    {
        Sleep(250);
        gotoxy(34,25);
        setColor(YELLOW);
        cout <<"<<<  USUARIO AGREGADO CON EXITO >>>";
        Sleep(250);
        gotoxy(34,25);
        setColor(LIGHTGREEN);
        cout <<"<<<  USUARIO AGREGADO CON EXITO >>>";
    }
    getch();
    system("cls");
}

void FuncionesExtras::CargaArticuloExitosa()
{

    while (kbhit()==0)
    {
        Marco(2,1,0,35,35);
        setColor(LIGHTGREEN);
        gotoxy(34,12);
        cout<< "<<< ARTICULO AGREGADO CON EXITO >>>";
        Sleep(250);
        Marco(2,1,0,35,35);
        setColor(YELLOW);
        gotoxy(34,12);
        cout<< "<<< ARTICULO AGREGADO CON EXITO >>>";
        Sleep(250);
    }
    getch();
    system("cls");
    setColor(WHITE);
}

void FuncionesExtras::DibujarUsuarioIncorrecto()
{
    while (kbhit()==0)
    {
        Marco(4,2,2,35,35);
        rlutil::locate(45, 15);
        setColor(RED);
        cout << "USUARIO INCORRECTO"<<endl;
        Sleep(250);
        Marco (4,3,2,35,35);
        rlutil::locate(45, 15);
        setColor(YELLOW);
        cout << "USUARIO INCORRECTO"<<endl;
        Sleep(250);
    }
    setColor(WHITE);
    getch();
    system("pause>nul");
}


