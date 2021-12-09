#ifndef ARTICULOS_PRESENTACION_H
#define ARTICULOS_PRESENTACION_H


class Articulos_Presentacion
{
    protected:

    public:
        Articulos_Presentacion();

        void VistaCargarArticulo();

        void VistaBajaArticulo();

        void MostrarArticulosVista();

        void MostrarArticuloXCodigo(int);

        void SubMenuArticulosVista();

        float ValidarIngresoPrecio();

        bool ValidarDescripcionArticulo(char *);

        int ValidarArticuloEliminar();
};

#endif // ARTICULOS_PRESENTACION_H
