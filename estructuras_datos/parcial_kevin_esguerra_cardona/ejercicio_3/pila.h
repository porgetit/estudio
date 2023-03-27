/* archivo pilaarray.h */
#include <stdio.h>
#include <stdlib.h>
#define TAMPILA 100

typedef char TipoDato; /* Tipo de los elementos de la pila */

typedef struct
{
    TipoDato listaPila[TAMPILA];
    int cima;
} Pila;

/* Operaciones sobre la pila */
void crearPila (Pila* pila);
void insertar (Pila* pila, TipoDato elemento);
TipoDato quitar (Pila* pila);
void limpiarPila (Pila* pila);

/* Operación de acceso a pila */
TipoDato cima (Pila pila);

/* Verificación estado de la pila */
int pilaVacia (Pila pila);
int pilaLlena (Pila pila);
