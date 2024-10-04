/*
  Módulo de definición de 'THistorial'.

  Los elementos de tipo THistorial contiene las estructuras necesarias para
  gestionar el historial (o histórico) de promociones. Un tipo THistorial tiene:
    - Un ConjuntoProductos con los productos del historial
    - Una Fecha que representa la fecha actual.
    - Una lista de promociones finalizadas.
    - Una lista de promociones activas.
    - Una lista de promociones futuras.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "fecha.h"
#include "listaPromociones.h"
#include "producto.h"

typedef struct rep_historial *THistorial;

// Crea una THistorial sin productos ni promociones, con la fecha actual pasada por
// parámetro. La función es O(1)
THistorial crearTHistorial(TFecha fecha);

// Agrega la promocion al historial.
// PRE: esCompatiblePromocionHistorial
// La función es O(n) siendo n la cantidad de promociones en la lista.
void agregarPromocionTHistorial(THistorial historial, TPromocion promocion);

// Agrega el producto pasado como parámetro a la promoción con id 'idPromo'
// PRE: existen una producto en el historial con id 'idProducto'
// PRE: existe una promoción en el historial con id 'idPromo'
// La función es O(n) siendo n la máxima cantidad de promociones en las listas.
void agregarProductoAPromocionTHistorial(THistorial historial,
                                         TProducto producto, int idPromo);

// Realiza la modificación lógica de la fecha. Modifica la fecha
// del historial y las listas de promociones para reflejar cuáles están
// finalizadas, cuáles activas y cuáles siguen siendo futuras. PRE: la fecha
// parámetro es posterior a la fecha actual de la historial
// La función es O(n) siendo n la máxima cantidad de promociones en las listas.
void avanzarAFechaTHistorial(THistorial historial, TFecha fecha);

// Imprime las promociones finalizadas.
// La función es O(n) donde n es el número de promociones finalizadas.
void imprimirPromocionesFinalizadosTHistorial(THistorial historial);

// Imprime las promociones activas.
// La función es O(n) donde n es el número de promociones activas.
void imprimirPromocionesActivasTHistorial(THistorial historial);

// Imprime las promociones futuras.
// La función es O(n) donde n es el número de promociones futuras.
void imprimirPromocionesFuturasTHistorial(THistorial historial);

// Devuelve true si la promoción 'promocion' es compatible con el resto de las
// promociones del historial
// La función es O(n) siendo n la máxima cantidad de promociones en las listas.
bool esCompatiblePromocionTHistorial(THistorial historial,
                                     TPromocion promocion);

// Libera la memoria utilizada por la historial
// También libera la memoria de todas las productos y promociones en la
// historial.
// La función es O(n) siendo n la máxima cantidad de promociones en las listas.
void liberarTHistorial(THistorial &historial);

#endif // HISTORIAL_H
