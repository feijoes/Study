#include "../include/carritoProductos.h"

struct rep_carritoProductos
{
    TProducto producto;
    TCarritoProductos sig;
};

TCarritoProductos crearCarritoProductosVacio()
{
    TCarritoProductos carrito = new rep_carritoProductos;
    carrito->sig = NULL;
    carrito->producto = NULL;
    return carrito;
}
TCarritoProductos crearCarritoProductosConProducto(TProducto producto)
{
    TCarritoProductos carrito = crearCarritoProductosVacio();
    carrito->producto = producto;
    return carrito;
}

void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto)
{
    if (carritoProductos == NULL){
        carritoProductos = crearCarritoProductosConProducto(producto);
        return;
    }
    if (carritoProductos != NULL && carritoProductos->producto == NULL)
    {
        carritoProductos->producto = producto;
        return;
    }
    TCarritoProductos carrito = crearCarritoProductosConProducto(producto);
    if (idTProducto(carritoProductos->producto) > idTProducto(producto))
    {
        carrito->sig = carritoProductos;
        carritoProductos = carrito ;
        return;
    }
    TCarritoProductos carritosCopy_before = carritoProductos;
    while (carritosCopy_before->sig != NULL && idTProducto(carritosCopy_before->sig->producto) < idTProducto(producto))
    {
        carritosCopy_before = carritosCopy_before->sig;
    }
    carrito->sig = carritosCopy_before->sig;
    carritosCopy_before->sig = carrito;
}

void imprimirCarritoProductos(TCarritoProductos carritoProductos)
{
    TCarritoProductos carritosCopy = carritoProductos;
    while (carritosCopy != NULL && carritosCopy->producto != NULL)
    {
        imprimirTProducto(carritosCopy->producto);
        carritosCopy = carritosCopy->sig;
    }
}

void liberarCarritoProductos(TCarritoProductos &carritoProductos)
{
    while (carritoProductos != NULL && carritoProductos->producto != NULL)
    {
        liberarTProducto(carritoProductos->producto);
        TCarritoProductos to_delete = carritoProductos;
        carritoProductos = carritoProductos->sig;
        delete to_delete;
    }
    delete carritoProductos;
    carritoProductos = NULL;
}

bool esVacioCarritoProductos(TCarritoProductos carritoProductos)
{
    return carritoProductos == NULL || carritoProductos->producto == NULL;
}

bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto)
{
    TCarritoProductos carritosCopy = carritoProductos;
    while (carritosCopy != NULL && carritosCopy->producto != NULL)
    {
        if (idTProducto(carritosCopy->producto) == idProducto)
        {
            return true;
        }
        carritosCopy = carritosCopy->sig;
    }
    return false;
}

TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto)
{
    TCarritoProductos carritosCopy = carritoProductos;
    while (carritosCopy != NULL && carritosCopy->producto != NULL)
    {
        if (idTProducto(carritosCopy->producto) == idProducto)
        {
            return carritosCopy->producto;
        }
        carritosCopy = carritosCopy->sig;
    }
    return NULL;
}

void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto) {
    
    if (carritoProductos->producto != NULL && idTProducto(carritoProductos->producto) == idProducto) {
        TCarritoProductos temp = carritoProductos;
        carritoProductos = carritoProductos->sig;
        liberarTProducto(temp->producto);
        delete temp;
        return;
    }
    TCarritoProductos carritoCopy = carritoProductos;
    while (carritoCopy->sig != NULL) {
        if (idTProducto(carritoCopy->sig->producto) == idProducto) {
            TCarritoProductos temp = carritoCopy->sig;
            carritoCopy->sig = carritoCopy->sig->sig;
            liberarTProducto(temp->producto);
            delete temp;
            return;
        }
        carritoCopy = carritoCopy->sig;
    }
}
