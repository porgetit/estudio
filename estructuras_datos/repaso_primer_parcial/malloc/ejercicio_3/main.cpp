/*
Crea un programa que lea una matriz de enteros m x n desde el usuario utilizando malloc para asignar memoria dinámicamente. Luego, calcula la suma de todos los elementos de la matriz y muestra el resultado en la consola.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int filas, columnas, **matriz;

    // Pedimos al usuario la cantidad de filas y de columnas
    cout << "Ingrese la cantidad de filas: ";
    cin >> filas; fflush(stdin);

    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas; fflush(stdin);

    // Separamos los espacios en memoria y verificamos la nulidad de los mismos
    matriz = (int**) malloc(filas * sizeof(int*));

    if (matriz == NULL) {
        cout << "Error: Memoria insuficiente." << endl;
        exit(1);
    }

    for (int index = 0; index < filas; index++) {
        matriz[index] = (int*) malloc(columnas * sizeof(int));

        if (matriz[index] == NULL) {
            cout << "Error: Memoria insuficiente." << endl;
            exit(1);
        }
    }


    // Llenamos la matriz fila por fila
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++) {
            cout << "Indice (" << fila +1 << "," << columna +1 << "): ";
            cin >> matriz[fila][columna]; fflush(stdin);
        }
    }

    cout << endl;

    // Mostramos la matriz
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            cout << matriz[fila][columna] << " ";
        }
        cout << endl;
    }

    // Liberamos el espacio en memoria
    for (int index = 0; index < filas; index++) {
        free(matriz[index]);
    }

    free(matriz);

    return 0;
}
