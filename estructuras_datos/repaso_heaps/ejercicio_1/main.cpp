#include <iostream>
#include <vector>
#include "../lib/heap.h"

using namespace std;

int main() {
    MaxHeap<int> heap;

    // Insertar elementos en el montículo
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(3);
    heap.insert(8);

    // Recorrido en anchura (BFS)
    vector<int> bfsResult = heap.breadthFirstTraversal();
    cout << "Recorrido en anchura (BFS): ";
    for (int value : bfsResult) {
        cout << value << " ";
    }
    cout << endl;

    // Recorrido en inorden
    vector<int> inorderResult = heap.inorderTraversal();
    cout << "Recorrido en inorden: ";
    for (int value : inorderResult) {
        cout << value << " ";
    }
    cout << endl;

    // Recorrido en preorden
    vector<int> preorderResult = heap.preorderTraversal();
    cout << "Recorrido en preorden: ";
    for (int value : preorderResult) {
        cout << value << " ";
    }
    cout << endl;

    // Eliminar el elemento raíz del montículo
    heap.remove();

    // Comprobar si el montículo está vacío
    if (heap.empty()) {
        cout << "El montículo está vacío" << endl;
    } else {
        cout << "El montículo no está vacío" << endl;
    }

    return 0;
}

