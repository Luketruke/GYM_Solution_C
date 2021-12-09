#ifndef ITEMS_FACTURAS_ARCHIVO_H
#define ITEMS_FACTURAS_ARCHIVO_H
#include <cstring>

class Items_Facturas_Archivo
{
private:
    int _idFactura;
    int _codigoItem;
    char _descripcionItem[100];
    int _categoriaItem;
    float _precio;
    float _descuento;
    int _cantidad;
public:
    Items_Facturas_Archivo();

    void setDescripcionItem(const char *descripcionItem)
    {
        strcpy(_descripcionItem, descripcionItem);
    };

    void setDescuento(float);

    void setCantidad(int);

    void setCategoriaItem(int);

    void setPrecioItem(float);

    void setIDFactura(int);

    void setCodigoItem(int);

    int getCodigoItem()
    {
        return _codigoItem;
    };

    char *getDescripcionItem()
    {
        return _descripcionItem;
    };

    int getCategoriaItem()
    {
        return _categoriaItem;
    };

    int getCantidad()
    {
        return _cantidad;
    };

    float getDescuento()
    {
        return _descuento;
    };

    int getIDFactura()
    {
        return _idFactura;
    };

    float getPrecio()
    {
        return _precio;
    };

    bool leerDeDisco(int pos);

    bool grabarEnDisco();
};

#endif // ITEMS_FACTURAS_ARCHIVO_H
