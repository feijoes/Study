#include "../include/tablaQuejas.h"
#include <cassert>

typedef struct req_lista_queja *TListaQueja;

struct req_lista_queja
{
  TQueja cabeza;
  TListaQueja sig;
};

struct rep_tablaQuejas
{
  int cantEstimadas;
  TListaQueja *quejas;
};

int funcionHash(TFecha fecha, int cantEstimadas)
{
  return (31 * (int)mesTFecha(fecha) + (int)diaTFecha(fecha)) % cantEstimadas;
}

TListaQueja crearTListaQuejaConCabeza(TQueja cabeza)
{
  TListaQueja lista = new req_lista_queja;
  lista->cabeza = cabeza;
  lista->sig = NULL;
  return lista;
}

TablaQuejas crearTablaQuejas(int cantEstimadas)
{
  TablaQuejas tabla = new rep_tablaQuejas;
  tabla->cantEstimadas = cantEstimadas;
  tabla->quejas = new TListaQueja[cantEstimadas + 1];
  for (int i = 0; i <= cantEstimadas; ++i)
  {
    tabla->quejas[i] = NULL;
  }
  return tabla;
}
void insertarQuejaTListaQuejas(TListaQueja &lista, TQueja queja)
{
  TListaQueja nueva = crearTListaQuejaConCabeza(queja);
  nueva->sig = lista;
  lista = nueva;
}

void agregarQuejaTablaQuejas(TablaQuejas tabla, TQueja queja)
{
  int i = funcionHash(fechaTQueja(queja), tabla->cantEstimadas);
  insertarQuejaTListaQuejas(tabla->quejas[i], queja); 
}
void imprimirTListaQueja(TListaQueja lista)
{
  while (lista != NULL)
  {
    imprimirTQueja(lista->cabeza);
    lista = lista->sig;
  }
}
void imprimirTablaQuejas(TablaQuejas tabla)
{
  for (int i = 0; i < tabla->cantEstimadas; i++)
  {
    if (tabla->quejas[i] == NULL)
    {
      printf("No hay elementos guardados en la posicion %d de la tabla.\n", i);
    }
    else
    {
      printf("Elementos en la posicion %d de la tabla:\n", i);
      imprimirTListaQueja(tabla->quejas[i]);
    }
  }
}

bool perteneceQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha)
{
  TListaQueja lista =  tabla->quejas[funcionHash(fecha, tabla->cantEstimadas)];
  while (lista != NULL)
  {
    if (compararTFechas(fecha, fechaTQueja(lista->cabeza)) == 0)
    {
      return true;
    }
    lista = lista->sig;
  }
  return false;
}

TQueja ObtenerQuejaTlistaQuejas(TListaQueja lista, TFecha fecha)
{
  if (lista == NULL)
  {
    return NULL;
  }
  if (compararTFechas(fecha, fechaTQueja(lista->cabeza)) == 0)
  {
    return lista->cabeza;
  }
  return ObtenerQuejaTlistaQuejas(lista->sig, fecha);
}

TQueja obtenerQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha)
{
  return ObtenerQuejaTlistaQuejas(tabla->quejas[funcionHash(fecha, tabla->cantEstimadas)], fecha);
}


void liberarTListaQueja(TListaQueja &lista){
  while (lista != NULL)
  {
    TListaQueja aux = lista;
    lista = lista->sig;
    liberarTQueja(aux->cabeza);
    delete aux;
  }
}
void liberarTablaQuejas(TablaQuejas &tabla)
{
  for (int i = 0; i <= tabla->cantEstimadas; i++)
  {
    if (tabla->quejas[i] != NULL)
    {
      liberarTListaQueja(tabla->quejas[i]);
    }
  }
  delete[] tabla->quejas;
  delete tabla;
  tabla = NULL;
}
