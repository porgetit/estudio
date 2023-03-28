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
void clear(Stack*);
DataType top(Stack*);
int size(Stack*);

int len = 0;

void push(Stack* stack, DataType atom) {
    Node* newNode = new Node;
    newNode->data = atom;
    newNode->next = stack->top;
    stack->top = newNode;
    len++;
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

    len--;

    return data;
}

bool empty(Stack* stack) {
    if (stack->top == NULL) {
        return true;
    }

    return false;
}

void clear(Stack* stack) {
    while (!empty(stack)) {
        pop(stack);
    }
}

DataType top(Stack* stack) {
    return stack->top->data;
}

int size(Stack* stack) {
    return len;
}
