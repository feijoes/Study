typedef nodoABB *ABB;
struct nodoABB
{
    int dato;
    nodoABB *izq, *der;
};

typedef nodoLista *Lista;
struct nodoLista
{
    int dato;
    nodoLista *sig;
};

void rangoEnLista(ABB t, int inf, int sup, Lista &l)
{
    if (t == nullptr)
    {
        return;
    }
    if (t->dato <= sup)
    {
        rangoEnLista(t->der, inf, sup, l);
    }
    Lista a_insertar = new Lista;
    a_insertar->dato = t->dato;
    a_insertar->sig = l;
    l = a_insertar;
    if (t->dato >= inf)
    {
        rangoEnLista(t->izq, inf, sup, l);
    }
}
typedef struct nodoAG *AG;

struct nodoAG
{
    int dato;
    nodoAG *pH, *sH;
};

int cantidadH(AG t)
{
    if (t == nullptr)
    {
        return 0;
    }
    return 1 + cantidadH(t->pH);
}
bool nArio(AG t, int n)
{
    if (t == nullptr)
    {
        return true;
    }
    return cantidadH(t) <= n && nArio(t->pH, n) && nArio(t->sH, n);
}
