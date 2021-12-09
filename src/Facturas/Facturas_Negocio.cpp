#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <rlutil.h>
#include <vector>

using namespace std;
#include "../include/Facturas/Facturas_Negocio.h"
#include "../include/Facturas/Facturas_Archivo.h"
#include "../include/Facturas/Factura.h"
#include "../include/Usuarios/Usuarios_Archivo.h"
#include "../include/Clientes/Clientes_Archivo.h"
#include "../include/Clientes/Clientes_Negocio.h"
#include "../include/Stock/Stock_Negocio.h"
#include "../include/Fecha/Fecha.h"

constexpr int C_STRING_NOMBRE = 100;
constexpr int C_STRING_DIRECCION = 50;

#define STRING(num) STR(num)
#define STR(num) #num

fstream MyFile;

Facturas_Negocio::Facturas_Negocio()
{
}

bool Facturas_Negocio::CargarDatosFactura(float subTotalFactura, float descuento,
        float totalFactura, int vendedor, float comisiones, int codigoCliente,
        Fecha fecha, int idFactura)
{
    Facturas_Archivo fc_db;

    fc_db.setVendedor(vendedor);
    fc_db.setSubtotalFactura(subTotalFactura);
    fc_db.setTotalFactura(totalFactura);
    fc_db.setDescuento(descuento);
    fc_db.setIDFactura(idFactura);
    fc_db.setComisiones(comisiones);
    fc_db.setCodigoCliente(codigoCliente);
    fc_db.setFecha(fecha);
    if(fc_db.grabarEnDisco())
        return true;
    else
        return false;
}

///SE LEE EL ARCHIVO PARA LLENAR EL REGISTRO FACTURA

bool Facturas_Negocio::ObtenerDatosComisiones(int &nroFC,char *nombreVendedor,
        float &comision,int &dia,int &mes,int &anio,int pos)
{
    Facturas_Archivo fc_db;
    Usuarios_Archivo user_db;

    int i=0;

    if(fc_db.leerDeDisco(pos))
    {
        while(user_db.leerDeDisco(i))
        {
            if(user_db.getCodigoUsuario()==fc_db.getVendedor())
                strcpy(nombreVendedor,user_db.getNombreCompleto());
            i++;
        }
        nroFC = fc_db.getIdFactura_Realizada();
        comision = fc_db.getComisiones();
        dia = fc_db.getFecha().getDia();
        mes = fc_db.getFecha().getMes();
        anio = fc_db.getFecha().getAnio();
        return true;
    }
    else
        return false;
}

void Facturas_Negocio::obtenerRegistrosFacturas(vector<Factura>& vFacturas)
{
    Clientes_Archivo cl_db;
    Facturas_Archivo fc_db;
    Usuarios_Archivo user_db;

    char nombreVendedor[100];

    int pos=0, pos2, pos3, dia, mes, anio;

    while(fc_db.leerDeDisco(pos))
    {
        pos2=0;
        while(cl_db.leerDeDisco(pos2))
        {
            pos3=0;
            if(fc_db.getCodigoCliente()==cl_db.getCodigoCliente())
            {
                Factura fc;

                dia = fc.getDia();
                mes = fc.getMes();
                anio = fc.getAnio();

                fc.setCodigoCliente(cl_db.getCodigoCliente());
                fc.setNombreCompletoCliente(cl_db.getNombreCompletoCliente());
                fc.setDireccionCliente(cl_db.getDireccionCliente());
                fc.setDocumentoCliente(cl_db.getDocumentoCliente());
                fc.setTotalFactura(fc_db.getTotal());
                fc.setComisiones(fc_db.getComisiones());
                fc.setVendedor(fc_db.getVendedor());
                fc.setDescuento(fc_db.getDescuento());
                fc.setDia(fc_db.getFecha().getDia());
                fc.setMes(fc_db.getFecha().getMes());
                fc.setAnio(fc_db.getFecha().getAnio());
                fc.setIDFactura(fc_db.getIdFactura_Realizada());
                fc.setSubtotalFactura(fc_db.getSubtotal());

                while(user_db.leerDeDisco(pos3))
                {
                    strcpy(nombreVendedor,user_db.getNombreCompleto());
                    pos3++;
                }

                fc.setNombreCompletoVendedor(nombreVendedor);
                vFacturas.push_back(fc);
            }
            pos2++;
        }
        pos++;
    }
}

float Facturas_Negocio::obtenerPorcentajeXVentaVendedor(int vendedor)
{
    Usuarios_Archivo user_db;
    float pXVenta;
    int i=0;
    while (user_db.leerDeDisco(i)==true)
    {
        if(user_db.getCodigoUsuario()==vendedor)
        {
            pXVenta=user_db.getPorcentajeXVenta();
            return pXVenta;
        }
        i++;
    }
}

int Facturas_Negocio::obtenerIDFacturaActual()
{
    Facturas_Archivo fc_db;

    int idFactura;

    idFactura = fc_db.getIDFactura();

    return idFactura;
}

///CALCULOS

float Facturas_Negocio::CalcularTotalFC(float auxTotal, float descuento)
{
    float total;
    total = auxTotal - descuento;

    return total;
}

float Facturas_Negocio::CalcularComision(float total, float pXVenta)
{
    float comision;
    comision = (pXVenta*total)/100;
    return comision;
}

string Facturas_Negocio::CalcularNumeroFC(int nroFC)
{
    string nro_fc;
    if(nroFC>=10000000) nro_fc = {"0001-"};
    if(nroFC>=1000000) nro_fc = {"0001-0"};
    if(nroFC>=100000) nro_fc = {"0001-00"};
    if(nroFC>=10000) nro_fc = {"0001-000"};
    if(nroFC>=1000) nro_fc = {"0001-0000"};
    if(nroFC>=100) nro_fc = {"0001-00000"};
    if(nroFC>=10) nro_fc = {"0001-000000"};
    if(nroFC<10) nro_fc = {"0001-0000000"};
    return nro_fc;
}

string Facturas_Negocio::MostrarFechasFacturas(int dia, int mes, int anio)
{
    string fecha, strdia, strmes, stranio;

    ostringstream diaAux;
    diaAux<<dia;
    strdia = diaAux.str();

    ostringstream mesAux;
    mesAux<<mes;
    strmes = mesAux.str();

    ostringstream anioAux;
    anioAux<<anio;
    stranio = anioAux.str();

    if(dia<10)
    {
        fecha = {"0"};
        fecha+= strdia;
        fecha+= {"/"};
        fecha+= strmes;
        fecha+= {"/"};
        fecha+= stranio;
    }
    else
    {
        fecha+= strdia;
        fecha+= {"/"};
        fecha+= strmes;
        fecha+= {"/"};
        fecha+= stranio;
    }
    return fecha;
}

///EXPORTADOR A EXCEL

void Facturas_Negocio::ExportToExcel()
{
    Facturas_Negocio fc_neg;

    fstream ReadFile("Reportes/facturas.csv",ios::in);
    string nro_FC_Completo, NumFC, Fecha, TotalFC= {' '}, NombreCompleto, Direccion, CodigoCliente, Documento;
    int dia, mes, anio;

    if(!ReadFile)
    {
        fstream CreateFile("Reportes/facturas.cvs", ios::out);
        CreateFile<<"NumFC,Fecha,TotalFC,CodigoCliente,Documento,Nombre,Apellido,Direccion"<<endl;
    }

    MyFile.open("Reportes/facturas.csv", ios::app);

    vector<Factura> vFacturas;
    fc_neg.obtenerRegistrosFacturas(vFacturas);

    NumFC = {"N°FC"};
    Fecha = {"FECHA"};
    TotalFC = {"TOTAL FC"};
    CodigoCliente = {"CODIGO CLIENTE"};
    NombreCompleto = {"NOMBRE COMPLETO"};
    Direccion = {"DIRECCION"};
    Documento = {"DOCUMENTO"};
    MyFile<<NumFC+","<<Fecha<<","<<TotalFC+","<<CodigoCliente+","<<Documento+","<<NombreCompleto+","<<Direccion<<endl;

    for(int i=0; i<vFacturas.size(); i++)
    {
        TotalFC = {'$'};

        NumFC = fc_neg.CalcularNumeroFC(vFacturas.at(i).getIdFactura_Realizada());

        ostringstream num_FC_2;
        num_FC_2<<vFacturas.at(i).getIdFactura_Realizada();
        NumFC += num_FC_2.str();

        ostringstream total_FC;
        total_FC<<vFacturas.at(i).getTotal(); //TOTAL DE LA FACTURA
        TotalFC += total_FC.str();
        TotalFC.erase(std::remove(TotalFC.begin(), TotalFC.end(), ' '), TotalFC.end());

        dia = vFacturas.at(i).getDia();
        mes = vFacturas.at(i).getMes();
        anio = vFacturas.at(i).getAnio();

        Fecha = fc_neg.MostrarFechasFacturas(dia,mes,anio);

        ostringstream codigo_cliente;
        codigo_cliente<<vFacturas.at(i).getCodigoCliente();
        CodigoCliente = codigo_cliente.str();

        ostringstream documento_cliente;
        documento_cliente<<vFacturas.at(i).getDocumentoCliente();
        Documento = documento_cliente.str();

        string nombre_completo_cliente(C_STRING_NOMBRE, 100);
        memmove(&nombre_completo_cliente[0], vFacturas.at(i).getNombreCompletoCliente(), C_STRING_NOMBRE);
        NombreCompleto = nombre_completo_cliente;
        NombreCompleto.erase(std::remove(NombreCompleto.begin(), NombreCompleto.end(), ';'), NombreCompleto.end());

        string direccion_cliente(C_STRING_DIRECCION, 50);
        memmove(&direccion_cliente[0], vFacturas.at(i).getDireccionCliente(), C_STRING_DIRECCION);
        Direccion=direccion_cliente;
        Direccion.erase(std::remove(Direccion.begin(), Direccion.end(), ';'), Direccion.end());

        MyFile<<NumFC+","<<Fecha<<","<<TotalFC+","<<CodigoCliente+","<<Documento+","<<NombreCompleto+","<<Direccion<<endl;
    }
    MyFile.close();
}

///VALIDACION

bool Facturas_Negocio::ValidarFactura(int idFactura)
{
    int i=0;

    Facturas_Archivo fc_db;

    while(fc_db.leerDeDisco(i))
    {
        while(fc_db.getIdFactura_Realizada()==idFactura)
        {
            return true;
        }
        i++;
    }
    return false;
}
