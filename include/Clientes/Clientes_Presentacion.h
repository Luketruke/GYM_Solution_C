#ifndef CLIENTES_PRESENTACION_H
#define CLIENTES_PRESENTACION_H

class Clientes_Presentacion
{
public:
    Clientes_Presentacion();

    int CargarClientesVista(int);

    void MostrarClientesVista();

    int ClienteEnFactura();

    void BajaClienteVista();

    void SubMenuClientesVista();

    int ValidarIngresoCodigo();

    bool ValidarIngresoDocumento(int &, int);

    char ValidarOpcionCliente();

    bool ValidarDireccionCliente(char *, int);

    bool ValidarNombreCompleto(char *, int);
};

#endif // CLIENTES_PRESENTACION_H
