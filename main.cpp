#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>
#include <conio.h>

using namespace std;
#include "include/Usuarios/Usuarios_Presentacion.h"
#include "include/Facturas/Facturas_Presentacion.h"
#include "include/Articulos/Articulos_Presentacion.h"
#include "include/Clientes/Clientes_Presentacion.h"
#include "include/Items_Facturas/Items_Facturas_Presentacion.h"
#include "include/Items_Facturas/Items_Facturas_Archivo.h"
#include "include/Planes/Planes_Presentacion.h"
#include "include/Fecha/Fecha.h"
#include "Menus.h"
#include "FuncionesExtras.h"

enum Opciones
{
    Ingresar=0,
    Registrarse=1,
    Salir=2
};

int main()
{
    Usuarios_Presentacion user_vista;
    Facturas_Presentacion fc_vista;
    Articulos_Presentacion art_vista;
    Clientes_Presentacion cl_vista;
    Planes_Presentacion plan_vista;
    FuncionesExtras fx;

    bool repetir = true, salir = true, habilitado = false, habilita2=true;
    int opcion, y=0, key, cont=-1, keyAux=-1;

    do
    {
        do
        {
            system("cls");

            rlutil::hidecursor();
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::setColor(rlutil::COLOR::WHITE);
            fx.DibujarMain();
            fx.showItem(" INGRESAR ", 47, 10, y == Ingresar);
            fx.showItem(" REGISTRARSE ", 47, 11, y == Registrarse);
            fx.showItem(" SALIR ", 47, 12, y == Salir);

            key=rlutil::getkey();
            switch (key)
            {
            case 14: // UP
                if(cont==2)
                    cont=1;
                else if(cont==1)
                {
                    cont=0;
                }
                else
                    cont=0;
                rlutil::locate(28, 10 + y);
                std::cout << " " << std::endl;
                y--;
                if (y < 0)
                {
                    y = 0;
                }
                if(key==1 && cont==1)
                {
                    opcion = 2;
                    habilita2=true;
                    system("cls");
                }
                break;
            case 15: // DOWN
                keyAux=0;
                if(cont==-1)
                    cont=1;
                else if(cont==1)
                    cont=2;
                else
                    cont=2;
                rlutil::locate(28, 10 + y);
                std::cout << " " << std::endl;
                y++;
                if (y > 2)
                {
                    y = 2;
                }
                if(key==1 && cont==1)
                {
                    opcion = 2;
                    habilita2=true;
                    system("cls");
                }
                break;
            case 1:
                if(key==1 && keyAux==-1)
                {
                    opcion = 1;
                    habilita2=true;
                    system("cls");
                }
                if((cont>-1 && cont<3) && key==1)
                {
                    opcion = MenuAnimado3(cont);
                    if(opcion==1 || opcion==2)
                        habilita2=true;
                    else if(opcion==0)
                        habilita2 = false;
                    system("cls");
                }
                break;
            }
            switch(opcion)
            {
            case 1:
                //INGRESO USUARIO
                if(user_vista.IngresarUsuario())
                {
                    do
                    {
                        fx.MenuPrincipalVista();

                        opcion= fx.validarOpcionesMenu(6);
                        switch (opcion)
                        {
                        case 1: //ARTICULOS Y STOCK
                            art_vista.SubMenuArticulosVista();
                            break;
                        case 2: //PLANES Y SERVICIOS
                            plan_vista.SubMenuPlanesVista();
                            break;
                        case 3: //GESTION DE CLIENTES
                            cl_vista.SubMenuClientesVista();
                            break;
                        case 4: //COBROS Y FACTURACION
                            fc_vista.SubMenuFacturasVista();
                            break;
                        case 5: //CAJA Y CUENTA CORRIENTE
                            user_vista.SubMenusUsuariosVista();
                            break;
                        case 0: //CERRAR SESION
                            repetir = false;
                            break;
                        }
                    }
                    while(repetir);
                }
                else
                {
                    fx.DibujarUsuarioIncorrecto();
                    opcion=-1;
                    cont=-1;
                }
                habilitado = false;
                break;
            case 2:
                user_vista.CargarUsuarioVista();
                opcion=-1;
                cont=1;
                system("cls");
                break;
            case 0:
                salir = false;
                break;
            }
        }
        while (habilita2 == true);
    }
    while(salir);
    return 0;
}
