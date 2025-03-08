/*
  Modulo de definición de 'TEnvio'
  Los elementos de tipo TEnvio representan el envío a un cliente.
  Los envíos están formados por un carrito de productos, con los
  productos comprados por el cliente, y una fecha, que representa
  cuando deberá hacerse el envío.
*/

#ifndef ENVIO_H
#define ENVIO_H

#include "carritoProductos.h"

// Define el tipo TEnvio como un puntero a rep_envio
typedef struct rep_envio *TEnvio;

// Función para crear un elemento de tipo TEnvio.
// 'carrito' es el carrito de productos asociado al envío y
// 'fecha' es la fecha en la cual deberá realizarse el envío.
// La función es O(1) en el pero caso.
TEnvio crearTEnvio(TCarritoProductos carrito, TFecha fecha);

// Procedimiento que libera la memoria asignada.
// Deja el puntero de la variable envio en NULL.
// El procedimiento es O(n) pero caso, siendo n la cantidad
// de productos en el carrito.
void liberarTEnvio(TEnvio &envio);

// Funcion que retorna el carrito de productos asociado
// al 'envio'. La función debera ser O(1) en el peor caso.
TCarritoProductos obtenerCarritoProductosTEnvio(TEnvio envio);

// Función que retorna la fecha del envío.
// La función debera ser O(1) peor caso.
TFecha obtenerFechaTEnvio(TEnvio envio);

// Procedimiento que imprime la información de un envío.
// El procedimiento imprime el carrito de productos y la fecha del envio.
// La impresión se realiza con el siguiente formato:
//   <carrito_de_productos>
//   Fecha del envio: <fecha>
// El procedimiento deberá ser O(n) siendo n la cantidad de productos
// dentro del envio.
void imprimirTEnvio(TEnvio envio);

#endif // ENVIO_H
