#include "../include/grupo.h"

struct rep_grupo
{
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TPersona personas[MAX_PERSONAS];
    int tope;
    /****** Fin de parte Parte 5.1 *****/
};

TGrupo crearTGrupo()
{
    TGrupo grupo = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    grupo = new rep_grupo;
    (*grupo).tope = 0;
    /****** Fin de parte Parte 5.2 *****/
    return grupo;
}

// Función para agregar una persona a un grupo
// Recibe un elemento de tipo TGrupo y un elemento de tipo TPersona y lo agrega al grupo en orden por fecha de nacimiento (de menor a mayor)
// Si dos personas tienen la misma fecha de nacimiento, deben ordenarse por orden de ingreso al grupo, de más nuevo a más antiguo
// Si la cantidad de personas en el grupo es igual a MAX_PERSONAS, la función no tiene efecto
void agregarAGrupo(TGrupo &grupo, TPersona persona)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if ((*grupo).tope == MAX_PERSONAS)
    {
        return;
    }
    int i = 0;
    while (i < (*grupo).tope && !esMasJoven((*grupo).personas[i], persona))
    {
        i++;
    }
    for (int j = (*grupo).tope; i < j; j--)
    {
        (*grupo).personas[j] = (*grupo).personas[j - 1];
    }
    (*grupo).tope = (*grupo).tope + 1;
    (*grupo).personas[i] = persona;

    /****** Fin de parte Parte 5.2 *****/
}

// Función para imprimir todas las personas de un grupo
// Recibe un elemento de tipo TGrupo e imprime sus personas en orden cronológico
// El formato en el que se debe imprimir el grupo es utilizando de forma secuencial la función imprimirTPersona
// Si el grupo está vacío no imprime nada
void imprimirTGrupo(TGrupo grupo)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if ((*grupo).tope != 0)
    {

        for (int i = 0; i < (*grupo).tope; i++)
        {
            imprimirTPersona((*grupo).personas[i]);
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

// Función para liberar un grupo
// Recibe una referencia a un elemento de tipo TGrupo y libera su memoria
// Libera además la memoria de cada una de las personas en el grupo
void liberarTGrupo(TGrupo &grupo)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if ((*grupo).tope != 0)
    {
        for (int i = 0; i < (*grupo).tope; i++)
        {
            liberarTPersona((*grupo).personas[i]);
        }
    }
    delete grupo;
    grupo = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

// Función para verificar si un elemento de tipo TPersona existe en un grupo
// Recibe un grupo y la cédula de la persona y regresa un booleano indicando su existencia
bool estaEnGrupo(TGrupo grupo, int cedula)
{
    bool esta = false;
    /************ Parte 5.3 ************/
    /*Escriba el código a continuación */
    int i = 0;
    while (i < (*grupo).tope && cedulaTPersona((*grupo).personas[i]) != cedula)
    {
        i++;
    }
    esta = i < (*grupo).tope;
    /****** Fin de parte Parte 5.3 *****/
    return esta;
}

// Esta función remueve la persona con ci "cedula" del grupo "grupo"
void removerDeGrupo(TGrupo &grupo, int cedula)
{
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    int i = 0;
    while (i < (*grupo).tope && cedulaTPersona((*grupo).personas[i]) != cedula)
    {
        i++;
    }
    liberarTPersona((*grupo).personas[i]);
    for (int j = i; j < (*grupo).tope; j++)
    {
        (*grupo).personas[j] = (*grupo).personas[j + 1];
    }
    (*grupo).tope = (*grupo).tope - 1;
    /****** Fin de parte Parte 5.4 *****/
}

// Función para verificar si hay, al menos, una persona en el grupo que tenga la fecha de nacimiento "fecha"
// Debe implementarse utilizando búsqueda binaria
bool hayPersonasFecha(TGrupo grupo, TFecha fecha)
{
    bool hay = false;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    int min = 0;
    int max = (*grupo).tope - 1;
    int medio = 0;
    hay = compararTFechas(fechaNacimientoTPersona((*grupo).personas[medio]), fecha) == 0;
    while (min <= max && !hay)
    {
        int medio = (min + max) / 2;
        int posicion = compararTFechas(fechaNacimientoTPersona((*grupo).personas[medio]), fecha);
        if (posicion == -1)
        {
            min = medio + 1;
        }
        else if (posicion == 1)
        {
            max = medio - 1;
        }
        hay = posicion == 0;
    }
    /****** Fin de parte Parte 5.5 *****/
    return hay;
}

// Imprime en pantalla las personas del grupo que tengan la fecha de nacimiento "fecha"
void imprimirPersonasFecha(TGrupo grupo, TFecha fecha)
{
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    for (int i = (*grupo).tope-1; i >=0; i--)
    {
        if (compararTFechas(fechaNacimientoTPersona((*grupo).personas[i]), fecha) == 0)
        {
            imprimirTPersona((*grupo).personas[i]);
        }
    }
    /****** Fin de parte Parte 5.5 *****/
}
