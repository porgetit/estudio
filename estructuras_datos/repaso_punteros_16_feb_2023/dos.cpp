#include <stdio.h>

int cuboPorValor ( int n );

int main() {

    int numero = 5;

    printf("El valor original de numero es %d", numero);
    numero = cuboPorValor(numero);
    printf("\nE1 nuevo valor de numero es %d\n", numero);
    return 0;
}

int cuboPorValor (int n)
{
    return n * n * n;
}

