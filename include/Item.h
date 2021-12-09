#ifndef ITEM_H
#define ITEM_H
#include <cstring>

class Item
{
protected:
    int _codigo;
    char _descripcion[100];
    float _precio;
    bool _estado;
public:
    Item();

    void setDescripcion(const char *descripcion)
    {
        strcpy(_descripcion, descripcion);
    };

    void setEstado(bool estado);

    void setPrecio(float precio);

    void setCodigo(int codigo);

    int getCodigo()
    {
        return _codigo;
    };

    char *getDescripcion()
    {
        return _descripcion;
    };

    float getPrecio()
    {
        return _precio;
    };

    bool getEstado()
    {
        return _estado;
    };
};

#endif // ITEM_H
