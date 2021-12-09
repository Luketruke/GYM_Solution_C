#ifndef USUARIOS_PRESENTACION_H
#define USUARIOS_PRESENTACION_H


class Usuarios_Presentacion
{
public:
    Usuarios_Presentacion();

    bool IngresarUsuario();

    void CargarUsuarioVista();

    void MostrarVendedorXCodigo(int);

    void MostrarVendedoresVista();

    void MostrarUsuariosVista();

    void BajaUsuario();

    void SubMenusUsuariosVista();

    void DibujarUsuarioIncorrecto();

    void MostrarTipoDeUsuario(int tipoUser);

    bool ValidarNombreCompleto(char *);

    int ValidarTipoVendedor();

    float ValidarPorcentajeXVenta();
};

#endif // USUARIOS_PRESENTACION_H
