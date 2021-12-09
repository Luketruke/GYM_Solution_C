#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace std;
#include "../include/Planes/Planes_Negocio.h"
#include "../include/Planes/Planes_Archivo.h"
#include "../include/Planes/Planes_Presentacion.h"
#include "../include/Planes/Plan.h"

Planes_Negocio::Planes_Negocio()
{
}

bool Planes_Negocio::CargarPlan(const char *nombrePlan,
                                const char *infoPlan,
                                float precio)
{
    Planes_Archivo plan_db;

    plan_db.setCodigoPlan(plan_db.getIDPlan());
    plan_db.setNombrePlan(nombrePlan);
    plan_db.setInfoPlan(infoPlan);
    plan_db.setPrecio(precio);
    plan_db.setEstadoPlan(true);

    if(plan_db.grabarEnDisco())
        return true;
    else
        return false;
}

void Planes_Negocio::obtenerRegistrosPlanes(vector<Plan>& vPlanes)
{
    Planes_Archivo plan_db;

    int pos=0;

    while(plan_db.leerDeDisco(pos))
    {
        if(plan_db.getEstado()==true)
        {
            Plan p;

            p.setCodigo(plan_db.getCodigoPlan());
            p.setEstado(plan_db.getEstado());
            p.setDescripcion(plan_db.getNombrePlan());
            p.setPrecio(plan_db.getPrecio());
            p.setInfo(plan_db.getInfoPlan());

            vPlanes.push_back(p);
        }
        pos++;
    }
}

Plan Planes_Negocio::ObtenerDatosPlanXCodigo(int idPlan)
{
    Planes_Archivo plan_db;
    Plan p;

    int pos=0;

    while(plan_db.leerDeDisco(pos))
    {
        if(idPlan==plan_db.getCodigoPlan() && plan_db.getEstado() == true)
        {
            p.setCodigo(plan_db.getCodigoPlan());
            p.setDescripcion(plan_db.getNombrePlan());
            p.setPrecio(plan_db.getPrecio());
            p.setEstado(plan_db.getEstado());
            p.setInfo(plan_db.getInfoPlan());
        }
        pos++;
    }
    return p;
}

bool Planes_Negocio::BajaPlan(int codPlan)
{
    Planes_Archivo plan_db;

    int i=0;

    while(plan_db.leerDeDisco(i))
    {
        if(plan_db.getCodigoPlan()==codPlan && plan_db.getEstado()==true)
        {
            plan_db.setEstadoPlan(false);
            if(plan_db.modificarEnDisco(i))
                return true;
        }
        i++;
    }
    return false;
}

bool Planes_Negocio::ValidarCodigo(int codPlan)
{
    Planes_Archivo plan_db;

    int i=0;

    while(plan_db.leerDeDisco(i))
    {
        while(plan_db.getCodigoPlan()==codPlan && plan_db.getEstado()==true)
        {
            return true;
        }
        i++;
    }
    return false;
}
