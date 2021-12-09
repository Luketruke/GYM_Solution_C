#ifndef PLANES_ARCHIVO_H
#define PLANES_ARCHIVO_H
#include <cstring>

class Planes_Archivo
{
private:
    int _codigoPlan;
    char _nombrePlan[100];
    char _infoPlan[1000];
    float _precio;
    bool _estado;
public:
    Planes_Archivo();

    void setNombrePlan(const char *nombrePlan)
    {
        strcpy(_nombrePlan, nombrePlan);
    };

    void setInfoPlan(const char *infoPlan)
    {
        strcpy(_infoPlan, infoPlan);
    };

    void setEstadoPlan(bool estado);

    void setPrecio(float precio);

    void setCodigoPlan(int codigoPlan);

    int getCodigoPlan(){return _codigoPlan;};

    char *getNombrePlan(){return _nombrePlan;};

    char *getInfoPlan(){return _infoPlan;};

    bool getEstado(){return _estado;};

    float getPrecio(){return _precio;};

    int getIDPlan();

    bool leerDeDisco(int pos);

    bool grabarEnDisco();

    bool modificarEnDisco(int pos);
};

#endif // PLANES_ARCHIVO_H
