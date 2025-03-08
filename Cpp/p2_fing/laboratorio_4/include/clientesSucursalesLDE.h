/*
  Módulo de definición de 'TClientesSucursalesLDE'.

  Los elementos de tipo TClientesSucursalesLDE es un lista doblemente encadenada de TClientesABB,
  con puntero al inicio y al final de la lista.

  Laboratorio de Programación 2. InCo-FIng-UDELAR
 */
#ifndef CLIENTESSUCURSALESLDE_H
#define CLIENTESSUCURSALESLDE_H

#include "clientesABB.h"

// Define el tipo TClientesSucursalesLDE como un puntero a rep_clientesSucursalesLDE
typedef struct rep_clientesSucursalesLDE *TClientesSucursalesLDE;

// Función para crear una nueva TClientesSucursalesLDE vacía
// Devuelve una colección vacía.
// La función es Theta(1) peor caso.
TClientesSucursalesLDE crearTClientesSucursalesLDEVacia();

// Función para insertar ordenadamente una coleccion de clientesABB en la lista de sucursales según
// la edad promedio (menor a mayor). Si ya existe uno o más clientesABB con la misma edad promedio,
// el nuevo es agregado a continuación de estos.
// La función es O(n) peor caso, siendo n la cantidad de clientesABB (sucursales) en la colección
void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal);

// Función que elimina la lista con todos sus ClientesABBs. También libera
// la memoria de los clientes.
// La función es O(n*m) peor caso, donde n es la cantidad de sucursales en la colección y m
// es la máxima cantidad de clientes en la sucursal con más clientes.
void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE);

// Función para imprimir secuencialmente los clientesABB de menor a mayor, según la edad promedio.
// La función es O(n*m) peor caso, donde n es la cantidad de sucursales en la colección y m es la
// máxima cantidad de clientes en las sucursales.
// El formato de impresión es:
// clientesSucursalesLDE de grupos:
  //  <y luego para cada grupo se repite>
  //  Grupo con edad promedio <edad promedio>:
  //  <imprimir el grupo con función imprimirTClientesABB>

// Nota: la edad promedio se imprime con 2 dígitos después de la coma (formato '%.2f').
void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);

// Función para imprimir secuencialmente los clientesABB de mayor a menor, según la edad promedio.
// La función es O(n*m) peor caso, donde n es la cantidad de sucursales en la colección y m es la
// máxima cantidad de clientes en el grupo más grande.
// El formato de impresión es idéntico que en la función 'imprimirTClientesSucursalesLDE'
void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);

// Función quer retorna la cantidad de grupos clientesABB en la colección.
// La función es O(n) peor caso, donde n es la cantidad de grupos en la colección
nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);

// Función para obtener el primer grupo de clientesABB en la lista de sucursales
// La función es O(1) peor caso.
// PRE: la lista no es vacía
TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);

// Función para obtener un grupo clientesABB en la lista de grupos (sucursales). 'n' indica el índice desde el
// inicio (base 1, invocar con n = 1 devuelve el primer elemento).
// La función es O(n) peor caso, siendo n la cantidad de clientesABB o sucursales en la lista.
// En caso de que n sea mayor que la cantidad de sucursales en la lista retorna NULL
// PRE: n > 0
TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n);

// Función para eliminar el último grupo (clientesABB) en la lista de sucursales.
// Retorna el grupo (clientesABB) removido.
// La función es O(1) en peor caso
// PRE: la lista no es vacía
TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);

// Función para eliminar el n-esimo grupo de la lista de sucursales 'n' indica el índice desde el
// inicio (base 1, invocar con n = 1 devuelve el primer elemento).
// Retorna el grupo removido.
// La función es O(n) en el peor caso, siendo n la cantidad de clientesABB en la lista.
// PRE: Hay al menos n elementos en la lista
// PRE: n > 0
TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n);

// Dada una coleccion de clientesABB, regresa el cliente que se encuentre en la mayor
// cantidad de clientesABB (sucursales). Un cliente se considera repetido si su
// id es el mismo. Si todos los clientesABB de la colección están vacíos o si
// la colección de clientesABB es vacía, retorna NULL. Si hay varios clientes empatados
// en apariciones, se retorna aquel con menor id.
// La función es O(n*n*m*m) peor caso, donde n es la cantidad de sucursales en la colección y m es la
// máxima cantidad de clientesABB en el grupo más grande.
TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE);

#endif // CLIENTESSUCURSALESLDE_H

