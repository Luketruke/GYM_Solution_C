#ifndef ARTICULO_H
#define ARTICULO_H
#include <cstring>
#include "Item.h"

class Articulo : public Item
{
private:
    int _stock;

public:
    Articulo();

    void setStock(int stock);

    int getStock(){return _stock;};
};

#endif // ARTICULO_H
