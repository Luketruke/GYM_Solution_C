#ifndef CLIENTES_ARCHIVO_H
#define CLIENTES_ARCHIVO_H
#include <cstring>

class Clientes_Archivo
{
private:
    int _codigoCliente;
    char _nombreCompleto[100];
    char _direccion[100];
    int _documento;
    bool _estado;
public:
    Clientes_Archivo();

    void setNombreCompletoCliente(const char *nombreCompleto)
    {
        strcpy(_nombreCompleto, nombreCompleto);
    };

    void setDireccionCliente(const char *direccion)
    {
        strcpy(_direccion, direccion);
    };

    void setCodigoCliente(int codigoCliente);

    void setDocumentoCliente(int documento);

    void setEstadoCliente(bool estado);

    char *getNombreCompletoCliente()
    {
        return _nombreCompleto;
    };

    char *getDireccionCliente()
    {
        return _direccion;
    };

    int getDocumentoCliente()
    {
        return _documento;
    };

    int getCodigoCliente()
    {
        return _codigoCliente;
    };

    bool getEstado()
    {
        return _estado;
    };

    int getIDCliente();

    bool leerDeDisco(int pos);

    bool grabarEnDisco();

    bool modificarEnDisco(int pos);
};

#endif // CLIENTES_ARCHIVO_H
