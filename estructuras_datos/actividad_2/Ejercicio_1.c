// Punto 1. Busqueda binaria con ordenamiento de inserción.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

void printArray(int *, int);
void mergeSort(int *, int, int);
int binarySearch(int *, int, int);

int main() {
    int data[TAM];  // Arreglo de enteros a ser ordenado y buscado
    int i, dato;    // Variables auxiliares para el ciclo y el dato a buscar
    srand(time(NULL));
    for (i = 0; i < TAM; i++)
        data[i] = (int)(rand() % TAM);  // Se inicializa el arreglo con valores aleatorios

    printf("\nAntes de ordenar------------------------------------\n");
    printArray(data, TAM);  // Se imprime el arreglo antes de ordenarlo
    printf("\nDespues de ordenar----------------------------------\n");
    mergeSort(data, 0, TAM-1);  // Se ordena el arreglo utilizando el algoritmo de merge sort
    printArray(data, TAM);  // Se imprime el arreglo después de ordenarlo

    // Generamos el dato mediante un random de 0 hasta 99
    dato = (int)(rand() % TAM);  // Se genera un dato aleatorio para buscar en el arreglo
    data[i] = dato;  // Se agrega el dato al final del arreglo
    printf("Dato a buscar %d\n", dato);

    int result = binarySearch(data, TAM, dato);  // Se realiza la búsqueda binaria del dato
    if (result != -1)
        printf("Posicion %d\n", ++result);  // Si se encuentra el dato, se imprime su posición en el arreglo
    else
        printf("Elemento no esta en el array");  // Si no se encuentra el dato, se imprime un mensaje indicándolo

    return 0;
}

void printArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("[%d]:%d ", i, arr[i]);  // Función auxiliar para imprimir un arreglo de enteros
    }
    printf("\n");
}

/* Función auxiliar para el algoritmo de mergeSort */
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* Función principal para ordenar un arreglo utilizando el algoritmo de mergeSort */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int binarySearch(int *arr, int len, int dato) {
    int ini = 0, fin = len - 1, mitad;
    mitad = (ini + fin) / 2;
    while ((ini <= fin) && (arr[mitad] != dato)) {
        if (dato < arr[mitad])
            fin = mitad - 1;
        else
            ini = mitad + 1;
        mitad = (ini + fin) / 2;
    }
    if (dato == arr[mitad])
        return mitad;
    else
        return -1;
}
