/*
Implementación de una lista enlazada: Escribe un programa que implemente una lista enlazada utilizando malloc() para reservar memoria para cada nodo de la lista. La lista debe permitir la inserción de nuevos nodos, la eliminación de nodos existentes y la búsqueda de un valor específico en la lista.
*/
#include <cstdio>
#include <cstdlib>

// Definición de la estructura del nodo
struct Node {
    int data; // cuerpo del nodo
    struct Node *next; // puntero del nodo
};

// Función para agregar un nuevo nodo al principio de la lista
void add_node(struct Node **head, int data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Función para eliminar un nodo de la lista
void remove_node(struct Node **head, int data) {
    struct Node *prev_node = NULL;
    struct Node *curr_node = *head;
    while (curr_node != NULL && curr_node->data != data) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node != NULL) {
        if (prev_node == NULL) {
            *head = curr_node->next;
        } else {
            prev_node->next = curr_node->next;
        }
        free(curr_node);
    }
}

// Función para imprimir la lista
void print_list(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Función principal
int main() {
    struct Node *head = NULL;

    // Agregamos algunos nodos a la lista
    add_node(&head, 3);
    add_node(&head, 5);
    add_node(&head, 7);
    add_node(&head, 9);

    // Imprimimos la lista
    printf("Lista inicial:\n");
    print_list(head);

    // Eliminamos un nodo de la lista
    remove_node(&head, 5);

    // Imprimimos la lista actualizada
    printf("Lista actualizada:\n");
    print_list(head);

    // Liberamos la memoria asignada para los nodos restantes
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
