#ifndef FECHA_H
#define FECHA_H

class Fecha
{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha();
    string MostrarFecha();
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;}
};


#endif // FECHA_H
