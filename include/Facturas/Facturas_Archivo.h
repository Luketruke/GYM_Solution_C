#ifndef FACTURAS_ARCHIVO_H
#define FACTURAS_ARCHIVO_H
#include "Fecha/Fecha.h"

class Facturas_Archivo
{
private:
    int _idFactura;
    float _subtotalFactura;
    float _descuento;
    float _totalFactura;
    int _vendedor;
    float _comisionesVendedor;
    int _codigoCliente;
    Fecha _fecha;
public:
    Facturas_Archivo();

    void setFecha(Fecha fecha);

    void setVendedor(int);

    void setSubtotalFactura(float);

    void setTotalFactura(float);

    void setDescuento(float);

    void setIDFactura(int);

    void setComisiones(float);

    void setCodigoCliente(int);

    Fecha getFecha(){return _fecha;};

    int getCodigoCliente()
    {
        return _codigoCliente;
    };

    int getVendedor()
    {
        return _vendedor;
    };

    float getSubtotal()
    {
        return _subtotalFactura;
    };

    float getTotal()
    {
        return _totalFactura;
    };

    float getDescuento()
    {
        return _descuento;
    };

    float getComisiones()
    {
        return _comisionesVendedor;
    };

    int getIdFactura_Realizada()
    {
        return _idFactura;
    };

    int getIDFactura();

    bool grabarEnDisco();

    bool leerDeDisco(int);
};

#endif // FACTURAS_ARCHIVO_H
