/*
Implementación de una pila de enteros: Implementar una pila para almacenar n enteros y mostrar (desempilando) su contenido.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int DataType;

typedef struct Node {
    DataType data;
    Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void push(Stack*, DataType);
DataType pop(Stack*);
bool empty(Stack*);

int main() {
    Stack my_stack;
    my_stack.top = NULL;

    int amount_integers;
    
    cout << "Ingrese cuántos números quiere: ";
    cin >> amount_integers; fflush(stdin);

    // Empilamos
    for (int index = amount_integers; index >= 0; index--) {
        DataType atom = (DataType) (index +1);
        push(&my_stack, atom);
    }

    // Desempilamos
    for (int i = 0; i < amount_integers; i++) {
        cout << pop(&my_stack) << " ";
    }
}

void push(Stack* stack, DataType atom) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = atom;
    newNode->next = stack->top;
    stack->top = newNode;
}

DataType pop(Stack* stack) {
    if (empty(stack)) {
        cerr << "Pila vacia" << endl;
        return 0;
    }

    Node* eliminatedNode = stack->top;
    DataType data = eliminatedNode->data;
    stack->top = eliminatedNode->next;
    free(eliminatedNode);

    return data;
}

bool empty(Stack* stack) {
    if (stack->top == NULL) {
        return true;
    }

    return false;
}