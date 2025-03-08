#include "../include/conjuntoProductos.h"

// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoproductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
struct rep_conjuntoProductos
{
    int cantMax;
    int cantElementos;
    int *elementos;
};

TConjuntoProductos crearTConjuntoProductos(int cantMax)
{
    TConjuntoProductos conjunto = new rep_conjuntoProductos;
    conjunto->cantMax = cantMax;
    conjunto->cantElementos = 0;
    conjunto->elementos = new int[cantMax];
    for (int i = 0; i < cantMax; i++)
    {
        conjunto->elementos[i] = 0;
    }
    return conjunto;
}

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto)
{
    if (idProducto >= conjuntoProductos->cantMax || conjuntoProductos->elementos[idProducto] == 1)
    {
        return;
    }
    conjuntoProductos->elementos[idProducto] = 1;
    conjuntoProductos->cantElementos++;
}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
    int cantElementImprimidos = 0;
    for (int i = 0; i < conjuntoProductos->cantMax && cantElementImprimidos < conjuntoProductos->cantElementos; i++)
    {
        if (conjuntoProductos->elementos[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos)
{
    delete[] conjuntoProductos->elementos;
    delete conjuntoProductos;
    conjuntoProductos = NULL;
}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
    return conjuntoProductos->cantElementos == 0;
}

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
    return conjuntoProductos->cantElementos;
}

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
    return conjuntoProductos->cantMax;
}

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto)
{
    if (idProducto >= conjuntoProductos->cantMax || conjuntoProductos->elementos[idProducto] == 0)
    {
        return false;
    }
    return true;
}

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto)
{
    if (idProducto >= conjuntoProductos->cantMax || conjuntoProductos->elementos[idProducto] == 0)
    {
        return;
    }
    conjuntoProductos->elementos[idProducto] = 0;
    conjuntoProductos->cantElementos--;
}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2)
{
    TConjuntoProductos conjunto_union = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    int cantElementAgregados = 0;

    for (int i = 0; i < conjuntoProductos1->cantMax && cantElementAgregados < conjuntoProductos1->cantElementos; i++)
    {
        if (conjuntoProductos2->elementos[i] == 1 || conjuntoProductos1->elementos[i] == 1)
        {
            insertarTConjuntoProductos(conjunto_union, i);
        }
    }
    return conjunto_union;
}

TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2)
{
    TConjuntoProductos conjunto_intersecion = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    int cantElementAgregados = 0;
    for (int i = 0; i < conjuntoProductos1->cantMax && cantElementAgregados < conjuntoProductos1->cantElementos && cantElementAgregados < conjuntoProductos2->cantElementos; i++)
    {
        if (conjuntoProductos1->elementos[i] == conjuntoProductos2->elementos[i] && conjuntoProductos1->elementos[i] == 1)
        {
            insertarTConjuntoProductos(conjunto_intersecion, i);
        }
    }
    return conjunto_intersecion;
}

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2)
{
    TConjuntoProductos conjunto_diferencia = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    int cantElementAgregados = 0;
    for (int i = 0; i < conjuntoProductos1->cantMax && cantElementAgregados < conjuntoProductos1->cantElementos && cantElementAgregados < conjuntoProductos2->cantElementos; i++)
    {
        if (conjuntoProductos1->elementos[i] != conjuntoProductos2->elementos[i] && conjuntoProductos1->elementos[i] == 1)
        {
            insertarTConjuntoProductos(conjunto_diferencia, i);
        }
    }
    return conjunto_diferencia;
}
