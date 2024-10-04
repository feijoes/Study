/* 1234567 */
/*
  Módulo de implementación de 'utils'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"

nat leerNat() {
    nat res;
    scanf("%u", &res);
    return res;
}

int leerInt(){
    int res;
    scanf("%d", &res);
    return res;
}

char leerChar() {
    char res;
    scanf(" %c", &res);
    return res;
}

double leerDouble() {
    double res;
    scanf("%lf", &res);
    return res;
}

void leerChars(char* cs) { scanf("%s", cs); }

void leerRestoLinea(char* cs) { scanf("%[^\n]", cs); }

void consumirRestoLinea() {
    int ch = getchar(); // Read the next character
    if (ch != EOF && (isspace(ch) || ch == '\n')) {
        // consumimos caracter si es espacio o salto de linea
    } else if (ch != EOF) {
        // si no, lo volvemos a guardar en la entrada
        ungetc(ch, stdin);
    }
}
