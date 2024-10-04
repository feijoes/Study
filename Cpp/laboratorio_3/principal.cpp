/*
  Módulo principal de la Tarea 1.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#define cmd_es(nom_comando, cmd) (0 == strcmp(nom_comando, cmd))

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/carritoProductos.h"
#include "include/cliente.h"
#include "include/clientesABB.h"
#include "include/clientesSucursalesLDE.h"
#include "include/conjuntoProductos.h"
#include "include/historial.h"
#include "include/listaPromociones.h"
#include "include/producto.h"
#include "include/promocion.h"

#define MAX_PALABRA 32
#define MAX_LINEA 256

#define NOMBRE_PRODUCTO "Producto Dummy"
#define PRECIO_DUMMY 100

///////////////////////////////
// Funciones main para Fecha //
///////////////////////////////

void leerFecha(TFecha &fecha); // Lee una fecha de la entrada en formato
                               // "dd/mm/aaaa" y la escribe la variable fecha
void main_crearFecha(
    TFecha &fecha);                    // Crea una fecha y la almacena en la variable fecha
void main_liberarFecha(TFecha &fecha); // Libera la memoria de la variable fecha
void main_imprimirFecha(
    TFecha fecha); // Imprime la fecha almacenada en la variable fecha
void main_aumentarDias(
    TFecha &fecha);         // Aumenta la fecha almacenada en la variable fecha en la
                            // cantidad de días indicada
void main_compararFechas(); // Compara dos fechas leidas de la entrada

////////////////////////////////////
// Funciones main para Clientes //
////////////////////////////////////
void main_crearCliente(TCliente &cliente); // Crea un cliente y lo almacena en
                                           // la variable 'cliente'
void main_imprimirEdadCliente(
    TCliente cliente); // Imprime la edad del cliente almacenado en la variable
                       // 'cliente'
void main_imprimirIdCliente(
    TCliente cliente); // Imprime la id del cliente almacenado en la variable
                       // 'cliente'
void main_imprimirNombreYApellidoCliente(
    TCliente cliente); // Imprime el nombre y apelldio del cliente almacenado en
                       // la variable 'cliente'
void main_imprimirCliente(
    TCliente cliente);                     // Imprime el cliente almacenado en la variable 'cliente'
void main_copiarCliente(TCliente cliente); // Copia al cliente en cliente
void main_liberarCliente(
    TCliente &cliente); // Libera la memoria asociada al cliente guardado en la
                        // variable 'cliente'

////////////////////////////////////
//   Funciones main para Productos   //
////////////////////////////////////
void main_crearTProducto(TProducto &producto, TFecha &fecha);
void main_imprimirTProducto(TProducto producto);
void main_liberarTProducto(TProducto &producto);
void main_idTProducto(TProducto producto);

//////////////////////////////////////////////
//   Funciones main para Colección Productos   //
//////////////////////////////////////////////
void main_crearCarritoProductos(TCarritoProductos &coleccionProductos);
void main_agregarCarritoProductos(TCarritoProductos &coleccionProductos,
                                  TProducto &producto);
void main_imprimirCarritoProductos(TCarritoProductos coleccionProductos);
void main_liberarCarritoProductos(TCarritoProductos &coleccionProductos);
void main_esVacioCarritoProductos(TCarritoProductos coleccionProductos);
void main_existeProductoCarritoProductos(TCarritoProductos coleccionProductos);
void main_obtenerProductoCarritoProductos(TCarritoProductos coleccionProductos);
void main_removerDeCarritoProductos(TCarritoProductos &coleccionProductos);

//////////////////////////////////
// Funciones main para ClientesABB //
//////////////////////////////////
void main_crearClientesABB(
    TClientesABB &grupo); // Crea un grupoABB y la almacena en la variable grupo
void main_agregarClienteAClientesABB(
    TClientesABB &grupo,
    TCliente &cliente); // Agrega el cliente almacenada en la variable 'cliente'
                        // al grupo almacenado en la variable grupo
void main_imprimirClientesABB(
    TClientesABB grupo); // Imprime toda la información del grupoABB almacenado
                         // en la variable grupo
void main_liberarClientesABB(TClientesABB &grupo);
void main_existeEnClientesABB(TClientesABB grupo);
void main_obtenerClienteClientesABB(TClientesABB grupo);
void main_alturaClientesABB(TClientesABB grupo);
void main_maxIdClientesABB(TClientesABB grupo);
void main_cantidadClientesClientesABB(TClientesABB grupo);
void main_edadPromedioClientesABB(TClientesABB grupo);
void main_removerDeClientesABB(TClientesABB &grupo);
void main_obtenerNesimoClienteTClientesABB(TClientesABB grupo);
void main_alturaClientesABBTiempo();
void main_obtenerExisteClienteClientesABBTiempo();

//////////////////////////////////////////
// Funciones main para ClientesSucursalesLDE //
//////////////////////////////////////////
void main_crearClientesSucursalesLDE(TClientesSucursalesLDE &coleccion);
void main_insertarClientesABBTClientesSucursalesLDE(
    TClientesSucursalesLDE &coleccion, TClientesABB &grupo, int idSucursal);
void main_imprimirClientesSucursalesLDE(TClientesSucursalesLDE coleccion);
void main_imprimirColeccionInvertidaTGrupos(TClientesSucursalesLDE coleccion);
void main_obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE coleccion);
void main_cantidadTClientesABBClientesSucursalesLDE(
    TClientesSucursalesLDE coleccion);
void main_obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE coleccion);
void main_removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE coleccion);
void main_removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE coleccion);
void main_liberarClientesSucursalesLDE(TClientesSucursalesLDE &coleccion);
void main_clienteMasRepetido(TClientesSucursalesLDE coleccion);

///////////////////////////////////
//        Conjunto Productos        //
///////////////////////////////////
void main_crearConjuntoProductos(TConjuntoProductos &conjuntoProductos);
void main_esVacioConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_insertarConjuntoProductos(TConjuntoProductos &conjuntoProductos);
void main_borrarDeConjuntoProductos(TConjuntoProductos &conjuntoProductos);
void main_perteneceConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_cardinalConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_cantMaxConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_imprimirConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_liberarConjuntoProductos(TConjuntoProductos &conjuntoProductos);
void main_unionConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_interseccionConjuntoProductos(TConjuntoProductos conjuntoProductos);
void main_diferenciaConjuntoProductos(TConjuntoProductos conjuntoProductos);

///////////////////////////////////
//          Promocion           //
///////////////////////////////////
void main_crearPromocion(TPromocion &promocion);
void main_agregarAPromocion(TPromocion promocion);
void main_perteneceAPromocion(TPromocion promocion);
void main_idPromocion(TPromocion promocion);
void main_imprimirPromocion(TPromocion promocion);
void main_fechaInicioTPromocion(TPromocion promocion);
void main_fechaFinTPromocion(TPromocion promocion);
void main_sonPromocionesCompatibles(TPromocion promocion);
void main_liberarTPromocion(TPromocion &promocion);

///////////////////////////////////
//       Lista Promociones      //
///////////////////////////////////
void main_crearListaPromociones(TListaPromociones &listaPromociones);
void main_agregarAListaPromociones(TListaPromociones &listaPromociones,
                                   TPromocion &promocion);
void main_esVaciaListaPromociones(TListaPromociones listaPromociones);
void main_imprimirListaPromociones(TListaPromociones listaPromociones);
void main_liberarListaPromociones(TListaPromociones &listaPromociones);
void main_pertenecePromocionListaPromociones(
    TListaPromociones listaPromociones);
void main_obtenerPromocionListaPromociones(TListaPromociones listaPromociones);
void main_obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones);
void main_obtenerPromocionesActivas(TListaPromociones &listaPromociones);
void main_esCompatibleListaPromociones(TListaPromociones listaPromociones,
                                       TPromocion promocion);
void main_unirListaPromociones(TListaPromociones listaPromociones);

///////////////////////////////////
//             Historial           //
///////////////////////////////////
void main_crearHistorial(THistorial &historial);
void main_agregarProductoHistorial(THistorial historial, TProducto &producto);
void main_agregarPromocionHistorial(THistorial historial,
                                    TPromocion &promocion);
void main_agregarProductoAPromocionHistorial(THistorial historial,
                                             TProducto &producto);
void main_avanzarAFechaHistorial(THistorial historial);
void main_imprimirPromocionesFinalizadosHistorial(THistorial historial);
void main_imprimirPromocionesActivasHistorial(THistorial historial);
void main_imprimirPromocionesFuturasHistorial(THistorial historial);
void main_esCompatiblePromocionHistorial(THistorial historial,
                                         TPromocion promocion);
void main_liberarHistorial(THistorial &historial);

// programa principal que lee comandos de la entrada estándar e invoca a la
// función de test correspondiente
int main()
{
  TFecha fecha = NULL;
  TCliente cliente = NULL;
  TClientesABB grupo = NULL;
  TProducto producto = NULL;
  TCarritoProductos coleccionProductos = NULL;
  TClientesSucursalesLDE coleccionGrupos = NULL;

  TConjuntoProductos conjuntoProductos = NULL;
  TPromocion promocion = NULL;
  TListaPromociones listaPromociones = NULL;
  THistorial historial = NULL;

  char restoLinea[MAX_LINEA + 1];
  char cmd[MAX_PALABRA];

  int cont_comandos = 0;
  bool seguir = true;
  printf("Bienvenido al programa principal de MercadoFinger. Por favor ingrese "
         "su comando:\n");
  while (seguir)
  {
    // mostrar el prompt
    cont_comandos++;
    printf("%u> ", cont_comandos);

    // leer el comando en la variable cmd
    leerChars(cmd);

    // procesar el comando
    if (cmd_es("Fin", cmd))
    { // Termina el programa
      seguir = false;
      printf("Fin.\n");
    }
    else if (cmd_es("#", cmd))
    { // Imprime el comentario luego del #
      leerRestoLinea(restoLinea);
      printf("# %s.\n", restoLinea);

      ///////////////////////////////////
      /* Funciones para testear fecha */
      ///////////////////////////////////
    }
    else if (cmd_es("crearFecha", cmd))
    {
      main_crearFecha(fecha);
    }
    else if (cmd_es("imprimirFecha", cmd))
    {
      main_imprimirFecha(fecha);
    }
    else if (cmd_es("liberarFecha", cmd))
    {
      main_liberarFecha(fecha);
    }
    else if (cmd_es("aumentarDias", cmd))
    {
      main_aumentarDias(fecha);
    }
    else if (cmd_es("compararFechas", cmd))
    {
      main_compararFechas();

      //////////////////////////////////////
      /* Funciones para testear cliente */
      //////////////////////////////////////
    }
    else if (cmd_es("crearCliente", cmd))
    {
      main_crearCliente(cliente);
    }
    else if (cmd_es("imprimirEdadCliente", cmd))
    {
      main_imprimirEdadCliente(cliente);
    }
    else if (cmd_es("imprimirIdCliente", cmd))
    {
      main_imprimirIdCliente(cliente);
    }
    else if (cmd_es("imprimirNombreYApellidoCliente", cmd))
    {
      main_imprimirNombreYApellidoCliente(cliente);
    }
    else if (cmd_es("imprimirCliente", cmd))
    {
      main_imprimirCliente(cliente);
    }
    else if (cmd_es("copiarCliente", cmd))
    {
      main_copiarCliente(cliente);
    }
    else if (cmd_es("liberarCliente", cmd))
    {
      main_liberarCliente(cliente);

      ////////////////////////////////////
      //   Funciones main para Productos   //
      ////////////////////////////////////
    }
    else if (cmd_es("crearProducto", cmd))
    {
      main_crearTProducto(producto, fecha);
    }
    else if (cmd_es("imprimirProducto", cmd))
    {
      main_imprimirTProducto(producto);
    }
    else if (cmd_es("liberarProducto", cmd))
    {
      main_liberarTProducto(producto);
    }
    else if (cmd_es("idProducto", cmd))
    {
      main_idTProducto(producto);

      //////////////////////////////////////////////
      //   Funciones main para Colección Productos   //
      //////////////////////////////////////////////
    }
    else if (cmd_es("crearCarritoProductos", cmd))
    {
      main_crearCarritoProductos(coleccionProductos);
    }
    else if (cmd_es("agregarCarritoProductos", cmd))
    {
      main_agregarCarritoProductos(coleccionProductos, producto);
    }
    else if (cmd_es("imprimirCarritoProductos", cmd))
    {
      main_imprimirCarritoProductos(coleccionProductos);
    }
    else if (cmd_es("liberarCarritoProductos", cmd))
    {
      main_liberarCarritoProductos(coleccionProductos);
    }
    else if (cmd_es("esVacioCarritoProductos", cmd))
    {
      main_esVacioCarritoProductos(coleccionProductos);
    }
    else if (cmd_es("existeProductoCarritoProductos", cmd))
    {
      main_existeProductoCarritoProductos(coleccionProductos);
    }
    else if (cmd_es("obtenerProductoCarritoProductos", cmd))
    {
      main_obtenerProductoCarritoProductos(coleccionProductos);
    }
    else if (cmd_es("removerDeCarritoProductos", cmd))
    {
      main_removerDeCarritoProductos(coleccionProductos);

      ///////////////////////////////////
      /* Funciones para testear grupo */
      ///////////////////////////////////
    }
    else if (cmd_es(
                 "crearClientesABB",
                 cmd))
    { // Crea un grupo y la almacena en la variable grupo
      main_crearClientesABB(grupo);
    }
    else if (cmd_es("agregarAClientesABB", cmd))
    {
      main_agregarClienteAClientesABB(grupo, cliente);
    }
    else if (cmd_es("imprimirClientesABB", cmd))
    {
      main_imprimirClientesABB(grupo);
    }
    else if (cmd_es("existeEnClientesABB", cmd))
    {
      main_existeEnClientesABB(grupo);
    }
    else if (cmd_es("obtenerClienteClientesABB", cmd))
    {
      main_obtenerClienteClientesABB(grupo);
    }
    else if (cmd_es("alturaClientesABB", cmd))
    {
      main_alturaClientesABB(grupo);
    }
    else if (cmd_es("maxIdClientesABB", cmd))
    {
      main_maxIdClientesABB(grupo);
    }
    else if (cmd_es("cantidadClientesClientesABB", cmd))
    {
      main_cantidadClientesClientesABB(grupo);
    }
    else if (cmd_es("edadPromedioClientesABB", cmd))
    {
      main_edadPromedioClientesABB(grupo);
    }
    else if (cmd_es("removerDeClientesABB", cmd))
    {
      main_removerDeClientesABB(grupo);
    }
    else if (cmd_es("liberarClientesABB", cmd))
    {
      main_liberarClientesABB(grupo);
    }
    else if (cmd_es("obtenerNesimoClienteClientesABB", cmd))
    {
      main_obtenerNesimoClienteTClientesABB(grupo);
    }
    else if (cmd_es("alturaClientesABBTiempo", cmd))
    {
      main_alturaClientesABBTiempo();
    }
    else if (cmd_es("obtenerExisteClienteClientesABBTiempo", cmd))
    {
      main_obtenerExisteClienteClientesABBTiempo();

      //////////////////////////////////////////////
      // Funciones para testear ClientesSucursalesLDE  //
      //////////////////////////////////////////////
    }
    else if (cmd_es("crearClientesSucursalesLDE", cmd))
    {
      main_crearClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("agregarAClientesSucursalesLDE", cmd))
    {
      int dummy_int = rand() % 1000;
      main_insertarClientesABBTClientesSucursalesLDE(coleccionGrupos, grupo,
                                                     dummy_int);
    }
    else if (cmd_es("imprimirClientesSucursalesLDE", cmd))
    {
      main_imprimirClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("imprimirInvertidaClientesSucursalesLDE", cmd))
    {
      main_imprimirColeccionInvertidaTGrupos(coleccionGrupos);
    }
    else if (cmd_es("obtenerNesimoClientesSucursalesLDE", cmd))
    {
      main_obtenerNesimoClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("cantidadClientesSucursalesLDE", cmd))
    {
      main_cantidadTClientesABBClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("obtenerPrimeroClientesSucursalesLDE", cmd))
    {
      main_obtenerPrimeroClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("removerUltimoClientesSucursalesLDE", cmd))
    {
      main_removerUltimoClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("removerNesimoClientesSucursalesLDE", cmd))
    {
      main_removerNesimoClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("liberarClientesSucursalesLDE", cmd))
    {
      main_liberarClientesSucursalesLDE(coleccionGrupos);
    }
    else if (cmd_es("clienteMasRepetido", cmd))
    {
      main_clienteMasRepetido(coleccionGrupos);

      ///////////////////////////////////
      //        Conjunto Productos        //
      ///////////////////////////////////
    }
    else if (cmd_es("crearConjuntoProductos", cmd))
    {
      main_crearConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("esVacioConjuntoProductos", cmd))
    {
      main_esVacioConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("insertarConjuntoProductos", cmd))
    {
      main_insertarConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("borrarDeConjuntoProductos", cmd))
    {
      main_borrarDeConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("perteneceConjuntoProductos", cmd))
    {
      main_perteneceConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("cardinalConjuntoProductos", cmd))
    {
      main_cardinalConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("cantMaxConjuntoProductos", cmd))
    {
      main_cantMaxConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("imprimirConjuntoProductos", cmd))
    {
      main_imprimirConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("liberarConjuntoProductos", cmd))
    {
      main_liberarConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("unionConjuntoProductos", cmd))
    {
      main_unionConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("interseccionConjuntoProductos", cmd))
    {
      main_interseccionConjuntoProductos(conjuntoProductos);
    }
    else if (cmd_es("diferenciaConjuntoProductos", cmd))
    {
      main_diferenciaConjuntoProductos(conjuntoProductos);

      ///////////////////////////////////
      //          Promocion           //
      ///////////////////////////////////
    }
    else if (cmd_es("crearPromocion", cmd))
    {
      main_crearPromocion(promocion);
    }
    else if (cmd_es("agregarAPromocion", cmd))
    {
      main_agregarAPromocion(promocion);
    }
    else if (cmd_es("perteneceAPromocion", cmd))
    {
      main_perteneceAPromocion(promocion);
    }
    else if (cmd_es("idPromocion", cmd))
    {
      main_idPromocion(promocion);
    }
    else if (cmd_es("imprimirPromocion", cmd))
    {
      main_imprimirPromocion(promocion);
    }
    else if (cmd_es("fechaInicioPromocion", cmd))
    {
      main_fechaInicioTPromocion(promocion);
    }
    else if (cmd_es("fechaFinPromocion", cmd))
    {
      main_fechaFinTPromocion(promocion);
    }
    else if (cmd_es("sonPromocionesCompatibles", cmd))
    {
      main_sonPromocionesCompatibles(promocion);
    }
    else if (cmd_es("liberarPromocion", cmd))
    {
      main_liberarTPromocion(promocion);

      ///////////////////////////////////
      //       Lista Promociones      //
      ///////////////////////////////////
    }
    else if (cmd_es("crearListaPromociones", cmd))
    {
      main_crearListaPromociones(listaPromociones);
    }
    else if (cmd_es("agregarAListaPromociones", cmd))
    {
      main_agregarAListaPromociones(listaPromociones, promocion);
    }
    else if (cmd_es("esVaciaListaPromociones", cmd))
    {
      main_esVaciaListaPromociones(listaPromociones);
    }
    else if (cmd_es("imprimirListaPromociones", cmd))
    {
      main_imprimirListaPromociones(listaPromociones);
    }
    else if (cmd_es("liberarListaPromociones", cmd))
    {
      main_liberarListaPromociones(listaPromociones);
    }
    else if (cmd_es("pertenecePromocionListaPromociones", cmd))
    {
      main_pertenecePromocionListaPromociones(listaPromociones);
    }
    else if (cmd_es("obtenerPromocionListaPromociones", cmd))
    {
      main_obtenerPromocionListaPromociones(listaPromociones);
    }
    else if (cmd_es("obtenerPromocionesFinalizadas", cmd))
    {
      main_obtenerPromocionesFinalizadas(listaPromociones);
    }
    else if (cmd_es("obtenerPromocionesActivas", cmd))
    {
      main_obtenerPromocionesActivas(listaPromociones);
    }
    else if (cmd_es("esCompatibleListaPromociones", cmd))
    {
      main_esCompatibleListaPromociones(listaPromociones, promocion);
    }
    else if (cmd_es("unirListaPromociones", cmd))
    {
      main_unirListaPromociones(listaPromociones);

      ///////////////////////////////////
      //            Historial            //
      ///////////////////////////////////
    }
    else if (cmd_es("crearHistorial", cmd))
    {
      main_crearHistorial(historial);
    }
    else if (cmd_es("agregarPromocionHistorial", cmd))
    {
      main_agregarPromocionHistorial(historial, promocion);
    }
    else if (cmd_es("agregarProductoAPromocionHistorial", cmd))
    {
      main_agregarProductoAPromocionHistorial(historial, producto);
    }
    else if (cmd_es("avanzarAFechaHistorial", cmd))
    {
      main_avanzarAFechaHistorial(historial);
    }
    else if (cmd_es("imprimirPromocionesFinalizadosHistorial", cmd))
    {
      main_imprimirPromocionesFinalizadosHistorial(historial);
    }
    else if (cmd_es("imprimirPromocionesActivasHistorial", cmd))
    {
      main_imprimirPromocionesActivasHistorial(historial);
    }
    else if (cmd_es("imprimirPromocionesFuturasHistorial", cmd))
    {
      main_imprimirPromocionesFuturasHistorial(historial);
    }
    else if (cmd_es("esCompatiblePromocionHistorial", cmd))
    {
      main_esCompatiblePromocionHistorial(historial, promocion);
    }
    else if (cmd_es("liberarHistorial", cmd))
    {
      main_liberarHistorial(historial);
    }
    else
    {
      printf("Comando no reconocido.\n"); // Comando no reconocido
    }
    fgets(restoLinea, MAX_LINEA + 1, stdin);
  } // while

  return 0;
} // main

///////////////////////////////
/* Funciones main para Fecha */
///////////////////////////////

void leerFecha(TFecha &fecha)
{
  nat *componentes = new nat[3];
  scanf("%u/%u/%u", &componentes[0], &componentes[1], &componentes[2]);
  fecha = crearTFecha(componentes[0], componentes[1], componentes[2]);
  delete[] componentes;
}

void main_crearFecha(TFecha &fecha)
{
  assert(fecha == NULL);
  leerFecha(fecha);
  printf("Fecha creada en forma exitosa.\n");
}

void main_liberarFecha(TFecha &fecha)
{
  assert(fecha != NULL);
  liberarTFecha(fecha);
  printf("Fecha liberada en forma exitosa.\n");
}

void main_imprimirFecha(TFecha fecha)
{
  assert(fecha != NULL);
  imprimirTFecha(fecha);
}

void main_aumentarDias(TFecha &fecha)
{
  assert(fecha != NULL);
  nat cantDias = leerNat();
  aumentarTFecha(fecha, cantDias);
  printf("La nueva fecha aplazada %d dias es: \n", cantDias);
  imprimirTFecha(fecha);
}

void main_compararFechas()
{
  TFecha fecha1 = NULL, fecha2 = NULL;
  leerFecha(fecha1);
  leerFecha(fecha2);
  int comp = compararTFechas(fecha1, fecha2);
  if (comp == 0)
  {
    printf("Las fechas son iguales. \n");
  }
  else if (comp == 1)
  {
    printf("La primera fecha es posterior a la segunda. \n");
  }
  else
    printf("La primera fecha es anterior a la segunda. \n");
  liberarTFecha(fecha1);
  liberarTFecha(fecha2);
}

///////////////////////////////////
/* Funciones main para Cliente */
///////////////////////////////////

void main_crearCliente(TCliente &cliente)
{
  assert(cliente == NULL);
  int id = leerInt();
  char nombre[MAX_NOMBRE];
  leerChars(nombre);
  char apellido[MAX_APELLIDO];
  leerChars(apellido);
  int edad = leerInt();
  cliente = crearTCliente(id, nombre, apellido, edad);
  printf("Cliente creadox de forma exitosa.\n");
}

void main_imprimirEdadCliente(TCliente cliente)
{
  assert(cliente != NULL);
  printf("La edad del cliente es: %d\n", edadTCliente(cliente));
}

void main_imprimirIdCliente(TCliente cliente)
{
  assert(cliente != NULL);
  printf("La id del cliente es: %d\n", idTCliente(cliente));
}

void main_imprimirNombreYApellidoCliente(TCliente cliente)
{
  assert(cliente != NULL);
  char nombre[MAX_NOMBRE];
  char apellido[MAX_APELLIDO];
  nombreTCliente(cliente, nombre);
  apellidoTCliente(cliente, apellido);
  printf("El nombre del cliente es: %s\n", nombre);
  printf("El apellido del cliente es: %s\n", apellido);
}

void main_imprimirCliente(TCliente cliente)
{
  assert(cliente != NULL);
  imprimirTCliente(cliente);
}

void main_copiarCliente(TCliente cliente)
{
  TCliente clienteCopia = copiarTCliente(cliente);
  printf("Cliente copiado. Datos de la copia:\n");
  imprimirTCliente(clienteCopia);

  liberarTCliente(clienteCopia);
}

void main_liberarCliente(TCliente &cliente)
{
  assert(cliente != NULL);
  liberarTCliente(cliente);
  printf("Cliente liberado con exito.\n");
}

////////////////////////////////////
//   Funciones main para Productos   //
////////////////////////////////////
void main_crearTProducto(TProducto &producto, TFecha &fecha)
{
  assert(producto == NULL);
  int id = leerInt();
  char nombreProducto[MAX_NOMBRE_PRODUCTO];
  leerChars(nombreProducto);
  int precio = leerInt();
  producto = crearTProducto(id, nombreProducto, precio, fecha);
  fecha = NULL;
  printf("Producto creado en forma exitosa.\n");
}

void main_imprimirTProducto(TProducto producto)
{
  assert(producto != NULL);
  imprimirTProducto(producto);
}

void main_liberarTProducto(TProducto &producto)
{
  assert(producto != NULL);
  liberarTProducto(producto);
  producto = NULL;
  printf("Producto liberada en forma exitosa.\n");
}

void main_idTProducto(TProducto producto)
{
  assert(producto != NULL);
  int id = idTProducto(producto);
  printf("ID: %d\n", id);
}

//////////////////////////////////////////////
//   Funciones main para Colección Productos   //
//////////////////////////////////////////////
void main_crearCarritoProductos(TCarritoProductos &coleccionProductos)
{
  assert(coleccionProductos == NULL);
  coleccionProductos = crearCarritoProductosVacio();
  printf("Coleccion de productos creada de forma exitosa.\n");
}

void main_agregarCarritoProductos(TCarritoProductos &coleccionProductos,
                                  TProducto &producto)
{
  insertarProductoCarritoProductos(coleccionProductos, producto);
  printf("Producto agregada de forma exitosa.\n");
  producto = NULL;
}

void main_imprimirCarritoProductos(TCarritoProductos coleccionProductos)
{
  imprimirCarritoProductos(coleccionProductos);
}

void main_liberarCarritoProductos(TCarritoProductos &coleccionProductos)
{
  liberarCarritoProductos(coleccionProductos);
  printf("Coleccion liberada con exito.\n");
}

void main_esVacioCarritoProductos(TCarritoProductos coleccionProductos)
{
  bool esVacia = esVacioCarritoProductos(coleccionProductos);
  if (esVacia)
  {
    printf("La coleccion de productos es vacia.\n");
  }
  else
  {
    printf("La coleccion de productos NO es vacia.\n");
  }
}

void main_existeProductoCarritoProductos(TCarritoProductos coleccionProductos)
{
  int id = leerInt();
  bool existe = existeProductoCarritoProductos(coleccionProductos, id);
  if (existe)
  {
    printf("El producto con id %d pertenece a la coleccion.\n", id);
  }
  else
  {
    printf("El producto con id %d NO pertenece a la coleccion.\n", id);
  }
}

void main_obtenerProductoCarritoProductos(
    TCarritoProductos coleccionProductos)
{
  int id = leerInt();
  assert(existeProductoCarritoProductos(coleccionProductos, id));
  TProducto producto = obtenerProductoCarritoProductos(coleccionProductos, id);
  imprimirTProducto(producto);
}

void main_removerDeCarritoProductos(TCarritoProductos &coleccionProductos)
{
  int id = leerInt();
  assert(existeProductoCarritoProductos(coleccionProductos, id));
  removerProductoCarritoProductos(coleccionProductos, id);
  printf("Producto con id %d removida con exito.\n", id);
}

////////////////////////////////
/* Funciones main para Grupo */
////////////////////////////////

void main_crearClientesABB(TClientesABB &grupo)
{
  assert(grupo == NULL);
  grupo = crearTClientesABBVacio();
  printf("El grupoABB ha sido creado de forma exitosa.\n");
}

void main_agregarClienteAClientesABB(TClientesABB &grupo, TCliente &cliente)
{
  assert(cliente != NULL);
  insertarTClienteTClientesABB(grupo, cliente);
  cliente = NULL;
  printf("Se ha agregado el cliente al grupo de forma exitosa.\n");
}

void main_imprimirClientesABB(TClientesABB grupo)
{
  imprimirTClientesABB(grupo);
}

void main_liberarClientesABB(TClientesABB &grupo)
{
  liberarTClientesABB(grupo);
  printf("Grupo liberado con exito.\n");
}

void main_existeEnClientesABB(TClientesABB grupo)
{
  int id = leerInt();
  if (existeTClienteTClientesABB(grupo, id))
  {
    printf("El cliente con id %d pertenece al grupo.\n", id);
  }
  else
  {
    printf("El cliente con id %d NO pertenece al grupo.\n", id);
  }
}

void main_obtenerClienteClientesABB(TClientesABB grupo)
{
  int id = leerInt();
  TCliente cliente = obtenerTClienteTClientesABB(grupo, id);
  if (cliente == NULL)
  {
    printf("El cliente con id %d no se puede imprimir pues NO pertenece al "
           "grupo.\n",
           id);
  }
  else
  {
    imprimirTCliente(cliente);
  }
}

void main_alturaClientesABB(TClientesABB grupo)
{
  nat altura = alturaTClientesABB(grupo);
  printf("La altura del grupo es %d.\n", altura);
}

void main_maxIdClientesABB(TClientesABB grupo)
{
  TCliente maxId = maxIdTClienteTClientesABB(grupo);
  printf("El mayor id en el grupo es %d.\n", idTCliente(maxId));
}

void main_cantidadClientesClientesABB(TClientesABB grupo)
{
  int cantidad = cantidadClientesTClientesABB(grupo);
  printf("La cantidad de clientes en el grupo es %d.\n", cantidad);
}

void main_edadPromedioClientesABB(TClientesABB grupo)
{
  float edadPromedio = edadPromedioTClientesABB(grupo);
  printf("La edad promedio del grupo es %.2f.\n", edadPromedio);
}

void main_removerDeClientesABB(TClientesABB &grupo)
{
  int id = leerInt();
  if (existeTClienteTClientesABB(grupo, id))
  {
    removerTClienteTClientesABB(grupo, id);
    printf("El cliente con id %d se removio del grupo.\n", id);
  }
  else
  {
    printf("El cliente con id %d no se puede remover porque NO pertenece al "
           "grupo.\n",
           id);
  }
}

void main_obtenerNesimoClienteTClientesABB(TClientesABB grupo)
{
  int n = leerInt();
  int cantEnGrupo = cantidadClientesTClientesABB(grupo);
  if (cantEnGrupo >= n)
  {
    TCliente cliente = obtenerNesimoClienteTClientesABB(grupo, n);
    printf("Cliente nro %d del grupoABB:\n", n);
    imprimirTCliente(cliente);
  }
  else
  {
    printf("No se puede imprimir vistante %d del grupoABB porque tiene solo %d "
           "clientes.\n",
           n, cantEnGrupo);
  }
}

void insertarEnArbolDesdeArreglo(TClientesABB &grupoABB, TCliente *arreglo,
                                 int inicio, int final)
{
  if (inicio <= final)
  {
    int mid = (inicio + final) / 2;
    insertarTClienteTClientesABB(grupoABB, arreglo[mid]);
    insertarEnArbolDesdeArreglo(grupoABB, arreglo, inicio, mid - 1);
    insertarEnArbolDesdeArreglo(grupoABB, arreglo, mid + 1, final);
  }
}

void main_alturaClientesABBTiempo()
{
  TClientesABB grupoABB = crearTClientesABBVacio();

  nat tamanio = leerNat();
  nat timeout = leerNat();

  TCliente *arreglo = new TCliente[tamanio];
  for (nat i = 0; i < tamanio; i++)
  {
    arreglo[i] = crearTCliente(i, "Alberto", "Pardo", 52);
  }

  nat inicio = 0;
  nat final = tamanio - 1;
  insertarEnArbolDesdeArreglo(grupoABB, arreglo, inicio, final);
  clock_t tm = clock();
  nat altura = alturaTClientesABB(grupoABB);
  tm = clock() - tm;

  float tiempo = ((float)tm) / CLOCKS_PER_SEC;
  if (tiempo > timeout)
  {
    printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
  }
  else
  {
    printf(
        "La altura del grupo es %d. Calculado correctamente en menos de %ds.\n",
        altura, timeout);
  }

  liberarTClientesABB(grupoABB);
  delete[] arreglo;
}

void main_obtenerExisteClienteClientesABBTiempo()
{
  TClientesABB grupoABB = crearTClientesABBVacio();

  nat tamanio = leerNat();
  double timeout = leerDouble();

  TCliente *arreglo = new TCliente[tamanio];
  for (nat i = 0; i < tamanio; i++)
  {
    arreglo[i] = crearTCliente(i, "Carlos", "Luna", 45);
  }

  nat inicio = 0;
  nat final = tamanio - 1;
  insertarEnArbolDesdeArreglo(grupoABB, arreglo, inicio, final);
  clock_t tm = clock();
  bool existeCliente1 = existeTClienteTClientesABB(grupoABB, 0);
  bool existeCliente2 = existeTClienteTClientesABB(grupoABB, tamanio - 1);
  bool existeCliente3 = existeTClienteTClientesABB(grupoABB, tamanio / 3);
  bool existeCliente4 = existeTClienteTClientesABB(grupoABB, (2 * tamanio) / 3);
  TCliente cliente1 = obtenerTClienteTClientesABB(grupoABB, 0);
  TCliente cliente2 = obtenerTClienteTClientesABB(grupoABB, tamanio - 1);
  TCliente cliente3 = obtenerTClienteTClientesABB(grupoABB, tamanio / 3);
  TCliente cliente4 = obtenerTClienteTClientesABB(grupoABB, (2 * tamanio) / 3);
  tm = clock() - tm;

  float tiempo = ((float)tm) / CLOCKS_PER_SEC;
  if (tiempo > timeout)
  {
    printf("ERROR, tiempo excedido: %.3f > %.3f \n", tiempo, timeout);
  }
  else
  {
    printf("Se obtuvieron los clientes? %d %d %d %d con ids respectivos %d %d "
           "%d %d\n",
           existeCliente1, existeCliente2, existeCliente3, existeCliente4,
           idTCliente(cliente1), idTCliente(cliente2), idTCliente(cliente3),
           idTCliente(cliente4));
    printf("Calculado correctamente en menos de %.3fs.\n", timeout);
  }

  liberarTClientesABB(grupoABB);
  delete[] arreglo;
}

//////////////////////////////////////////
// Funciones main para ClientesSucursalesLDE //
//////////////////////////////////////////
void main_crearClientesSucursalesLDE(TClientesSucursalesLDE &coleccion)
{
  assert(coleccion == NULL);
  coleccion = crearTClientesSucursalesLDEVacia();
  printf("La coleccion de grupos ha sido creado de forma exitosa.\n");
}

void main_insertarClientesABBTClientesSucursalesLDE(
    TClientesSucursalesLDE &coleccion, TClientesABB &grupo, int idSucursal)
{
  assert(grupo != NULL);
  insertarClientesABBTClientesSucursalesLDE(coleccion, grupo, idSucursal);
  grupo = NULL;
  printf("Se ha agregado el grupo a la coleccion de forma exitosa.\n");
}

void main_imprimirClientesSucursalesLDE(TClientesSucursalesLDE coleccion)
{
  imprimirTClientesSucursalesLDE(coleccion);
}

void main_imprimirColeccionInvertidaTGrupos(TClientesSucursalesLDE coleccion)
{
  imprimirInvertidoTClientesSucursalesLDE(coleccion);
}

void main_obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE coleccion)
{
  int n = leerInt();
  TClientesABB grupo = obtenerNesimoClientesSucursalesLDE(coleccion, n);
  if (grupo)
  {
    printf("Grupo en la posicion %d:\n", n);
    imprimirTClientesABB(grupo);
  }
  else
  {
    printf("NO existe un grupo en la posicion %d\n", n);
  }
}

void main_cantidadTClientesABBClientesSucursalesLDE(
    TClientesSucursalesLDE coleccion)
{
  nat cant = cantidadTClientesABBClientesSucursalesLDE(coleccion);
  printf("La cantidad de grupos en la coleccion es %d\n", cant);
}

void main_obtenerPrimeroClientesSucursalesLDE(
    TClientesSucursalesLDE coleccion)
{
  nat cant = cantidadTClientesABBClientesSucursalesLDE(coleccion);
  if (cant > 0)
  {
    TClientesABB grupo = obtenerPrimeroClientesSucursalesLDE(coleccion);
    assert(grupo != NULL);
    printf("Primer grupo:\n");
    imprimirTClientesABB(grupo);
  }
  else
  {
    printf("No se puede obtener el primero de la coleccion de grupos porque es "
           "vacia\n");
  }
}

void main_removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE coleccion)
{
  nat cant = cantidadTClientesABBClientesSucursalesLDE(coleccion);
  if (cant > 0)
  {
    TClientesABB grupo = removerUltimoClientesSucursalesLDE(coleccion);
    assert(grupo != NULL);
    printf("Ultimo grupo (removido):\n");
    imprimirTClientesABB(grupo);
    liberarTClientesABB(grupo);
  }
  else
  {
    printf("No se puede remover el ultimo de la coleccion de grupos porque es "
           "vacia\n");
  }
}

void main_removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE coleccion)
{
  nat n = leerNat();
  nat cant = cantidadTClientesABBClientesSucursalesLDE(coleccion);
  if (cant >= n)
  {
    TClientesABB grupo = removerNesimoClientesSucursalesLDE(coleccion, n);
    assert(grupo != NULL);
    printf("Grupo en la posicion %d (removido):\n", n);
    imprimirTClientesABB(grupo);
    liberarTClientesABB(grupo);
  }
  else
  {
    printf("No se puede remover el elemento %d de la coleccion de grupos "
           "porque solo contiene %d\n",
           n, cant);
  }
}

void main_liberarClientesSucursalesLDE(TClientesSucursalesLDE &coleccion)
{
  assert(coleccion != NULL);
  liberarTClientesSucursalesLDE(coleccion);
  printf("Coleccion de grupos liberada\n");
  coleccion = NULL;
}

void main_clienteMasRepetido(TClientesSucursalesLDE coleccion)
{
  assert(coleccion != NULL);
  TCliente cliente = clienteMasRepetido(coleccion);
  if (cliente == NULL)
  {
    printf("No hay cliente repetido porque no hay clientes en los grupos de la "
           "coleccion.\n");
  }
  else
  {
    printf("El cliente que aparece en la mayor cantidad de grupos es:\n");
    imprimirTCliente(cliente);
  }
}

///////////////////////////////////
//        Conjunto Productos        //
///////////////////////////////////
void main_crearConjuntoProductos(TConjuntoProductos &conjuntoProductos)
{
  assert(conjuntoProductos == NULL);

  int cantMax = leerInt();
  conjuntoProductos = crearTConjuntoProductos(cantMax);
  printf("El conjunto productos fue creado en forma correcta.\n");
}

void main_esVacioConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  bool esVacia = esVacioTConjuntoProductos(conjuntoProductos);
  if (esVacia)
  {
    printf("El conjunto de productos es vacio.\n");
  }
  else
  {
    printf("La conjunto de productos NO es vacio.\n");
  }
}

void main_insertarConjuntoProductos(TConjuntoProductos &conjuntoProductos)
{
  int id = leerInt();
  insertarTConjuntoProductos(conjuntoProductos, id);
  printf("Se ejecuto 'insertarTConjuntoProductos' con producto de id %d "
         "exitosamente.\n",
         id);
}

void main_borrarDeConjuntoProductos(TConjuntoProductos &conjuntoProductos)
{
  int id = leerInt();
  borrarDeTConjuntoProductos(conjuntoProductos, id);
  printf("Se ejecuto 'borrarDeTConjuntoProductos' con producto de id %d "
         "exitosamente.\n",
         id);
}

void main_perteneceConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  int id = leerInt();
  bool pertenece = perteneceTConjuntoProductos(conjuntoProductos, id);
  if (pertenece)
  {
    printf("El producto de id %d pertenece al conjunto.\n", id);
  }
  else
  {
    printf("El producto de id %d NO pertenece al conjunto.\n", id);
  }
}

void main_cardinalConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  int cardinal = cantidadTConjuntoProductos(conjuntoProductos);
  printf("El cardinal del conjunto es: %d.\n", cardinal);
}

void main_cantMaxConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  int cantMax = cantMaxTConjuntoProductos(conjuntoProductos);
  printf("La cantidad maxima del conjunto es: %d.\n", cantMax);
}

void main_imprimirConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  printf("Conjunto de productos:\n");
  imprimirTConjuntoProductos(conjuntoProductos);
}

void main_liberarConjuntoProductos(TConjuntoProductos &conjuntoProductos)
{
  liberarTConjuntoProductos(conjuntoProductos);
  printf("Conjunto de productos liberado exitosamente.\n");
}

void main_unionConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  int cantMax = cantMaxTConjuntoProductos(conjuntoProductos);
  TConjuntoProductos otroConjunto = crearTConjuntoProductos(cantMax);

  int cant = leerInt();
  for (int i = 0; i < cant; i++)
  {
    int id = leerInt();
    insertarTConjuntoProductos(otroConjunto, id);
  }

  TConjuntoProductos unionConjuntoProductos =
      unionTConjuntoProductos(conjuntoProductos, otroConjunto);
  printf("Conjunto de productos union:\n");
  imprimirTConjuntoProductos(unionConjuntoProductos);

  liberarTConjuntoProductos(unionConjuntoProductos);
  liberarTConjuntoProductos(otroConjunto);
}

void main_interseccionConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  int cantMax = cantMaxTConjuntoProductos(conjuntoProductos);
  TConjuntoProductos otroConjunto = crearTConjuntoProductos(cantMax);

  int cant = leerInt();
  for (int i = 0; i < cant; i++)
  {
    int id = leerInt();
    insertarTConjuntoProductos(otroConjunto, id);
  }

  TConjuntoProductos interseccion =
      interseccionTConjuntoProductos(conjuntoProductos, otroConjunto);
  printf("Conjunto de productos interseccion:\n");
  imprimirTConjuntoProductos(interseccion);

  liberarTConjuntoProductos(interseccion);
  liberarTConjuntoProductos(otroConjunto);
}

void main_diferenciaConjuntoProductos(TConjuntoProductos conjuntoProductos)
{
  int cantMax = cantMaxTConjuntoProductos(conjuntoProductos);
  TConjuntoProductos otroConjunto = crearTConjuntoProductos(cantMax);

  int cant = leerInt();
  for (int i = 0; i < cant; i++)
  {
    int id = leerInt();
    insertarTConjuntoProductos(otroConjunto, id);
  }

  TConjuntoProductos diferencia =
      diferenciaTConjuntoProductos(conjuntoProductos, otroConjunto);
  printf("Conjunto de productos diferencia:\n");
  imprimirTConjuntoProductos(diferencia);

  liberarTConjuntoProductos(diferencia);
  liberarTConjuntoProductos(otroConjunto);
}

///////////////////////////////////
//          Promocion           //
///////////////////////////////////
void main_crearPromocion(TPromocion &promocion)
{
  assert(promocion == NULL);

  TFecha fechaIni;
  leerFecha(fechaIni);

  TFecha fechaFin;
  leerFecha(fechaFin);

  int cantMax = leerInt();
  int id = leerInt();

  promocion = crearTPromocion(id, fechaIni, fechaFin, cantMax);
  printf("Promocion creada con exito.\n");
}

void main_agregarAPromocion(TPromocion promocion)
{
  int cant = leerInt();
  for (int i = 0; i < cant; i++)
  {
    int idProducto = leerInt();

    TFecha fechaDummy = crearTFecha(1, 1, 1);
    TProducto p =
        crearTProducto(idProducto, NOMBRE_PRODUCTO, PRECIO_DUMMY, fechaDummy);
    agregarATPromocion(promocion, p);
    liberarTProducto(p);
  }

  printf("Productos agregados a la promocion de forma exitosa.\n");
}

void main_perteneceAPromocion(TPromocion promocion)
{
  int idProducto = leerInt();

  TFecha fechaDummy = crearTFecha(1, 1, 1);
  TProducto p =
      crearTProducto(idProducto, NOMBRE_PRODUCTO, PRECIO_DUMMY, fechaDummy);
  bool pertenece = perteneceATPromocion(promocion, p);

  if (pertenece)
  {
    printf("El producto de id %d pertenece a la promocion.\n", idTProducto(p));
  }
  else
  {
    printf("El producto de id %d NO pertenece a la promocion.\n",
           idTProducto(p));
  }

  liberarTProducto(p);
}

void main_idPromocion(TPromocion promocion)
{
  printf("El id de la promocion es: %d.\n", idTPromocion(promocion));
}

void main_fechaInicioTPromocion(TPromocion promocion)
{
  printf("La fecha inicio de la promocion es: ");
  TFecha fechaIni = fechaInicioTPromocion(promocion);
  imprimirTFecha(fechaIni);
  printf("\n");
}

void main_fechaFinTPromocion(TPromocion promocion)
{
  printf("La fecha fin de la promocion es: ");
  TFecha fechaFin = fechaFinTPromocion(promocion);
  imprimirTFecha(fechaFin);
  printf("\n");
}

void main_imprimirPromocion(TPromocion promocion)
{
  imprimirTPromocion(promocion);
}

void main_sonPromocionesCompatibles(TPromocion promocion1)
{
  TFecha fechaIni;
  leerFecha(fechaIni);

  TFecha fechaFin;
  leerFecha(fechaFin);

  int cantMax = leerInt();
  int id = leerInt();

  TPromocion promocion2 = crearTPromocion(id, fechaIni, fechaFin, cantMax);

  int cant = leerInt();
  for (int i = 0; i < cant; i++)
  {
    int idProducto = leerInt();

    TFecha fechaDummy = crearTFecha(1, 1, 1);
    TProducto p =
        crearTProducto(idProducto, NOMBRE_PRODUCTO, PRECIO_DUMMY, fechaDummy);
    agregarATPromocion(promocion2, p);
    liberarTProducto(p);
  }

  if (sonPromocionesCompatibles(promocion1, promocion2))
  {
    printf("Las promociones son compatibles.\n");
  }
  else
  {
    printf("Las promociones NO son compatibles.\n");
  }

  liberarTPromocion(promocion2);
}

void main_liberarTPromocion(TPromocion &promocion)
{
  liberarTPromocion(promocion);
  printf("Promocion liberada con exito.\n");
}

///////////////////////////////////
//       Lista Promociones      //
///////////////////////////////////
void main_crearListaPromociones(TListaPromociones &listaPromociones)
{
  assert(listaPromociones == NULL);

  listaPromociones = crearTListaPromocionesVacia();
  printf("Lista de promociones creada con exito.\n");
}

void main_agregarAListaPromociones(TListaPromociones &listaPromociones,
                                   TPromocion &promocion)
{
  assert(promocion != NULL);
  agregarPromocionTListaPromociones(listaPromociones, promocion);
  promocion = NULL;
  printf("Se ha agregado la promocion a la lista de forma exitosa.\n");
}

void main_esVaciaListaPromociones(TListaPromociones listaPromociones)
{
  bool esVacia = esVaciaTListaPromociones(listaPromociones);
  if (esVacia)
  {
    printf("La lista de promociones es vacia.\n");
  }
  else
  {
    printf("La lista de promociones NO es vacia.\n");
  }
}

void main_imprimirListaPromociones(TListaPromociones listaPromociones)
{
  imprimirTListaPromociones(listaPromociones);
}

void main_liberarListaPromociones(TListaPromociones &listaPromociones)
{
  liberarTListaPromociones(listaPromociones, true);
  printf("Lista promociones liberada con exito.\n");
}

void main_pertenecePromocionListaPromociones(
    TListaPromociones listaPromociones)
{
  int idExpo = leerInt();

  bool pertenece =
      pertenecePromocionTListaPromociones(listaPromociones, idExpo);
  if (pertenece)
  {
    printf("La promocion de id %d pertenece a la lista de promociones.\n",
           idExpo);
  }
  else
  {
    printf("La promocion de id %d NO pertenece a la lista de promociones.\n",
           idExpo);
  }
}

void main_obtenerPromocionListaPromociones(TListaPromociones listaPromociones)
{
  int idExpo = leerInt();

  bool pertenece =
      pertenecePromocionTListaPromociones(listaPromociones, idExpo);
  if (pertenece)
  {
    TPromocion promocion =
        obtenerPromocionTListaPromociones(listaPromociones, idExpo);
    imprimirTPromocion(promocion);
  }
  else
  {
    printf("La promocion de id %d NO pertenece a la lista de promociones.\n",
           idExpo);
  }
}

void main_obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones)
{
  TFecha fecha;
  leerFecha(fecha);

  TListaPromociones finalizadas =
      obtenerPromocionesFinalizadas(listaPromociones, fecha);

  printf("Promociones finalizadas: \n");
  imprimirTListaPromociones(finalizadas);
  liberarTListaPromociones(finalizadas, true);
  liberarTFecha(fecha);
}

void main_obtenerPromocionesActivas(TListaPromociones &listaPromociones)
{
  TFecha fecha;
  leerFecha(fecha);

  TListaPromociones activas =
      obtenerPromocionesActivas(listaPromociones, fecha);

  printf("Promociones activas: \n");
  imprimirTListaPromociones(activas);
  liberarTListaPromociones(activas, true);
  liberarTFecha(fecha);
}

void main_esCompatibleListaPromociones(TListaPromociones listaPromociones,
                                       TPromocion promocion)
{
  bool compatible = esCompatibleTListaPromociones(listaPromociones, promocion);

  if (compatible)
  {
    printf("La promocion es compatible con el resto de las promociones de la "
           "lista.\n");
  }
  else
  {
    printf("La promocion NO es compatible con el resto de las promociones de "
           "la lista.\n");
  }
}

void main_unirListaPromociones(TListaPromociones listaPromociones)
{
  TListaPromociones lista2 = crearTListaPromocionesVacia();
  int cantidadPromociones = leerInt();
  for (int i = 0; i < cantidadPromociones; i++)
  {
    TFecha fechaInicio = NULL;
    leerFecha(fechaInicio);
    TFecha fechaFin = NULL;
    leerFecha(fechaFin);
    int cantidadProductos = leerInt();
    int idExpo = leerInt();
    TPromocion promocion =
        crearTPromocion(idExpo, fechaInicio, fechaFin, cantidadProductos);
    int cantidadProductosAgregar = leerInt();
    for (int i = 0; i < cantidadProductosAgregar; i++)
    {
      int idProducto = leerInt();

      TFecha fechaDummy = crearTFecha(1, 1, 1);
      TProducto p =
          crearTProducto(idProducto, NOMBRE_PRODUCTO, PRECIO_DUMMY, fechaDummy);
      agregarATPromocion(promocion, p);
      liberarTProducto(p);
    }
    agregarPromocionTListaPromociones(lista2, promocion);
  }
  TListaPromociones unida = unirListaPromociones(listaPromociones, lista2);
  imprimirTListaPromociones(unida);
  liberarTListaPromociones(unida, false);
  liberarTListaPromociones(lista2, true);
}

///////////////////////////////////
//             Historial           //
///////////////////////////////////
void main_crearHistorial(THistorial &historial)
{
  assert(historial == NULL);

  TFecha fechaActual;
  leerFecha(fechaActual);

  historial = crearTHistorial(fechaActual);
  printf("Historial creado con exito.\n");
}

void main_agregarPromocionHistorial(THistorial historial,
                                    TPromocion &promocion)
{
  agregarPromocionTHistorial(historial, promocion);
  promocion = NULL;
  printf("La promocion fue agregada al historial con exito.\n");
}

void main_agregarProductoAPromocionHistorial(THistorial historial,
                                             TProducto &producto)
{
  int idExpo = leerInt();

  agregarProductoAPromocionTHistorial(historial, producto, idExpo);
  liberarTProducto(producto);
  printf("El producto fue agregado a la promocion de id %d.\n", idExpo);
}

void main_avanzarAFechaHistorial(THistorial historial)
{
  TFecha fecha;
  leerFecha(fecha);
  avanzarAFechaTHistorial(historial, fecha);
  printf("Se avanzo la fecha de la historial a ");
  imprimirTFecha(fecha);
  printf("\n");
}

void main_imprimirPromocionesFinalizadosHistorial(THistorial historial)
{
  printf("Promociones finalizadas:\n");
  imprimirPromocionesFinalizadosTHistorial(historial);
}

void main_imprimirPromocionesActivasHistorial(THistorial historial)
{
  printf("Promociones activas:\n");
  imprimirPromocionesActivasTHistorial(historial);
}

void main_imprimirPromocionesFuturasHistorial(THistorial historial)
{
  printf("Promociones futuras:\n");
  imprimirPromocionesFuturasTHistorial(historial);
}

void main_esCompatiblePromocionHistorial(THistorial historial,
                                         TPromocion promocion)
{
  bool esCompatible = esCompatiblePromocionTHistorial(historial, promocion);
  if (esCompatible)
  {
    printf("La promocion es compatible con las demas promociones de la "
           "historial.\n");
  }
  else
  {
    printf("La promocion NO es compatible con las demas promociones de la "
           "historial.\n");
  }
}

void main_liberarHistorial(THistorial &historial)
{
  liberarTHistorial(historial);
  printf("Historial liberada con exito.\n");
}
