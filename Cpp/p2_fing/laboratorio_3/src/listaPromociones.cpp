#include "../include/listaPromociones.h"

struct rep_listaPromociones
{
  TListaPromociones sig;
  TPromocion promocion;
};

TListaPromociones crearTListaPromocionesVacia() { return NULL; }

TListaPromociones crearTListaPromocionesConPromocion(TPromocion promocion)
{
  TListaPromociones lista = new rep_listaPromociones;
  lista->sig = NULL;
  lista->promocion = promocion;
  return lista;
}

void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones,
                                       TPromocion promocion)
{
  if (listaPromociones == NULL)
  {
    listaPromociones = crearTListaPromocionesConPromocion(promocion);
    return;
  }
  if (compararTFechas(fechaInicioTPromocion(listaPromociones->promocion), fechaInicioTPromocion(promocion)) == -1)
  {
    return agregarPromocionTListaPromociones(listaPromociones->sig, promocion);
  }
  TListaPromociones aux = crearTListaPromocionesConPromocion(promocion);
  aux->sig = listaPromociones;
  listaPromociones = aux;
}

void imprimirTListaPromociones(TListaPromociones listaPromociones)
{
  if (listaPromociones == NULL)
  {
    return;
  }
  imprimirTPromocion(listaPromociones->promocion);
  imprimirTListaPromociones(listaPromociones->sig);
}

void liberarTListaPromociones(TListaPromociones &listaPromociones,
                              bool liberarPromociones)
{
  if (listaPromociones == NULL)
  {
    return;
  }
  if (liberarPromociones == true)
  {
    liberarTPromocion(listaPromociones->promocion);
  }
  liberarTListaPromociones(listaPromociones->sig, liberarPromociones);
  delete listaPromociones;
  listaPromociones = NULL;
}

void liberarSoloTListaPromociones(TListaPromociones &listaPromociones,
                                  bool liberarPromociones)
{
   if (listaPromociones == NULL)
  {
    return;
  }
  if (liberarPromociones == true)
  {
    liberarTPromocion(listaPromociones->promocion);
  }
  delete listaPromociones;
  listaPromociones = NULL;
}

bool esVaciaTListaPromociones(TListaPromociones promociones)
{
  return promociones == NULL;
}

bool pertenecePromocionTListaPromociones(TListaPromociones listaPromociones,
                                         int idPromocion)
{
  if (esVaciaTListaPromociones(listaPromociones))
  {
    return false;
  }
  if (idPromocion == idTPromocion(listaPromociones->promocion))
  {
    return true;
  }
  return pertenecePromocionTListaPromociones(listaPromociones->sig, idPromocion);
}

TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones,
                                             int idPromocion)
{
  if (esVaciaTListaPromociones(listaPromociones))
  {
    return NULL;
  }
  if (idPromocion == idTPromocion(listaPromociones->promocion))
  {
    return listaPromociones->promocion;
  }
  return obtenerPromocionTListaPromociones(listaPromociones->sig, idPromocion);
}

TListaPromociones obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,
                                                TFecha fecha)
{
  if (esVaciaTListaPromociones(listaPromociones))
  {
    return NULL;
  }

  if (compararTFechas(fecha, fechaFinTPromocion(listaPromociones->promocion)) != 1)
  {
    return obtenerPromocionesFinalizadas(listaPromociones->sig, fecha);
  }

  TListaPromociones temp = listaPromociones;
  TListaPromociones a_crear = crearTListaPromocionesConPromocion(listaPromociones->promocion);
  listaPromociones = listaPromociones->sig;
  liberarSoloTListaPromociones(temp, false);
  a_crear->sig = obtenerPromocionesFinalizadas(listaPromociones, fecha);
  return a_crear;
}

TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,
                                            TFecha fecha)
{
  if (esVaciaTListaPromociones(listaPromociones))
  {
    return NULL;
  }

  if (compararTFechas(fecha, fechaInicioTPromocion(listaPromociones->promocion)) == -1 || compararTFechas(fecha, fechaFinTPromocion(listaPromociones->promocion)) == 1)
  {
    return obtenerPromocionesActivas(listaPromociones->sig, fecha);
  }

  TListaPromociones temp = listaPromociones;
  TListaPromociones a_crear = crearTListaPromocionesConPromocion(listaPromociones->promocion);
  listaPromociones = listaPromociones->sig;
  liberarSoloTListaPromociones(temp, false);
  a_crear->sig = obtenerPromocionesActivas(listaPromociones, fecha);
  return a_crear;
}

bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,
                                   TPromocion promocion)
{
  if (listaPromociones == NULL){
    return true;
  }
  if (!sonPromocionesCompatibles(listaPromociones->promocion, promocion)){
    return false;
  }
  return esCompatibleTListaPromociones(listaPromociones->sig, promocion);
}

TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1,
                                       TListaPromociones listaPromociones2)
{
  TListaPromociones promocion_union = crearTListaPromocionesVacia();
  while (!esVaciaTListaPromociones(listaPromociones1))
  {
    agregarPromocionTListaPromociones(promocion_union, listaPromociones1->promocion);
    listaPromociones1 = listaPromociones1->sig;
  }
  while (!esVaciaTListaPromociones(listaPromociones2))
  {
    agregarPromocionTListaPromociones(promocion_union, listaPromociones2->promocion);
    listaPromociones2 = listaPromociones2->sig;
  }
  return promocion_union;
}
