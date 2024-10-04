#include "../include/historial.h"

struct rep_historial
{
    TListaPromociones pasada, activas, futuras;
    TFecha fecha;
};

THistorial crearTHistorial(TFecha fecha)
{
    THistorial a_crear = new rep_historial;
    a_crear->pasada = NULL;
    a_crear->activas = NULL;
    a_crear->futuras = NULL;
    a_crear->fecha = fecha;
    return a_crear;
}

// pasado -1 activo 0 futuro 1
int promocionStatus(TPromocion promocion, TFecha fechaActual)
{
    if (compararTFechas(fechaActual, fechaInicioTPromocion(promocion)) == -1)
    {
        return 1;
    }
    if (compararTFechas(fechaActual, fechaFinTPromocion(promocion)) == 1)
    {
        return -1;
    }
    return 0;
}

void agregarPromocionTHistorial(THistorial historial, TPromocion promocion)
{
    int status = promocionStatus(promocion, historial->fecha);
    switch (status)
    {
    case -1:
        agregarPromocionTListaPromociones(historial->pasada, promocion);
        break;
    case 0:
        agregarPromocionTListaPromociones(historial->activas, promocion);
        break;
    case 1:
        agregarPromocionTListaPromociones(historial->futuras, promocion);
        break;
    }
}

void agregarProductoAPromocionTHistorial(THistorial historial,
                                         TProducto producto, int idPromo)
{
    TListaPromociones temp = historial->pasada;

    if (pertenecePromocionTListaPromociones(historial->futuras, idPromo))
    {
        temp = historial->futuras;
    }
    else if (pertenecePromocionTListaPromociones(historial->activas, idPromo))
    {
        temp = historial->activas;
    }
    TPromocion promo = obtenerPromocionTListaPromociones(temp, idPromo);
    agregarATPromocion(promo, producto);
}

void imprimirPromocionesFinalizadosTHistorial(THistorial historial)
{
    imprimirTListaPromociones(historial->pasada);
}

void imprimirPromocionesActivasTHistorial(THistorial historial)
{
    imprimirTListaPromociones(historial->activas);
}

void imprimirPromocionesFuturasTHistorial(THistorial historial)
{
    imprimirTListaPromociones(historial->futuras);
}

bool esCompatiblePromocionTHistorial(THistorial historial,
                                     TPromocion promocion)
{
    return esCompatibleTListaPromociones(historial->pasada, promocion) && esCompatibleTListaPromociones(historial->futuras, promocion) && esCompatibleTListaPromociones(historial->activas, promocion);
    int status = promocionStatus(promocion, historial->fecha);
    switch (status)
    {
    case -1:
        return esCompatibleTListaPromociones(historial->pasada, promocion);
    case 0:
        return esCompatibleTListaPromociones(historial->activas, promocion);
    case 1:
        return esCompatibleTListaPromociones(historial->futuras, promocion);
    }
    return false;
}

void liberarTHistorial(THistorial &historial)
{
    if (historial == NULL)
    {
        return;
    }
    liberarTListaPromociones(historial->pasada, true);
    liberarTListaPromociones(historial->activas, true);
    liberarTListaPromociones(historial->futuras, true);
    liberarTFecha(historial->fecha);
    delete historial;
    historial = NULL;
}

void avanzarAFechaTHistorial(THistorial historial, TFecha fecha)
{
    liberarTFecha(historial->fecha);
    historial->fecha = fecha;

    TListaPromociones nuevasPasadas = obtenerPromocionesFinalizadas(historial->activas, fecha);
    TListaPromociones nuevasActivas = obtenerPromocionesActivas(historial->futuras, fecha);
    
    TListaPromociones old_activa = historial->activas;

    historial->pasada = unirListaPromociones(historial->pasada, nuevasPasadas);
    historial->activas = unirListaPromociones(historial->activas, nuevasActivas);

    liberarTListaPromociones(nuevasPasadas, false);
    liberarTListaPromociones(nuevasActivas, false);
    liberarTListaPromociones(old_activa, false);
}