#ifndef CLIENTES_NEGOCIO_H
#define CLIENTES_NEGOCIO_H
#include <vector>
#include "Clientes/Cliente.h"

class Clientes_Negocio
{
public:
    Clientes_Negocio();

    int CargarCliente(int, const char*, const char *);

    void obtenerRegistrosClientes(vector<Cliente>&);

    Cliente ObtenerDatosClientesXCodigo(int);

    bool BajaClienteValidar(int);

    bool ValidarCliente(int);

    int ValidarDocumento(int);

    Cliente VectorClientes();
};

#endif // CLIENTES_NEGOCIO_H
