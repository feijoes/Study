/*
  Módulo de definición de 'TColaEnvios'.

  Los elementos de tipo TColaEnvios almacenan una colección de elementos de tipo
  TEnvio. Representan las diferentes compras realizadas junto con su fecha de envío. 
  Se implementa como una cola de prioridad.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef COLAENVIOS_H
#define COLAENVIOS_H

#include "clientesABB.h"
#include "envio.h"

// Define el tipo TColaEnvios como un puntero a rep_cola_envios
typedef struct rep_cola_envios *TColaEnvios;

// Función para crear un elemento de tipo TColaEnvios;
// N es la cantidad máxima de compras pendientes o en espera a ser envíadas.
// La función es O(N) en el peor caso.
TColaEnvios crearTColaEnvios(int N);

// Agrega un envío a la cola de envíos según la prioridad dada por su fecha de
// envío, donde la fecha más reciente es la prioritaria.
void encolarEnvioTColaEnvios(TColaEnvios &colaEnvios, TEnvio envio);

// Devuelve la cantidad de envíos pendientes.
// La función es O(1) en el peor caso.
int cantidadTColaEnvios(TColaEnvios colaEnvios);

// Imprime los envíos dentro de la cola con el formato:
// Nivel 1:
// 1) <Envio 1>
// ...
// Nivel i:
// j) <Envio j>
// j+1) <Envio j+1>
// ...
// La función es O(n * m) en el peor caso, donde n es la cantidad de envíos pendientes y 
// m la cantidad máxima de productos en los envíos.
void imprimirTColaEnvios(TColaEnvios colaEnvios);

// Retira el último envío pendiente y lo regresa.
// La función es O(log(n)) peor caso, donde n es la cantidad máxima de envíos.
// PRE: cantidadTColaEnvios > 0
TEnvio desencolarTColaEnvios(TColaEnvios &colaEnvios);

// Función que libera la memoria asignada.
// Deja el puntero envío apuntando a NULL.
// Ejecuta en O(n*m) en el peor caso, donde n es la cantidad de elementos de la cola y
// m, la cantidad máxima de productos en los envíos.
void liberarTColaEnvios(TColaEnvios &colaEnvios);

// Función que invierte la prioridad dada por la fecha.
// Ahora el envío con fecha más lejana es el más prioritario.
// La función es O(n * log(n)) en el peor caso, donde N es la cantidad máxima de envíos pendientes.
void invertirPrioridadTColaEnvios(TColaEnvios &colaEnvio);

// Función que devuelve el elemento más prioritario.
// La función ejecuta en O(1) en el peor caso.
// PRE: cantidadTColaEnvios > 0
TEnvio masPrioritarioTColaEnvios(TColaEnvios colaEnvio);

// Función que devuelve la cantidad máxima de envios pendientes.
// La función ejecuta en O(1) en el peor caso.
int maxTColaEnvios(TColaEnvios colaEnvio);

#endif // COLAENVIOS_H
