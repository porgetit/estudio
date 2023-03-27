/*
Crea un programa que pida al usuario un número entero n y luego cree un arreglo dinámico de enteros de tamaño n utilizando malloc. Luego, pide al usuario que ingrese los valores para cada elemento del arreglo y muestra el contenido del arreglo en la consola.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    // Pedimos el tamaño del arreglos por teclado y asignamos el espacio requerido
    int cantidad, *numeros;

    cout << "Ingrese la cantidad de enteros a registrar: ";
    cin >> cantidad;

    numeros = (int*) malloc(cantidad * sizeof(int));

    // Verificamos el puntero y, si procede, pedimos y mostramos los datos
    if (numeros == NULL) {
        cout << "Error: No se asignó la memoria solicitada." << endl;
        exit(1);
    }else{
        cout << "Ingrese los valores para los datos:" << endl;

        for (int index = 0; index < cantidad; index++) {
            cout << "\tDato [" << index + 1 << "]: ";
            cin >> *(numeros + index);
        }

        cout << endl;

        cout << "[ ";
        for (int index = 0; index < cantidad; index++) {
            cout << *(numeros + index) << " ";
        }
        cout << "]" << endl;
    }

    // liberamos la memoria
    free(numeros);

    return 0;
}