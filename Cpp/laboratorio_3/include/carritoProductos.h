/*
  Módulo de definición de 'TCarritoProductos'.

  Los elementos de tipo TCarritoProductos almacenan una coleccion de elementos de tipo TProducto.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef CARRITOPRODUCTOS_H
#define CARRITOPRODUCTOS_H

#include "producto.h"

// Define el tipo TCarritoProductos como un puntero a rep_carrito
typedef struct rep_carritoProductos *TCarritoProductos;

// Función para crear un elemento de tipo TCarritoProductos.
// Devuelve un carrito de productos vacío.
// La función es Theta(1) peor caso.
TCarritoProductos crearCarritoProductosVacio();

// Función para agregar un producto a un carrito de productos.
// Inserta el producto en el carrito, ordenado de menor a mayor por ID producto.
// La función es Theta(n) peor caso, siendo n la cantidad de productos en el carrito
// PRE: no existe producto con el mismo id en la carrito
void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto);

// Función para imprimir todos los productos de un carrito.
// El formato en el que se debe imprimir el carrito es utilizando de forma secuencial la función imprimirTProducto.
// Si la colección está vacía no imprime nada.
// La función es Theta(n) peor caso, siendo n la cantidad de productos en el carrito.
void imprimirCarritoProductos(TCarritoProductos carritoProductos);

// Función para liberar un carrito de productos
// Recibe una referencia a un elemento de tipo TCarritoProductos y libera su memoria
// Libera además la memoria de cada uno de los productos en el carrito.
// La función es Theta(n) peor caso, siendo n la cantidad de productos en el carrito.
void liberarCarritoProductos(TCarritoProductos &carritoProductos);

// Funcion para verificar si una carrito de productos es vacio, retorna true si y solo si el carrito es vacío
// La función es Theta(1) peor caso
bool esVacioCarritoProductos(TCarritoProductos carritoProductos);

// Función para verificar si un producto existe en un carrito de productos.
// Recibe una carrito de productos y un id de producto y regresa un booleano indicando su existencia.
// La función es Theta(n) peor caso, siendo n la cantidad de produtos en el carrito.
bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto);

// Función para obtener un producto de un carrito de productos.
// Recibe un carrito y un id de producto y regresa el producto con ese id.
// La función es Theta(n) peor caso, siendo n la cantidad de productos en el carrito
// PRE: El producto debe estar en el carrito
TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto);

// Función para remover un producto de un carrito.
// Recibe un carrito de productos y un id de producto y elimina el producto con ese id.
// También elimina la memoria asociada a dicho producto.
// La función es Theta(n) peor caso, siendo n la cantidad de productos en el carrito.
// PRE: El producto debe estar en el carrito
void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto);

#endif // CARRITOPRODUCTOS_H  
