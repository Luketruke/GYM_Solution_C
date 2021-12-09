#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;
#include "../../include/Usuarios/Usuarios_Presentacion.h"
#include "../../include/Usuarios/Usuarios_Negocio.h"
#include "../../include/Usuarios/Usuarios_Archivo.h"
#include "../../include/Usuarios/Usuario.h"

Usuarios_Negocio::Usuarios_Negocio()
{
}

bool Usuarios_Negocio::CargarUsuario(const char *user,
                                     const char *pass, string passValidar, const char *nombreCompleto,
                                     int codigoUsuario, int tipoUsuario, float porcentajeXVenta = 0)
{
    Usuarios_Archivo userDB; //ARCHIVO
    userDB.setCodigoUsuario(userDB.getIDUsuario());
    userDB.setUsuario(user);
    userDB.setPassword(pass);
    userDB.setNombreCompleto(nombreCompleto);
    userDB.setPorcentajeXVenta(porcentajeXVenta);
    userDB.setTipoUsuario(tipoUsuario);
    if(pass==passValidar)
    {
        if(userDB.grabarEnDisco())
            return true;
    }
    else
        return false;
}

bool Usuarios_Negocio::BajaLogicaUsuario(int codCliente)
{
    Usuarios_Archivo user_db;
    int i= 0;
    while (user_db.leerDeDisco(i)== true)
    {
        if(user_db.getCodigoUsuario()==codCliente && user_db.getEstado()==true)
        {
            user_db.setEstadoUsuario(false);
            if(user_db.modificarEnDisco(i))
                return true;
            else
                return false;
        }
        i++;
    }
}

bool Usuarios_Negocio::ValidarIngresoUsuario(string user, string pass)
{
    Usuarios_Archivo user_db;
    int i=0;
    while (user_db.leerDeDisco(i)== true)
    {
        if(user==user_db.getUsuario() && pass==user_db.getPassword() && user_db.getEstado()==true)
            return true;
        i++;
    }
}

void Usuarios_Negocio::obtenerRegistrosUsuarios(vector<Usuario>& vUsuarios)
{
    Usuarios_Archivo user_db;

    int pos=0;

    char tipoUsuario[15];

    while(user_db.leerDeDisco(pos))
    {
        if(user_db.getEstado()==true)
        {
            Usuario user;

            user.setCodigo(user_db.getCodigoUsuario());
            user.setEstado(user_db.getEstado());
            user.setNombreCompleto(user_db.getNombreCompleto());
            obtenerTipoUsuario(user_db.getTipoUsuario(),tipoUsuario);
            user.setNombreTipoUsuario(tipoUsuario);
            user.setPorcentajeXVenta(user_db.getPorcentajeXVenta());
            user.setTipoUsuario(user_db.getTipoUsuario());
            user.setUsuario(user_db.getUsuario());
            user.setPassword(user_db.getPassword());
            vUsuarios.push_back(user);
        }
        pos++;
    }
}

Usuario Usuarios_Negocio::ObtenerDatosUsuarioXCodigo(int idUsuario)
{
    Usuarios_Archivo user_db;

    Usuario user;

    char tipoUsuario[15];
    int pos=0;

    while(user_db.leerDeDisco(pos))
    {
        if(idUsuario==user_db.getCodigoUsuario() && user_db.getEstado() == true)
        {
            user.setCodigo(user_db.getCodigoUsuario());
            user.setEstado(user_db.getEstado());
            user.setNombreCompleto(user_db.getNombreCompleto());
            obtenerTipoUsuario(user_db.getTipoUsuario(),tipoUsuario);
            user.setNombreTipoUsuario(tipoUsuario);
            user.setPorcentajeXVenta(user_db.getPorcentajeXVenta());
            user.setTipoUsuario(user_db.getTipoUsuario());
            user.setUsuario(user_db.getUsuario());
            user.setPassword(user_db.getPassword());
        }
        pos++;
    }
    return user;
}

bool Usuarios_Negocio::ValidarVendedor(int idVendedor)
{
    int i=0;

    Usuarios_Archivo user_db;

    while(user_db.leerDeDisco(i))
    {
        while(user_db.getCodigoUsuario()==idVendedor && user_db.getTipoUsuario()==3 &&user_db.getEstado()==true)
        {
            return true;
        }
        i++;
    }
    return false;
}

void Usuarios_Negocio::obtenerTipoUsuario(int idTipoUsuario, char *tipoUsuario)
{
    char administrador[15]={"ADMINISTRADOR"}, administrativo[15]={"ADMINISTRATIVO"}, vendedor[9]={"VENDEDOR"};

    switch(idTipoUsuario)
    {
    case 1:
        strcpy(tipoUsuario,administrador);
        break;

    case 2:
        strcpy(tipoUsuario,administrativo);
        break;

    case 3:
        strcpy(tipoUsuario,vendedor);
        break;
    }
}
