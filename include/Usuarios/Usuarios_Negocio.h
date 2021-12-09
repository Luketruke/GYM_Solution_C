#ifndef USUARIOS_NEGOCIO_H
#define USUARIOS_NEGOCIO_H
#include <vector>
#include "Usuario.h"

class Usuarios_Negocio
{
public:
    Usuarios_Negocio();

    bool CargarUsuario(const char *, const char *, string, const char *, int, int, float);

    bool BajaLogicaUsuario(int codCliente);

    bool ValidarIngresoUsuario(string, string);

    void obtenerRegistrosUsuarios(vector<Usuario>&);

    Usuario ObtenerDatosUsuarioXCodigo(int);

    void obtenerTipoUsuario(int, char *);

    bool ValidarVendedor(int);
    };

#endif // USUARIOS_NEGOCIO_H
