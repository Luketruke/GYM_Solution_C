#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <rlutil.h>

using namespace std;
#include "../include/Stock/Stock_Negocio.h"
#include "../include/Stock/Stock_Database.h"
#include "../include/Stock/Stock_Presentacion.h"


Stock_Database::Stock_Database()
{
}

void Stock_Database::setStock(int stock)
{
    _stock = stock;
}

void Stock_Database::setCodigoArticulo(int codigoArticulo)
{
    _codigoArticulo = codigoArticulo;
}

bool Stock_Database::grabarEnDisco()
{
    FILE* p;
    p = fopen("Database/stock.dat", "ab");
    if (p == NULL)
    {
        return false;
    }

    if (fwrite(this, sizeof(Stock_Database), 1, p))
    {
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}

bool Stock_Database::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("Database/stock.dat", "rb");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Stock_Database) * pos, 0);

    if (fread(this, sizeof(Stock_Database), 1, p))
    {
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}
