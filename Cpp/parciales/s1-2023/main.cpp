#include <iostream>
struct NodoLista{
    int dato;
    NodoLista * sig;
    NodoLista * ant;
};

struct cabeza1
{
    NodoLista * inicio;
    NodoLista * final;
};

void insFinal(int x, cabeza1 & l){
    NodoLista * nuevo = new NodoLista;
    nuevo->dato = x;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    if (l->inicio == NULL){
        l->inicio = nuevo;
        l->final = nuevo;
        return;
    }
    l->final->sig = nuevo;
    nuevo->ant = l->final;
    l.final = nuevo;
}
void insInicio(int x, cabeza1 & l){
}

Lista pivote(int x, cabeza1 l){
    cabeza1 nueva_cabeza = new cabeza1;
    nueva_cabeza.inicio = nueva_cabeza.final = NULL;
    insInicio(x, nueva_cabeza)
    NodoLista inicio = l.inicio;
    while ( inicio != NULL)
    {
        if (inicio.dato < x){
            insInicio(inicio.dato, nueva_cabeza);
        } else{
            insFinal(inicio.dato, nueva_cabeza);
        }
        inicio = inicio.sig;
    }
    return nueva_cabeza;
}

struct Lista
{
    int dato;
    Lista * sig;
};

// [1,4,5,8,9] [3,4,5,6]
Lista funcao(Lista l1, Lista l2){
    Lista copyL1 = l1;
    Lista copyL2 = l2;
    Lista interseccion = new Lista;
    interseccion.sig = NULL;

    while (copyL1 != NULL && copyL2 != NULL){
        if (copyL1.dato == copyL2.dato ){
            Lista nuevo = new Lista;
            nuevo.sig = interseccion;
            nuevo.dato = copyL1.dato;
            interseccion = nuevo;
        } else if (copyL1.dato > copyL2.dato){
            copyL2 = copyL2.sig;
        } else {
            copyL1 = copyL1.sig;
        }
    }
    return interseccion;
}
