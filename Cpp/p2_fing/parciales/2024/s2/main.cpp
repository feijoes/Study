struct repCP{
    NodoLista * lista;
    NodoLista * prioritario;
};
typedef repCP * CP;
struct NodoLista{
    unsigned int prioridad;
    NodoLista * sig;
    T dato;
};

CP crear(){
    CP nuevo = new repCP;
    nuevo->lista = NULL;
    nuevo->prioritario = NULL;
}
void agregar(T x, unsigned int p, CP &cp ){
    CP copia = cp;
    NodoLista* nuevo_nodo =  new NodoLista;
    nuevo_nodo.dato = x;
    while (copia->lista != NULL || copia->prioritario > p){
        copia->lista = copia->lista->sig;
    }
    if (copia->lista == NULL){
        cp->prioritario = nuevo_nodo;
    }
    nuevo_nodo->sig =  copia->lista;
    copia->lista = nuevo_nodo;
}
// Problema 2
struct nodoABB
{
   int dato;
   unsigned int altura;
   nodoABB *izq, *der
};
typedef nodoABB * ABB;

/*    
    if (t->der == nullptr){
        return (t->izq->altura == 1 && v);
    } else if (t->izq == nullptr){
        return (t->der->altura == 1 && v);
    }*/
bool insertar(ABB &t, int x){
    if (t == nullptr){
        ABB nuevo = new nodoABB;
        nuevo->dato = x;
        nuevo->altura = 1;
        nuevo->der= nuevo->izq = nullptr
        return true;
    }
   
    if (t->dato > x){
        bool v = insertart(t->izq, x)
    } else {
        bool v = insertart(t->der, x)
    }
    t->altura = max(altura(t->izq),altura(t->izq))+1;

    return (v && abs(t->der->altura - t->izq->altura) <= 1)
}
struct ColaABB
{
    /* data */
};

void imprimir(ABB t){
    if (t == nullptr) return;
    
    ColaABB cola = crear();
    encolar(t, cola);
    while (!esVacio(cola))
    {
        t = desencolar(cola);
        impInt(t->dato);
        if (t->der != nullptr) encolar(t->der, cola);
        if (t->izq != nullptr) encolar(t->izq, cola);
    }
    
}