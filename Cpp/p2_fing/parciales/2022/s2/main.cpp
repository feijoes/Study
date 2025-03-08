// 1) A)
struct NodoLista{
    int dato;
    NodoLista * sig;
}
struct representacionStock{
    int cant;
    int max;
    NodoLista **tabla;
};

typedef representacionStock * Stock;

Stock crear(int cantidadEsperado){
    Stock nuevo = new representacionStock;
    nuevo->cant = 0;
    nuevo->max = cantidadEsperado;
    nuevo->tabla = new NodoLista*[cantidadEsperado];
    return nuevo;
}
void insertar(Stock &s, int x){
    int posicion = x % s->max;
    NodoLista *nuevo = new NodoLista;
    nuevo->dato = x;
    nuevo->sig = s->tabla[posicion];
    s->tabla[posicion] = nuevo;
    s->cant++;
}

// 1) B)
struct NodoAVL
{   
    int dato;
    NodoABB *izq, *der;
};

struct representacionStock{
    int cant;
    int max;
    NodoABB * abb;
};

typedef representacionStock * Stock;

// 2) 
Pila mayoresQueLosAnteriores(Pila & p){

}

