#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../utilities.h"

#define MAX 11


using namespace std;

int main() {
    srand(time(nullptr));

    // Crear una cola de enteros
    QueueTools<int> myQueue;

    // Agregar elementos a la cola
    for (int i = 0; i < 5; i++) {
        myQueue.push(rand() % MAX);
    }

    // Imprimir la cola
    cout << "La cola es: ";
    for (auto i : myQueue.return_queue()) {
        cout << i << " ";
    }
    cout << endl;

    // Obtener el primer y último elemento de la cola
    cout << "El primer elemento es: " << myQueue.firstIn() << endl;
    cout << "El último elemento es: " << myQueue.lastIn() << endl;

    // Sacar elementos de la cola
    int elem1 = myQueue.pop();
    int elem2 = myQueue.pop();

    // Imprimir la cola después de sacar elementos
    cout << "La cola después de sacar elementos es: ";
    for (auto i : myQueue.return_queue()) {
        cout << i << " ";
    }
    cout << endl;

    // Agregar más elementos a la cola
    for (int i = 0; i < 2; i++) {
        myQueue.push(rand() % MAX);
    }

    // Imprimir la cola nuevamente
    cout << "La cola ahora es: ";
    for (auto i : myQueue.return_queue()) {
        cout << i << " ";
    }
    cout << endl;

    // Obtener el tamaño de la cola
    cout << "El tamaño de la cola es: " << myQueue.size() << endl;

    return 0;
}
