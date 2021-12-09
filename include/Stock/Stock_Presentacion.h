#ifndef STOCK_PRESENTACION_H
#define STOCK_PRESENTACION_H


class Stock_Presentacion
{
    public:
        Stock_Presentacion();

        void ModificarStockVista();

        void MostrarStockVista();

        void DescontarStockVista(int,int);

        int ValidarCodigoArticulo();

        int validarNuevoStock();
};

#endif // STOCK_PRESENTACION_H
