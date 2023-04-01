#include <iostream>
#include "../../utilities.h"

using namespace std;

int main() {
    StackTools<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Tamaño de la pila: " << myStack.size() << endl;
    cout << "Contenido de la pila: ";
    for (int val : myStack.return_stack()) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Valor en la parte superior de la pila: " << myStack.peek() << endl;

    int poppedVal = myStack.pop();
    cout << "Elemento extraído de la pila: " << poppedVal << endl;

    myStack.clear();
    cout << "La pila está vacía: " << myStack.empty() << endl;
    cout << "Tamaño después de limpiar: " << myStack.size() << endl; // Debería imprimir "0"

    return 0;
}
