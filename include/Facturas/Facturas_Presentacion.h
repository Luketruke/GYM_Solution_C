#ifndef FACTURAS_PRESENTACION_H
#define FACTURAS_PRESENTACION_H

class Facturas_Presentacion
{
public:
    Facturas_Presentacion();

    void VistaCargarFacturas();

    void VistaFacturasVista();

    void VistaMostrarFacturas();

    void VistaExportToExcel();

    void MostrarFacturaDetallada();

    void VistaComisionesVendedores();

    void SubMenuFacturasVista();

    float CargarDescuento(float);

    int IngresoVendedor();

    string ValidarIngresoOpcion();

    float ValidarIngresoDescuento(float);

    int ValidarIngresoCodigo();
};

#endif // FACTURAS_PRESENTACION_H
