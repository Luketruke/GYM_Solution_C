#ifndef FACTURAS_NEGOCIO_H
#define FACTURAS_NEGOCIO_H
#include <vector>
#include "Factura.h"
#include "Fecha/Fecha.h"

class Facturas_Negocio
{
public:
    Facturas_Negocio();

    bool CargarDatosFactura(float, float, float, int, float, int, Fecha, int);

    float obtenerPorcentajeXVentaVendedor(int);

    void obtenerRegistrosFacturas(vector<Factura>&);

    string MostrarFechasFacturas(int,int,int);

    string CalcularNumeroFC(int);

    float CalcularTotalFC(float, float);

    float CalcularComision(float,float);

    void ExportToExcel();

    bool ObtenerDatosComisiones(int &,char *,float &,int &,int &,int &,int);

    int obtenerIDFacturaActual();

    bool ValidarFactura(int);
};

#endif // FACTURAS_NEGOCIO_H
