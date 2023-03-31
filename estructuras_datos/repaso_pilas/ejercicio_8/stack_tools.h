#ifndef STACK_TOOLS_H
#define STACK_TOOLS_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>

/**
 * @brief stack_tools contiene estructuras y métodos que le permiten definir una pila de cualquier tipo de dato.
 * 
 * @defgroup stack_tools
 * 
 * @section Instancia de clase:
 * Para instanciar un objeto stack_tools debe hacerlo así: 
 *      stack_tools<DataType> miPila;
 * Dónde DataType es el tipo de dato que heredará la pila y,
 * miPila es el objeto que heredará todos los métodos de la clase.
 * 
 * @section Tipos de datos recomendados para trabajar con la clase:
 * Tipos de datos numéricos: int, float, double, long, etc.
 * Tipos de datos booleanos: bool.
 * Tipos de datos de caracteres: char, std::string, etc;
 * Tipos de datos estructurados simples: struct.
*/
class stack_tools {
public:
    typedef T DataType; // Tipo de dato de la pila

    /**
     * @brief Esta estructura define la naturaleza de los nodos de una pila.
    */
    typedef struct Node {
        DataType data;
        Node* next;
    } Node;

    /**
     * @brief Esta estructura define una pila.
    */
    typedef struct Stack { 
        Node* top;
    } Stack;

    // stack_tools() {
    //     this->size_ = 0;
    // }

    static Stack init_stack() {
        Stack stack;
        stack.top = NULL;
        return stack;
    }

    /**
     * @brief Este método inserta/empila un nuevo nodo.
     * 
     * @param atom es el elemento que se insertará a la pila. 
    */
    static void push(Stack* stack, DataType atom) {
        Node* newNode = new Node;
        newNode->data = atom;
        newNode->next = stack->top;
        stack->top = newNode;
    }

    /**
     * @brief Este método devuelve/desempila el nodo cabecera de la pila.
     * 
     * @throw Si la pila está vacía el método arrojará una excepción: (runtime_error) 
    */
    static DataType pop(Stack* stack) {
        if (empty(stack)) {
            throw std::runtime_error("Pila vacia");
        }

        Node* eliminatedNode = stack->top;
        DataType data = eliminatedNode->data;
        stack->top = eliminatedNode->next;
        delete eliminatedNode;

        return data;
    }

    /**
     * @brief Este método verifica si la pila está vacía.
     * 
     * @todo Cambiar por verificación por tamaño, para evitar problemas de operadores
    */
    static bool empty(Stack* stack) {
        if (stack->top == NULL) {
            return true;
        }

        return false;
    }

    /**
     * @brief Este método vacía/límpia por completo al pila.
     * 
     * @throw Si la pila está vacía el método arrojará una excepción: (runtime_error)
    */
    static void clear(Stack* stack) {
        if (empty(stack)) {
            throw std::runtime_error("Pila vacia");
        }

        while (!empty(stack)) {
            pop(stack);
        }
    }

    /**
     * @brief Este método devuelve el contenido de la cabecera de la pila.
    */
    static DataType peek(Stack* stack) {
        return stack->top->data;
    }

    /**
     * @brief Este método retorna el largo de la pila.
     * @todo Debo hacer que este método recorra la pila (stack) contando el número de nodos y retorne el número de nodos
    */
    static int size(Stack* stack) {
        int len = 0;
        
        Node* currentNode = stack->top;

        while (currentNode->next != NULL) {
            len++;
            currentNode = currentNode->next;
        }
        
        return len;
    }
};

#endif