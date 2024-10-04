#include "../include/promocion.h"

//  La estructura almacena un id de tipo entero, dos fechas para representar el inicio y el fin
// de la promocion, así como la información de qué productos forman parte de la promocion.
struct rep_promocion
{
    int idProm;
    TFecha ini, fin;
    int cantMax;
    TConjuntoProductos productos;
};

TPromocion crearTPromocion(int idProm, TFecha ini, TFecha fin, int cantMax)
{
    TPromocion prom = new rep_promocion;
    prom->idProm = idProm;
    prom->ini = ini;
    prom->fin = fin;
    prom->cantMax = cantMax;
    prom->productos = crearTConjuntoProductos(cantMax);
    return prom;
}
TPromocion copiaTPromocion(TPromocion prom) {
    return crearTPromocion(idTPromocion(prom), fechaInicioTPromocion(prom), fechaFinTPromocion(prom), prom->cantMax);
}

void agregarATPromocion(TPromocion &prom, TProducto p)
{
    insertarTConjuntoProductos(prom->productos, idTProducto(p));
}

int idTPromocion(TPromocion prom)
{
    return prom->idProm;
}

void imprimirTPromocion(TPromocion prom)
{

    printf("Promocion #%d del ", idTPromocion(prom));
    imprimirTFecha(prom->ini);
    printf(" al ");
    imprimirTFecha(prom->fin);
    printf("\nProductos: ");
    imprimirTConjuntoProductos(prom->productos);
}

void liberarTPromocion(TPromocion &prom)
{
    liberarTConjuntoProductos(prom->productos);
    liberarTFecha(prom->ini);
    liberarTFecha(prom->fin);
    delete prom;
    prom = NULL;
}

bool perteneceATPromocion(TPromocion prom, TProducto p)
{
    return perteneceTConjuntoProductos(prom->productos, idTProducto(p));
}

TFecha fechaInicioTPromocion(TPromocion prom)
{
    return prom->ini;
}

TFecha fechaFinTPromocion(TPromocion prom)
{
    return prom->fin;
}

bool sonPromocionesCompatibles(TPromocion prom1, TPromocion prom2)
{
    if (idTPromocion(prom1) == idTPromocion(prom2))
    {
        return true;
    }
    if (compararTFechas(fechaFinTPromocion(prom1), fechaInicioTPromocion(prom2)) == -1)
    {
        return true;
    }
    if (compararTFechas(fechaFinTPromocion(prom2), fechaInicioTPromocion(prom1)) == -1)
    {
        return true;
    }
    TConjuntoProductos intersecion = interseccionTConjuntoProductos(prom1->productos, prom2->productos);
    if (esVacioTConjuntoProductos(intersecion)){
        liberarTConjuntoProductos(intersecion);
        return true;
    }
    liberarTConjuntoProductos(intersecion);
    return false;
}
