#ifndef ARTICULOS_ARCHIVO_H
#define ARTICULOS_ARCHIVO_H
#include <cstring>

class Articulos_Archivo
{
private:
    int _codigoArticulo;
    char _descripcionArticulo[100];
    float _precio;
    bool _estado;
public:
    Articulos_Archivo();

    void setDescripcionArticulo(const char *descripcionArticulo)
    {
        strcpy(_descripcionArticulo, descripcionArticulo);
    };

    void setPrecio(float precio);

    void setEstado(bool);

    void setCodigoArticulo(int);

    int getCodigoArticulo()
    {
        return _codigoArticulo;
    };

    char *getDescripcionArticulo()
    {
        return _descripcionArticulo;
    };

    float getPrecio()
    {
        return _precio;
    };

    bool getEstado()
    {
        return _estado;
    };

    int getIDArticulo();

    bool leerDeDisco(int);

    bool grabarEnDisco();

    bool modificarEnDisco(int);
};

#endif // ARTICULOS_ARCHIVO_H
