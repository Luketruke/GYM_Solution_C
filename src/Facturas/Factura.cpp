#include <iostream>
#include <vector>

using namespace std;
#include "../include/Facturas/Factura.h"

Factura::Factura()
{
    for(int i=0; i<100; i++)
    {
        _nombreCompleto[i]= {';'};
    }
    for(int i=0; i<50; i++)
    {
        _direccion[i]= {';'};
    }
}

void Factura::setCodigoCliente(int codigoCliente)
{
    _codigoCliente = codigoCliente;
}

void Factura::setDocumentoCliente(int documento)
{
    _documento = documento;
}

void Factura::setVendedor(int vendedor)
{
    _vendedor = vendedor;
}

void Factura::setSubtotalFactura(float subtotalFactura)
{
    _subtotalFactura = subtotalFactura;
}

void Factura::setTotalFactura(float totalFactura)
{
    _totalFactura = totalFactura;
}

void Factura::setComisiones(float comisiones)
{
    _comisionesVendedor = comisiones;
}

void Factura::setDescuento(float descuento)
{
    _descuento = descuento;
}

void Factura::setIDFactura(int idFactura)
{
    _idFactura = idFactura;
}

void Factura::setDia(int dia)
{
    _dia = dia;
}

void Factura::setMes(int mes)
{
    _mes = mes;
}

void Factura::setAnio(int anio)
{
    _anio = anio;
}
