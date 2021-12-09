#ifndef ARTICULOS_NEGOCIO_H
#define ARTICULOS_NEGOCIO_H
#include <vector>
#include "../include/Articulos/Articulo.h"


class Articulos_Negocio
{
public:
    Articulos_Negocio();

    bool CargarArticulo(const char *, float);

    void MostrarArticulos();

    bool BajaArticulo(int);

    Articulo ObtenerDatosArticuloXCodigo(int);

    void obtenerRegistrosArticulos(vector<Articulo>&);

    bool ValidarCodigo(int);
    bool ObtenerArticuloXCodigo (int);
};

#endif // ARTICULOS_NEGOCIO_H
