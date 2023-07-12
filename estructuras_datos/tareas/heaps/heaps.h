#include <stdlib.h>
#include <iostream>
#define MAX 1001 // Tamaño máximo

using namespace std;

typedef struct Heap {    
    int data[MAX +1];
    int maxNodos; // Limite 
    int n; // Carga actual
} Heap;

void flotar(Heap *heap, int i) { // Flota un elemento
    int nuevaClave;
    nuevaClave = heap->data[i]; // Almacenar la clave del nodo a flotar    
    while ((i > 1) && (heap->data[i / 2] > nuevaClave)) { // Mientras el nodo padre sea mayor que el nodo actual        
        heap->data[i] = heap->data[i / 2]; // swap los nodos        
        i = i / 2; // Actualizar la posición del nodo actual    
    }
    
    heap->data[i] = nuevaClave; // Colocar el nodo actual en su posición correcta
}

void insertar(Heap *heap, int clave) { // Insertar un elemento
    if (heap->n == heap->maxNodos) { 
        cerr << "Heap lleno" << endl;
        return;
    }
    
    heap->n++; // Incrementar el número de nodos en el Heap    
    heap->data[heap->n] = clave; // Agregar el nuevo nodo en la última posición    
    flotar(heap, heap->n); // Flotar el nuevo nodo hasta su posición correcta
}

bool empty(Heap *heap) { // Heap vacio
    return (heap->n == 0);
}

int min(Heap *heap) { // Retorna el menor valor del heap
    if (!empty(heap)) { // Si el Heap no está vacío
        return heap->data[1]; // La clave del valor mínimo es la del primer nodo    
    }
}

void swap(int *a, int *b) { // Intercambiar dos valores
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int data[], int primero, int ultimo) {
    // Declaración de variables locales
    int esHeap;
    int hijo;
    esHeap = 0;

    while ((primero <= ultimo) && !esHeap) {        
        // Si el primer nodo tiene un solo hijo
        if (2*primero == ultimo){
            // El hijo es el único hijo del nodo
            hijo = 2*primero;
        } else {
            // Si no, se compara los dos hijos del nodo y se escoge el menor
            if (data[2*primero] < data[2*primero+1]) {
                hijo = 2*primero;
            } else {
                hijo = 2*primero+1;
            }

            // Si el valor del hijo es menor que el valor del padre, se intercambian
            if (data[hijo] < data[primero]) {
                swap(&data[primero], &data[hijo]);
                primero = hijo;
            } else {
                // Si no se cumple la condición anterior, el árbol es un montículo
                esHeap = 1;
            }
        }
    }
}

int pop(Heap* heap) { // Devolver y eliminar el menor valor del heap
    // Si el montículo no está vacío
    if(!empty(heap)) {
        // Buscar el valor mínimo
        int menor = min(heap);
        // Reemplazar el valor mínimo por el último valor del montículo
        heap ->data[1] = heap ->data[heap->n];
        // Decrementar el número de elementos en el montículo
        (heap->n)++;
        // Mantener la propiedad de montículo a partir del nodo raíz (1)
        heapify(heap->data ,1 , heap->n);
        // Retornar el valor mínimo eliminado
        return menor;
    }
}

