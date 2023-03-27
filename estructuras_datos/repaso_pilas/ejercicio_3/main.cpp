/*
Tuplas: Implemente una pila que contenga tuplas dónde, el primer valor corresponderá a la X y el segundo f(X). Los valores de X irán desde 0 hasta N con paso de 0.1.

f(x) = x^2 +2x +1
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct DataType {
    float X;
    float Y;
} DataType;

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

    float n;
    float increment = 0.1;

    cout << "Ingrese hasta dónde desea tabular: ";
    cin >> n; fflush(stdin);

    // Empilamos || Llenamos la pila
    int iterations = (int) (10 * n);
    for (int iteration = 0; iteration < iterations; iteration++) {
        float current_value = n - iteration * increment;
        float sub_atom_x = current_value;
        float sub_atom_y = (sub_atom_x * sub_atom_x) + (2 * sub_atom_x) +1;
        DataType atom;
        atom.X = sub_atom_x;
        atom.Y = sub_atom_y;

        push(&my_stack, atom);
    }

    // Desempilamos || Mostramos la pila
    while (true) {
        if (!empty(&my_stack)) {
            DataType data = pop(&my_stack);
            cout << "[" << data.X << " ,\t" << data.Y << "]" << endl;
        }
        else {
            break;
        }        
    }
}

void push(Stack* stack, DataType atom) {
    Node* newNode = new Node;
    newNode->data = atom;
    newNode->next = stack->top;
    stack->top = newNode;
}

DataType pop(Stack* stack) {
    if (empty(stack)) {
        cerr << "Pila vacia" << endl;
        exit(1);
    }

    Node* eliminatedNode = stack->top;
    DataType data = eliminatedNode->data;
    stack->top = eliminatedNode->next;
    delete eliminatedNode;

    return data;
}

bool empty(Stack* stack) {
    if (stack->top == NULL) {
        return true;
    }

    return false;
}
