
typedef nodolista * Lista;
struct nodoLista { int persona; Lista sig; };

int masVotada(Lista & l, int m){
    int* votos =  new int[m];

    for (int i = 0; i <= m; i++){
        votos[i] = 0;
    }

    while (l != NULL)
    {
        Lista a_borrar = l;
        votos[l->persona]++;
        l = l->sig;
        delete a_borrar;
    }
    int max = 0;
    for (int i = 0; i <= m; i++){
        if (votos[i] > max){
            max = votos[i];
        } 
    }
    delete[] votos;
  
    return max;
}


typedef nodoABB * ABB
struct nodoABB { int dato; ABB izq; ABB der;}
int delMin(ABB & t){

    if(t ==nullptr){
        return;
    }
    if (t->izq == nullptr){
        int n =  t->dato;
        ABB a_borrar = t;
        t = t->der;
        delete a_borrar;
        return n;
    }
    delMin(t->izq);
}
// el peor caso es O(n) ya que tenemos que recurrir a todos los nodos y  sobre casa nodo la velcoidad es O(1)
// el caso promedio es O(log(n)) ya que la altura promedio de un arvobe es log2(n) y sobre cada nodo es O(1)


typedef nodoAG * AG
struct nodoAG { int dato; AG pH; AG sH;}

int nivel(AG t, int x){
    if (t == nullptr){
        return 0;
    }
    if (t.dato == x){
        return 1;
    }
    int res = nivel(t->ph, x);
    if (res > 0){
        return res + 1;
    }
    return nivel(t.sh, x)
}