/*
  Módulo de definición de 'TProducto'.

  Los elementos de tipo TProducto son elementos que almacenan un id, el nombre
  del producto, la fecha de ingreso del producto y el precio.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string.h>

#include "fecha.h"

// Constante para definir el largo máximo del nombre de un producto
const int MAX_NOMBRE_PRODUCTO = 100;

// Define el tipo TProducto como un puntero a rep_producto
typedef struct rep_producto *TProducto;

// Función que crea un elemento de tipo TProducto con los valores pasados como
// parámetro Ejecuta en O(1) peor caso.
TProducto crearTProducto(int id, const char nombre[MAX_NOMBRE_PRODUCTO],
                         int precio, TFecha fechaIngreso);

// Función que retorna el id del producto
// Ejecuta en O(1) peor caso.
int idTProducto(TProducto producto);

// Función que retorna el precio del producto
// Ejecuta en O(1) peor caso.
int precioTProducto(TProducto producto);

// Función que imprime la información de un producto en el siguiente formato:
// Producto: <Id>
// <NombreProducto>
// Precio: <precio>
// Ingresado el: <Fecha>
// Ejecuta en O(1) peor caso
void imprimirTProducto(TProducto producto);

// Función que libera la memoria asociada a un producto
// Ejecuta en O(1) peor caso
void liberarTProducto(TProducto &producto);

#endif // PRODUCTO_H
