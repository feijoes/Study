/*
  Módulo de definición de 'TListaPromociones'.

  Los estructura de tipo TListaPromociones es una lista de promociones.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef LISTAPROMOCIONES_H
#define LISTAPROMOCIONES_H

#include "promocion.h"
#include "utils.h"

typedef struct rep_listaPromociones *TListaPromociones;

// Función para crear un elemento de tipo TListaPromociones.
// Devuelve una lista vacía.
// La función es O(1) peor caso.
TListaPromociones crearTListaPromocionesVacia();

// Función para agregar una promoción a una lista de promociones.
// Inserta la promoción en la lista de promociones ordenada de menor a mayor por
// fecha de inicio de la promoción. En caso de empate la promoción se
// almacena antes de las existentes con misma fecha.
// La función es O(n) peor caso, siendo n la cantidad de promociones en la
// lista PRE: no existe promoción con el mismo id en la lista
void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones,
                                       TPromocion promocion);

// Función para imprimir todas las promociones de una lista de promociones.
// El formato en el que se debe imprimir la lista es utilizando de forma
// secuencial la función imprimirTPromocion. Si la lista es vacía no imprime
// nada. La función es Theta(n*m) peor caso, siendo n la cantidad de promociones
// en la lista de promociones y m la cantidad máxima de productos en las promociones.
void imprimirTListaPromociones(TListaPromociones listaPromociones);

// Función para liberar una lista de promociones
// Recibe una referencia a un elemento de tipo TListaPromociones y libera su
// memoria Si 'liberarPromociones' es true, libera además la memoria de cada una
// de las promociones en la colección. La función es O(n) peor caso, siendo n
// la cantidad de promociones en la lista.
void liberarTListaPromociones(TListaPromociones &listaPromociones,
                              bool liberarPromociones);

// Funcion para verificar si una lista de promociones es vacia. Retorna true si
// y solo si la lista es vacia. La función es O(1) peor caso.
bool esVaciaTListaPromociones(TListaPromociones promociones);

// Función para verificar si una promoción existe en la lista de promociones.
// Recibe una lista de promociones y un id de promoción y regresa un booleano
// indicando si pertenece a la lista . La función es O(n) peor caso, siendo n la
// cantidad de promociones en la lista.
bool pertenecePromocionTListaPromociones(TListaPromociones listaPromociones,
                                         int idPromocion);

// Función para obtener una promoción de una lista de promociones.
// Recibe una lista de promociones y un id de promoción y regresa la
// promoción con ese id. La función es O(n) peor caso, siendo n la cantidad de
// promociones en la lista PRE: La promoción pertenece a la lista.
TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones,
                                             int idPromocion);

// Dada una lista de promociones y una fecha, devuelve una nueva lista de
// promociones con las promociones que finalizaron. Remueve las promociones
// finalizadas de la lista parámetro. La función es O(n) peor caso, donde n es
// la cantidad de promociones de la lista.
TListaPromociones obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,
                                                TFecha fecha);

// Dada una lista de promociones y una fecha, devuelve una nueva lista de
// promociones con las promociones que están activas. Remueve las promociones
// activas de la lista parámetro. La función es O(n) peor caso, donde n es la
// cantidad de promociones de la lista.
TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,
                                            TFecha fecha);

// Dada una lista de promociones y una promocion, devuelve true si la
// promoción es compatible con todas las promociones de la lista. La función
// es O(n) peor caso, donde n es la cantidad de promociones de la lista.
bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,
                                   TPromocion promocion);

// Dadas dos listas de promociones, devuelve una nueva lista de promociones
// con todos los elementos de ambas listas. La función es O(n1 + n2) peor caso,
// donde n es la cantidad de cantidad de promociones en la primera lista y n2
// la cantidad de promociones en la segunda lista.
// PRE: las listas no tienen promociones en común (no tienen ids repetidos)
TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1,
                                       TListaPromociones listaPromociones2);

#endif // LISTAPROMOCIONES_H
