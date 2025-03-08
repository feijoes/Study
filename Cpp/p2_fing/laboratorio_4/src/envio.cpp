#include "../include/envio.h"

struct rep_envio
{
  TCarritoProductos carrito;
  TFecha fecha;
};

TEnvio crearTEnvio(TCarritoProductos carrito, TFecha fecha)
{
  TEnvio nuevoEnvio = new rep_envio;
  nuevoEnvio->carrito = carrito;
  nuevoEnvio->fecha = fecha;
  return nuevoEnvio;
}

void liberarTEnvio(TEnvio &envio)
{
  liberarCarritoProductos(envio->carrito);
  liberarTFecha(envio->fecha);
  delete envio;
  envio = NULL;
}

TCarritoProductos obtenerCarritoProductosTEnvio(TEnvio envio) { return envio->carrito; }

TFecha obtenerFechaTEnvio(TEnvio envio) { return envio->fecha; }

void imprimirTEnvio(TEnvio envio)
{
  imprimirCarritoProductos(envio->carrito);
  printf("\n");
  printf("Fecha del envio: ");
  imprimirTFecha(envio->fecha);
  printf("\n");
}
