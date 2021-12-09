#include <iostream>

using namespace std;
#include "../../include/Usuarios/Usuario.h"

Usuario::Usuario()
{
}

void Usuario::setPorcentajeXVenta(float porcentajeXVenta)
{
    _porcentajeXVenta = porcentajeXVenta;
}

void Usuario::setTipoUsuario(int tipoUsuario)
{
    _tipoUsuario = tipoUsuario;
}
