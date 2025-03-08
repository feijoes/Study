
#include <assert.h>
#include <ctype.h>  // toupper
#include <math.h>   // sqrt
#include <stdio.h>  // scanf, printf
#include <string.h> // strcmp

#define MAX_PALABRA 32
#define MAX_LINEA 100

#define N 10000 // para la función primos

// Tipos de datos y declaraciones de funciones.
// Podrían estar en archivos .h que deberían incluirse mediante #include

// Tipos de datos para puntos
typedef struct rep_punto {
  int coordX, coordY;
} Punto;

typedef struct rep_colPuntos {
  int capacidad, cantidad;
  Punto * arregloPuntos;
} ColPuntos;

// Declaraciones de las funciones

/*
 precondición: 0 <= calN <= 10 para N en 1..N
*/
float promClase(int cal1, int cal2, int cal3, int cal4, int cal5);
void primos(int A, int B);
int ocurrencias(char frase[100], int largo, char letra);
bool esPalindrome(char *frase);
void insertarPunto(ColPuntos & colPtos, Punto pto); 
int * ordenar(int * A, int n);


// Programa principal. Intérprete de comandos
// 

int main() {
  char resto_linea[MAX_LINEA+1];

  ColPuntos colPtos;
  const int maxPuntos = 8;
  colPtos.arregloPuntos = new Punto[maxPuntos];
  colPtos.cantidad = 0;
  colPtos.capacidad = maxPuntos;
  
  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    // mostrar el prompt
    cont_comandos++;
    printf("%u>", cont_comandos);

    // leer el comando
    char nom_comando[MAX_PALABRA];
    scanf("%s", nom_comando);

    // procesar el comando
    if (0 == strcmp(nom_comando, "Fin")) {
      salir = true;
      printf("Fin.\n");
      // comentario
    } else if (0 == strcmp(nom_comando, "#")) {
      scanf("%[^\n]", resto_linea);
      printf("# %s.\n", resto_linea);

      //------------- Inicio comandos

    } else if (0 == strcmp(nom_comando, "promClase")) {

      float prom;
      int cal1, cal2, cal3, cal4, cal5;
      fprintf(stderr, "Ingrese las calificaciones: \n");
      scanf("%d %d %d %d %d", &cal1, &cal2, &cal3, &cal4, &cal5);
      assert((0 <= cal1) && (cal1 <= 10) && (0 <= cal2) && (cal2 <= 10) &&
             (0 <= cal3) && (cal3 <= 10) && (0 <= cal4) && (cal4 <= 10) &&
             (0 <= cal5) && (cal5 <= 10));
      prom = promClase(cal1, cal2, cal3, cal4, cal5);
      printf("El promedio es %.2f.\n", prom);

    } else if (0 == strcmp(nom_comando, "primos")) {

      fprintf(stderr,"Ingrese dos enteros positivos, el segundo mayor o igual que el primero: \n");
      int A, B;
      scanf("%d %d", &A, &B);
      assert(A <= B);
      primos(A, B);

    } else if (0 == strcmp(nom_comando, "ocurrencias")) {

      char frase[101];
      char letra;

      fprintf(stderr,"Ingrese una letra: \n");
      scanf(" %c", &letra);

      fprintf(stderr, "Ingrese frase de hasta 100 caracteres: \n");
      scanf("%*c");
      scanf("%[^\n]s", frase);
      
      printf("La cantidad de ocurrencias de %c en '%s' es %d.\n", letra, frase,
             ocurrencias(frase, strlen(frase), letra));

    } else if (0 == strcmp(nom_comando, "esPalindrome")) {

      char *frase = new char[101];

      fprintf(stderr, "Ingrese frase de hasta 100 caracteres: \n");
      scanf("%*c");
      scanf("%[^\n]s", frase);
      
      if (esPalindrome(frase))
        printf("La frase %s es Palindrome.\n", frase);
      else
        printf("La frase %s NO es Palindrome.\n", frase);

      delete[] frase;

    } else if (0 == strcmp(nom_comando, "insertarPunto")) {
      fprintf(stderr, "Ingrese las dos coordenadas: \n");
      Punto pto;
      scanf("%d %d", &pto.coordX, &pto.coordY);

      insertarPunto(colPtos, pto);

      for (int i = 0; i < colPtos.cantidad; i++)
	printf("(%d,%d) ", colPtos.arregloPuntos[i].coordX, colPtos.arregloPuntos[i].coordY);
      printf("\n");

    } else if (0 == strcmp(nom_comando, "ordenar")) {
      int A[10];
      fprintf(stderr, "Ingrese 10 enteros: \n");
      for (int i = 0; i < 10; i++)
        scanf("%d",&A[i]);
      int * B = ordenar(A,10);
      for (int i = 0; i < 10; i++)
        printf("%d ", B[i]);
      printf("\n");

      //------------- Fin comandos

    } else {
      printf("Comando no reconocido.\n");
    } // if
    fgets(resto_linea, MAX_LINEA + 1, stdin);
  } // while

  return 0;
}

int minCal(int cal1, int cal2, int cal3, int cal4, int cal5) {
  int min = cal1;

  if (cal2 < min)
    min = cal2;
  if (cal3 < min)
    min = cal3;
  if (cal4 < min)
    min = cal4;
  if (cal5 < min)
    min = cal5;

  return min;
}

float promClase(int cal1, int cal2, int cal3, int cal4, int cal5) {
  int suma = cal1 + cal2 + cal3 + cal4 + cal5;
  int minimo = minCal(cal1, cal2, cal3, cal4, cal5);
  return (suma - minimo) / 4.0;
}


void primos(int A, int B) {
  bool es_primo[N + 1];
  for (int i = 2; i <= B; i++)
    es_primo[i] = true;

  int raiz = sqrt(B);

  for (int p = 2; p <= raiz; p++)
    if (es_primo[p])
      for (int i = p; i * p <= B; i++)
        es_primo[i * p] = false;

  for (int i = A; i <= B; i++)
    if (es_primo[i])
      printf("%d ", i);

  printf("\n");
}

int ocurrencias(char frase[100], int largo, char letra) {
  int cant = 0;
  char ucLetra = toupper(letra);

  for (int i = 0; i < largo; i++)
    if (toupper(frase[i]) == ucLetra)
      cant++;

  return cant;
}


bool esPalindrome(char *frase) {
  int largo = (unsigned)strlen(frase);
  int i;
  for (i = 0; (i < largo / 2) && frase[i] == frase[largo - 1 - i]; i++);
  return i >= largo / 2;
}

void insertarPunto(ColPuntos & colPtos, Punto pto) {
  if (colPtos.cantidad < colPtos.capacidad) {
    int i = colPtos.cantidad;
    while ((i > 0)  &&
	   ((pto.coordX < colPtos.arregloPuntos[i-1].coordX) || ((pto.coordX == colPtos.arregloPuntos[i-1].coordX) && (pto.coordY < colPtos.arregloPuntos[i-1].coordY)))
	   ) {
      colPtos.arregloPuntos[i] = colPtos.arregloPuntos[i-1];
      i--;
    }
    colPtos.arregloPuntos[i] = pto;
    colPtos.cantidad++;
  }
}



int * ordenar(int * A, int n) {
  int * B = new int[n];
  for (int i = 0; i < n; i++)
    B[i] = A[i];
  
  for (int i = 1; i < n; i++) {
    int pos = i - 1;
    int insertando = B[i];
    while ((pos >= 0) && (B[pos] > insertando)) {
      B[pos + 1] = B[pos];
      pos--;
    }
    B[pos+1] = insertando;
  }
  return B;
}

