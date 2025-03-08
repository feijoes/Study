/*
  Módulo de definición de 'TCliente'.

  Los elementos de tipo TCliente son elementos que almacenan un id, un nombre, un apellido y una edad.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>

#include "fecha.h"


// Constante para definir el largo máximo del nombre y apellido del cliente
const int MAX_NOMBRE = 100;
const int MAX_APELLIDO = 100;

// Define el tipo TCliente como un puntero a rep_cliente
typedef struct rep_cliente *TCliente;

// Función que crea un elemento de tipo TCliente con los valores pasados por parámetro
// Ejecuta en O(1) peor caso
TCliente crearTCliente(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad);

// Función que imprime la información de UN cliente en el siguiente formato:
  // Cliente <nombre> <apellido>
  // Id: <idCliente>
  // Edad: <edad>
// Ejecuta en O(1) peor caso
void imprimirTCliente(TCliente cliente);

// Función que libera la memoria asignada a un cliente
// Ejecuta en O(1) peor caso
void liberarTCliente(TCliente &cliente);

// Función que retorna el nombre del cliente
// Ejecuta en O(1) peor caso
void nombreTCliente(TCliente cliente, char nombre[MAX_NOMBRE]);

// Función que retorna el apellido del cliente
void apellidoTCliente(TCliente cliente, char apellido[MAX_APELLIDO]);

// Función que retorna el id del cliente
// Ejecuta en O(1) peor caso
int idTCliente(TCliente cliente);

// Función que retorna la edad del cliente
// Ejecuta en O(1) peor caso
int edadTCliente(TCliente cliente);

// Función que copia un cliente. La copia no comparte memoria con el cliente pasado por parámetro.
// Ejecuta en O(1) peor caso
TCliente copiarTCliente(TCliente cliente);

#endif  // CLIENTE_H