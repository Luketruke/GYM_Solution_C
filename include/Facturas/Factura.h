#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
#include <cstring>

class Factura
{
private:
    int _codigoCliente;
    char _nombreCompleto[100];
    char _direccion[100];
    int _documento;
    int _idFactura;
    float _subtotalFactura;
    float _descuento;
    float _totalFactura;
    int _vendedor;
    float _comisionesVendedor;
    int _dia;
    int _mes;
    int _anio;
    char _nombreVendedor[100];

public:
    Factura();

    void setVendedor(int);

    void setSubtotalFactura(float);

    void setTotalFactura(float);

    void setDescuento(float);

    void setIDFactura(int);

    void setComisiones(float);

    void setCodigoCliente(int);

    void setDia(int);

    void setMes(int);

    void setAnio(int);

    void setNombreCompletoCliente(const char *nombreCompleto){
    strcpy(_nombreCompleto, nombreCompleto);};

    void setDireccionCliente(const char *direccion)
    {strcpy(_direccion, direccion);};

    void setDocumentoCliente(int documento);

    void setNombreCompletoVendedor(const char *nombreVendedor){
    strcpy(_nombreVendedor, nombreVendedor);};

    int getVendedor(){return _vendedor;};

    int getDia(){return _dia;};

    int getMes(){return _mes;};

    int getAnio(){return _anio;};

    float getSubtotal(){return _subtotalFactura;};

    float getTotal(){return _totalFactura;};

    float getDescuento(){return _descuento;};

    float getComisiones(){return _comisionesVendedor;};

    int getIdFactura_Realizada(){return _idFactura;};

    char *getNombreCompletoCliente(){return _nombreCompleto;};

    char *getDireccionCliente(){return _direccion;};

     char *getNombreCompletoVendedor(){return _nombreVendedor;};

    int getCodigoCliente(){return _codigoCliente;};

    int getDocumentoCliente(){return _documento;};
};

#endif // FACTURA_H
