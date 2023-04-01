/*
Implementar una cola con nodos enlazados: Crea una cola utilizando nodos enlazados. Los nodos deben tener dos campos: uno para el valor y otro para el siguiente nodo en la cola. La cola debe tener los métodos enqueue y dequeue, al igual que en el ejercicio anterior.
*/

#include <iostream>
#include "./colas/colas.h"

using namespace std;

int main() {

    // Definimos e inicializamos la cola
    Queue* miCola = new Queue;
    miCola->front = NULL;
    miCola->back = NULL;

    // Insertamos los elemntos en la cola / Encolamos
    for (int i = 1; i <= 10; i++) {
        push(miCola, i);
    }

    // Desencolamos
    int i = 1;
    while (!empty(miCola)) {
        DataType elementoEliminado = pop(miCola);
        cout << "OUT: [" << i++ << "]: " << elementoEliminado << endl;
    }
}