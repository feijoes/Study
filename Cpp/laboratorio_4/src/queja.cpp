#include "../include/queja.h"

struct rep_queja { 
  char comentario[MAX_COMENTARIO];
  TFecha fecha;
  TProducto producto;
  TCliente cliente;
};

TQueja crearTQueja(TFecha fecha, TProducto producto, TCliente cliente,
                   const char comentario[MAX_COMENTARIO]) {
  TQueja nuevaQueja = new rep_queja;
  nuevaQueja->fecha = fecha;
  nuevaQueja->producto = producto;
  nuevaQueja->cliente = cliente;
  strcpy(nuevaQueja->comentario, comentario);
  return nuevaQueja;
}
// Se imprimen la queja empleando el siguiente formato:
//   Fecha: <fecha_queja>
//   Cliente: <cliente>
//   Producto: <producto>
//   Comentario: <comentario>
// La impresión del cliente se realiza con la función 'imprimirTCliente'.
// La impresión del producto se realiza con la función 'imprimirTProducto'.
// La impresión de la fecha se realiza con la función 'imprimirTFecha'.
void imprimirTQueja(TQueja queja) {
  printf("Fecha: ");
  imprimirTFecha(fechaTQueja(queja));
  printf("\n");
  printf("Cliente: ");
  imprimirTCliente(queja->cliente);
  imprimirTProducto(queja->producto);
  printf("\n");
  printf("Comentario: %s\n", queja->comentario);
 }

void liberarTQueja(TQueja &queja) { 
  liberarTCliente(queja->cliente);
  liberarTProducto(queja->producto);
  liberarTFecha(queja->fecha);
  delete queja;
  queja = NULL;
}

TFecha fechaTQueja(TQueja queja) { return queja->fecha; }
