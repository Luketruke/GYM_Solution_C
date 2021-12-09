#ifndef FUNCIONESEXTRAS_H
#define FUNCIONESEXTRAS_H

class FuncionesExtras
{
public:

    FuncionesExtras();

    void showItem(const char*, int, int, bool);

    void Marco(int, int, int, int, int);

    void showInput(const char*, int, int, bool);

    void DibujarFactura(int);

    void DibujarBordesFactura();

    int validarOpcionesMenu(int);

    void DibujarMain();
    void MenuPrincipalVista();
    void Marco();
    void SubMenuArt();
    void SubMenuPlan();
    void SubMenuCliente();
    void SubMenuFactura();
    void SubMenuUsuario();
    void CargaUsuarioExitosa(const char *,const char *,const char *);
    void CargaArticuloExitosa();
    void DibujarUsuarioIncorrecto();
    void DibujarMarcoPlan();
    void MarcoArt();
};

#endif // FUNCIONESEXTRAS_H
