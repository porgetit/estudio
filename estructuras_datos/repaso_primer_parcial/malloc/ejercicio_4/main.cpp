/*
Crea un programa que pida al usuario un número entero n y luego cree un arreglo dinámico de enteros de tamaño n utilizando malloc. Luego, ordena los elementos del arreglo en orden ascendente utilizando el algoritmo de ordenamiento de burbuja y muestra el arreglo ordenado en la consola.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int*, int);

int main() {
    srand(time(NULL));

    int cantidad, *numeros;

    // Pedimos la cantidad de numeros
    cout << "Ingrese la cantidad de numeros: ";
    cin >> cantidad; fflush(stdin);

    // Reservamos el espacio en memoria
    numeros = (int*)malloc(cantidad * sizeof(int));

    if (numeros == NULL) {
        cout << "Error: Memoria insuficiente." << endl;
        exit(1);
    }

    // Llenamos y mostramos el arreglo
    for (int index = 0; index < cantidad; index++) {
        numeros[index] = (rand() + 0) % 100;
    }

    for (int index = 0; index < cantidad; index++) {
        cout << *(numeros + index) << " ";
    }
    cout << endl;

    // Ordenamos y mostramos el arreglo
    bubbleSort(numeros, cantidad);

    for (int index = 0; index < cantidad; index++) {
        cout << *(numeros + index) << " ";
    }

    // Limpiamos el espacio en memoria
    free(numeros);

    return 0;
}

void bubbleSort(int *input, int len) {
    for (int i = 0; i < len -1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (input[j] > input[j+1]) {
                // Intercambiar elementos
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}

