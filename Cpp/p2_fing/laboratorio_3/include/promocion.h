/*
  Módulo de definición de 'TPromocion'.

  Los elementos de tipo TPromocion representan un promoción. La estructura almacena
  un identificador (id) de promocion, dos fechas para representar el inicio y el fin de validez,
  así como la información de qué productos forman parte de la promoción (la integran).

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef PROMOCION_H
#define PROMOCION_H

#include "fecha.h"
#include "producto.h"
#include "conjuntoProductos.h"

// Definición de tipo TPromocion como un puntero a rep_promocion
typedef struct rep_promocion *TPromocion;

// Función para crear un nuevo promocion.
// Devuelve un conjunto vacío.
// La funcion es O(n) peor caso, siendo n la cantidad máxima de productos en la promocion.
TPromocion crearTPromocion(int idProm, TFecha ini, TFecha fin, int cantMax);

// Actualiza la promocion para indicar que el producto "p" forma parte de la promocion.
// La función es O(1) peor caso.
// PRE: p no pertenece a la promocion.
void agregarATPromocion(TPromocion &prom, TProducto p);

// Devuelve true si el producto "p" forma parte de la promocion.
// La función es O(1) peor caso.
bool perteneceATPromocion(TPromocion prom, TProducto p);

// Retorna el id de la promocion.
// La función es O(1) peor caso.
int idTPromocion(TPromocion prom);

// Imprime la promocion con el siguiente formato:
//  Promocion #<id> del <fechaIni> al <fechaFin>
//  Productos: <lista productos>
// La <lista productos> se imprime con el formato dado por 'conjuntoProductos'
// La función es O(n) donde en es el número máximo de productos en la promocion.
void imprimirTPromocion(TPromocion prom);

// Retorna la fecha inicio de la promocion.
// La función es O(1) peor caso.
TFecha fechaInicioTPromocion(TPromocion prom);

// Retorna la fecha fin de la promocion.
// La función es O(1) peor caso.
TFecha fechaFinTPromocion(TPromocion prom);

// Devuelve true si las promociones prom1 y prom2 son compatibles.
// Una promocion es compatible con otra si no comparten productos durante un mismo período de tiempo.
// O de otra manera, no son compatibles si coinciden en el tiempo y además un mismo producto
// es parte de ambas promociones.
// La función es O(n) peor caso.
bool sonPromocionesCompatibles(TPromocion prom1, TPromocion prom2);

// Procedimiento para liberar la memoria asignada a una promocion.
// La función es O(1) peor caso.
void liberarTPromocion(TPromocion &prom);

#endif // PROMOCION_H
