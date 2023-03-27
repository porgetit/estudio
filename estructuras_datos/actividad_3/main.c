// n-esimo termino de la sucesion de Fibonacci.
/*
Escrito, correjido y presentado por: 
    Sofía Jaramillo,
    Daniel Rico,
    Kevin Esguerra.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SUP_LIMIT 10

int recursively_fibonacci(int);
int iteration_fibonacci(int);
int function_fibonacci(int);

int main(){
    int n_term;
    srand(time(NULL));
    n_term = (int)(rand() % SUP_LIMIT);

    printf("Objetivo: %d\n", n_term);

    printf("Recursividad: %d\n", recursively_fibonacci(n_term));
    printf("Iteracion: %d\n", iteration_fibonacci(n_term));
    printf("Funcion: %d\n", function_fibonacci(n_term));
}

int recursively_fibonacci(int n){
    if (n == 0 || n == 1) {
        return n;
    } else {
        return recursively_fibonacci(n-1) + recursively_fibonacci(n-2);
    }
}

int iteration_fibonacci(int n){
    int t1 = 0, t2 = 1, siguiente;
    if (n == 0)
        return t1;
    if (n == 1)
        return t2;
    for (int i = 2; i <= n; i++) {
        siguiente = t1 + t2;
        t1 = t2;
        t2 = siguiente;
    }
    return siguiente;
}

int function_fibonacci(int n){
    double phi = (1 + sqrt(5)) / 2;
    return round((pow(phi, n) - pow(1 - phi, n)) / sqrt(5));
}