#include "../include/historial.h"

struct rep_historial {
  TFecha fechaActual;
  TListaPromociones promosFuturas;
  TListaPromociones promosActivas;
  TListaPromociones promosPasadas;
};

THistorial crearTHistorial(TFecha fecha) {
  THistorial resultado = new rep_historial;
  resultado->fechaActual = fecha;
  resultado->promosFuturas = crearTListaPromocionesVacia();
  resultado->promosActivas = crearTListaPromocionesVacia();
  resultado->promosPasadas = crearTListaPromocionesVacia();
  return resultado;
}

void agregarPromocionTHistorial(THistorial historial, TPromocion promocion) {
  if (compararTFechas(fechaFinTPromocion(promocion), historial->fechaActual) <
      0) {
    agregarPromocionTListaPromociones(historial->promosPasadas, promocion);
  } else if (compararTFechas(fechaInicioTPromocion(promocion),
                             historial->fechaActual) > 0) {
    agregarPromocionTListaPromociones(historial->promosFuturas, promocion);
  } else {
    agregarPromocionTListaPromociones(historial->promosActivas, promocion);
  }
}

void agregarProductoAPromocionTHistorial(THistorial historial,
                                         TProducto producto, int idPromo) {
  if (pertenecePromocionTListaPromociones(historial->promosPasadas, idPromo)) {
    TPromocion promo =
        obtenerPromocionTListaPromociones(historial->promosPasadas, idPromo);
    agregarATPromocion(promo, producto);
  } else if (pertenecePromocionTListaPromociones(historial->promosActivas,
                                                 idPromo)) {
    TPromocion promo =
        obtenerPromocionTListaPromociones(historial->promosActivas, idPromo);
    agregarATPromocion(promo, producto);
  } else if (pertenecePromocionTListaPromociones(historial->promosFuturas,
                                                 idPromo)) {
    TPromocion promo =
        obtenerPromocionTListaPromociones(historial->promosFuturas, idPromo);
    agregarATPromocion(promo, producto);
  }
}

void avanzarAFechaTHistorial(THistorial historial, TFecha fecha) {
  TListaPromociones finalizadas =
      obtenerPromocionesFinalizadas(historial->promosActivas, fecha);
  TListaPromociones unionFinalizadas =
      unirListaPromociones(finalizadas, historial->promosPasadas);
  liberarTListaPromociones(finalizadas, false);
  liberarTListaPromociones(historial->promosPasadas, false);
  historial->promosPasadas = unionFinalizadas;

  TListaPromociones finalizadasFuturas =
      obtenerPromocionesFinalizadas(historial->promosFuturas, fecha);
  unionFinalizadas =
      unirListaPromociones(finalizadasFuturas, historial->promosPasadas);
  liberarTListaPromociones(finalizadasFuturas, false);
  liberarTListaPromociones(historial->promosPasadas, false);
  historial->promosPasadas = unionFinalizadas;

  TListaPromociones activasFuturas =
      obtenerPromocionesActivas(historial->promosFuturas, fecha);
  TListaPromociones unionActivas =
      unirListaPromociones(activasFuturas, historial->promosActivas);
  liberarTListaPromociones(activasFuturas, false);
  liberarTListaPromociones(historial->promosActivas, false);
  historial->promosActivas = unionActivas;

  liberarTFecha(historial->fechaActual);
  historial->fechaActual = fecha;
}

void imprimirPromocionesFinalizadosTHistorial(THistorial historial) {
  imprimirTListaPromociones(historial->promosPasadas);
}

void imprimirPromocionesActivasTHistorial(THistorial historial) {
  imprimirTListaPromociones(historial->promosActivas);
}

void imprimirPromocionesFuturasTHistorial(THistorial historial) {
  imprimirTListaPromociones(historial->promosFuturas);
}

bool esCompatiblePromocionTHistorial(THistorial historial,
                                     TPromocion promocion) {
  bool compatibleFutura =
      esCompatibleTListaPromociones(historial->promosFuturas, promocion);
  bool compatiblePasadas =
      esCompatibleTListaPromociones(historial->promosPasadas, promocion);
  bool compatibleActivas =
      esCompatibleTListaPromociones(historial->promosActivas, promocion);

  return compatibleFutura && compatiblePasadas && compatibleActivas;
}

void liberarTHistorial(THistorial &historial) {
  liberarTFecha(historial->fechaActual);
  liberarTListaPromociones(historial->promosFuturas, true);
  liberarTListaPromociones(historial->promosActivas, true);
  liberarTListaPromociones(historial->promosPasadas, true);
  delete historial;
  historial = NULL;
}
