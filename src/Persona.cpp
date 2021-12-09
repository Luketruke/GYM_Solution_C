#include <iostream>

using namespace std;
#include "Persona.h"

Persona::Persona()
{
}

void Persona::setCodigo(int codigo)
{
    _codigo = codigo;
}

void Persona::setEstado(bool estado)
{
    _estado = estado;
}
