#ifndef PERSONA_H
#define PERSONA_H
#include <cstring>

class Persona
{
protected:
    char _nombreCompleto[100];
    int _codigo;
    bool _estado;

public:
    Persona();

    void setNombreCompleto(const char *nombreCompleto)
    {
        strcpy(_nombreCompleto, nombreCompleto);
    };

    void setCodigo(int);

    void setEstado(bool);

    char *getNombreCompleto()
    {
        return _nombreCompleto;
    };

    int getCodigo()
    {
        return _codigo;
    };

    bool getEstado(){return _estado;};
};

#endif // PERSONA_H
