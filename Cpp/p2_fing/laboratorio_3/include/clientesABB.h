/*
  Módulo de definición de 'TClientesABB'.

  Los elementos de tipo TClientesABB almacenan una coleccion de elementos de tipo TCliente.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef CLIENTESABB_H
#define CLIENTESABB_H

#include "cliente.h"

// Define el tipo TClientesABB como un puntero a rep_clientesABB.
typedef struct rep_clientesABB *TClientesABB;

// Función para crear un nuevo grupo vacío.
// Devuelve un nuevo árbol binario vacío.
// La funcion es Theta(1) peor caso.
TClientesABB crearTClientesABBVacio();

// Función para insertar un Cliente en el árbol binario, por id.
// La funcion es Theta(n) peor caso, siendo n la cantidad de Clientes en el grupo.
// PRE: El Cliente no está en el grupo.
void insertarTClienteTClientesABB(TClientesABB &clientesABB, TCliente cliente);

// Función para imprimir los Clientes del grupo en orden de id. La impresión
// de los clientes se realiza con la función 'imprimirTCliente'.
// La función es Theta(n) peor caso, donde n es la cantidad de clientes en el grupo.
void imprimirTClientesABB(TClientesABB clientesABB);

// Función para liberar la memoria asignada a un grupo.
// La función es Theta(n) peor caso, donde n es la cantidad de clientes en el grupo.
void liberarTClientesABB(TClientesABB &clientesABB);

// Función que determina si un cliente está en el árbol binario.
// Devuelve true si el cliente está en el grupo, false en caso contrario.
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de clientes en el grupo.
bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente);

// Función para obtener un cliente del árbol binario.
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de clientes en el grupo
// PRE: el cliente está en el grupo
TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente);

// Funcion para obtener la altura del árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de clientes en el grupo
nat alturaTClientesABB(TClientesABB clientesABB);

// Función para obtener el cliente con el id más grande del árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de clientes en el árbol binario
// PRE: el árbol binario no es vacío
TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB);

// Función para eliminar un cliente del árbol binario.
// En caso de que el nodo a remover tenga ambos subárboles no vacíos, se
// reemplaza por el cliente con el id más grande del subárbol izquierdo. 
// La función es Theta(n) peor caso, donde n es la cantidad de clientes en el grupo.
// PRE: El cliente está en el grupo
void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente);

// Función para obtener la cantidad de clientes en el árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de clientes en el grupo
int cantidadClientesTClientesABB(TClientesABB clientesABB);

// Funcion para obtener la edad promedio de los clientes. Si no hay clientes en el grupo devuelve 0.
// La funcion es Theta(n) peor caso, siendo n la cantidad de clientes en el grupo.
float edadPromedioTClientesABB(TClientesABB clientesABB);

// Función para obtener el Nesimo cliente del grupo. El órden de los clientes
// se considera por orden de 'id', con base 1.
// Ejemplos:  
//  obtenerNesimoClienteTClientesABB(grupo, 1) devuelve el cliente con menor id
//  obtenerNesimoClienteTClientesABB(grupo, 2) devuelve el segundo cliente con menor id
//  obtenerNesimoClienteTClientesABB(grupo, cantidadClientesTClientesABB(grupo)) devuelve el 
//  cliente con mayor id.
// La funcion es Theta(m) peor caso, siendo m la cantidad de clientes en el grupo.
// PRE: cantidadClientesTClientesABB(grupo) >= n
// PRE: n > 0 
TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n);

#endif // CLIENTESABB_H  

