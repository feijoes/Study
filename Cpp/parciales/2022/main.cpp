typedef nodoLista *Lista;
struct nodoLista
{
    int dato;
    nodoLista *sig;
};

bool sinRepetidos(Lista l, int p)
{
    if (l == nullptr)
    {
        return true;
    }
    bool *esta = new bool[p + 1];
    for (int i = 0; i <= p; i++){
        esta[i] = true;
    }
    while (l != nullptr)
    {
        if (esta[l->dato] == true)
        {
            return false;
        }
        esta[l->dato] = true;
        l = l->sig;
    }
    delete esta;
    return false;
}
typedef struct nodoAB *AB;

struct nodoAB
{
    int dato;
    nodoAB *izq, *der;
};

AB maximo(AB t)
{
    if (t == nullptr)
    {
        return nullptr;
    }
    AB maximo_izq = maximo(t->izq);
    AB maximo_der = maximo(t->der);
    if (maximo_izq == nullptr && maximo_der == nullptr)
    {
        return t;
    }
    AB max = t;
    if (maximo_der != nullptr && t->dato < maximo_der->dato)
    {
        max = maximo_der;
    }
    else if (maximo_izq != nullptr && t->dato < maximo_izq->dato)
    {
        max = maximo_izq;
    }
    return max;
}

typedef struct nodoAG *AG;
struct nodoAG
{
    int dato;
    nodoAG *pH, *sH;
};


void nivelEnLista(AG t, Lista & l, int k){
    if (t == nullptr || k == 0){
        return;
    }
    nivelEnLista(t->sH, l->sig, k);
    if (k > 1){
        return nivelEnLista(t->pH, l, k);
    }
    Lista a_insertar = new Lista;
    a_insertar->dato = t->dato;
    a_insertar->sig = l;
    l = a_insertar;
    return;
}