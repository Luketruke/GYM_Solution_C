#ifndef STOCK_NEGOCIO_H
#define STOCK_NEGOCIO_H

class Stock_Negocio
{
public:
    Stock_Negocio();

    bool DescontarStock(int,int);

    bool ModificarStock(int,int);

    bool MostrarStockXArticulo(int);

    int ObtenerStockXArticulo(int);
};

#endif // STOCK_NEGOCIO_H
