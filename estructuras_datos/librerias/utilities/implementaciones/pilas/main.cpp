#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../utilities.h"

#define MAX 11

using namespace std;

int main() {
    srand(time(nullptr));
    StackTools<int> myStack;
    
    for (int i = 0; i < 10; i++) {
        myStack.push(rand() % MAX);
    }

    cout << "Pila actual: ";
    for (auto i : myStack.return_stack()) {
        cout << i << " ";
    }
    cout << endl;

    int top = myStack.pop();
    cout << "Elemento superior extraído: " << top << endl;

    cout << "Pila actual: ";
    for (auto i : myStack.return_stack()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Tamaño de la pila: " << myStack.size() << endl;

    if (!myStack.empty()) {
        cout << "El elemento superior es: " << myStack.peek() << endl;
    }

    return 0;
}
