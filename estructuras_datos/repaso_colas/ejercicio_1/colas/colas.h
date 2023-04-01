#include <iostream>
#include <cstdlib>

using namespace std;

typedef int DataType;

typedef struct Node {
    DataType data;
    Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* back;
} Queue;

void push(Queue* queue, DataType data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (empty(queue)) {
        queue->front = newNode;
        queue->back = newNode;
    } else {
        queue->back->next = newNode;
        queue->back = newNode;
    }
}

DataType pop(Queue* queue) {
    if (empty(queue)) {
        cerr << "La cola está vacía" << endl;
        exit(1);
    }

    Node* currentNode = queue->front;
    DataType data = currentNode->data;

    if (queue->front == queue->back) { // La cola tiene un solo elemento
        queue->front = NULL;
        queue->back = NULL;
    } else {
        queue->front = currentNode->next;
    }
    
    delete currentNode;

    return data;
}

int size(Queue* queue) {
    int count = 0;
    Node* currentNode = queue->front;

    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

bool empty(Queue* queue) {
    if (queue->back == NULL) {
        return true;
    }

    return false;
}

DataType firstIn(Queue* queue) {
    DataType data = queue->front->data;
    return data;
}

DataType lastIn(Queue* queue) {
    DataType data = queue->back->data;
    return data;
}