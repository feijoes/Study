#include "../include/colaEnvios.h"

struct rep_cola_envios
{
    TEnvio *envios;
    int tope;
    int max;
    bool is_inv;
};

TEnvio *CrearArrayTEnvio(int N) { 
    TEnvio *envios = new TEnvio[N + 1];
    for (int i = 0; i <= N; i++)
    {
        envios[i] = NULL;
    }
    return envios;
}
TColaEnvios crearTColaEnvios(int N)
{
    TColaEnvios colaEnvios = new rep_cola_envios;
    colaEnvios->envios = CrearArrayTEnvio(N);
    colaEnvios->tope = 0;
    colaEnvios->max = N;
    colaEnvios->is_inv = false;
    return colaEnvios;
}

int calcular_nivel(int tope)
{
    if (tope < 1)
        return 0;
    int nivel = 0;
    int nodos_en_nivel = 1;
    int total_nodos = 0;
    while (total_nodos + nodos_en_nivel < tope)
    {
        total_nodos += nodos_en_nivel;
        nivel++;
        nodos_en_nivel *= 2;
    }
    return nivel + 1;
}
int primer_indice_nivel(int nivel)
{
    if (nivel < 1)
        return -1;             // Niveles no válidos
    return (1 << (nivel - 1)); // 2^(nivel-1)
}

// verdadero si evio1 tiene mayor prioridad
bool prioridadTColaEnvios(TEnvio envio1, TEnvio envio2, bool is_inv)
{
    if (is_inv)
        return compararTFechas(obtenerFechaTEnvio(envio1), obtenerFechaTEnvio(envio2)) == 1;
    return compararTFechas(obtenerFechaTEnvio(envio1), obtenerFechaTEnvio(envio2)) == -1;
}
void filtradoAscendente(int pos, TColaEnvios &colaEnvios)
{
    while (pos > 1 && prioridadTColaEnvios(colaEnvios->envios[pos / 2], colaEnvios->envios[pos], colaEnvios->is_inv))
    {
        TEnvio aux = colaEnvios->envios[pos / 2];
        colaEnvios->envios[pos / 2] = colaEnvios->envios[pos];
        colaEnvios->envios[pos] = aux;
        pos = pos / 2;
    }
}
/*
 while (1)
    {
        int hijo_izq = 2 * pos;
        int hijo_der = 2 * pos + 1;
        int menor = pos;
        if (hijo_izq < colaEnvios->tope && prioridadTColaEnvios(colaEnvios->envios[hijo_izq], colaEnvios->envios[menor]))
            menor = hijo_izq;
        if (hijo_der < colaEnvios->tope && prioridadTColaEnvios(colaEnvios->envios[hijo_der], colaEnvios->envios[menor]))
            menor = hijo_der;
        if (menor == pos)
            break;
        TEnvio temp = colaEnvios->envios[pos];
        colaEnvios->envios[pos] = colaEnvios->envios[menor];
        colaEnvios->envios[menor] = temp;
        pos = menor;
    }
    */
void filtradoDescendente(int pos, TColaEnvios &colaEnvios)
{

    while (pos < colaEnvios->tope && (pos * 2) < colaEnvios->tope)
    {
        int diff = 0;
        bool prioridad_izq = prioridadTColaEnvios(colaEnvios->envios[pos], colaEnvios->envios[pos * 2], colaEnvios->is_inv);
        bool prioridad_der = prioridadTColaEnvios(colaEnvios->envios[pos], colaEnvios->envios[pos * 2 + 1], colaEnvios->is_inv);
        if (!prioridad_izq && !prioridad_der)
        {
            break;
        }
        if (prioridadTColaEnvios(colaEnvios->envios[pos * 2], colaEnvios->envios[pos * 2 + 1], colaEnvios->is_inv))
        {
            diff = 1;
        }
        TEnvio aux = colaEnvios->envios[pos * 2 + diff];
        colaEnvios->envios[pos * 2 + diff] = colaEnvios->envios[pos];
        colaEnvios->envios[pos] = aux;
        pos = pos * 2;
    }
}

void encolarEnvioTColaEnvios(TColaEnvios &colaEnvios, TEnvio envio)
{
    colaEnvios->tope++;
    colaEnvios->envios[colaEnvios->tope] = envio;
    filtradoAscendente(colaEnvios->tope, colaEnvios);
}

int cantidadTColaEnvios(TColaEnvios colaEnvios) { return colaEnvios->tope; }

void imprimirTColaEnvios(TColaEnvios colaEnvios)
{
    int i = 1;
    printf("\n");
    while (i <= calcular_nivel(colaEnvios->tope))
    {

        printf("Nivel %d\n", i);
        for (int j = primer_indice_nivel(i); j < primer_indice_nivel(i + 1) && j <= colaEnvios->max; j++)
        {
            if (colaEnvios->envios[j] != NULL)
            {
                printf("%d) ", j);
                imprimirTEnvio(colaEnvios->envios[j]);
            }
        }
        printf("\n");
        i += 1;
    }
}
TEnvio desencolarTColaEnvios(TColaEnvios &colaEnvios)
{
    TEnvio aux = colaEnvios->envios[1];
    colaEnvios->envios[1] = colaEnvios->envios[colaEnvios->tope];
    colaEnvios->envios[colaEnvios->tope] = NULL;
    colaEnvios->tope--;
    filtradoDescendente(1, colaEnvios);
    return aux;
}

void liberarTColaEnvios(TColaEnvios &colaEnvios)
{
    for (int i = 1; i <= colaEnvios->tope; i++)
    {
        liberarTEnvio(colaEnvios->envios[i]);
    }
    delete[] colaEnvios->envios;
    delete colaEnvios;
    colaEnvios = NULL;
}

void invertirPrioridadTColaEnvios(TColaEnvios &colaEnvio)
{
    colaEnvio->is_inv = !colaEnvio->is_inv;
    for (int i = 1; i <= colaEnvio->tope; i++)
    {
        filtradoAscendente(i, colaEnvio);
    }
}

TEnvio masPrioritarioTColaEnvios(TColaEnvios colaEnvio) { return colaEnvio->envios[1]; }

int maxTColaEnvios(TColaEnvios colaEnvio) { return colaEnvio->max; }