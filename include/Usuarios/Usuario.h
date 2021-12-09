#ifndef USUARIO_H
#define USUARIO_H
#include <cstring>
#include "Persona.h"

class Usuario : public Persona
{
private:
    char _user[30];
    char _pass[30];
    int _tipoUsuario;
    char _tipoUsuarioNombre[15];
    float _porcentajeXVenta;
public:
    Usuario();

    void setPorcentajeXVenta(float);

    void setTipoUsuario(int);

    void setUsuario(const char *user){strcpy(_user, user);};

    void setPassword(const char *pass){strcpy(_pass, pass);};

    void setNombreTipoUsuario(char *tipoUsuarioNombre){strcpy(_tipoUsuarioNombre, tipoUsuarioNombre);};

    char *getUsuario(){return _user;};

    char *getPassword(){return _pass;};

    int getTipoUsuario(){return _tipoUsuario;};

    char *getNombreTipoUsuario(){return _tipoUsuarioNombre;};

    float getPorcentajeXVenta(){return _porcentajeXVenta;};
};

#endif // USUARIO_H
