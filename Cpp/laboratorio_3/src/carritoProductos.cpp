#include "../include/carritoProductos.h"

struct rep_carritoProductos
{
    TCarritoProductos sig;
    TProducto producto;
};

TCarritoProductos crearCarritoProductosVacio()
{
    return NULL;
}

void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto)
{
    int idProducto = idTProducto(producto);
    TCarritoProductos nuevo = new rep_carritoProductos;
    nuevo->producto = producto;
    if (carritoProductos == NULL || idTProducto(carritoProductos->producto) > idProducto)
    {
        nuevo->sig = carritoProductos;
        carritoProductos = nuevo;
    }
    else
    {
        TCarritoProductos aux = carritoProductos;
        while (aux->sig != NULL && idTProducto(aux->sig->producto) < idProducto)
        {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

void imprimirCarritoProductos(TCarritoProductos carritoProductos)
{
    TCarritoProductos aux = carritoProductos;
    while (aux != NULL)
    {
        imprimirTProducto(aux->producto);
        aux = aux->sig;
    }
}

void liberarCarritoProductos(TCarritoProductos &carritoProductos)
{
    TCarritoProductos aux;
    while (carritoProductos != NULL)
    {
        aux = carritoProductos;
        carritoProductos = carritoProductos->sig;
        liberarTProducto(aux->producto);
        delete aux;
    }
}

bool esVacioCarritoProductos(TCarritoProductos carritoProductos)
{
    return carritoProductos == NULL;
}

bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto)
{
    TCarritoProductos aux = carritoProductos;
    while (aux != NULL && idTProducto(aux->producto) != idProducto)
    {
        aux = aux->sig;
    }
    return aux != NULL;
}

TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto)
{
    TProducto res = NULL;
    TCarritoProductos iter = carritoProductos;
    while (iter != NULL && !res) {
        if (idProducto == idTProducto(iter->producto)) {
            res = iter->producto;
        }
        iter = iter->sig;
    }
    return res;

}

void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto)
{
    if (carritoProductos != NULL){
        if (idTProducto(carritoProductos->producto) == idProducto){
            TCarritoProductos aBorrar = carritoProductos;
            carritoProductos = carritoProductos->sig;
            liberarTProducto(aBorrar->producto);
            delete aBorrar;
        }else{
            TCarritoProductos iter = carritoProductos;
            while (iter->sig != NULL && idTProducto(iter->sig->producto) != idProducto){
                iter = iter->sig;
            }
            if (iter->sig != NULL){
                TCarritoProductos aBorrar = iter->sig;
                liberarTProducto(aBorrar->producto);
                iter->sig = aBorrar->sig;
                delete aBorrar;
            }
        }
    }

}
