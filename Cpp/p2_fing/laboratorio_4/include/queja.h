/*
  Módulo de definición de 'TQueja'.

  Los elementos de tipo TQueja almacenan un elementos de tipo TCliente, TProducto, un comentario y una fecha.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef QUEJA_H
#define QUEJA_H
#include "producto.h"
#include "cliente.h"

// Constante para definir el largo máximo del comentario
const int MAX_COMENTARIO = 100;


// Define el tipo TQueja como un puntero a rep_queja
typedef struct rep_queja *TQueja;

// Función para crear un elemento de tipo TQueja.
// fecha es la fecha de la queja
// La función es O(1) peor caso.
TQueja crearTQueja(TFecha fecha, TProducto producto, TCliente cliente, const char comentario[MAX_COMENTARIO]);

// Se imprimen la queja empleando el siguiente formato:
//   Fecha: <fecha_queja>
//   Cliente: <cliente>
//   Producto: <producto>
//   Comentario: <comentario>
// La impresión del cliente se realiza con la función 'imprimirTCliente'.
// La impresión del producto se realiza con la función 'imprimirTProducto'.
// La impresión de la fecha se realiza con la función 'imprimirTFecha'.
void imprimirTQueja(TQueja queja);

// Función que libera la memoria asignada para la queja.
// Deja el puntero Queja apuntando a NULL.
// Ejecuta en O(1) peor caso 
void liberarTQueja(TQueja &queja);

// Devuelve la fecha de la Queja
// La función ejecuta en O(1) peor caso
TFecha fechaTQueja(TQueja queja);

#endif // QUEJA_H  










