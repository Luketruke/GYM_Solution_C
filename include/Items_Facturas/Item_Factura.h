#ifndef ITEM_FACTURA_H
#define ITEM_FACTURA_H
#include <vector>
#include <cstring>
#include "Item.h"

class Item_Factura : public Item
{
private:
    int _idFactura;
    int _categoriaItem;
    float _descuento;
    int _cantidad;
    float _total;

public:
    Item_Factura();

    void setDescuento(float);

    void setCantidad(int);

    void setTotal(float);

    void setCategoriaItem(int);

    void setIDFactura(int);

    int getCategoriaItem(){return _categoriaItem;};

    int getCantidad(){return _cantidad;};

    float getDescuento(){return _descuento;};

    float getTotal(){return _total;};

    int getIDFactura(){return _idFactura;};
};

#endif // ITEM_FACTURA_H
