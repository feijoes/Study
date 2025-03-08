#include "../include/promocion.h"

struct rep_promocion
{
  int id;
  TFecha fechaIni;
  TFecha fechaFin;
  TConjuntoProductos productos;
};

TPromocion crearTPromocion(int idProm, TFecha ini, TFecha fin, int cantMax)
{
  TPromocion promocion = new rep_promocion;
  promocion->id = idProm;
  promocion->fechaIni = ini;
  promocion->fechaFin = fin;
  promocion->productos = crearTConjuntoProductos(cantMax);
  return promocion;
}

void agregarATPromocion(TPromocion &prom, TProducto p)
{
  insertarTConjuntoProductos(prom->productos, idTProducto(p));
}

bool perteneceATPromocion(TPromocion prom, TProducto p)
{
  return perteneceTConjuntoProductos(prom->productos, idTProducto(p));
}

int idTPromocion(TPromocion prom)
{
  return prom->id;
}

void imprimirTPromocion(TPromocion prom)
{
  printf("Promocion #%d del ", prom->id);
  imprimirTFecha(prom->fechaIni);
  printf(" al ");
  imprimirTFecha(prom->fechaFin);
  printf("\n");
  printf("Productos: ");
  imprimirTConjuntoProductos(prom->productos);
}

TFecha fechaInicioTPromocion(TPromocion prom)
{
  return prom->fechaIni;
}

TFecha fechaFinTPromocion(TPromocion prom)
{
  return prom->fechaFin;
}

bool sonPromocionesCompatibles(TPromocion prom1, TPromocion prom2)
{
  if ((compararTFechas(prom1->fechaIni, prom2->fechaIni) >= 0 && compararTFechas(prom1->fechaIni, prom2->fechaFin) <= 0) ||
      (compararTFechas(prom1->fechaFin, prom2->fechaIni) >= 0 && compararTFechas(prom1->fechaFin, prom2->fechaFin) <= 0) ||
      (compararTFechas(prom2->fechaIni, prom1->fechaIni) >= 0 && compararTFechas(prom2->fechaIni, prom1->fechaFin) <= 0) ||
      (compararTFechas(prom2->fechaFin, prom1->fechaIni) >= 0 && compararTFechas(prom2->fechaFin, prom1->fechaFin) <= 0))
  {
    // se solapan. Ahora hay que fijarse si comparten productos
    TConjuntoProductos interseccion = interseccionTConjuntoProductos(prom1->productos, prom2->productos);
    bool compatibles = cantidadTConjuntoProductos(interseccion) == 0;
    liberarTConjuntoProductos(interseccion);
    return compatibles;
  }
  return true;
}

void liberarTPromocion(TPromocion &prom)
{
  liberarTFecha(prom->fechaIni);
  liberarTFecha(prom->fechaFin);
  liberarTConjuntoProductos(prom->productos);
  delete prom;
  prom = NULL;
}
