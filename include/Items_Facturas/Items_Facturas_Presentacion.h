#ifndef ITEMS_FACTURAS_PRESENTACION_H
#define ITEMS_FACTURAS_PRESENTACION_H


class Items_Facturas_Presentacion
{
public:
    Items_Facturas_Presentacion();

    void CargarItemsFacturasVista(int);

    void CargarItemsFacturas(int);

    float MostrarItemsFacturas(int &);

    float setDescuentoItem(float);

    int ValidarCategoriaItem();

    int ValidarCodigoArticulo();

    int ValidarCodigoPlan();

    int ValidarCantidad();

    string ValidarIngresoOpcion();

    string ValidarIngresoOpcionDescuento();
};

#endif // ITEMS_FACTURAS_PRESENTACION_H
