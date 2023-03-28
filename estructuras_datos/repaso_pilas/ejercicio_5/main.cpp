/*
Pila de enteros: Implemente una pila de enteros, y muestre su sumatoria. Utilice la librería ../pilas/pilas.h
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pilas.h"

using namespace std;

int main() {
    Stack integers;
    integers.top = NULL;
    int amount_integers, total = 0; // Hubo que inicializar la variable total en 0 al momento de la definición. Aún no sé porqué.
    srand(time(NULL));

    // Pedimos la cantidad de enteros y empilamos
    cout << "Ingrese la cantidad de enteros deseada: ";
    cin >> amount_integers; fflush(stdin);

    for (int i = 0; i < amount_integers; i++) {
        DataType atom = (DataType) (rand() +0) % 10;
        push(&integers, atom);
    }

    cout << "La pila tiene " << size(&integers) << " nodos" << endl;

    // Desempilamos y sumamos
    cout << "[ ";
    while(!empty(&integers)) {
        int atom = (int) pop(&integers);
        total += atom;
        cout << atom << " ";
    }
    cout << "] = " << total;

    cout << "\nLa pila tiene " << size(&integers) << " nodos" << endl;

    return 0;
}