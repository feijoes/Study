/*
  Módulo de definición de 'TablaQuejas'.

  Los elementos de tipo TablaQuejas almacenan una colección de TQuejas en forma
  de tabla.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef tablaQuejas_H
#define tablaQuejas_H
#include "queja.h"

// Define el tipo TablaQuejas como un puntero a rep_tablaQuejas
typedef struct rep_tablaQuejas *TablaQuejas;

// Función para crear una nueva tabla de quejas. El parámetro cantEstimadas
// indica la cantidad de quejas que se espera almacenar en esta estructura.
TablaQuejas crearTablaQuejas(int cantEstimadas);

// Agrega una queja a la estructura.
// La función es O(1) peor caso. 
// PRE: no existe una queja con la misma fecha en la estructura.
void agregarQuejaTablaQuejas(TablaQuejas tabla, TQueja queja);

// Imprime la tabla de quejas de la siguiente forma:
// Para cada posición i entre 0 y cantEstimadas de la tabla:
//     Si no hay una queja guardada en dicha posición, imprime
//        No hay elementos guardados en la posicion i de la tabla.
//     Si hay queja las imprime (en el orden que aparecen) utilizando la función
//     imprimirTQueja: Elementos en la posicion <i> de la tabla: <queja_1>
//     <queja_2>
//     ...
//     <queja_N>
void imprimirTablaQuejas(TablaQuejas tabla);

// Devuelve true si existe una queja para la fecha indicada y false en caso
// contrario. La función es O(1) caso promedio.
bool perteneceQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha);

// Obtiene la queja para la fecha indicada. Si no existe una queja para la fecha
// indicada devuelve NULL.
// Esta función no elimina la queja de la tabla.
// La función es O(1) caso promedio.
TQueja obtenerQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha);

// Función que libera la memoria asignada a la tabla.
// También libera la memoria de las queja que se encuentren en la estructura.
// Finalmente, modifica el valor tabla para que apunte a NULL;
// Ejecuta en O(n) peor caso, donde n es la cantidad de quejas en la tabla.
void liberarTablaQuejas(TablaQuejas &tabla);

#endif // tablaQuejas_H
