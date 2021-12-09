#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include "../include/Clientes/Clientes_Presentacion.h"
#include "../include/Clientes/Clientes_Negocio.h"
#include "../include/Clientes/Clientes_Archivo.h"
#include "../include/Clientes/Cliente.h"

Clientes_Negocio::Clientes_Negocio()
{
}

///CARGA DE CLIENTE EN ARCHIVO

int Clientes_Negocio::CargarCliente(int documento, const char *nombreCompleto, const char *direccion)
{
    Clientes_Archivo cl_db;

    int codCliente = cl_db.getIDCliente();

    cl_db.setCodigoCliente(codCliente);
    cl_db.setDocumentoCliente(documento);
    cl_db.setNombreCompletoCliente(nombreCompleto);
    cl_db.setDireccionCliente(direccion);
    cl_db.setEstadoCliente(true);

    if(cl_db.grabarEnDisco())
        return codCliente;
    else
        return 0;
}

///LLENO REGISTRO CLIENTE

Cliente Clientes_Negocio::ObtenerDatosClientesXCodigo(int idCliente)
{
    Clientes_Archivo cl_db;
    Cliente cl;

    int pos=0;

    while(cl_db.leerDeDisco(pos))
    {
        if(idCliente==cl_db.getCodigoCliente() && cl_db.getEstado() == true)
        {
            cl.setNombreCompleto(cl_db.getNombreCompletoCliente());
            cl.setDireccion(cl_db.getDireccionCliente());
            cl.setDocumento(cl_db.getDocumentoCliente());
            cl.setCodigo(cl_db.getCodigoCliente());
        }
        pos++;
    }
    return cl;
}

void Clientes_Negocio::obtenerRegistrosClientes(vector<Cliente>& vClientes)
{
    Clientes_Archivo cl_db;

    int pos=0;

    while(cl_db.leerDeDisco(pos))
    {
        if(cl_db.getEstado()==true)
        {
            Cliente cl;

            cl.setNombreCompleto(cl_db.getNombreCompletoCliente());
            cl.setDireccion(cl_db.getDireccionCliente());
            cl.setDocumento(cl_db.getDocumentoCliente());
            cl.setCodigo(cl_db.getCodigoCliente());
            vClientes.push_back(cl);
        }
        pos++;
    }
}

///VALIDACIONES

bool Clientes_Negocio::BajaClienteValidar(int codCliente)
{
    system("cls");

    Clientes_Archivo cl_db;

    int i= 0;

    while (cl_db.leerDeDisco(i)== true)
    {
        if(cl_db.getCodigoCliente()==codCliente && cl_db.getEstado()==true)
        {
            cl_db.setEstadoCliente(false);
            if(cl_db.modificarEnDisco(i))
                return true;
        }
        i++;
    }
}

bool Clientes_Negocio::ValidarCliente(int idCliente)
{
    int i=0;

    Clientes_Archivo cl_db;

    while(cl_db.leerDeDisco(i))
    {
        while(cl_db.getCodigoCliente()==idCliente)
        {
            return true;
        }
        i++;
    }
    return false;
}

int Clientes_Negocio::ValidarDocumento(int documento)
{
    Clientes_Archivo cl_db;

    int i=0, tam;

    tam = std::to_string(documento).length();

    if(tam==7 || tam==8)
    {
        while(cl_db.leerDeDisco(i))
        {
            if(documento==cl_db.getDocumentoCliente())
                return 2;
            i++;
        }
        return 1;
    }
    else
    {
        return 3;
    }
}
