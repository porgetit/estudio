#include <iostream>
#include "../../utilities.h" // Suponiendo que se encuentra en un archivo llamado QueueTools.h

using namespace std;

int main() {
    QueueTools<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    cout << "Tamaño: " << queue.size() << endl; // Debería imprimir "3"

    cout << "Primer elemento: " << queue.firstIn() << endl; // Debería imprimir "10"

    cout << "Último elemento: " << queue.lastIn() << endl; // Debería imprimir "30"

    cout << "Elementos: ";
    for (int elem : queue.return_queue()) {
        cout << elem << " "; // Debería imprimir "10 20 30"
    }
    cout << endl;

    int first = queue.pop();
    cout << "Primer elemento desencolado: " << first << endl; // Debería imprimir "10"

    cout << "Elemetos: ";
    for (int elem : queue.return_queue()) {
        cout << elem << " "; // Debería imprimir "20 30"
    }
    cout << endl;

    queue.clear();

    cout << "Tamaño después de limpiar: " << queue.size() << endl; // Debería imprimir "0"

    return 0;
}

