#ifndef STOCK_DATABASE_H
#define STOCK_DATABASE_H
#include <cstring>

class Stock_Database
{
private:
    int _codigoArticulo;
    int _stock;
public:
    Stock_Database();

    void setStock(int stock);

    void setCodigoArticulo(int codigo);

    int getStock()
    {
        return _stock;
    };

    int getCodigoArticulo()
    {
        return _codigoArticulo;
    };

    bool leerDeDisco(int pos);

    bool grabarEnDisco();
};

#endif // STOCK_DATABASE_H
