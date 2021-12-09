#ifndef PLANES_NEGOCIO_H
#define PLANES_NEGOCIO_H
#include "../include/Planes/Plan.h"
#include <vector>

class Planes_Negocio
{
public:
    Planes_Negocio();

    bool CargarPlan(const char *,const char *,float);

    bool BajaPlan(int);

    void MostrarPlanXCodigo(int);

    void obtenerRegistrosPlanes(vector<Plan>&);

    Plan ObtenerDatosPlanXCodigo(int);

    bool ValidarCodigo(int);
};

#endif // PLANES_NEGOCIO_H
