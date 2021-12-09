#ifndef USUARIOS_ARCHIVO_H
#define USUARIOS_ARCHIVO_H

class Usuarios_Archivo
{
private:
    int _codigoUsuario;
    char _user[30];
    char _pass[30];
    char _nombreCompleto[100];
    float _porcentajeXVenta;
    int _tipoUsuario; //1. Administrador - 2. Administrativo - 3. Vendedor
    bool _estado;
public:
    Usuarios_Archivo();

    void setCodigoUsuario(int codigoUsuario);

    void setPorcentajeXVenta(float porcentajeXVenta);

    void setTipoUsuario(int tipoUsuario);

    void setEstadoUsuario(bool estado);

    void setUsuario(const char *user)
    {
        strcpy(_user, user);
    };

    void setPassword(const char *pass)
    {
        strcpy(_pass, pass);
    };

    void setNombreCompleto(const char *nombreCompleto)
    {
        strcpy(_nombreCompleto, nombreCompleto);
    };

    int getCodigoUsuario()
    {
        return _codigoUsuario;
    };

    char *getUsuario()
    {
        return _user;
    };

    char *getPassword()
    {
        return _pass;
    };

    int getTipoUsuario()
    {
        return _tipoUsuario;
    };

    bool getEstado()
    {
        return _estado;
    };

    char *getNombreCompleto()
    {
        return _nombreCompleto;
    };

    float getPorcentajeXVenta()
    {
        return _porcentajeXVenta;
    };

    int getIDUsuario();

    bool leerDeDisco(int pos);

    bool grabarEnDisco();

    bool modificarEnDisco(int pos);
};

#endif // USUARIOS_ARCHIVO_H
