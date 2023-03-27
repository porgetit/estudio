/*
Reserva de memoria para un array de enteros: Escribe un programa que solicite al usuario la longitud de un array de enteros y reserve memoria dinámicamente para él utilizando malloc(). Luego, permite al usuario ingresar los valores de cada elemento del array y muestra el resultado en la pantalla.
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int longitud, *arreglo;

    // Pedir longitud y separar memoria
    cout << "Ingrese la cantidad de números: ";
    cin >> longitud; fflush(stdin);

    arreglo = (int*) malloc(longitud * sizeof(int));

    if (arreglo == NULL) {
        cout << "Error: memoria insuficiente." << endl;
        exit(1);
    }

    // Pedir los datos
    for (int index = 0; index < longitud; index++) {
        cout << "Ingrese el dato [" << index +1 << "]: ";
        cin >> arreglo[index]; fflush(stdin);
    }

    // Mostrar los datos
    for (int index = 0; index < longitud; index++) {
        cout << arreglo[index] << " ";
    }
    cout << endl;

    // Limpiar la memoria
    free(arreglo);
}
