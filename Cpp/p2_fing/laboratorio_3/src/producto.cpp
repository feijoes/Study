#include "../include/producto.h"

struct rep_producto {
  int id;
  char nombre[MAX_NOMBRE_PRODUCTO];
  TFecha fechaIngreso;
  int precio;
};

TProducto crearTProducto(int id, const char nombre[MAX_NOMBRE_PRODUCTO],
                         int precio, TFecha fechaIngreso) {
  TProducto nuevoProducto = new rep_producto;
  nuevoProducto->id = id;
  strcpy(nuevoProducto->nombre, nombre);
  nuevoProducto->fechaIngreso = fechaIngreso;
  nuevoProducto->precio = precio;
  return nuevoProducto;
}

int idTProducto(TProducto producto) { return producto->id; }

int precioTProducto(TProducto producto) { return producto->precio; }

void imprimirTProducto(TProducto producto) {
  printf("Producto: %d\n", producto->id);
  printf("%s\n", producto->nombre);
  printf("Precio: %d\n", producto->precio);
  printf("Ingresado el: ");
  imprimirTFecha(producto->fechaIngreso);
}

void liberarTProducto(TProducto &producto) {
  liberarTFecha(producto->fechaIngreso);
  delete producto;
  producto = NULL;
}
