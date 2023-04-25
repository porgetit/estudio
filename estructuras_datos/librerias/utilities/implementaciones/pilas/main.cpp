#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../utilities.h"

#define MAX 11

using namespace std;

int main() {
    srand(time(nullptr));
    StackTools<int> myStack("data.bin");
    
    for (int i = 0; i < 10; i++) {
        myStack.push(rand() % MAX);
    }

    cout << "Pila actual: " << myStack << endl;

    int top = myStack.pop();
    cout << "Elemento superior extraído: " << top << endl;

    cout << "Pila actual: " << myStack << endl;

    cout << "Tamaño de la pila: " << myStack.size() << endl;

    if (!myStack.empty()) {
        cout << "El elemento superior es: " << myStack.peek() << endl;
    }

    cout << "Pila actual: " << myStack << endl;

    return 0;
}
