#include <stdio.h>

/* prototipo de la función */
void cuboPorReferencia(int *ptrN);

int main() {
    int numero = 5; /* inicializa numero */
    printf("El valor original de numero es %d", numero);
    /* pasa la dirección de numero a cuboPorReferencia */
    cuboPorReferencia(&numero);
    printf("\nEl nuevo valor de numero es %d\n", numero);
    return 0; /* indica terminación exitosa */
} /* fin de main */

/* calcula el cubo de *ptrN; modifica la variable numero en main */
void cuboPorReferencia(int *ptrN) {
    *ptrN = *ptrN * *ptrN * *ptrN; /* cubo de *ptrN */
} /* fin de la función cuboPorReferencia */

