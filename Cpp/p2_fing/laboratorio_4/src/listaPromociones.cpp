#include "../include/listaPromociones.h"

struct rep_listaPromociones {
  TListaPromociones sig;
  TPromocion promocion;
};

TListaPromociones crearTListaPromocionesVacia() { return NULL; }

void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones,
                                       TPromocion promocion) {
  TFecha inicioPromocion = fechaInicioTPromocion(promocion);

  TListaPromociones nuevoElemento = new rep_listaPromociones;
  nuevoElemento->promocion = promocion;
  nuevoElemento->sig = NULL;

  if ((esVaciaTListaPromociones(listaPromociones)) ||
      (compararTFechas(inicioPromocion,
                       fechaInicioTPromocion(listaPromociones->promocion)) <=
       0)) {
    nuevoElemento->sig = listaPromociones;
    listaPromociones = nuevoElemento;
  } else {
    TListaPromociones iter = listaPromociones;
    while (iter->sig != NULL &&
           compararTFechas(inicioPromocion,
                           fechaInicioTPromocion(iter->sig->promocion)) > 0) {
      iter = iter->sig;
    }
    nuevoElemento->sig = iter->sig;
    iter->sig = nuevoElemento;
  }
}

bool esVaciaTListaPromociones(TListaPromociones promociones) {
  return promociones == NULL;
}

void imprimirTListaPromociones(TListaPromociones listaPromociones) {
  TListaPromociones iter = listaPromociones;
  while (iter != NULL) {
    imprimirTPromocion(iter->promocion);
    iter = iter->sig;
  }
}

bool pertenecePromocionTListaPromociones(TListaPromociones listaPromociones,
                                         int idPromocion) {
  while (listaPromociones != NULL &&
         idTPromocion(listaPromociones->promocion) != idPromocion) {
    listaPromociones = listaPromociones->sig;
  }
  return listaPromociones != NULL;
}

TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones,
                                             int idPromocion) {
  while (idTPromocion(listaPromociones->promocion) != idPromocion) {
    listaPromociones = listaPromociones->sig;
  }
  return listaPromociones->promocion;
}

void liberarTListaPromociones(TListaPromociones &listaPromociones,
                              bool liberarPromociones) {
  TListaPromociones aux = listaPromociones;
  if (liberarPromociones) {
    while (listaPromociones != NULL) {
      aux = listaPromociones;
      listaPromociones = listaPromociones->sig;
      liberarTPromocion(aux->promocion);
      delete aux;
    }
  } else {
    while (listaPromociones != NULL) {
      aux = listaPromociones;
      listaPromociones = listaPromociones->sig;
      delete aux;
    }
  }
}

TListaPromociones
obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,
                              TFecha fecha) {
  TListaPromociones inicioListaPromociones = listaPromociones;
  TListaPromociones nueva = NULL;
  TListaPromociones nuevaInicio = NULL;

  bool finPrimerTramo = false;
  while ((listaPromociones != NULL) && !finPrimerTramo &&
         (inicioListaPromociones == listaPromociones)) {
    TFecha fechaFinPromocion = fechaFinTPromocion(listaPromociones->promocion);
    if (compararTFechas(fechaFinPromocion, fecha) < 0) {
      if (nueva == NULL) {
        nueva = listaPromociones;
        nuevaInicio = nueva;
      } else {
        nueva->sig = listaPromociones;
        nueva = nueva->sig;
      }
      listaPromociones = listaPromociones->sig;
      inicioListaPromociones = listaPromociones;
      nueva->sig = NULL;
    } else {
      finPrimerTramo = true;
    }
  }
  if (listaPromociones != NULL) {
    while (listaPromociones->sig != NULL) {
      TListaPromociones inspecciono = listaPromociones->sig;
      TFecha fechaFinPromocion = fechaFinTPromocion(inspecciono->promocion);
      if (compararTFechas(fechaFinPromocion, fecha) < 0) {
        listaPromociones->sig = inspecciono->sig;
        inspecciono->sig = NULL;
        if (nuevaInicio == NULL) {
          nueva = inspecciono;
          nuevaInicio = nueva;
        } else {
          nueva->sig = inspecciono;
          nueva = nueva->sig;
        }
      } else {
        listaPromociones = listaPromociones->sig;
      }
    }
  }
  listaPromociones = inicioListaPromociones;
  return nuevaInicio;
}

TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,
                                            TFecha fecha) {
  TListaPromociones inicioListaPromociones = listaPromociones;
  TListaPromociones nueva = NULL;
  TListaPromociones nuevaInicio = NULL;

  bool finPrimerTramo = false;
  while ((listaPromociones != NULL) && !finPrimerTramo &&
         (inicioListaPromociones == listaPromociones)) {
    TFecha fechaIniPromocion =
        fechaInicioTPromocion(listaPromociones->promocion);
    TFecha fechaFinPromocion = fechaFinTPromocion(listaPromociones->promocion);
    if ((compararTFechas(fechaIniPromocion, fecha) <= 0) &&
        (compararTFechas(fechaFinPromocion, fecha) >= 0)) {
      if (nueva == NULL) {
        nueva = listaPromociones;
        nuevaInicio = nueva;
      } else {
        nueva->sig = listaPromociones;
        nueva = nueva->sig;
      }
      listaPromociones = listaPromociones->sig;
      inicioListaPromociones = listaPromociones;
      nueva->sig = NULL;
    } else {
      finPrimerTramo = true;
    }
  }
  if (listaPromociones != NULL) {
    while (listaPromociones->sig != NULL) {
      TListaPromociones inspecciono = listaPromociones->sig;
      TFecha fechaIniPromocion =
          fechaInicioTPromocion(listaPromociones->promocion);
      TFecha fechaFinPromocion =
          fechaFinTPromocion(listaPromociones->promocion);
      if ((compararTFechas(fechaIniPromocion, fecha) <= 0) &&
          (compararTFechas(fechaFinPromocion, fecha) >= 0)) {
        listaPromociones->sig = inspecciono->sig;
        inspecciono->sig = NULL;
        if (nuevaInicio == NULL) {
          nueva = inspecciono;
          nuevaInicio = nueva;
        } else {
          nueva->sig = inspecciono;
          nueva = nueva->sig;
        }
      } else {
        listaPromociones = listaPromociones->sig;
      }
    }
  }
  listaPromociones = inicioListaPromociones;
  return nuevaInicio;
}

bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,
                                   TPromocion promocion) {
  TListaPromociones iter = listaPromociones;
  while (iter != NULL) {
    if (!sonPromocionesCompatibles(promocion, iter->promocion)) {
      return false;
    }
    iter = iter->sig;
  }
  return true;
}

TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1,
                                       TListaPromociones listaPromociones2) {
  TListaPromociones nueva = crearTListaPromocionesVacia();

  TListaPromociones iter = listaPromociones1;
  while (iter != NULL) {
    agregarPromocionTListaPromociones(nueva, iter->promocion);
    iter = iter->sig;
  }

  iter = listaPromociones2;
  while (iter != NULL) {
    agregarPromocionTListaPromociones(nueva, iter->promocion);
    iter = iter->sig;
  }
  return nueva;
}

