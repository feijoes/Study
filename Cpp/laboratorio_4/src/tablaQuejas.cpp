#include "../include/tablaQuejas.h"

struct rep_tablaQuejas { 
  int cantEstimadas;
  TQueja *queja;
  int cant;
};

int funcionHash(TFecha fecha, int cantEstimadas){
    return (31 * (int) mesTFecha(fecha) + (int) diaTFecha(fecha)) % cantEstimadas;
}

TablaQuejas crearTablaQuejas(int cantEstimadas) { 
  TablaQuejas tabla = new rep_tablaQuejas;
  tabla->cantEstimadas = cantEstimadas;
  tabla->queja = new TQueja[cantEstimadas];
  tabla->cant = 0;
  return tabla;
}

void agregarQuejaTablaQuejas(TablaQuejas tabla, TQueja queja) {
  int i = funcionHash(fechaTQueja(queja), tabla->cantEstimadas);
  tabla->queja[i] = queja;
  tabla->cant++;
}

void imprimirTablaQuejas(TablaQuejas tabla) { }

bool perteneceQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha) {
  return false;
}

TQueja obtenerQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha) {
  return NULL;
}

void liberarTablaQuejas(TablaQuejas &tabla) {}
