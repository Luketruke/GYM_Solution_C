#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void MenuPrincipalVista()
{
    system("cls");
    cout << "1. ARTICULOS Y STOCK" << endl;
    cout << "2. PLANES Y SERVICIOS" << endl;
    cout << "3. GESTION DE CLIENTES" << endl;
    cout << "4. COBROS Y FACTURACION" << endl;
    cout << "5. GESTION DE USUARIOS" << endl;
    cout << "0. CERRAR SESION" << endl;
}

int MenuAnimado3(int cont)
{
    int opcion;

    switch(cont)
    {
    case 0:
        opcion = 1;
        return opcion;
        break;
    case 1:
        opcion = 2;
        return opcion;
        break;
    case 2:
        opcion = 0;
        return opcion;
        break;
    }
}


#endif // MENUS_H_INCLUDED
