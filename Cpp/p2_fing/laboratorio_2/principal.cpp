/*
  Módulo principal de la Tarea 2.

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
#include "include/clientesSucursalesLDE.h"

#define MAX_PALABRA 32
#define MAX_LINEA 256

///////////////////////////////
// Funciones main para Fecha //
///////////////////////////////

void leerFecha(TFecha &fecha); // Lee una fecha de la entrada en formato "dd/mm/aaaa" y la escribe la variable fecha
void main_crearFecha(TFecha &fecha); // Crea una fecha y la almacena en la variable fecha
void main_liberarFecha(TFecha &fecha); // Libera la memoria de la variable fecha
void main_imprimirFecha(TFecha fecha); // Imprime la fecha almacenada en la variable fecha
void main_aumentarDias(TFecha &fecha); // Aumenta la fecha almacenada en la variable fecha en la cantidad de días indicada
void main_compararFechas(); // Compara dos fechas leidas de la entrada

////////////////////////////////////
// Funciones main para Clientes  //
////////////////////////////////////

void main_crearCliente(TCliente &cliente); // Crea un cliente y lo almacena en la variable 'cliente'
void main_imprimirCliente(TCliente cliente); // Imprime el cliente almacenado en 'cliente'
void main_liberarCliente(TCliente &cliente); // Libera la memoria asociada al cliente guardado en la variable 'cliente'
void main_imprimirNombreYApellidoCliente(TCliente cliente); //Imprime el nombre y apellido del cliente almacenado en la variable 'cliente'
void main_imprimirIdCliente(TCliente cliente); // Imprime el id del cliente almacenado en la variable 'cliente'
void main_imprimirEdadCliente(TCliente cliente); // Imprime la edad del cliente almacenado en la variable 'cliente'
void main_copiarCliente(TCliente cliente); // copia visitante en visitante


///////////////////////////////////////
//   Funciones main para Productos   //
///////////////////////////////////////
void main_crearTProducto(TProducto &producto, TFecha &fecha);
void main_imprimirTProducto(TProducto producto);
void main_liberarTProducto(TProducto &producto);
void main_idTProducto(TProducto producto);
void main_precioTProducto(TProducto producto);


////////////////////////////////////////////////
//  Funciones main para Carrito de Productos  //
////////////////////////////////////////////////
void main_crearCarritoProductos(TCarritoProductos &carritoProductos);
void main_agregarCarritoProductos(TCarritoProductos &carritoProductos, TProducto &producto);
void main_imprimirCarritoProductos(TCarritoProductos carritoProductos);
void main_liberarCarritoProductos(TCarritoProductos &carritoProductos);
void main_esVacioCarritoProductos(TCarritoProductos carritoProductos);
void main_existeProductoCarritoProductos(TCarritoProductos carritoProductos);
void main_obtenerProductoCarritoProductos(TCarritoProductos carritoProductos);
void main_removerDeCarritoProductos(TCarritoProductos &carritoProductos);

//////////////////////////////////
// Funciones main para ClientesABB //
//////////////////////////////////
void main_crearClientesABB(TClientesABB &clientesABB); // Crea un clientesABB y la almacena en la variable clientesABB
void main_agregarClienteAClientesABB(TClientesABB &clientesABB, TCliente &cliente); // Agrega el visitante almacenada en la variable 'visitante' al clientesABB almacenado en la variable clientesABB
void main_imprimirClientesABB(TClientesABB clientesABB); // Imprime toda la información del clientesABB almacenado en la variable clientesABB
void main_liberarClientesABB(TClientesABB &clientesABB);
void main_existeClienteEnClientesABB(TClientesABB clientesABB);
void main_obtenerClienteClientesABB(TClientesABB clientesABB);
void main_alturaClientesABB(TClientesABB clientesABB);
void main_maxIdClientesABB(TClientesABB clientesABB);
void main_cantidadClientesClientesABB(TClientesABB clientesABB);
void main_edadPromedioClientesABB(TClientesABB clientesABB);
void main_removerDeClientesABB(TClientesABB &clientesABB);
void main_obtenerNesimoClienteClientesABB(TClientesABB clientesABB);
void main_alturaClientesABBTiempo();
void main_obtenerExisteClienteClientesABBTiempo();

//////////////////////////////////////////
// Funciones main para TClientesSucursalesLDE //
//////////////////////////////////////////
void main_crearClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE);
void main_agregarClientesASucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE, TClientesABB &clientesABB);
void main_imprimirClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_imprimirInvertidaClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_cantidadClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE);
void main_liberarClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE);
void main_clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE);


// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TCliente cliente = NULL;
    TClientesABB clientesABB = NULL;
    TProducto producto = NULL;
    TCarritoProductos carritoProductos = NULL;
    TClientesSucursalesLDE clientesSucursalesLDE = NULL;

    char restoLinea[MAX_LINEA + 1];
    char cmd[MAX_PALABRA];

    int cont_comandos = 0;
    bool seguir = true;
    printf("Bienvenido al programa principal de Mercado FINGer. Por favor ingrese su comando:\n");
    while (seguir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%u> ", cont_comandos);

        // leer el comando en la variable cmd
        leerChars(cmd);

        // procesar el comando
        if (cmd_es("Fin", cmd)) {  // Termina el programa
            seguir = false;
            printf("Fin.\n");

        } else if (cmd_es("#", cmd)) {  // Imprime el comentario luego del #
            leerRestoLinea(restoLinea);
            printf("# %s.\n", restoLinea);

            ///////////////////////////////////
            /* Funciones para testear fecha */
            ///////////////////////////////////

        } else if (cmd_es("crearFecha", cmd)) {
            main_crearFecha(fecha);
        } else if (cmd_es("imprimirFecha", cmd)) {
            main_imprimirFecha(fecha);
        } else if (cmd_es("liberarFecha", cmd)) {
            main_liberarFecha(fecha);
        } else if (cmd_es("aumentarDias", cmd)) {
            main_aumentarDias(fecha);
        } else if (cmd_es("compararFechas", cmd)) {
            main_compararFechas();

            //////////////////////////////////////
            /* Funciones para testear Cliente */
            //////////////////////////////////////

        } else if (cmd_es("crearCliente", cmd)) {
            main_crearCliente(cliente);
        } else if (cmd_es("imprimirEdadCliente", cmd)) {
            main_imprimirEdadCliente(cliente);
        } else if (cmd_es("imprimirIdCliente",cmd)){
            main_imprimirIdCliente(cliente);
        } else if (cmd_es("imprimirNombreYApellidoCliente", cmd)){
            main_imprimirNombreYApellidoCliente(cliente);
        } else if (cmd_es("imprimirCliente", cmd)) {
            main_imprimirCliente(cliente);
        } else if (cmd_es("copiarCliente",cmd)){
            main_copiarCliente(cliente);
        } else if (cmd_es("liberarCliente", cmd)) {
            main_liberarCliente(cliente);

            ////////////////////////////////////
            //   Funciones main para Productos   //
            ////////////////////////////////////
        } else if (cmd_es("crearProducto", cmd)) {
            main_crearTProducto(producto, fecha);
        } else if (cmd_es("imprimirProducto", cmd)) {
            main_imprimirTProducto(producto);
        } else if (cmd_es("liberarProducto", cmd)) {
            main_liberarTProducto(producto);
        } else if (cmd_es("idProducto", cmd)) {
            main_idTProducto(producto);
        } else if (cmd_es("precioProducto",cmd)) {
            main_precioTProducto(producto);

            //////////////////////////////////////////////
            //   Funciones main para Carrito de Productos   //
            //////////////////////////////////////////////
        } else if (cmd_es("crearCarritoProductos", cmd)) {
            main_crearCarritoProductos(carritoProductos);
        } else if (cmd_es("agregarCarritoProductos", cmd)) {
            main_agregarCarritoProductos(carritoProductos, producto);
        } else if (cmd_es("imprimirCarritoProductos", cmd)) {
            main_imprimirCarritoProductos(carritoProductos);
        } else if (cmd_es("liberarCarritoProductos", cmd)) {
            main_liberarCarritoProductos(carritoProductos);
        } else if (cmd_es("esVacioCarritoProductos", cmd)) {
            main_esVacioCarritoProductos(carritoProductos);
        } else if (cmd_es("existeProductoCarritoProductos", cmd)){
            main_existeProductoCarritoProductos(carritoProductos);
        } else if (cmd_es("obtenerProductoCarritoProductos", cmd)) {
            main_obtenerProductoCarritoProductos(carritoProductos);
        } else if (cmd_es("removerDeCarritoProductos", cmd)) {
            main_removerDeCarritoProductos(carritoProductos);


            ///////////////////////////////////////
            /* Funciones para testear ClientesABB */
            ///////////////////////////////////////
        } else if (cmd_es("crearClientesABB", cmd)) {  // Crea un clientesABB y la almacena en la variable clientesABB
            main_crearClientesABB(clientesABB);
        } else if (cmd_es("agregarAClientesABB", cmd)) {
            main_agregarClienteAClientesABB(clientesABB, cliente);
        } else if (cmd_es("imprimirClientesABB", cmd)) {
            main_imprimirClientesABB(clientesABB);
        } else if (cmd_es("existeEnClientesABB", cmd)) {
            main_existeClienteEnClientesABB(clientesABB);
        } else if (cmd_es("obtenerClienteClientesABB", cmd)) {
            main_obtenerClienteClientesABB(clientesABB);
        } else if (cmd_es("alturaClientesABB", cmd)) {
            main_alturaClientesABB(clientesABB);
        } else if (cmd_es("maxIdClientesABB", cmd)) {
            main_maxIdClientesABB(clientesABB);
        } else if (cmd_es("cantidadClientesClientesABB", cmd)) {
            main_cantidadClientesClientesABB(clientesABB);
        } else if (cmd_es("edadPromedioClientesABB", cmd)) {
            main_edadPromedioClientesABB(clientesABB);
        } else if (cmd_es("removerDeClientesABB", cmd)) {
            main_removerDeClientesABB(clientesABB);
        } else if (cmd_es("liberarClientesABB", cmd)) {
            main_liberarClientesABB(clientesABB);
        } else if (cmd_es("obtenerNesimoClienteClientesABB", cmd)) {
            main_obtenerNesimoClienteClientesABB(clientesABB);
        } else if (cmd_es("alturaClientesABBTiempo", cmd)) {
            main_alturaClientesABBTiempo();
        } else if (cmd_es("obtenerExisteClienteClientesABBTiempo", cmd)) {
            main_obtenerExisteClienteClientesABBTiempo();

            ////////////////////////////////////////////////////
            // Funciones para testear TClientesSucursalesLDE  //
            ////////////////////////////////////////////////////
        } else if (cmd_es("crearClientesSucursalesLDE", cmd)) {
            main_crearClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("agregarAClientesSucursalesLDE", cmd)) {
            main_agregarClientesASucursalesLDE(clientesSucursalesLDE, clientesABB);
        } else if (cmd_es("imprimirClientesSucursalesLDE", cmd)) {
            main_imprimirClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("imprimirInvertidaClientesSucursalesLDE", cmd)) {
            main_imprimirInvertidaClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("obtenerNesimoClientesSucursalesLDE", cmd)) {
            main_obtenerNesimoClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("cantidadClientesSucursalesLDE", cmd)) {
            main_cantidadClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("obtenerPrimeroClientesSucursalesLDE", cmd)) {
            main_obtenerPrimeroClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("removerUltimoClientesSucursalesLDE", cmd)) {
            main_removerUltimoClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("removerNesimoClientesSucursalesLDE", cmd)) {
            main_removerNesimoClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("liberarClientesSucursalesLDE", cmd)) {
            main_liberarClientesSucursalesLDE(clientesSucursalesLDE);
        } else if (cmd_es("clienteMasRepetido", cmd)) {
            main_clienteMasRepetido(clientesSucursalesLDE);


        } else {
            printf("Comando no reconocido.\n");  // Comando no reconocido
        }

        consumirRestoLinea();

    }  // while

    return 0;
}  // main

///////////////////////////////
/* Funciones main para Fecha */
///////////////////////////////

void leerFecha(TFecha &fecha) {
    nat *componentes = new nat[3];
    scanf("%u/%u/%u", &componentes[0], &componentes[1], &componentes[2]);
    fecha = crearTFecha(componentes[0], componentes[1], componentes[2]);
    delete[] componentes;
}

void main_crearFecha(TFecha &fecha) {
    assert(fecha == NULL);
    leerFecha(fecha);
    printf("Fecha creada en forma exitosa.\n");
}

void main_liberarFecha(TFecha &fecha) {
    assert(fecha != NULL);
    liberarTFecha(fecha);
    printf("Fecha liberada en forma exitosa.\n");
}

void main_imprimirFecha(TFecha fecha) {
    assert(fecha != NULL);
    imprimirTFecha(fecha);
}

void main_aumentarDias(TFecha &fecha) {
    assert(fecha != NULL);
    nat cantDias = leerNat();
    aumentarTFecha(fecha, cantDias);
    printf("La nueva fecha aplazada %d dias es: \n", cantDias);
    imprimirTFecha(fecha);
}

void main_compararFechas() {
    TFecha fecha1 = NULL, fecha2 = NULL;
    leerFecha(fecha1);
    leerFecha(fecha2);
    int comp = compararTFechas(fecha1, fecha2);
    if (comp == 0) {
        printf("Las fechas son iguales. \n");
    } else if (comp == 1) {
        printf("La primera fecha es posterior a la segunda. \n");
    } else
        printf("La primera fecha es anterior a la segunda. \n");
    liberarTFecha(fecha1);
    liberarTFecha(fecha2);
}

///////////////////////////////////
/* Funciones main para Clientes */
///////////////////////////////////

void main_crearCliente(TCliente &cliente){
    assert(cliente == NULL);
    int id = leerInt();
    char nombre[MAX_NOMBRE];
    leerChars(nombre);
    char apellido[MAX_APELLIDO];
    leerChars(apellido);
    int edad = leerInt();
    cliente = crearTCliente(id, nombre, apellido, edad);
    printf("Cliente creado de forma exitosa.\n");
}

void main_imprimirEdadCliente(TCliente cliente) {
    assert(cliente != NULL);
    printf("La edad del cliente es: %d\n", edadTCliente(cliente));
}

void main_imprimirIdCliente(TCliente cliente) {
    assert(cliente != NULL);
    printf("El id del cliente es: %d\n", idTCliente(cliente));
}

void main_imprimirNombreYApellidoCliente(TCliente cliente){
    assert(cliente != NULL);
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    nombreTCliente(cliente, nombre);
    apellidoTCliente(cliente, apellido);
    printf("El nombre del cliente es: %s\n", nombre);
    printf("El apellido del cliente es: %s\n", apellido);
}

void main_imprimirCliente(TCliente cliente) {
    assert(cliente != NULL);
    imprimirTCliente(cliente);
}

void main_copiarCliente(TCliente cliente){
    TCliente clienteCopia = copiarTCliente(cliente);
    printf("Cliente copiado. Datos de la copia:\n");
    imprimirTCliente(clienteCopia);

    liberarTCliente(clienteCopia);
}

void main_liberarCliente(TCliente &cliente) {
    assert(cliente != NULL);
    liberarTCliente(cliente);
    printf("Cliente liberado con exito.\n");
}

////////////////////////////////////
//   Funciones main para Productos   //
////////////////////////////////////
void main_crearTProducto(TProducto &producto, TFecha &fecha){
    assert(producto == NULL);
    int id = leerInt();
    char nombreProducto[MAX_NOMBRE_PRODUCTO];
    leerChars(nombreProducto);
    int precio = leerInt();
    producto = crearTProducto(id, nombreProducto, precio, fecha);
    fecha = NULL;
    printf("Producto creado en forma exitosa.\n");
}

void main_imprimirTProducto(TProducto producto){
    assert(producto != NULL);
    imprimirTProducto(producto);
}

void main_liberarTProducto(TProducto &producto){
    assert(producto != NULL);
    liberarTProducto(producto);
    producto = NULL;
    printf("Producto liberado en forma exitosa.\n");
}

void main_idTProducto(TProducto producto){
    assert(producto != NULL);
    int id = idTProducto(producto);
    printf("ID: %d\n", id);
}


void main_precioTProducto(TProducto producto){
    assert(producto != NULL);
    int precio = precioTProducto(producto);
    printf("Precio: %d\n", precio);
}

//////////////////////////////////////////////
//   Funciones main para Carrito de Productos   //
//////////////////////////////////////////////
void main_crearCarritoProductos(TCarritoProductos &carritoProductos){
    assert(carritoProductos == NULL);
    carritoProductos = crearCarritoProductosVacio();
    printf("Carrito de productos creado de forma exitosa.\n");
}

void main_agregarCarritoProductos(TCarritoProductos &carritoProductos, TProducto &producto){
    insertarProductoCarritoProductos(carritoProductos, producto);
    printf("Producto agregado de forma exitosa.\n");
    producto = NULL;
}

void main_imprimirCarritoProductos(TCarritoProductos carritoProductos){
    imprimirCarritoProductos(carritoProductos);
}

void main_liberarCarritoProductos(TCarritoProductos &carritoProductos){
    liberarCarritoProductos(carritoProductos);
    printf("Carrito de productos liberado con exito.\n");
}

void main_esVacioCarritoProductos(TCarritoProductos carritoProductos){
    bool esVacia = esVacioCarritoProductos(carritoProductos);
    if (esVacia){
        printf("El carrito de productos es vacio.\n");
    } else {
        printf("El carrito de productos NO es vacio.\n");
    }
}

void main_existeProductoCarritoProductos(TCarritoProductos carritoProductos){
    int id = leerInt();
    bool existe = existeProductoCarritoProductos(carritoProductos, id);
    if (existe){
        printf("El producto con id %d se encuentra a el carrito.\n", id);
    } else {
        printf("El producto con id %d NO se encuentra en el carrito.\n", id);
    }
}

void main_obtenerProductoCarritoProductos(TCarritoProductos carritoProductos){
    int id = leerInt();
    assert(existeProductoCarritoProductos(carritoProductos, id));
    TProducto producto = obtenerProductoCarritoProductos(carritoProductos, id);
    imprimirTProducto(producto);
}

void main_removerDeCarritoProductos(TCarritoProductos &carritoProductos){
    int id = leerInt();
    assert(existeProductoCarritoProductos(carritoProductos, id));
    removerProductoCarritoProductos(carritoProductos, id);
    printf("Producto con id %d removido con exito.\n", id);
}


//////////////////////////////////////
/* Funciones main para ClientesABB */
/////////////////////////////////////

void main_crearClientesABB(TClientesABB &clientesABB){
    assert(clientesABB == NULL);
    clientesABB = crearTClientesABBVacio();
    printf("El clientesABB ha sido creado de forma exitosa.\n");
}

void main_agregarClienteAClientesABB(TClientesABB &clientesABB, TCliente &cliente){
    assert(cliente != NULL);
    insertarTClienteTClientesABB(clientesABB, cliente);
    cliente = NULL;
    printf("Se ha agregado el cliente al clientesABB de forma exitosa.\n");
}

void main_imprimirClientesABB(TClientesABB clientesABB){
    imprimirTClientesABB(clientesABB);
}

void main_liberarClientesABB(TClientesABB &clientesABB){
    liberarTClientesABB(clientesABB);
    printf("ClientesABB liberado con exito.\n");
}

void main_existeClienteEnClientesABB(TClientesABB clientesABB){
    int id = leerInt();
    if (existeTClienteTClientesABB(clientesABB, id)){
        printf("El cliente con id %d pertenece al clientesABB.\n", id);
    }else{
        printf("El cliente con id %d NO pertenece al clientesABB.\n", id);
    }
}

void main_obtenerClienteClientesABB(TClientesABB clientesABB){
    int id = leerInt();
    TCliente cliente = obtenerTClienteTClientesABB(clientesABB, id);
    if (cliente == NULL){
        printf("El cliente con id %d no se puede imprimir pues NO pertenece al clientesABB.\n", id);
    }else{
        imprimirTCliente(cliente);
    }
}

void main_alturaClientesABB(TClientesABB clientesABB){
    nat altura = alturaTClientesABB(clientesABB);
    printf("La altura del clientesABB es %d.\n", altura);
}

void main_maxIdClientesABB(TClientesABB clientesABB){
    TCliente maxId = maxIdTClienteTClientesABB(clientesABB);
    printf("El mayor id en el clientesABB es %d.\n", idTCliente(maxId));
}

void main_cantidadClientesClientesABB(TClientesABB clientesABB){
    int cantidad = cantidadClientesTClientesABB(clientesABB);
    printf("La cantidad de clientes en el clientesABB es %d.\n", cantidad);
}

void main_edadPromedioClientesABB(TClientesABB clientesABB){
    float edadPromedio = edadPromedioTClientesABB(clientesABB);
    printf("La edad promedio del clientesABB es %.2f.\n", edadPromedio);
}

void main_removerDeClientesABB(TClientesABB &clientesABB){
    int id = leerInt();
    if (existeTClienteTClientesABB(clientesABB, id)) {
        removerTClienteTClientesABB(clientesABB, id);
        printf("El cliente con id %d se removio del clientesABB.\n", id);
    } else {
        printf("El cliente con id %d no se puede remover porque NO pertenece al clientesABB.\n", id);
    }
}

void main_obtenerNesimoClienteClientesABB(TClientesABB clientesABB){
    int n = leerInt();
    int cantEnClientesABB = cantidadClientesTClientesABB(clientesABB);
    if (cantEnClientesABB >= n) {
        TCliente cliente = obtenerNesimoClienteTClientesABB(clientesABB, n);
        printf("Cliente nro %d del clientesABB:\n", n);
        imprimirTCliente(cliente);
    } else {
        printf("No se puede imprimir vistante %d del clientesABB porque tiene solo %d clientes.\n", n, cantEnClientesABB);
    }
}

void insertarEnArbolDesdeArreglo(TClientesABB &clientesABB, TCliente *arreglo, int inicio, int final){
    if (inicio <= final){
        int mid = (inicio + final) / 2;
        insertarTClienteTClientesABB(clientesABB, arreglo[mid]);
        insertarEnArbolDesdeArreglo(clientesABB, arreglo, inicio, mid - 1);
        insertarEnArbolDesdeArreglo(clientesABB, arreglo, mid + 1, final);
    }
}

void main_alturaClientesABBTiempo(){
    TClientesABB clientesABB = crearTClientesABBVacio();

    nat tamanio = leerNat();
    nat timeout = leerNat();

    TCliente *arreglo = new TCliente[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTCliente(i, "Alberto", "Pardo", 52);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(clientesABB, arreglo, inicio, final);
    clock_t tm = clock();
    nat altura = alturaTClientesABB(clientesABB);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    }else{
        printf("La altura del clientesABB es %d. Calculado correctamente en menos de %ds.\n", altura, timeout);
    }

    liberarTClientesABB(clientesABB);
    delete[] arreglo;
}

void main_obtenerExisteClienteClientesABBTiempo(){
    TClientesABB clientesABB = crearTClientesABBVacio();

    nat tamanio = leerNat();
    double timeout = leerDouble();

    TCliente *arreglo = new TCliente[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTCliente(i, "Carlos", "Luna", 45);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(clientesABB, arreglo, inicio, final);
    clock_t tm = clock();
    bool existeCliente1 = existeTClienteTClientesABB(clientesABB, 0);
    bool existeCliente2 = existeTClienteTClientesABB(clientesABB, tamanio - 1);
    bool existeCliente3 = existeTClienteTClientesABB(clientesABB, tamanio / 3);
    bool existeCliente4 = existeTClienteTClientesABB(clientesABB, (2 * tamanio) / 3);
    TCliente cliente1 = obtenerTClienteTClientesABB(clientesABB, 0);
    TCliente cliente2 = obtenerTClienteTClientesABB(clientesABB, tamanio - 1);
    TCliente cliente3 = obtenerTClienteTClientesABB(clientesABB, tamanio / 3);
    TCliente cliente4 = obtenerTClienteTClientesABB(clientesABB, (2 * tamanio) / 3);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido: %.3f > %.3f \n", tiempo, timeout);
    }else{
        printf("Se obtuvieron los clientes? %d %d %d %d con ids respectivos %d %d %d %d\n", existeCliente1, existeCliente2, existeCliente3, existeCliente4, idTCliente(cliente1), idTCliente(cliente2), idTCliente(cliente3), idTCliente(cliente4));
        printf("Calculado correctamente en menos de %.3fs.\n", timeout);
    }

    liberarTClientesABB(clientesABB);
    delete[] arreglo;
}

////////////////////////////////////////////////
// Funciones main para TClientesSucursalesLDE //
///////////////////////////////////////////////
void main_crearClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE){
    assert(clientesSucursalesLDE == NULL);
    clientesSucursalesLDE = crearTClientesSucursalesLDEVacia();
    printf("La SucursalesLDE de clientes ha sido creado de forma exitosa.\n");
}

void main_agregarClientesASucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE, TClientesABB &clientesABB){
    assert(clientesABB != NULL);
    int idSucursal = leerInt();
    insertarClientesABBTClientesSucursalesLDE(clientesSucursalesLDE, clientesABB, idSucursal);
    clientesABB = NULL;
    printf("Se ha agregado el clientesABB a SucursalesLDE de forma exitosa.\n");
}

void main_imprimirClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    imprimirTClientesSucursalesLDE(clientesSucursalesLDE);
}

void main_imprimirInvertidaClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    imprimirInvertidoTClientesSucursalesLDE(clientesSucursalesLDE);
}

void main_obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    int n = leerInt();
    TClientesABB clientesABB = obtenerNesimoClientesSucursalesLDE(clientesSucursalesLDE, n);
    if (clientesABB){
        printf("ClientesABB en la posicion %d:\n", n);
        imprimirTClientesABB(clientesABB);
    }else{
        printf("NO existe un clientesABB en la posicion %d\n", n);
    }
}

void main_cantidadClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    nat cant = cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE);
    printf("La cantidad de clientesABB en SucursalesLDE es %d\n", cant);
}

void main_obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    nat cant = cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE);
    if (cant > 0){
        TClientesABB clientesABB = obtenerPrimeroClientesSucursalesLDE(clientesSucursalesLDE);
        assert(clientesABB != NULL);
        printf("Primer clientesABB:\n");
        imprimirTClientesABB(clientesABB);
    }else{
        printf("No se puede obtener el primero de los clientesABB de SucursalesLDE porque es vacia\n");
    }
}

void main_removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    nat cant = cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE);
    if (cant > 0){
        TClientesABB clientesABB = removerUltimoClientesSucursalesLDE(clientesSucursalesLDE);
        assert(clientesABB != NULL);
        printf("Ultimo clientesABB (removido):\n");
        imprimirTClientesABB(clientesABB);
        liberarTClientesABB(clientesABB);
    }else{
        printf("No se puede remover el ultimo clientesABB de SucursalesLDE porque es vacia\n");
    }
}

void main_removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
    nat n = leerNat();
    nat cant = cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE);
    if (cant >= n){
        TClientesABB clientesABB = removerNesimoClientesSucursalesLDE(clientesSucursalesLDE, n);
        assert(clientesABB != NULL);
        printf("clientesABB en la posicion %d (removido):\n", n);
        imprimirTClientesABB(clientesABB);
        liberarTClientesABB(clientesABB);
    }else{
        printf("No se puede remover el elemento %d de SucursalesLDE porque solo contiene %d\n", n, cant);
    }
}

void main_liberarClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE){
    assert(clientesSucursalesLDE != NULL);
    liberarTClientesSucursalesLDE(clientesSucursalesLDE);
    printf("SucursalesLDE de ClientesABB liberada\n");
    clientesSucursalesLDE = NULL;
}

void main_clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE){
    assert(clientesSucursalesLDE != NULL);
    TCliente cliente = clienteMasRepetido(clientesSucursalesLDE);
    if (cliente == NULL){
        printf("No hay cliente repetido porque no hay clientes en los clientesABB de sucursales.\n");
    }else{
        printf("El cliente que aparece en la mayor cantidad de sucursales es:\n");
        imprimirTCliente(cliente);
    }
}


