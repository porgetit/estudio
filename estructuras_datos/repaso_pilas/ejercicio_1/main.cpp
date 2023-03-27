/*
Implementación de una pila de enteros: Implementar una pila para almacenar 10 enteros y mostrar (desempilando) su contenido.
*/

#include <iostream>
#include <cstdlib>

#define TAM 15

using namespace std;

typedef int DataType;

typedef struct Nodo { // Esto define la naturaleza de cada nodo de la estructura
    DataType data;
    Nodo* next;
} Nodo;

typedef struct Pila {
    Nodo* top; // Esto define la cabeza de la estructura
} Pila;

void push(Pila*, DataType);
DataType pop(Pila*);

int main() {
    Pila pila;
    pila.top = NULL;

    // Inicializar pila 
    for (int index = 0; index < TAM; index++) {
        DataType temp = (DataType) (index +1) * (index +1);
        push(&pila, temp);
    }
    
    for (int index = 0; index < TAM; index++) {
        cout << pop(&pila) << endl;
    }
}

void push(Pila* pila, DataType data) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->data = data;
    nuevoNodo->next = pila->top;
    pila->top = nuevoNodo;
}

DataType pop(Pila* pila) {
    if (pila->top == NULL) {
        cerr << "La pila está vacía" << endl;
        return 0;
    }

    Nodo* nodoEliminado = pila->top;
    DataType temp_data = nodoEliminado->data;
    pila->top = nodoEliminado->next;
    free(nodoEliminado);
    
    return temp_data;
}
