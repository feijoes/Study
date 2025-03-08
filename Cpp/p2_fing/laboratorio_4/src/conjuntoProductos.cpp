#include "../include/conjuntoProductos.h"

struct rep_conjuntoProductos
{
  bool *mapaBits;
  int cantidad;
  int cantMax;
};

TConjuntoProductos crearTConjuntoProductos(int cantMax)
{
  TConjuntoProductos conjuntoProductos = new rep_conjuntoProductos;
  conjuntoProductos->mapaBits = new bool[cantMax];
  for (int i = 0; i < cantMax; i++)
  {
    conjuntoProductos->mapaBits[i] = false;
  }
  conjuntoProductos->cantidad = 0;
  conjuntoProductos->cantMax = cantMax;
  return conjuntoProductos;
}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  return conjuntoProductos->cantidad == 0;
}

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto)
{
  if (idProducto >= 0 && idProducto < conjuntoProductos->cantMax && !perteneceTConjuntoProductos(conjuntoProductos, idProducto))
  {
    conjuntoProductos->mapaBits[idProducto] = true;
    conjuntoProductos->cantidad++;
  }
}

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto)
{
  if (perteneceTConjuntoProductos(conjuntoProductos, idProducto))
  {
    conjuntoProductos->mapaBits[idProducto] = false;
    conjuntoProductos->cantidad--;
  }
}

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto)
{
  return  idProducto >= 0 && idProducto < conjuntoProductos->cantMax && conjuntoProductos->mapaBits[idProducto];
}

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  return conjuntoProductos->cantidad;
}

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  return conjuntoProductos->cantMax;
}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  for (int i = 0; i < conjuntoProductos->cantMax; i++)
  {
    if (perteneceTConjuntoProductos(conjuntoProductos, i))
    {
      printf("%d ", i);
    }
  }
  printf("\n");
}

void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos)
{
  delete[] conjuntoProductos->mapaBits;
  delete conjuntoProductos;
  conjuntoProductos = NULL;
}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2)
{
  TConjuntoProductos conjuntoUnion = crearTConjuntoProductos(conjuntoProductos1->cantMax);
  for (int i = 0; i < conjuntoProductos1->cantMax; i++)
  {
    if (perteneceTConjuntoProductos(conjuntoProductos1, i) || perteneceTConjuntoProductos(conjuntoProductos2, i))
    {
      insertarTConjuntoProductos(conjuntoUnion, i);
    }
  }
  return conjuntoUnion;
}

TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2)
{
  TConjuntoProductos conjuntoInterseccion = crearTConjuntoProductos(conjuntoProductos1->cantMax);
  for (int i = 0; i < conjuntoProductos1->cantMax; i++)
  {
    if (perteneceTConjuntoProductos(conjuntoProductos1, i) && perteneceTConjuntoProductos(conjuntoProductos2, i))
    {
      insertarTConjuntoProductos(conjuntoInterseccion, i);
    }
  }
  return conjuntoInterseccion;
}

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2)
{
  TConjuntoProductos conjuntoDiferencia = crearTConjuntoProductos(conjuntoProductos1->cantMax);
  for (int i = 0; i < conjuntoProductos1->cantMax; i++)
  {
    if (perteneceTConjuntoProductos(conjuntoProductos1, i) && !perteneceTConjuntoProductos(conjuntoProductos2, i))
    {
      insertarTConjuntoProductos(conjuntoDiferencia, i);
    }
  }
  return conjuntoDiferencia;
}
