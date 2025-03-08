/*
  Módulo de definición de 'TConjuntoProductos'.

  Los estructura de tipo TConjuntoProductos es un conjunto acotado que almacena ids de productos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef CONJUNTO_PRODUCTOS_H
#define CONJUNTO_PRODUCTOS_H

#include "utils.h"

// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoProductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de 
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
typedef struct rep_conjuntoProductos* TConjuntoProductos;

// Función para crear un nuevo conjunto de productos.
// Devuelve un conjunto vacío
// La funcion es Theta(n) peor caso, siendo n la cantidad máxima de elementos del conjunto
TConjuntoProductos crearTConjuntoProductos(int cantMax);

// Función para determinar si un conjunto de productos es vacío
// Devuelve true si el conjunto es vacío, false en otro caso
// La funcion es O(1) peor caso
bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos);

// Procedimiento para insertar el identificador "idProducto" en el conjunto "conjuntoProductos".
// Si "idProducto" no pertenece al rango válido de ids del conjunto "conjuntoProductos" la función no hace nada.
// Si "idProducto" ya pertenece al conjunto, la función no hace nada.
// La función es O(1) peor caso.
void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto);

// Procedimiento para borrar al "idProducto" del conjunto de productos "conjuntoProductos"
// Si "idProducto" no pertenece al conjunto "conjuntoProductos" la función no hace nada
// La función es O(1) peor caso
void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto);

// Función para determinar si el identificador "idProducto" pertenece al conjunto "conjuntoProductos"
// Devuelve true si pertenece, false en otro caso
// La funcion es O(1) peor caso
bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto);

// Función que retorna la cantidad de elementos del conjunto de productos "conjuntoProductos".
// La función es O(1) peor caso.
int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos);

// Función que retorna la cantidad máxima de elementos del conjunto de productos "conjuntoProductos".
// La función es O(1) peor caso.
int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos);

// Procedimiento para imprimir el conjunto de productos.
// Imprime los ids de las productos del conjunto ordenado de menor a mayor.
// Deben imprimirse solamente los elementos, separados por un espacio, con un salto de línea al final.
// Ejemplo: si el conjunto "conjuntoProductos" tiene los elementos 7, 29, 42 y 75 la impresión debe ser "7 29 42 75 ".
// La función es O(n) peor caso, siendo "n" la cantidad máxima de elementos de "conjuntoProductos".
void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos);

// Procedimiento para liberar la memoria asignada a un conjunto de productos.
// La funcion es O(1) peor caso.
void liberarTConjuntoProductos(TConjuntoProductos &c);

// Función que retorna la unión entre los conjuntos de productos "conjuntoProductos1" y "conjuntoProductos2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// La función es O(n) peor caso.
TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2);

// Función que retorna la intersección entre los conjuntos de c "conjuntoProductos1" y "conjuntoProductos2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// La función es O(n) peor caso.
TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2);

// Función que retorna la diferencia entre los conjuntos de productos "conjuntoProductos1" y "conjuntoProductos2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// La función es O(n) peor caso.
TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2);

#endif  // CONJUNTO_PRODUCTOS_H
