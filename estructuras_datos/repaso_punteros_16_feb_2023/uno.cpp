#include <stdio.h>

int main() {
    int a;
    int *ptrA;

    a = 7;
    ptrA = &a;

    printf("La dirección de a es %p y el valor de ptrA es %p\n", &a, ptrA);
    printf("El valor de a es %d y el contenido de ptrA es %d\n", a, *ptrA);
    printf("\n\nEsto es una muestra de que * y & son complementos uno del otro y \n&ptrA es igual a %p y \n&ptrA es igual a %p\n", &ptrA, *&ptrA);

    return 0;
}