#ifndef PLANES_PRESENTACION_H
#define PLANES_PRESENTACION_H


class Planes_Presentacion
{
    public:
        Planes_Presentacion();

        void CargarPlanVista();

        void MostrarPlanesVista();

        void BajaPlanVista();

        void SubMenuPlanesVista();

        void MostrarPlanXCodigo(int);

        bool ValidarNombrePlan(char *);

        bool ValidarInfoPlan(char *);

        int ValidarIngresoPlan();

        float ValidarIngresoPrecio();
};

#endif // PLANES_PRESENTACION_H
