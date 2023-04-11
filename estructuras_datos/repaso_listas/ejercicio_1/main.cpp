#include <iostream>

using namespace std;

typedef int DataType;

typedef struct Node {
    DataType data;
    Node* next;
} Node;

typedef struct List {
    Node* head = nullptr;
} List;

void append(List*, DataType);
DataType pseudoPop(List*);

int main() {
    // Inicializamos una lista
    List my_lst;

    for (int i = 0; i < 10; i++) {
        DataType atom = (DataType) i;
        append(&my_lst, atom);
    }

    try
    {
        while (my_lst.head != nullptr) {
            cout << pseudoPop(&my_lst) << endl;
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    

    return 0;
}

void append(List* container, DataType data) {

    // Definimos e inicializamos los miembros de un nuevo nodo.
    Node* newNode = new Node; // (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr; // Ya que es una lista simplemente enlazada

    // Verificamos si la lista está vacía de forma manual
    if (container->head == nullptr) {
        container->head = newNode;
    } else {
        // Si no, recorremos la lista para insertar al final
        Node* temp = container->head; // Utilizamos un nodo auxiliar para hacer el recorrido

        while (temp->next != nullptr) {
            temp = temp->next; // Paso simple
        }

        temp->next = newNode;
    }
}

DataType pseudoPop(List* container) {
    Node* current = container->head;

    if (current == nullptr) {
        throw runtime_error("No se puede eliminar elementos de una lista vacía.");
    }

    DataType data = current->data; // Volcamos el dato a la variable de retorno
    container->head = current->next;

    delete current; // free(current);
    return data;
}
