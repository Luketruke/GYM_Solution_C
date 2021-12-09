#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"

class Cliente : public Persona
{
protected:
    char _direccion[100];
    int _documento;

public:
    Cliente();

    void setDireccion(const char *direccion)
    {
        strcpy(_direccion, direccion);
    };

    void setDocumento(int);

    char *getDireccion()
    {
        return _direccion;
    };

    int getDocumento()
    {
        return _documento;
    };
};

#endif // CLIENTE_H
